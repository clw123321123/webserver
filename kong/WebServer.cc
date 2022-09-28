#include "WebServer.h"
#include "Macro.h"

namespace kong
{
    static kong::Logger::ptr g_logger = KONG_LOG_NAME("WebServer");

    WebServer::WebServer(
        int port, int trigMode, int timeoutMS, bool OptLinger,
        int sqlPort, const char *sqlUser, const char *sqlPwd,
        const char *dbName, int connPoolNum, int threadNum) : port_(port), openLinger_(OptLinger), timeoutMS_(timeoutMS), isClose_(false),
                                                              m_timer(new Timer()), threadpool_(new Thread(threadNum)), m_epoller(new Epoller())
    {
        srcDir_ = getcwd(nullptr, 256);
        KONG_ASSERT(srcDir_);
        strncat(srcDir_, "/resources/", 16);
        HttpConn::userCount = 0;
        HttpConn::srcDir = srcDir_;
        kong::SqlConnPool::connPool::GetInsatnce()->Init("localhost", sqlPort, sqlUser, sqlPwd, dbName, connPoolNum);

        InitEventMode_(trigMode);
        if (!InitSocket_())
        {
            isClose_ = true;
        }

        KONG_LOG_INFO(g_logger) << "========== Server init ==========";
        KONG_LOG_INFO(g_logger) << "Port:" << port_ << "OpenLinger:" << (OptLinger ? "true" : "false");
        KONG_LOG_INFO(g_logger) << "Listen Mode:" << (listenEvent_ & EPOLLET ? "ET" : "LT") << "OpenConn Mode:" << (connEvent_ & EPOLLET ? "ET" : "LT");
        KONG_LOG_INFO(g_logger) << "srcDir:" << HttpConn::srcDir;
        KONG_LOG_INFO(g_logger) << "SqlConnPool num:" << connPoolNum << "ThreadPool num:" << threadNum;
    }

    WebServer::~WebServer()
    {
        close(listenFd_);
        isClose_ = true;
        free(srcDir_);
        kong::SqlConnPool::connPool::GetInsatnce()->ClosePool();
    }

    void WebServer::InitEventMode_(int trigMode)
    {
        listenEvent_ = EPOLLRDHUP;
        connEvent_ = EPOLLONESHOT | EPOLLRDHUP;
        switch (trigMode)
        {
        case 0: //5040
            break;
        case 1://3216
            connEvent_ |= EPOLLET;
            break;
        case 2: //6516
            listenEvent_ |= EPOLLET;
            break;
        case 3: //18924
            listenEvent_ |= EPOLLET;
            connEvent_ |= EPOLLET;
            break;
        default:
            listenEvent_ |= EPOLLET;
            connEvent_ |= EPOLLET;
            break;
        }
        HttpConn::isET = (connEvent_ & EPOLLET);
    }

    void WebServer::Start()
    {
        int timeMS = -1; /* epoll wait timeout == -1 无事件将阻塞 */
        if (!isClose_)
        {
            KONG_LOG_INFO(g_logger) << "========== Server start ==========";
        }
        while (!isClose_)
        {
            if (timeoutMS_ > 0)
            {
                timeMS = m_timer->GetNextTick();
            }
            int eventCnt = m_epoller->Wait(timeMS);
            for (int i = 0; i < eventCnt; i++)
            {
                /* 处理事件 */
                int fd = m_epoller->GetEventFd(i);
                uint32_t events = m_epoller->GetEvents(i);
                if (fd == listenFd_)
                {
                    DealListen_();
                }
                else if (events & (EPOLLRDHUP | EPOLLHUP | EPOLLERR))
                {
                    KONG_ASSERT(m_users.count(fd) > 0);
                    CloseConn_(&m_users[fd]);
                }
                else if (events & EPOLLIN)
                {
                    KONG_ASSERT(m_users.count(fd) > 0);
                    DealRead_(&m_users[fd]);
                }
                else if (events & EPOLLOUT)
                {
                    KONG_ASSERT(m_users.count(fd) > 0);
                    DealWrite_(&m_users[fd]);
                }
                else
                {
                    KONG_LOG_ERROR(g_logger) << "Unexpected event";
                }
            }
        }
    }

    void WebServer::SendError_(int fd, const char *info)
    {
        KONG_ASSERT(fd > 0);
        int ret = send(fd, info, strlen(info), 0);
        if (ret < 0)
        {
            KONG_LOG_WARN(g_logger) << "send error to client error!" << fd;
        }
        close(fd);
    }

    void WebServer::CloseConn_(HttpConn *client)
    {
        KONG_ASSERT(client);
        KONG_LOG_INFO(g_logger) << "Client quit!" << client->GetFd();
        m_epoller->DelFd(client->GetFd());
        client->Close();
    }

    void WebServer::AddClient_(int fd, sockaddr_in addr)
    {
        KONG_ASSERT(fd > 0);
        m_users[fd].init(fd, addr);
        if (timeoutMS_ > 0)
        {
            m_timer->add(fd, timeoutMS_, std::bind(&WebServer::CloseConn_, this, &m_users[fd]));
        }
        m_epoller->AddFd(fd, EPOLLIN | connEvent_);
        SetFdNonblock(fd);
        KONG_LOG_INFO(g_logger) << "Client in!" << m_users[fd].GetFd();
    }

