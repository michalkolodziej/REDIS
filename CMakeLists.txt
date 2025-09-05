cmake_minimum_required(VERSION 4.0)
project(REDIS)

set(CMAKE_CXX_STANDARD 20)

add_executable(REDIS src/main.cpp
        src/RedisServer.cpp
        include/RedisServer.h)
