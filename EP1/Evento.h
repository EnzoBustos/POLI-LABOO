#ifndef EVENTO_H
#define EVENTO_H
#include <string>
#include <iostream>
#include "Publicacao.h"


class Evento: public Publicacao{
public:
    Evento (Perfil* autor, string texto, string data);
    ~Evento();
    string getData();
    void imprimir();
private:
    string data;
};

#endif // EVENTO_H
