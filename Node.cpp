#include "Node.h"

Node::Node(Paciente &P1){
	P = &P1;
	Esq = NULL;
	Dir = NULL;
}

Node::~Node(){
}

Paciente Node::getP() const{
	return *P;
}

Nodeptr Node::getdir() const{
	return Dir;
}

Nodeptr Node::getesq() const{
	return Esq;
}

void Node::setP(Paciente P){
	this->P = &P;
}

void Node::setDir(Nodeptr Direito){
	Dir = Direito;
}
void Node::setEsq(Nodeptr Esquerdo){
	Esq = Esquerdo;
}
