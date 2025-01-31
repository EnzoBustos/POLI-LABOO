#include "Disciplina.h"

Disciplina::Disciplina(string sigla, string nome, Professor* responsavel):Perfil(0, nome, ""){
    this->sigla = sigla;
    this->responsavel = responsavel;
    this->adicionarSeguidor(responsavel);
}

Disciplina::~Disciplina(){
}

string Disciplina::getSigla(){
    return sigla;
}

Professor* Disciplina::getResponsavel(){
    return responsavel;
}

void Disciplina::imprimir(){
    cout << sigla << " - " << nome << endl;
    cout << "Seguidores: " << quantidadeDeSeguidores << endl;
}
