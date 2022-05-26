#include <string>
#include <iostream>
#include "../c/estructuras.h"
#include <stdlib.h>


#ifndef CLASES_H_
#define CLASES_H_

using namespace std;


    class Usuario{
        private:
        
            string id_user;
	        string nom_user;
	        string pass_user;
	        int ent_fest; 
        public:
            Usuario(string id_user, string nom_user,std::string pass_user,int ent_fest);
            Usuario();
            ~Usuario();
            void setIdUser(string id_user);
            string getIdUser()const;
            void setNomUser(string nom_user);
            string getNomUser()const;
            void setPassUser(string pass_user);
            string getPassUser()const;
            void setIdUser(int ent_fest);
            int getEntFest()const;
 

    };
    class Entrada{
        private:
            int cod_ent;
            string tipo_ent;
            string info_ent;
            int precio;
        public:
            Entrada(int cod_ent, string tipo_ent, std :: string info_ent, int precio);
            Entrada();
            ~Entrada();
            void setCodEnt(int cod_ent);
            int getCodEnt() const;
            void setTipoEnt(string tipo_ent);
            string getTipoEnt() const;
            void setInfoEnt(string info_ent);
            string getInfoEnt() const;
            void setPrecio(int precio);
            int getPrecio() const;
    };
    class Zona{
        private:
            int cod_zona;
	        string nom_zona;
	        int fest_zona;       
        public:
            Zona(int cod_dj, string nom_dj, int gen_dj);
            Zona();
            ~Zona();
            void setCodZona(int cod_zona);
            int getCodZona()const;
            void setNomZona(string nom_zona);
            string getNomZona() const;
            void setFestZona(int fest_zona);
            int getFestZona() const;

    };
    class Dj{
        private:

            int cod_dj;
	        string nom_dj;
	        int gen_dj;
        public:
            Dj(int cod_dj, string nom_dj, int gen_dj);
            Dj();
            ~Dj();
            void setCodDj(int cod_dj);
            int getCodDj()const;
            void setNomDj(string nom_dj);
            string getNomDj()const;
            void setGenDj(int gen_dj);
            int getGenDj()const;
            

    };

#endif