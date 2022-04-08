#include "../../main/C/utils/structures.h"
#include "../../lib/sqlite3/sqlite3.h"
#include "../dbConnection.h"
#ifndef getData
#define getData

extern int numFilas;

int getLogin(char *email, char *contrasenya, int userType);

#endif 