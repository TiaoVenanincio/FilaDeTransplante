#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <string>
#include "Node.h"
#include "Paciente.h"

class lista{
  private:
    Nodeptr primeiro;
    Nodeptr ultimo;

  public:
    lista();

    void insere(int, string, string, int, string);
    bool vazia();
    bool cheia();
    void imprimeTodos();
};

#endif