#include "estructuras.h"
#include "../../../lib/sqlite3/sqlite3.h"
#include "../../db/c/getData.h"
#include "../../db/c/postData.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30


void menuInicial(){

	int repite = 1;
	int opcion;

	
	do {
    system("cls");
		printf("\n\t\t\tMENU INICIAL\n");
		printf("\t\t\t============\n\n");
		printf("\t\t1. Ver Usuarios Registrados\n");
		printf("\t\t2. Registrar Usuario Nuevo\n");
		printf("\t\t3. Iniciar Sesion\n");
		printf("\t\t0. Salir\n\n");
		printf("\t\tIngrese una opcion: [ ]\b\b");
		scanf("%i", &opcion);

		switch (opcion) {
			case 1:
       // getListaUsuarios();
        menuVerUsuarios();
			case 2:	

      
        menuRegistrarUsuario();
				break;
			case 3:
				
          inicioSesion();
				break;
			case 0:
				  
				repite = 0;
				break;
		}   
	} while (repite == 1);
	printf("\nFIN DEL PROGRAMA");
} 

int comprobarUsuario(char *usuario, char *contrasenya){
	startConn();
	

char sql[] = "SELECT usuario, contrasenya FROM usuario";
    sqlite3_stmt *stmt;
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	int usuarioValido = 0;
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			if(strcmp(usuario, sqlite3_column_text(stmt,0)) == 0 &&
			strcmp(contrasenya, sqlite3_column_text(stmt,1)) == 0){
				usuarioValido = 1;
				break;
			}

		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	return usuarioValido;
}
void inicioSesion(){

	int correcto = 0;
	int intento = 0;
	char nombreUsuario[20];
	char password[20];
	
	Usuario *usu;
  usu=(Usuario*)malloc(sizeof(Usuario));


	do {
		system("cls");
		printf("\n\t\t\tINGRESAR AL SISTEMA\n");
		printf("\t\t\t===================\n");
		printf("\n\t\tUSUARIO: ");
		scanf("%s", nombreUsuario);
		printf("\t\tCLAVE: ");
		scanf("%s", password);

		usu = getUsuario(nombreUsuario);
		
		if(comprobarUsuario(nombreUsuario, password) == 1){

			menuSeleccionFestival(usu);
			
		}else{
      intento=intento+1;
      printf("Incorrecto");
      inicioSesion();
      break;
    }
		
	} while (intento < 4 && correcto == 0);

}

void menuVerUsuarios()
{ 
  int a=1;
  int input;

	do {	
    
    getListaUsuarios();
    printf("\t1. Volver. \n"
         "\t2. Cerrar. \n"
         "\tIngrese una opcion: [ ]\b\b");
         
    scanf("%d", &input);
    fflush(stdin);
		switch (input) {
			case 1:
       menuInicial();
      case 2:	
       	break;
			case 0:
				a = 0;
		}  
    a=0; 
	} while (a == 1);
	printf("\nFIN DEL PROGRAMA");
} 

