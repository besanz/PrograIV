#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../lib/sqlite3/sqlite3.h"
#include "../../main/c/estructuras.h"
#include "../../db/c/postData.h"
#include "../connect/connect.h"



void actualizarEntrada(char * nom_user,int *ent_fest){
	
    int rc;
    char *err_msg = 0;
    sqlite3_stmt *res;
	sqlite3_stmt *stmt;

    char *sql = "UPDATE Usuario SET ENT_FEST = ?  WHERE NOM_USER = ?";

    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    if (rc == SQLITE_OK)
    {

        sqlite3_bind_int(res, 3, *ent_fest);
        sqlite3_bind_text(stmt, 1,nom_user, (strlen(nom_user)), SQLITE_STATIC);
    }
    else
    {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    int step = sqlite3_step(res);
    sqlite3_finalize(res);

	
}