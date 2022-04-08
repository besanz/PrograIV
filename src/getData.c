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
Usuario **getListaClientes(char *idProf)
{
    int rc, rc1;
    char *err_msg = 0;
    sqlite3_stmt *res, *res1;

    char *sql = "SELECT * FROM CLIENTE WHERE ID_PROF = ? ORDER BY DNI ASC";
    char *sql1 = "SELECT COUNT(*) FROM CLIENTE WHERE ID_PROF = ?";

    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);
    rc1 = sqlite3_prepare_v2(db, sql1, -1, &res1, 0);

    if (rc == SQLITE_OK && rc1 == SQLITE_OK)
    {
        sqlite3_bind_text(res, 1, idProf, (strlen(idProf)), SQLITE_STATIC);
        sqlite3_bind_text(res1, 1, idProf, (strlen(idProf)), SQLITE_STATIC);
    }
    else
    {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    int step = sqlite3_step(res);
    int step1 = sqlite3_step(res1);

    numFilas = sqlite3_column_int(res1, 0);

    Cliente **lista;
    lista = (Cliente **)malloc(numFilas * sizeof(Cliente *));
    for (int i = 0; i < numFilas; i++)
    {
        *(lista + i) = (Cliente *)malloc(sizeof(Cliente));
        (*(lista + i))->user = (Usuario *)malloc(sizeof(Usuario));
    }

    int i = 0;

    while (step == SQLITE_ROW)
    {
        strcpy((*(lista + i))->user->dni, (const char *)sqlite3_column_text(res, 0));
        strcpy((*(lista + i))->user->contrasenya, (const char *)sqlite3_column_text(res, 1));
        strcpy((*(lista + i))->user->nombreApellidos, (const char *)sqlite3_column_text(res, 2));
        (*(lista + i))->user->telefono = sqlite3_column_int(res, 3);
        strcpy((*(lista + i))->user->email, (const char *)sqlite3_column_text(res, 4));
        strcpy((*(lista + i))->domicilio, (const char *)sqlite3_column_text(res, 5));
        strcpy((*(lista + i))->user->fechaNacimiento, (const char *)sqlite3_column_text(res, 6));

        i++;
        step = sqlite3_step(res);
    }

    sqlite3_finalize(res);

    return lista; //El resto de punteros se liberan desde el menu, accediendo a ellos a traves del puntero que se crea ahi
}