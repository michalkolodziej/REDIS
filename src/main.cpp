#include <iostream>
#include "../include/RedisServer.h"
using  namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main(int argc, char *argv[]) {
    int port = 6379;
    if (argc > 2) {
        port = stoi(argv[1]);
    }
    RedisServer server(port);


    return 0;
}