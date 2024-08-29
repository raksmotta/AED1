/*
PUC MINAS - AEDs1
Maio/2024

Estudo Dirigido 13

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: exercicios_1311_a_1320_raquelmotta
Versao: 0.0

*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <limits>

using std::cout;
using std::cin;



//>>>>>>>>>> metodo_01 - exercicio 1311 <<<<<<<<<<

class dados{
	
public:
	
	std::string nome;
	std::string telefone;
	std::string telefone2;
	int qtdtel;
	
	dados(){
		
		nome = "name";
		telefone = "0000-0000";
		telefone2 = "0000-0000";
		
	}
	
	dados (std::string name, std::string t1, std::string t2){
		
		nome = name;
		telefone = t1;
		telefone2 = t2;
		
	}
	
	void atribuir_nome (){
		
		cout << "\n\nqual o seu nome? ";
		
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore characters until a newline is removed
		/*
		O código nao estava funcionando antes de incluir isso.
		
		Por exemplo, se você fizer uma leitura de um número inteiro com std::cin >>, o caractere de nova linha que você digita 
		quando pressiona Enter permanece no buffer. Se não for removido, ele pode ser lido imediatamente por uma subsequente chamada 
		a std::getline(), fazendo parecer que std::getline() foi pulado.
		*/
		
		std::getline(cin, nome);
		
	}
	
	void atribuir_telefone (){
		
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
		cout << "\n\nqual o seu telefone? ";
		
		//cin >> telefone; bug!!
		std::getline(cin, telefone);
		
	}
	
	int atribuir_telefone2 (){
		
		int r = 2;
		
		cout << "\n\ndeseja adicionar um segundo telefone? digite 1 para sim e qualquer outro inteiro para nao.\n";
		cin >> r;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Limpa o buffer
		
		if(r == 1){
			
			cout << "\n\nqual o seu segundo telefone? ";
			
			std::getline(cin, telefone2);
			
		}
		
		return r;
		
	}
	
	void editar_telefone2 (){

		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
		if (phones()!=2){
			
			cout << "\n\nERRO. vc nao possui dois telefones registrados" << std::endl;
			
		}else{
			
			cout << "\n\nqual o seu segundo telefone? ";
			std::getline(cin, telefone2);
			
		}
		
	}
	
	void remover_telefone2 (){
		
		if (phones()!=2){
			
			cout << "\n\nERRO. vc nao possui dois telefones registrados" << std::endl;
			
		}else{
			
			telefone2.erase();
			
		}
		
	}
	
	bool testa_is_telefone(){
		
		bool result = is_telefone();
		
		return result;
		
	}
	
	void readFromFile(const std::string & filename) {
		
		std::ifstream arquivo(filename);
		
		if (arquivo) {
			
			std::getline(arquivo, nome);
			std::getline(arquivo, telefone);
			
		} else {
			std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
		}
		
		arquivo.close();
		
	}
	
	void writeToFile(const std::string & filename) {
		
		std::ofstream arquivo(filename);
		
		if (arquivo) {
			
			arquivo << nome << "\n" << telefone << "\n";
			
		} else {
			
			std::cerr << "erro ao abrir o arquivo para escrita" << std::endl;
			
		}
		arquivo.close();
	}
	
	int phones (){
		
		/*
		empty() é um método da classe std::string que retorna true se a string estiver vazia, ou seja, se não contiver nenhum caractere.
		*/
		
		if ((telefone.empty() || telefone == "0000-0000") && (telefone2.empty() || telefone2 == "0000-0000")){
			
			qtdtel = 0;
			
		}else if ((!telefone.empty() || telefone != "0000-0000") && (telefone2.empty() || telefone2 == "0000-0000")){
			
			qtdtel = 1;
			
		}else if ((telefone.empty() || telefone == "0000-0000") && (!telefone2.empty() || telefone2 != "0000-0000")){
			
			qtdtel = 1;
			
		}else{
			
			qtdtel = 2;
			
		}
		
		return qtdtel;
		
	}

	
private:
	
	bool is_telefone (){
		
		bool tel = true;
		
		for(int x = 0; x < telefone.length(); x++){
			
			//Incorrect: "-" is a const char*, not a char
			if(telefone[x] != '-' && !isdigit(telefone[x])){
				
				tel = false;
				break;
				
			}
			
		}
		
		return tel;
		
	}
	
	
};


void metodo_01 (){
	
	cout << "\nmetodo_01\n";
	
	dados* info = new dados;
	
	info -> atribuir_nome();
	
	cout << "\n\nnome digitado: " << info -> nome << std::endl;
	
}



//>>>>>>>>>> metodo_02 - exercicio 1312 <<<<<<<<<<

void metodo_02 (){
	
	cout << "\nmetodo_02\n";
	
	dados* info = new dados;
	
	info -> atribuir_telefone();
	
	cout << "\n\ntelefone digitado: " << info -> telefone << std::endl;
	
}



//>>>>>>>>>> metodo_03 - exercicio 1313 <<<<<<<<<<

