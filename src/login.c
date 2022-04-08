#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "login.h"
#include "main.h"


void login(void)
{
    int resultLogin = 0;
    char *dni;
    dni = malloc(30 * sizeof(char));
    char *contrasenya;
    contrasenya = malloc(18 * sizeof(char));
    Usuario *usu;
    usu=(Usuario *)malloc(sizeof(Usuario))
    
    printf("**********************Bienvenido**********************\n");
    printf("INICIAR SESION\n");
    do
    {
        printf("Introduce el DNI: ");
        fgets(dni, 30, stdin);
        sscanf(dni, "%c", dni);
        fflush(stdin);

        printf("Introduce contraseña: ");
        fgets(contrasenya, 18, stdin);
        sscanf(contrasenya, "%c", contrasenya);
        fflush(stdin);
        *(contrasenya + strlen(contrasenya) - 1) = '\0'; 

        resultLogin = getLogin(dni, contrasenya, 1);

        if (resultLogin == 0)
        {
            printf("%sINICIO DE SESION CORRECTO\n", FGREN);
            printf(CLEAR);
            usu = getInfoUsuario(dni);
            menu(usu);
        }
        else
            printf(FRED "Error en el inicio de sesion\n" FCYAN);
    } while (resultLogin != 0);

    free(dni);
    dni = NULL;
    free(contrasenya);
    contrasenya = NULL;
    
    free(usu);
    usu = NULL;
}