#include <iostream>
#include <string>
#include <cstring>

using std::getline; 
using namespace std;

#include "Fila.h"
#include "lista.h"
#include "Paciente.h"

void Final(){
	cout<<"\n\n \t\tDIGITE QUALQUER LETRA E TECLE ENTER: ";
  cout<<flush;
	string enter;
	cin>>enter;
	system("clear");
}

void finalDireto(){
  system("clear");
}

int main() {
	
  fila f1;
  lista geral;
  lista obito;
  lista atendido;
  lista desistente;


  int select=100;
  while(select != 0){
		cout <<"\t\t FILA DE TRANSPLANTE DE ORGÃOS  \n\n";
    cout << "\t ========================================== \n";
  	cout << "\t\t\t\tQUADRO DE OPÇÕES\n\n";
    cout << "\t ========================================== \n";
  	cout << "\t\t[1] Inserir novo paciente na fila\n";
  	cout << "\t\t[2] Atender paciente \n";
		cout << "\t\t[3] Visualizar Pacientes\n";
    cout << "\t\t[4] Remover um Paciente da fila\n\n";
  	cout << "\t\t[0] Encerrar programa \n";
    cout << "\t ========================================== \n";
  	cout << "\n";

		cout << "\t\tDigite a opção desejada: ";
    cin >> select;
    cout << "\n";
		
    
		if(select == 1){
      finalDireto();
      
      int validator = 0;

      while(validator < 4){
        cout << "\t\tInserindo novo paciente na fila de transplante: \n\n";
        cout << "\t\tDigite o ID: ";
        int id;
        cin >> id;
        cout << "\n";

        cout << "\t\tDigite o nome do Paciente: ";
        string nome;
        cin.ignore();
        getline( cin, nome );
        cout << "\n";

        nome.empty() ? validator = validator : validator += 1;

        cout << "\t\tDigite o orgão necessitado: ";
        string orgao;
        cin.ignore();
        getline( cin, orgao );
        cout << "\n";

        orgao.empty() ? validator = validator : validator += 1;

        cout << "\t\tDigite o grau de urgência(entre 1 a 5): ";
        int Grau_Urgencia;
        cin >> Grau_Urgencia;
        cout << "\n";

        if(Grau_Urgencia >= 1 && Grau_Urgencia <= 5){
          validator += 1;
        }

        cout << "\t\tDescreva a situação do paciente: ";
        string descricao;
        cin.ignore();
        getline( cin, descricao );
        cout << flush;
        cout << "\n\n";

        descricao.empty() ? validator = validator : validator += 1;

        if(validator == 4){
          f1.enfileira(id, nome, orgao, Grau_Urgencia, descricao);
          geral.insere(id, nome, orgao, Grau_Urgencia, descricao);

          finalDireto();
          cout << "\t\t++ Paciente \" "<< nome <<" \" incluído na fila de transplante ++\n\n";
          Final();

        } else {
          finalDireto();
          cout << "[ERRO] *Algum campo não foi preenchido corretamente! \n\n";
        }
      }
		}

    if(select == 2){
      finalDireto();

			Paciente P;
      string orgao;

      cout << "Informe o orgão disponível para transplante: ";
      cin >> orgao;
      cout << "\n\n";

      f1.desenfileira(P, orgao);
      
      if(P.getOrgao() == orgao){
        cout << "++ AÇÃO EXECUTADA COM SUCESSO ++\n\n";
        cout << "\t Dados do paciente \n";
        cout << "--------------------------------------";
        cout << "\t> id: " << P.getId() << "   > nome: " << P.getNome() << endl;
        cout << "\t> orgão: " << P.getOrgao() << "grau de urgência: " << P.getGrau_Urgencia() << endl;
        cout << "\t> descrição: " << P.getDescricao() << endl;
        cout << "--------------------------------------";
        cout << "\n\n";
        atendido.insere(P.getId(), P.getNome(), P.getOrgao(), P.getGrau_Urgencia(), P.getDescricao());
				Final();
      } else {
        cout << "-- AÇÃO NÃO EXECUTADA -- \n\n\n";
				Final();
      }
    }

      int option;
    if(select == 3){
      finalDireto();
      cout << "\t ========================================== \n";
      cout << "\tVisualizar:\n";
      cout << "\t\t[1] Fila de Transplante de Orgãos \n";
      cout << "\t\t[2] Lista de  atendidos \n";
      cout << "\t\t[3] Lista de desistentes\n";
      cout << "\t\t[4] Lista de óbitos\n";
      cout << "\t ========================================== \n";
      cout << "\n\n\n";
      
      cout << "\t Informe a opção desejada: ";
      cin >> option;
      cout << "\n\n";

      if(option >=1 && option <= 4){
        if(option == 1){
          finalDireto();
          cout << "\t [1] Visualizar todos \n";
          cout << "\t [2] Visualizar por grau de urgência \n\n";

          cout << "\t Informe a maneira desejada: ";
          int modo;
          cin >> modo;
          cout << "\n\n\n";

          if(modo == 1 && f1.vazia() == false){
            cout << "============ Imprimindo todos pacientes da fila ============ \n\n";
            f1.imprimeTodos();
            cout << "============================================================ \n\n\n";
          }

          if(modo == 2 && f1.vazia() == false){
            int grau;
            cout << "\t Informe o grau de urgencia a ser imprimido: ";
            cin >> grau;
            
            cout << "============ Imprimindo pacientes da fila com grau" << grau << " ============ \n\n";
            f1.imprimeGrau(grau);
            cout << "============================================================================= \n\n\n";
          }
        } 
          
        if(option == 2 && atendido.vazia() == false){
          cout << "============ Imprimindo todos pacientes da Lista de atendidos ============ \n\n";
          atendido.imprimeTodos();
          cout << "======================================================================= \n\n\n";
          
        }

        if(option == 3 && desistente.vazia() == false){
          cout << "============ Imprimindo todos pacientes da Lista de desistentes ============ \n\n";
          desistente.imprimeTodos();
          cout << "======================================================================= \n\n\n";

        }

        if(option == 4 && obito.vazia() == false){
          cout << "============ Imprimindo todos pacientes da Lista de óbitos ============ \n\n";
          obito.imprimeTodos();
          cout << "======================================================================= \n\n\n";
        }
        
        Final();
      }
    } else {
      finalDireto();
      cout << "--- AÇÃO NÃO REALIZADA --- \n";
      cout << "*opção \"" << option << "\" escolhida é inválida! \n\n";
      Final();
    }

    if(select == 4){
      finalDireto();
      cout << "\tInforme o id do paciente a ser removido: ";
      int id;
      cin >> id;
      cout << "\n\n";

      cout << "\t ========================================== \n";
      cout << "\t\tQUADRO DE OPÇÕES >> REMOVE PACIENTE\n\n";
      cout << "\t ========================================== \n";
      cout << "\t\t[1] Óbito \n";
      cout << "\t\t[2] Desistente \n";
      cout << "\t\t[3] Já atendido\n\n";
      cout << "\t ========================================== \n\n";

      cout << "\tInforme o motivo da remoção: ";
      int remotion;
      cin >> remotion;
      cout << "\n\n";
      
      if(remotion >=1 && remotion <=3){
        Paciente P;
        f1.removeID(P, id);
        
        if(P.getId() == id){
          finalDireto();
          cout << "+++ PACIENTE REMOVIDO COM SUCESSO +++ \n\n";

          if(remotion == 1){
            obito.insere(P.getId(), P.getNome(), P.getOrgao(), P.getGrau_Urgencia(), P.getDescricao());
            cout << "Paciente \" " << P.getId() << " - " << P.getNome() << " \" inserido na lista de óbitos\n\n";
            Final();
          }

          if(remotion == 2){
            desistente.insere(P.getId(), P.getNome(), P.getOrgao(), P.getGrau_Urgencia(), P.getDescricao());
            cout << "Paciente \" " << P.getId() << " - " << P.getNome() << " \" inserido na lista de desistentes\n\n";
            Final();
          }

          if(remotion == 3){
            atendido.insere(P.getId(), P.getNome(), P.getOrgao(), P.getGrau_Urgencia(), P.getDescricao());
            cout << "Paciente \" " << P.getId() << " - " << P.getNome() << " \" inserido na lista de atendidos\n\n";
            Final();
          }
        } else {
          finalDireto();
          cout << "--- AÇÃO NÃO REALIZADA --- \n";
          cout << "*Não há paciente com o id \"" << id << "\" na fila de transplante \n\n";
          Final();
        }

      } else {
        finalDireto();
        cout << "--- AÇÃO NÃO REALIZADA --- \n";
        cout << "*Motivo de remoção \"" << remotion << "\" inválido \n\n";
				Final();
      }
    }

    if(select == 0){
      cout << "Encerrando programa \n" << "... \n";
    }
  }

  return 0;
}
