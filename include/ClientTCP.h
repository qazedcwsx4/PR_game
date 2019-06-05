#ifndef LIL_CLIENTTCP_H
#define LIL_CLIENTTCP_H

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <thread>
#include <time.h>
#include <queue>
#include <mutex>

#ifdef _WIN32

#include <winsock2.h>

#elif __linux__
#define SOCKET_ERROR (-1)
#include <netinet/in.h>
#include <libnet.h>
#include <pcap.h>
#endif

#include "Message.h"

void hello();

class ClientTCP {
public:
    const int LIL_ERROR = 1;
    const int LIL_SUCCESS = 0;

private:
    const char *addr;
    const int port;
    bool shouldDie = false;
    bool recvWorking = false;
    SOCKET mainSocket;
    std::thread recvTh;
    std::queue<Message *> messages;
    std::mutex messagesMutex;
public:
    Message *getMessage();

    ClientTCP(const char *addr, const int port);

    ~ClientTCP();

    int init();

    int send(const char *data, size_t size, unsigned int type);


private:
    void recvThread();

    int startRecv();

    std::queue<Message *> &getMessages();
};

#endif