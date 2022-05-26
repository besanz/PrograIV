 /*#include <string.h>
#include <string>
#include "postdata.h"
#include <iostream>

using namespace std;

int modificarUsuario(char *elige, Usuario user, char *input)
{
    int rc;
    char *err_msg = 0;
    sqlite3_stmt *res;

    const char *sql;
    const char *sql1 = "UPDATE USUARIO SET pass_user  = ? WHERE nom_user = ?";
  

    switch (*selec)
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
        sqlite3_bind_text(res, 2, cli.getDni().c_str(), (strlen(cli.getDni().c_str())), SQLITE_STATIC);
    }
    else
    {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    int step = sqlite3_step(res);
    sqlite3_finalize(res);

    return step;
}
*/