/*
PUC MINAS - AEDs1
Mai/2024

Estudo Dirigido 11

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: ed11_exercicio_1116_raquelmotta
Versao: 0.0

*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//mesma classe do exercicio anterior
class read_array_file{
	
public:
	
	string fname;		
	int qtd = 0;
	
	read_array_file(){	//construtor
		
		qtd = read_file_qtd();
		
	}
	
	int read_file_qtd(){	//retorna a quantidade de inteiros no arquivo
		
		cout << "nome do arquivo:" << endl; //inputar "dados.txt" para testar
		cin >> fname;
		
		ifstream inputFile; //criando um objeto ifstream para abrir o arquivo de nome dado
		
		inputFile.open(fname);
		
		if (!inputFile.is_open()) {
			cerr << "\nnao foi possivel abrir o arquivo" << endl;
			return -1; // Return error code
		}
		
		int number;
		
		int quantidade = 0;
		
		while (inputFile >> number) {
			
			quantidade ++; 
			
		}		
		
		inputFile.close();
		
		return quantidade;
	}
	
	int* read_file (){
		
		int* array = new int[qtd];
		
		ifstream inputFile;
		
		inputFile.open(fname);
		
		int number = 0;
		int counter = 0;
		
		while (inputFile >> number) {
			
			array[counter] = number;
			
			counter ++;
			
		}		
		
		inputFile.close();
		
		return array;	
	}
	
	int print_array (int* array){
		
		for(int i = 0; i<qtd; i++){
			
			cout << array[i] << " ";
			
		}
		
		cout << endl;
		
		return qtd;
	}
	
	void bubbleSort(int* array) {
		
		bool swapped;
		
		for (int i = 0; i < qtd - 1; ++i) { 
			
			swapped = false;
			
			for (int j = 0; j < qtd - i - 1; ++j) { 
				
				if (array[j] > array[j + 1]) {	//verifica se o numero é menor que o valor imediatamente à frente dele
					
					swap(array[j], array[j + 1]); // se for MAIOR que o valor imediatamente à frente dele, troca os 2 de posição e bota o maior na frente
					
					swapped = true;
				}
				
			}
			
			// if no two elements were swapped by inner loop, then the list is sorted
			if (!swapped) {
				break;
			}
		}
	}
	
	
};

void is_all_negative(int* arr, int qtd){	//para testar usar "negativos.txt"
	
	bool is_neg = true;
	
	for(int i=0; i<qtd; i++){
		
		if(arr[i]>=0){
			
			is_neg = false;
			
		}
		
	}
	
	if(is_neg){
		
		cout << "\ntodos os numeros do arranjo sao negativos" << endl;
		
	}else{
		
		cout << "\ntodos os numeros do arranjo NAO sao negativos" << endl;
		
	}
	
}

int main (){
	
	//instanciando a classe dinamicamente. o objeto "ler" passa a existir. a memória precisa ser liberada com delete[].
	read_array_file* ler = new read_array_file(); 
	
	//o array resultado contém os inteiros escritos no arquivo
	int* resultado = ler->read_file();	
	
	cout << "\nos numeros lidos do arquivo sao:" << endl;
	
	ler->print_array(resultado);
	
	//ordenando o array em ordem crescente
	ler->bubbleSort(resultado);
	
	cout << "\nvalores ordenados em ordem crescente sao: " << endl;
	
	//além de imprimir o array, armazeno seu tamanho (quantidade de inteiros) na variável quantidade
	int quantidade = ler->print_array(resultado);
	
	is_all_negative(resultado, quantidade);
	
	delete[] ler;
	ler = nullptr;
	
	return 0;
}
