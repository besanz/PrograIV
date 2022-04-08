#include "../lib/sqlite3/sqlite3.h"
#ifndef dbConnection
#define dbConnection

extern sqlite3 *db;

int startConn();

#endif