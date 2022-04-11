#ifndef _ESTRUCTURAS_H_
#define _ESTRUCTURAS_H_


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
	char *id_user;
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
	int cod_gen;
	char *nom_gen;
}Genero;

typedef struct{
	int cod_dj;
	char *nom_dj;
	int gen_dj;
}Dj;
typedef struct{
	int cod_zona;
	char* nom_zona;
	Genero gen_zona;
	int fest_zona;
}Zona;

#endif