#include "RedeSocial.h"
#include <iostream>

RedeSocial::RedeSocial(int numeroMaximoDePerfis){
    this->numeroMaximoDePerfis = numeroMaximoDePerfis;
    perfis = new Perfil* [numeroMaximoDePerfis];
    quantidadeDePerfis = 0;
}

RedeSocial::~RedeSocial(){
    for (int i = 0; i < quantidadeDePerfis; i++){
        delete perfis[i];
    }
}

int RedeSocial::getQuantidadeDePerfis(){
    return quantidadeDePerfis;
}

Perfil** RedeSocial::getPerfis(){
    return perfis;
}

bool RedeSocial::adicionar(Perfil* p){
    if (quantidadeDePerfis < numeroMaximoDePerfis){
        perfis[quantidadeDePerfis] = p;
        quantidadeDePerfis += 1;
        return true;
    } else{
        return false;
    }
}

//nao sei se esse metodo sera util por conta que nosso programa trabalha com interfaces
void RedeSocial::imprimir(){
    cout << endl << "------------------------------ " << endl;
    cout << "RedeSocial: " << quantidadeDePerfis << " perfis" << endl;
    cout << "------------------------------ " << endl;

    // estatisticas da rede

    if (quantidadeDePerfis == 0){
        cout << "Sem perfis" << endl;
        cout << "------------------------------ " << endl;
    } else {
        int numProf = 0;
        int numDisc = 0;
        for (int i = 0; i < quantidadeDePerfis; i++){
            Professor* testaProf = dynamic_cast<Professor*>(perfis[i]);
            Disciplina* testaDisc = dynamic_cast<Disciplina*>(perfis[i]);
            if (testaProf != NULL){
                numProf += 1;
            } else if (testaDisc != NULL){
                numDisc += 1;
            }
        }
        cout << "Total de perfis: " << quantidadeDePerfis << endl;
        cout << "Perfis comuns: " << (quantidadeDePerfis - numDisc - numProf) << endl;
        cout << "Perfis de professor: " << numProf << endl;
        cout << "Perfis de disciplina: " << numDisc << endl;
        cout << "------------------------------ " << endl;
        for (int i = 0; i < quantidadeDePerfis; i++){
            perfis[i]->imprimir();
            cout << "------------------------------ " << endl;
        }
    }
}

void RedeSocial::passaDadosPerfil(int nUSP, string nome, string email, string ehprof){
    if (ehprof.compare("n") == 0){
        perfis[quantidadeDePerfis] = new Perfil(nUSP, nome, email);
        this->adicionar(perfis[quantidadeDePerfis]);
    } else if (ehprof.compare("s") == 0){
        string departamento;
        cout << "Departamento: ";
        cin >> departamento;
        cin.ignore(100, '\n');
        perfis[quantidadeDePerfis] = new Professor(nUSP, nome, email, departamento);
        this->adicionar(perfis[quantidadeDePerfis]);
    }
}

bool RedeSocial::passaDadosDisciplina(string sigla, string nome){
    cout << endl;
    int opcao;
    cout << "Responsavel: " << endl;
    mostraPerfis();
    cin >> opcao;
    cin.ignore(100,'\n');
    Professor* testaProf = dynamic_cast<Professor*>(perfis[opcao - 1]);
    if (testaProf != NULL){
        perfis[quantidadeDePerfis] = new Disciplina(sigla, nome, testaProf);
        this->adicionar(perfis[quantidadeDePerfis]);
        cout << endl;
        return true;
    } else {
        cout << endl;
        return false;
    }
}

void RedeSocial::mostraPerfis(){
    for (int i = 0; i < quantidadeDePerfis; i++){
        cout << i+1 << ") " << perfis[i]->getNome() << endl;
    }
    cout << "Digite o numero ou 0 para cancelar: " << endl;
}
