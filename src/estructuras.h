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



#endif