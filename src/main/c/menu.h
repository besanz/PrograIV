#ifndef _MENU_H_
#define _MENU_H_
#include "estructuras.h"
#include "../../../lib/sqlite3/sqlite3.h"
#include "../../db/c/getData.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../db/c/postData.h"

void menuInicial();

void menuComprarEntrada(Entrada *e, Usuario *u);

void menuEntradas(Usuario *u);

void menuDentroFestival(Festival *f, Usuario *u);

void menuSeleccionFestival(Usuario *u);

void inicioSesion();

void menuVerUsuarios();

//void registrarUsuario();

#endif