    void WebServer::DealListen_()
    {
        struct sockaddr_in addr;
        socklen_t len = sizeof(addr);
        do
        {
            int fd = accept(listenFd_, (struct sockaddr *)&addr, &len);
            if (fd <= 0)
            {
                return;
            }
            else if (HttpConn::userCount >= MAX_FD)
            {
                SendError_(fd, "Server busy!");
                KONG_LOG_WARN(g_logger) << "Clients is full!";
                return;
            }
            AddClient_(fd, addr);
        } while (listenEvent_ & EPOLLET);
    }

    void WebServer::DealRead_(HttpConn *client)
    {
        KONG_ASSERT(client);
        ExtentTime_(client);
        // kong::Thread::ptr thr(new kong::Thread(std::bind(&WebServer::OnRead_,this,client)));
        threadpool_->AddTask(std::bind(&WebServer::OnRead_, this, client));
    }

    void WebServer::DealWrite_(HttpConn *client)
    {
        KONG_ASSERT(client);
        ExtentTime_(client);
        // kong::Thread::ptr thr(new kong::Thread(std::bind(&WebServer::OnWrite_,this,client)));
        threadpool_->AddTask(std::bind(&WebServer::OnWrite_, this, client));
    }

    void WebServer::ExtentTime_(HttpConn *client)
    {
        KONG_ASSERT(client);
        if (timeoutMS_ > 0)
        {
            m_timer->adjust(client->GetFd(), timeoutMS_);
        }
    }

    void WebServer::OnRead_(HttpConn *client)
    {
        KONG_ASSERT(client);
        int ret = -1;
        int readErrno = 0;
        ret = client->read(&readErrno);
        if (ret <= 0 && readErrno != EAGAIN)
        {
            CloseConn_(client);
            return;
        }
        OnProcess(client);
    }

    void WebServer::OnProcess(HttpConn *client)
    {
        if (client->process())
        {
            m_epoller->ModFd(client->GetFd(), connEvent_ | EPOLLOUT);
        }
        else
        {
            m_epoller->ModFd(client->GetFd(), connEvent_ | EPOLLIN);
        }
    }

    void WebServer::OnWrite_(HttpConn *client)
    {
        KONG_ASSERT(client);
        int ret = -1;
        int writeErrno = 0;
        ret = client->write(&writeErrno);
        if (client->ToWriteBytes() == 0)
        {
            /* 传输完成 */
            if (client->IsKeepAlive())
            {
                OnProcess(client);
                return;
            }
        }
        else if (ret < 0)
        {
            if (writeErrno == EAGAIN)
            {
                /* 继续传输 */
                m_epoller->ModFd(client->GetFd(), connEvent_ | EPOLLOUT);
                return;
            }
        }
        CloseConn_(client);
    }

    /* Create listenFd */
    bool WebServer::InitSocket_()
    {
        int ret;
        struct sockaddr_in addr;
        // if(port_ > 65535 || port_ < 1024) {
        //     KONG_LOG_ERROR(g_logger) << "Port: error!" << port_;
        //     return false;
        // }
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = htonl(INADDR_ANY);
        addr.sin_port = htons(port_);
        struct linger optLinger = {0};
        if (openLinger_)
        {
            /* 优雅关闭: 直到所剩数据发送完毕或超时 */
            optLinger.l_onoff = 1;
            optLinger.l_linger = 1;
        }

        listenFd_ = socket(AF_INET, SOCK_STREAM, 0);
        if (listenFd_ < 0)
        {
            KONG_LOG_ERROR(g_logger) << "Create socket error!" << port_;
            return false;
        }

        ret = setsockopt(listenFd_, SOL_SOCKET, SO_LINGER, &optLinger, sizeof(optLinger));
        if (ret < 0)
        {
            close(listenFd_);
            KONG_LOG_ERROR(g_logger) << "Init linger error!" << port_;
            return false;
        }

        int optval = 1;
        /* 端口复用 */
        /* 只有最后一个套接字会正常接收数据。 */
        ret = setsockopt(listenFd_, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int));
        if (ret == -1)
        {
            KONG_LOG_ERROR(g_logger) << "set socket setsockopt error !";
            close(listenFd_);
            return false;
        }

        ret = bind(listenFd_, (struct sockaddr *)&addr, sizeof(addr));
        if (ret < 0)
        {
            KONG_LOG_ERROR(g_logger) << "Bind Port: error!" << port_;
            close(listenFd_);
            return false;
        }

        ret = listen(listenFd_, 6);
        if (ret < 0)
        {
            KONG_LOG_ERROR(g_logger) << "Listen port:%d error!" << port_;
            close(listenFd_);
            return false;
        }
        ret = m_epoller->AddFd(listenFd_, listenEvent_ | EPOLLIN);
        if (ret == 0)
        {
            KONG_LOG_ERROR(g_logger) << "Add listen error!";
            close(listenFd_);
            return false;
        }
        SetFdNonblock(listenFd_);
        KONG_LOG_INFO(g_logger) << "Server port:" << port_;
        return true;
    }

    int WebServer::SetFdNonblock(int fd)
    {
        KONG_ASSERT(fd > 0);
        return fcntl(fd, F_SETFL, fcntl(fd, F_GETFD, 0) | O_NONBLOCK);
    }

}
