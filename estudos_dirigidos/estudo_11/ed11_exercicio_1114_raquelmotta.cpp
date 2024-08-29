/*
PUC MINAS - AEDs1
Mai/2024

Estudo Dirigido 11

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: ed11_exercicio_1114_raquelmotta
Versao: 0.0

*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//agora modifiquei a classe para não trabalhar mais com vector, e sim com array apenas

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
		
		//int* array = (int*)malloc(qtd*sizeof(int));
		//int *dynamicArray = new int[n]; // Dynamic allocation of an array with n elements
		int* array = new int[qtd];
		//DÚVIDA: onde eu devo usar o delete[] e desalocar a memória desse array? O destrutor não irá reconhece-lo pois o array esta definido dentro dessa função
		
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

//---------------------------------------------------------------------------------------------

class ler_intervalo_teclado{
	
public:
	int lower_limit = 0;
	int upper_limit = 0;
	
	int num = 0; // tamanho do array que vai receber os resultados 
	
	
	ler_intervalo_teclado(){	//construtor
		
		cout<<"\ninsira o limite inferior do intervalo: "<<endl;
		cin >> lower_limit;
		
		cout<<"\ninsira o limite superior do intervalo: "<<endl;
		cin >> upper_limit;
		
		while (upper_limit<=lower_limit){
			
			cout<<"\nvalores invalidos. tente novamente."<<endl;
			
			cout<<"\ninsira o limite inferior do intervalo: "<<endl;
			cin >> lower_limit;
			
			cout<<"\ninsira o limite superior do intervalo: "<<endl;
			cin >> upper_limit;
			
		}
		
	}
	
	int* esta_no_intervalo (int* array, int n){	//n é o tamanho do array recebido. retorna array com valores que estao dentro do intervalo
		
		for(int i=0; i < n; i++) {
			
			if(lower_limit<=array[i] && array[i]<=upper_limit){
				
				num = num+1; //descobrindo o tamanho do array que vai guardar o resultado
				
			}
			
		}  
		
		//int* result = (int*)malloc(num * sizeof(int));
		int* result = new int[num];
		//DÚVIDA: onde eu devo usar o delete[] e desalocar a memória desse array? O destrutor não irá reconhece-lo pois o array esta definido dentro dessa função
		
		int count = 0;
		
		for(int i = 0; i < n; i++){
			
			if(lower_limit<=array[i] && array[i]<=upper_limit){
				
				result[count] = array[i];
				
				count ++;
				
			}
			
		}
		
		cout << "\n\nquantidade de valores dentro do intervalo = " << num << endl;
		
		return result;
		
	}
	
	
	void print_array_inside_interval(int* array) {	
		
		cout << "\n\nnumeros dentro do intervalo: " << endl;
		
		for (int x = 0; x<num; x++) {
			cout << array[x] << " ";
		}
		
		cout << endl;		
		
	}
	
};




int main (){
	
	//MyClass* obj = new MyClass(); //Calls the constructor of MyClass
	read_array_file* ler = new read_array_file(); 
	
	int* resultado = ler->read_file();	//criando um array para armazenar os inteiros lidos do arquivo
	//DUVIDA: precisa dar free nesse array? ^^^^
	
	cout << "\nos numeros lidos do arquivo sao:" << endl;
	
	ler->print_array(resultado);
	
	ler->bubbleSort(resultado);
	
	cout << "\nvalores ordenados em ordem crescente sao: " << endl;
	
	int quantidade = ler->print_array(resultado);	//agora tenho a quantidade de inteiros no array lido do arquivo (o tamanho dele)
	
	ler_intervalo_teclado intervalo;	//inicializando sem usar o new -> nao precisa usar delete[]
	
	int* isinterval = intervalo.esta_no_intervalo(resultado, quantidade);	//criando um array para armazenar os inteiros dentro do intervalo
	//DUVIDA: precisa dar free nesse array? ^^^^
	
	intervalo.print_array_inside_interval(isinterval);
	
	delete[] ler;
	ler = nullptr;
	
	return 0;
}

