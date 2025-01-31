#include "Evento.h"

Evento::Evento(Perfil* autor, string texto, string data):Publicacao(autor, texto){
    this->data = data;
}

Evento::~Evento(){
}

string Evento::getData(){
    return data;
}

void Evento::imprimir(){
    cout << data << " - " << texto << " (" << autor->getNome() << ") [" << quantidadeDeCurtidas << "] " << endl;
}

