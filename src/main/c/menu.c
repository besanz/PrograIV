#include "foro.h"
#include "estructuras.h"
#include "../../../lib/sqlite3/sqlite3.h"
#include "../../db/c/getData.h"
#include "../../db/c/postData.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"
#define MAX 30
#define LONGITUD_MAXIMA_CADENA 1000

void menuInicial(){

  int repite = 1;
  int opcion;

  
  do {
    system("cls");
    printf("Cargando...");
    setTimeout(1300);
    system("cls");
    printf("\n\t\t\t\tMENU INICIAL\n");
    printf("\t\t------------------------------------------\n\n");
    printf("\t\t1. Ver Usuarios Registrados\n");
    printf("\t\t2. Registrar Usuario Nuevo\n");
    printf("\t\t3. Iniciar Sesion\n");
    printf("\t\t0. Salir\n\n");
    printf("\t\tIngrese una opcion: [ ]\b\b");
    scanf("%i", &opcion);

    switch (opcion) {
      case 1:
       system("cls");
       printf("Cargando lista de usuarios desde la base de datos...");
       setTimeout(3333);
       system("cls");
       menuVerUsuarios();
            
      case 2: 
       system("cls");
       printf("Redirigiendo a registro...");
       setTimeout(1600);
       system("cls");
        menuRegistrarUsuario();
        break;
      case 3:
        system("cls");
       printf("Redirigiendo a inicio de sesion...");
       setTimeout(1400);
       system("cls");
          inicioSesion();
        break;
      case 0:
        system("cls");
          printf("Cerrando programa...");
  setTimeout(2500);
  system("cls");
  exit(0);
        repite = 0;
        break;
    }   
  } while (repite == 1);
  
  
    printf("Cerrando programa...");
  setTimeout(2500);
  system("cls");
  exit(0);
} 

int comprobarUsuario(char *usuario, char *contrasenya){
  startConn();
  

char sql[] = "SELECT nom_user, pass_user FROM Usuario WHERE nom_user = ?";
    sqlite3_stmt *stmt;
  int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

  if (result != SQLITE_OK) {
    printf("Error preparing statement (SELECT)\n");
    printf("%s\n", sqlite3_errmsg(db));
    return result;
  } else {
    sqlite3_bind_text(stmt, 1, usuario, (-1), SQLITE_STATIC);
  }

  int usuarioValido = 0;
  do {
    result = sqlite3_step(stmt) ;
    if (result == SQLITE_ROW) {
      if(strcmp(usuario, (const char*)sqlite3_column_text(stmt,0)) == 0 &&
      strcmp(contrasenya,(const char*)sqlite3_column_text(stmt,1)) == 0){
        usuarioValido = 1;
        break;
      }

    }
  } while (result == SQLITE_ROW);

  result = sqlite3_finalize(stmt);
  if (result != SQLITE_OK) {
    printf("Error finalizing statement (SELECT)\n");
    printf("%s\n", sqlite3_errmsg(db));
    return result;
  }
  return usuarioValido;
}
void inicioSesion(){

  int correcto = 0;
  int intento = 0;
  char nombreUsuario[20];
  char password[20];
  char respuesta[MAX];
  
  Usuario *usu;
  usu=(Usuario*)malloc(sizeof(Usuario));


  do {
    system("cls");
    printf("\n\t\t\tINGRESAR AL SISTEMA\n");
    printf("\t\t\t----------------------\n");
    printf("\n\t\tUSUARIO: ");
    scanf("%s", nombreUsuario);
    printf("\t\tCLAVE: ");
    scanf("%s", password);

    usu = getUsuario(nombreUsuario);
    
    if(comprobarUsuario(nombreUsuario, password) == 1){

      menuSeleccionFestival(usu);
      
    }else{
      printf("\n\tUsuario o Password no coinciden. Intentar de nuevo? [S/N]: ");
      leerLinea(respuesta, MAX);
 
    if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
      intento++;
    }

    }
    
  } while (intento < 4 && correcto == 0);

}

