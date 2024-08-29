/*
PUC MINAS - AEDs1
Abr/2024

Estudo Dirigido 08

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: exercicios_0811_a_0820_raquelmotta
Versao: 0.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <io.h>
#include <time.h>

//>>>>>>>>>> method_01 - programa 0811 <<<<<<<<<<

void read_array_keyboard (int array[], int size) {
	
	printf("\n\nentre com %d elementos (inteiros):\n", size);
	
	for (int i = 0; i < size; i++) {
		
		printf("elemento %d: ", i + 1);
		
		scanf("%d", &array[i]); getchar();
		
	}
	
}


void print_array(int arr[], int size) {
	
	printf("[");
	
	for (int i = 0; i < size; i++) {
		
		printf("%d", arr[i]);
		
		if (i < size - 1) {
			printf(", ");
		}
		
	}
	
	printf("]\n");
}


bool is_all_positive_even (int n, int array[]){
	
	bool result = true;
	int x = 0;
	
	while(x<n && result){
		
		//testar valor
		result = result && (array[x]%2 == 0) && (array[x]>0);
		
		x++;
		
	}
	
	return(result);
	
}


void method_01 (void){
	
	int n1 = 0;
	int n2 = 0;
	//int a1[] = {-4, -3, -2, -1, 0, 10, 1, 2, 3, 4, 100};
	//int a2[] = {2, 4, 6, 8, 800};
	bool result1 = true;
	bool result2 = true;
	
	//identificar
	printf("\nmethod_01 - programa 0811");
	
	//n1 = (sizeof(a1) / sizeof(int));
	//n2 = (sizeof(a2) / sizeof(int));
	//the preferred divisor is sizeof(a[0]) or the equivalent sizeof(*a), the size of the first element of the array.
	
	printf("\n\nqual o tamanho do array 1?  ");
	scanf("%d", &n1); getchar();
	
	int a1[n1];

	printf("\nqual o tamanho do array 2?  ");
	scanf("%d", &n2); getchar();
	
	int a2[n2];
	
	if(n1<=0 || n2<=0){
		
		printf("%s\n", "ERRO. valores invalidos. ambos devem ser positivos e maiores que 0.");
		
	}else{
		
		read_array_keyboard(a1, n1);
		
		read_array_keyboard(a2, n2);
		
		printf("\n\n\na1 = ");
		print_array(a1, n1);
		
		//printf("\ntamanho do a1 = %d", n1);
		
		printf("\n\n\na2 = ");
		print_array(a2, n2);
		
		//printf("\ntamanho do a2 = %d", n2);
		
		result1 = is_all_positive_even(n1, a1);
		
		result2 = is_all_positive_even(n2, a2);
		
		printf("\n");
		
		if(result1){
			
			printf("\n\ntodos os elementos de a1 SAO positivos e pares");
			
		}else{
			
			printf("\n\nNEM todos os elementos de a1 sao positivos e pares");
			
		}
		
		if(result2){
			
			printf("\n\ntodos os elementos de a2 SAO positivos e pares");
			
		}else{
			
			printf("\n\nNEM todos os elementos de a2 sao positivos e pares");
			
		}
		
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}
/* when you pass an array to a function in C, it decays into a pointer to its first element. 
Consequently, sizeof(array) inside the array_size function returns the size of a pointer, not the size of the array itself.*/





//>>>>>>>>>> method_02 - programa 0811 <<<<<<<<<<

int file_count_integers_in_array(char *fileName) {
	
	FILE *file = fopen(fileName, "rt");
	
	if (file == NULL) {
		
		printf("Error opening file %s\n", fileName);
		return -1; // Return -1 to indicate failure
		
	}
	
	int count = 0;
	int num;
	
	while (fscanf(file, "%d", &num) == 1) {
		
		count++;
	}
	
	fclose(file);
	
	if (count == 0) {
		
		printf("\n\nNO integers found in file %s\n", fileName);
		
	} else {
		
		printf("\n\nnumber of integers in array: %d\n", count);
		
	}
	
	fclose(file);
	
	return count;
}

