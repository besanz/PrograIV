#include "../../main/c/estructuras.h"
#include "../../db/c/getData.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Dj *getinfoDj(int cod_dj){
    int rc;
    char *err_msg = 0;
    sqlite3_stmt *res;
    Dj *djbase;
    djbase = (Dj *)malloc(sizeof(Dj));
    djbase->genero.nom_gen=(char*)malloc(sizeof(char));
    char *sql = "SELECT  Dj.cod_dj, Dj.nom_dj, Genero.nom_gen FROM Dj INNER JOIN Genero ON Genero.cod_gen=Dj.gen_dj where cod_dj = ?";

    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    if (rc == SQLITE_OK)
    {
        sqlite3_bind_int(res, 1, cod_dj); 
    }
    else
    {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    int step = sqlite3_step(res);

    if (step == SQLITE_ROW)
    {

        djbase->cod_dj= sqlite3_column_int(res, 0);

        djbase->nom_dj=(char*)malloc((strlen(sqlite3_column_text(res,1))+1)*sizeof(char));
        djbase->nom_dj=strcpy(djbase->nom_dj, (const char *)sqlite3_column_text(res, 1));
        djbase->nom_dj[(strlen(sqlite3_column_text(res,1)))]='\0';

      djbase->genero.nom_gen=(char*) malloc((strlen(sqlite3_column_text(res,1))+1)*sizeof(char));
    djbase->genero.nom_gen=strcpy(djbase->genero.nom_gen, (const char *)sqlite3_column_text(res, 1));
       djbase->genero.nom_gen[(strlen(sqlite3_column_text(res,1)))]='\0';
        
    }

    return djbase;
    free(djbase);
}