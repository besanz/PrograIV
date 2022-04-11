#ifndef getData
#define getData
#include "../../main/c/estructuras.h"
#include "../../../lib/sqlite3/sqlite3.h"
#include "../connect/connect.h"

extern int numFilas;

int getLogin(char *email, char *contrasenya, int userType);
Dj *getinfoDj(int cod_dj);


#endif 