//
// Created by mkolodziej on 9/5/25.
//

#ifndef REDIS_REDISSERVER_H
#define REDIS_REDISSERVER_H
#include <iostream>

class RedisServer{
public:
    RedisServer(int port);
private:
    int port;
};

#endif //REDIS_REDISSERVER_H