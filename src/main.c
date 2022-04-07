#include <stdio.h>
#include <stdlib.h>


typedef struct{
	int cod_fest;
	char *nom_fest;
	char *info_fest;
}Festival;

typedef struct{
	int cod_ent;
	char *tipo_ent;
	char *info_ent;
}Entrada;

typedef struct{
	int id_user;
	char *nom_user;
	char *pass_user;
	int num_ent;
}Usuario;

typedef struct{
	int cod_foro;
	char *info_foro;
}Foro;

typedef struct{
	int cod_zona;
	int cod_dj;
	int cod_gen;
}Zona;

typedef struct{
	int cod_dj;
	char *nom_dj;
	char *info_dj;
}Dj;

typedef struct{
	int cod_gen;
	char *nom_gen;
	char *desc_gen;
}Genero;


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

	int correcto;
	int intento;
	int logeoExitoso;


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

	if (logeoExitoso == 1) {
		
		
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

	archivo = fopen("AÑADIR_NOMBRE_ARCHIVO", "rb");

	//Creo que hay que añadir un input, de usuario y contraseña y pasar las variables ahi.
	if (archivo == NULL) {
		logeoExitoso = 0;

	} else {
		correcto = 0;
		fread(&usuario, sizeof(usuario), 1, archivo);
		while (!feof(archivo)) {
			if (strcmp(usuario.nom_user, 'nombreUsuario') == 0 && strcmp(usuario.pass_user, 'password') == 0) {
				
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