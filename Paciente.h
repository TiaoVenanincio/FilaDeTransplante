#ifndef PACIENTE_H
#define PACIENTE_H

#include <iostream>
#include <string>
#include <ctime>

using namespace std;


class Paciente{
	private:

		int id; //identificação
		string nome;
		string orgao;//orgão necessitado
		int Grau_Urgencia;//Grau  de Urgencia
		string descricao;//tipo uma descrição do Paciente

	public:

    Paciente();
		Paciente(int id, string nome, string orgao, int Grau_Urgencia, string descricao);//construtor
		~Paciente();//destruidor

		//getters
		int getId() const;
		string getNome() const;
		string getOrgao() const;
		int getGrau_Urgencia() const;
		string getDescricao() const;

		//setters
		void setId(int id);
		void setNome(string nome);
		void setOrgao(string orgao);
		void setGrau_Urgencia(int Grau_Urgencia);
		void setDescricao(string descricao);
};

typedef Paciente *Pacienteptr;

#endif