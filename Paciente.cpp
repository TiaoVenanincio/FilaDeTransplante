#include "Paciente.h"

Paciente::Paciente(){
  // ctor
}

Paciente::Paciente(int id, string nome, string orgao, int Grau_Urgencia,string descricao){
	this->id = id;
	this->nome = nome;
	this->orgao = orgao;
	this->Grau_Urgencia = Grau_Urgencia;
	this->descricao = descricao;
}

Paciente::~Paciente(){
}

int Paciente::getId() const{
	return id;
}

string Paciente::getNome() const{
	return nome;
}

string Paciente::getOrgao() const{
	return orgao;
}

int Paciente::getGrau_Urgencia() const{
	return Grau_Urgencia;
}

string Paciente::getDescricao() const{
	return descricao;
}

void Paciente::setId(int id){
	this->id = id;
}
void Paciente::setNome(string nome){
	this->nome = nome;
}

void Paciente::setOrgao(string orgao){
	this->orgao = orgao;
}

void Paciente::setGrau_Urgencia(int Grau_Urgencia){
	this->Grau_Urgencia = Grau_Urgencia;
}

void Paciente::setDescricao(string descricao){
	this->descricao = descricao;
}