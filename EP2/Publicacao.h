#ifndef PUBLICACAO_H
#define PUBLICACAO_H
#include "Perfil.h"
#include <string>

using namespace std;

class Perfil;

class Publicacao {
    public:
        //metodos gerais
        Publicacao(Perfil* autor, string texto);
        virtual ~Publicacao();
        virtual void curtir(Perfil* quemCurtiu) = 0; //metodo abstrato

        //para testes
        virtual void imprimir();

        //getters
        Perfil* getAutor();
        string getTexto();
        virtual int getCurtidas();

    protected:
        //atributos
        int curtidas;
        string texto;
        Perfil* autor;
};

#endif // PUBLICACAO_H
