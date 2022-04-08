#include "../lib/sqlite3/sqlite3.h"
#include "dbConnection.h"
#include <stdio.h>

sqlite3 *db;

int startConn()
{
    int rc = sqlite3_open("./bd/BaseDeDatos4.db", &db);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "No se puede abrir la base de datos: %s\n",
                sqlite3_errmsg(db));
        sqlite3_close(db);

        return 0;
    }

    return 1;
}