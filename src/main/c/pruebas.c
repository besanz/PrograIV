

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


    do {
        result = sqlite3_step(stmt);
        if (result == SQLITE_ROW){
            users[i].nom_user = sqlite3_column_int(stmt, 1);
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
/*
void iniciarSesion(){
    imprimirTitulo();
    printf("INICIO DE SESION:\n\nUsuario:\t");
    char *usuario = malloc(25 * sizeof(char));
    char *contrasenya = malloc(25 * sizeof(char));
    scanf("%s", usuario);
    printf("\nContrasenya:\t");
    scanf("%s",contrasenya);
    system("cls");
    //Ahora se debe comprobar la contrasenya y pasar a la siguiente ventana.
    if(comprobarUsuario(usuario, contrasenya) == 1){
        printf("Contrasenya correcta.\nSus datos son los siguientes:\n\n");
        Usuario *user = getUsuario(usuario);
        if(user->esSocio == 1) {
            menuSocio(*user);
        } else{
            imprimirDatosUsuario(*user);
            //MenuNoSocio(*user);
        }
        
    } else{
        if(comprobarAdministrador(usuario, contrasenya) == 1){
            menuAdmin();
        } else{
            printf("La contrasenya no es valida.\n");
        }
    }
    free(usuario);
    free(contrasenya);
}


*/