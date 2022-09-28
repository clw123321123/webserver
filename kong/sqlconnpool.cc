#include "sqlconnpool.h"
#include "Macro.h"

using namespace std;

namespace kong {

static kong::Logger::ptr g_logger = KONG_LOG_NAME("SQL");

SqlConnPool::SqlConnPool() {
    useCount_ = 0;
    freeCount_ = 0;
}


void SqlConnPool::Init(const char* host, int port,
            const char* user,const char* pwd, const char* dbName,
            int connSize = 10) {
    KONG_ASSERT(connSize > 0);
    for (int i = 0; i < connSize; i++) {
        MYSQL *sql = nullptr;
        sql = mysql_init(sql);
        if (!sql) {
            KONG_LOG_ERROR(g_logger) << "MySql init error!";
            KONG_ASSERT(sql);
        }
        sql = mysql_real_connect(sql, host,
                                 user, pwd,
                                 dbName, port, nullptr, 0);
        if (!sql) {
            KONG_LOG_ERROR(g_logger) << "MySql Connect error!";
        }
        connQue_.push(sql);
    }
    MAX_CONN_ = connSize;
    sem_init(&semId_, 0, MAX_CONN_);
}

MYSQL* SqlConnPool::GetConn() {
    MYSQL *sql = nullptr;
    if(connQue_.empty()){
        KONG_LOG_WARN(g_logger) << "SqlConnPool busy!";
        return nullptr;
    }
    sem_wait(&semId_);
    {
        MutexType::Lock lock(m_mutex);
        sql = connQue_.front();
        connQue_.pop();
    }
    return sql;
}

void SqlConnPool::FreeConn(MYSQL* sql) {
    KONG_ASSERT(sql);
    MutexType::Lock lock(m_mutex);
    connQue_.push(sql);
    sem_post(&semId_);
}

void SqlConnPool::ClosePool() {
    MutexType::Lock lock(m_mutex);
    while(!connQue_.empty()) {
        auto item = connQue_.front();
        connQue_.pop();
        mysql_close(item);
    }
    mysql_library_end();        
}

int SqlConnPool::GetFreeConnCount() {
    MutexType::Lock lock(m_mutex); 
    return connQue_.size();
}

SqlConnPool::~SqlConnPool() {
    ClosePool();
}

}
