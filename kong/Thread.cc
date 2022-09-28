// #include "Thread.h"
// #include "Log.h"
// #include "Util.h"

// namespace kong {

// static kong::Logger::ptr g_logger = KONG_LOG_NAME("Thread");



// Thread::Thread(std::function<void()> cb)
//     :m_cb(cb) {
//     int rt = pthread_create(&m_thread, nullptr, &Thread::run, this);
//     if(rt) {
//         KONG_LOG_ERROR(g_logger) << "pthread_create thread fail, rt=" << rt;
//         throw std::logic_error("pthread_create error");
//     }
//     m_semaphore.wait();
// }

// Thread::~Thread() {
//     if(m_thread) {
//         pthread_detach(m_thread);
//     }
// }

// void Thread::join() {
//     if(m_thread) {
//         int rt = pthread_join(m_thread, nullptr);
//         if(rt) {
//             KONG_LOG_ERROR(g_logger) << "pthread_join thread fail, rt=" << rt;
//             throw std::logic_error("pthread_join error");
//         }
//         m_thread = 0;
//     }
// }

// void* Thread::run(void* arg) {
//     Thread* thread = (Thread*)arg;
//     thread->m_id = kong::GetThreadId();

//     std::function<void()> cb;
//     cb.swap(thread->m_cb);

//     thread->m_semaphore.notify();

//     cb();
//     return 0;
// }

// }



// #include "Thread.h"
// #include "Macro.h"


// namespace kong {

    // Thread::Thread(int threadCount) : pool_(std::make_shared<Pool>()) {
    //         KONG_ASSERT(threadCount > 0);
    //         for(size_t i = 0; i < threadCount; i++) {
    //             std::thread([ pool= pool_] {
    //                 MutexType::Lock lock(pool->m_mutex);
    //                 while(true) {
    //                     if(!pool->tasks.empty()) {
    //                         auto task = std::move(pool->tasks.front());
    //                         pool->tasks.pop();
    //                         MutexType::Lock unlock(pool->m_mutex);
    //                         task();
    //                         MutexType::Lock lock(pool->m_mutex);
    //                     } 
    //                     else if(pool->isClosed) break;
    //                     // else pool->cond.wait(lock);
    //                 }
    //             }).detach();
    //         }
    // }
    
    // Thread::~Thread() {
    //     if(static_cast<bool>(pool_)) {
    //         {
    //             MutexType::Lock lock(pool_->m_mutex);
    //             pool_->isClosed = true;
    //         }
    //         pool_->cond.notify_all();
    //     }
    // }

    // template<class F>
    // void AddTask(F&& task) {
    //     {
    //         MutexType::Lock lock(pool_->m_mutex);
    //         pool_->tasks.emplace(std::forward<F>(task));
    //     }
    //     pool_->cond.notify_one();
    // }



// }