/*
PUC MINAS - AEDs1
Mai/2024

Estudo Dirigido 11

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: ed11_exercicio_1112_raquelmotta
Versao: 0.0

*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

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
		/*
		In C++, the >> operator is overloaded for input stream objects like ifstream (input file stream) and cin (standard input). This operator reads data from the stream into a 
		variable. When used within a while loop, the stream extraction operation serves a dual purpose:
		
		Reading Data: It attempts to read the next item from the stream and store it in the variable (number in this case).
		
		Evaluating Stream State: It checks the state of the stream after attempting the read operation.
		The condition in the while loop evaluates to true as long as the stream is in a good state. The stream goes into a bad state (making the condition false) if:
		- End of file (EOF) is reached.
		- A read operation fails (e.g., trying to read an integer but encountering a non-numeric character).
		- Any other error occurs with the stream.
		*/		
		
		inputFile.close(); // Close the file
		
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

int maior_par (vector<int> numbers){
	
	int maior = -1; //posso inicializar assim pois sei que só tem números positivos no meu arquivo
	
	for (int number : numbers) {
		
		if (number%2==0 && number>maior){
			
			maior = number;
			
		}
		
	}
	
	return maior;
}

int main (){
	
	read_array_file* ler = new read_array_file; //ou poderia ser só read_array_file ler;
	
	ler->print_array(); //se usar sem o new, pode ser apenas ler.print_array; e a instância é deletada, o compilador limpa a memória para mim
	
	int resultado = maior_par(ler->numbers);
	
	cout << "\no maior numero par eh: " << resultado << endl;
	
	delete ler;
	
	return 0;
}

//new e malloc permitem maior controle sobre o gerenciamento da memória do programa. se não usar, tem + conforto e - poder de gestão
