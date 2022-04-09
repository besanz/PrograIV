#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H


typedef struct{
	int cod_fest;
	char *nom_fest;
	char *info_fest;
}Festival;

typedef struct{
	int cod_ent;
	char *tipo_ent;
	char *info_ent;
	int precio;
}Entrada;

typedef struct{
	int id_user;
	char *nom_user;
	char *pass_user;
	int ent_fest;
}Usuario;

typedef struct{
	int cod_foro;
	char *info_foro;
	int fest_foro;
}Foro;

typedef struct{
	int cod_zona;
	char* nom_zona;
	int gen_zona;
	int fest_zona
}Zona;

typedef struct{
	int cod_dj;
	char *nom_dj;
	char *Genero;
}Dj;

typedef struct{
	int cod_gen;
	char *nom_gen;
}Genero;



#endif