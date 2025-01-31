#ifndef EVENTO_H
#define EVENTO_H
#include "Publicacao.h"

using namespace std;

class Evento : public Publicacao {
    public:
        //metodos gerais
        Evento(Perfil* autor, string texto, string data);
        virtual ~Evento();

        //getter
        string getData();

        //tirando abstracao
        virtual void curtir(Perfil* quemCurtiu);

    private:
        //atributos
        string data;
};

#endif // EVENTO_H
