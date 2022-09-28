#ifndef KONG_SQLCONNPOOL_H
#define KONG_SQLCONNPOOL_H

#include <mysql/mysql.h>
#include <string>
#include <queue>
#include <memory>
#include <semaphore.h>
#include <thread>
#include "Log.h"
#include "Mutex.h"


namespace kong {
class SqlConnPool {
public:
    typedef kong::Singleton<SqlConnPool> connPool;
    typedef Spinlock MutexType;

    SqlConnPool();
    ~SqlConnPool();
    MYSQL *GetConn();
    void FreeConn(MYSQL * conn);
    int GetFreeConnCount();

    void Init(const char* host, int port,
              const char* user,const char* pwd, 
              const char* dbName, int connSize);
    void ClosePool();

private:

    int MAX_CONN_;
    int useCount_;
    int freeCount_;

    std::queue<MYSQL *> connQue_;
    MutexType m_mutex; 
    sem_t semId_;
};

}
#endif // SQLCONNPOOL_H

