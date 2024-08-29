/*
PUC MINAS - AEDs1
Mai/2024

Estudo Dirigido 11

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: ed11_exercicio_1119_raquelmotta
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
	
	
};

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
	
	
	//adicionar a funcao search nessa classe
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
	
	bool search_interval (int* array){
		
		int procurado = 0;
		
		cout << "\npor qual valor vc deseja procurar?  " << endl;
		cin >> procurado;
		
		bool existe = false;
		
		for(int i = 0; i < num; i++){
			
			if (array[i] == procurado){
				
				existe = true;
				
			}
			
		}
		
		if(existe){
			
			cout << "\no valor procurado EXISTE dentro do intervalo" << endl;
			
		}else{
			
			cout << "\no valor procurado NAO existe dentro do intervalo" << endl;
			
		}
		
		return existe;
		
	}
	
	int* scale_interval (int* array){
		
		int constante = 0;
		
		cout << "\npor qual constante vc deseja multiplicar?  " << endl;
		cin >> constante;
		
		int* result = new int[num];
		
		for(int i = 0; i < num; i++){
			
			result[i] = array[i] * constante;
			
		}
		
		return result;
		
	}
	
	void print_array_inside_interval(int* array) {	
		
		//cout << "\n\nnumeros dentro do intervalo: " << endl;
		
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
	
	int quantidade = ler->print_array(resultado);
	
	ler_intervalo_teclado* intervalo = new ler_intervalo_teclado(quantidade);
	
	int* interval = intervalo->esta_entre_pos(resultado, quantidade);
	
	intervalo->print_array_inside_interval(interval);
	
	int* escalados = intervalo->scale_interval(interval);
	
	cout << "\nos numeros multiplicados  pela constante sao = "<<endl;
	
	intervalo->print_array_inside_interval(escalados);
	
	delete[] ler;
	ler = nullptr;
	
	delete[] intervalo;
	intervalo = nullptr;
	
	return 0;
}
