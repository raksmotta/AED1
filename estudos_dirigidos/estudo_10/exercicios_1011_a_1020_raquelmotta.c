/*
PUC MINAS - AEDs1
Mai/2024

Estudo Dirigido 10

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: exercicios_1011_a_1020_raquelmotta
Versao: 0.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

//>>>>>>>>>> method_01 - programa 1011 <<<<<<<<<<

typedef struct valores
{
	int lim_inf;
	int lim_sup;
	int tam_arranjo;
	int * arranjo;
}
s_valores;	//nome do tipo

/*essa funcao faz os 2 malloc que precisamos: ela aloca memoria dinamicamente para o struct e depois aloca memoria dinamicamente para o array
dentro da estrutura. ou seja: é a função básica para criar um "objeto struct"*/

s_valores* create_valores (int n){
	
	s_valores* values = (s_valores*)malloc(sizeof(s_valores));	
	//o malloc retorna um ponteiro que aponta para uma área de memória reservada que é do tamanho da estrutura valores.
	//esse ponteiro se chamará values
	
	if(values == NULL){		//malloc retorna NULL quando dá erro
		
		printf("\n\nerro. falta espaco.");
		
	}else{
		
		values -> arranjo = NULL;	//logo após alocar dinamicamente o struct, é boa prática inicializar o ponteiro como NULL
		values -> tam_arranjo = 0;
		values -> lim_inf = 0;
		values -> lim_sup = 0;
		
		do{
			printf("\n\ninsira o limite inferior:  ");
			scanf("%d", & values->lim_inf); getchar();
			
			printf("\ninsira o limite superior:  ");
			scanf("%d", & values->lim_sup); getchar();
			
		}while(values->lim_inf > values->lim_sup || values->lim_inf == values->lim_sup);

		if (n>0){
			
			values->tam_arranjo = n;
			
			values->arranjo = (int*)malloc(n*sizeof(int));	//agora o ponteiro arranjo aponta para um espaço de n inteiros
			
		}else{
			
			printf("\n\nerro. tamanho de arranjo negativo.");
			
		}
		
	}
	
	return (values);	//retorna o ponteiro para o "objeto struct" criado
}


void free_valores (s_valores* values){
	
	free (values->arranjo);
	free (values);
	
}


void random_array (s_valores* values){
	
	int range = values->lim_sup - values->lim_inf + 1;
	
	for(int x = 0; x < values->tam_arranjo; x++){
		
		values->arranjo[x] = values->lim_inf + rand() % range;
		
	}
	
}


void valores_print_array (s_valores* values){	//nao precisaria passar o parametro como ponteiro pois não irei alterar nada dentro da função, só visualizar
	
	for(int x = 0; x < values->tam_arranjo; x++){
		
		printf("%d ", values->arranjo[x]);
		
	}
	
}

void valores_print_array_file (s_valores* values, char* filename){
	
	FILE* arquivo = fopen(filename, "wt");
	
	fprintf(arquivo, "%d\n", values->tam_arranjo);	//imprimindo a qtd de inteiros no arranjo na primeira linha do arquivo
	
	for (int x = 0; x < values->tam_arranjo; x++){
		
		fprintf(arquivo, "%d", values->arranjo[x]);
		
		if(x < values->tam_arranjo-1){
			
			fprintf(arquivo, "\n");
			
		}
		
	}
	
	fclose(arquivo);
	
}


void method_01 (void){
	
	//identificar
	printf("\nmethod_01 - programa 1011");
	
	int n = 0;
	
	printf("\n\nquantidade de valores no arranjo: ");
	scanf("%d", &n); getchar();
	
	s_valores* val = create_valores(n);
	
	random_array(val);
	
	printf("\n\narranjo gerado:\n");
	valores_print_array(val);
	
	valores_print_array_file(val, "dados.txt");
	
	free_valores(val);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}



//>>>>>>>>>> method_02 - programa 1012 <<<<<<<<<<

