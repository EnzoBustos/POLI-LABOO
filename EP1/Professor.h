#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <string>
#include <iostream>
#include "Perfil.h"

using namespace std;

class Professor : public Perfil{
    public:
        Professor(int numeroUSP,string nome, string email,string departamento);
        virtual ~Professor();
        void imprimir();
        string getDepartamento();

    private:
        string departamento;
};

#endif // PROFESSOR_H
