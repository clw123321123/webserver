#include "../kong/Kong.h"
#include <string>



static kong::Logger::ptr g_logger = KONG_LOG_NAME("test_sql");

bool UserVerify(const std::string &name, const std::string &pwd, bool isLogin) {
    if(name == "" || pwd == "") { return false; }
    KONG_LOG_INFO(g_logger) << "Verify name: pwd:" << name.c_str() << pwd.c_str();
    MYSQL* sql;
    kong::SqlConnRAII(&sql,  kong::SqlConnPool::connPool::GetInsatnce());
    assert(sql);
    
    bool flag = false;
    unsigned int j = 0;
    char order[256] = { 0 };
    MYSQL_FIELD *fields = nullptr;
    MYSQL_RES *res = nullptr;
    
    if(!isLogin) { flag = true; }
    snprintf(order, 256, "SELECT username, password FROM user WHERE username='%s' LIMIT 1", name.c_str());
    KONG_LOG_DEBUG(g_logger) << order;

    if(mysql_query(sql, order)) { 
        mysql_free_result(res);
        return false; 
    }
    res = mysql_store_result(sql);
    j = mysql_num_fields(res);
    fields = mysql_fetch_fields(res);

    while(MYSQL_ROW row = mysql_fetch_row(res)) {
        KONG_LOG_DEBUG(g_logger) << "MYSQL ROW:" << row[0] << row[1];
        std::string password(row[1]);
        if(isLogin) {
            if(pwd == password) { flag = true; }
            else {
                flag = false;
                KONG_LOG_DEBUG(g_logger) << "pwd error!";
            }
        } 
        else { 
            flag = false; 
            KONG_LOG_DEBUG(g_logger) << "user used!";
        }
    }
    mysql_free_result(res);

    if(!isLogin && flag == true) {
        KONG_LOG_DEBUG(g_logger) << "regirster!";
        bzero(order, 256);
        snprintf(order, 256,"INSERT INTO user(username, password) VALUES('%s','%s')", name.c_str(), pwd.c_str());
        KONG_LOG_DEBUG(g_logger) << order;
        if(mysql_query(sql, order)) { 
            KONG_LOG_DEBUG(g_logger) << "Insert error!";
            flag = false; 
        }
        flag = true;
    }
    kong::SqlConnPool::connPool::GetInsatnce()->FreeConn(sql);
    KONG_LOG_DEBUG(g_logger) << "UserVerify success!!";
    return flag;
}


int main() {
    KONG_LOG_INFO(g_logger) << "hey sql";
    kong::SqlConnPool::connPool::GetInsatnce()->Init("localhost", 3306, "root", "root", "test_sql", 3);
    UserVerify("root", "root", true);
    UserVerify("sd", "sd", false);

    KONG_LOG_INFO(g_logger) << "end sql";
    return 0;
}