void menuSeleccionFestival(Usuario *u)
{ 

    int input;
    int eleccion = 0;
    Festival *f;
    f = (Festival*)malloc(sizeof(Festival));
    
    system("cls");

do{
      system("cls");
        printf("\t\t\n---------------------Bienvenido!---------------------------\n"   
         "\t\tElige un festival : \n"
         "\t\t1. Festival JOKINAL SOUND. \n"
         "\t\t2. Festival Tomorrowland.  \n"
         "\t\t3. Festival Vive Latino. \n"
         "\t\t4. Festival Coachella. \n"
         "\t\t5. Festival Ultra Miami. \n"
         "\t\t6. Volver. \n"
         "\t\tIngrese una opcion: [ ]\b\b");
        
        scanf("%d", &input);
        fflush(stdin);
        switch (input)
        {
        case 1:
          f = getFestival("JOKINAL SOUND");
        	menuDentroFestival(f, u);
        	eleccion=1;
          
          break;
        case 2:
           f = getFestival("Tomorrowland");
        	menuDentroFestival(f, u);
        	eleccion=1;
        
          break; 
        case 3:
          f = getFestival("Vive Latino");
        	menuDentroFestival(f, u);
        	eleccion=1;
          break;
        case 4:
          f = getFestival("Coachella");
        	menuDentroFestival(f, u);
        	eleccion=1;
          break;
        case 5:
          f = getFestival("Ultra Miami");
        	menuDentroFestival(f, u);
        	eleccion=1;
          break;
        case 6:
          eleccion=1;
          menuInicial();
          break;
        case 0:
            printf("\n\n\n");
            break;
        }
      }  while (eleccion == 0);
    
}
void menuInfoFestival(Festival *f, Usuario *u)
{
   int input;
   int eleccion=0;
    do{
        printf("Bienvenido al %s\n", f->nom_fest);
        printf(
            "Aqui encontraras toda la informacion que necesitas saber sobre este festival: \n"
            "------------------------------------------------------------------------------\n\n"    
        );
        printf("%s\n", f->info_fest);
        printf(
            "Selecciona una opcion: \n"
            "1. Comprar la entrada para el festival\n"
            "2. Consultar otros festivales\n"
            "3. Volver\n\n"
            "\t\tIngrese una opcion: [ ]\b\b"
        );
        scanf("%d", &input);
        fflush(stdin);
        switch (input)
        {
            case 1:
                menuEntradas(u);
                break;
            case 2:
                menuSeleccionFestival(u);
                break;
            case 3:
                eleccion=1;
                menuDentroFestival(f,u);
                break;
            
        }
    }while(eleccion==0);
}
void menuDentroFestival(Festival *f, Usuario *u)
{
    int input;
    int eleccion = 0;
    
    system("cls");

    do{
        printf(   
         "1. Ver info festival. \n"
         "2. Ver info entradas.  \n"
         "0. Cerrar.\n\n"
         "\t\tIngrese una opcion: [ ]\b\b");
        
        scanf("%d", &input);
        fflush(stdin);
        switch (input)
        {
        case 1:
          menuInfoFestival(f, u);
          break;
        case 2:
          menuEntradas(u);
        
          break; 
        case 0:

            printf("\nFin del programa.\n\n");
            eleccion=1;
            break;
        }
      }  while (eleccion==0);
    
}



void menuEntradas(Usuario *u)
{
    int input;
    int eleccion = 0;
    Entrada *ent;
    ent=(Entrada*)malloc(sizeof(Entrada));

    system("cls");

    do{
            printf(   
               
        	"Elige una entrada : \n"
			"1. Entrada VIP: \n"
			"2. Entrada Normal:  \n"
			"3. Entrada especial Reggaeton:\n"
			"4. Entrada Total Pack: \nra Raperos:\n"
			"5. Entrada para traperos:\n"
			"6. Entrada BackStage:\n"
			"7. Entrada AllIncluded:\n"
      "8. Entrada:\n"
			"0. Cerrar\n\n"
      
         "\t\tIngrese una opcion: [ ]\b\b");
        
        scanf("%i", &input);
        fflush(stdin);
      switch (input)
      {
        case 1:
          ent = getinfoEnt(1);
          menuComprarEntrada(ent, u);
          break;
        case 2:
          menuComprarEntrada(ent, u);
          break; 
		    case 3:         
          menuComprarEntrada(ent, u);
          break; 
		    case 4:
          menuComprarEntrada(ent, u);
          break; 
		    case 5:
          menuComprarEntrada(ent, u);
          break; 
		    case 6: 
          menuComprarEntrada(ent, u);        
          break; 
		    case 7:
          menuComprarEntrada(ent, u);
          break; 
        case 8:
          menuComprarEntrada(ent, u);  
          break;
        case 0:
            printf("\nFin del programa.\n\n");
            eleccion=1;
            break;
      }
    }while (eleccion==0);
    
}
void menuComprarEntrada(Entrada *e, Usuario *u){

  int input;
  int eleccion=1;
  int elec;

  
  do{
    system("cls");
    printf("\n\nInformacion entrada: %s\n\n", e->info_ent);
    printf("\tPRECIO: %i\n", e->precio);
    printf("------------------------------------");
    printf("\nQuieres comprar la entrada %s? \n", e->tipo_ent);
 
    printf("1.Si\n2.No");

    scanf("%i", &elec);

    switch(elec){
      case 1:
        printf("Gracias por la compra");
        break;
      case 2:
        menuEntradas(u);
        eleccion=0;
        break;
    }
    
  }while(eleccion=1);
}

