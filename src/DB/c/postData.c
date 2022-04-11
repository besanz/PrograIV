#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../../lib/sqlite3/sqlite3.h"
#include "postData.h"
#include "../connect/connect.h"


int insertUsuario(Usuario usu) {

	startConn();
    sqlite3_stmt *stmt;
	char sql[] = "INSERT INTO usuario VALUES (?, ?, ?, ?)";

int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 1, usu.id_user, strlen(usu.id_user), SQLITE_STATIC);
	result = sqlite3_bind_text(stmt, 2, usu.nom_user, strlen(usu.nom_user), SQLITE_STATIC);
	result = sqlite3_bind_text(stmt, 3, usu.pass_user, strlen(usu.pass_user), SQLITE_STATIC);
	result = sqlite3_bind_text(stmt, 4, usu.ent_fest, strlen(usu.ent_fest), SQLITE_STATIC);

	if (result != SQLITE_OK) {
		printf("Error creando el usuario\n");
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
    closeConn();
}