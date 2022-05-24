#include "clases.h"
#include <iostream>
#include <stdlib.h>

using namespace std;



 
 Usuario ::Usuario( std :: string id_user, std :: string nom_user, std ::string pass_user,int ent_fest)
{
    this->id_user=id_user;
    this->nom_user = nom_user;
	this->pass_user=pass_user;
    this->ent_fest=ent_fest;
}


Entrada::Entrada(int cod_ent,  std :: string tipo_ent, std :: string info_ent, int precio){
    this->cod_ent=cod_ent;
    this->tipo_ent=tipo_ent;
    this->info_ent=info_ent;
    this->precio=precio;
}
Entrada::~Entrada(){
    delete[] this->array;
}
void Entrada::setCodEnt(int cod_ent){
    this->cod_ent= cod_ent;
}
int Entrada:: getCodEnt()const{
    return this->cod_ent;
}
void Entrada::setTipoEnt(int tipo_ent){
    this->cod_ent= cod_ent;
}
int Entrada:: getCodEnt(){
    return this->cod_ent;
}
 Zona(int cod_dj, string nom_dj, int gen_dj){
     
 }
Zona(){
                
     }
~Zona(){
    
}
        