/*
PUC MINAS - AEDs1
Junho/2024

Estudo Dirigido 16

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: exercicios_1611_a_1620_raquelmotta
Versao: 0.0

*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using std::cout;
using std::cin;


class kelarray{
	
public:
	
	int* arr1;  //array original
	int qtd = 0;	//tamanho do array
	int value;
	
	
	//construtor para ler array do teclado e guardar em um array dinamicamente alocado
	kelarray(){
		
		while (qtd <= 0){
			
			cout << "\nqual a quantidade de elementos do array? (entre com um valor inteiro positivo)\n";
			cin >> qtd;
			
		}
		
		//dinamically allocate memory for the array
		arr1 = new int [qtd];
		
		for (int i = 0; i < qtd; i++){
			
			cout << "\ninteiro na posicao " << i << ": ";
			
			cin >> arr1[i];
		}
	}
	
	//construtor para apenas inicializar array com certa quantidade, mas preencher todas as posicoes com 0
	kelarray(int tam){
		
		qtd = tam;
		
		arr1 = new int [qtd];
		
		for (int i = 0; i < qtd; i++){
			
			arr1[i] = 0;
			
		}
		
	}
	
	int* add_end_array (){
		
		cout << "\nqual valor inteiro vc deseja acrescentar ao final do array? ";
		
		cin >> value;
		
		int* destino = new int [qtd+1];
		
		for (int i = 0; i < qtd; i++) {
			
			destino[i] = arr1[i];
			
		}
		
		destino[qtd] = value;
		
		return destino;
	}
	
	int* remove_end_array (){
		
		cout << "\no valor na ultima posicao que sera removido eh: " << arr1[qtd-1];
		
		int* destino = new int [qtd-1];
		
		for (int i = 0; i < qtd-1; i++) {
			
			destino[i] = arr1[i];
			
		}
		
		return destino;
	}
	
	int* add_start_array(){
		
		cout << "\nqual valor inteiro vc deseja acrescentar ao inicio do array? ";
		
		cin >> value;
		
		int* destino = new int [qtd+1];
		
		destino[0] = value;
		
		int x = 0;
		
		for (int i = 1; i < qtd+1; i++) {
			
			destino[i] = arr1[x];
			
			x++;
			
		}
		
		return destino;	
	}
	
	int* remove_start_array(){
		
		cout << "\no valor na primeira posicao que sera removido eh: " << arr1[0];
		
		int* destino = new int [qtd-1];
		
		int x = 1;
		
		for (int i = 0; i < qtd-1; i++) {
			
			destino[i] = arr1[x];
			x++;
			
		}
		
		return destino;
	}
	
	int* add_mid_array(){
		
		cout << "\nqual valor inteiro vc deseja acrescentar ao meio (aproximado) do array? ";
		
		cin >> value;
		
		int* destino = new int [qtd+1];
		
		int x = 0;
		
		int middle = 0;
		
		if(qtd%2 == 0){
			
			middle = qtd/2;
			
			for (int i = 0; i < qtd+1; i++) {
				
				if(i == middle){
					
					destino[i] = value;
					
				}else{
					
					destino[i] = arr1[x];
					x++;
					
				}

				
			}
			
		}else{
			
			middle = (int)qtd/2; 
			
			for (int i = 0; i < qtd+1; i++) {
				
				if(i == middle){
					
					destino[i] = value;
					
				}else{
					
					destino[i] = arr1[x];
					x++;
					
				}
				
				
			}
			
		}
		
		return destino;
		
	}
	
	int* remove_mid_array(){
		
		int middle = 0;
		int x = 0;
		int y = 0;
		
		int* destino = new int [qtd-1];
		
		/*
		Access the Element: The value at destino[y] is accessed or assigned. At this point, y points to the current index where you want to place the next value (starting from 0).
		
		Post-Increment: After the element access or assignment, the y variable is incremented by 1. This means y is ready to point to the next index for any subsequent operations.
		*/
		
		if(qtd%2 == 0){
			
			middle = qtd/2;
			
			while(x < qtd){
				
				if(x != middle){
					
					destino[y] = arr1[x];
					y++;
					x++;
					
				}else{
					
					x++;
					
				}
				
			}
			
			
		}
		else{
			
			middle = (int)qtd/2; 
			
			while(x < qtd){
				
				if(x != middle){
					
					destino[y] = arr1[x];
					y++;
					x++;
					
				}else{
					
					x++;
					
				}
				
			}
			
		}
		
		cout << "\no valor na posicao do meio (aproximada) que sera removido eh: " << arr1[middle];
		
		return destino;
	}
	
	
	~kelarray(){
		
		delete[] arr1;
		
	}
	
};


