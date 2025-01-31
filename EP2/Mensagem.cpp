#include "Mensagem.h"
#include <stdexcept>

//construtor
Mensagem::Mensagem(Perfil* autor, string texto) : Publicacao(autor, texto) {
}

Mensagem::~Mensagem() {
}

//tirando abstracao de Publciacao
void Mensagem::curtir(Perfil* quemCurtiu) {
    //se vc tentar curtir sua propria msg
    if (quemCurtiu == autor) {
        throw new invalid_argument("Impossivel curtir a propria mensagem");
    } else {
        curtidas += 1;
    }

}
