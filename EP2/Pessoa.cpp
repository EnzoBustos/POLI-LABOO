#include "Pessoa.h"
#include <stdexcept>
#include <algorithm>
#include "Mensagem.h"

//construtor padrao
Pessoa::Pessoa(int numeroUSP, string nome, string email) : Perfil(nome) {
    this->numeroUSP = numeroUSP;
    this->email = email;
}

Pessoa::~Pessoa() {
}

/* tirando abstracao de adicionar seguidor
   observe que aluno e prof tem o msm comportamento para esse metodo */
void Pessoa::adicionarSeguidor(Perfil* seguidor) {
    //checa se eh o proprio perfil tentando seguir
    if(seguidor == this) {
        throw new invalid_argument("Impossivel seguir voce mesmo");
    }
    vector<Perfil*>::iterator itr;
    //checa se ja eh um seguidor
    itr = find(seguidores->begin(), seguidores->end(), seguidor);
    if(itr != seguidores->end()) {
        throw new invalid_argument("Voce ja segue este perfil");
    }
    //adiciona efetivamente
    seguidores->push_back(seguidor);
    //manda a mensagem
    Mensagem* p = new Mensagem(this, "Novo seguidor: " + seguidor->getNome());
    this->publicacoesRecebidas->push_back(p);
}

//construtor na persistencia
Pessoa::Pessoa(int id, int numeroUSP, string nome, string email) : Perfil(id, nome){
    this->numeroUSP = numeroUSP;
    this->email = email;
}

//getters
int Pessoa::getNumeroUSP() {
    return numeroUSP;
}

string Pessoa::getEmail() {
    return email;
}
