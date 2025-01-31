#include "PersistenciaDaRede.h"
#include <iostream>
#include <fstream>
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"
#include <stdexcept>

using namespace std;

//construtor
PersistenciaDaRede::PersistenciaDaRede(string arquivo) {
    this->arquivo = arquivo;
}

PersistenciaDaRede::~PersistenciaDaRede() {
}

//salva o estado da rede em documento .txt
void PersistenciaDaRede::salvar(RedeSocial* r) {
    //abrindo o documento e escrevendo o ultimo id
    ofstream documento;
    documento.open(arquivo.c_str());

    //checa se conseguiu abrir o documento
    if(documento.bad()) {
        throw new logic_error("Erro ao abrir o arquivo");

    } else {

        int n_alunos = 0, n_prof = 0, n_disc = 0;
        documento << Perfil::getUltimoId() << "\n";
        vector<Perfil*>::iterator itr;

        //percorrendo o vector para contar quantos perfis de cada tipo temos
        for(itr = r->getPerfis()->begin(); itr != r->getPerfis()->end(); itr++) {
            Aluno* testeAluno = dynamic_cast<Aluno*>(*itr);
            Professor* testeProf = dynamic_cast<Professor*>(*itr);
            Disciplina* testeDisc = dynamic_cast<Disciplina*>(*itr);
            if (testeAluno != NULL) {
                n_alunos += 1;
            } else if (testeProf != NULL) {
                n_prof += 1;
            } else if (testeDisc != NULL) {
                n_disc += 1;
            }
        }

        //percorrendo para escrever as descricoes dos alunos
        documento << n_alunos << "\n";
        for(itr = r->getPerfis()->begin(); itr != r->getPerfis()->end(); itr++) {
            Aluno* testeAluno = dynamic_cast<Aluno*>(*itr);
            if (testeAluno != NULL) {
                documento << testeAluno->getId() << " "
                          << testeAluno->getNumeroUSP() << " "
                          << testeAluno->getNome() << " "
                          << testeAluno->getEmail() << "\n";
            }
        }

        //percorrendo para escrever as descricoes dos professores
        documento << n_prof << "\n";
        for(itr = r->getPerfis()->begin(); itr != r->getPerfis()->end(); itr++) {
            Professor* testeProf = dynamic_cast<Professor*>(*itr);
            if (testeProf != NULL) {
                documento << testeProf->getId() << " "
                          << testeProf->getNumeroUSP() << " "
                          << testeProf->getNome() << " "
                          << testeProf->getEmail() << " "
                          << testeProf->getDepartamento() << "\n";
            }
        }

        //percorrendo para escrever as descricoes das disciplinas
        documento << n_disc << "\n";
        for(itr = r->getPerfis()->begin(); itr != r->getPerfis()->end(); itr++) {
            Disciplina* testeDisc = dynamic_cast<Disciplina*>(*itr);
            if (testeDisc != NULL) {
                documento << testeDisc->getId() << " "
                          << testeDisc->getSigla() << " "
                          << testeDisc->getNome() << " "
                          << testeDisc->getResponsavel()->getId() << "\n";
            }
        }

        //percorrendo uma ultima vez para atribuir as relacoes de seguido-seguidor
        vector<Perfil*>::iterator itr2;
        for(itr = r->getPerfis()->begin(); itr != r->getPerfis()->end(); itr++) {
            int id_1, id_2;
            id_1 = (*itr)->getId();
            for (itr2 = (*itr)->getSeguidores()->begin(); itr2 != (*itr)->getSeguidores()->end(); itr2++) {
                id_2 = (*itr2)->getId();
                documento << id_1 << " " << id_2 << "\n";
            }
        }
        documento.close();
    }
}

//devolve uma rede a partir de um documento .txt
RedeSocial* PersistenciaDaRede::carregar() {
    //abrindo o documento para pegar os dados
    ifstream documento;
    documento.open(arquivo.c_str());
    RedeSocial* rede = new RedeSocial(); //nova rede para retornar

    //teste para checar se o arquivo existe
    //se a abertura falhar pq nn existe ele apenas retorna rede vazia
    if (documento.fail()) { //o doc nn existe
        return rede;

    //badbit significa um erro de leitura
    } else if (documento.bad()) { //deu erro na leitura
        throw new logic_error("Erro de leitura do arquivo");

    //se conseguir abrir ele checa por esses dados na rede
    } else {
        int ultimo, n_alunos, n_prof, n_disc;
        documento >> ultimo;
        Perfil::setUltimoId(ultimo);

        //settando alunos
        int id, nUSP;
        string nome, email;
        documento >> n_alunos;
        for(int i = 0; i < n_alunos; i++) {
            documento >> id >> nUSP >> nome >> email;
            Aluno* aluno = new Aluno(id, nUSP, nome, email);
            rede->adicionar(aluno);
        }

        //settando prof
        string departamento;
        documento >> n_prof;
        for(int i = 0; i < n_prof; i++) {
            documento >> id >> nUSP >> nome >> email >> departamento;
            Professor* prof = new Professor(id, nUSP, nome, email, departamento);
            rede->adicionar(prof);
        }

        //settando disc
        string sigla;
        int id_r;
        documento >> n_disc;
        for(int i = 0; i < n_disc; i++) {
            documento >> id >> sigla >> nome >> id_r;
            Professor* responsavel = dynamic_cast<Professor*>(rede->getPerfil(id_r));
            Disciplina* disc = new Disciplina(id, sigla, nome, responsavel);
            rede->adicionar(disc);
        }

        //settando relacao seguido-seguidor
        int id_1, id_2;
        while (documento) {
            documento >> id_1 >> id_2;
            if(!documento.eof()) {
                rede->getPerfil(id_1)->adicionarSeguidor(rede->getPerfil(id_2));
            } else {
                documento.close();
                return rede;
            }
        }
    }
}
