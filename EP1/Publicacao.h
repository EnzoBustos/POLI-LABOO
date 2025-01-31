#ifndef PUBLICACAO_H
#define PUBLICACAO_H
#include <string>
#include "Perfil.h"

using namespace std;

class Perfil;

class Publicacao{
    public:
        //construtor e destrutor
        Publicacao(Perfil* autor, string texto);
        virtual ~Publicacao();

        //getters
        virtual Perfil* getAutor();
        string getTexto();

        //metodos
        virtual void curtir(Perfil* quemCurtiu);
        virtual int getCurtidas();
        virtual void imprimir();

    protected:
        string texto;
        Perfil* autor;
        int quantidadeDeCurtidas;
};

#endif // PUBLICACAO_H
