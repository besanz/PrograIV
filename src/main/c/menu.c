#include "../../main/c/estructuras.h"
#include "../../db/c/getData.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../db/c/postData.h"
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
void menuComprarEntrada(Entrada *e, Usuario *u){
  int input;
  int eleccion=0;
  do{
    printf("\nQuieres comprar la entrada %s? \n1.Si\n2.No", e->tipo_ent);
    
  }while(eleccion=1);
}
void menuEntradas(Usuario *u)
{
    int input;
    int eleccion =0;
    Entrada *ent;
    ent=(Entrada*)malloc(sizeof(Entrada));

    
    

    do{
            printf(   
               
        	"Elige una entrada : \n"
			"1.- Entrada VIP: \n"
			"2.- Entrada Normal:  \n"
			"3.- Entrada especial Reggaeton:\n"
			"4.- Entrada para Raperos:\n"
			"5.- Entrada para traperos:\n"
			"6.- Entrada BackStage:\n"
			"7.- Entrada AllIncluded:\n"
			"q.- Cerrar\n\n"
      
         "\t\tIngrese una opcion: [ ]\b\b");
        
        scanf("%c", &input);
        fflush(stdin);
        switch (input)
        {
        case 1:
          
          break;
        case 2:
        
          break; 
		  case 3:
        
          break; 
		  case 4:
        
          break; 
		  case 5:
        
          break; 
		  case 6:
        
          break; 
		  case 7:
        
          break; 
		 
        default:
            printf("\nIntroduce una opcion valida, por favor.\n\n");
            break;
        }
      }  while (eleccion=0);
    
}
void menudentroFestival(Festival *f, Usuario *u)
{
    int input;
    int eleccion = 0;

    do{
            printf(   
               
         "1.- Ver info festival: \n"
         "2.- Ver info entradas:  \n"
         "0.- Cerrar\n\n"
         "\t\tIngrese una opcion: [ ]\b\b");
        
        scanf("%d", &input);
        fflush(stdin);
        switch (input)
        {
        case 1:
          printf("INFORMACION DE %s: \n\n%s\n\n\n", f->nom_fest, f->info_fest);
          menudentroFestival(f, u);
          break;
        case 2:
          menuEntradas(u);
        
          break; 
        case 0:

            printf("\nFin del programa\n\n");
            eleccion=1;
            break;
        }
      }  while (eleccion=0);
    
}

void menuSeleccionFestival(Usuario *u)
{ 
    int input;
    int eleccion = 0;
    Festival *f;
    f= (Festival*)malloc(sizeof(Festival));


    do{
            printf("\n---------------------Bienvenido errege %s! ----------------------------------\n"   
                "Elige un festival : \n"
         "1.- Festival JOKINAL SOUND \n"
         "2.- Festival Tomorrowland  \n"
         "3.- Festival Vive Latino \n"
         "4.- Festival Coachella \n"
         "5.- Festival Ultra Miami \n"
         "0.- Cerrar\n\n"
         "\t\tIngrese una opcion: [ ]\b\b", u->id_user);
        
        scanf("%d", &input);
        fflush(stdin);
        switch (input)
        {
        case 1:
          f = getFestival("JOKINAL SOUND");
        	menudentroFestival(f, u);
        	eleccion=1;
          
          break;
        case 2:
           f = getFestival("Tomorrowland");
        	menudentroFestival(f, u);
        	eleccion=1;
        
          break; 
        case 3:
          f = getFestival("Vive Latino");
        	menudentroFestival(f, u);
        	eleccion=1;
          break;
        case 4:
          f = getFestival("Coachella");
        	menudentroFestival(f, u);
        	eleccion=1;
          break;
        case 5:
          f = getFestival("Ultra Miami");
        	menudentroFestival(f, u);
        	eleccion=1;
          break;
        case 0:
            printf("\n\n\n");
            break;
        }
      }  while (eleccion == 0);
    
}
void inicioSesion(){

	int correcto = 0;
	int intento = 0;
	char nombreUsuario[20];
	char password[20];
	
	Usuario *usu;
    usu=(Usuario*)malloc(sizeof(Usuario));

	do {
		
		printf("\n\t\t\tINGRESAR AL SISTEMA\n");
		printf("\t\t\t===================\n");
		printf("\n\t\tUSUARIO: ");
		
		scanf("%s", nombreUsuario);
		printf("\t\tCLAVE: ");
		
		scanf("%s", password);


		usu = getUsuario(nombreUsuario);
		
		if(strcmp(usu->id_user, nombreUsuario) == 0 && strcmp(usu->pass_user, password) == 0){
			
			printf("\nEL TAJAAASS\n");
			correcto=1;
			intento=intento+1;
		}
		
	} while (intento < 4 && correcto == 0);

	if (correcto == 1) 
	{
		menuSeleccionFestival(usu);
		
	} 
	else {
		printf("\n\tHa sobrepasado el numero maximo de intentos permitidos\n");
		
	}
}


void menuInicial(){

	int repite = 1;
	int opcion;
	
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
			
                //verUsuariosRegistrados();
				break;
			case 2:	
                
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


 




