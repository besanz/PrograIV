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
      getListaUsuarios();
				break;
			case 2:	
                
        //Aqui se registra un nuevo usuario
        //registrarUsuario();
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

			menuSeleccionFestival(usu);
			
		}else{
      break;
      intento=intento+1;
      printf("Incorrecto");
      inicioSesion();
    }
		
	} while (intento < 4 && correcto == 0);

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
        printf("Bienvenido al %s", f->nom_fest);
        printf(
            "Aqui encontraras toda la informacion que necesitas saber sobre este festival: \n"
            "------------------------------------------------------------------------------\n"    
        );
        printf("%s\n", f->info_fest);
        printf(
            "Selecciona una opcion: \n"
            "1- Comprar la entrada para el festival\n"
            "2- Consultar otros festivales\n"
            "3-Volver\n\n"
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
      "8. Entrada "
			"0. Cerrar\n\n"
      
         "\t\tIngrese una opcion: [ ]\b\b");
        
        scanf("%c", &input);
        fflush(stdin);
        switch (input)
        {
      case 1:
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
void InfoFestival(Festival *f)
{

  




  
}
 

/*void registrarUsuario(){

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

}
*/




