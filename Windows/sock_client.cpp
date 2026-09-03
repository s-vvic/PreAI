#pragma comment(lib, "ws2_32.lib")

#include <iostream>
#include <string.h>
#include <Winsock2.h>

#define BUFF_SIZE 1024

using namespace std;

int main(int argc, char **argv) {
    WSADATA wsadata;

    SOCKET client_socket;
    SOCKADDR_IN server_addr;
    char buf[BUFF_SIZE];
    
    if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0) {
        cout << "WSAStratup error" << endl;
        WSACleanup();
        exit(1);
    }

    client_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        cout << "client socket error" << endl;
        WSACleanup();
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(client_socket, (SOCKADDR *)&server_addr, sizeof(server_addr)) == -1) {
        cout << "connect error" << endl;
        WSACleanup();
        exit(1);
    }

    send(client_socket, argv[1], strlen(argv[1]) + 1, 0);
    recv(client_socket, buf, BUFF_SIZE, 0);
    cout << buf << endl;
    WSACleanup();

    return 0;
}
