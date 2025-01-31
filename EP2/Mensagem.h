#ifndef MENSAGEM_H
#define MENSAGEM_H
#include "Publicacao.h"

using namespace std;

class Mensagem : public Publicacao {
    public:
        //metodos gerais
        Mensagem(Perfil* autor, string texto);
        virtual ~Mensagem();

        //tirando abstracao
        virtual void curtir(Perfil* quemCurtiu);
};

#endif // MENSAGEM_H
