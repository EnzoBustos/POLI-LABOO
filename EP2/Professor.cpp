#include "Professor.h"

//construtor utilizado pelo usuario
Professor::Professor(int numeroUSP, string nome, string email, string departamento) : Pessoa(numeroUSP, nome, email) {
    this->departamento = departamento;
}

Professor::~Professor() {
}

//persistencia
Professor::Professor(int id, int numeroUSP, string nome, string email, string departamento) : Pessoa(id, numeroUSP, nome, email){
    this->departamento = departamento;
}

//tirando abstracao de Pessoa
void Professor::receber(Publicacao* p) {
    publicacoesRecebidas->push_back(p);
}

//gettter
string Professor::getDepartamento() {
    return departamento;
}