//o metodo abaixo faz A MESMA COISA

int file_integer_quantity (char* fileName){
	
	int temp;
	
	int count = 0;
	
	FILE *file = fopen(fileName,"rt");
	
	if(file == NULL){
		printf("could not open specified file");
		return -1;
	}
	while(fscanf(file,"%d",&temp)==1){
		count++;
	}
	
	fclose(file);
	
	//printf("%d",count);
	
	return (count); //count é o tamanho de inteiros do array
}
/* Using feof() as the loop condition can lead to reading beyond the end of the file, resulting in unexpected behavior. feof() only returns true after 
attempting to read past the end of the file, so your loop may execute one extra iteration.*/
/*When you read integers from a file, the file pointer (arquivo) moves forward with each successful read operation. However, when you reach the end of the file 
and try to read again, the fscanf operation fails, and the file pointer remains at the end of the file. This can cause subsequent read operations to 
fail because there are no more integers to read.*/


void file_read_array (char* fileName, int array[], int count){
	
	FILE *file = fopen(fileName,"rt");
	
	if(count == 0){  //do not create array of size 0
		fclose(file);
	}
	else{
		//second run
		
		//int array[count];
		
		rewind(file);
		/*function returns the file position indicator to the beginning of the file. It takes a file pointer as input and moves the 
		indicator to the beginning of the file, allowing data to be read once more from the beginning.*/
		
		for(int i=0; i<count; i++){
			fscanf(file,"%d",&array[i]);
		}
		
		fclose(file);
	}
	
}


void file_print_array(char* fileName, int arr[], int size) {
	
	FILE *arquivo = fopen(fileName, "at");
	
	//fprintf(arquivo, "[");
	
	for (int i = 0; i < size; i++) {
		
		fprintf(arquivo, "%d", arr[i]);
		
		if (i < size - 1) {
			fprintf(arquivo, "\n");
		}
		
	}
	
	//fprintf(arquivo, "]\n");
	
	fclose(arquivo);
}


void file_print_int_array (char *fileName, int n, int array[]){
	
	FILE *arquivo = fopen (fileName, "wt");
	int x = 0;
	
	fprintf(arquivo, "%d\n", n);
	
	for(x=0; x<n; x++){
		
		fprintf(arquivo, "%d\n", array[x]);
		
	}
	
	fclose(arquivo);
	
}


int count_positives_array (int arr[], int n){
	
	int x = 0;
	int pos = 0;
	
	while(x<n){
		
		if ((arr[x]%2 == 0) && (arr[x]>=0)){
			
			pos++;
			
		}
		
		x++;
		
	}
	
	return(pos);
}


