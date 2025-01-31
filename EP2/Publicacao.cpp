#include "Publicacao.h"
#include <iostream>
#include <string>

//construtor
Publicacao::Publicacao(Perfil* autor, string texto) {
    this->autor = autor;
    this->texto = texto;
    curtidas = 0;
}

Publicacao::~Publicacao() {
}

//para testes
void Publicacao::imprimir() {
    cout << getTexto() << " - " << getAutor()->getNome() << " [" << getCurtidas() << "]" << endl;
}

//getters
Perfil* Publicacao::getAutor() {
    return autor;
}

string Publicacao::getTexto() {
    return texto;
}

int Publicacao::getCurtidas() {
    return curtidas;
}
