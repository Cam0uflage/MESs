#ifndef NETWORKING_H_
#define NETWORKING_H_

typedef struct {
    int sockfd;
    short port;
    struct addrinfo host;
    struct sockaddr_storage client_addr;
} MessConnection;


#endif
