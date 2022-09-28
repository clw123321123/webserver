#include "../kong/Kong.h"
#include <memory>

kong::Logger::ptr g_logger = KONG_LOG_ROOT();

void fun2() {
    int i = 30;
    while(i--) {
        KONG_LOG_INFO(g_logger) << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
    }
}

void fun3() {
    int i = 40;
    while(i--) {
        KONG_LOG_INFO(g_logger) << "========================================";
    }
}

int main(int argc, char** argv) {
    KONG_LOG_INFO(g_logger) << "thread test begin";
    
    kong::Thread::ptr threadpool_(new kong::Thread(4));
    threadpool_->AddTask(fun2);
    threadpool_->AddTask(fun3);
        threadpool_->AddTask(fun2);
    threadpool_->AddTask(fun3);
        threadpool_->AddTask(fun3);
    threadpool_->AddTask(fun2);

    sleep(1);

    KONG_LOG_INFO(g_logger) << "thread test end";

    return 0;
}