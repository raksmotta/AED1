/*
PUC MINAS - AEDs1
Mai/2024

Estudo Dirigido 11

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: ed11_exercicio_1115_raquelmotta
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


//incluir mais um construtor, que agora receberá um parâmetro
//incluir funcao para checar quais numeros estao em um intervalo de POSICOES
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
	
	ler_intervalo_teclado(int max){		//max é a qtd de inteiros no array a ser checado. a posicao final não pode ser maior que o tamamho do array.
		
		cout<<"\ninsira a posicao inicial do intervalo: "<<endl;
		cin >> lower_limit;
		
		cout<<"\ninsira a posicao final do intervalo: "<<endl;
		cin >> upper_limit;
		
		while (upper_limit<=lower_limit || max-1 < upper_limit){
			
			cout<<"\nvalores invalidos. tente novamente."<<endl;
			
			cout<<"\ninsira a posicao inicial do intervalo: "<<endl;
			cin >> lower_limit;
			
			cout<<"\ninsira a posicao inicial do intervalo: "<<endl;
			cin >> upper_limit;
			
		}
		
	}
	
	int* esta_no_intervalo (int* array, int n){		//n é o tamanho do array recebido. retorna array com valores que estao dentro do intervalo
		
		for(int i=0; i < n; i++) {
			
			if(lower_limit<=array[i] && array[i]<=upper_limit){
				
				num = num+1; //descobrindo o tamanho do array que vai guardar o resultado
				
			}
			
		}  
		
		int* result = new int[num];
		
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
	
	int* esta_entre_pos(int* array, int n){	//n é o tamanho do array recebido. retorna array com valores que estao dentro do intervalo
		
		num = upper_limit - lower_limit + 1; //qtd de inteiros que o array que guarda o resultado terá 
		
		int* result = new int[num];
		
		int count = 0;
		
		for(int i = lower_limit; i <= upper_limit; i++){
			
			result[count] = array[i];
			
			count ++;
			
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
	
	ler_intervalo_teclado* intervalo = new ler_intervalo_teclado(quantidade);	//passando um parametro para inicializar com o construtor das posicoes
	
	int* isinterval = intervalo->esta_entre_pos(resultado, quantidade);	//criando um array para armazenar os inteiros dentro do intervalo
	
	intervalo->print_array_inside_interval(isinterval);
	
	delete[] ler;
	ler = nullptr;
	
	delete[] intervalo;
	intervalo = nullptr;
	
	return 0;
}













