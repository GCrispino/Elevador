#ifndef ELEVADOR_H
#define ELEVADOR_H
#include<iostream>

using namespace std;

class Elevador
{
public:
	Elevador();
	~Elevador();

private:
	int andar;    //Indica o andar atual do elevador quando ele pára.
	int nandares; //Numero de andares do prédio.
	int npessoas; //Numero máximo de pessoas que o elevador suporta.
	int subir;     //Variável que representa o botão de subir do elevador.
	int descer; 	  //Variável que representa o botão de descer do elevador.
	float pesomax;  //Peso máximo(em kgs) que o elevador suporta.
	string modelo; //Variável que guarda o modelo do elevador.
	int alarme;    //Variável que aciona um alarme caso a acapacidade em kg seja ultrapassada.
};

#endif // ELEVADOR_H
