#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../lib/sqlite3/sqlite3.h"
#include "../../src/main/c/data/estructuras.h"
#include "../../db/c/getData.h"

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

Dj *getinfoDj(int cod_dj){
    int rc;
    char *err_msg = 0;
    sqlite3_stmt *res;
    Dj *djbase;
    djbase = (Dj *)malloc(sizeof(Dj));
    djbase->info_dj=(Genero*)malloc(sizeof(Genero));

    char *sql = "SELECT DJ.cod_dj, DJ.nom_dj, GENERO.nom_gen FROM DJ INNER JOIN GENERO ON Genero.cod_gen=DJ.gen_dj where cod_dj = ?";

    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    if (rc == SQLITE_OK)
    {
        sqlite3_bind_text(res, 1, cod_dj, (strlen(cod_dj) - 1), SQLITE_STATIC); 
    }
    else
    {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    int step = sqlite3_step(res);

    if (step == SQLITE_ROW)
    {

        strcpy(djbase->nom_dj, (const char *)sqlite3_column_text(res, 1));
        djbase->cod_dj = sqlite3_column_int(res, 0);

        //strcpy(djbase->info_dj->nom_gen, (const char *)sqlite3_column_text(res, 1));
        //Revisar esta linea. 
              
        
    }

    return djbase;
    free(djbase);
}