void menuVerUsuarios()
{ 
  int a=1;
  int input;

  do {  
    
    getListaUsuarios();
    printf("\n---------------------------\n");
    printf("\t1. Volver. \n"
         "\t2. Cerrar. \n\n"
         "\tIngrese una opcion: [ ]\b\b");
         
    scanf("%d", &input);
    fflush(stdin);
    switch (input) {
      case 1:
        system("cls");
        printf("Volvindo al Menu Inicial...");
        setTimeout(2500);
        system("cls");
        menuInicial();
        break;
      case 2: 
        system("cls");
        printf("Cerrando programa...");
        setTimeout(2000);
        system("cls");
        exit(0);   
        break;      
      case 0:
        a = 0;
        break;
    }  
    
  } while (a == 1);
  printf("\nFIN DEL PROGRAMA");
  
  system("cls");
  //printf("Cerrando programa...");
  //setTimeout(2500);
  //system("cls");
  //exit(0);
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
      printf("Cargando los mejores festivales para ti, %s...", u->nom_user);
      setTimeout(3500);
      system("cls");
        printf("\t\t\n-------------------- Bienvenido, %s! ---------------------------\n\n", u->nom_user); 
        printf( "\t\tElige un festival : \n\n"
         "\t\t1. Festival JOKINAL SOUND. \n"
         "\t\t2. Festival Tomorrowland \n"
         "\t\t3. Festival Vive Latino. \n"
         "\t\t4. Festival Coachella. \n"
         "\t\t5. Festival Ultra Miami. \n"
         "\t\t6. Volver. \n"
         "\t\t\nIngrese una opcion: [ ]\b\b");
        
        scanf("%d", &input);
        fflush(stdin);
        switch (input)
        {
        case 1:
      system("cls");
       printf("Cargando informacion de JOKINAL SOUND...");
       setTimeout(2300);
       system("cls");

          f = getFestival("JOKINAL SOUND");
          menuDentroFestival(f, u);
          eleccion=1;
          
          break;
        case 2:
              system("cls");
       printf("Cargando informacion de Tomorrowland...");
       setTimeout(2300);
       system("cls");
           f = getFestival("Tomorrowland");
          menuDentroFestival(f, u);
          eleccion=1;
        
          break; 
        case 3:
              system("cls");
       printf("Cargando informacion de Vive Latino...");
       setTimeout(2300);
       system("cls");
          f = getFestival("Vive Latino");
          menuDentroFestival(f, u);
          eleccion=1;
          break;
        case 4:
              system("cls");
       printf("Cargando informacion de Coachella...");
       setTimeout(2300);
       system("cls");
          f = getFestival("Coachella");
          menuDentroFestival(f, u);
          eleccion=1;
          break;
        case 5:
              system("cls");
       printf("Cargando informacion de Ultra Miami...");
       setTimeout(2300);
       system("cls");
          f = getFestival("Ultra Miami");
          menuDentroFestival(f, u);
          eleccion=1;
          break;
        case 6:
          eleccion=1;
          system("cls");
          printf("Volviendo al Menu Inicial...");
          setTimeout(2500);
          system("cls");
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
      system("cls");
       printf("Espere por favor...");
       setTimeout(1500);
       system("cls");
        printf("Bienvenido al %s\n", f->nom_fest);
        printf(
            "Aqui encontraras toda la informacion que necesitas saber sobre este festival: \n"
            "------------------------------------------------------------------------------\n\n"    
        );
        printf("%s\n", f->info_fest);
        printf(
            "Selecciona una opcion: \n\n"
            "1. Comprar la entrada para el festival\n"
            "2. Consultar otros festivales\n"
            "3. Volver\n\n"
            "\t\t\nIngrese una opcion: [ ]\b\b"
        );
        scanf("%d", &input);
        fflush(stdin);
        switch (input)
        {
            case 1:
                system("cls");
                printf("Cargando menu de entradas...");
                setTimeout(1700);
                system("cls");
                menuEntradas(u);
                break;
            case 2:
                system("cls");
                printf("Conectando con la base de datos...");
                setTimeout(2000);
                system("cls");
                menuSeleccionFestival(u);
                break;
            case 3:
                system("cls");
                printf("Redirigiendo a %s...", f->nom_fest);
                setTimeout(2300);
                system("cls");
                eleccion=1;
                menuDentroFestival(f,u);
                break;
            
        }
    }while(eleccion==0);
}
void menuForo(Usuario *u, Festival *f){
  int index = 0;
  int input;
  do{
  system("cls");
    printf("Sera redirigido al foro. Recuerde ser respetuoso...");
    setTimeout(2300);
    system("cls");
    system("cls");
    printf("BIENVENIDO AL FORO DEL FESTIVAL %s, %s",f->nom_fest, u->nom_user);
    leerForo();
    printf("\n1. Escribir en el foro\n2. Actualizar el foro\n3. Volver\n0. Salir\n\n[ ]\b\b");
    scanf("%d", &input);
    switch(input){
      case 1:
        escribirForo();
        break;
      case 2:
        leerForo();
        break;
      case 3:
        system("cls");
        printf("Volviendo. Espere un momento por favor...");
        setTimeout(2121);
        system("cls");
        menuSeleccionFestival(u);
        break;
      case 0:
        menuDentroFestival(f,u); 
        break;
    }

    

  }while(index==0);
  
}
void menuDentroFestival(Festival *f, Usuario *u)
{
    int input;
    int eleccion = 0;
    
    

    do{
      system("cls");
        printf(   
         "1. Ver informacion sobre el festival \n"
         "2. Ver informacion de las entradas \n"
         "3. Acceder al foro del festival \n"
         "0. Cerrar\n\n"
         "\tIngrese una opcion: [ ]\b\b");
        
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
        case 3:
          menuForo(u, f);
          break;
        case 0:

        system("cls");
        printf("Cerrando programa...");
        setTimeout(2000);
        system("cls");
        exit(0);
        }
      }  while (eleccion==0);
    
}



