#ifndef REDESOCIAL_H
#define REDESOCIAL_H
#include "Perfil.h"
#include <vector>
#include "Perfil.h"

using namespace std;

class RedeSocial {
    public:
        //metodos gerais
        RedeSocial();
        virtual ~RedeSocial();
        void adicionar(Perfil* perfil);

        //getters
        vector<Perfil*>* getPerfis();
        Perfil* getPerfil(int id);
        void imprimir();

    private:
        //atributos
        vector<Perfil*>* perfis;
};

#endif // REDESOCIAL_H
