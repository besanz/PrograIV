#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getData.h"
#include "../dbConnection.h"
#include "../../lib/sqlite3/sqlite3.h"
#include "../../main/C/utils/structures.h"

int numFilas = 1;

int getLogin(char *id, char *contrasenya, int userType) 
{
    int comprobacionContrasenya = 0; 
    int rc;
    char *err_msg = 0;
    sqlite3_stmt *res;

    char *sql = "SELECT  x";

    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    if (rc == SQLITE_OK)
    {
        sqlite3_bind_text(res, 1, id, (strlen(id) - userType), SQLITE_STATIC);
        sqlite3_bind_text(res, 2, id, (strlen(id) - userType), SQLITE_STATIC);
    }
    else
    {
        fprintf(stderr, "Error para ejecutar el statement: %s\n", sqlite3_errmsg(db));
    }

    int step = sqlite3_step(res);

    if (step == SQLITE_ROW)
    {
        comprobacionContrasenya = strcmp(contrasenya, (const char *)sqlite3_column_text(res, userType));
    }
    else
        comprobacionContrasenya = 1;

    return comprobacionContrasenya;
}
