#include "Professor.h"

Professor::Professor(int numeroUSP, string nome, string email, string departamento):Perfil(numeroUSP, nome, email){
    this->departamento = departamento;
}

Professor::~Professor(){
}

void Professor::imprimir(){
    Perfil::imprimir();
    cout << "Departamento: " << departamento << endl;
}

string Professor::getDepartamento(){
    return departamento;
}
