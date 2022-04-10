#ifndef getData
#define getData
#include "../../src/main/c/estructuras.h"
#include "../../src/db/connect/connect.h"
#include "../../lib/sqlite3/sqlite3.h"

extern int numFilas;

int getLogin(char *email, char *contrasenya, int userType);
Dj *getinfoDj(int cod_dj);


#endif 