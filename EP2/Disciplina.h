#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#include "Perfil.h"
#include "Professor.h"

using namespace std;

class Disciplina : public Perfil {
    public:
        //metodos gerais
        Disciplina(string sigla, string nome, Professor* responsavel);
        virtual ~Disciplina();

        //persistencia
        Disciplina(int id, string sigla, string nome, Professor* responsavel);

        //getters
        virtual string getSigla();
        virtual Professor* getResponsavel();

        //tirando abstracao de Perfil
        virtual void adicionarSeguidor(Perfil* seguidor);
        virtual void receber(Publicacao* p);

    private:
        //atributos
        string sigla;
        Professor* responsavel;
};

#endif // DISCIPLINA_H
