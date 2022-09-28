#include <unistd.h>
#include "WebServer.h"

int main() {
    /* 守护进程 后台运行 */
    //daemon(1, 0); 
    kong::WebServer server(
        1874, 3, 60000, false,             /* 端口 ET模式 timeoutMs 优雅退出  */
        3306, "root", "root", "webserver", /* Mysql配置 */
        12, 20);             /* 连接池数量 线程池数量 */
    server.Start();
} 
  