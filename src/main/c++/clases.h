#include <string>
#include <iostream>
#include "../c/estructuras.h"
#include <stdlib.h>


#ifndef CLASES_H_
#define CLASES_H_




    class Usuario{
        private:
        
            std::string id_user;
	        std::string nom_user;
	        std::string pass_user;
	        int ent_fest; 
        public:
            Usuario(std::string id_user,std::string nom_user,std::string pass_user,int ent_fest);
            Usuario();
            ~Usuario();
            void setIdUser(std::string id_user);
            std::string getIdUser()const;
            void setNomUser(std::string nom_user);
            std::string getNomUser()const;
            void setPassUser(std::string pass_user);
            std::string getPassUser()const;
            void setIdUser(int ent_fest);
            int getEntFest()const;
 

    };
    class Entrada{
        private:
            int cod_ent;
             std :: string tipo_ent;
           std ::  string info_ent;
            int precio;
        public:
            Entrada(int cod_ent, std :: string tipo_ent, std :: string info_ent, int precio);
            Entrada();
            ~Entrada();
            void setCodEnt(int cod_ent);
            int getCodEnt() const;
            void setTipoEnt(std :: string tipo_ent);
           std :: string getTipoEnt() const;
            void setInfoEnt(std :: string info_ent);
            std :: string getInfoEnt() const;
            void setPrecio(int precio);
            int getPrecio() const;
    };
    class Zona{
        private:
            int cod_zona;
	        std :: string nom_zona;
	        int fest_zona;       
        public:
            Zona(int cod_dj, std :: string nom_dj, int gen_dj);
            Zona();
            ~Zona();
            void setCodZona(int cod_zona);
            int getCodZona()const;
            void setNomZona(std::string nom_zona);
            std ::string getNomZona() const;
            void setFestZona(int precio);
            int getFestZona() const;

    };
    class Dj{
        private:

            int cod_dj;
	       std :: string nom_dj;
	        int gen_dj;
        public:
            Dj(int cod_dj,std :: string nom_dj, int gen_dj);
            Dj();
            ~Dj();
            void setCodDj(int cod_dj);
            int getCodDj()const;
            void setNomDj(std :: string nom_user);
           std :: string getNomDj()const;
            void setGenDj(int gen_dj);
           std :: string getGenDj()const;
            

    };

#endif