/*
PUC MINAS - AEDs1
Maio/2024

Estudo Dirigido 12

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: exercicios_1214_a_1220_raquelmotta
Versao: 0.0

*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using std::cout;
using std::cin;





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
		
		data = new int* [m];
		
		for (int i = 0; i < m; ++i) {
			
			data[i] = new int[n];
			
		}
		
	}	
	

	my_matrix (const std::string filename){
		
		std::ifstream arquivo; 
		
		arquivo.open(filename); 
		
		if(!arquivo.is_open()){
			
			std::cerr << "\nnao foi possivel abrir o arquivo" << std::endl;
			
		}else{
			
			arquivo >> m;	
			
			data = new int* [m];
			
			int temp = 0;
			int x = 0;
			
			while(arquivo >> temp){
				
				x++;
				
			}
			
			n = x / m;	
			
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
			arquivo >> rows;
			
			for(int i=0; i<m; i++){
				
				for(int j=0; j<n; j++){
					
					arquivo >> data[i][j];
					
				}
				
			}
			
			arquivo.close();
			
			return m;
			
		}
		
		
	}
	
	void matrix_random_int_generate (int lowLim, int upLim){
		
		srand(static_cast<unsigned int>(time(0))); 
		
		for(int i = 0; i < m; ++i){
			
			for(int j=0; j < n; ++j){
				
				data[i][j] = lowLim + rand() % (upLim - lowLim + 1);
				
			}
			
		}
		
	}
	
	void print_matrix(){
		
		for(int i = 0; i < m; ++i){
			
			for(int j=0; j < n; ++j){
				
				cout << data[i][j] << "\t";
				
			}
			
			cout << "\n";
			
		}
		
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
	
	int return_rows (){
		
		return m;
		
	}
	
	int return_cols (){
		
		return n;
		
	}
	
	
};



//>>>>>>>>>> metodo_04 - exercicio 1214 <<<<<<<<<<

//d1 e d2 sao as matrizes
//r1 = qtd de rows de d1	//c1 = qtd de columns de d1
bool matrix_is_equal (int** d1, int r1, int c1, int** d2, int r2, int c2){
	
	if(r1!=r2 || c1!=c2){
		
		return false;	//as matrizes precisam ter o mesmo numero de linhas e colunas
		
	}else{
		
		for(int i=0; i<r1; i++){
			
			for(int j=0; j<c1; j++){
				
				if (d1[i][j]!=d2[i][j]){
					
					return false;
					
				}
				
			}
			
		}
		
	}
	
	return true;
	
}


void metodo_04 (){
	
	cout << "\nmetodo_04\n\n";
	
	cout << "matriz 1:\n";
	
	my_matrix* d1 = new my_matrix("dados2.txt");
	
	d1 -> read_matrix_file("dados2.txt");
	
	d1 -> print_matrix();
	cout << "\n\n";
	
	int r1 = d1->return_rows();
	int c1 = d1->return_cols();
	
	//---
	
	cout << "matriz 2:\n";
	
	my_matrix* d2 = new my_matrix("identidade.txt");
	
	d2 -> read_matrix_file("identidade.txt");
	
	d2 -> print_matrix();
	
	int r2 = d2->return_rows();
	int c2 = d2->return_cols();
	
	//---
	
	bool iguais = matrix_is_equal(d1->data, r1, c1, d2->data, r2, c2);
	
	if(iguais){
		
		cout << "\n\nas matrizes sao iguais";
		
	}else{
		
		cout << "\n\nas matrizes NAO sao iguais";
		
	}
	
	delete[]d1;
	d1 == nullptr;
	
	delete[]d2;
	d2 == nullptr;
}



//>>>>>>>>>> metodo_05 - exercicio 1215 <<<<<<<<<<

int** somar_matrizes (int** d1, int** d2, int rows, int cols){
	
	//alocando dinamicamente memoria de matriz para receber o resultado
	int** resultado;
	
	resultado = new int* [rows];
	
	for (int i = 0; i < rows; i++){
		
		resultado[i] = new int [cols];
		
	}
	
	for (int i = 0; i < rows; i++){
		
		for (int j = 0; j < cols; j++){
			
			resultado[i][j] = d1[i][j] + d2[i][j];
			
		}
		
	}
	
	return resultado;
	
}


void imprimir_matriz(int** matriz, int rows, int cols){
	
	for(int i = 0; i < rows; ++i){
		
		for(int j=0; j < cols; ++j){
			
			cout << matriz[i][j] << "\t";
			
		}
		
		cout << "\n";
		
	}
	
}


void metodo_05 (){
	
	cout << "\nmetodo_05\n";
	
	cout << "matriz 1:\n";
	
	my_matrix* d1 = new my_matrix("dados2.txt");
	
	d1 -> read_matrix_file("dados2.txt");
	
	d1 -> print_matrix();
	cout << "\n\n";
	
	int r1 = d1->return_rows();
	int c1 = d1->return_cols();
	
	//---
	
	cout << "matriz 2:\n";
	
	my_matrix* d2 = new my_matrix("identidade.txt");
	
	d2 -> read_matrix_file("identidade.txt");
	
	d2 -> print_matrix();
	
	int r2 = d2->return_rows();
	int c2 = d2->return_cols();
	
	//---
	
	if(r1!=r2 || c1!=c2){
		
		cout << "\n\nnao eh possivel somar as matrizes pois elas possuem dimensoes diferentes";
		
	}else{
		
		int** resultado = somar_matrizes(d1->data, d2->data, r1, c1);
		
		cout << "\n\nsoma das matrizes:\n";
		imprimir_matriz(resultado, r1, c1);
		
	}
	
	delete[]d1;
	d1 == nullptr;
	
	delete[]d2;
	d2 == nullptr;
	
}



//>>>>>>>>>> metodo_06 - exercicio 1216 <<<<<<<<<<

int** operar_2linhas_soma (int** matriz, int rows, int cols, int c){
	
	for(int i = 0; i < 1; ++i){
		
		for(int j=0; j < cols; ++j){
			
			matriz[i][j] = (matriz[i][j] + matriz[i+1][j]) * c;
			
		}
		
	}
	
	return matriz;
	
}


void metodo_06 (){
	
	cout << "\nmetodo_06\n";
	
	cout << "matriz 1:\n";
	
	my_matrix* d1 = new my_matrix("dados.txt");
	
	d1 -> read_matrix_file("dados.txt");
	
	d1 -> print_matrix();
	cout << "\n\n";
	
	int r1 = d1->return_rows();
	int c1 = d1->return_cols();
	
	int c = 0;
	
	cout << "\n\npor qual constante vc deseja multiplicar a soma das 2 primeiras linhas? ";
	cin >> c;
	
	int** resultado = operar_2linhas_soma(d1->data, r1, c1, c);
	
	cout << "\n\nresultado de substituir os valores da primeira linha pela soma deles mesmos com os da segunda linha multiplicados pela constante:\n";
	imprimir_matriz(resultado, r1, c1);
	
	delete[]d1;
	d1 == nullptr;
	
}



//>>>>>>>>>> metodo_07 - exercicio 1217 <<<<<<<<<<

int** operar_2linhas_diferenca (int** matriz, int rows, int cols, int c){
	
	for(int i = 0; i < 1; ++i){
		
		for(int j=0; j < cols; ++j){
			
			matriz[i][j] = (matriz[i][j] - matriz[i+1][j]) * c;
			
		}
		
	}
	
	return matriz;
	
}


void metodo_07 (){
	
	cout << "\nmetodo_07\n";
	
	cout << "matriz 1:\n";
	
	my_matrix* d1 = new my_matrix("dados.txt");
	
	d1 -> read_matrix_file("dados.txt");
	
	d1 -> print_matrix();
	cout << "\n\n";
	
	int r1 = d1->return_rows();
	int c1 = d1->return_cols();
	
	int c = 0;
	
	cout << "\n\npor qual constante vc deseja multiplicar a diferenca entre as 2 primeiras linhas? ";
	cin >> c;
	
	int** resultado = operar_2linhas_diferenca(d1->data, r1, c1, c);
	
	cout << "\n\nresultado de substituir os valores da primeira linha pela diferenca deles mesmos em relacao aos da segunda linha multiplicados pela constante:\n";
	imprimir_matriz(resultado, r1, c1);
	
	delete[]d1;
	d1 == nullptr;
	
}



//>>>>>>>>>> metodo_08 - exercicio 1218 <<<<<<<<<<

int search_rows (int** matriz, int rows, int cols, int procurado){
	
	for(int i = 0; i < rows; ++i){
		
		for(int j=0; j < cols; ++j){
			
			if(matriz[i][j] == procurado){
				
				return i;
				
			}
			
		}
		
	}
	
	return -1;
	
}


void metodo_08 (){
	
	cout << "\nmetodo_08\n";
	
	cout << "matriz 1:\n";
	
	my_matrix* d1 = new my_matrix("dados.txt");
	
	d1 -> read_matrix_file("dados.txt");
	
	d1 -> print_matrix();
	cout << "\n\n";
	
	int r1 = d1->return_rows();
	int c1 = d1->return_cols();
	
	int search = 0;
	
	cout << "\n\npor qual valor vc deseja procurar? ";
	cin >> search;
	
	int linha = search_rows(d1->data, r1, c1, search);
	
	if(linha == -1){
		
		cout << "\n\no valor procurado nao existe na matriz";
		
	}else{
		
		cout << "\n\no valor procurado esta na linha: " << linha;
		
	}
	
	delete[]d1;
	d1 == nullptr;
	
}



//>>>>>>>>>> metodo_09 - exercicio 1219 <<<<<<<<<<

int search_cols (int** matriz, int rows, int cols, int procurado){
	
	for(int i = 0; i < rows; ++i){
		
		for(int j=0; j < cols; ++j){
			
			if(matriz[i][j] == procurado){
				
				return j;
				
			}
			
		}
		
	}
	
	return -1;
	
}


void metodo_09 (){
	
	cout << "\nmetodo_09\n";
	
	cout << "matriz 1:\n";
	
	my_matrix* d1 = new my_matrix("dados.txt");
	
	d1 -> read_matrix_file("dados.txt");
	
	d1 -> print_matrix();
	cout << "\n\n";
	
	int r1 = d1->return_rows();
	int c1 = d1->return_cols();
	
	int search = 0;
	
	cout << "\n\npor qual valor vc deseja procurar? ";
	cin >> search;
	
	int col = search_cols(d1->data, r1, c1, search);
	
	if(col == -1){
		
		cout << "\n\no valor procurado nao existe na matriz";
		
	}else{
		
		cout << "\n\no valor procurado esta na coluna: " << col;
		
	}
	
	delete[]d1;
	d1 == nullptr;
	
}



//>>>>>>>>>> metodo_10 - exercicio 1220 <<<<<<<<<<

int** transpose (int** matriz, int rows, int cols){
	
	int m = cols;
	int n = rows;
	
	//alocando a matriz transposta com as dimensoes inversas da matriz original
	int** transposta = new int* [m];
	
	for(int i = 0; i < m; i++){
		
		transposta[i] = new int [n];
		
	}
	
	for(int i = 0; i < m; i++){
		
		for(int j = 0; j < n; j++){
			
			transposta[i][j] = matriz[j][i];
			
		}
		
	}
	
	return transposta;
	
}


void metodo_10 (){
	
	cout << "\nmetodo_10\n";
	
	cout << "matriz 1:\n";
	
	my_matrix* d1 = new my_matrix("dados3.txt");
	
	d1 -> read_matrix_file("dados3.txt");
	
	d1 -> print_matrix();
	cout << "\n\n";
	
	int r1 = d1->return_rows();
	int c1 = d1->return_cols();
	
	int** resultado = transpose(d1->data, r1, c1);
	
	cout << "\n\nmatriz transposta:\n";
	
	imprimir_matriz(resultado, c1, r1);	//dimensoes opostas
	
	delete[]d1;
	d1 == nullptr;
	
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

//>>>>>>>> NOTAS E COMENTÁRIOS

/*
Sei que o ideal é fazer todos os métodos num arquivo só.
Entretanto, separei em dois programas pois queria organizar melhor minha classe para atender melhor as demandas dos exercícios sem perder
registro do que tinha feito anteriormente e precisar refazer completamente as questões anteriores.
*/