void metodo_03 (){
	
	cout << "\nmetodo_03\n";
	
	dados* info = new dados;
	
	info -> atribuir_telefone();
	
	cout << "\n\ntelefone digitado: " << info -> telefone << std::endl;

	bool result = info -> testa_is_telefone();
	
	if (result){
		
		cout << "\n\nEH um telefone valido";
		
	}else{
		
		cout << "\n\nNAO eh um telefone valido";
		
	}
}



//>>>>>>>>>> metodo_04 - exercicio 1314 <<<<<<<<<<

void metodo_04 (){
	
	cout << "\nmetodo_04\n";
	
	dados info;
	
	info.readFromFile("pessoa1.txt");
	
	std::cout << "nome: " << info.nome << "\ntelefone: " << info.telefone << std::endl;
	
}



//>>>>>>>>>> metodo_05 - exercicio 1315 <<<<<<<<<<

void metodo_05 (){
	
	cout << "\nmetodo_05\n";
	
	dados info;
	
	info.atribuir_nome(); 
	
	info.atribuir_telefone();    
	
	info.writeToFile("pessoa2.txt"); 
	
}



//>>>>>>>>>> metodo_06 - exercicio 1316 <<<<<<<<<<

void metodo_06 (){
	
	cout << "\nmetodo_06\n";
	
	dados* info = new dados("Raquel Motta", "2222-2222", "3333-3333");
	
	cout << "\n\nnome: " << info -> nome << std::endl;
	
	cout << "\n\nprimeiro telefone: " << info -> telefone << std::endl;
	
	cout << "\n\nsegundo telefone: " << info -> telefone2 << std::endl;
	
}



//>>>>>>>>>> metodo_07 - exercicio 1317 <<<<<<<<<<

void metodo_07 (){
	
	cout << "\nmetodo_07\n";
	
	dados* info = new dados("Raquel Motta", "2222-2222", "3333-3333");
	
	cout << "\n\nnome: " << info -> nome << std::endl;
	
	cout << "\n\nprimeiro telefone: " << info -> telefone << std::endl;
	
	cout << "\n\nsegundo telefone: " << info -> telefone2 << std::endl;
	
	int n = info->phones();
	
	cout << "\n\nquantidade de telefones associados ao objeto: " << n << std::endl;
	
	cout << "\n-----------\n";
	
	dados info2;
	
	info2.readFromFile("pessoa2.txt");
	
	std::cout << "\n\nnome: " << info2.nome << "\ntelefone: " << info2.telefone << std::endl;
	
	int m = info2.phones();
	
	cout << "\n\nquantidade de telefones associados ao objeto: " << m << std::endl;
	
}



//>>>>>>>>>> metodo_08 - exercicio 1318 <<<<<<<<<<

void metodo_08 (){
	
	cout << "\nmetodo_08\n";
	
	dados info;
	
	info.atribuir_nome(); 	//nao sei pq, mas quando a pessoa digita o nome precisa dar enter DUAS vezes para o programa prosseguir.
							//porem, se eu tiro o cin.ignore() da funcao, o metodo 1 simplesmente nao funciona, passa direto sem
							//esperar pelo input do nome do usuario.
	
	info.atribuir_telefone();
	
	int i = info.atribuir_telefone2();
	
	cout << "\n\nnome: " << info.nome << std::endl;
	
	cout << "\n\nprimeiro telefone: " << info.telefone << std::endl;
	
	if (i == 1){
		
		cout << "\n\nsegundo telefone: " << info.telefone2 << std::endl;
		
	}
	
}



//>>>>>>>>>> metodo_09 - exercicio 1319 <<<<<<<<<<

void metodo_09 (){
	
	cout << "\nmetodo_09\n";
	
	dados info;
	
	info.atribuir_nome();
	
	info.atribuir_telefone();
	
	int i = info.atribuir_telefone2();
	
	cout << "\n\nnome: " << info.nome << std::endl;
	
	cout << "\n\nprimeiro telefone: " << info.telefone << std::endl;
	
	if (i == 1){
		
		cout << "\n\nsegundo telefone: " << info.telefone2 << std::endl;
		
	}
	
	int r = 2;
	
	cout << "\n\ndeseja editar o segundo telefone? digite 1 para sim e qualquer outro inteiro para nao." << std::endl;
	cin >> r;
	
	if (r == 1){
		
		info.editar_telefone2();
		
	}
	
}



//>>>>>>>>>> metodo_10 - exercicio 1320 <<<<<<<<<<

void metodo_10 (){
	
	cout << "\nmetodo_10\n";
	
	dados info;
	
	info.atribuir_nome();
	
	info.atribuir_telefone();
	
	int i = info.atribuir_telefone2();
	
	cout << "\n\nnome: " << info.nome << std::endl;
	
	cout << "\n\nprimeiro telefone: " << info.telefone << std::endl;
	
	if (i == 1){
		
		cout << "\n\nsegundo telefone: " << info.telefone2 << std::endl;
		
	}
	
	int r = 2;
	
	cout << "\n\ndeseja apagar o segundo telefone? digite 1 para sim e qualquer outro inteiro para nao." << std::endl;
	cin >> r;
	
	if (r == 1){
		
		info.remover_telefone2();
		//cout << "\n" << info.telefone2;	PARA TESTAR
	}
	
}



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int main (){
	
	int opcao = 0;
	
	//identificar o programa
	cout << "estudo dirigido 13\n";
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
