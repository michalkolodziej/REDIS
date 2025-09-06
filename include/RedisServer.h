//
// Created by mkolodziej on 9/5/25.
//

#ifndef REDIS_REDISSERVER_H
#define REDIS_REDISSERVER_H
#include <atomic>
#include <iostream>
#include <string>
#include <atomic>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

class RedisServer{
public:
    RedisServer(int port);
    void run();
    void stop();
private:
    int port;
    int server_socket;
    std::atomic<bool> running;

};

#endif //REDIS_REDISSERVER_H