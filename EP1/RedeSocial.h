#ifndef REDESOCIAL_H
#define REDESOCIAL_H
#include "Perfil.h"
#include "Professor.h"
#include "Disciplina.h"

class RedeSocial{
    public:
        //construtor e destrutor
        RedeSocial(int numeroMaximoDePerfis);
        virtual ~RedeSocial();

        //getters
        int getQuantidadeDePerfis();
        Perfil** getPerfis();

        //metodos
        bool adicionar(Perfil* p);
        virtual void imprimir();
        virtual void passaDadosPerfil(int nUSP, string nome, string email, string ehprof);
        virtual bool passaDadosDisciplina(string sigla, string nome);
        virtual void mostraPerfis();

    private:
        Perfil** perfis;
        int numeroMaximoDePerfis;
        int quantidadeDePerfis;
};

#endif // REDESOCIAL_H
