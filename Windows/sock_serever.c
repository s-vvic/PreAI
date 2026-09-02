#pragma comment(lib, "ws2_32.lib")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Winsock2.h>
#include <process.h>

#define BUFF_SIZE 1024

int main() {
    WSADATA *wasdata;

    SOCKET      server_socket;
    SOCKET      client_socket;
    int    client_addr;

    SOCKADDR_IN server_addr;
    SOCKADDR_IN client_addr;

    char buf_rcv[BUFF_SIZE];
    char buf_snd[BUFF_SIZE];


}