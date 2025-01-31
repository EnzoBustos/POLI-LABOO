#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "Pessoa.h"
#include <string>

using namespace std;

class Professor : public Pessoa {
    public:
        //metodos gerais
        Professor(int numeroUSP, string nome, string email, string departamento);
        virtual ~Professor();

        //persistencia
        Professor(int id, int numeroUSP, string nome, string email, string departamento);

        //getter
        string getDepartamento();

        //tirando abstradao
        virtual void receber(Publicacao* p);

    private:
        //atributos
        string departamento;
};

#endif // PROFESSOR_H
