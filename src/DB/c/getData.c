#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../lib/sqlite3/sqlite3.h"
#include "../../src/main/c/estructuras.h"
#include "../../db/c/getData.h"
#define MAX 40;

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
    djbase->genero=malloc(sizeof(Genero));

    char *sql = "SELECT  DJ.nom_dj, GENERO.nom_gen FROM DJ INNER JOIN GENERO ON Genero.cod_gen=DJ.gen_dj where cod_dj = ?";

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

        djbase->nom_dj=malloc(sizeof(char));
        djbase->genero=(Genero*) malloc(sizeof(Genero));
        strcpy(djbase->nom_dj, (const char *)sqlite3_column_text(res, 1));
         strcpy(djbase->genero, (const char *)sqlite3_column_text(res, 2));
        
    }

    return djbase;
    free(djbase);
}

Entrada *getinfoEnt(int cod_ent){
    int rc;
    char *err_msg = 0;
    sqlite3_stmt *res;
    Entrada *entrada;
    entrada = (Entrada *)malloc(sizeof(Entrada));
   

    char *sql = "SELECT * FROM ENTRADA WHERE COD_ENT = ?";

    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    if (rc == SQLITE_OK)
    {
        sqlite3_bind_text(res, 1, cod_ent, (strlen(cod_ent) - 1), SQLITE_STATIC); 
    }
    else
    {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    int step = sqlite3_step(res);

    if (step == SQLITE_ROW)
    {

        entrada->info_ent=(char*)malloc(sizeof(char));
        entrada->tipo_ent=(char*)malloc(sizeof(char));
        strcpy(entrada->info_ent, (const char *)sqlite3_column_text(res, 1));
         strcpy(entrada->tipo_ent, (const char *)sqlite3_column_text(res, 2));
        entrada->cod_ent= sqlite3_column_int(res, 0);
        entrada->precio== sqlite3_column_int(res, 3);
    }
    
    

    return entrada;
    free(entrada);
}
Zona *getinfoZona(int cod_zona){
    int rc;
    char *err_msg = 0;
    sqlite3_stmt *res;
    Zona *zona;
    zona = (Zona *)malloc(sizeof(Zona));
    zona->gen_zona=malloc(sizeof(Genero));
   

    char *sql = "SELECT NOM_ZONA FROM ZONA WHERE COD_ZONA = ?";

    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    if (rc == SQLITE_OK)
    {
        sqlite3_bind_text(res, 1, cod_zona, (strlen(cod_zona) - 1), SQLITE_STATIC); 
    }
    else
    {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    int step = sqlite3_step(res);

    if (step == SQLITE_ROW)
    {

       zona->nom_zona=(char*)malloc(sizeof(char));
        zona->gen_zona=(Genero*) malloc(sizeof(Genero));
        strcpy(zona->nom_zona, (const char *)sqlite3_column_text(res, 1));
        strcpy(zona->gen_zona,(const char *)sqlite3_column_text(res, 2));       
    }
    
    

    return zona;
    free(zona);
}
Usuario *getUsuario(char *id_user) 
{
    
    int rc;
    char *err_msg = 0;
    sqlite3_stmt *res;
    Usuario *usu;

    char *sql = "SELECT * FROM Usuario WHERE ID=?";

    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    if (rc == SQLITE_OK)
    {
        sqlite3_bind_text(res, 1, id_user, (strlen(id_user)-1), SQLITE_STATIC);
        
    }
    else
    {
        fprintf(stderr, "Error para ejecutar el statement: %s\n", sqlite3_errmsg(db));
    }

    int step = sqlite3_step(res);

    if (step == SQLITE_ROW)
    {
        usu->id_user=(char*)malloc(sizeof(char));
        usu->nom_user=(char*) malloc(sizeof(char));
        usu->pass_user=(char*) malloc(sizeof(char));
       
        strcpy(usu->id_user, (const char *)sqlite3_column_text(res, 1));
        strcpy(usu->nom_user,(const char *)sqlite3_column_text(res, 2));
        strcpy(usu->pass_user,(const char *)sqlite3_column_text(res, 3));
        usu->ent_fest== sqlite3_column_int(res, 4);
        
    }
    else{}

    return usu;
}
void main(void){
    
    //Aqui para comprobar el metodo creas lo que tengas que pasarle por parametro y en el gcc solo pones getData.c no tienes que incluir todos los .c del proyecto
    // de lujo
}


