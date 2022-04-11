#ifndef getData
#define getData
#include "../../main/c/estructuras.h"
#include "../../../lib/sqlite3/sqlite3.h"
#include "../connect/connect.h"

extern int numFilas;

int getLogin(char *id, char *contrasenya, int userType);

Dj *getinfoDj(int cod_dj);

Entrada *getinfoEnt(int cod_ent);

Zona *getinfoZona(int cod_zona);

Usuario *getUsuario(char *id_user);

Festival *getFestival(char *nom_fest);





#endif 