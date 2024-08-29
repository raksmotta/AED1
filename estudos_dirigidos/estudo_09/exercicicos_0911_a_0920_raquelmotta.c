/*
PUC MINAS - AEDs1
Mai/2024

Estudo Dirigido 09

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: exercicios_0911_a_0920_raquelmotta
Versao: 0.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <io.h>

//>>>>>>>>>> method_01 - programa 0911 <<<<<<<<<<

void ler_dimensoes_matriz_teclado (int *rows, int *columns){
	
	do{
		printf("\nnumero de linhas da matriz = ");
		scanf("%d", rows); getchar();
		
		printf("\nnumero de colunas da matriz = ");
		scanf("%d", columns); getchar();
		
	}while (*rows<=0 || *columns<=0);
	
}

void read_double_matrix_negatives (int rows, int columns, double matrix[][columns]){
	
	int x = 0; int y = 0; double z = 0;
	
	for(x=0; x<rows; x++){
		
		while(y<columns){
			
			printf("\n%d , %d : ", x, y);
			scanf("%lf", &z); getchar();
			
			if(z>=0){
				
				printf("valor invalido. entre apenas com numeros negativos");
				
			}else{
				
				//guardar valor
				matrix[x][y] = z;
				y++;
				
			}
			
		}
		
		y = 0;
		
	}
	
}

void print_double_matrix (int rows,  int columns, double matrix[][columns]){
	
	int x = 0; int y = 0;
	
	//mostrar valores na matriz
	for (x=0; x<rows; x++){
		
		for(y=0; y<columns; y++){
			
			printf("%3lf\t", matrix[x][y]);
			
		}
		
		printf("\n");
	}
	
}

void method_01 (void){
	
	int row = 0;
	int col = 0;
	
	//identificar
	printf("\nmethod_01 - programa 0911");
	
	printf("\n");
	
	ler_dimensoes_matriz_teclado(&row, &col);
	
	printf("\nlinhas = %d", row);
	printf("\ncolunas = %d", col);
	
	printf("\n");
	
	double matrix[row][col];
	
	read_double_matrix_negatives(row, col, matrix);
	
	printf("\n");
	
	print_double_matrix(row, col, matrix);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





//>>>>>>>>>> method_02 - programa 0912 <<<<<<<<<<

void file_print_double_matrix (char* fileName, int rows, int columns, double matrix[][columns]){
	
	FILE *arquivo = fopen(fileName, "wt");
	int x = 0; int y = 0;
	
	//gravar qtd de dados
	//fprintf(arquivo, "%d\n", rows);
	//fprintf(arquivo, "%d\n", columns);
	
	//gravar valores no arquivo
	
	for(x=0; x<rows; x++){
		
		for(y=0; y<columns; y++){
			
			fprintf(arquivo, "%lf\n", matrix[x][y]);
			
		}		
		
	}
	
	fclose(arquivo);
	
}

void file_read_double_matrix (chars fileName, int rows, int columns, double matrix[][columns]){
	
	int x = 0; int y = 0; double z = 0;
	FILE* arquivo = fopen (fileName, "rt");
	
	//fscanf(arquivo, "%d", &x);
	//fscanf(arquivo, "%d", &y);
	
	//ler e guardar valores em arranjo
	x = 0;
	
	while(!feof(arquivo) && x<rows){
		
		y = 0;
		
		while(!feof(arquivo) && y<columns){
			
			//ler valor
			fscanf(arquivo, "%lf", &z);
			
			//guardar valor
			matrix[x][y] = z;
			
			y = y+1;
			
		}
		
		x = x+1;
		
	}
	
	
	fclose(arquivo);
	
}

void method_02 (void){
	
	int row = 0;
	int col = 0;
	
	//identificar
	printf("\nmethod_02 - programa 0912");
	
	printf("\n");
	
	ler_dimensoes_matriz_teclado(&row, &col);
	
	printf("\nlinhas = %d", row);
	printf("\ncolunas = %d", col);
	
	printf("\n");
	
	double matrix[row][col];
	
	read_double_matrix_negatives(row, col, matrix);
	
	file_print_double_matrix("ED09_METHOD02.TXT", row, col, matrix);
	
	file_read_double_matrix("ED09_METHOD02.TXT", row, col, matrix);
	
	printf("\n\n");
	print_double_matrix(row, col, matrix);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





//>>>>>>>>>> method_03 - programa 0913 <<<<<<<<<<

void mostrar_diagonal_principal(int n, double matrix[][n]) {
	
	printf("\n\nvalores na diagonal principal:\n");
	
	// Percorre a diagonal principal
	for (int i = 0; i < n; i++) {
		
		printf("%lf ", matrix[i][i]);
		
	}
	
	printf("\n");
}

void method_03 (void){
	
	int row = 0; int col =0;
	
	//identificar
	printf("\nmethod_03 - programa 0913");
	
	printf("\n");
	ler_dimensoes_matriz_teclado(&row, &col);
	
	printf("\nlinhas = %d", row);
	printf("\ncolunas = %d", col);
	
	printf("\n");
	double matrix[row][col];
	
	read_double_matrix_negatives(row, col, matrix);
	
	printf("\n");
	print_double_matrix(row, col, matrix);
	
	if(row == col){
		
		mostrar_diagonal_principal(col, matrix);
		
	}else{
		
		printf("\n\na matriz nao eh quadrada");
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





//>>>>>>>>>> method_04 - programa 0914 <<<<<<<<<<

void mostrar_diagonal_secundaria(int n, double matrix[][n]) {
	
	printf("\n\nvalores na diagonal secundaria:\n");
	
	// Percorre a diagonal secundaria
	for (int i = 0; i < n; i++) {
		
		printf("%lf ", matrix[i][n-i-1]);
		
	}
	
	printf("\n");
}

void method_04 (void){
	
	int row = 0; int col =0;
	
	//identificar
	printf("\nmethod_04 - programa 0914");
	
	printf("\n");
	ler_dimensoes_matriz_teclado(&row, &col);
	
	printf("\nlinhas = %d", row);
	printf("\ncolunas = %d", col);
	
	printf("\n");
	double matrix[row][col];
	
	read_double_matrix_negatives(row, col, matrix);
	
	printf("\n");
	print_double_matrix(row, col, matrix);
	
	if(row == col){
		
		mostrar_diagonal_secundaria(col, matrix);
		
	}else{
		
		printf("\n\na matriz nao eh quadrada");
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}





//>>>>>>>>>> method_05 - programa 0915 <<<<<<<<<<

void mostrar_triangulo_abaixo_diagpri(int n, double matrix[][n]) {
	
	printf("\n\nvalores na diagonal principal e abaixo:\n");
	
	// Percorre a diagonal principal
	for (int i = 0; i < n; i++) {
		
		for(int j = 0; j<=i; j++){
			
			printf("%lf ", matrix[i][j]);
			
		}
		
		printf("\n");
		
	}
	
}

void method_05 (void){
	
	int row = 0; int col =0;
	
	//identificar
	printf("\nmethod_05 - programa 0915");
	
	printf("\n");
	ler_dimensoes_matriz_teclado(&row, &col);
	
	printf("\nlinhas = %d", row);
	printf("\ncolunas = %d", col);
	
	printf("\n");
	double matrix[row][col];
	
	read_double_matrix_negatives(row, col, matrix);
	
	printf("\n");
	print_double_matrix(row, col, matrix);
	
	if(row == col){
		
		mostrar_triangulo_abaixo_diagpri(col, matrix);
		
	}else{
		
		printf("\n\na matriz nao eh quadrada");
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}





//>>>>>>>>>> method_06 - programa 0916 <<<<<<<<<<

void read_double_matrix (int rows, int columns, double matrix[][columns]){
	
	int x = 0; int y = 0; double z = 0;
	
	for(x=0; x<rows; x++){
		
		while(y<columns){
			
			printf("\n%d , %d : ", x, y);
			scanf("%lf", &z); getchar();
			
			//guardar valor
			matrix[x][y] = z;
			
			y++;
			
		}
		
		y=0;
		
	}
	
}

void mostrar_triangulo_acima_diagpri(int n, double matrix[][n]) {
	
	printf("\n\nvalores na diagonal principal e acima:\n");
	
	// Percorre a diagonal principal
	for (int i = 0; i < n; i++) {
		
		for(int j = i; j<n; j++){
			
			printf("%lf ", matrix[i][j]);
			
		}
		
		printf("\n");
		
	}
	
}

void method_06 (void){
	
	int row = 0; int col =0;
	
	//identificar
	printf("\nmethod_06 - programa 0916");
	
	printf("\n");
	ler_dimensoes_matriz_teclado(&row, &col);
	
	printf("\nlinhas = %d", row);
	printf("\ncolunas = %d", col);
	
	printf("\n");
	double matrix[row][col];
	
	read_double_matrix(row, col, matrix);
	
	printf("\n");
	print_double_matrix(row, col, matrix);
	
	if(row == col){
		
		mostrar_triangulo_acima_diagpri(col, matrix);
		
	}else{
		
		printf("\n\na matriz nao eh quadrada");
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}





//>>>>>>>>>> method_07 - programa 0917 <<<<<<<<<<

void mostrar_triangulo_abaixo_diagsec(int n, double matrix[][n]) {
	
	printf("\n\nvalores na diagonal secundaria e abaixo:\n");
	
	for (int i = 0; i < n; i++) {
		
		for(int j = n-1; j>=(n-i-1); j--){
			
			printf("%lf ", matrix[i][j]);
			
		}
		
		printf("\n");
		
	}
	
}

void method_07 (void){
	
	int row = 0; int col =0;
	
	//identificar
	printf("\nmethod_07 - programa 0917");
	
	printf("\n");
	ler_dimensoes_matriz_teclado(&row, &col);
	
	printf("\nlinhas = %d", row);
	printf("\ncolunas = %d", col);
	
	printf("\n");
	double matrix[row][col];
	
	read_double_matrix(row, col, matrix);
	
	printf("\n");
	print_double_matrix(row, col, matrix);
	
	if(row == col){
		
		mostrar_triangulo_abaixo_diagsec(col, matrix);
		
	}else{
		
		printf("\n\na matriz nao eh quadrada");
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}





//>>>>>>>>>> method_08 - programa 0918 <<<<<<<<<<

void mostrar_triangulo_acima_diagsec(int n, double matrix[][n]) {
	
	printf("\n\nvalores na diagonal secundaria e acima:\n");
	
	for (int i = 0; i < n; i++) {
		
		for(int j = 0; j<=(n-i-1); j++){
			
			printf("%lf ", matrix[i][j]);
			
		}
		
		printf("\n");
		
	}
	
}

void method_08 (void){

	int row = 0; int col =0;
	
	//identificar
	printf("\nmethod_08 - programa 0918");
	
	printf("\n");
	ler_dimensoes_matriz_teclado(&row, &col);
	
	printf("\nlinhas = %d", row);
	printf("\ncolunas = %d", col);
	
	printf("\n");
	double matrix[row][col];
	
	read_double_matrix(row, col, matrix);
	
	printf("\n");
	print_double_matrix(row, col, matrix);
	
	if(row == col){
		
		mostrar_triangulo_acima_diagsec(col, matrix);
		
	}else{
		
		printf("\n\na matriz nao eh quadrada");
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}





//>>>>>>>>>> method_09 - programa 0919 <<<<<<<<<<

bool zeros_abaixo_diagpri(int n, double matrix[][n]) {
	
	printf("\n\nvalores abaixo da diagonal principal:\n");
	
	bool is_zero = true;
	
	// Percorre a diagonal principal
	for (int i = 0; i < n; i++) {
		
		//ao retirar a condicao menor OU IGUAL a i, nao lemos mais os números de fato na diagonal
		//apenas aqueles ABAIXO dela
		
		for(int j = 0; j<i; j++){
			
			printf("%lf ", matrix[i][j]);
			
			if(matrix[i][j]!=0){
				
				is_zero = false;
				
			}
			
		}
		
		printf("\n");
		
	}
	
	return (is_zero);
	//se todos os valores forem zero, retorna true
	//se tiver algum valor diferente de zero, retorna falso
	
}

void method_09 (void){

	int row = 0; int col = 0;
	bool result;
	
	//identificar
	printf("\nmethod_09 - programa 0919");
	
	printf("\n");
	ler_dimensoes_matriz_teclado(&row, &col);
	
	printf("\nlinhas = %d", row);
	printf("\ncolunas = %d", col);
	
	printf("\n");
	double matrix[row][col];
	
	read_double_matrix(row, col, matrix);
	
	printf("\n");
	print_double_matrix(row, col, matrix);
	
	if(row == col){
		
		result = zeros_abaixo_diagpri(col, matrix);
		
		if (result){
			
			printf("\n\nSAO todos zeros");
			
		}else{
			
			printf("\n\nNAO sao todos zeros");
			
		}
		
	}else{
		
		printf("\n\na matriz nao eh quadrada");
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}





//>>>>>>>>>> method_10 - programa 0920 <<<<<<<<<<

bool zeros_acima_diagpri(int n, double matrix[][n]) {
	
	bool is_zero = true;
	
	printf("\n\nvalores acima da diagonal principal:\n");
	
	for (int i = 0; i < n; i++) {
		
		for(int j = n-1; j>i; j--){
			
			printf("%lf ", matrix[i][j]);
			
			if(matrix[i][j]!=0){
				
				is_zero = false;
				
			}
			
		}
		
		printf("\n");
		
	}
	
	return (is_zero);
	//se todos os valores forem zero, retorna true
	//se tiver algum valor diferente de zero, retorna falso
	
}

void method_10 (void){

	int row = 0; int col = 0;
	bool result;
	
	//identificar
	printf("\nmethod_10 - programa 0920");
	
	printf("\n");
	ler_dimensoes_matriz_teclado(&row, &col);
	
	printf("\nlinhas = %d", row);
	printf("\ncolunas = %d", col);
	
	printf("\n");
	double matrix[row][col];
	
	read_double_matrix(row, col, matrix);
	
	printf("\n");
	print_double_matrix(row, col, matrix);
	
	if(row == col){
		
		result = zeros_acima_diagpri(col, matrix);
		
		if (result){
			
			printf("\n\nSAO todos zeros");
			
		}else{
			
			printf("\n\nNAO sao todos zeros");
			
		}
		
	}else{
		
		printf("\n\na matriz nao eh quadrada");
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}




int main (int argc, char *argv[]){
	
	//identificar o programa
	printf ("%s", "estudo dirigido 09 - programas_0911_a_0920");
	printf ("\n%s\n%s", "autor: raquel de parde motta", "matricula: 854017");
	
	int opcao = 0;
	
	do{
		//mostrar as opcoes
		printf ("\n\n%s", "digite o numero correspondente a opcao desejada: ");
		printf ("\n\n%s", "0 - encerrar");
		printf ("\n\n%s", "1 - method_01 - programa 0911");
		printf ("\n\n%s", "2 - method_02 - programa 0912");
		printf ("\n\n%s", "3 - method_03 - programa 0913");
		printf ("\n\n%s", "4 - method_04 - programa 0914");
		printf ("\n\n%s", "5 - method_05 - programa 0915");
		printf ("\n\n%s", "6 - method_06 - programa 0916");
		printf ("\n\n%s", "7 - method_07 - programa 0917");
		printf ("\n\n%s", "8 - method_08 - programa 0918");
		printf ("\n\n%s", "9 - method_09 - programa 0919");
		printf ("\n\n%s", "10 - method_10 - programa 0920");
		
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

testes e outputs estao no arquivo "outputs_exercicios_ED09_raquelmotta.txt"


>>>>>>>>>>>>>>>>>>>>>>>>>>>>> notas e comentarios

*/
