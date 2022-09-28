#ifndef KONG_LOG_H
#define KONG_LOG_H

#include <string>
#include <stdint.h>
#include <memory>
#include <list>
#include <sstream>
#include <fstream>
#include <vector> 
#include <stdarg.h>
#include <map>
#include "Util.h"
#include "Singleton.h"
#include "Thread.h"

/**
 * @brief 使用流式方式将日志级别level的日志写入到logger
 */
#define KONG_LOG_LEVEL(logger, level) \
    if(logger->getLevel() <= level) \
        kong::LogEventWrap(kong::LogEvent::ptr(new kong::LogEvent(logger, level, \
                        __FILE__, __LINE__, kong::GetThreadId(),time(0)))).getSS()

/**
 * @brief 使用流式方式将日志级别debug的日志写入到logger
 */
#define KONG_LOG_DEBUG(logger) KONG_LOG_LEVEL(logger, kong::LogLevel::DEBUG)

/**
 * @brief 使用流式方式将日志级别info的日志写入到logger
 */
#define KONG_LOG_INFO(logger) KONG_LOG_LEVEL(logger, kong::LogLevel::INFO)

/**
 * @brief 使用流式方式将日志级别warn的日志写入到logger
 */
#define KONG_LOG_WARN(logger) KONG_LOG_LEVEL(logger, kong::LogLevel::WARN)

/**
 * @brief 使用流式方式将日志级别error的日志写入到logger
 */
#define KONG_LOG_ERROR(logger) KONG_LOG_LEVEL(logger, kong::LogLevel::ERROR)

/**
 * @brief 使用流式方式将日志级别fatal的日志写入到logger
 */
#define KONG_LOG_FATAL(logger) KONG_LOG_LEVEL(logger, kong::LogLevel::FATAL)


/**
 * @brief 获取主日志器
 */
#define KONG_LOG_ROOT() kong::LoggerMgr::GetInsatnce()->getRoot()

/**
 * @brief 获取name的日志器
 */
#define KONG_LOG_NAME(name) kong::LoggerMgr::GetInsatnce()->getLogger(name)

namespace kong {

class Logger;
class LoggerManager;

//日志级别
class LogLevel {
public:
    enum Level {
        UNKNOW = 0,
        DEBUG = 1,
        INFO = 2,
        WARN = 3,
        ERROR = 4,
        FATAL = 5
    };

    static const char* ToString(LogLevel::Level level);
    static LogLevel::Level FromString(const std::string& str);
};

//日志事件    
class LogEvent {
public:
    typedef std::shared_ptr<LogEvent> ptr;
    LogEvent(std::shared_ptr<Logger> logger, LogLevel::Level level
            ,const char* file, int32_t line
            ,uint32_t thread_id, uint64_t time);
        
    const char* getFile() const { return m_file;}
    int32_t getLine() const { return m_line;}
    uint32_t getElapse() const { return m_elapse;}
    uint32_t getThreadId() const { return m_threadId;}
    uint32_t getFiberId() const { return m_fiberId;}
    uint64_t getTime() const { return m_time;}
    const std::string& getThreadName() const { return m_threadName;}
    std::string getContent() const { return m_ss.str();}
    std::shared_ptr<Logger> getLogger() const { return m_logger;}
    LogLevel::Level getLevel() const { return m_level;}

    /**
     * @brief 返回日志内容字符串流
     */
    std::stringstream& getSS() { return m_ss;}

    /**
     * @brief 格式化写入日志内容
     */
    void format(const char* fmt, ...);

    /**
     * @brief 格式化写入日志内容
     */
    void format(const char* fmt, va_list al);
private:
    const char* m_file = nullptr;    //文件名
    int32_t m_line = 0;              //行号
    uint32_t m_elapse = 0;           //程序启动开始到现在的毫秒数
    uint32_t m_threadId = 0;         //线程id
    uint32_t m_fiberId = 0;          //协程id
    uint64_t m_time = 0;             //时间戳
  
    std::string m_threadName;
    std::stringstream m_ss; 
    std::shared_ptr<Logger> m_logger;
    LogLevel::Level m_level;
};



/**
 * @brief 日志事件包装器
 */
class LogEventWrap {
public:

    /**
     * @brief 构造函数
     * @param[in] e 日志事件
     */
    LogEventWrap(LogEvent::ptr e);

    /**
     * @brief 析构函数
     */
    ~LogEventWrap();

    /**
     * @brief 获取日志事件
     */
    LogEvent::ptr getEvent() const { return m_event;}

