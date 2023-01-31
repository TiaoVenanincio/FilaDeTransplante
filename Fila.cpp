#include "Fila.h"
#include "Paciente.h"
#include "Node.h"

// Construtor
fila::fila(){
  primeiro = NULL;
  ultimo = NULL;
}


// Método enfileira: cria e enfileira um novo nó
void fila::enfileira(int id, string nome, string orgao, int Grau_Urgencia, string descricao){
  /* validação: grau de urgencia só aceita valores inteiros de 1 a 5 */
  if(Grau_Urgencia >= 1 && Grau_Urgencia <= 5) {

    Paciente* P = new Paciente(id, nome, orgao, Grau_Urgencia, descricao); // alocação dinamica do obj e chamada do ctor
    if(P == NULL){
      cout << "Erro de alocação de memória... \n";
      exit(EXIT_FAILURE);
    }

    // se ainda não há nenhum elemento na fila 
    if(this->vazia() == true){
      Nodeptr aux = new Node(*P); // alocação dinamica de novo nó e chamada do ctor
      if(aux == NULL){
        cout << "Erro de alcoação de memória... \n";
        exit(EXIT_FAILURE);
      }

      primeiro = aux;       // novo elemento torna-se o primeiro elemento da fila
      ultimo = aux;         // novo elemento torna-se o último elemento da fila
      aux->setDir(aux);      // proximo elemento do novo elemento é ele mesmo
      aux->setEsq(aux);      // elemento anterior ao novo elemento é ele mesmo

      /* se há pelo menos um elemento na fila */
    } else {
      Nodeptr aux = new Node(*P); // alocação dinamica de novo nó e chamada do ctor
      if(aux == NULL){
        cout << "Erro de alcoação de memória... \n";
        exit(EXIT_FAILURE);
      }
      Nodeptr ptr = primeiro;
      Paciente P1 = ptr->getP(); 
      int grau_primeiro = P1.getGrau_Urgencia();   

      /* Se grau de urgência do novo paciente for maior que o do atual primeiro paciente da fila, insere como novo primeiro */
      if(P->getGrau_Urgencia() > grau_primeiro){
        ultimo->setDir(aux);     // conecta ultimo elemento da fila ao novo primeiro elemento
        aux->setEsq(ultimo);     // conecta novo elemento ao ultimo elemento da fila
        
        primeiro->setEsq(aux);   // conecta atual primeiro elemento da fila ao novo elemento
        aux->setDir(primeiro);   // conecta novo elemento ao atual primeiro elemento da fila

        primeiro = aux;          // novo elemento torna-se o primeiro elemento da fila  


        /*Se o grau de urgencia do novo paciente for menor ou igual ao do primeiro, insere após o ultimo elemento com mesmo grau     de urgência*/          
      } else {
        ptr = ultimo;                             // ptr Node auxiliar recebe referencia do primeiro elemento
        P1 = ptr->getP();                         // ptr Paciente auxiliar recebe referencia do elemento
        int grau_ultimo = P1.getGrau_Urgencia();  // armazena valor do grau de urgencia

        /* se novo grau de urgencia for menor ou igual ao ultimo elemento da fila, insere como novo ultimo elemento da fila */
        if(P->getGrau_Urgencia() <= grau_ultimo){
          ultimo->setDir(aux);    // conecta ultimo elemento da fila ao novo elemento
          aux->setEsq(ultimo);    // conecta novo elemento ao ultimo elemento da fila
          
          primeiro->setEsq(aux);  // conecta atual primeiro elemento da fila ao novo elemento
          aux->setDir(primeiro);  // conecta novo elemento ao primeiro elemento da fila

          ultimo = aux;           // novo elemento torna-se o primeiro elemento da fila    


          /* se o novo grau de urgência é diferente de 1, insere após o ultimo paciente com mesmo grau de urgencia */
        } else {
          ptr = primeiro;                           // ptr Node auxiliar recebe referencia do primeiro elemento
          P1 = ptr->getP();                         // ptr Paciente auxiliar recebe referencia do elemento
          int grau_atual = P1.getGrau_Urgencia();   // armazena valor do grau de urgencia

          while(P->getGrau_Urgencia() >= grau_atual) {
            ptr = ptr->getdir();                    // ptr Node recebe referência do proximo nó
            P1 = ptr->getP();                       // ptr Paciente auxiliar recebe referencia do paciente do nó atual
            grau_atual = P1.getGrau_Urgencia();     // armazena valor do grau de urgencia de paciente do nó atual
          } // fim while
          /* laço de repetição para no primeiro paciente que possui grau menor que o dele */

          ptr->getesq()->setDir(aux);      // nó da esquerda conecta novo nó como sendo sua direita
          aux->setEsq(ptr->getesq());      // conecta novo elemento ao nó da esquerda
          
          ptr->getdir()->setEsq(aux);      // nó da direitra conecta ao novo nó como sendo sua esquerda
          aux->setDir(ptr);                // novo nó é conectado ao nó da direita

        } // fim if
      } // fim if
    } // fim if
  } else {
    cout << "Grau de urgência inválido \n\n";
  }
} // fim enfileira