void menuEntradas(Usuario *u)
{
    int input;
    int eleccion = 0;
    Entrada *ent;
    ent=(Entrada*)malloc(sizeof(Entrada));

    

    do{
    system("cls");
    printf("Buscando entradas en la base de datos...");
    setTimeout(2300);
      system("cls");
            printf(   
               
          "Elige una entrada : \n\n"
      "1. Entrada VIP: \n"
      "2. Entrada Normal:  \n"
      "3. Entrada especial Reggaeton:\n"
      "4. Entrada Total Pack: \n"
      "5. Entrada para traperos:\n"
      "6. Entrada BackStage:\n"
      "7. Entrada All Included:\n"
      "8. Entrada:\n\n"
      "0. Cerrar\n\n"
      
         "\t\tIngrese una opcion: [ ]\b\b");
        
        scanf("%i", &input);
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
          ent = getinfoEnt(4);
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
          system("cls");
          printf("Cerrando programa...");
          setTimeout(2500);
          system("cls");
          exit(0);
            eleccion=1;
            break;
      }
    }while (eleccion==0);
    
}
void menuComprarEntrada(Entrada *e, Usuario *u){

  int input;
  int eleccion=1;
  int elec;
  char respuesta[MAX];

  
  do{
    system("cls");
    printf("Reservando las mejores entradas...");
    setTimeout(1700);
    system("cls");
    printf("\n\nInformacion entrada: %s\n\n", e->info_ent);
    printf("\tPRECIO: %i\n", e->precio);
    printf("------------------------------------\n");
    printf("\nQuieres comprar la entrada %s? \n", e->tipo_ent);
 
    printf("\n1. Si\n2. No\n3. Salir \n\n");
    printf("\tIngrese una opcion: [ ]\b\b");

    scanf("%i", &elec);

    switch(elec){
      case 1:
          system("cls");
        printf("\nGracias por tu compra. Redirigiendo... ");
        setTimeout(2500);
        menuSeleccionFestival(u);
        break;
      case 2:
        system("cls");
        printf("De acuerdo. Volviendo al menu de entradas...");
        setTimeout(2500);
        system("cls");
        menuEntradas(u);
        eleccion=0;
        break;
        case 3:
        system("cls");
        printf("Cerrando programa...");
        setTimeout(2000);
        system("cls");
        exit(0);
    }
    
  }while(eleccion=1);
          
}

