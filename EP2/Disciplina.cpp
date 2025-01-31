#include "Disciplina.h"
#include <stdexcept>
#include <algorithm>

//construtor usado pelo usuario
Disciplina::Disciplina(string sigla, string nome, Professor* responsavel) : Perfil(nome) {
    this->sigla = sigla;
    this->responsavel = responsavel;
    this->adicionarSeguidor(responsavel);
}

Disciplina::~Disciplina(){
}

//persistencia
Disciplina::Disciplina(int id, string sigla, string nome, Professor* responsavel) : Perfil(id, nome) {
    this->sigla = sigla;
    this->responsavel = responsavel;
}

//getters
string Disciplina::getSigla() {
    return sigla;
}

Professor* Disciplina::getResponsavel() {
    return responsavel;
}

//tirando abstracoes de Perfil
void Disciplina::adicionarSeguidor(Perfil* seguidor) {
    //checando se eh voce msm
    if(seguidor == this) {
        throw new invalid_argument("Impossivel seguir voce mesmo");
    }
    vector<Perfil*>::iterator itr;
    itr = find(seguidores->begin(), seguidores->end(), seguidor);
    //se tentou seguir uma pessoa q ja segue
    if(itr != seguidores->end()) {
        throw new invalid_argument("Voce ja segue este perfil");
    }
    seguidores->push_back(seguidor);
}


void Disciplina::receber(Publicacao* p) {
    publicacoesRecebidas->push_back(p);
}
