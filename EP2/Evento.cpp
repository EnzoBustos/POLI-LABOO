#include "Evento.h"

//construtor
Evento::Evento(Perfil* autor, string texto, string data) : Publicacao(autor, texto) {
    this->data = data;
}

Evento::~Evento() {
}

//getter
string Evento::getData() {
    return data;
}

//tirando abstraca de publicacao
void Evento::curtir(Perfil* quemCurtiu) {
    curtidas += 1;
}
