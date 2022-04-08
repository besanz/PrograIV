#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getData.h"
#include "conexionBD.h"
#include "../../lib/sqlite3/sqlite3.h"
#include "../utils/estructuras.h"



Usuario *getUsuario(char *id_User)
{
    int rc;
    char *err_msg = 0;
    sqlite3_stmt *res;
    char* nombre;
    nombre = (char*)malloc(20*sizeof(char));

    char *sql = "SELECT * FROM Usuario WHERE ID_USER = ?";

    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    if (rc == SQLITE_OK)
    {
        sqlite3_bind_text(res, 1, id_User,sizeof(*id_User), SQLITE_STATIC);
    }
    else
    {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }
    Usuario *u;
    u = (Usuario*) malloc(sizeof(Usuario));
    int step = sqlite3_step(res);

    if (step == SQLITE_ROW)
    {
        u->nom_user = (char*)malloc(25*sizeof(char));
        strcpy((u->nom_user), (char*)sqlite3_column_text(res, 0));
        
    }

    sqlite3_finalize(res);

    return u; 
}

int main(void){
    startConn();

    Usuario *u = getUsuario("73037923");
    printf("Nombre de usuario: %s", u->nom_user);
}