typedef struct meu_arranjo{
	
	int tam;
	int* arranjo;
	
}s_meuarranjo;

s_meuarranjo* create_meuarranjo (int n){
	
	s_meuarranjo* kelArray = (s_meuarranjo*)malloc(sizeof(s_meuarranjo)); //pode fazer o malloc dentro de uma funcao assim? como se fosse o construtor
	
	if(kelArray == NULL){
		
		printf("\n\nERRO. falta espaco para alocar a estrutura.");
		
	}else{
		
		kelArray->arranjo = NULL;
		kelArray->tam = 0;
		
		if(n>0){
			
			kelArray->tam = n;
			
			kelArray->arranjo = (int*)malloc(n*sizeof(int));
			
		}else{
			
			printf("\n\nERRO. tamanho de arranjo nulo ou negativo.");
			
		}
		
	}
	
	return kelArray;
	
}


void free_meuarranjo (s_meuarranjo* kelArray){
	
	free(kelArray->arranjo);
	free(kelArray);
	
}


int read_int_qtd_file (char* filename){		//funcao só para ler a quantidade de inteiros no arquivo
	
	int qtd = 0;
	
	FILE* arquivo = fopen (filename, "rt");
	
	fscanf(arquivo, "%d", &qtd);
	
	fclose(arquivo);
	
	return qtd;
	
}


/*
If you open a file in one function, read from it, and then close it, and afterward, in a different function, you open the same file again, 
you do not need to use rewind(file) When you close a file using fclose(), all the associated buffers are flushed and the file pointer 
associated with that file is discarded.
*/
void meuarranjo_read_array_file (s_meuarranjo* kelArray, char* filename){
	
	int qtd = 0;
	
	FILE* arquivo = fopen(filename, "rt");
	
	fscanf(arquivo, "%d", &qtd);	//pular a primeira linha
	
	for(int x = 0; x < kelArray->tam; x++){
		
		fscanf(arquivo, "%d", & kelArray->arranjo[x]);
		
	}
	
	fclose(arquivo);
	
}

void meuarranjo_print (s_meuarranjo* kelArray){
	
	for(int x = 0; x < kelArray->tam; x++){
		
		printf("%d ", kelArray->arranjo[x]);
		
	}
	
}

bool meuarranjo_search (s_meuarranjo* kelArray, int procurado){
	
	bool achado = false;
	
	for(int x = 0; x < kelArray->tam; x++){
		
		if(kelArray->arranjo[x] == procurado){
			
			achado = true;
			
		}
		
	}
	
	return achado;
	
}


