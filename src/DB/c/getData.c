#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../lib/sqlite3/sqlite3.h"
#include "../../main/c/estructuras.h"
#include "../../db/c/getData.h"
#include "../connect/connect.h"
#define MAX 40;

Entrada *getinfoEnt(int cod_ent){
    int rc;
    char *err_msg = 0;
    sqlite3_stmt *res;
    Entrada *entrada;
    entrada = (Entrada *)malloc(sizeof(Entrada));
   

    char *sql = "SELECT * FROM Entrada WHERE cod_ent = ?";

    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    if (rc == SQLITE_OK)
    {
        sqlite3_bind_int(res, 1, cod_ent); 
    }
    else
    {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    int step = sqlite3_step(res);

    if (step == SQLITE_ROW)
    {

        entrada->info_ent=(char*)malloc((strlen(sqlite3_column_text(res,2))+1)*sizeof(char));
        entrada->info_ent=strcpy(entrada->info_ent, (const char *)sqlite3_column_text(res, 2));
        entrada->info_ent[(strlen(sqlite3_column_text(res,2)))]='\0';
       
        entrada->tipo_ent=(char*)malloc((strlen(sqlite3_column_text(res,1))+1)*sizeof(char));
        entrada->tipo_ent=strcpy(entrada->tipo_ent, (const char *)sqlite3_column_text(res, 1));
        entrada->tipo_ent[(strlen(sqlite3_column_text(res,1)))]='\0';
       
        entrada->cod_ent= sqlite3_column_int(res, 0);
        entrada->precio= sqlite3_column_int(res, 3);
        
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
   
   

    char *sql = "SELECT * FROM Zona WHERE cod_zona = ?";

    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    if (rc == SQLITE_OK)
    {
        sqlite3_bind_int(res, 1, cod_zona); 
    }
    else
    {
        fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
    }

    int step = sqlite3_step(res);

    if (step == SQLITE_ROW)
    {
        zona->nom_zona=(char*)malloc((strlen(sqlite3_column_text(res,1))+1)*(sizeof(char)));
        zona->nom_zona=strcpy(zona->nom_zona, (const char *)sqlite3_column_text(res, 1));
        zona->nom_zona[(strlen(sqlite3_column_text(res,1)))]='\0';   
    }
    

    return zona;
    free(zona);
}

Usuario *getUsuario(char *id_user) 
{
    startConn();
    
    int rc;
    char *err_msg = 0;
    sqlite3_stmt *res;
    Usuario *usu;
    usu=(Usuario*)malloc(sizeof(Usuario));

    char *sql = "SELECT * FROM Usuario WHERE nom_user=?";

    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    if (rc == SQLITE_OK)
    {
        sqlite3_bind_text(res, 1, id_user, (strlen(id_user)), SQLITE_STATIC);
        
    }
    else
    {
        fprintf(stderr, "Error para ejecutar el statement: %s\n", sqlite3_errmsg(db));
    }

    int step = sqlite3_step(res);
    
    if (step == SQLITE_ROW)

    {
        usu->id_user=(char*)malloc((strlen(sqlite3_column_text(res,0))+1)*sizeof(char));
        usu->id_user=strcpy(usu->id_user, (const char *)sqlite3_column_text(res, 0));
        usu->id_user[(strlen(sqlite3_column_text(res,0)))]='\0';

        usu->nom_user=(char*)malloc((strlen(sqlite3_column_text(res,1))+1)*sizeof(char));
        usu->nom_user=strcpy(usu->nom_user, (const char *)sqlite3_column_text(res, 1));
        usu->nom_user[(strlen(sqlite3_column_text(res,1)))]='\0';

        usu->pass_user=(char*)malloc((strlen(sqlite3_column_text(res,2))+1)*sizeof(char));
        usu->pass_user=strcpy(usu->pass_user, (const char *)sqlite3_column_text(res, 2));
        usu->pass_user[(strlen(sqlite3_column_text(res,2)))]='\0';

        usu->ent_fest= sqlite3_column_int(res, 3);
    }

    return usu;
    

}


Festival *getFestival(char *nom_fest) 
{
    
    int rc;
    char *err_msg = 0;
    sqlite3_stmt *res;
    Festival *fest;
    fest=(Festival*)malloc(sizeof(Festival));

    char *sql = "SELECT * FROM Festival WHERE nom_fest=?";

    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    if (rc == SQLITE_OK)
    {
        sqlite3_bind_text(res, 1, nom_fest, (strlen(nom_fest)), SQLITE_STATIC);
        
    }
    else
    {
        fprintf(stderr, "Error para ejecutar el statement: %s\n", sqlite3_errmsg(db));
    }

    int step = sqlite3_step(res);
    
    if (step == SQLITE_ROW)

    {

        fest->cod_fest= sqlite3_column_int(res, 0);
        
        fest->nom_fest=(char*)malloc((strlen(sqlite3_column_text(res,1))+1)*sizeof(char));
        fest->nom_fest=strcpy(fest->nom_fest, (const char *)sqlite3_column_text(res, 1));
        fest->nom_fest[(strlen(sqlite3_column_text(res,1)))]='\0';

        fest->info_fest=(char*)malloc((strlen(sqlite3_column_text(res,2))+1)*sizeof(char));
        fest->info_fest=strcpy(fest->info_fest, (const char *)sqlite3_column_text(res, 2));
        fest->info_fest[(strlen(sqlite3_column_text(res,2)))]='\0';
    }
    else{}
    

    return fest;
    free(fest);


}




Dj *getinfoDj(int cod_dj){
    int rc;
    char *err_msg = 0;
    sqlite3_stmt *res;
    Dj *djbase;
    djbase = (Dj *)malloc(sizeof(Dj));
   
    char *sql = "SELECT * FROM Dj WHERE cod_dj = ?";

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
        djbase->gen_dj= sqlite3_column_int(res, 0);    
        
    }

    return djbase;
    free(djbase);
}
Usuario* getListaUsuarios (){
    startConn();
	sqlite3_stmt *stmt;
	char sql[] = "SELECT * FROM usuario";
    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (result != SQLITE_OK){
        printf("Error preparing statemet (SELECT)\n");
        printf("%s\n", sqlite3_errmsg(db));
    }

    int numFilas = getNumFilas("SELECT * FROM usuario");
    
    Usuario* users = (Usuario*)malloc(numFilas*sizeof(Usuario));
    int i = 0;
    printf("\tTLISTA DE USUARIOS REGISTRADOS");
    printf("\n\t==============================\n");

    do { 
        result = sqlite3_step(stmt);
        if (result == SQLITE_ROW){
            int size = strlen((char*)sqlite3_column_text(stmt,1));
            users[i].nom_user = (char*)malloc((size+1)*sizeof(char));
            users[i].nom_user = strcpy(users[i].nom_user,(char*)sqlite3_column_text(stmt,1));
            printf("\tUsuario N.%i: " ,i);
            printf(users[i].nom_user);
            printf("\n");
            i++;
        }
    } while (result == SQLITE_ROW);
    
    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
        printf("Error finalizing statement (SELECT)\n");
        printf("%s\n", sqlite3_errmsg(db));
    }
    return users;
}
int getNumFilas(char sql[]){
	startConn();
    sqlite3_stmt *stmt;
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	int numFilas = 0;
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			numFilas++;
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	return numFilas;
}

int usuarioLibre(char *nom_user) {
	char sql[] = "SELECT nom_user FROM usuario WHERE nom_user = ?";

    startConn();
    sqlite3_stmt *stmt;
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);


	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	} else {
        sqlite3_bind_text(stmt, 1, nom_user, (-1), SQLITE_STATIC); 
    }

	int existeUser = 1;
	do {
		result = sqlite3_step(stmt) ;
        
		if (result == SQLITE_ROW) {
            existeUser = strcmp(nom_user, (const char *)sqlite3_column_text(stmt, 0));
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);

    
    return existeUser; //0 si existe, >0 si no

	}
