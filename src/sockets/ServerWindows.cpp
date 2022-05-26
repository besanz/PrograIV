#undef UNICODE

#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x501

extern "C" //LOS .H DE LO QUE HE IMPLEMENTADO EN C
{
    
    #include "../../lib/sqlite3/sqlite3.h"
    
}
#include "../main/c/menu.h"
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;



// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 1024
#define DEF 100
#define DEFAULT_PORT "27015"

//void limpiarBuffer(char* buffer, int bufferLen);

int __cdecl main(void) 
{
    WSADATA wsaData;
    int iResult;

    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKET ClientSocket = INVALID_SOCKET;

    struct addrinfo *result = NULL, *ptr = NULL, hints;

    int iSendResult;
    char* recvbuf = new char[DEFAULT_BUFLEN];
    char* sendbuf = new char[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;
    char* recvbuf1 = new char[DEFAULT_BUFLEN];
    char* recvbuf2 = new char[DEFAULT_BUFLEN];
    char* recvbuf3 = new char[DEFAULT_BUFLEN];
    char* recvbuf4 = new char[DEFAULT_BUFLEN];
    char* recvbuf5 = new char[DEFAULT_BUFLEN];
    char* recvbuf6 = new char[DEFAULT_BUFLEN];
    char* recvbuf7 = new char[DEFAULT_BUFLEN];
    char* recvbuf8 = new char[DEFAULT_BUFLEN];
    char* recvbuf9 = new char[DEFAULT_BUFLEN];
    char* recvbuf10 = new char[DEFAULT_BUFLEN];


    char* f_pathBD = new char[DEF];
    sqlite3 *db;
    int result = sqlite3_open(f_pathBD, &db);

    
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port

    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if ( iResult != 0 ) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    // Create a SOCKET for connecting to server
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    // Setup the TCP listening socket
    iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    freeaddrinfo(result);

    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    // Accept a client socket
    ClientSocket = accept(ListenSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    // No longer need server socket
    closesocket(ListenSocket);

    // Receive until the peer shuts down the connection
    do {
        //1: El cliente se ha conectado!
        iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0) {
            char* text = new char[iResult];
            strcpy(text, recvbuf);
            text[iResult] = '\0';
            printf("%s\n", text);

        // Echo the buffer back to the sender
        //1.1. Recibir nom_user
        char* msg = "Introduce el nombre de usuario: \n";
        iSendResult = send(ClientSocket, msg, (int)strlen(msg), 0);

        iResult = recv(ClientSocket, recvbuf1, recvbuflen, 0);
        char* nom_user = new char[iResult];
        strcpy(nom_user, recvbuf1);
        text[iResult] = '\0';
        //limpiarBuffer(recvbuf, recvbuflen);
        printf("Usuario recibido: %s\n", nom_user);

        //1.2. Recibir pass_user
        char* msg2 = "Introduce tu password: \n";
        iSendResult = send(ClientSocket, msg2, (int)strlen(msg2), 0);

        iResult = recv(ClientSocket, recvbuf2, recvbuflen, 0);
        char* pass_user = new char[iResult];
        strcpy(pass_user, recvbuf2);
        text[iResult] = '\0';
        //limpiarBuffer(recvbuf, recvbuflen);
        printf("Password recibida: %s\n", pass_user);
        
        //COMPROBAR USER Y PASSWORD CORRECTOS
       cout << comprobarUsuario(nom_user, pass_user) << endl;
        //2
        //Cliente* cliente = new Cliente(1234, "Cliente", "01/01/2001", 'f', "1234");
        //CuentaCorriente *cuenta = new CuentaCorriente(1, 200.00, cliente);
    
        //metodo polimorfico
        sendbuf = "¡Hola %s! \n", "JOKIN";
        iSendResult = send( ClientSocket, sendbuf, (int)strlen(sendbuf), 0 );
            if (iSendResult == SOCKET_ERROR) {
                printf("send failed with error: %d\n", WSAGetLastError());
                closesocket(ClientSocket);
                WSACleanup();
                return 1;
            }
            //printf("Bytes sent: %d\n", iSendResult);
            printf("Text sent: %s\n", sendbuf);

            //3
            iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
            if (iResult>0) {
                char* text = new char[iResult];
                strcpy(text, recvbuf);
                text[iResult] = '\0';
                printf("Opcion recibida: %s", text);
                //limpiarBuffer(recvbuf, recvbuflen);
            }

            if(text=="s" || text=="S"){
                printf("Chupamela nos ha salido.");
            }
                
                
            
            
            //printf("%s", recvbuf);

            //iSendResult = send(ClientSocket, recvbuf, iResult, 0);
            
            // shutdown the connection since we're done
        iResult = shutdown(ClientSocket, SD_SEND);
        if (iResult == SOCKET_ERROR) {
            printf("shutdown failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            return 1;
        }
        }
        else if (iResult == 0)
            printf("Connection closing...\n");
        else  {
            printf("recv failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            return 1;
        }

    } while (iResult > 0);

    

    // cleanup
    closesocket(ClientSocket);
    WSACleanup();

    return 0;
}