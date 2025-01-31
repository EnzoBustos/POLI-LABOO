#include "RedeSocial.h"
#include <stdexcept>
#include <algorithm>
#include "PerfilInexistente.h"
#include <iostream>

//construtor
RedeSocial::RedeSocial() {
    perfis = new vector<Perfil*>();
}

//chama os destrutores de perfis tb
RedeSocial::~RedeSocial() {
    vector<Perfil*>::iterator itr;
    for(itr = perfis->begin(); itr != perfis->end(); itr++) {
        delete (*itr);
    }
}

//coloca um novo perfil na rede
void RedeSocial::adicionar(Perfil* perfil) {
    vector<Perfil*>::iterator itr;
    itr = find(perfis->begin(), perfis->end(), perfil);
    //testa para ver se perfil ja esta nela
    if(itr != perfis->end()){
        throw new invalid_argument("Perfil ja esta na rede");
    } else {
        //adicionando efetivamente
        perfis->push_back(perfil);
    }
}

//getters
vector<Perfil*>* RedeSocial::getPerfis() {
    return perfis;
}

Perfil* RedeSocial::getPerfil(int id) {
    vector<Perfil*>::iterator itr;
    for (itr = perfis->begin(); itr != perfis->end(); itr++){
        if ((*itr)->getId() == id) {
            return (*itr);
        }
    }
    //se o perfil nn estiver na rede
    throw new PerfilInexistente();
}

//metodo para testes
void RedeSocial::imprimir() {
    vector<Perfil*>::iterator itr;
    cout << endl << " ========== REDE ========== " << endl;
    for (itr = perfis->begin(); itr != perfis->end(); itr++) {
        (*itr)->imprimir();
    }
}
