#include "Socket.h"
#include <iostream>

using namespace sockets;
using namespace std;

int main() {
    Socket *s = new Socket();
    s->sendRequest((char *)"Solicitud de prueba");
    char *c = new char[60];
    cin>>c;
    s->printBuffer();
    delete s;
}