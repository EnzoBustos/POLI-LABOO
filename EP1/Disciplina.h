#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#include <string>
#include "Professor.h"

using namespace std;

class Disciplina : public Perfil{
    public:
        Disciplina(string sigla, string nome, Professor* responsavel);
        virtual ~Disciplina();
        string getSigla();
        Professor* getResponsavel();
        void imprimir();

    protected:
        string sigla;
        Professor* responsavel;

};

#endif // DISCIPLINA_H