void print_array (int* array, int qtd){
	
	for(int x = 0; x<qtd; x++){
		
		cout << array[x] << " ";
		
	}
	
}


//>>>>>>>>>> metodo_01 - exercicio 1611 <<<<<<<<<<

void metodo_01 (){
	
	cout << "\nmetodo_01\n";
	
	kelarray arr;
	
	int* destino = arr.add_end_array();
	
	cout << "\narray modificado: ";
	
	print_array(destino, arr.qtd+1);
	
}



//>>>>>>>>>> metodo_02 - exercicio 1612 <<<<<<<<<<

void metodo_02 (){
	
	cout << "\nmetodo_02\n";
	
	kelarray arr;
	
	int* destino = arr.remove_end_array();
	
	cout << "\narray modificado: ";
	
	print_array(destino, arr.qtd-1); 
	
}



//>>>>>>>>>> metodo_03 - exercicio 1613 <<<<<<<<<<

void metodo_03 (){
	
	cout << "\nmetodo_03\n";
	
	kelarray arr;
	
	int* destino = arr.add_start_array();
	
	cout << "\narray modificado: ";
	
	print_array(destino, arr.qtd+1);
	
}



//>>>>>>>>>> metodo_04 - exercicio 1614 <<<<<<<<<<

void metodo_04 (){
	
	cout << "\nmetodo_04\n";
	
	kelarray arr;
	
	int* destino = arr.remove_start_array();
	
	cout << "\narray modificado: ";
	
	print_array(destino, arr.qtd-1); 
	
}



//>>>>>>>>>> metodo_05 - exercicio 1615 <<<<<<<<<<

void metodo_05 (){
	
	cout << "\nmetodo_05\n";
	
	kelarray arr;
	
	int* destino = arr.add_mid_array();
	
	cout << "\narray modificado: ";
	
	print_array(destino, arr.qtd+1);
	
}



//>>>>>>>>>> metodo_06 - exercicio 1616 <<<<<<<<<<

void metodo_06 (){
	
	cout << "\nmetodo_06\n";
	
	kelarray arr;
	
	int* destino = arr.remove_mid_array();
	
	cout << "\narray modificado: ";
	
	print_array(destino, arr.qtd-1); 
	
}



//>>>>>>>>>> metodo_07 - exercicio 1617 <<<<<<<<<<

int compare_arrays (kelarray* p, kelarray* q){
	
	if(p->qtd != q->qtd){
		
		return -1;
		
	}else{
		
		for(int i = 0; i<p->qtd; i++){
			
			if(p->arr1[i] != q->arr1[i]){
				
				return -1;
				
			}
			
		}
		
		return 0;
	}
	
}

void metodo_07 (){
	
	cout << "\nmetodo_07\n";
	
	cout << "\n------array1------";
	kelarray a1;
	
	cout << "\n------array2------";
	kelarray a2;
	
	int result = compare_arrays(&a1, &a2);
	
	if(result == 0){
		
		cout << "\n\nos arrays SAO iguais";
		
	}else{
		
		cout << "\n\nos arrays NAO sao iguais";
		
	}
	
}



//>>>>>>>>>> metodo_08 - exercicio 1618 <<<<<<<<<<