int insertarUsuario(Usuario usuario) {
  startConn();
  sqlite3_stmt *stmt;
  char sql[] = "INSERT INTO Usuario(nom_user, pass_user, ent_fest) VALUES (?, ?, 1)";
  
  
  int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
  if (result != SQLITE_OK) {
    printf("Error preparing statement (INSERT)\n");
    printf("%s\n", sqlite3_errmsg(db));
    return result;
  }

  sqlite3_bind_text(stmt, 1, usuario.nom_user, -1, SQLITE_STATIC);
  sqlite3_bind_text(stmt, 2, usuario.pass_user, -1, SQLITE_STATIC);

  
  if (result != SQLITE_OK) {
    printf("Error binding parameters\n");
    printf("%s\n", sqlite3_errmsg(db));
    return result;
  }

  result = sqlite3_step(stmt);

  
  if (result != SQLITE_DONE) {
    printf("Error inserting new data\n");
    return result;
  }

  result = sqlite3_finalize(stmt);
  if (result != SQLITE_OK) {
    printf("Error finalizing statement (INSERT)\n");
    printf("%s\n", sqlite3_errmsg(db));
    return result;
  }
  

  return result;
}

int leerLinea(char *cad, int n)
{
  int i, c;

  //1 COMPROBACIÓN DE DATOS INICIALES EN EL BUFFER 
  c = getchar();
  if (c == EOF) {
    cad[0] = '\0';
    return 0;
  }

  if (c == '\n') {
    i = 0;
  } else {
    cad[0] = c;
    i = 1;
  }

  //2. LECTURA DE LA CADENA 
  for (; i < n - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    cad[i] = c;
  }
  cad[i] = '\0';

  //3. LIMPIEZA DEL BUFFER  
  if (c != '\n' && c != EOF) //es un caracter
    while ((c = getchar()) != '\n' && c != EOF);
 
  return 1;
}
 
void menuRegistrarUsuario() {
  Usuario usuario;
  usuario.nom_user = (char*)malloc(MAX*sizeof(char));
  usuario.pass_user = (char*)malloc(MAX*sizeof(char));
  char nombreUsuario[MAX];
  char respuesta[MAX];
  char repite = 1;
  char linea[MAX];
  
  do {
    system("cls");
    printf("\n\t\t\tREGISTRAR USUARIO\n");
    printf("\t\t\t--------------------\n\n");
    printf("\n\tIngrese el nombre de usuario: ");
    scanf("%s", nombreUsuario);

    //Se verifica que el nombre de usuario no exista 
    if (usuarioLibre(nombreUsuario) == 1) {
      strcpy(usuario.nom_user, nombreUsuario);

      printf("\tIngrese la clave: ");
      leerLinea(usuario.pass_user, MAX);

      //Se inserta el usuario en la bd 
      if (insertarUsuario(usuario)==SQLITE_OK) {
        printf("\n\tEl usuario fue registrado satisfactoriamente!\n");

      } else {
        printf("\n\tOcurrio un error al registrar el usuario\n");
        printf("\nInténtelo mas tarde\n");
      }
    } else {
      printf("\n\tEl usuario \"%s\" ya ha sido registrado previamente\n", nombreUsuario);
      printf("\tNo puedes registrar dos usuarios con el mismo nombre de usuario.\n");
    }

    printf("\n\tDesea seguir registrando usuarios? [S/N]: ");
    leerLinea(respuesta, MAX);
 
    if (!(strcmp(respuesta, "S") == 0 || strcmp(respuesta, "s") == 0)) {
      repite = 0;
    }
  } while (repite == 1);
    system("cls");
    printf("Volviendo al Menu Inicial...");
    setTimeout(2500);
    system("cls");
    menuInicial();
}

