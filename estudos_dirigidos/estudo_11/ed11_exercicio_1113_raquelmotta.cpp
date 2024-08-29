/*
PUC MINAS - AEDs1
Mai/2024

Estudo Dirigido 11

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: ed11_exercicio_1113_raquelmotta
Versao: 0.0

*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//usando exatamente a mesma classe do exercicio anterior
class read_array_file{
	
public:
	
	string fname;	//nome do arquivo
	vector<int> numbers;	//array onde serao guardados os numeros lidos do arquivo
	
	read_array_file(){
		
		int check = read_file();
		
	}
	
	
	int read_file(){
		
		cout << "nome do arquivo:" << endl;
		cin >> fname;
		
		ifstream inputFile; //criando um objeto ifstream
		
		inputFile.open(fname);
		
		if (!inputFile.is_open()) {
			cerr << "\nnao foi possivel abrir o arquivo" << endl;
			return 1; // Return error code
		}
		
		
		int number;
		
		while (inputFile >> number) {
			numbers.push_back(number); // Add each number to the vector
		}		
		
		inputFile.close();
		
		return 0;
	}
	
	
	void print_array(){
		
		// Output the numbers read
		cout << "\nos numeros lidos do arquivo sao:" << endl;
		
		for (int num : numbers) {
			cout << num << " ";
		}
		cout << endl;
		
	}
	
	
};

int menor_impar (vector<int> numbers){
	
	int menor = 101; //posso inicializar assim pois sei que meu intervalo vai no máximo até 100
	
	for (int number : numbers) {
		
		if (number%2!=0 && number<menor){
			
			menor = number;
			
		}
		
	}
	
	return menor;
}


int main (){
	
	read_array_file ler; 
	
	ler.print_array(); 
	
	int resultado = menor_impar(ler.numbers);
	
	cout << "\no menor numero impar eh: " << resultado << endl;
	
	return 0;
	
}
