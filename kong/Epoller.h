#ifndef KONG_EPOLLER_H
#define KONG_EPOLLER_H

#include <sys/epoll.h> //epoll_ctl()
#include <fcntl.h>  // fcntl()
#include <unistd.h> // close()
#include "Macro.h"
#include <memory>
#include <vector>
#include <errno.h>

namespace kong {
class Epoller {
public:
    typedef std::shared_ptr<Epoller> ptr;
    explicit Epoller(int maxEvent = 1024);

    ~Epoller();

    bool AddFd(int fd, uint32_t events);

    bool ModFd(int fd, uint32_t events);

    bool DelFd(int fd);

    int Wait(int timeoutMs = -1);

    int GetEventFd(size_t i) const;

    uint32_t GetEvents(size_t i) const;
        
private:
    int epollFd_;

    std::vector<struct epoll_event> events_;    
};

}
#endif //EPOLLER_H
