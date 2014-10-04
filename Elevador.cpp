#include "Elevador.h"

Elevador::Elevador()
{
	andar = 0;
	nandares = 0;
	subir = 0;
	descer = 0;
	pesomax = 0;
	modelo = "";
	alarme = 0;
}

Elevador::Elevador(int andar,int nandares, int subir, int descer, float pesomax, string modelo, int alarme){
	Elevador::andar = andar;
	Elevador::nandares = nandares;
	Elevador::subir = subir;
	Elevador::descer = descer;
	Elevador::pesomax = pesomax;
	Elevador::modelo = modelo;
	Elevador::alarme = alarme;
}

void Elevador::setSubir(int subir){
	Elevador::subir = subir;
}

int Elevador::getSubir(){
	return subir;
}

void Elevador::setDescer(int descer){
	Elevador::descer = descer;
}

int Elevador::getDescer(){
	return descer;
}

void Elevador::setAndar(int andar){
	Elevador::andar = andar;
}

int Elevador::getAndar(){
	return andar;
}

int Elevador::getNAndares(){
	return nandares;
}

int Elevador::getAlarme(){
	return alarme;
}

string Elevador::getModelo(){
	return modelo;
}

void Elevador::chamar(int *subir, int *descer,int *andar,float *peso){
	Elevador::subir = *subir;
	Elevador::descer = *descer;
	Elevador::andar = *andar;
	
	if (*peso > pesomax)
	   emergencia();
	
}

void Elevador::info() const{
	cout<<"-- Informacoes do elevador:\n";
	cout<<"\nModelo: "<<modelo<<".";
	cout<<"\nPeso maximo suportado pelo elevador: "<<pesomax<<" kgs.";
	cout<<"\nNumero de andares do predio: "<<nandares<<".";
}
	
void Elevador::emergencia(){
	alarme = 1;
}

int Elevador::verificaAndar(int andaratual, int andar,int subir, int descer)const{
	if (subir == 1 && descer == 0) //elevador sobe
		if (andaratual >= andar)
			return -1; //Erro
		else
			return 0;
	else if (subir == 0 && descer == 1) //elevador desce
		if (andaratual <= andar)
			return -1;
		else
			return 0;
	else
		return -1;
}