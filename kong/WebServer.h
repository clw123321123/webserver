#ifndef KONG_WEBSERVER_H
#define KONG_WEBSERVER_H

#include <unordered_map>
#include <fcntl.h>  // fcntl()
#include <unistd.h> // close()
#include <assert.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "Epoller.h"
#include "Log.h"
#include "Timer.h"
#include "sqlconnpool.h"
#include "Thread.h"
#include "sqlconnRAII.h"
#include "httpconn.h"

namespace kong
{
    class WebServer
    {
    public:
        WebServer(
            int port, int trigMode, int timeoutMS, bool OptLinger,
            int sqlPort, const char *sqlUser, const char *sqlPwd,
            const char *dbName, int connPoolNum, int threadNum);

        ~WebServer();
        void Start();

    private:
        bool InitSocket_();
        void InitEventMode_(int trigMode);
        void AddClient_(int fd, sockaddr_in addr);

        void DealListen_();
        void DealWrite_(HttpConn *client);
        void DealRead_(HttpConn *client);

        void SendError_(int fd, const char *info);
        void ExtentTime_(HttpConn *client);
        void CloseConn_(HttpConn *client);

        void OnRead_(HttpConn *client);
        void OnWrite_(HttpConn *client);
        void OnProcess(HttpConn *client);

        static const int MAX_FD = 65536;

        static int SetFdNonblock(int fd);

        int port_;
        bool openLinger_;
        bool openfile;
        int timeoutMS_; /* 毫秒MS */
        bool isClose_;
        int listenFd_;
        char *srcDir_;

        uint32_t listenEvent_;
        uint32_t connEvent_;

        kong::Timer::ptr m_timer;
        std::unique_ptr<Thread> threadpool_;
        kong::Epoller::ptr m_epoller;
        std::unordered_map<int, HttpConn> m_users;
    };

}
#endif // WEBSERVER_H
