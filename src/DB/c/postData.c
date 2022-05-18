#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../lib/sqlite3/sqlite3.h"
#include "../../main/c/estructuras.h"
#include "../../db/c/postData.h"
#include "../connect/connect.h"


int insertarUsuario(Usuario usuario) {
	startConn();
    sqlite3_stmt *stmt;
	char sql[] = "INSERT INTO usuario VALUES (?, ?, ?, ?)";
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	usuario.ent_fest = 0;

	result = sqlite3_bind_int(stmt, 0, usuario.id_user);
	result = sqlite3_bind_text(stmt, 1, usuario.nom_user, strlen(usuario.nom_user), SQLITE_STATIC);
	result = sqlite3_bind_text(stmt, 2, usuario.pass_user, strlen(usuario.pass_user), SQLITE_STATIC);
	result = sqlite3_bind_int(stmt, 3, usuario.ent_fest);


	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	return SQLITE_OK;
}
void actualizarEntrada(char * nom_user,int *ent_fest){
	
    int rc;
    char *err_msg = 0;
    sqlite3_stmt *res;
	sqlite3_stmt *stmt;

    char *sql = "UPDATE Usuario SET ENT_FEST = ?  WHERE NOM_USER = ?";

    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    if (rc == SQLITE_OK)
    {

        sqlite3_bind_int(res, 1, *ent_fest);
        res = sqlite3_bind_text(stmt, 2,*nom_user, strlen(*nom_user), SQLITE_STATIC);
    }
    else
    {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    int step = sqlite3_step(res);
    sqlite3_finalize(res);

	
}