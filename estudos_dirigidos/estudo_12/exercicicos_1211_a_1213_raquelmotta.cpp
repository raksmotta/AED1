/*
PUC MINAS - AEDs1
Maio/2024

Estudo Dirigido 12

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: exercicios_1211_a_1213_raquelmotta
Versao: 0.0

*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <ctime>

using std::cout;
using std::cin;



//>>>>>>>>>> metodo_01 - exercicio 1211 <<<<<<<<<<

class my_matrix{
	
public:
	
	int** data = nullptr;
	int m = 0;//-------ROWS
	int n = 0;//-------COLS
	
	//construtor 1
	my_matrix(){
		
		do{
			
			cout << "\nnumber of rows = ";
			cin >> m;
			
			cout << "\nnumber of columns = ";
			cin >> n;
			
		}while (m<=0 || n<=0);
		
		//definindo o tamanho da matriz
		
		data = new int* [m];
		//This line allocates memory for an array of int* pointers, each of which will later point to an array of integers. 
		//The array has m elements, where m is the number of rows in your matrix.
		
		for (int i = 0; i < m; ++i) {
			
			data[i] = new int[n];
			
		}
		//For each row i, allocate an array of n integers. n is the number of columns. Now, data[i] points to the start of an array of n integers. 
		//By the end of this loop, data has become a fully allocated 2D array with m rows and n columns.
	}
	
	
	//construtor 2 (ler TAMANHO de matriz de arquivo e alocar matriz dinamicamente)
	my_matrix (const std::string filename){
		
		std::ifstream arquivo; //criando um objeto ifstream para abrir o arquivo de nome dado
		
		arquivo.open(filename); //chamando a funcao open do objeto arquivo e passando o parametro filename
		
		if(!arquivo.is_open()){
			
			std::cerr << "\nnao foi possivel abrir o arquivo" << std::endl;
			
		}else{
			
			arquivo >> m;	//guardando em m o número de rows, que está na primeira linha do arquivo
			
			data = new int* [m];	//criando um ponteiro de ponteiros
			
			int temp = 0;
			int x = 0;
			
			while(arquivo >> temp){
				
				x++;	//numero total de elementos na matriz
				
			}
			
			n = x / m;	//o numero de colunas é o número total de elementos dividido pelo número de linhas
			
			for (int i = 0; i < m; ++i) {
				
				data[i] = new int[n];
				
			}
			
			cout << "m = " << m << std::endl;
			cout << "n = " << n << std::endl;
			
		}
		
		arquivo.close();
		
	}
	
	int read_matrix_file (const std::string filename){
		
		std::ifstream arquivo;
		
		arquivo.open(filename);
		
		if(!arquivo.is_open()){
			
			std::cerr << "\nnao foi possivel abrir o arquivo" << std::endl;
			return -1;
			
		}else{
			
			int rows;
			arquivo >> rows;	//ler a primeira linha que contém o numero de linhas
			
			for(int i=0; i<m; i++){
				
				for(int j=0; j<n; j++){
					
					arquivo >> data[i][j];
					
				}
				
			}
			
			arquivo.close();
			
			return m;
			
		}
		
		
	}
	
	//preencher a matriz com valores random
	void matrix_random_int_generate (int lowLim, int upLim){
		
		srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
		
		for(int i = 0; i < m; ++i){
			
			for(int j=0; j < n; ++j){
				
				data[i][j] = lowLim + rand() % (upLim - lowLim + 1);
				
			}
			
		}
		
	}
	
	int print_matrix(){
		
		for(int i = 0; i < m; ++i){
			
			for(int j=0; j < n; ++j){
				
				cout << data[i][j] << "\t";
				
			}
			
			cout << "\n";
			
		}
		
		return n;
		
	}
	
	//salvar matriz em arquivo
	int matrix_print_file (const std::string filename){
		
		std::ofstream arquivo(filename);
		
		if(!arquivo){
			
			std::cerr << "\nnao foi possivel abrir o arquivo" << std::endl;
			return -1; //retorna valor para indicar erro
			
		}else{
			
			arquivo << m << std::endl;	//imprimindo a quantidade de ROWS na primeira linha do arquivo
			
			//imprimir cada elemento, um por linha
			for(int i=0; i < m; ++i){
				
				for(int j=0; j < n; ++j){
					
					arquivo << data[i][j] << std::endl;
					
				}
				
			}
			
			arquivo.close();
			
			return 0;
			
		}
		
	}
	/*
	The const qualifier means that the function cannot modify the string object referred to by filename. 
	This is a way to ensure that the function can read from the filename variable without risking alterations to its content.
	
	Inclusive, como não quero alterar o valor da string dentro da função, posso passar o parâmetro SEM &. Dessa maneira, será feita uma cópia da string.
	*/
	
	void escalar_matriz (int c){
		
		for(int i=0; i < m; ++i){
			
			for(int j=0; j < n; ++j){
				
				data[i][j] = data[i][j] * c;
				
			}
			
		}
		
	}
	
	
	bool is_identity(){
		
		if(m!=n){	//a matriz precisa ser quadrada para ser identidade
			
			return false;
			
		}else {
			
			for(int i = 0; i<m; i++){
				
				for(int j = 0; j<n; j++){
					
					if(j==i){	//checando os elementos da diagonal principa;, que devem todos ser iguais a 1
						
						if(data[i][j]!=1){
							
							return false;
							
						}
						
					}else if(data[i][j]!=0){	//todos os elementos fora da diag. principal devem ser 0
						
						return false;
						
					}
					
				}		
				
			}
			
			
		}
		
		return true;	//se passar em todos os testes, retorna true
		
	}
	
	
};


