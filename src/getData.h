#include "../../Programacion4/PrograIV/src/DB/getData.h"
#include "../../Programacion4/PrograIV/src/DB/conexionBD.h"
#include "../../lib/sqlite3/sqlite3.h"
#include "../../Programacion4/PrograIV/src/estructuras.h"
#ifndef getData
#define getData

extern int numFilas;

int getLogin(char *email, char *contrasenya, int userType);
Dj *getinfoDj(int cod_dj);



#endif 