void registrarUsuario(){

  int end, pi = 0;
  char nombreUsuario[MAX];
  char password1[MAX];
  char password2[MAX];
  
  Usuario *usuario;
  usuario=(Usuario*)malloc(sizeof(Usuario));


  do {
    system("cls");
    printf("\n\t\t\tREGISTRARSE AL SISTEMA\n");
    printf("\t\t\t-------------------------\n");
    printf("\n\t\tElige un nombre de Usuario: ");
    scanf("%s", nombreUsuario);

    int usuarioCorrecto = 0;
    while(!usuarioCorrecto){
        char userName[MAX];
        scanf("%s", userName);
        fflush(stdin);
        if(usuarioLibre(userName) == 1){
            printf("El usuario \"%s\" ya existe, elige otro", nombreUsuario);

        } else{
            usuarioCorrecto = 1;
            strcpy(usuario->nom_user, userName);
        }
    }
  do{

    printf("\t\tElige un buen Password: \n");
    scanf("%s", password1);

    printf("\t\tVuelve a escribirlo: \n");
    scanf("%s", password2);

    if(password1 == password2){
      strcpy(usuario->pass_user, password1);
      insertarUsuario(*usuario);
      pi=1;

    printf("\t\tPulsa un numero para continuar [] \n");
    scanf("%d", end);

    system("cls");
printf("Volviendo al Menu Inicial...");
setTimeout(2500);
system("cls");
menuInicial();
    }

   } while (pi == 0);

  } while (end == 0);

}

//Temporizador en milisegundos
void setTimeout(int milliseconds)
{
    // Si milisegundos es menor o igual a 0 devuelve return con throw error
    if (milliseconds <= 0) {
        fprintf(stderr, "Count milliseconds for timeout is less or equal to 0\n");
        return;
    }

    // tiempo actual en milisegundos
    int milliseconds_since = clock() * 1000 / CLOCKS_PER_SEC;

    // tiempo necesario en milisegundos
    int end = milliseconds_since + milliseconds;

    // esperar a que pase el tiempo
    do {
        milliseconds_since = clock() * 1000 / CLOCKS_PER_SEC;
    } while (milliseconds_since <= end);
}
int longitud(char *p){
    int c=0;
    while(*p!='\0')
    {
        c++;
        *p++;
    }
    return(c);
}

void leerForo(){
  char a[1000];
  char bufer[LONGITUD_MAXIMA_CADENA];
    FILE *f;
    f = fopen("foro.txt", "r");
    while (fgets(bufer, LONGITUD_MAXIMA_CADENA, f))
    {
        while( fscanf(f, "%[^\n]", &a) == 1)
    {
        printf("%s", a);
    }
    printf("\n"); 
    }
    fclose(f);


}
void escribirForo(){
    int x;
    char texto[100];
    FILE *f;
    f = fopen("foro.txt", "a");
    printf("Escribe un mensaje de maximo 30 caracteres: ");

    scanf("%30[^\n]", texto);

    x = longitud(texto);
    if(x<31){
      fprintf(f, "%s\n", texto);
   
    fclose(f);

    printf("\nMensaje insertado con exito\n");

    }else{
      printf("\nSu mensaje supera los 30 caracteres.\n");
    }

    


}






