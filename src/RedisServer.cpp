//
// Created by mkolodziej on 9/5/25.
//

#include "../include/RedisServer.h"

static RedisServer* globalServer = nullptr;

RedisServer::RedisServer(int port) :port(port), server_socket(-1),running(true){
    globalServer = this;
}

void RedisServer::stop() {
    running = false;
    if (server_socket != -1) {
        close(server_socket);
    }
    std::cout << "RedisServer::stop)" << std::endl;
}
void RedisServer::run() {
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        std::cerr << "Error creating server socket" << std::endl;
        return;
    }
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    sockaddr_in server_address{};
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(port);
    server_address.sin_port.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        std::cerr << "Error binding server socket to port" << std::endl;
        return;
    }
    if (listen(server_socket, 10) < 0) {
        std::cerr << "Error listening on port" << std::endl;
        return;
    }
    std::cout << "RedisServer::run() port: " << port << std::endl;
}