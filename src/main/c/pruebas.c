/**

#include "../../main/c/estructuras.h"
#include "../../db/c/getData.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../db/c/postData.h"

int modificarUsuario(char *elig, Usuario *usuario,char *input)
{

	 int rc;
    char *err_msg = 0;
    sqlite3_stmt *res;

    char *sql;
    char *sql1 = "UPDATE Usuario SET ent_fes = ? WHERE nom_user = ?";
    

    switch (*elig)
    {
    case '1':
        sql = sql1;
        break;
    default:
        break;
    }

    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    if (rc == SQLITE_OK)
    {
        sqlite3_bind_text(res, 1, input, (strlen(input)), SQLITE_STATIC);
        sqlite3_bind_text(res, 2, usuario->nom_user, (strlen(usuario->nom_user)), SQLITE_STATIC);
    }
    else
    {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    int step = sqlite3_step(res);
    sqlite3_finalize(res);

    return step;
}

void main(void){
    
}

**/