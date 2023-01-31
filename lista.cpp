#include "lista.h"
#include "Paciente.h"
#include "Node.h"

// Construtor
lista::lista(){
  primeiro = NULL;
  ultimo = NULL;
}


// Método insere: cria e insere um novo nó na lista organizando por ordem alfábetica de nome
void lista::insere(int id, string nome, string orgao, int Grau_Urgencia, string descricao){
  Paciente* P = new Paciente(id, nome, orgao, Grau_Urgencia, descricao); // alocação dinamica do obj e chamada do ctor
  if(P == NULL){
    cout << "Erro de alocação de memória... \n";
    exit(EXIT_FAILURE);
  }

  // se ainda não há nenhum elemento na lista
  if(this->vazia() == true){
    Nodeptr aux = new Node(*P); // alocação dinamica de novo nó e chamada do ctor
    if(aux == NULL){
      cout << "Erro de alcoação de memória... \n";
      exit(EXIT_FAILURE);
    }

    primeiro = aux;        // novo elemento torna-se o primeiro elemento da lista
    ultimo = aux;          // novo elemento torna-se o último elemento da lista
    aux->setDir(aux);      // proximo elemento do novo elemento é ele mesmo
    aux->setEsq(aux);      // elemento anterior ao novo elemento é ele mesmo

    /* se há pelo menos um elemento na lista */
  } else {
    Nodeptr aux = new Node(*P); // alocação dinamica de novo nó e chamada do ctor
    if(aux == NULL){
      cout << "Erro de alcoação de memória... \n";
      exit(EXIT_FAILURE);
    }
    Nodeptr ptr = primeiro;
		Paciente P1 = ptr->getP(); 
		string primeiroNome = P1.getNome();   

    /* Se nome do novo paciente ter maior precedencia que o do primeiro paciente da lista, insere como novo primeiro praciente */
    if(P->getNome() < primeiroNome){
      ultimo->setDir(aux);     // conecta ultimo elemento da lista ao novo primeiro elemento
      aux->setEsq(ultimo);     // conecta novo elemento ao ultimo elemento da lista
      
      primeiro->setEsq(aux);   // conecta atual primeiro elemento da lista ao novo elemento
      aux->setDir(primeiro);   // conecta novo elemento ao atual primeiro elemento da lista

      primeiro = aux;          // novo elemento torna-se o primeiro elemento da lista


      /* Se não tiver maior precedencia que o primero paciente da lista */          
    } else {
      ptr = ultimo;                      // ptr Node auxiliar recebe referencia do primeiro elemento
      P1 = ptr->getP();                  // ptr Paciente auxiliar recebe referencia do elemento
      string ultimoName = P1.getNome();  // armazena valor do grau de urgencia

      /* Se novo paciente tiver nome com maior procedencia que do ultimo paciente da lista, insere como novo ultimo elemento da lista */
      if(P->getNome() > ultimoName){
        ultimo->setDir(aux);    // conecta ultimo elemento da lista ao novo elemento
        aux->setEsq(ultimo);    // conecta novo elemento ao ultimo elemento da lista
        
        primeiro->setEsq(aux);  // conecta atual primeiro elemento da lista ao novo elemento
        aux->setDir(primeiro);  // conecta novo elemento ao primeiro elemento da fila

        ultimo = aux;           // novo elemento torna-se o primeiro elemento da lista    


        /* se nome do novo paciente tiver mais procedencia que o primeiro e menos procedencia que o utlimo, insere após paciente com maior precendencia que ele */
      } else {
        ptr = primeiro;                     // ptr Node auxiliar recebe referencia do primeiro elemento
        P1 = ptr->getP();                   // ptr Paciente auxiliar recebe referencia do elemento
        string atualName = P1.getNome();    // armazena valor do grau de urgencia

        while(P->getNome() <= atualName) {
          ptr = ptr->getdir();              // ptr Node recebe referência do proximo nó
          P1 = ptr->getP();                 // ptr Paciente auxiliar recebe referencia do paciente do nó atual
          atualName = P1.getNome();         // armazena valor do grau de urgencia de paciente do nó atual
        } // fim while
        /* laço de repetição para no primeiro paciente da lista que possui maior procedencia que o novo paciente */

        ptr->getesq()->setDir(aux);      // nó da esquerda conecta novo nó como sendo sua direita
        aux->setEsq(ptr->getesq());      // conecta novo elemento ao nó da esquerda
        
        ptr->getdir()->setEsq(aux);      // nó da direitra conecta ao novo nó como sendo sua esquerda
        aux->setDir(ptr);                // novo nó é conectado ao nó da direita

      } // fim if
    } // fim if
  } // fim if
} // fim enfileira


// Método cheia: verifica se a lista está cheia / obs: só estará caso não haja memória local no pc do usuário
bool lista::cheia(){
  return false;
}


// Método vazia: verifica se a lista está vazia
bool lista::vazia(){
  if(primeiro == NULL)
    return true;
  else
    return false;
}


void lista::imprimeTodos(){
  if(this->vazia() != true){
    Nodeptr ptr = primeiro;
    Paciente P = ptr->getP();

    if(primeiro->getdir() == primeiro){
      cout << ">>ID: " << P.getId() << "    >>Nome: " << P.getNome() << endl;
      cout << ">>Orgão: " << P.getOrgao() << "    >>Grau de Urgência: " << P.getGrau_Urgencia() << endl;
      cout << ">>Descrição: " << P.getDescricao() << endl;
      cout << "\n";
    } else {
      bool controle = false;
      while(controle == false){
        cout << "> ID: " << P.getId() << "    > Nome: " << P.getNome() << endl;
        cout << "> Orgão: " << P.getOrgao() << "    > Grau de Urgência: " << P.getGrau_Urgencia() << endl;
        cout << "> Descrição: " << P.getDescricao() << endl;
        cout << "\n";

        ptr = ptr->getdir();
        P = ptr->getP();

        if(ptr == primeiro){
          controle = true;
        }
      }
    }
  }
}