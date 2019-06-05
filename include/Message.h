//
// Created by qaze on 18/05/2019.
//

#ifndef LIL_MESSAGE_H
#define LIL_MESSAGE_H

#include <stdlib.h>

class Message {
public:
    size_t size;
    int type;
    long timeSent;
    long timeReceived;
    int originalSender;
    void *data;

    const static size_t headerSize = sizeof(size_t) + sizeof(int) + sizeof(long) + sizeof(int);

public:
    Message(size_t size, int type, time_t time);

    Message(char* headerBuffer);

    ~Message();

    static void createHeader(char* headerBuffer, size_t size, int type, long timeSent, int originalSender);

    static void parseHeader(char* headerBuffer, size_t &size, int &type, long &timeSent, int &originalSender);
};


#endif //LIL_MESSAGE_H
