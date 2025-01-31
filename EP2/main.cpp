#include "Perfil.h"
#include "Publicacao.h"
#include "Pessoa.h"
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"
#include "Evento.h"
#include "Mensagem.h"
#include "RedeSocial.h"
#include "PersistenciaDaRede.h"
#include "PerfilInexistente.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <list>
#include <vector>
#include <algorithm>
#include<fstream>

using namespace std;

void opcoesDeRede(RedeSocial* rede); //mostra tela de funcoes da rede criar/logar
void criaPerfil(RedeSocial* rede); //mostra tela de criacao de perfil (prof ou nn)
void criaDisciplina(RedeSocial* rede); //mostra tela de criacao de disciplina
void logar(RedeSocial* rede); //mostra tela com opcoes de perfil para logar
void opcoesDePerfil(Perfil* perfil, RedeSocial* rede); //mostra oq um perfil pode realizar
void mostraFeitas(Perfil* perfil, RedeSocial* rede); //mostra publicacoes feitas do perfil logado
void mostraRecebidas(Perfil* perfil, RedeSocial* rede); //mostra publicacoes recebidas do perfil logado
void fazerPublicacao(Perfil* perfil, RedeSocial* rede); //mostra tela de criacao de publicacao (evento ou nn)
void mostraPerfis(Perfil* perfil, RedeSocial* rede); //mostra tela para escolher qual perfil ira seguir

//mostra os perfil e faz o perfil logado seguir o perfil escolhido
void mostraPerfis(Perfil* perfil, RedeSocial* rede) {
    cout << endl;
    cout << "Perfil: " << endl;
    vector<Perfil*>::iterator itr; //percorrer o vector
    for(itr = rede->getPerfis()->begin(); itr != rede->getPerfis()->end(); itr++) {
        cout << (*itr)->getId() << ") " << (*itr)->getNome() << endl;
    }
    int opcao;
    cout << "Digite o id ou 0 para cancelar: ";
    cin >> opcao;
    cin.ignore(100, '\n');

    cout << endl;
    if (opcao == 0) {
        opcoesDePerfil(perfil, rede);
    } else {
        try {
            rede->getPerfil(opcao)->adicionarSeguidor(perfil); //tenta adicinar o seguidor
        } catch (invalid_argument *e) {
            cout << e->what() << endl;
            delete e;
        }
        opcoesDePerfil(perfil, rede);
    }
}

//coleta as informacoes para realizar uma publicacao do perfil logado
void fazerPublicacao(Perfil* perfil, RedeSocial* rede) {
    cout << endl;
    string ehEvento;
    cout << "Evento (s/n): ";
    cin >> ehEvento;
    cin.ignore(100, '\n');
    string data;

    if(ehEvento.compare("s") == 0) {
        cout << "Data: ";
        cin >> data;
        cin.ignore(100, '\n');
    }

    string texto;
    cout << "Texto: ";
    getline(cin, texto);

    if(ehEvento.compare("s") == 0) {
        perfil->publicar(texto, data);
    } else {
        perfil->publicar(texto);
    }
    cout << endl;
    opcoesDePerfil(perfil, rede);
}

//mostra as publicacoes recebidas e permite curtir uma publicacao de outro usuario
void mostraRecebidas(Perfil* perfil, RedeSocial* rede) {
    cout << endl;
    cout << "Publicacoes recebidas: " << endl;
    list<Publicacao*>::iterator itr;
    int cont = 1, opcao;

    //varrendo as publicacoes
    //obs que evento tem um comportamento um pouco diferente por isso foi necessario o cast
    for(itr = perfil->getPublicacoesRecebidas()->begin(); itr != perfil->getPublicacoesRecebidas()->end(); itr++) {
        Evento* testeEvento = dynamic_cast<Evento*> (*itr);
        Mensagem* testeMsg = dynamic_cast<Mensagem*> (*itr);
        if (testeMsg != NULL) {
            cout << cont << ") " << testeMsg->getTexto() << " ("
                                 << testeMsg->getAutor()->getNome() << ") ["
                                 << testeMsg->getCurtidas() << "]" << endl;

        } else if (testeEvento != NULL) {
            cout << cont << ") " << testeEvento->getData() << " - "
                                 << testeEvento->getTexto() << " ("
                                 << testeEvento->getAutor()->getNome() <<") ["
                                 << testeEvento->getCurtidas() << "]" << endl;
        }
        cont += 1;
    }
    cout << "Digite o numero da mensagem para curtir ou 0 para voltar: ";
    cin >> opcao;
    cin.ignore(100, '\n');
    cont = 1;

    //percorrendo novamente as recebidas para poder atribuir corretamente a curtida
    for(itr = perfil->getPublicacoesRecebidas()->begin(); itr != perfil->getPublicacoesRecebidas()->end(); itr++) {
        if (cont == opcao) {
            try {
                (*itr)->curtir(perfil);
            } catch (invalid_argument *e) {
                cout << endl;
                cout << e->what() << endl;
                delete e;
            }
        } else {
            cont += 1;
        }
    }

    cout << endl;
    opcoesDePerfil(perfil, rede);
}

