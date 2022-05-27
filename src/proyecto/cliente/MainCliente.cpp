#include "Socket.h"
#include <iostream>

extern "C"{
  #include "../../main/c/estructuras.h"
#include "../../../lib/sqlite3/sqlite3.h"
#include "../../db/c/getData.h"
#include "../../db/c/postData.h"
#include "../../main/c/menu.h"
}
using namespace sockets;
using namespace std;

int main() {
    /*Socket *s = new Socket();
    s->sendRequest((char *)"Solicitud de prueba");
    char *c = new char[60];
    cin>>c;
    s->printBuffer();
    delete s;
    */
    startConn();
    menuInicial();
}