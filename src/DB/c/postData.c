#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../lib/sqlite3/sqlite3.h"
#include "../../main/c/estructuras.h"
#include "../../db/c/postData.h"
#include "../connect/connect.h"

/*int insertarUsuario(Usuario usuario) {
	startConn();
    sqlite3_stmt *stmt;
	char sql[] = "INSERT INTO usuario VALUES (?, ?, ?, 0)";
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_bind_text(stmt, 0, usuario.id_user, strlen(usuario.id_user), SQLITE_STATIC);
	result = sqlite3_bind_text(stmt, 1, usuario.nom_user, strlen(usuario.nom_user), SQLITE_STATIC);
	result = sqlite3_bind_text(stmt, 2, usuario.pass_user, strlen(usuario.pass_user), SQLITE_STATIC);
	result = sqlite3_bind_text(stmt, 3, usuario.ent_fest, strlen(usuario.ent_fest), SQLITE_STATIC);


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
*/