//Apenas mostra as publicacoes feitas pelo usuario
void mostraFeitas(Perfil* perfil, RedeSocial* rede) {
    cout << endl;
    cout << "Publicacoes feitas: " << endl;
    list<Publicacao*>::iterator itr;

    //varrendo a lista e imprimindo as publicacoes
    for(itr = perfil->getPublicacoesFeitas()->begin(); itr != perfil->getPublicacoesFeitas()->end(); itr++) {
        cout << (*itr)->getTexto() << " (" << (*itr)->getAutor()->getNome() << ") [" << (*itr)->getCurtidas() << "]" << endl;
    }
    cout << endl;
    opcoesDePerfil(perfil, rede);
}

//mostra as opcoes que um perfil tem e encaminha para a tela
void opcoesDePerfil(Perfil* perfil, RedeSocial* rede) {
    cout << endl;

    //cast necessario pois cada tipo de perfil tem um comportamento diferente na hora de ser mostrado
    Aluno* testeAluno     = dynamic_cast<Aluno*>(perfil);
    Professor* testeProf  = dynamic_cast<Professor*>(perfil);
    Disciplina* testeDisc = dynamic_cast<Disciplina*>(perfil);

    if (testeAluno != NULL) {
        cout << testeAluno->getNumeroUSP() << " - " << testeAluno->getNome() << endl;
    } else if (testeProf != NULL) {
        cout << testeProf->getNumeroUSP() << " - " << testeProf->getNome() << endl;
        cout << "Departamento: " << testeProf->getDepartamento() << endl;
    } else if (testeDisc != NULL) {
        cout << testeDisc->getSigla() << " - " << testeDisc->getNome() << endl;
    }

    //essa parte eh comum a todos os tipos de perfil
    cout << "Seguidores: " << perfil->getSeguidores()->size() << endl;
    cout << "---" << endl;
    int opcao;
    cout << "Escolha uma opcao: " << endl;
    cout << "1) Ver publicacoes feitas " << endl;
    cout << "2) Ver publicacoes recebidas " << endl;
    cout << "3) Fazer publicacao " << endl;
    if (testeDisc == NULL) {
        cout << "4) Seguir perfil " << endl;
    }

    cout << "0) Deslogar " << endl;
    cin >> opcao;
    cin.ignore(100, '\n');
    cout << endl;

    //encaminhando para a tela correta
    if (opcao == 0) {
        opcoesDeRede(rede);
    } else if (opcao == 1) {
        mostraFeitas(perfil, rede);
    } else if (opcao == 2) {
        mostraRecebidas(perfil, rede);
    } else if (opcao == 3) {
        fazerPublicacao(perfil, rede);
    } else if (opcao == 4 && testeDisc == NULL) {
        mostraPerfis(perfil, rede);
    }

}

//mostra os perfis disponiveis na rede e encaminha para as opcoes especificas
void logar(RedeSocial* rede) {
    cout << endl;
    cout << "Escolha um perfil: " << endl;
    int opcao;

    //mostrando cada perfil com base no ID na tela
    vector<Perfil*>::iterator itr;
    for(itr = rede->getPerfis()->begin(); itr != rede->getPerfis()->end(); itr++) {
        cout << (*itr)->getId() << ") " << (*itr)->getNome() << endl;
    }
    cout << "Digite o id ou 0 para cancelar: ";
    cin >> opcao;
    cin.ignore(100, '\n');

    cout << endl;
    if (opcao == 0) {
        opcoesDeRede(rede);
    } else {
        try {

            //tentando se a escolha eh valida
            opcoesDePerfil(rede->getPerfil(opcao), rede);
        } catch (PerfilInexistente* e) {
            cout << e->what() << endl;
            delete e;
        }
    }
}

