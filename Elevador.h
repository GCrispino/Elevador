#ifndef ELEVADOR_H
#define ELEVADOR_H
#include<iostream>

using namespace std;

class Elevador
{
public:
	Elevador();
	Elevador(int andar,int nandares, int subir, int descer, float pesomax, string modelo, int alarme);
	
	void setSubir(int subir);
	int getSubir();
	void setDescer(int subir);
	int getDescer();
	void setAndar(int andar);
	int getAndar();
	int getNAndares();
	int getAlarme();
	void setPeso(float peso);
	string getModelo();
	
	void chamar(int *subir, int *descer,int *andar,float *peso);//passagem por referencia feita para "economizar" memória
	inline void emergencia();												   //a cada vez que este método for chamado.
	void info() const;
	int verificaAndar(int andaratual, int andar,int subir,int descer) const; //Verifica se a escolha dos andares foi feita
																	//corretamente, de acordo com a subida/descida do elevador.
private:
	int andar;    //Indica o andar atual do elevador quando ele pára.
	int nandares; //Numero de andares do prédio.
	int subir;     //Variável que representa o botão de subir do elevador.
	int descer; 	  //Variável que representa o botão de descer do elevador.
	float pesomax;  //Peso máximo(em kgs) que o elevador suporta.
	string modelo; //Variável que guarda o modelo do elevador.
	int alarme;    //Variável que aciona um alarme caso a acapacidade em kg seja ultrapassada.
};

#endif // ELEVADOR_H

