#include <iostream>
#include <string>
#include "RedeSocial.h"

using namespace std;

void opcoesDeRede(RedeSocial* rede);
void opcoesDePerfil(RedeSocial* rede, Perfil* p);
void pubFeitas (RedeSocial* rede, Perfil *p);
void pubRecebidas (RedeSocial* rede, Perfil *p);
void fazPublicacao(RedeSocial* rede, Perfil *p);
void opcoesDeDisciplina(RedeSocial* rede, Perfil* d);
void pubFeitasDisciplina(RedeSocial* rede, Perfil* d);
void pubRecebidasDisciplina(RedeSocial* rede, Perfil* d);

void fazPublicacaoDisciplina(RedeSocial* rede, Perfil* d){
    cout << endl;
    string ehEvento;
    string texto;

    cout << "Evento (s/n): ";
    cin >> ehEvento;
    cin.ignore(100, '\n');

    if (ehEvento.compare("s") == 0){
        string data;
        cout << "Data: ";
        getline(cin, data);

        cout << "Texto: ";
        cin >> texto;
        getline(cin, texto);

        d->publicar(texto, data);

    } else if (ehEvento.compare("n") == 0){
        cout << "Texto: ";
        getline(cin, texto);
        d->publicar(texto);
    }

    cout << endl;
    opcoesDeDisciplina(rede, d);
}

void pubRecebidasDisciplina(RedeSocial* rede, Perfil *d){
    cout << endl;
    int opcao;
    cout << "Publicacoes recebidas: " << endl;
    for (int i = 0; i < d->getQuantidadeDePublicacoesRecebidas(); i++){
        cout << i+1 << ") ";
        d->getPublicacoesRecebidas()[i]->imprimir();
    }
    cout << "Digite o numero da mensagem para curtir ou 0 para voltar: ";
    cin >> opcao;
    cin.ignore(100, '\n');

    if (opcao == 0){
        cout << endl;
        opcoesDeDisciplina(rede, d);
    } else {
        d->getPublicacoesRecebidas()[opcao - 1]->curtir(d);
        cout << endl;
        opcoesDeDisciplina(rede, d);
    }
}

void pubFeitasDisciplina(RedeSocial* rede, Perfil *d){
    cout << endl;
    cout << "Publicacoes feitas: " << endl;
    for (int i = 0; i < d->getQuantidadeDePublicacoesFeitas(); i++){
        d->getPublicacoesFeitas()[i]->imprimir();
    }
    cout << endl;
    opcoesDeDisciplina(rede, d);
}

void opcoesDeDisciplina(RedeSocial* rede, Perfil* d){
    cout << endl;
    int escolha;
    d->imprimir();

    cout << "---" << endl;
    cout << "Escolha uma opcao: " << endl;
    cout << "1) Ver publicacoes feitas " << endl;
    cout << "2) Ver publicacoes recebidas " << endl;
    cout << "3) Fazer publicacao " << endl;
    cout << "0) Deslogar " << endl;

    cin >> escolha;
    cin.ignore(100, '\n');
    cout << endl;

    if (escolha == 0){
        opcoesDeRede(rede);
    } else if (escolha == 1){
        pubFeitasDisciplina(rede, d);
    } else if (escolha == 2){
        pubRecebidasDisciplina(rede, d);
    } else if (escolha == 3){
        fazPublicacaoDisciplina(rede, d);
    }
}

void seguirPerfil(RedeSocial* rede, Perfil* p){
    cout << endl;
    int opcao;
    cout << "Perfil: " << endl;
    rede->mostraPerfis();
    cin >> opcao;
    cin.ignore(100, '\n');
    rede->getPerfis()[opcao-1]->adicionarSeguidor(p);
    opcoesDePerfil(rede, p);
}

void fazPublicacao(RedeSocial* rede, Perfil* p){
    cout << endl;
    string ehEvento;
    string texto;

    cout << "Evento (s/n): ";
    cin >> ehEvento;
    cin.ignore(100, '\n');

    if (ehEvento.compare("s") == 0){
        string data;
        cout << "Data: ";
        getline(cin, data);

        cout << "Texto: ";
        cin >> texto;
        getline(cin, texto);

        p->publicar(texto, data);

    } else if (ehEvento.compare("n") == 0){
        cout << "Texto: ";
        getline(cin, texto);
        p->publicar(texto);
    }

    cout << endl;
    opcoesDePerfil(rede, p);
}

