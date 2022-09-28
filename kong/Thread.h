// #ifndef __KONG_THREAD_H__
// #define __KONG_THREAD_H__

// #include "Mutex.h"

// namespace kong {

// /**
//  * @brief 线程类
//  */
// class Thread : Noncopyable {
// public:
//     /// 线程智能指针类型
//     typedef std::shared_ptr<Thread> ptr;

//     /**
//      * @brief 构造函数
//      * @param[in] cb 线程执行函数
//      * @param[in] name 线程名称
//      */
//     Thread(std::function<void()> cb);

//     /**
//      * @brief 析构函数
//      */
//     ~Thread();

//     /**
//      * @brief 线程ID
//      */
//     pid_t getId() const { return m_id;}

//     /**
//      * @brief 等待线程执行完成
//      */
//     void join();

//     /**
//      * @brief 获取当前的线程指针
//      */
//     static Thread* GetThis();

// private:

//     /**
//      * @brief 线程执行函数
//      */
//     static void* run(void* arg);
// private:
//     /// 线程id
//     pid_t m_id = -1;
//     /// 线程结构
//     pthread_t m_thread = 0;
//     /// 线程执行函数
//     std::function<void()> m_cb;
//     std::vector<kong::Thread::ptr> threadpool;
//     /// 信号量
//     Semaphore m_semaphore;
// };

// }

// #endif

#ifndef KONG_THREAD_H
#define KONG_THREAD_H

#include "Mutex.h"
#include <mutex>
#include "Macro.h"
#include <condition_variable>
#include <queue>
#include <thread>
#include <functional>

namespace kong
{

    class Thread
    {
    public:
        typedef std::shared_ptr<Thread> ptr;
        typedef Mutex MutexType;

        explicit Thread(int threadCount = 8) : pool_(std::make_shared<Pool>())
        {
            assert(threadCount > 0);
            for (size_t i = 0; i < threadCount; i++)
            {
                std::thread([pool = pool_]
                            {
                    // MutexType::Lock lock(pool->m_mutex);
                    std::unique_lock<std::mutex> locker(pool->mtx);
                    while(true) {
                        if(!pool->tasks.empty()) {
                            auto task = std::move(pool->tasks.front());
                            pool->tasks.pop();
                            // MutexType::Lock unlock(pool->m_mutex);
                            locker.unlock();
                            task();
                            // MutexType::Lock lock(pool->m_mutex);
                            locker.lock();
                        } 
                        // else if(pool->isClosed) break;
                        else pool->cond.wait(locker);
                        // else pool->m_sem.wait();
                    } })
                    .detach();
            }
        }

        ~Thread()
        {
            if (static_cast<bool>(pool_))
            {
                {
                    // MutexType::Lock lock(pool_->m_mutex);
                    std::lock_guard<std::mutex> locker(pool_->mtx);
                    pool_->isClosed = true;
                }
                pool_->cond.notify_all();
            }
        }

        template <class F>
        void AddTask(F &&task)
        {
            {
                // MutexType::Lock lock(pool_->m_mutex);
                std::lock_guard<std::mutex> locker(pool_->mtx);
                pool_->tasks.emplace(std::forward<F>(task));
            }
            pool_->cond.notify_one();
            // pool_->m_sem.notify();
        }

        Thread() = default;

        Thread(Thread &&) = default;

    private:
        struct Pool
        {
            // MutexType m_mutex;
            std::mutex mtx;
            std::condition_variable cond;
            // kong::Semaphore m_sem;
            bool isClosed;
            std::queue<std::function<void()>> tasks;
        };
        std::shared_ptr<Pool> pool_;
    };

}
#endif // THREADPOOL_H
