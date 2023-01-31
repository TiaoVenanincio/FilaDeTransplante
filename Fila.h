#ifndef FILA_H
#define FILA_H

#include <iostream>
#include <string>
#include "Node.h"
#include "Paciente.h"

class fila{
  private:
    Nodeptr primeiro;
    Nodeptr ultimo;

  public:
    Nodeptr inicio;
    
    fila();
    void enfileira(int, string, string, int, string);
    void desenfileira(Paciente &P, string orgao);
    bool vazia();
    bool cheia();
    void imprimeGrau(int);
    void imprimeTodos();
    void removeID(Paciente &, int);
};

#endif

/*fazer no main:
  imprime todos + opção de visualizar um paciente no final
  imprime todos pacientes de um determinado grau de necessidade + opção de visualizar um paciente no final
  imprime todos pacientes que entraram de xx/xx/xxxx há xx/xx/xxxx + opção de visualizar um paciente no final
  Visualizar paciente: procura um paciente e, caso encontrado, dá a opção de ver/imprimir todos os seus dados (nesse caso ja se tem conhecimento de que o paciente está na lista pois foi visualizado. Utiliza-se o procura paciente para pegar seus dados)
  Procura paciente: procura um determinado paciente pelo nome.
*/