int insertarUsuario(Usuario usuario) {
	startConn();
    sqlite3_stmt *stmt;
	char sql[] = "INSERT INTO usuario VALUES (0, ?, ?, 0)";
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}


	result = sqlite3_bind_text(stmt, 1, usuario.nom_user, strlen(usuario.nom_user), SQLITE_STATIC);
	result = sqlite3_bind_text(stmt, 2, usuario.pass_user, strlen(usuario.pass_user), SQLITE_STATIC);



	if (result != SQLITE_OK) {
		printf("Error binding parameters\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) {
		printf("Error inserting new data\n");
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (INSERT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	return SQLITE_OK;
}

int leerLinea(char *cad, int n)
{
	int i, c;

	/* 1 COMPROBACIÓN DE DATOS INICIALES EN EL BUFFER */
	c = getchar();
	if (c == EOF) {
		cad[0] = '\0';
		return 0;
	}

	if (c == '\n') {
		i = 0;
	} else {
		cad[0] = c;
		i = 1;
	}

	/* 2. LECTURA DE LA CADENA */
	for (; i < n - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
		cad[i] = c;
	}
	cad[i] = '\0';

	/*3. LIMPIEZA DEL BUFFER */ 
	if (c != '\n' && c != EOF) /* es un caracter */
		while ((c = getchar()) != '\n' && c != EOF);
 
	return 1;
}
 
void menuRegistrarUsuario() {
	Usuario usuario;
	char nombreUsuario[MAX];
	char respuesta[MAX];
	char repite = 1;
  char linea[MAX];
	
	do {
		system("cls");
		printf("\n\t\t\tREGISTRAR USUARIO\n");
		printf("\t\t\t=================\n");
		printf("\n\tIngrese el nombre de usuario: ");
		leerLinea(linea, MAX);
		sscanf(linea, "%s", nombreUsuario);

		/* Se verifica que el nombre de usuario no exista */
		if (usuarioLibre(nombreUsuario) == 1) {
			strcpy(usuario.nom_user, nombreUsuario);

			printf("\tIngrese la clave: ");
			leerLinea(usuario.pass_user, MAX);

			/* Se inserta el usuario en la bd */
			if (insertarUsuario(usuario)) {
				printf("\n\tEl usuario fue registrado satisfactoriamente!\n");

			} else {
				printf("\n\tOcurrio un error al registrar el usuario\n");
				printf("\nInténtelo mas tarde\n");
			}
		} else {
			printf("\n\tEl usuario \"%s\" ya ha sido registrado previamente\n", usuario.nom_user);
			printf("\tNo puede registrar dos usuarios con el mismo nombre de usuario.\n");
		}

		printf("\n\tDesea seguir registrando usuarios? [S/N]: ");
		leerLinea(respuesta, MAX);
 
		if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
			repite = 0;
		}

	} while (repite == 1);

  menuInicial();
}

void registrarUsuario(){

	int end, pi = 0;
	char nombreUsuario[MAX];
	char password1[MAX];
  char password2[MAX];
	
	Usuario *usuario;
  usuario=(Usuario*)malloc(sizeof(Usuario));


	do {
		system("cls");
		printf("\n\t\t\tREGISTRARSE AL SISTEMA\n");
		printf("\t\t\t-------------------------\n");
		printf("\n\t\tElige un nombre de Usuario: ");
		scanf("%s", nombreUsuario);

    int usuarioCorrecto = 0;
    while(!usuarioCorrecto){
        char userName[MAX];
        scanf("%s", userName);
        fflush(stdin);
        if(usuarioLibre(userName) == 1){
            printf("El usuario \"%s\" ya existe, elige otro", userName);

        } else{
            usuarioCorrecto = 1;
            strcpy(usuario->nom_user, userName);
        }
    }
  do{


		printf("\t\tElige un buen Password: \n");
		scanf("%s", password1);

    printf("\t\tVuelve a escribirlo (para gozar x2): \n");
		scanf("%s", password2);

    if(password1 == password2){
      strcpy(usuario->pass_user, password1);
      insertarUsuario(*usuario);
      pi=1;

    printf("\t\tPulsa un numero para continuar [] \n");
		scanf("%d", end);
    }

   } while (pi == 0);

	} while (end == 0);

}







