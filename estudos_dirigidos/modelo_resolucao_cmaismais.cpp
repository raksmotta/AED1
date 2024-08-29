/*
PUC MINAS - AEDs1
Maio/2024

Estudo Dirigido 00

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: exercicios_0000_a_0000_raquelmotta
Versao: 0.0

*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using std::cout;
using std::cin;



//>>>>>>>>>> metodo_01 - exercicio 0011 <<<<<<<<<<

void metodo_01 (){
	
	cout << "\nmetodo_01\n";
	
}



//>>>>>>>>>> metodo_02 - exercicio 0012 <<<<<<<<<<

void metodo_02 (){
	
	cout << "\nmetodo_02\n";
	
}



//>>>>>>>>>> metodo_03 - exercicio 0013 <<<<<<<<<<

void metodo_03 (){
	
	cout << "\nmetodo_03\n";
	
}



//>>>>>>>>>> metodo_04 - exercicio 0014 <<<<<<<<<<

void metodo_04 (){
	
	cout << "\nmetodo_04\n";
	
}



//>>>>>>>>>> metodo_05 - exercicio 0015 <<<<<<<<<<

void metodo_05 (){
	
	cout << "\nmetodo_05\n";
	
}



//>>>>>>>>>> metodo_06 - exercicio 0016 <<<<<<<<<<

void metodo_06 (){
	
	cout << "\nmetodo_06\n";
	
}



//>>>>>>>>>> metodo_07 - exercicio 0017 <<<<<<<<<<

void metodo_07 (){
	
	cout << "\nmetodo_07\n";
	
}



//>>>>>>>>>> metodo_08 - exercicio 0018 <<<<<<<<<<

void metodo_08 (){
	
	cout << "\nmetodo_08\n";
	
}



//>>>>>>>>>> metodo_09 - exercicio 0019 <<<<<<<<<<

void metodo_09 (){
	
	cout << "\nmetodo_09\n";
	
}



//>>>>>>>>>> metodo_10 - exercicio 0020 <<<<<<<<<<

void metodo_10 (){
	
	cout << "\nmetodo_10\n";
	
}



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int main (){
	
	int opcao = 0;
	
	//identificar o programa
	cout << "estudo dirigido 00\n";
	cout << "autor: raquel de parde motta - matricula: 854017";
	
	do{
		//mostrar as opcoes
		cout << "\n\n--------------------------------------------------------";
		cout << "\n0 - encerrar";
		cout << "\n1 - metodo_01";
		cout << "\n2 - metodo_02";
		cout << "\n3 - metodo_03";
		cout << "\n4 - metodo_04";
		cout << "\n5 - metodo_05";
		cout << "\n6 - metodo_06";
		cout << "\n7 - metodo_07";
		cout << "\n8 - metodo_08";
		cout << "\n9 - metodo_09";
		cout << "\n10 - metodo_10";
		
		
		//ler o valor inputado
		cout << "\n\nescolha o metodo:  ";
		cin >> opcao;
		
		switch (opcao) {
		case 0:
			break;
		case 1:
			metodo_01 ();
			break;
		case 2:
			metodo_02 ();
			break;
		case 3:
			metodo_03 ();
			break;
		case 4:
			metodo_04 ();
			break;
		case 5:
			metodo_05 ();
			break;
		case 6:
			metodo_06 ();
			break;
		case 7:
			metodo_07 ();
			break;
		case 8:
			metodo_08 ();
			break;
		case 9:
			metodo_09 ();
			break;
		case 10:
			metodo_10 ();
			break;
		default:
			cout << "erro. opcao invalida.";
			break;
		}
		
	}while(opcao !=0);
	
	return 0;
}

