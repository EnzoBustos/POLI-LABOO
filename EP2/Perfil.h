#ifndef PERFIL_H
#define PERFIL_H
#include "Publicacao.h"
#include <vector>
#include <list>
#include <string>

using namespace std;

class Publicacao;

class Perfil {
    public:
        //metodos gerais
        Perfil(string nome);
        virtual ~Perfil();
        virtual void adicionarSeguidor(Perfil* seguidor) = 0; //metodo abstrato
        virtual void publicar(string texto);
        virtual void publicar(string texto, string data);
        virtual void receber(Publicacao* p) = 0; //metodo abstrato

        //persistencia
        Perfil(int id, string nome);
        static void setUltimoId(int ultimoId);
        static int getUltimoId();

        //getters
        int getId();
        string getNome();
        virtual list<Publicacao*>* getPublicacoesFeitas();
        virtual list<Publicacao*>* getPublicacoesRecebidas();
        virtual vector<Perfil*>* getSeguidores();

        //metodo opcional para testes
        virtual void imprimir();

    protected:
        //atributos
        static int contadorDePerfis;
        int id;
        string nome;
        list<Publicacao*>* publicacoesFeitas;
        list<Publicacao*>* publicacoesRecebidas;
        vector<Perfil*>* seguidores;

};

#endif // PERFIL_H
