#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>    /* Internet domain header */

int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr);
int Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

void Bind(int fd, const struct sockaddr *sa, socklen_t salen);
void Listen(int fd, int backlog);

int Select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
int Socket(int family, int type, int protocol);

void Close(int fd);
void Dup2(int oldfd, int newfd);

int Setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);

ssize_t Write(int fd, const void *buf, size_t count);

ssize_t Read(int fd, void *buf, size_t count);