kelarray* unite_arrays (kelarray* p, kelarray* q){
	
	int tam = p->qtd + q->qtd;
	
	kelarray* uniao = new kelarray(tam);
	
	//print_array(uniao->arr1, tam);
	
	for(int a = 0; a < p->qtd; a++){
		
		uniao->arr1[a] = p->arr1[a];
		
	}
	
	int b = p->qtd;
	int c = 0;
	
	while (c < q->qtd){
		
		uniao->arr1[b] = q->arr1[c];
		b++;
		c++;
		
	}

	return uniao;
}

void metodo_08 (){
	
	cout << "\nmetodo_08\n";
	
	cout << "\n------array1------";
	kelarray a1;
	
	cout << "\n------array2------";
	kelarray a2;
	
	kelarray* uniao = unite_arrays(&a1, &a2);
	
	cout << "\n\nuniao dos dois arrays: ";
	
	print_array(uniao->arr1, uniao->qtd);
	
}



//>>>>>>>>>> metodo_09 - exercicio 1619 <<<<<<<<<<

kelarray* seek_value (kelarray* p, int v){
	
	int pos = 0;
	int counter = 0;
	int x = 0;
	
	while (x < p->qtd){
		
		if(p->arr1[x] == v && counter == 0){	//apenas atribui o x a pos na primeira ocorrencia do valor
			
			pos = x;
			counter = 1;
			
		}
		
		x++;
		
	}
	
	if(counter == 0){
		
		return nullptr;
		
	}else{
		
		cout << "\n\na primeira ocorrencia do valor " << v << " no arranjo eh na posicao " << pos;
		
		int tam = p->qtd - pos;
		
		kelarray* destino = new kelarray(tam);
		
		int h = 0;
		
		for(int i = pos; h<tam; i++){
			
			destino->arr1[h] = p->arr1[i];
			h++;
		}
		
		return destino;
		
	}
	
}

void metodo_09 (){
	
	cout << "\nmetodo_09\n";
	
	kelarray p;
	
	kelarray* destino = seek_value(&p, 3);
	
	if (destino == nullptr){
		
		cout << "\no valor procurado nao existe no array";
		
	}else{
		
		if(destino->qtd > 1){
			
			cout << "\n\narray A PARTIR da primeira ocorrencia do valor: ";
			
			print_array(destino->arr1, destino->qtd);
			
		}
		
	}	
	
}



//>>>>>>>>>> metodo_10 - exercicio 1620 <<<<<<<<<<

kelarray* separar_subsequencia (kelarray* sequencia){
	
	int start = 0;
	int size = 0;
	
	cout << "\n\nqual a posicao de inicio da subsequencia? ";
	cin >> start;
	
	if(start > sequencia->qtd){
		
		cout << "\nERRO. posicao de inicio excede o tamanho do array";
		return nullptr;
		
	}
	
	cout << "\nqual o tamanho (qtd de inteiros) da subsequencia? ";
	cin >> size;
	
	if (size > sequencia->qtd - start){
		
		cout << "\nERRO. tamanho da sequencia excede o tamanho do array";
		return nullptr;
		
	}
	
	int x = 0;
	int y = start;
	
	kelarray* destino = new kelarray(size);
	
	while (x < size){
		
		destino->arr1[x] = sequencia->arr1[y];
		
		y++;
		x++;
	}
	
	return destino;
	
}

void metodo_10 (){
	
	cout << "\nmetodo_10\n";
	
	kelarray p;
	
	kelarray* destino = separar_subsequencia(&p);
	
	if (destino == nullptr){
		
		cout << "\ntente novamente. inpute valores validos.";
		
	}else{
		
		cout << "\nsubsequencia obtida:  ";
		
		print_array(destino->arr1, destino->qtd);
		
	}
	
}



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int main (){
	
	int opcao = 0;
	
	//identificar o programa
	cout << "estudo dirigido 16\n";
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