void method_02 (void){
	
	int p = 0;
	int a = 0;
	
	//identificar
	printf("\nmethod_02 - programa 0812");
	
	int n = file_count_integers_in_array("ed08method_02TESTE.txt");
	
	int array[n];
	
	file_read_array("ed08method_02TESTE.txt", array, n);
	
	print_array(array, n);
	
	p = count_positives_array(array, n);
		
	int positivos[p];
	
	printf("\np = %d\n", p);
	
	for(int i = 0; i<n; i++){
		
		if((array[i]>=0) && (array[i]%2 == 0)){
			
			positivos[a] = array[i];
			a++;
		}
		
	}
	
	print_array(positivos, p);
	
	FILE *arquivo = fopen("ed08method_02RESULTADO.txt", "wt");
	
	fprintf(arquivo, "tamanho total do array = %d", p);
	
	fprintf(arquivo, "\n\napenas valores positivos = \n");
	
	fclose(arquivo);
	
	file_print_array("ed08method_02RESULTADO.txt", positivos, p);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





//>>>>>>>>>> method_03 - programa 0813 <<<<<<<<<<

void init_random() {
	srand(time(NULL)); // Inicializa o gerador de números aleatórios com o tempo atual
}

int generate_random_int(int start, int end) {
	
	// Se o início for maior que o fim, troca os valores
	if (start > end) {
		int temp = start;
		start = end;
		end = temp;
	}
	
	// Calcula o intervalo entre start e end
	int interval = end - start + 1;
	
	// Gera um número aleatório no intervalo e o retorna
	int random_number = rand() % interval + start;
	return random_number;
}


void method_03 (void){
	
	int start = 0;
	int end = 0;
	int qtd = 0;
	int temp = 0;
	
	//identificar
	printf("\nmethod_03 - programa 0513");
	
	printf("\n\nlimite inferior do intervalo = ");
	scanf("%d", &start); getchar();
	
	printf("\n\nlimite superior do intervalo = ");
	scanf("%d", &end); getchar();
	
	printf("\n\nquantos valores vc quer gerar? ");
	scanf("%d", &qtd); getchar();
	
	int valores[qtd];
	
	for(int i = 0; i<=qtd; i++){
		
		temp = generate_random_int(start, end);
		
		valores[i] = temp;
	}
	
	print_array(valores, qtd);
	
	FILE *arquivo = fopen("ed08method_03DADOS.txt", "wt");
	
	fprintf(arquivo, "quantidade de numeros aleatorios = %d\n", qtd);
	
	fclose(arquivo);
	
	file_print_array("ed08method_03DADOS.txt", valores, qtd);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





//>>>>>>>>>> method_04 - programa 0814 <<<<<<<<<<

int smallest_odd (int arr[], int size){
	
	int temp = 0;
	int i = 0;
	
	temp = arr[i];
	
	for(int i=0;i<size;i++){
		
		if(arr[i]%2 != 0){
			
			if(arr[i]<temp){
				
				temp = arr[i];
				
			}
			
		}
		
	}
	
	return temp;
}


void method_04 (void){
	
	//identificar
	printf("\nmethod_04 - programa 0814");
	
	int tam = file_count_integers_in_array("ed08method_04TESTE.txt");
	
	int arranjo[tam];
	
	file_read_array("ed08method_04TESTE.txt", arranjo, tam);
	
	print_array(arranjo, tam);
	
	int menor = smallest_odd(arranjo, tam);
	
	printf("\n\nmenor numero impar = %d", menor);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





//>>>>>>>>>> method_05 - programa 0815 <<<<<<<<<<

int biggest_odd (int arr[], int size){
	
	int temp = 0;
	int i = 0;
	
	temp = arr[i];
	
	for(int i=0;i<size;i++){
		
		if(arr[i]%2 != 0){
			
			if(arr[i]>temp){
				
				temp = arr[i];
				
			}
			
		}
		
	}
	
	return temp;
}


void method_05 (void){
	
	//identificar
	printf("\nmethod_05 - programa 0815");
	
	int tam = file_count_integers_in_array("ed08method_04TESTE.txt");
	
	int arranjo[tam];
	
	file_read_array("ed08method_04TESTE.txt", arranjo, tam);
	
	print_array(arranjo, tam);
	
	int maior = biggest_odd(arranjo, tam);
	
	printf("\n\nmaior numero impar = %d", maior);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





//>>>>>>>>>> method_06 - programa 0816 <<<<<<<<<<

int media_arranjo (int arr[], int size){
	
	int soma = 0;
	int media = 0;
	
	for(int i=0;i<size;i++){
		
		soma = soma + arr[i];
		
	}
	
	media = soma/size;
	
	return media;
}

void method_06 (void){
	
	int media = 0;
	
	//identificar
	printf("\nmethod_06 - programa 0816");
	
	int tam = file_count_integers_in_array("ed08method_04TESTE.txt");
	
	int arranjo[tam];
	
	file_read_array("ed08method_04TESTE.txt", arranjo, tam);
	
	print_array(arranjo, tam);
	
	media = media_arranjo(arranjo, tam);
	
	printf("\n\nmedia dos valores = %d", media);
	
	FILE* arquivo1 = fopen("ed08method_06_MAIORES.txt", "wt");
	FILE* arquivo2 = fopen("ed08method_06_MENORES.txt", "wt");
	
	for(int i=0;i<tam;i++){
		
		if(arranjo[i] > media){
			
			fprintf(arquivo1, "%d\n", arranjo[i]);
			
		}else{
			
			fprintf(arquivo2, "%d\n", arranjo[i]);
			
		}
	}
	
	fclose(arquivo1);
	fclose(arquivo2);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





//>>>>>>>>>> method_07 - programa 0817 <<<<<<<<<<

bool esta_ordenado (int arr[], int size){
	
	bool result = true;
	int temp = 0;
	int i = 0;

	
	for(int i=0;i<size-1;i++){
		
		temp = arr[i];
		
		if(arr[i+1]>temp){
			
			result = false;
			
		}

		
	}
	
	return(result);
	
}


void method_07 (void){
	
	char *nomearquivo = "ed08method07_TESTE01.txt";
	//char *nomearquivo = "ed08method07_TESTE02.txt";
	//char *nomearquivo = "ed08method07_TESTE03.txt";
	//char *nomearquivo = "ed08method07_TESTE04.txt";
	
	//identificar
	printf("\nmethod_07 - programa 0817");
	
	int tam = file_count_integers_in_array(nomearquivo);
	
	int arranjo[tam];
	
	file_read_array(nomearquivo, arranjo, tam);
	
	print_array(arranjo, tam);
	
	bool ordenado = esta_ordenado(arranjo, tam);
	
	if (ordenado){
		
		printf("\n\no arranjo ESTA ordenado em ordem decrescente");
		
	}else{
		
		printf("\n\no arranjo NAO esta ordenado em ordem decrescente");
		
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





//>>>>>>>>>> method_08 - programa 0818 <<<<<<<<<<

bool find_int (int arr[], int size, int find){
	
	bool result = false;
	int i = 0;
	
	
	for(int i=0;i<size;i++){
		
		
		if(arr[i] == find){
			
			result = true;
			
		}
		
		
	}
	
	return(result);
	
}


void method_08 (void){
	
	char *nomearquivo = "ed08method_04TESTE.txt";
	
	int find = 0;
	
	bool achou = false;
	
	//identificar
	printf("\nmethod_08 - programa 0818");
	
	int tam = file_count_integers_in_array(nomearquivo);
	
	int arranjo[tam];
	
	file_read_array(nomearquivo, arranjo, tam);
	
	print_array(arranjo, tam);
	
	printf("\n\nqual valor vc deseja procurar?  ");
	scanf("%d", &find); getchar();
	
	achou = find_int(arranjo, tam, find);
	
	if (achou){
		
		printf("\n\no valor %d FOI encontrado no arranjo", find);
		
	}else{
		
		printf("\n\no valor %d NAO foi encontrado no arranjo", find);
		
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





//>>>>>>>>>> method_09 - programa 0009 <<<<<<<<<<

int find_int_position (int arr[], int size, int find){
	
	int i = 0;
	
	
	for(int i=0;i<size;i++){
		
		
		if(arr[i] == find){
			
			return(i);
			
		}
		
		
	}
	
	return(-1); //caso o valor nao seja encontrado
	
}


void method_09 (void){
	
	char *nomearquivo = "ed08method_04TESTE.txt";
	
	int find = 0;
	
	bool achou = false;
	
	int pos = 0;
	
	//identificar
	printf("\nmethod_09 - programa 0819");
	
	int tam = file_count_integers_in_array(nomearquivo);
	
	int arranjo[tam];
	
	file_read_array(nomearquivo, arranjo, tam);
	
	print_array(arranjo, tam);
	
	printf("\n\nqual valor vc deseja procurar?  ");
	scanf("%d", &find); getchar();
	
	achou = find_int(arranjo, tam, find);
	
	if (achou){
		
		printf("\n\no valor %d FOI encontrado no arranjo", find);
		
		pos = find_int_position(arranjo, tam, find);
		
		printf("\nele esta na posicao %d", pos);
		
	}else{
		
		printf("\n\no valor %d NAO foi encontrado no arranjo", find);
		
	}
	
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





//>>>>>>>>>> method_10 - programa 0000 <<<<<<<<<<

int how_many_int (int arr[], int size, int find){
	
	int i = 0;
	int qtd = 0;
	
	for(int i=0;i<size;i++){
		
		
		if(arr[i] == find){
			
			qtd++;
			
		}
		
		
	}
	
	return(qtd);
	
}

void method_10 (void){
	
	char *nomearquivo = "ed08method_10TESTE.txt";
	
	int find = 0;
	
	bool achou = false;
	
	int vezes = 0;
	
	//identificar
	printf("\nmethod_10 - programa 0820");
	
	int tam = file_count_integers_in_array(nomearquivo);
	
	int arranjo[tam];
	
	file_read_array(nomearquivo, arranjo, tam);
	
	print_array(arranjo, tam);
	
	printf("\n\nqual valor vc deseja procurar?  ");
	scanf("%d", &find); getchar();
	
	achou = find_int(arranjo, tam, find);
	
	if (achou){
		
		printf("\n\no valor %d FOI encontrado no arranjo", find);
		
		vezes = how_many_int(arranjo, tam, find);
		
		printf("\nele aparece %d vezes", vezes);
		
	}else{
		
		printf("\n\no valor %d NAO foi encontrado no arranjo", find);
		
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





int main (int argc, char *argv[]){
	
	//identificar o programa
	printf ("%s", "estudo dirigido 08 - programas_0811_a_0820");
	printf ("\n%s\n%s", "autor: raquel de parde motta", "matricula: 854017");
	
	int opcao = 0;
	
	do{
		//mostrar as opcoes
		printf ("\n\n%s", "digite o numero correspondente a opcao desejada: ");
		printf ("\n\n%s", "0 - encerrar");
		printf ("\n\n%s", "1 - method_01 - programa 0511");
		printf ("\n\n%s", "2 - method_02 - programa 0512");
		printf ("\n\n%s", "3 - method_03 - programa 0513");
		printf ("\n\n%s", "4 - method_04 - programa 0514");
		printf ("\n\n%s", "5 - method_05 - programa 0515");
		printf ("\n\n%s", "6 - method_06 - programa 0516");
		printf ("\n\n%s", "7 - method_07 - programa 0517");
		printf ("\n\n%s", "8 - method_08 - programa 0518");
		printf ("\n\n%s", "9 - method_09 - programa 0519");
		printf ("\n\n%s", "10 - method_10 - programa 0520");
		
		//ler o valor inputado
		printf ("\n\n%s", "opcao =  ");
		scanf ("%i", &opcao);
		getchar ();
		
		switch (opcao) {
		case 0:
			break;
		case 1:
			method_01 ();
			break;
		case 2:
			method_02 ();
			break;
		case 3:
			method_03 ();
			break;
		case 4:
			method_04 ();
			break;
		case 5:
			method_05 ();
			break;
		case 6:
			method_06 ();
			break;
		case 7:
			method_07 ();
			break;
		case 8:
			method_08 ();
			break;
		case 9:
			method_09 ();
			break;
		case 10:
			method_10 ();
			break;
		default:
			printf ("\n\n%s", "erro - opcao invalida");
			break;
		}
	}while(opcao !=0);
	
	return (0);
}

/*
DOCUMENTACAO COMPLEMENTAR


>>>>>>>>>>>>>>>>>>>>>>>>>>>>> outputs

testes e outputs estao no arquivo "outputs_exercicios_ED08_raquelmotta.txt"


>>>>>>>>>>>>>>>>>>>>>>>>>>>>> notas e comentarios

*/
