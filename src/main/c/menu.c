#include "../../main/c/estructuras.h"
#include "../../db/c/getData.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
                verUsuariosRegistrados();
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
	char *cd = "Fin del Programa";
	printf("%s\n", cd);
}

void verUsuariosRegistrados(){
//TODO
}

void registrarUsuario(){
//TODO
}

void inicioSesion(){

	int correcto = 0;
	int intento = 0;
	char *nombreUsuario;
	char *password;

	do {
		printf("\n\t\t\tINGRESAR AL SISTEMA\n");
		printf("\t\t\t===================\n");
		printf("\n\t\tUSUARIO: ");
		scanf("%s", &nombreUsuario);
		printf("\t\tCLAVE: ");
		scanf("%s", &password);
		if (login(nombreUsuario, password) == 1) {
			correcto = 1;
            menuFestival();
		} else {
			printf("\n\n\t\tUsuario y/o password incorrectos");
			intento++;
			getchar();
		}
	} while (intento < 4 && correcto == 0);

	if (correcto == 1) 
	{
		menuFestival();
	} 
	else {
		printf("\n\tHa sobrepasado el numero maximo de intentos permitidos\n");
		getchar();
	}
}

int login(char id_user[], char pass_user[]) {
	
	char *nombreUsuario;
	char *password;
	int correcto;
	int logeoExitoso;
	Usuario usuario;

	correcto = 0;

	printf("INICIAR SESION\n");
	printf("Usuario:\n");
	scanf(*nombreUsuario);
	printf("Password:\n");
	scanf(*password);
	
	if (strcmp(usuario.nom_user, &nombreUsuario) == 0 && strcmp(usuario.pass_user, &password) == 0) {			
		correcto = 1;         
    }
	printf("Logueo exitoso!");
	return correcto;	
}


int menuSeleccionFestival()
{
    char *input;
    input=malloc(sizeof(char));


    do{
            printf(   
                "Elige un festival : \n"
         "1.- Festival JOKINAL SOUND \n"
         "2.- Festival Tomorrowland  \n"
         "3.- Festival Vive Latino \n"
         "4.- Festival Coachella \n"
         "5.- Festival Ultra Miami \n"
         "q.- Cerrar\n\n"
         "\t\tIngrese una opcion: [ ]\b\b");
        fgets(input, 5, stdin);
        sscanf(input, "%c", input);
        fflush(stdin);
        switch (*input)
        {
        case '1':
          
          break;
        case '2':
        
          break; 
         case '3':
        
          break;
         case '4':
        
          break;
         case '5':
          
          break;
        default:
            printf("\nIntroduce una opcion valida, por favor.\n\n");
            break;
        }
      }  while (*input != 'q');
    free(input);
}

int menudentroFestival()
{
    char *input;
    input=malloc(sizeof(char));
    

    do{
            printf(   
               
         "1.- Ver info festival: \n"
         "2.- Ver info entradas:  \n"
         "q.- Cerrar\n\n"
         "\t\tIngrese una opcion: [ ]\b\b");
        fgets(input, 2, stdin);
        sscanf(input, "%c", input);
        fflush(stdin);
        switch (*input)
        {
        case '1':
          
          break;
        case '2':
        
          break; 
        default:
            printf("\nIntroduce una opcion valida, por favor.\n\n");
            break;
        }
      }  while (*input != 'q');
    free(input);
}

int menuEntradas()
{
    char *input;
    input=malloc(sizeof(char));
    

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
        fgets(input, 7, stdin);
        sscanf(input, "%c", input);
        fflush(stdin);
        switch (*input)
        {
        case '1':
          
          break;
        case '2':
        
          break; 
		  case '3':
        
          break; 
		  case '4':
        
          break; 
		  case '5':
        
          break; 
		  case '6':
        
          break; 
		  case '7':
        
          break; 
		 
        default:
            printf("\nIntroduce una opcion valida, por favor.\n\n");
            break;
        }
      }  while (*input != 'q');
    free(input);
}

