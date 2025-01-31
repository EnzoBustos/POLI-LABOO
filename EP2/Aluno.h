#ifndef ALUNO_H
#define ALUNO_H
#include "Pessoa.h"
#include <string>

using namespace std;

class Aluno : public Pessoa {
    public:
        //metodos gerais
        Aluno(int numeroUSP, string nome, string email);
        virtual ~Aluno();

        //persistencia
        Aluno(int id, int numeroUSP, string nome, string email);

        //tirando abstracao
        virtual void receber(Publicacao* p);
};

#endif // ALUNO_H
