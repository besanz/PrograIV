/*
#include <iostream>
#include <ws2tcpip.h>

#pragma comment (lib, "ws2_32.lib")

using namespace std;

void main(){
    //Initialice winsock
    WSADATA wsData;
    WORD ver= MAKEWORD(2,2);


    int wsok=WSAStartup(ver, &wsData);
     
     if(wsok!=0){
         cerr <<"Can't initialize winsock!" << endl;
         return;
     }

    //create a socket
    SOCKET listening= socket(AF_INET,SOCK_STREAM,0);
    if(listening== INVALID_SOCKET){
        cerr << "Can't create a socket!" <<endl;
    }

    //bind the ip adress and port to a socket
    sockaddr_in hint;
    hint.sin_family= AF_INET;
    hint.sin_port= htons(54000);
    hint.sin_addr.S_un.S_addr=INADDR_ANY; //TAMBIEN SE PUEDE USAR inet_pton...

    bind(listening, (sockaddr*)&hint, sizeof(hint));

    //Tell the Winsock the socket is for listening
    listen(listening, SOMAXCONN);
    
    //Wait for connection
    sockaddr_in client;
    int clientSize=sizeof(client);
    SOCKET clientSocket= accept(listening, (sockaddr*)&client, &clientSize);
    if (clientSocket==INVALID_SOCKET){
        cerr << "Invalid socket! quiting..." <<endl;  //comprobar que el socket esta bien
    } 
    char host[NI_MAXHOST];  //nombre de client
    char service[NI_MAXSERV];   //puerto al que se conecta el cliente

    ZeroMemory(host, NI_MAXHOST); //same as memset(host, o, NI_MAXHOST);
    ZeroMemory(service, NI_MAXSERV);

    if (getnameinfo((sockaddr*)&client, sizeof(client), host,NI_MAXHOST, service, NI_MAXSERV,0)==0){
        cout << host << "connected on port" <<service <<endl;
    }
    else{
      inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
      cout << host << "connected on port" << ntohs(client.sin_port) <<endl;
    }

    //close listening socket
    closesocket(listening);

    //White loop: accept and echo message back to client
    char buff[4096];

    while(true){
        ZeroMemory(buff, 4096);
        //Wait for client to send data
        int bytesReceived=recv(clientSocket, buff, 4096,0);
        if(bytesReceived==SOCKET_ERROR){
            cerr<< "Error in recv(). Quiting" <<endl;
            break;
        }
        if(bytesReceived==0){
            cout <<"client disconnected" <<endl;
        }
        //Echo message back to client
        send(clientSocket, buff, bytesReceived+1, 0);

    }
    //close the socket
    closesocket(clientSocket);

    //shutdown winsock
    WSACleanup();
}

*/