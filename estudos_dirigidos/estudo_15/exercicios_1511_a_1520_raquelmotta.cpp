/*
PUC MINAS - AEDs1
Junho/2024

Estudo Dirigido 15

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: exercicios_1511_a_1520_raquelmotta
Versao: 0.0

*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>

using std::cout;
using std::cin;


class kelstring{
	
public:
	
	std::string s;
	
	int tam = 0;
	
	char c = 0;
	
	//construtor
	kelstring(){
		
		cout << "\ndigite uma cadeia de caracteres:  ";
		cin >> s;
		tam = s.length();
		
	}
	
	char* add_end_string (){
		
		cout << "\nqual caractere vc deseja acrescentar ao final da string? ";
		
		cin >> c;
		
		tam = s.size() + 2;
		// +1 for the null terminator
		// +1 para o novo caractere adicionado
		
		//se o tamanho da string é x, o ultimo elemento está na posicao x-1
		
		char* destino = new char[tam];
		
		for (int i = 0; i < s.size(); i++) {
			
			destino[i] = s[i];
			
		}
		
		destino[s.size()] = c;
		
		//set the null terminator
		destino[s.size()+1] = '\0';
		
		return destino;
	}
	
	char* remove_end_string (){
		
		cout << "\no valor na ultima posicao que sera removido eh: " << s[s.size()-1];
		
		//o tamanho da nova string sera o mesmo da original, pois removemos 1 caractere mas adicionamos o \0
		
		char* destino = new char[tam];
		
		for (int i = 0; i < tam-1; i++) {
			
			destino[i] = s[i];
			
		}
		
		destino[tam-1] = '\0';
		
		return destino;
	}
	
	char* add_start_string (){
		
		cout << "\nqual caractere vc deseja acrescentar ao inicio da string? ";
		
		cin >> c;
		
		tam = s.size() + 2;
		// +1 for the null terminator
		// +1 para o novo caractere adicionado
		
		//se o tamanho da string é x, o ultimo elemento está na posicao x-1
		
		char* destino = new char[tam];
		
		destino[0] = c;
		
		int x = 0;
		
		for (int i = 1; i < tam-1; i++) {
			
			destino[i] = s[x];
			
			x++;
		}
		
		//set the null terminator
		destino[tam-1] = '\0';
		
		return destino;
	}
	
	char* remove_start_string (){
		
		cout << "\no valor na primeira posicao que sera removido eh: " << s[0];
		
		//o tamanho da nova string sera o mesmo da original, pois removemos 1 caractere mas adicionamos o \0
		
		char* destino = new char[tam];
		
		int x = 0;
		
		for (int i = 1; i < s.size(); i++) {
			
			destino[x] = s[i];
			
			x++;
		}
		
		destino[tam-1] = '\0';
		
		return destino;
	}
	
	char* add_mid_string (){
		
		cout << "\nqual caractere vc deseja acrescentar ao meio (aproximadamente) da string? ";
		
		cin >> c;
		
		tam = s.size() + 2;
		
		char* destino = new char[tam];
		
		int x = 0;
		
		int middle = (int)((tam-1)/2);
		
		for (int i = 0; i < tam-1; i++) {
			
			if(i == middle){
				
				destino[i] = c;
				
			}else{
				
				destino[i] = s[x];
				x++;
				
			}
			
			
		}
		
		destino[tam-1] = '\0';
		
		return destino;
	}
	
	char* remove_mid_string(){
		
		tam = s.size();
		
		char* destino = new char[tam];
		
		int x = 0;
		int y = 0;
		
		int middle = (int)((tam)/2);

		
		while(x < s.size()){
			
			if(x != middle){
				
				destino[y] = s[x];
				y++;
				x++;
				
			}else{
				
				x++;
				
			}
			
		}
		
		destino[tam-1] = '\0';
		
		cout << "\no valor na posicao do meio (aproximada) que sera removido eh: " << s[middle];
		
		return destino;
	}
	
	char* add_pos_string(){
		
		int pos = 0;
		
		cout << "\nqual caractere vc deseja acrescentar a string? ";
		
		cin >> c;
		
		cout << "\nem qual posicao? ";
		
		cin >> pos;
		
		if (pos<0 || pos>s.size()){
			
			cout << "\nERRO. posicao invalida";
			
			return nullptr;
		}
		
		tam = s.size() + 2;
		
		char* destino = new char[tam];
		
		int x = 0;
		
		for (int i = 0; i < tam-1; i++) {
			
			if(i == pos){
				
				destino[i] = c;
				
			}else{
				
				destino[i] = s[x];
				x++;
				
			}
			
			
		}
		
		destino[tam-1] = '\0';
		
		return destino;
	}
	
	char* remove_pos_string(){
		
		int pos = 0;
		
		cout << "\nqual a posicao do caractere que vc deseja remover? ";
		
		cin >> pos;
		
		if (pos<0 || pos>s.size()-1){
			
			cout << "\nERRO. posicao invalida";
			
			return nullptr;
		}
		
		tam = s.size();
		
		char* destino = new char[tam];
		
		int x = 0;
		int y = 0;
		
		
		while(x < s.size()){
			
			if(x != pos){
				
				destino[y] = s[x];
				y++;
				x++;
				
			}else{
				
				x++;
				
			}
			
		}
		
		destino[tam-1] = '\0';
		
		return destino;
	}
	
	char* seek_value (){
		
		cout << "\nqual caractere vc deseja procurar? ";
		
		cin >> c;
		
		int pos = 0;
		int counter = 0;
		int x = 0;
		
		while (x < s.length()){
			
			if(s[x] == c && counter == 0){	//apenas atribui o x a pos na primeira ocorrencia do valor
				
				pos = x;
				counter = 1;
				
			}
			
			x++;
			
		}
		
		if(counter == 0){
			
			cout << "\nERRO. o valor procurado nao existe na string";
			return nullptr;	//se nao achou o valor retorna nulo
			
		}else{
			
			cout << "\na primeira ocorrencia do caractere " << c << " no arranjo eh na posicao " << pos;
			
			tam = s.size() - pos + 1;
			
			char* destino = new char[tam];
			
			int h = 0;
			
			for(int i = pos; h<tam-1; i++){
				
				destino[h] = s[i];
				h++;
			}
			
			destino[tam-1] = '\0';
			
			return destino;
			
		}
	}
	
	char* split_value (){
		
		cout << "\nqual caractere vc deseja procurar? ";
		
		cin >> c;
		
		int pos = 0;
		int counter = 0;
		int x = 0;
		
		while (x < s.length()){
			
			if(s[x] == c && counter == 0){	//apenas atribui o x a pos na primeira ocorrencia do valor
				
				pos = x;
				counter = 1;
				
			}
			
			x++;
			
		}
		
		if(counter == 0){
			
			cout << "\nERRO. o valor procurado nao existe na string";
			return nullptr;	//se nao achou o valor retorna nulo
			
		}else{
			
			cout << "\na primeira ocorrencia do caractere " << c << " no arranjo eh na posicao " << pos;
			
			tam = pos + 2;
			//+1 é para o \0
			//o outro +1 é para que o tamanho seja igual ao numero de elementos
			
			char* destino = new char[tam];
			
			
			for(int i = 0; i<tam-1; i++){
				
				destino[i] = s[i];
			}
			
			destino[tam-1] = '\0';
			
			return destino;
		}
	}
	
};

void print_chars (char* cadeia){
	
	int i = 0;
	
	cout << "\n";
	
	while(cadeia[i] != '\0'){
		
		cout << cadeia[i];
		i++;
	}
}

//>>>>>>>>>> metodo_01 - exercicio 1511 <<<<<<<<<<

void metodo_01 (){
	
	cout << "\nmetodo_01\n";
	
	kelstring str;
	
	char* destino = str.add_end_string();
	
	cout << "\nstring modificada:";
	
	print_chars(destino);
}



//>>>>>>>>>> metodo_02 - exercicio 1512 <<<<<<<<<<

void metodo_02 (){
	
	cout << "\nmetodo_02\n";
	
	kelstring str;
	
	char* destino = str.remove_end_string();
	
	cout << "\n\nstring modificada:";
	
	print_chars(destino);
}



//>>>>>>>>>> metodo_03 - exercicio 1513 <<<<<<<<<<

void metodo_03 (){
	
	cout << "\nmetodo_03\n";
	
	kelstring str;
	
	char* destino = str.add_start_string();
	
	cout << "\nstring modificada:";
	
	print_chars(destino);
}



//>>>>>>>>>> metodo_04 - exercicio 1514 <<<<<<<<<<

void metodo_04 (){
	
	cout << "\nmetodo_04\n";
	
	kelstring str;
	
	char* destino = str.remove_start_string();
	
	cout << "\n\nstring modificada:";
	
	print_chars(destino);
}



//>>>>>>>>>> metodo_05 - exercicio 1515 <<<<<<<<<<

void metodo_05 (){
	
	cout << "\nmetodo_05\n";
	
	kelstring str;
	
	char* destino = str.add_mid_string();
	
	cout << "\nstring modificada:";
	
	print_chars(destino);	
}



//>>>>>>>>>> metodo_06 - exercicio 1516 <<<<<<<<<<

void metodo_06 (){
	
	cout << "\nmetodo_06\n";
	
	kelstring str;
	
	char* destino = str.remove_mid_string();
	
	cout << "\n\nstring modificada:";
	
	print_chars(destino);
}



//>>>>>>>>>> metodo_07 - exercicio 1517 <<<<<<<<<<

void metodo_07 (){
	
	cout << "\nmetodo_07\n";
	
	kelstring str;
	
	char* destino = str.add_pos_string();
	
	if (destino != nullptr){
		
		cout << "\nstring modificada:";
		print_chars(destino);
	}
}



//>>>>>>>>>> metodo_08 - exercicio 1518 <<<<<<<<<<

void metodo_08 (){
	
	cout << "\nmetodo_08\n";
	
	kelstring str;
	
	char* destino = str.remove_pos_string();
	
	if (destino != nullptr){
		
		cout << "\nstring modificada:";
		print_chars(destino);
	}
}



//>>>>>>>>>> metodo_09 - exercicio 1519 <<<<<<<<<<

void metodo_09 (){
	
	cout << "\nmetodo_09\n";
	
	kelstring str;
	
	char* destino = str.seek_value();
	
	if (destino != nullptr){
		
		cout << "\n\nstring A PARTIR da primeira ocorrencia do caractere procurado:";
		print_chars(destino);
	}
	
}



//>>>>>>>>>> metodo_10 - exercicio 1520 <<<<<<<<<<

void metodo_10 (){
	
	cout << "\nmetodo_10\n";
	
	kelstring str;
	
	char* destino = str.split_value();
	
	if (destino != nullptr){
		
		cout << "\n\nstring ATE a primeira ocorrencia do caractere procurado:";
		print_chars(destino);
	}
}



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int main (){
	
	int opcao = 0;
	
	//identificar o programa
	cout << "estudo dirigido 15\n";
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

