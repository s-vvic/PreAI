#pragma comment(lib, "ws2_32.lib")

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <Winsock2.h>
#include <process.h>

#define BUFF_SIZE 1024

using namespace std;

int main() {
    WSADATA     wasdata;
    SOCKET      server_socket;
    SOCKET      client_socket;
    int         client_addr_size;

    SOCKADDR_IN server_addr;
    SOCKADDR_IN client_addr;

    char buf_rcv[BUFF_SIZE];
    char buf_snd[BUFF_SIZE];

    if (WSAStartup(MAKEWORD(2, 2), &wasdata) != 0) {
        cout << "WSAStratup error" << endl;
        WSACleanup();
        exit(1);
    }

    server_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        cout << "server_socket error" << endl;
        WSACleanup();
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family      = AF_INET;
    server_addr.sin_port        = htons(8080);
    server_addr.sin_addr.s_addr = (INADDR_ANY);

    if (bind(server_socket, (SOCKADDR *)&server_addr, sizeof(server_addr)) == -1) {
        cout << "bind error" << endl;
        WSACleanup();
        exit(1);
    }

    if (listen(server_socket, 5)) {
        cout << "listen error" << endl;
        WSACleanup();
        exit(1);
    }

    while (1) {
        client_addr_size    = sizeof(client_addr);
        client_socket       = accept(server_socket, (SOCKADDR *)&client_addr, &client_addr_size);

        if (client_socket == -1) {
            cout << "client_socket error" << endl;
            WSACleanup();
            exit(1);
        }

        recv(client_socket, buf_rcv, BUFF_SIZE, 0);
        cout << "receive: " << buf_rcv << endl;

        send(client_socket, buf_snd, BUFF_SIZE, 0);
        WSACleanup();
    }
}