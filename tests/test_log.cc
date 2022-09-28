#include <iostream>
#include "../kong/Log.h"
#include "../kong/Util.h"
#include "../kong/Macro.h"

int main(int argc, char** argv) {
      kong::Logger::ptr logger(new kong::Logger);
      logger->addAppender(kong::LogAppender::ptr(new kong::StdoutLogAppender));

    // kong::FileLogAppender::ptr file_appender(new kong::FileLogAppender("../log/log"+ time(0)));
    // kong::LogFormatter::ptr fmt(new kong::LogFormatter("%d%T%p%T%m%n"));
    // file_appender->setFormatter(fmt);
    // file_appender->setLevel(kong::LogLevel::ERROR);

    // logger->addAppender(file_appender);


    // std::cout << "hello kong log" << std::endl;

    KONG_LOG_INFO(logger) << "test macro";
    // int i = 1;
    // KONG_ASSERT(i > 2);
    KONG_LOG_ERROR(logger) << "test macro error";


    //  auto l = kong::LoggerMgr::GetInsatnce()->getLogger("xx");
    //  KONG_LOG_INFO(l) << "xxx";
    std::cout << "hey kong" << std::endl;
    return 0;
}
