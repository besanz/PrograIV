#include <stdio.h>
#include <stdlib.h>
#include "../utils/estructuras.h"

void menuPrincipal()
{
     if (startConn() == 0)
    {
        return 0;
    }

    char *input;
    int num;
    do
    {
        printf(
               "1.- Inicio de sesion:\n"
               "2.- Crear un usuario:\n"
               "q.- Cerrar\n\n"
               "Inserte selección: ");

        fgets(input, 2, stdin);
        sscanf(input, "%c", input);
        fflush(stdin);

        switch (*input)
        {
        case '1':
             //Limpia el terminal
          //  meter aqui el login
          inicioSesion();
            break;
        case '2':
            
          // meter aqui el crear usuario    
            break;
        case 'q':
            printf(FRED "\nSaliendo.\n\n");
            break;
        default:
            printf(FRED "\nIntroduce una opcion valida, por favor.\n\n");
            break;
        }
    } while (*input != 'q');

    printf(RESET); //Resetea los atributos de fuente cuando salimos del programa
    sqlite3_close(db);
    free(input);
    input = NULL;

    return 0;
}

void inicioSesion(){

    char *inp;
    int numero;
    

    printf("Introduce un nombre: \n");
    scanf("%s",inp);
    printf("Introduce una contraseña: \n");
    scanf("%s",inp);

do{
    printf(
               "1.- Festival :\n"
               "2.- Festival :\n"
               "3.- Festival :\n"
               "4.- Festival :\n"
               "5.- Festival :\n"
               "q.- Cerrar\n\n"
               "Inserte selección: ");

        fgets(inp, 2, stdin);
        sscanf(inp, "%c", inp);
        fflush(stdin);

        switch (*inp)
        {
        case '1':
             //Limpia el terminal
          //  meter aqui el login
          inicioSesion();
            break;
        case '2':
            
          // meter aqui el crear usuario    
            break;
             case '3':
             //Limpia el terminal
          //  meter aqui el login
          inicioSesion();
            break;
             case '4':
             //Limpia el terminal
          //  meter aqui el login
          inicioSesion();
            break;
             case '5':
             //Limpia el terminal
          //  meter aqui el login
          inicioSesion();
            break;
        case 'q':
            printf(FRED "\nSaliendo.\n\n");
            break;
        default:
            printf(FRED "\nIntroduce una opcion valida, por favor.\n\n");
            break;
        }
    } while (*input != 'q');










}










}






}

 