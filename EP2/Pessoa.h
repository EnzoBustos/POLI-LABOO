#ifndef PESSOA_H
#define PESSOA_H
#include "Perfil.h"
#include <string>


class Pessoa : public Perfil {
    public:
        //metodos gerais
        Pessoa(int numeroUSP, string nome, string email);
        virtual ~Pessoa();

        //tirando abstracao
        virtual void adicionarSeguidor(Perfil* seguidor);
        //observe ainda eh abstrata pq receber nn esta definido

        //persistencia
        Pessoa(int id, int numeroUSP, string nome, string email);

        //getters
        virtual int getNumeroUSP();
        virtual string getEmail();

    protected:
        //atributos
        int numeroUSP;
        string email;

};

#endif // PESSOA_H
