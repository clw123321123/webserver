## 功能
* 利用IO复用技术Epoll与线程池实现多线程的Reactor高并发模型；
* 利用正则与状态机解析HTTP请求报文，实现处理静态资源的请求；
* 利用标准库容器封装char，实现自动增长的缓冲区；
* 基于小根堆实现的定时器，关闭超时的非活动连接；
* 利用单例模式与日志修饰类实现异步的日志系统，记录服务器运行状态；
* 利用RAII机制实现了数据库连接池，减少数据库连接建立与关闭的开销，同时实现了用户注册登录功能。 


## 目录树
```
.
├── code           源代码
│   ├── buffer
│   ├── config
│   ├── http
│   ├── log
│   ├── timer
│   ├── pool
│   ├── server
│   └── main.cpp
├── test           单元测试
│   ├── test_log.cc
|   ├──test_sql.cc
│   └──test_thread.cc
├── resources      静态资源
│   ├── index.html
│   ├── image
│   ├── video
├── bin            可执行文件
│   └── main
├── log            日志文件
├── webbench-1.5   压力测试
├── build          
│   └── Makefile
├── CMakeLists.txt
└── readme.md
```