void metodo_01 (){
	
	cout << "\nmetodo_01\n";
	
	my_matrix* matriz = new my_matrix();
	
	matriz->matrix_random_int_generate(0, 100);
	
	cout << "\n\nmatriz gerada:\n" << std::endl;
	
	int rows = matriz->print_matrix();
	
	rows = matriz->matrix_print_file("dados.txt");
	
	delete[] matriz;
	matriz == nullptr;
	
}



//>>>>>>>>>> metodo_02 - exercicio 1212 <<<<<<<<<<

void metodo_02 (){
	
	cout << "\nmetodo_02\n";
	
	//adicionei construtor que recebe nome de arquivo como parâmetro na classe para ler TAMANHO de matriz em arquivo cuja primeira linha é o número de ROWS 
	my_matrix* matriz = new my_matrix("dados.txt");
	
	//vou precisar de abrir o arquivo 2 vezes: a primeira apenas para descobrir o tamanho da matriz e a segunda para armazenar os dados em uma matriz já com o tamanho certo
	int rows = matriz->read_matrix_file("dados.txt");
	
	cout << "\n\nmatriz lida do arquivo:\n" << std::endl;
	rows = (*matriz).print_matrix();
	
	int c = 0;
	
	//adicionei função escalar_matrix na classe
	cout << "\n\npor qual constante vc deseja multiplicar?  ";
	cin >> c;
	
	matriz->escalar_matriz(c);
	cout << "\n\nmatriz escalada:\n";
	
	rows = matriz->print_matrix();
	
	delete[] matriz;
	matriz == nullptr;
	
}



//>>>>>>>>>> metodo_03 - exercicio 1213 <<<<<<<<<<

void metodo_03 (){
	
	cout << "\nmetodo_03\n";
	
	//testar com os arquivos "dados.txt", "identidade.txt" e "dados1.txt"
	
	my_matrix* matriz = new my_matrix("identidade.txt");
	int rows = matriz->read_matrix_file("identidade.txt");
	
	cout << "\n\nmatriz lida do arquivo:\n" << std::endl;
	rows = (*matriz).print_matrix();
	
	//adicionei a funcao is_identity na classe
	bool id = matriz->is_identity();
	
	if(id){
		
		cout << "\n\nmatriz identidade";
		
	}else{
		
		cout << "\n\nmatriz NAO eh identidade";
		
	}
	
	delete[] matriz;
	matriz == nullptr;
	
}



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int main (){
	
	int opcao = 0;
	
	//identificar o programa
	cout << "estudo dirigido 12\n";
	cout << "autor: raquel de parde motta - matricula: 854017";
	
	do{
		//mostrar as opcoes
		cout << "\n\n--------------------------------------------------------";
		cout << "\n0 - encerrar";
		cout << "\n1 - metodo_01";
		cout << "\n2 - metodo_02";
		cout << "\n3 - metodo_03";
		
		
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
		default:
			cout << "erro. opcao invalida.";
			break;
		}
		
	}while(opcao !=0);
	
	return 0;
}

