#include "Perfil.h"
#include <string>
#include <iostream>
#include "Evento.h"

using namespace std;

Perfil::Perfil(int numeroUSP, string nome, string email){
    this->numeroUSP = numeroUSP;
    this->nome = nome;
    this->email = email;
    quantidadeDePublicacoesFeitas = 0;
    quantidadeDePublicacoesRecebidas = 0;
    quantidadeDeSeguidores = 0;
    publicacoesFeitas = new Publicacao* [MAXIMO_PUBLICACOES];
    publicacoesRecebidas = new Publicacao* [MAXIMO_PUBLICACOES];
    seguidores = new Perfil* [MAXIMO_SEGUIDORES];
}

Perfil::~Perfil(){
    for (int i = 0; i < quantidadeDePublicacoesFeitas; i++){
        delete publicacoesFeitas[i];
    }
}

int Perfil::getNumeroUSP(){
    return numeroUSP;
}

string Perfil::getNome(){
    return nome;
}

string Perfil::getEmail(){
    return email;
}

int Perfil::getQuantidadeDePublicacoesFeitas(){
    return quantidadeDePublicacoesFeitas;
}

int Perfil::getQuantidadeDePublicacoesRecebidas(){
    return quantidadeDePublicacoesRecebidas;
}

int Perfil::getQuantidadeDeSeguidores(){
    return quantidadeDeSeguidores;
}

Perfil** Perfil::getSeguidores(){
    return seguidores;
}

Publicacao** Perfil::getPublicacoesFeitas(){
    return publicacoesFeitas;
}

Publicacao** Perfil::getPublicacoesRecebidas(){
    return publicacoesRecebidas;
}

bool Perfil::adicionarSeguidor(Perfil* seguidor){
    if (this == seguidor){
        cout << endl;
        cout << "Perfil nao adicionado" << endl;
        cout << endl;
        return false;
    }
    bool ehSeguidor = false;
    for (int i = 0; i < quantidadeDeSeguidores; i++){
        if (seguidores[i] == seguidor){
                ehSeguidor = true;
        }
    }
    if (ehSeguidor){
        cout << endl;
        cout << "Perfil nao adicionado" << endl;
        cout << endl;
        return false;
    } else if (quantidadeDeSeguidores >= MAXIMO_SEGUIDORES){
        cout << endl;
        cout << "Perfil nao adicionado" << endl;
        cout << endl;
        return false;
    } else {
        seguidores[quantidadeDeSeguidores] = seguidor;
        quantidadeDeSeguidores += 1;
        this->receberNotificacao(seguidor);
        return true;
    }
}

bool Perfil::receberNotificacao(Perfil* seguidor){
    string notificacao = "Novo seguidor: ";
    notificacao = notificacao + seguidor->getNome();
    if (quantidadeDePublicacoesRecebidas < MAXIMO_PUBLICACOES){
            publicacoesRecebidas[quantidadeDePublicacoesRecebidas] = new Publicacao(this, notificacao);
            quantidadeDePublicacoesRecebidas += 1;
            return true;
    } else {
        return false;
    }
}

bool Perfil::publicar(string texto){
    if (quantidadeDePublicacoesFeitas < MAXIMO_PUBLICACOES){
        publicacoesFeitas[quantidadeDePublicacoesFeitas] = new Publicacao(this, texto);
        if (quantidadeDeSeguidores > 0){
            for (int i = 0; i < quantidadeDeSeguidores; i++){
                seguidores[i]->receber(publicacoesFeitas[quantidadeDePublicacoesFeitas]);
            }
        }
        quantidadeDePublicacoesFeitas += 1;
        return true;
    } else {
        return false;
    }
}

bool Perfil::publicar(string texto, string data){
    if (quantidadeDePublicacoesFeitas < MAXIMO_PUBLICACOES){
        publicacoesFeitas[quantidadeDePublicacoesFeitas] = new Evento(this, texto, data);
        if (quantidadeDeSeguidores > 0){
            for (int i = 0; i < quantidadeDeSeguidores; i++){
                seguidores[i]->receber(publicacoesFeitas[quantidadeDePublicacoesFeitas]);
            }
        }
        quantidadeDePublicacoesFeitas += 1;
        return true;
    } else {
        return false;
    }
}

bool Perfil::receber(Publicacao* p){
    if (quantidadeDePublicacoesRecebidas < MAXIMO_PUBLICACOES){
        publicacoesRecebidas[quantidadeDePublicacoesRecebidas] = p;
        quantidadeDePublicacoesRecebidas += 1;
        return true;
    } else {
        return false;
    }
}

void Perfil::imprimir(){
    cout << numeroUSP << " - " << nome << endl;
    cout << "Seguidores: " << quantidadeDeSeguidores << endl;
}