void method_02 (void){
	
	//identificar
	printf("\nmethod_02 - programa 1012");
	
	int n = read_int_qtd_file("dados.txt");
	
	s_meuarranjo* kelArranjo = create_meuarranjo(n);	//ao inves de fazer o primeiro malloc aqui, fiz lá dentro da funcao
	
	meuarranjo_read_array_file(kelArranjo, "dados.txt");
	
	printf("\n\narranjo lido do arquivo: ");
	meuarranjo_print(kelArranjo);
	
	int search = 0;
	printf("\n\npor qual valor vc deseja procurar? ");
	scanf("%d", &search); getchar();
	
	bool result = meuarranjo_search(kelArranjo, search);
	
	if(result){
		
		printf("\n\no valor FOI encontrado no arranjo");
		
	}else{
		
		printf("\n\no valor NAO foi encontrado no arranjo");
		
	}
	
	free_meuarranjo(kelArranjo);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



//>>>>>>>>>> method_03 - programa 1013 <<<<<<<<<<

bool meuarranjo_compare (s_meuarranjo* a1, s_meuarranjo* a2){
	
	bool igual = true;
	
	if (a1->tam != a2->tam){
		
		printf("\n\narranjos de tamanhos diferentes");
		
		igual = false;
		
		return igual;
		
	}else{
		
		for(int x = 0; x < a1->tam; x++){
			
			if (a1->arranjo[x] != a2->arranjo[x]){
				
				igual = false;
				
			}
			
			
		}
		
		return igual;
		
	}
	
}


void method_03 (void){
	
	//identificar
	printf("\nmethod_03 - programa 1013");
	
	/*
	para testar: "dados" e "dados2" contém arrays identicos
	"dados3" possui um array com o mesmo tamanho de "dados", porém que armazena inteiros diferentes
	"dados4" possui um array de tamanho diferente dos demais
	*/
	
	int n1 = read_int_qtd_file("dados.txt");
	
	s_meuarranjo* a1 = create_meuarranjo(n1);
	
	meuarranjo_read_array_file(a1, "dados.txt");
	
	printf("\n\narranjo lido do arquivo 1: ");
	meuarranjo_print(a1);
	
	int n2 = read_int_qtd_file("dados3.txt");
	
	s_meuarranjo* a2 = create_meuarranjo(n2);
	
	meuarranjo_read_array_file(a2, "dados3.txt");
	
	printf("\n\narranjo lido do arquivo 2: ");
	meuarranjo_print(a2);
	
	bool result = meuarranjo_compare(a1, a2);
	
	if(result){
		
		printf("\n\nos arranjos sao IGUAIS");
		
	}else{
		
		printf("\n\nos arranjos sao DIFERENTES");
		
	}
	
	free_meuarranjo(a1);
	free_meuarranjo(a2);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



//>>>>>>>>>> method_04 - programa 1014 <<<<<<<<<<

int* add_meuarranjo (s_meuarranjo* a1, s_meuarranjo* a2, int c){
	
	if (a1->tam != a2->tam){
		
		printf("\n\nERRO. arranjos de tamanhos diferentes nao podem ser somados.");
		
		return NULL;
		
	}else{
		
		int* resultado = (int*)malloc(a1->tam * sizeof(int));
		
		for(int x = 0; x < a1->tam; x++){
			
			resultado[x] = a1->arranjo[x] + (c * a2->arranjo[x]);
			
		}
		
		return resultado;
		
	}
	
}


void print_array (int* array, int size){
	
	for(int x = 0; x < size; x++){
		
		printf("%d ", array[x]);
		
	}
	
}


void method_04 (void){
	
	int c = 0;
	int* result = NULL;
	
	//identificar
	printf("\nmethod_04 - programa 1014");
	
	int n1 = read_int_qtd_file("dados.txt");
	
	s_meuarranjo* a1 = create_meuarranjo(n1);
	
	meuarranjo_read_array_file(a1, "dados.txt");
	
	printf("\n\narranjo lido do arquivo 1: ");
	meuarranjo_print(a1);
	
	int n2 = read_int_qtd_file("dados3.txt");
	
	s_meuarranjo* a2 = create_meuarranjo(n2);
	
	meuarranjo_read_array_file(a2, "dados3.txt");
	
	printf("\n\narranjo lido do arquivo 2: ");
	meuarranjo_print(a2);
	
	result = (int*)malloc(a1->tam * sizeof(int));
	
	printf("\n\npor qual constante vc quer escalar o segundo arranjo?  ");
	scanf("%d", &c); getchar();
	
	result = add_meuarranjo(a1, a2, c);
	
	if(result != NULL){
		
		printf("\nresultado da soma dos arranjos:\n");
		
		print_array(result, a1->tam);
		
	}
	
	free_meuarranjo(a1);
	free_meuarranjo(a2);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



//>>>>>>>>>> method_05 - programa 1015 <<<<<<<<<<

bool is_meuarranjo_decrescent (s_meuarranjo* kelarray){
	
	bool decrescente = true;
	
	for(int x = 0; x < kelarray->tam - 1; x++){
		
		if(kelarray->arranjo[x] < kelarray->arranjo[x+1]){
			
			decrescente = false;
			
		}
		
	}
	
	return decrescente;
	
}


void method_05 (void){
	
	//identificar
	printf("\nmethod_05 - programa 1015");
	
	int n1 = read_int_qtd_file("dados5.txt");
	
	s_meuarranjo* a1 = create_meuarranjo(n1);
	
	meuarranjo_read_array_file(a1, "dados5.txt");
	
	printf("\n\narranjo lido do arquivo: ");
	meuarranjo_print(a1);
	
	//para testar: "dados5.txt" possui arranjo decrescente
	
	bool dec = is_meuarranjo_decrescent(a1);
	
	if (dec){
		
		printf("\n\no arranjo EH decrescente");
		
	}else{
		
		printf("\n\no arranjo NAO eh decrescente");
		
	}
	
	free_meuarranjo(a1);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



//>>>>>>>>>> method_06 - programa 1016 <<<<<<<<<<

typedef struct minha_matriz{
	
	int** matrix;
	int cols;
	int rows;
	
}s_matriz;

int inicializar_matriz_teclado (s_matriz* kelmatrix){
	
	if (kelmatrix == NULL){
		
		return -1; // Handle NULL input
		
	}
	
	kelmatrix->rows = 0;
	kelmatrix->cols = 0;
	
	while (kelmatrix->rows <= 1 || kelmatrix->cols <= 1){
		
		printf("\n\nROWS = ");
		scanf("%d", &kelmatrix->rows); getchar();
		
		printf("\nCOLUMNS = ");
		scanf("%d", &kelmatrix->cols); getchar();
		
	}
	
	kelmatrix->matrix = (int**)malloc(kelmatrix->rows * sizeof(int*));
	
	if (kelmatrix->matrix == NULL){
		
		return -1; // Check malloc success
		
	} 
	
	for(int i = 0; i < kelmatrix->rows; i++){
		
		kelmatrix->matrix[i] = (int*)malloc(kelmatrix->cols * sizeof(int));
		
		//if (kelmatrix->matrix[i] == NULL) {
			
			/*Free previously allocated memory on failure
			
			for (int x = 0; x < i; x++) {
			free(kelmatrix->matrix[x]);
			}
			
			free(kelmatrix->matrix);
			return -1;*/ 
		//}
	}
	
	// Initialize matrix elements to zero
	for (int x = 0; x < kelmatrix->rows; x++){
		
		for (int y = 0; y < kelmatrix->cols; y++) {
			kelmatrix->matrix[x][y] = 0;
		}
		
	}
	
	return 0;
}

void preencher_minhamatriz (s_matriz* kelmatrix){
	
	int temp = 0;
	
	printf("\n\n");
	
	for (int i = 0; i < kelmatrix->rows; i++){
		
		for (int j = 0; j < kelmatrix->cols; j++){
			
			printf("row %d , col %d = ", i , j);
			
			scanf("%d", &temp); getchar();
			
			kelmatrix->matrix[i][j] = temp;
			
		}
		
	}
	
}

//serve para quando o numero de rows e columns estiver escrito nas primeiras duas linhas do arquivo
int inicializar_matriz_arquivo (s_matriz* kelmatrix, char* filename){
	
	if (kelmatrix == NULL){
		
		return -1; // Handle NULL input
		
	}
	
	kelmatrix->rows = 0;
	kelmatrix->cols = 0;
	
	FILE* arquivo = fopen (filename, "rt");
	
	if (arquivo == NULL) {
		return -1; // File couldn't be opened
	}
	
	fscanf(arquivo, "%d", &kelmatrix->rows);
	fscanf(arquivo, "%d", &kelmatrix->cols);
	
	if (kelmatrix->rows <= 1 || kelmatrix->cols <= 1){
		
		fclose(arquivo);
		return -1;
		
	}
	
	//alocar memória para a matriz!!!
	kelmatrix->matrix = (int**)malloc(kelmatrix->rows * sizeof(int*));
	if (kelmatrix->matrix == NULL) {
		fclose(arquivo);
		return -1; // Memory allocation failed
	}
	
	for (int i = 0; i < kelmatrix->rows; i++){
		
		kelmatrix->matrix[i] = (int*)malloc(kelmatrix->cols * sizeof(int));
		
	}
	
	
	//read matrix elements
	int x = 0;
	int y = 0;
	int temp = 0;
	
	while (!feof(arquivo) && x<kelmatrix->rows){
		
		y = 0;
		
		while (!feof(arquivo) && y<kelmatrix->cols){
			
			//ler valor do arquivo
			fscanf(arquivo, "%d", &temp);
			
			//guardar valor na matriz
			kelmatrix->matrix[x][y] = temp;
			
			y++;
			
		}
		
		x++;
		
	}	
	
	fclose (arquivo);
	return 0;
	
}

void free_minhamatriz (s_matriz* kelmatrix){
	
	for (int i = 0; i < kelmatrix->rows; i++) {
		free(kelmatrix->matrix[i]);
	}
	
	free(kelmatrix->matrix);
	
}

void transpor_matriz (s_matriz* original, s_matriz* destino){
	
	//criando a matriz de destino com as dimensoes opostas 
	
	destino->rows = original->cols;
	destino->cols = original->rows;
	
	destino->matrix = (int**)malloc(original->cols * sizeof(int*));
	
	for (int i = 0; i < original->cols; i++){
		
		destino->matrix[i] = (int*)malloc(original->rows * sizeof(int));
		
	}
	
	//fazendo a transposicao
	int x = 0;
	int y = 0;
	
	while (x  < destino->rows){
		
		y = 0;
		
		while (y < destino->cols){
			
			destino->matrix[x][y] = original->matrix[y][x];
			
			y++;
			
		}
		
		x++;
		
	}
	
}

void imprimir_minhamatriz (s_matriz* kelmatrix){
	
	printf("\n\n");
	
	for (int i = 0; i < kelmatrix->rows; i++){
		
		for (int j = 0; j < kelmatrix->cols; j++){
			
			printf("%3d\t", kelmatrix->matrix[i][j]);
			
		}
		
		printf("\n");
		
	}
	
}

void method_06 (void){
	
	//identificar
	printf("\nmethod_06 - programa 1016");
	
	s_matriz* kel = (s_matriz*)malloc(sizeof(s_matriz));
	
	int check = inicializar_matriz_teclado(kel);
	
	if (check == -1){
		
		printf("\n\nERRO ao inicializar matriz");
		
	}else{
		
		imprimir_minhamatriz(kel);
		
		preencher_minhamatriz(kel);
		
		imprimir_minhamatriz(kel);
		
		s_matriz* transposta = (s_matriz*)malloc(sizeof(s_matriz));
		
		transpor_matriz(kel, transposta);
		
		imprimir_minhamatriz(transposta);
		
		free_minhamatriz(transposta);
		
	}
	
	free_minhamatriz(kel);
	free(kel);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



//>>>>>>>>>> method_07 - programa 1017 <<<<<<<<<<

bool is_minhamatriz_allzero (s_matriz* kel){
	
	bool result = true;
	
	for (int i = 0; i < kel->rows; i++){
		
		for (int j = 0; j < kel->cols; j++){
			
			if (kel->matrix[i][j] != 0){
				
				result = false;
				
			}
			
		}
		
	}
	
	return result;
	
}

void method_07 (void){
	
	//identificar
	printf("\nmethod_07 - programa 1017");
	
	s_matriz* zeros = (s_matriz*)malloc(sizeof(s_matriz));
	
	int check = inicializar_matriz_teclado(zeros);
	
	if (check == -1){
		
		printf("\n\nERRO ao inicializar matriz");
		
	}else{
		
		printf("\n\nmatriz 1:");
		imprimir_minhamatriz(zeros);
		
		s_matriz* naozeros = (s_matriz*)malloc(sizeof(s_matriz));
		
		check = inicializar_matriz_arquivo(naozeros, "matriz.txt");
		
		if (check == -1){
			
			printf("\n\nERRO ao inicializar matriz a partir de arquivo");
			
		}else{
			
			printf("\n\nmatriz 2:");
			imprimir_minhamatriz(naozeros);
			
			bool r1 = is_minhamatriz_allzero(zeros);
			bool r2 = is_minhamatriz_allzero(naozeros);
			
			if (r1){
				
				printf("\n\na matriz 1 APENAS contem valores iguais a zero");
				
			}else{
				
				printf("\n\na matriz 1 NAO contem apenas valores iguais a zero");
				
			}
			
			if (r2){
				
				printf("\n\na matriz 2 APENAS contem valores iguais a zero");
				
			}else{
				
				printf("\n\na matriz 2 NAO contem apenas valores iguais a zero");
				
			}
			
			free_minhamatriz(naozeros);
			
		}
		
		
	}
	
	free_minhamatriz(zeros);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



//>>>>>>>>>> method_08 - programa 1018 <<<<<<<<<<

bool is_minhamatriz_iguais (s_matriz m1, s_matriz m2){
	
	if (m1.rows != m2.rows || m1.cols != m2.cols){
		
		return false;
		
	}
	
	for (int x = 0; x < m1.rows; x++){
		
		for (int y = 0; y < m1.cols; y++){
			
			if(m1.matrix[x][y] != m2.matrix[x][y]){
				
				return false;
				
			}
			
		}
		
	}
	
	return true;
	
}

void method_08 (void){
	
	//identificar
	printf("\nmethod_08 - programa 1018");
	
	s_matriz m1;
	s_matriz m2;
	
	int check = 0;
	
	check = inicializar_matriz_arquivo(&m1, "matriz.txt");
	
	if(check == -1){
		
		printf("\n\nERRO ao inicializar matriz a partir de arquivo");
		
	}else{
		
		printf("\n\nmatriz 1:");
		imprimir_minhamatriz(&m1);
		
		check = inicializar_matriz_arquivo(&m2, "matriz1.txt");
		
		if(check == -1){
			
			printf("\n\nERRO ao inicializar matriz a partir de arquivo");
			
		}else{
			
			printf("\n\nmatriz 2:");
			imprimir_minhamatriz(&m2);
			
			bool result = is_minhamatriz_iguais(m1, m2);
			
			if(result){
				
				printf("\n\nas matrizes sao IGUAIS");
				
			}else{
				
				printf("\n\nas matrizes NAO sao iguais");
				
			}
			
		}
		
	}
	
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



//>>>>>>>>>> method_09 - programa 1019 <<<<<<<<<<

s_matriz* soma_minhasmatrizes (s_matriz m1, s_matriz m2, int c){
	
	if (m1.rows != m2.rows || m1.cols != m2.cols){
		
		return NULL;	//as matrizes precisam ter as mesmas dimensoes para serem somadas
		
	}else{
		
		s_matriz* resultado = (s_matriz*)malloc(sizeof(s_matriz));
		
		resultado->rows = m1.rows;
		resultado->cols = m1.cols;
		
		resultado->matrix = (int**)malloc(resultado->rows * sizeof(int*));
		
		for (int i = 0; i < resultado->rows; i++){
			
			resultado->matrix[i] = (int*)malloc(resultado->cols * sizeof(int));
			
		}
		
		for (int x = 0; x < resultado->rows; x++){
			
			for (int y = 0; y < resultado->cols; y++){
				
				resultado->matrix[x][y]  = (m1.matrix[x][y]) + (m2.matrix[x][y] * c);
				
			}
			
		}
		
	}
	
}

void method_09 (void){
	
	//identificar
	printf("\nmethod_09 - programa 1019");
	
	s_matriz m1;
	s_matriz m2;
	
	int check = 0;
	
	check = inicializar_matriz_arquivo(&m1, "matriz.txt");
	
	if(check == -1){
		
		printf("\n\nERRO ao inicializar matriz a partir de arquivo");
		
	}else{
		
		printf("\n\nmatriz 1:");
		imprimir_minhamatriz(&m1);
		
		check = inicializar_matriz_arquivo(&m2, "matriz1.txt");
		
		if(check == -1){
			
			printf("\n\nERRO ao inicializar matriz a partir de arquivo");
			
		}else{
			
			printf("\n\nmatriz 2:");
			imprimir_minhamatriz(&m2);
			
			s_matriz* result = soma_minhasmatrizes(m1, m2, 5);
			
			if(result == NULL){
				
				printf("\n\nERRO ao somar as matrizes");
				
			}else{
				
				//imprimir matriz resultado
				
			}
			
			
		}
		
	}
	
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



//>>>>>>>>>> method_10 - programa 1020 <<<<<<<<<<

void method_10 (void){
	
	//identificar
	printf("\nmethod_10 - programa 1020");
	
	s_matriz m1;
	s_matriz m2;
	s_matriz m3;
	
	int check = 0;
	
	check = inicializar_matriz_arquivo(&m1, "matriz.txt");
	
	if(check == -1){
		
		printf("\n\nERRO ao inicializar matriz a partir de arquivo");
		
	}else{
		
		printf("\n\nmatriz 1:");
		imprimir_minhamatriz(&m1);
		
		check = inicializar_matriz_arquivo(&m2, "matriz1.txt");
		
		if(check == -1){
			
			printf("\n\nERRO ao inicializar matriz a partir de arquivo");
			
		}else{
			
			printf("\n\nmatriz 2:");
			imprimir_minhamatriz(&m2);
			
		}
		
	}
	
	//Alocar espaço para a matriz3
	m3.matrix = (int**)malloc(sizeof(int*)*m1.rows);
	
	for (int i=0;i<m1.rows;i++){
		m3.matrix[i] = (int*)malloc(sizeof(int)*m2.cols);
	}
	
	//multiplicação
	for (int i=0;i<m1.rows;i++){
		
		for (int j=0;j<m2.cols; j++){
			
			m3.matrix[i][j]=0;
			
			for (int k=0;k<m1.cols;k++){
				
				m3.matrix[i][j]+= m1.matrix[i][k]*m2.matrix[k][j];
				
			}
			
		}
		
	}
	
	m3.rows = m1.rows;
	m3.cols = m2.cols;
	
	imprimir_minhamatriz(&m3);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



int main (int argc, char *argv[]){
	
	//identificar o programa
	printf ("%s", "estudo dirigido 10 - programas_1011_a_1020");
	printf ("\n%s\n%s", "autor: raquel de parde motta", "matricula: 854017");
	
	int opcao = 0;
	
	do{
		//mostrar as opcoes
		printf ("\n\n%s", "digite o numero correspondente a opcao desejada: ");
		printf ("\n\n%s", "0 - encerrar");
		printf ("\n\n%s", "1 - method_01 - programa 1011");
		printf ("\n\n%s", "2 - method_02 - programa 1012");
		printf ("\n\n%s", "3 - method_03 - programa 1013");
		printf ("\n\n%s", "4 - method_04 - programa 1014");
		printf ("\n\n%s", "5 - method_05 - programa 1015");
		printf ("\n\n%s", "6 - method_06 - programa 1016");
		printf ("\n\n%s", "7 - method_07 - programa 1017");
		printf ("\n\n%s", "8 - method_08 - programa 1018");
		printf ("\n\n%s", "9 - method_09 - programa 1019");
		printf ("\n\n%s", "10 - method_10 - programa 1020");
		
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


>>>>>>>>>>>>>>>>>>>>>>>>>>>>> notas e comentarios

*/
