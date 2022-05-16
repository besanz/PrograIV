#include "estructuras.h"
#include "../../../lib/sqlite3/sqlite3.h"
#include "../../db/c/getData.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../db/c/postData.h"

void menuInicial(){

	int repite = 1;
	int opcion;

	system("cls");
	do {
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
			
       // verUsuariosRegistrados();
				break;
			case 2:	
                
        //Aqui se registra un nuevo usuario
        registrarUsuario();
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
      system("cls");
			menuSeleccionFestival(usu);
			
		}else{
      break;
      intento=intento+1;
      printf("Incorrecto");
      inicioSesion();
    }
		
	} while (intento < 4 && correcto == 0);

}

void registrarUsuario(){

		printf("\n\t\tREGISTRO\n");
		printf("\t\t=============\n\n");
    char usuario[20];
    int usuarioCorrecto = 0;
    while(!usuarioCorrecto){
        char user[20];
        scanf("%s", user);
        fflush(stdin);
        if(usuarioLibre(user) == 0){
            printf("El usuario ya existe, elige otro por favor.\nUsuario:\t");
        } else{
            usuarioCorrecto = 1;
            strcpy(usuario, user);
        }
    }

    int *id_user = malloc(30*sizeof(char));
    char *nom_user = malloc(30*sizeof(char));
    char *pass_user = malloc(30 * sizeof(char));
    int ent_fest;

    printf("\nUsuario:\t");
    scanf("%s", nom_user);
    fflush(stdin);
    printf("\nContrasenya:\t");
    scanf("%s", pass_user);
    fflush(stdin);
    printf("\nUsuario registrado correctamente.\t");

    Usuario nuevoUsuario = {id_user, pass_user, nom_user, 0};
    insertarUsuario(nuevoUsuario);
    free(id_user);
    free(nom_user);
    free(pass_user);
    menuPrincipal();
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
        printf("\t\t\n---------------------Bienvenido!----------------------------------\n"   
         "\t\tElige un festival : \n"
         "\t\t1. Festival JOKINAL SOUND. \n"
         "\t\t2. Festival Tomorrowland.  \n"
         "\t\t3. Festival Vive Latino. \n"
         "\t\t4. Festival Coachella. \n"
         "\t\t5. Festival Ultra Miami. \n"
         "\t\t6. Volver. \n"
         "\t\t0. Cerrar.\n\n"
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
          menuDentroFestival(f, u);
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
    int eleccion =0;
    Entrada *ent;
    ent=(Entrada*)malloc(sizeof(Entrada));

    system("cls"); 

    do{
            printf(   
               
        	"Elige una entrada : \n"
			"1. Entrada VIP: \n"
			"2. Entrada Normal:  \n"
			"3. Entrada especial Reggaeton:\n"
			"4. EntTotal Pack: \nra Raperos:\n"
			"5. Entrada para traperos:\n"
			"6. Entrada BackStage:\n"
			"7. Entrada AllIncluded:\n"
      "8. Entrada "
			"0. Cerrar\n\n"
      
         "\t\tIngrese una opcion: [ ]\b\b");
        
        scanf("%c", &input);
        fflush(stdin);
        switch (input)
        {
      case 1:
          ent = getinfoEnt(1);
          menuComprarEntrada(ent, u);
          break;
      case 2:
          ent = getinfoEnt(2);
          menuComprarEntrada(ent, u);
          break; 
		  case 3:
          ent = getinfoEnt(3);
          menuComprarEntrada(ent, u);
          break; 
		  case 4:
          ent  = getinfoEnt(4);
          menuComprarEntrada(ent, u);
          break; 
		  case 5:
          ent = getinfoEnt(5);
          menuComprarEntrada(ent, u);
          break; 
		  case 6:
          ent = getinfoEnt(6);  
          menuComprarEntrada(ent, u);        
          break; 
		  case 7:
          ent = getinfoEnt(7);
          menuComprarEntrada(ent, u);
          break; 
      case 8:
          ent = getinfoEnt(8);  
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

  system("cls");
  
  do{
    printf("\n\nInformacion entrada: %s\n\n", e->info_ent);

    printf("\tPRECIO: %i\n", e->precio);
    
    printf("------------------------------------");

    printf("\nQuieres comprar la entrada %s? \n", e->tipo_ent);

    

    printf("1.Si\n2.No");

    scanf("%i", &elec);

    switch(elec){
      case 1:
        //se anyade la entrada al usuario
        printf("Gracias por la compra");
        break;
      case 2:
        menuEntradas(u);
        eleccion=0;
        break;
    }
    
  }while(eleccion=1);
}
 

/*
void registrarUsuario(){

    printf("\n\t\tREGISTRAR AL SISTEMA\n");
		printf("\t\t\t===================\n");
		printf("\n\t\tUSUARIO: ");

    char usuario[20];
    int usuarioCorrecto = 0;
    while(!usuarioCorrecto){
        char user[20];
        scanf("%s", user);
        fflush(stdin);
        if(usuarioDisponible(user) == 0){
            printf("%s ya existe. Intentalo de nuevo", user);
            printf("\n\t\tUSUARIO: ");
        } else{
            usuarioCorrecto = 1;
            strcpy(usuario, user);
        }
    }
    char *id_user =(char*) malloc(20 *sizeof(char));
    char *nom_user = (char*)malloc(20 *sizeof(char));
    char *pass_user =(char*)malloc(20 *sizeof(char));
    int ent_fest;


    printf("\nPassword:\t");
    scanf("%s", pass_user);
    fflush(stdin);
    printf("\nComo te llamas?:\t");
    scanf("%s", nom_user);
    fflush(stdin);
    ent_fest = 0;
    printf("En este momento tienes %i entradas", ent_fest);


    int i = 0;
    while(i == 0){
        char verify[5];
        printf("\nEstas seguro que deseas crear un usuario (SI/NO):\t");
        scanf("%s", verify);
        fflush(stdin);
        if(strcmp(verify, "YES") == 0){
            i=1;
        } else{
            if(strcmp(verify, "NO") == 0) {
                break;
            } else{
                printf("Escribe YES o NO. PORFAVOR.\n");
            }
        }
    }

    printf("Usuario: %s. Nombre: %s. Password: %s. Entradas Desp: %s. \n", 
    id_user, nom_user, pass_user, ent_fest);
    Usuario newUser = {id_user, nom_user, pass_user, ent_fest};

    int resultado=0;
    resultado=insertUsuario(newUser);

    free(id_user);
    free(pass_user);
    free(nom_user);
    
    menuInicial();
}

int getFilas(char sql[]){
	startConn();
    sqlite3_stmt *stmt;
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}

	int filas = 0;
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			filas++;
		}
	} while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
		return result;
	}
	return filas;
}

int usuarioDisponible(char *nom_user) {
	char sql[] = "SELECT * FROM Usuario WHERE usuario = '";
	strcat(sql, nom_user);
	strcat(sql, "'");
	if(getFilas(sql) > 0) {
		return 0;
	} else{
		return 1;
	}
}
*/


 