    /**
     * @brief 获取日志内容流
     */
    std::stringstream& getSS();
private:
    /**
     * @brief 日志事件
     */
    LogEvent::ptr m_event;
};

//日志格式器
class LogFormatter {
public:
typedef std::shared_ptr<LogFormatter> ptr;
//     /**
//      * @brief 构造函数
//      * @param[in] pattern 格式模板
//      * @details 
//      *  %m 消息
//      *  %p 日志级别
//      *  %c 日志名称
//      *  %t 线程id
//      *  %n 换行
//      *  %d 时间
//      *  %f 文件名
//      *  %l 行号
//      *  %T 制表符
//      *  %N 线程名称
//      *
//      *  默认格式 "%d{%Y-%m-%d %H:%M:%S}%T%t%T%F[%p]%T[%c]%T%f:%l%T%m%n"
//      */
LogFormatter(const std::string& pattern);

//     /**
//      * @brief 返回格式化日志文本
//      * @param[in] logger 日志器
//      * @param[in] level 日志级别
//      * @param[in] event 日志事件
//      */
std::string format(std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event);
std::ostream& format(std::ostream& ofs, std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event);
public:

    /**
     * @brief 日志内容项格式化
     */
    class FormatItem {
    public:
        typedef std::shared_ptr<FormatItem> ptr;
        /**
         * @brief 析构函数
         */
        virtual ~FormatItem() {}
        /**
         * @brief 格式化日志到流
         * @param[in, out] os 日志输出流
         * @param[in] logger 日志器
         * @param[in] level 日志等级
         * @param[in] event 日志事件
         */
        virtual void format(std::ostream& os, std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) = 0;
    };

    void init();
    bool isError() const { return m_error;}

    /**
     * @brief 返回日志模板
     */
    const std::string getPattern() const { return m_pattern;}
private:
    /// 日志格式模板
    std::string m_pattern;
    /// 日志格式解析后格式
    std::vector<FormatItem::ptr> m_items;
    /// 是否有错误
    bool m_error = false;

};

//日志输出地
class LogAppender {
friend class Logger;
public:
    typedef std::shared_ptr<LogAppender> ptr;
    typedef Spinlock MutexType;
    virtual ~LogAppender() {}
    virtual void log(std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) = 0;
// //更改日志格式器
    void setFormatter(LogFormatter::ptr val);
// //获取日志格式器
    LogFormatter::ptr getFormatter();
    LogLevel::Level getLevel() const { return m_level;}
    void setLevel(LogLevel::Level val) { m_level = val;}
protected:
    /// 日志级别
    LogLevel::Level m_level = LogLevel::DEBUG;
    /// 是否有自己的日志格式器
    bool m_hasFormatter = false;
    // Mutex
   MutexType m_mutex;
    /// 日志格式器
    LogFormatter::ptr m_formatter;
};

class Logger : public std::enable_shared_from_this<Logger> {
friend class LoggerManager;
public:
    typedef std::shared_ptr<Logger> ptr;
    typedef Spinlock MutexType;
    Logger(const std::string& name = "dejavu");
    void log(LogLevel::Level level, LogEvent::ptr event);
    void debug(LogEvent::ptr event);
    void info(LogEvent::ptr event);
    void warn(LogEvent::ptr event);
    void error(LogEvent::ptr event);
    void fatal(LogEvent::ptr event);
    void addAppender(LogAppender::ptr appender);
    void delAppender(LogAppender::ptr appender);
    void clearAppenders();
    LogLevel::Level getLevel() const { return m_level;}
    void setLevel(LogLevel::Level val) { m_level = val;}
    const std::string& getName() const { return m_name;}
//设置日志格式器
    void setFormatter(LogFormatter::ptr val);
//设置日志格式模板
    void setFormatter(const std::string& val);
    LogFormatter::ptr getFormatter();
private:
    /// 日志名称
    std::string m_name;
    /// 日志级别
    LogLevel::Level m_level;
    /// Mutex
  MutexType m_mutex;
    // 日志目标集合
    std::list<LogAppender::ptr> m_appenders;
    // 日志格式器
    LogFormatter::ptr m_formatter;
    /// 主日志器
    Logger::ptr m_root;
}; 

//输出到控制台的Appender
class StdoutLogAppender : public LogAppender {
public:
    typedef std::shared_ptr<StdoutLogAppender> ptr;
    void log(Logger::ptr logger, LogLevel::Level level, LogEvent::ptr event) override;
};

//输出到文件的Appender
class FileLogAppender : public LogAppender {
public: 
    typedef std::shared_ptr<FileLogAppender> ptr;
    // FileLogAppender(const std::string& filename);
    FileLogAppender(const char* path = "./log", 
                const char* suffix =".log");
    void log(Logger::ptr logger, LogLevel::Level level, LogEvent::ptr event) override;
    bool reopen();
private:
    /// 文件路径
    std::string m_filename;
    /// 文件流
    std::ofstream m_filestream;
//     /// 上次重新打开时间
    uint64_t m_lastTime = 0;

};


//日志器管理类
class LoggerManager {
public:
   typedef Spinlock MutexType;

    LoggerManager(bool flag = false);
    Logger::ptr getLogger(const std::string& name);
    void init();
    Logger::ptr getRoot() const { return m_root;}
private:
    /// Mutex
   MutexType m_mutex;
    /// 日志器容器
    std::map<std::string, Logger::ptr> m_loggers;
    /// 主日志器
    Logger::ptr m_root;
};

// 日志器管理类单例模式
typedef kong::Singleton<LoggerManager> LoggerMgr;


}


#endif