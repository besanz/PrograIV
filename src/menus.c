#include <stdio.h>
#include <stdlib.h>
#include <..//utils/estructuras.h>


void menuElegirFestival(Usuario *user)
{
    char *input;
    input=malloc(sizeof(char));
    int festSeleccionado;

    do{
            printf(   
                "Elige un festival : \n"
         "1.- Festival JOKINAL SOUND \n"
         "2.- Festival Tomorrowland  \n"
         "3.- Festival Vive Latino \n"
         "4.- Festival Coachella \n"
         "5.- Festival Ultra Miami \n"
         
        "q.- Cerrar\n\n"
               "Inserte seleccion: " );
          fgets(input, 5, stdin);
        sscanf(input, "%c", input);
        fflush(stdin);
        
        switch (*input)
        {
        case '1':
          festSeleccionado = 1;
          menufestival();
          break;
        case '2':
          festSeleccionado = 2;
          menufestival();
          break;
         case '3':
          festSeleccionado = 3;
          menufestival();
          break;
         case '4':
          festSeleccionado = 4;
          menufestival();
          break;
         case '5':
          festSeleccionado = 5;
          menufestival();;
          break;
        case 'q':
           
            break;
        default:
            printf("\nIntroduce una opcion valida, por favor.\n\n");
            break;
        }
      }  while (*input != 'q');
    free(input);
}


void menuFestival(Festival *festival)
{

    char *input;
    input=malloc(sizeof(char));
     do{
            printf(   
                "Elige un festival : \n"
         "1.- Informacion sobre el festival: \n"
         "2.- Informacion sobre las entradas  \n"
         "3.- Foro \n"
         "q.- Cerrar\n\n"
               "Inserte seleccion: " );
               
          fgets(input, 4, stdin);
        sscanf(input, "%c", input);
        fflush(stdin);
        
        switch (*input)
        {
        case '1':
         verInfoFestival();
            
        break;
        case '2':
         verInfoEntradas();
           
            break;
         case '3':
         abrirForo();
         
            break;
          case 'q':
           
            break;
        default:
            printf( "\nIntroduce una opcion valida, por favor.\n\n");
            break;
        }
        }while (*input != 'q');
    free(input);
}

void menuEntradas(Entrada *entrada)
{

      char *input;
    input=malloc(sizeof(char));

    do{
        printf(   
                "Elige un festival : \n"
         "1.- Entrada VIP: \n"
         "2.- Entrada normal:  \n"
         "3.- Entrada especial reggaeton:\n"
         "4.- Entrada para raperos:\n"
         "5.- Entrada para traperos:\n"
         "6.- Entrada BackStage:\n"
          "7.- Entrada AllIncluded:\n"
         "q.- Cerrar\n\n"
               "Inserte selección: " );
               
          fgets(input, 7, stdin);
        sscanf(input, "%c", input);
        fflush(stdin);
        


 switch (*input)
        {
        case '1':
         // metodo que coga informacion;
            
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
          
          
          case 'q':
           
            break;
        default:
            printf( "\nIntroduce una opcion valida, por favor.\n\n");
            break;
        }
        }while (*input != 'q');
    free(input);
}






    





