//mostra as opcoes da criacao de disciplina e adc na rede
void criaDisciplina(RedeSocial* rede) {
    cout << endl;
    cout << "Informe os dados da disciplina: " << endl;
    string sigla, nome;
    int opcao;

    //coletando os dados
    cout << "Sigla: ";
    cin >> sigla;
    cin.ignore(100, '\n');
    cout << "Nome: ";
    cin >> nome;
    cin.ignore(100, '\n');
    cout << "Responsavel: " << endl;

    //mostrando possiveis perfis de responsavel
    vector<Perfil*>::iterator itr;
    for(itr = rede->getPerfis()->begin(); itr != rede->getPerfis()->end(); itr++) {
        cout << (*itr)->getId() << ") " << (*itr)->getNome() << endl;
    }
    cout << "Digite o id ou 0 para cancelar: ";
    cin >> opcao;
    cin.ignore(100, '\n');
    cout << endl;

    if (opcao == 0) {
        opcoesDeRede(rede);
    } else {
        //teste feito para confirmar se eh um professor
        Professor* testeProf = dynamic_cast<Professor*>(rede->getPerfil(opcao));
        if (testeProf != NULL) {
            Disciplina* disc = new Disciplina(sigla, nome, testeProf);
            rede->adicionar(disc);
            opcoesDeRede(rede);

        } else {
            //caso nn seja um professor mostra o erro
            cout << endl << "Somente professores podem ser responsaveis por disciplinas" << endl << endl;
            opcoesDeRede(rede);
        }
    }
}

//mostra opcoes de criacao de perfil e adc na rede
void criaPerfil(RedeSocial* rede) {
    cout << endl;
    //coletando informacoes
    int nUSP;
    string nome, email, ehProf;
    cout << "Informe os dados do perfil " << endl;
    cout << "Numero USP: ";
    cin >> nUSP;
    cin.ignore(100, '\n');
    cout << "Nome: ";
    cin >> nome; //nomes nn terao espacos entao ta check
    cin.ignore(100, '\n');
    cout << "Email: ";
    cin >> email;
    cin.ignore(100, '\n');
    cout << "Professor (s/n): ";
    cin >> ehProf;
    cin.ignore(100, '\n');

    //checando se ehProf
    if(ehProf.compare("s") == 0) {
        string dpto;
        cout << "Departamento: ";
        cin >> dpto;
        cin.ignore(100, '\n');

        Professor* prof = new Professor(nUSP, nome, email, dpto);

        try {
            //tentando adicionar na rede sendo prof
            rede->adicionar(prof);
        } catch (invalid_argument *e) {
            cout << e->what() << endl;
            delete e;
        }

    } else if (ehProf.compare("n") == 0) {
        Aluno* aluno = new Aluno(nUSP, nome, email);
        try {
            //tentando adicionar caso aluno
            rede->adicionar(aluno);
        } catch (invalid_argument *e) {
            cout << e->what() << endl;
            delete e;
        }
    }
    cout << endl;
    opcoesDeRede(rede);
}

//mostra as possibilidades de rede
void opcoesDeRede(RedeSocial* rede) {
    cout << endl;
    //mostrando possibilidades
    cout << "Escolha uma opcao: " << endl;
    cout << "1) Cadastrar Perfil " << endl;
    cout << "2) Cadastrar Disciplina " << endl;
    cout << "3) Logar " << endl;
    cout << "0) Terminar " << endl;

    int opcao;
    cin >> opcao;
    cin.ignore(100, '\n');

    cout << endl;

    //encaminhando para a tela correta
    if (opcao == 1) {
        criaPerfil(rede);
    } else if (opcao == 2) {
        criaDisciplina(rede);
    } else if (opcao == 3) {
        logar(rede);
    } else {

    }
}

//o main ira iniciar o nossa rede e a persistencia
//e no main terminara tambem a execucao da rede
int main() {

    //----- INICIO DO PROGRAMA -----
    string arquivo;
    cout << "Arquivo: ";
    cin >> arquivo;
    cin.ignore(100, '\n');
    RedeSocial* rede;
    PersistenciaDaRede* persistencia = new PersistenciaDaRede(arquivo);
    try {
        rede = persistencia->carregar();
    } catch (logic_error *e) {
        cout << e->what() << endl;
        delete e;
    }

    //----- INDO PARA O PROGRAMA EM SI -----
    cout << endl;
    opcoesDeRede(rede); //como voce necessariamente passa por essa tela para iniciar e terminar esta aqui
    cout << endl;

    //----- FINAL DO PROGRAMA -----
    string salvar;
    cout << "Deseja salvar? (s/n) ";
    cin >> salvar;
    cin.ignore(100, '\n');

    //vendo se quer salvar
    if (salvar.compare("s") == 0) {
        persistencia->salvar(rede);
    }

    //limpando
    delete rede;
    delete persistencia;

    return 0;
}
