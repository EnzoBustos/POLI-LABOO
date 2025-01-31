#include "Publicacao.h"
#include <string>
#include <iostream>

using namespace std;

Publicacao::~Publicacao(){
}

Publicacao::Publicacao(Perfil* autor, string texto){
    this->autor = autor;
    this->texto = texto;
    quantidadeDeCurtidas = 0;
}

Perfil* Publicacao::getAutor(){
    return autor;
}

string Publicacao::getTexto(){
    return texto;
}

void Publicacao::curtir(Perfil* quemCurtiu){
    if(quemCurtiu != autor){
        quantidadeDeCurtidas += 1;
    }
}

int Publicacao::getCurtidas(){
    return quantidadeDeCurtidas;
}

void Publicacao::imprimir(){
    cout << texto << " (" << autor->getNome() << ") [" << quantidadeDeCurtidas << "]" << endl;
}