void fila::desenfileira(Paciente &P, string orgao){
	if(primeiro==NULL){
		cout<<"Não há pacientes na Fila de Transplantes \n\n";
	}
	else{
		if(primeiro->getdir() == primeiro){
			P = primeiro->getP();
			delete primeiro;
			primeiro = NULL;
		}
		else{
			Paciente Aux = primeiro->getP();
			string orgao_aux = Aux.getOrgao();
			if(orgao_aux == orgao){
				P = Aux;
				Nodeptr ptr1 = primeiro;
				primeiro = primeiro->getdir();
				primeiro->setEsq(ultimo);
				delete ptr1;
			}
			else{
				Nodeptr ptr1 = primeiro;
        bool controle = false;
				while(orgao_aux != orgao && controle == false ){
					ptr1 = ptr1->getdir();
					Aux = ptr1->getP();
					orgao_aux = Aux.getOrgao();

          if(ptr1->getdir() == primeiro){
            controle = true;
          }
				}
        if(controle == false){
          Nodeptr Ant = ptr1->getesq();
          Nodeptr Dep = ptr1->getdir();
          Ant->setDir(Dep);
          Dep->setEsq(Ant);
          P = Aux;
          delete ptr1;
        }
			}
		}
	}
}

// Método cheia: verifica se a fila está cheia / obs: só estará caso não haja memória local no pc do usuário
bool fila::cheia(){
  return false;
}

// Método vazia: verifica se a fila está vazia
bool fila::vazia(){
  if(primeiro == NULL)
    return true;
  else
    return false;
}

void fila::imprimeGrau(int imprimeGrau){
  // validação do valor do grau de prioridade: aceita numeros inteiros de 0 a 5
  if(imprimeGrau >= 1 && imprimeGrau <=5 && this->vazia() == false){
    Nodeptr ptr = primeiro;                 // ponteiro auxiliar do tipo node recebe referencia ao primeiro paciente da fila
    Paciente P = ptr->getP();               // obj auxiliar do tipo paciente recebe os dados do paciente contido em ptr
    int grauUrgencia = P.getGrau_Urgencia();// variavel auxiliar recebe valor do grau de urgencia 

    bool controle = true;     // variavel de controle de laço de repetição
    
    // laço de repetição enquato variavel de controle for verdadeira
    while(controle == true){
      /* se grau de urgência do paciente atual em análise for igual ao grau de urgencia recebido por parametro, imprime dados do paciente */
      if(grauUrgencia == imprimeGrau){
        cout << "> ID: " << P.getId() << "    > Nome: " << P.getNome() << endl;
        cout << "> Orgão: " << P.getOrgao() << "    > Grau de Urgência: " << P.getGrau_Urgencia() << endl;
        cout << "> Descrição: " << P.getDescricao() << endl;
        cout << "\n";
      }

      ptr = ptr->getdir();                // ptr recebe referencia do próximo nó
      P = ptr->getP();                    // paciente recebe atributos do paciente contido no nó
      grauUrgencia = P.getGrau_Urgencia();// variavel recebe valor do grau de urgencia do pacient em análise

      /* se grau de urgencia do paciente em análise for menor que o grau recebido por parametro, ou o elemento a ser analisado for o primeiro elemento da fila novamente, variavel de controle encerra o laço de reptição */
      if(grauUrgencia < imprimeGrau || ptr == primeiro){
        controle = false;
      }
    }
  }
}

void fila::imprimeTodos(){
  /* imprime todos os pacientes da fila utilizando o método imprimeGrau */
  for(int i = 5; i >= 1; i--){
    this->imprimeGrau(i);
  }
}

void fila::removeID(Paciente &P, int idRetira){
  /* Se não houver pacientes na fila */
  if(primeiro == NULL){
		cout<<"Não há pacientes na Fila de Transplantes \n\n";

    /* Há pelo menos um paciente na fila */
	} else {
    Nodeptr ptr = primeiro;     // ptr auxiliar recebe referencia do primeiro nó
    Paciente aux = ptr->getP(); // obj auxiliar recebe referencia do paciente contido em ptr
    int id_aux = aux.getId();   // variavelr ecebe id do paciente

    /* Se há apenas um paciente na fila e é o paciente a ser retirado */
		if(primeiro->getdir() == primeiro && id_aux == idRetira){
			P = primeiro->getP(); // bacukp dos dados do paciente
			delete primeiro;      // deleta paciente
			primeiro = NULL;      // limpa variavel
      ultimo = NULL;        // limpa variavel


      /* Se há mais de um paciente na fila */
		} else {

      /* Se paciente a ser retirado é o primeiro da fila*/
			if(id_aux == idRetira){
        P = primeiro->getP();
				ptr->getdir()->setEsq(ultimo);  // segundo nó é conectado ao ultimo nó
        primeiro = ptr->getdir();       // segundo nó torna-se novo primeiro nó
        ultimo->setDir(primeiro);       // ultimo nó é conectado ao novo primeiro nó

				delete ptr; // deleta nó

        /* se paciente a ser retirado não é o primeiro da fila */
			} else {
        bool controle = false;

        /* laço de reptição procura paciente com id recebido por parametro; caso ache ou a fila acabe, o laço é encerrado */
				while(id_aux != idRetira || controle == false ){
					ptr = ptr->getdir();  
					aux = ptr->getP();
					id_aux = aux.getId();

          if(ptr == primeiro){
            controle = true;
          }
				}

        /* se achou o id procurado */
        if(controle == false) {
          ptr->getesq()->setDir(ptr->getdir()); // nó anterior ao nó atual é conectado ao proximo nó do nó atual
          ptr->getdir()->setEsq(ptr->getesq()); // próximo nó do nó atual é concetado ao nó anterior do nó atual
          P = aux;      // bacukp dos dados do paciente
          delete ptr;   // deleta paciente
        }
			}
		}
	}
}