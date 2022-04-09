#ifndef CONEXION_BD_H
#define CONEXION_BD_H
#include "../../lib/sqlite3/sqlite3.h"

extern sqlite3 *db;

int startConn();

#endif