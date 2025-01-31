#ifndef PERSISTENCIADAREDE_H
#define PERSISTENCIADAREDE_H
#include "RedeSocial.h"
#include <string>

using namespace std;

class PersistenciaDaRede {
    public:
        //metodos gerais
        PersistenciaDaRede(string arquivo);
        virtual ~PersistenciaDaRede();
        void salvar(RedeSocial* r); //guarda a rede em arquivo txt
        RedeSocial* carregar(); //resgata a rede de arquivo txt

    private:
        //atributos
        string arquivo;
};

#endif // PERSISTENCIADAREDE_H
