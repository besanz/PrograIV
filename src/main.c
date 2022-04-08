#include <stdio.h>
#include <stdlib.h>


void main(void){

	int repite = 1;
	int opcion;
	
	do {
		printf("\n\t\t\tMENU INICIAL\n");
		printf("\t\t\t============\n\n");
		printf("\t\t1. Ver usuarios registrados\n");
		printf("\t\t2. Registrar usuario nuevo\n");
		printf("\t\t3. Ingresar al sistema\n");
		printf("\t\t0. Salir\n\n");
		printf("\t\tIngrese su opcion: [ ]\b\b");
		
		scanf("%i", &opcion);

		switch (opcion) {
			case 1:
				
				break;

			case 2:
				
				break;

			case 3:
				inicioSesion();
				break;

			case 0:
				repite = 0;
				break;
		}

	} while (repite == 1);

	char *cd = "fin del programa";

	printf("%s\n", cd);

	





}
void inicioSesion(){

<<<<<<< HEAD
	int correcto = 0;
	int intento = 0;
	
=======
	int correcto;
	int intento;
	int logeoExitoso;

>>>>>>> d2647fec1ad045a7dce578f40cdea44b131a574e

	char *nombreUsuario;
	char *password;

	do {
		printf("\n\t\t\tINGRESAR AL SISTEMA\n");
		printf("\t\t\t===================\n");

		printf("\n\t\tUSUARIO: ");
		
		scanf("%s", &nombreUsuario);

		printf("\t\tCLAVE: ");

		scanf("%s", &password);
		
		
		if (login(nombreUsuario, password)) {
			correcto = 1;
			
		} else {
			printf("\n\n\t\tUsuario y/o password incorrectos");
			intento++;
			getchar();
		}
	} while (intento < 4 && correcto == 0);

<<<<<<< HEAD
	if (correcto == 1) {
		printf("\nBienvenido %s", //nomuser);
=======
	if (logeoExitoso == 1) {
		
>>>>>>> d2647fec1ad045a7dce578f40cdea44b131a574e
		
	} else {
		printf("\n\tHa sobrepasado el numero maximo de intentos permitidos\n");
		getchar();
	}

}
char login(char nom_user[], char pass_user[]) {
	FILE *archivo;
	int correcto;
	int logeoExitoso;
	Usuario usuario;

<<<<<<< HEAD
	archivo = fopen(basedatos, "rb");
=======
	archivo = fopen("AÑADIR_NOMBRE_ARCHIVO", "rb");
>>>>>>> d2647fec1ad045a7dce578f40cdea44b131a574e

	//Creo que hay que añadir un input, de usuario y contraseña y pasar las variables ahi.
	if (archivo == NULL) {
		correcto = 0;

	} else {
		correcto = 0;
		fread(&usuario, sizeof(usuario), 1, archivo);
		while (!feof(archivo)) {
<<<<<<< HEAD
			if (strcmp(usuario.nom_user, nombreUsuario) == 0 && strcmp(usuario.pass_user, password) == 0) {
=======
			if (strcmp(usuario.nom_user, 'nombreUsuario') == 0 && strcmp(usuario.pass_user, 'password') == 0) {
>>>>>>> d2647fec1ad045a7dce578f40cdea44b131a574e
				
				correcto = 1;
				break;
			}

			fread(&usuario, sizeof(usuario), 1, archivo);
		}
		fclose(archivo);
	}

	return correcto;
	//yer
}