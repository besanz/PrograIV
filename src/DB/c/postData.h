#ifndef _POSTDATA_H_
#define _POSTDATA_H_
#include "../../main/c/estructuras.h"
#include "../../../lib/sqlite3/sqlite3.h"
#include "../connect/connect.h"

int insertUsuario(Usuario usuario);
void actualizarEntrada(char * nom_user,int *ent_fest);

#endif