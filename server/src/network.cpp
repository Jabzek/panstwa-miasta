#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/epoll.h>
#include "network.hpp"
#include "utils.hpp"


int init_server_socket(const int port) {
    int fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
    if (fd == -1){
        log_errno("socket()");
        return -1;
    }

    int one = 1;
    int res = setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one));
    if (res == -1){
        log_errno("setsockopt()");
        close(fd);
        return -1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    res = bind(fd, (sockaddr*) &serverAddr, sizeof(serverAddr));
    if (res == -1){
        log_errno("bind()");
        close(fd);
        return -1;
    }

    return fd;
}


