/*#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x501

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


#define DEFAULT_BUFLEN 1024
#define DEFAULT_PORT "27015"

int __cdecl main(int argc, char **argv) 
{
    WSADATA wsaData;
    SOCKET ConnectSocket = INVALID_SOCKET;
    struct addrinfo *result = NULL,
                    *ptr = NULL,
                    hints;
    const char *sendbuf = "El cliente se ha conectado\0\n";
    char recvbuf[DEFAULT_BUFLEN];
    int iResult;
    int recvbuflen = DEFAULT_BUFLEN;
    
    // Validate the parameters
    if (argc != 2) {
        printf("usage: %s server-name\n", argv[0]);
        return 1;
    }

    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory( &hints, sizeof(hints) );
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Resolve the server address and port
    iResult = getaddrinfo(argv[1], DEFAULT_PORT, &hints, &result);
    if ( iResult != 0 ) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    // Attempt to connect to an address until one succeeds
    for(ptr=result; ptr != NULL ;ptr=ptr->ai_next) {

        // Create a SOCKET for connecting to server
        ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, 
            ptr->ai_protocol);
        if (ConnectSocket == INVALID_SOCKET) {
            printf("socket failed with error: %ld\n", WSAGetLastError());
            WSACleanup();
            return 1;
        }

        // Connect to server.
        iResult = connect( ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            closesocket(ConnectSocket);
            ConnectSocket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result);

    if (ConnectSocket == INVALID_SOCKET) {
        printf("Unable to connect to server!\n");
        WSACleanup();
        return 1;
    }

    // Send an initial buffer
    //1: El cliente se ha conectado!
    iResult = send( ConnectSocket, sendbuf, (int)strlen(sendbuf), 0 );
    if (iResult == SOCKET_ERROR) {
        printf("send failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    //printf("Bytes Sent: %ld\n", iResult);
     
    // Receive until the peer closes the connection
    do {
        //1.1. Enviar user
        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        char* msgUser = new char[iResult];
        strcpy(msgUser, recvbuf);
        msgUser[iResult] = '\0';
        printf("%s", msgUser);
        char* user = new char[15];
        cin >> user;
        iResult = send(ConnectSocket, user, (int)strlen(user), 0);
        
        //1.2. Enviar contrasenya
        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        char* msgContrasenya = new char[iResult];
        strcpy(msgContrasenya, recvbuf);
        msgContrasenya[iResult] = '\0';
        printf("%s", msgContrasenya);
        char* contrasenya = new char[15];
        cin >> contrasenya;
        iResult = send(ConnectSocket, contrasenya, (int)strlen(contrasenya), 0);
        

        //2 Recibir opciones menu
        iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
        if ( iResult > 0 ) {
            //printf("Bytes received: %d\n", iResult);
            char* text = new char[iResult];
            strcpy(text, recvbuf);
            text[iResult] = '\0';
            printf("%s", text);

            //3 Enviar opcion
            char* opcion = new char[15];
            cin >> opcion;
            iResult = send(ConnectSocket, opcion, (int)strlen(opcion), 0);
            if (iResult == SOCKET_ERROR) {
                printf("send failed with error: %d\n", WSAGetLastError());
                closesocket(ConnectSocket);
                WSACleanup();
                return 1;
            }

            if (opcion=="s" || opcion=="S") {
                //4 Enviar datos nueva transferencia
                //4.1.
                iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
                char* msgDestino = new char[iResult];
                strcpy(msgDestino, recvbuf);
                msgDestino[iResult] = '\0';
                printf("%s", msgDestino);
                char* destino = new char[15];
                cin >> destino;
                iResult = send(ConnectSocket, destino, (int)strlen(destino), 0);
            
                //4.2.
                iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
                char* msgImporte = new char[iResult];
                strcpy(msgImporte, recvbuf);
                msgImporte[iResult] = '\0';
                printf("%s", msgImporte);
                char* importe = new char[15];
                cin >> importe;
                iResult = send(ConnectSocket, importe, (int)strlen(importe), 0);

                //4.3.
                iResult = recv(ConnectSocket, recvbuf, recvbuflen, 0);
                char* msgDescripcion = new char[iResult];
                strcpy(msgDescripcion, recvbuf);
                msgDestino[iResult] = '\0';
                printf("%s", msgDescripcion);
                char* descripcion = new char[15];
                cin >> descripcion;
                iResult = send(ConnectSocket, descripcion, (int)strlen(descripcion), 0);


            }
           



        } else if ( iResult == 0 )
            printf("Connection closed\n");
        else
            printf("recv failed with error: %d\n", WSAGetLastError());
        
    } while( iResult > 0 );

    // shutdown the connection since no more data will be sent
    iResult = shutdown(ConnectSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ConnectSocket);
        WSACleanup();
        return 1;
    }

    // cleanup
    closesocket(ConnectSocket);
    WSACleanup();

    return 0;
}
*/