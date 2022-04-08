#include "../../lib/sqlite3/sqlite3.h"



#ifndef CONEXION_BD_H
#define CONEXION_BD_H

extern sqlite3 *db;

int startConn();

#endif