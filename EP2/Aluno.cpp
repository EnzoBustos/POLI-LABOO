#include "Aluno.h"

//construtor usado pelo usuario
Aluno::Aluno(int numeroUSP, string nome, string email) : Pessoa(numeroUSP, nome, email) {
}

Aluno::~Aluno() {
}

//persistencia
Aluno::Aluno(int id, int numeroUSP, string nome, string email) : Pessoa(id, numeroUSP, nome, email) {
}

//tirando a abstracao de Pessoa
void Aluno::receber(Publicacao* p) {
    publicacoesRecebidas->push_back(p);
}
