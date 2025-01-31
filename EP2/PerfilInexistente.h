#ifndef PERFILINEXISTENTE_H
#define PERFILINEXISTENTE_H
#include <stdexcept>

using namespace std;

class PerfilInexistente : public logic_error {
    public:
        //metodos gerais
        PerfilInexistente();
        virtual ~PerfilInexistente()
            throw() {}; //precisei colocar isso no destrutor pois nn compilava
};

#endif // PERFILINEXISTENTE_H