void pubRecebidas (RedeSocial* rede, Perfil *p){
    cout << endl;
    int opcao;
    cout << "Publicacoes recebidas: " << endl;
    for (int i = 0; i < p->getQuantidadeDePublicacoesRecebidas(); i++){
        cout << i+1 << ") ";
        p->getPublicacoesRecebidas()[i]->imprimir();
    }
    cout << "Digite o numero da mensagem para curtir ou 0 para voltar: ";
    cin >> opcao;
    cin.ignore(100, '\n');

    if (opcao == 0){
        cout << endl;
        opcoesDePerfil(rede, p);
    } else {
        p->getPublicacoesRecebidas()[opcao - 1]->curtir(p);
        cout << endl;
        opcoesDePerfil(rede, p);
    }
}

void pubFeitas (RedeSocial* rede, Perfil *p){
    cout << endl;
    cout << "Publicacoes feitas: " << endl;
    for (int i = 0; i < p->getQuantidadeDePublicacoesFeitas(); i++){
        p->getPublicacoesFeitas()[i]->imprimir();
    }
    cout << endl;
    opcoesDePerfil(rede, p);
}

void opcoesDePerfil(RedeSocial* rede, Perfil *p){
    cout << endl;
    int escolha;
    p->imprimir();

    cout << "---" << endl;
    cout << "Escolha uma opcao: " << endl;
    cout << "1) Ver publicacoes feitas " << endl;
    cout << "2) Ver publicacoes recebidas " << endl;
    cout << "3) Fazer publicacao " << endl;
    cout << "4) Seguir perfil " << endl;
    cout << "0) Deslogar " << endl;

    cin >> escolha;
    cin.ignore(100, '\n');
    cout << endl;

    if (escolha == 0){
        opcoesDeRede(rede);
    } else if (escolha == 1){
        pubFeitas(rede, p);
    } else if (escolha == 2){
        pubRecebidas(rede, p);
    } else if (escolha == 3){
        fazPublicacao(rede, p);
    } else if (escolha == 4){
        seguirPerfil(rede, p);
    }
}

void logar(RedeSocial* rede){
    cout << endl;
    int opcao;
    cout << "Escolha um perfil: " << endl;
    rede->mostraPerfis();
    cin >> opcao;
    cin.ignore(100, '\n');
    cout << endl;
    if (opcao == 0){
        opcoesDeRede(rede);
    } else {
        Disciplina* testaDisciplina = dynamic_cast<Disciplina*>(rede->getPerfis()[opcao-1]);
        if (testaDisciplina == NULL){
            opcoesDePerfil(rede, rede->getPerfis()[opcao-1]);
        } else {
            opcoesDeDisciplina(rede, rede->getPerfis()[opcao-1]);
        }
    }
}

void criarDisciplina(RedeSocial* rede){
    cout << endl;
    string sigla;
    string nome;
    cout << "Informe os dados da disciplina " << endl;

    cout << "Sigla: ";
    cin >> sigla;
    cin.ignore(100, '\n');

    cout << "Nome: ";
    getline(cin, nome);

    cout << endl;

    if(rede->passaDadosDisciplina(sigla, nome)){
        opcoesDeRede(rede);
    } else {
        cout << "Apenas professores podem ser responsaveis por disciplinas " << endl;
        cout << endl;
        opcoesDeRede(rede);
    }
}

void criarPerfil(RedeSocial* rede){
    cout << endl;
    int nUSP;
    string nome;
    string email;
    string ehprof;
    cout << "Informe os dados do perfil " << endl;

    cout << "Numero USP: ";
    cin >> nUSP;
    cin.ignore(100, '\n');

    cout << "Nome: ";
    getline(cin, nome);

    cout << "Email: ";
    cin >> email;
    cin.ignore(100, '\n');

    cout << "Professor (s/n): ";
    cin >> ehprof;
    cin.ignore(100, '\n');

    rede->passaDadosPerfil(nUSP, nome, email, ehprof);

    cout << endl;

    opcoesDeRede(rede);
}

void opcoesDeRede(RedeSocial* rede){
    cout << endl;

    int opcao;
    cout << "Escolha uma opcao: " << endl;
    cout << "1) Cadastrar Perfil " << endl;
    cout << "2) Cadastrar Disciplina " << endl;
    cout << "3) Logar " << endl;
    cout << "0) Terminar " << endl;

    cin >> opcao;
    cin.ignore(100, '\n');

    cout << endl;
    if (opcao == 1){
        criarPerfil(rede);
    } else if (opcao == 2){
        criarDisciplina (rede);
    } else if (opcao == 3){
        logar(rede);
    } else if (opcao == 0){
        delete rede;
    }
}

void inicializarRede(){
    int tamanho;
    cout << "Tamanho da rede: ";
    cin >> tamanho;
    cin.ignore(100, '\n');
    RedeSocial* rede = new RedeSocial(tamanho);
    cout << endl;
    opcoesDeRede(rede);
};

int main(){
    inicializarRede();
    return 0;
}
