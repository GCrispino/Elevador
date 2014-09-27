#include "Elevador.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>       

using namespace std;

int main(int argc, char **argv)
{
    int andaratual,andar,nandares,opcao,s,d;
	string modelo;
	float pesomax,peso;
	char r;
	
	cout<<"||||ELEVADOR|||\n";
	
	cout<<"\nDigite as informacoes referentes ao elevador:";
	cout<<" (aperte qualquer tecla para continuar...)";
	getch();
	system("cls");
	cout<<"\nModelo: ";
	cin>>modelo;
	cout<<"\nPeso maximo que o elevador suporta(em kg): ";
	cin>>pesomax;
	cout<<"\nNumero de andares do predio: ";
	cin>>nandares;
	system("cls");
	
	Elevador e(0,nandares,0,0,pesomax,modelo,0);
	
	cout<<"\nO que voce deseja fazer?\n";
	cout<<"\n 1- Imprimir as informacoes do elevador e sair do programa;";
	cout<<"\n 2- Chamar o elevador.\n";
	cin>>opcao;
	system("cls");
	
	switch(opcao){
		case 1:
			e.info();
			break;
		case 2:
			do{
				do{
					cout<<"Voce deseja (s)ubir ou (d)escer?";
					cin>>r;
					r = toupper(r);
					if(r == 'S'){
						e.setSubir(1);
						e.setDescer(0);
					}
					else{
						e.setSubir(0);
						e.setDescer(1);
					}
				}while(r != 'S' && r != 'D');
				
				do{
					cout<<"\nEm que andar voce esta? ";
					cin>>andaratual;
					if (andaratual < 1 || andaratual > e.getNAndares()){
						cout<<"Opcao invalida!!\n";
						getch();
					}
				}while(andaratual < 1 || andaratual > e.getNAndares());
				
				e.setAndar(andaratual);
				
				do{
					cout<<"\nPara que andar voce deseja ir? ";
					cin>>andar;
					if (andar < 1 || andar > e.getNAndares()){
						cout<<"Opcao invalida!!\n";
						getch();
					}
				}while(andar < 1 || andar > e.getNAndares());
				cout<<"\nDigite o valor total do peso ocupado pelos passageiros do elevador: ";
				cin>>peso;
				if( e.verificaAndar(e.getAndar(),andar,e.getSubir(),e.getDescer()) == -1){
					cout<<"\nValores informados nao compactuam com a escolha de subida/descida!\n";
					cout<<"\nAperte qualquer tecla para voltar a entrada de dados...";
					getch();
					system("cls");
				}
			}while (e.verificaAndar(e.getAndar(),andar,e.getSubir(),e.getDescer()) == -1);
			
			s = e.getSubir();
			d = e.getDescer();
			andaratual = e.getAndar();
			
			e.chamar(&s,&d,&andaratual,&peso);
			
			if (e.getAlarme() == 1){
				cout<<"\nO elevador nao pode se movimentar pois o peso dentro dele ultrapassa o peso limite!";
				cout<<"\nRetire algumas pessoas do elevador e entre novamente com o peso total: ";
				cin>>peso;
					if (peso > pesomax){
						do{
							cout<<"\nO peso continua excedente. Entre com o valor do peso novamente: ";
							cin>>peso;
						}while(peso > pesomax);
						cout<<"\nPeso aceito! Pressione qualquer tecla para que o elevador va para o andar desejado.";
						getch();
					}
			}
			
			cout<<"\nVoce acaba de chegar ao andar "<<andar<<"!";
			
			cout<<"\n\nObrigado por utilizar o elevador "<<e.getModelo()<<"!";
			getch();
			break;
	}
	
	
	cout<<"\n\nPrograma encerrado.";
	getch();
	return 0;
}
