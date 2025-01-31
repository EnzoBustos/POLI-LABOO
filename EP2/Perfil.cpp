#include "Perfil.h"
#include <iostream>
#include "Mensagem.h"
#include "Evento.h"

//inicia variavel com escopo de classe
int Perfil::contadorDePerfis = 0;

//construtor utilizado pelo usuario
Perfil::Perfil(string nome) {
    contadorDePerfis += 1;
    this->nome = nome;
    this->id = contadorDePerfis; //coleta o ID atual
    publicacoesFeitas = new list<Publicacao*>();
    publicacoesRecebidas = new list<Publicacao*>();
    seguidores = new vector<Perfil*>();
}

//destroi chama os destrutores das publicacoes feitas
Perfil::~Perfil() {
    list<Publicacao*>::iterator itr;
    for(itr = publicacoesFeitas->begin(); itr != publicacoesFeitas->end(); itr++) {
        delete (*itr);
    }
}

//publica uma mensagem e envia para os seus seguidores
void Perfil::publicar(string texto) {
    Mensagem* p = new Mensagem(this, texto);
    //guardando nas publicacoes feitas
    publicacoesFeitas->push_back(p);
    if(seguidores->size() > 0) {
        vector<Perfil*>::iterator itr;
        for (itr = seguidores->begin(); itr != seguidores->end(); itr++) {
            Perfil* generico = *itr;
            //enviando para qm segue
            generico->getPublicacoesRecebidas()->push_back(p);
        }
    }
}

//publica um evento e envia para os seus seguidores
void Perfil::publicar(string texto, string data) {
    Evento* e = new Evento(this, texto, data);
    //guardando em feitas
    publicacoesFeitas->push_back(e);
    if(seguidores->size() > 0) {
        vector<Perfil*>::iterator itr;
        for (itr = seguidores->begin(); itr != seguidores->end(); itr++) {
            Perfil* generico = *itr;
            //enviando para qm segue
            generico->getPublicacoesRecebidas()->push_back(e);
        }
    //eventos sao guardados em recebidas tb para poderem serem curtidos
    this->getPublicacoesRecebidas()->push_back(e);
    }
}

//metodos utilizados pela persistencia
Perfil::Perfil(int id, string nome) {
    this->nome = nome;
    this->id = id;
    publicacoesFeitas = new list<Publicacao*>();
    publicacoesRecebidas = new list<Publicacao*>();
    seguidores = new vector<Perfil*>();

}

//setter
void Perfil::setUltimoId(int ultimoId) {
    Perfil::contadorDePerfis = ultimoId;
}

//getters
int Perfil::getUltimoId() {
    return contadorDePerfis;
}

int Perfil::getId() {
    return id;
}

string Perfil::getNome() {
    return nome;
}

list<Publicacao*>* Perfil::getPublicacoesFeitas() {
    return publicacoesFeitas;
}

list<Publicacao*>* Perfil::getPublicacoesRecebidas() {
    return publicacoesRecebidas;
}

vector<Perfil*>* Perfil::getSeguidores() {
    return seguidores;
}

//para finalidade de teste
void Perfil::imprimir() {
    cout << endl << " ==================== " << endl;
    cout << getId() << " - " << getNome() << endl;
    cout << "N_Seguidores: " << seguidores->size() << endl;
    list<Publicacao*>::iterator itr;
    cout << "Publicacoes feitas: " << endl;
    for (itr = publicacoesFeitas->begin(); itr != publicacoesFeitas->end(); itr++) {
        cout << (*itr)->getTexto() << endl;
    }
    cout << "Publicacoes recebidas: " << endl;
    for (itr = publicacoesRecebidas->begin(); itr != publicacoesRecebidas->end(); itr++) {
        cout << (*itr)->getTexto() << endl;
    }
}
