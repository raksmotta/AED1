/*
PUC MINAS - AEDs1
Mai/2024

Estudo Dirigido 11

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: ed11_exercicio_1120_raquelmotta
Versao: 0.0

*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

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
		
		int n = qtd; // Initialize n to the total number of elements in the array
		
		while (n > 0){ 		// continue until no swaps are made (n becomes 0 because last_switched becomes 0)
			
			int last_switched = 0; 
			
			for (int i = 0; i < n - 1; ++i) {	//vai até a penúltima posição (n-1)
				
				if (array[i] > array[i + 1]) {
					
					swap(array[i], array[i + 1]);
					
					last_switched = i + 1; // update last switched to the last swapped position
				}
			}
			
			n = last_switched; // reduce n to the last swapped position for the next pass
			
		} 
	}
	
	void reverseBubbleSort (int* array){
		
		int n = qtd;
		int last_switch = 0;
		
		while (n>0){
			
			last_switch = 0;
			
			for(int i=0; i < n-1; i++){
				
				if(array[i] < array[i+1]){
					
					swap(array[i], array[i+1]);
					
					last_switch = i+1;
					
				}
				
			}
			
			n = last_switch;
			
		}
		
	}
	
};

int main (){
	
	//instanciando a classe dinamicamente. o objeto "ler" passa a existir. a memória precisa ser liberada com delete[].
	read_array_file* ler = new read_array_file(); 
	
	//o array resultado contém os inteiros escritos no arquivo
	int* resultado = ler->read_file();	
	
	cout << "\nos numeros lidos do arquivo sao:" << endl;
	
	int quantidade = ler->print_array(resultado);
	
	ler -> reverseBubbleSort(resultado);
	
	cout << "\nvalores ordenados em ordem DEcrescente: " << endl;
	
	ler->print_array(resultado);
	
	delete[] ler;
	ler = nullptr;

	return 0;
}
