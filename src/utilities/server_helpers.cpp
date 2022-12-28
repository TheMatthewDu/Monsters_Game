#include "server_helpers.hpp"
#include <iostream>
#include <unistd.h>

/* Socket function wrappers that incorporate error checking */
int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen) {
    int n = accept(sockfd, addr, addrlen);
    if (n < 0) {
        perror("accept");
        exit(1);
    }
    return n;
}

int Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen){
    int n = connect(sockfd, addr, addrlen);
    if (n < 0) {
        perror("connect");
        exit(1);
    }
    return n;
}

/* Socket function wrappers that incorporate error checking */
void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
    if (bind(sockfd, addr, addrlen) < 0){
        perror("bind");
        exit(1);
    }
}


void Listen(int sockfd, int backlog) {
    if (listen(sockfd, backlog) < 0) {
        perror("listen");
        exit(1);
    }
}

int Select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout) {
    int n = select(nfds, readfds, writefds, exceptfds, timeout);
    if (n < 0) {
        perror("select");
        exit(1);
    }
    return n;              /* can return 0 on timeout */
}


int Socket(int domain, int type, int protocol) {
    int n = socket(domain, type, protocol);
    if (n < 0) {
        perror("socket");
        exit(1);
    }

    return n;
}

void Close(int fd) {
    if (close(fd) == -1) {
        perror("close");
        exit(1);
    }
}

void Dup2(int oldfd, int newfd) {
    if(dup2(oldfd, newfd) == -1) {
        perror("dup2");
        exit(1);
    }
}

int Setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen) {
    int status = setsockopt(sockfd, level, optname, optval, optlen);
    if (status < 0) {
        perror("setsockopt");
        exit(1);
    }
    return status;
}

ssize_t Write(int fd, const void *buf, size_t count){
    int num_written = write(fd, buf, count);
    if (num_written == -1) {
        perror("write");
        exit(1);
    }
    return num_written;
}

ssize_t Read(int fd, void *buf, size_t count){
    int num_read = read(fd, buf, count);
    if (num_read == -1) {
        perror("read");
        exit(1);
    }
    return num_read;
}
