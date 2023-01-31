#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <cstdlib>

#include "Paciente.h"

using namespace std;

class Node{
	private:
		Paciente *P;
		Node *Esq;
		Node *Dir;
	public:
		Node(Paciente &);
		~Node();
		Paciente getP() const;
		Node *getdir() const;
		Node *getesq() const;
		void setP(Paciente P);
		void setDir(Node *);
		void setEsq(Node *);
};

typedef Node *Nodeptr;

#endif