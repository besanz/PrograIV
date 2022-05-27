#include <iostream>
#include <string.h>
#include <stdlib.h>


extern "C"
{
#include "estructuras.h"
#include "../../../lib/sqlite3/sqlite3.h"
#include "../../db/c/getData.h"
#include "../../db/c/postData.h"
}


using namespace std;
using namespace containers;

void loginCliente(void)
{

    int resultLogin = 0;
    char *dni;
    dni = new char[30];
    char *contrasenya;
    contrasenya = new char[18];

    cout << "**********************Bienvenido**********************" << endl;
    cout << "INICIAR SESION" << endl;

    do
    {
        cout << "Introduce el DNI: ";
        cin >> dni;
        cout << endl;

        cout << "Introduce contrasena: " << endl;
        cin >> contrasenya;
        cout << endl;

        // *(contrasenya + strlen(contrasenya) - 1) = '\0'; //para quitar el salto de linea que añade sscanf

        resultLogin = getLogin(dni, contrasenya, 0);

        if (resultLogin == 0)
        {
            cout << FGREN "INICIO DE SESION CORRECTO" << endl;
            cout << CLEAR << endl;
            ClienteCpp c(getInfoCliente(dni));
            menuCliente(c);
        }
        else
            cout << FRED << "Error en el inicio de sesion" << FCYAN << endl;
    } while (resultLogin != 0);

    delete[] dni;
    delete[] contrasenya;
}