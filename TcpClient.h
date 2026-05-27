#pragma comment("lib","ws2_32.lib")
#include<winsock2.h>
#include<iostream>
#pragma once

class TcpClient{
    private:
        int socket_fd;
        struct sockaddr_in target_sa;
    public:
        TcpClient(const char* ip,short port);
        bool Connect();
        ~TcpClient();
};