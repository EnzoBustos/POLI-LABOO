#ifndef PERFIL_H
#define PERFIL_H
#define MAXIMO_SEGUIDORES 20
#define MAXIMO_PUBLICACOES 20
#include <string>
#include "Publicacao.h"

using namespace std;

class Publicacao;

class Perfil{

protected://protected a decidir pelo que eu vou usar nas outras classes filhas
    //atributos
    int numeroUSP;
    string nome;
    string email;
    int quantidadeDePublicacoesFeitas;
    int quantidadeDePublicacoesRecebidas;
    int quantidadeDeSeguidores;
    Perfil** seguidores;
    Publicacao** publicacoesFeitas;
    Publicacao** publicacoesRecebidas;
    bool receberNotificacao(Perfil* seguidor);

public:
    //construtor e destrutor
    Perfil(int numeroUSP, string nome, string email);
    virtual ~Perfil();

    //getters
    int getNumeroUSP();
    string getNome();
    string getEmail();
    virtual int getQuantidadeDePublicacoesFeitas();
    virtual int getQuantidadeDePublicacoesRecebidas();
    virtual int getQuantidadeDeSeguidores();
    virtual Perfil** getSeguidores();
    virtual Publicacao** getPublicacoesFeitas();
    virtual Publicacao** getPublicacoesRecebidas();

    //metodos
    virtual bool adicionarSeguidor(Perfil* seguidor);
    virtual bool publicar(string texto);
    virtual bool publicar(string texto, string data);
    virtual bool receber(Publicacao* p);
    virtual void imprimir();

};

#endif // PERFIL_H
