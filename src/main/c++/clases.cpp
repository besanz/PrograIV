#include "clases.h"
#include "../c/estructuras.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

Usuario ::Usuario( string id_user, std :: string nom_user, std ::string pass_user,int ent_fest)
{
    this->id_user=id_user;
    this->nom_user = nom_user;
	this->pass_user=pass_user;
    this->ent_fest=ent_fest;
}
void Usuario::setIdUser(string id_user){
    this->id_user=id_user;
}
string Usuario::getIdUser()const{
    return this->id_user;
}
void Usuario::setNomUser(string nom_user){
    this->nom_user=nom_user;
}
string Usuario::getNomUser()const{
    return this->nom_user;
}
void Usuario::setPassUser(std::string pass_user){
    this->pass_user=pass_user;
}
string Usuario::getPassUser()const{
    return this->nom_user;
}
void Usuario::setIdUser(int ent_fest){
    this->ent_fest=ent_fest;
}
int Usuario::getEntFest()const{
    return this->ent_fest;
}


Entrada::Entrada(int cod_ent,  std :: string tipo_ent, std :: string info_ent, int precio){
    this->cod_ent=cod_ent;
    this->tipo_ent=tipo_ent;
    this->info_ent=info_ent;
    this->precio=precio;
}
Entrada::~Entrada()
{
    
}
void Entrada::setCodEnt(int cod_ent){
    this->cod_ent= cod_ent;
}
int Entrada:: getCodEnt()const{
    return this->cod_ent;
}
void Entrada::setTipoEnt(string tipo_ent){
    this->cod_ent= cod_ent;
}

Zona::Zona(int cod_dj, string nom_dj, int gen_dj){
     
}
Zona::Zona(){
    this->cod_zona=0;
    this->nom_zona="";
    this->fest_zona=0;
}
Zona::~Zona(){
    
}
void Zona::setCodZona(int cod_zona){
    this->cod_zona= cod_zona;
}
int Zona::getCodZona()const{
    return this->cod_zona;
}
void Zona::setNomZona(std::string nom_zona){
    this->nom_zona= nom_zona;
}
string Zona::getNomZona() const{
    return this->nom_zona;
}
void Zona::setFestZona(int fest_zona){
    this->fest_zona= fest_zona;
}
int Zona::getFestZona() const{
    return this->fest_zona;
}

Dj::Dj(int cod_dj, string nom_dj, int gen_dj){
    this->cod_dj=cod_dj;
    this->nom_dj=nom_dj;
    this->gen_dj=gen_dj;
}
Dj::Dj(){
    this->cod_dj=0;
    this->nom_dj="";
    this->gen_dj=0;
}
Dj::~Dj(){

}
void Dj::setCodDj(int cod_dj){
    this->cod_dj=cod_dj;
}
int Dj::getCodDj()const{
    return this->cod_dj;
}
void Dj::setNomDj(string nom_dj){
    this->nom_dj=nom_dj;
}
string Dj::getNomDj()const{
    return this->nom_dj;
}
void Dj::setGenDj(int gen_dj){
    this->gen_dj=gen_dj;
}
int Dj::getGenDj() const{
    return this->gen_dj;
}