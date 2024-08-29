/*
PUC MINAS - AEDs1
Abr/2024

Estudo Dirigido 09

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: exemplos_ed09_raquelmotta
Versao: 0.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <io.h>

//>>>>>>>>>> method_01 <<<<<<<<<<
//mostrar arranjo bidimensional com valores inteiros
//@param rows - qtd de linhas
//@param columns - qtd de colunas
//@param matrix - grupo de valores inteiros

void print_int_matrix (int rows,  int columns, int matrix[][columns]){
	
	int x = 0; int y = 0;
	
	//mostrar valores na matriz
	for (x=0; x<rows; x++){
		
		for(y=0; y<columns; y++){
			
			printf("%3d\t", matrix[x][y]);
			
		}
		
		printf("\n");
	}
	
}


void method_01 (void){
	
	int matrix[][3]={
		
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
		
	};
	
	//identificar
	printf("\nmethod_01\n");
	
	print_int_matrix(3, 3, matrix);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}
//a atribuicao direta de todos os valores à matriz só é permitida quando da 
//sua definicao.
//a ordem dos parâmetros recomendada deve trazer a quantidade de linhas e colunas
//antes do armazenador da matriz, e a qtd de colunas deve ser indicada





//>>>>>>>>>> method_02 <<<<<<<<<<
//ler arranjo bidimensional com valores inteiros

void read_int_matrix (int rows, int columns, int matrix[][columns]){
	
	int x = 0; int y = 0; int z = 0;
	
	//char *text = (char*)malloc(81);
	
	for(x=0; x<rows; x++){
		
		for(y=0; y<columns; y++){
			
			//strcpy(text, STR_EMPTY);
			
			//z = IO_readint ( IO_concat (IO_concat ( IO_concat ( text, IO_toString_d ( x ) ), ", " ),IO_concat ( IO_concat ( text, IO_toString_d ( y ) ), " : " ) ) );
			
			printf("\n%d , %d : ", x, y);
			scanf("%d", &z); getchar();
			
			//guardar valor
			matrix[x][y] = z;
			
		}
		
	}
	
}
//const   char STR_EMPTY [] =  "" ;   // definir cadeia de caracteres vazia

/*
Funcao para ler valor inteiro do teclado.
@return valor lido
@param  text - mensagem a ser exibida antes da leitura

int IO_readint ( const char * const text )
{
int x = 0;
if ( IO_trace )
	IO_printf ( "%s", text   );
IO_scanf  ( "%d", &x );
IO_flush  ( );
return    ( x );
} 
*/

/*
IO_toString_d = Funcao para converter inteiro para caracteres.
@return cadeia com o resultado
@param x     - valor inteiro
*/


void method_02 (void){
	
	int n = 2;
	int matrix[n][n];
	
	//identificar
	printf("\nmethod_02");
	
	//ler dados
	printf("\n");
	read_int_matrix(n, n, matrix);
	
	//mostrar dados
	printf("\n");
	print_int_matrix(n, n, matrix);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}
//só poderá ser mostrada a matriz em que existir algum conteúdo
//(diferente de NULL = inexistência de dados)





//>>>>>>>>>> method_03 <<<<<<<<<<
//gravar em arquivo arranjo bidimensional com valores inteiros

void file_print_int_matrix (char* fileName, int rows, int columns, int matrix[][columns]){
	
	FILE *arquivo = fopen(fileName, "wt");
	int x = 0; int y = 0;
	
	//gravar qtd de dados
	fprintf(arquivo, "%d\n", rows);
	fprintf(arquivo, "%d\n", columns);
	
	//gravar valores no arquivo
	
	for(x=0; x<rows; x++){
		
		for(y=0; y<columns; y++){
			
			fprintf(arquivo, "%d\n", matrix[x][y]);
			
		}
		
	}
	
	fclose(arquivo);
	
}
//a linha e a coluna podem mudar, mas a QUANTIDADE de colunas n pode mudar


void method_03 (void){
	
	int rows = 0;
	int columns = 0;
	
	//identificar
	printf("\nmethod_03\n");
	
	printf("\nrows = ");
	scanf("%d", &rows); getchar();
	
	printf("\ncolumns = ");
	scanf("%d", &columns); getchar();
	
	printf("\n");
	
	if (rows<=0 || columns <= 0){
		
		printf("\n\nERRO. valor invalido");
		
	}else{
		
		//reservar espaço
		int matrix[rows][columns];
		
		read_int_matrix(rows, columns, matrix);
		
		printf("\n");
		print_int_matrix(rows, columns, matrix);
		
		printf("\n");
		file_print_int_matrix("MATRIX1.TXT", rows, columns, matrix);
		
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}
//se existir dados na matriz original, eles serão sobrescritos





//>>>>>>>>>> method_04 <<<<<<<<<<


//ler tamanho (linhas) da matriz com valores inteiros
//@return - qtd de linhas da matriz

int file_read_matrix_rows (char* fileName){
	
	int n = 0;
	FILE* arquivo = fopen(fileName, "rt");
	int* array = NULL;
	
	fscanf(arquivo, "%d", &n);
	
	if(n<=0){
		
		printf("\nERRO. valor invalido");
		n = 0;
		
	}
	
	//retornar dado lido
	return(n);
	
}


//ler tamanho (colunas) da matriz com valores inteiros
//@return - qtd de colunas da matriz

int file_read_matrix_columns (char* fileName){
	
	int n = 0;
	FILE* arquivo = fopen(fileName, "rt");
	
	fscanf(arquivo, "%d", &n);
	fscanf(arquivo, "%d", &n);
	//é pq o número de linhas e de colunas está escrito no início do arquivo
	
	if(n<=0){
		
		printf("\nERRO. valor invalido");
		n = 0;
		
	}
	
	//retornar dado lido
	return(n);
	
}


//ler de arquivo arranjo bidimensional com valores inteiros

void file_read_int_matrix (chars fileName, int rows, int columns, int matrix[][columns]){
	
	int x = 0; int y = 0; int z = 0;
	FILE* arquivo = fopen (fileName, "rt");
	
	fscanf(arquivo, "%d", &x);
	fscanf(arquivo, "%d", &y);
	
	if(rows<=0 || rows > x || columns<= 0 || columns>y){
		
		printf("\nERRO. valor invalido");
		
	}else{
		
		//ler e guardar valores em arranjo
		x = 0;
		
		while(!feof(arquivo) && x<rows){
			
			y = 0;
			
			while(!feof(arquivo) && y<columns){
				
				//ler valor
				fscanf(arquivo, "%d", &z);
				
				//guardar valor
				matrix[x][y] = z;
				
				y = y+1;
				
			}
			
			x = x+1;
			
		}
		
	}
	
	fclose(arquivo);
	
}


void method_04 (void){
	
	int rows = 0; int columns = 0;
	
	//identificar
	printf("\nmethod_04");
	
	rows = file_read_matrix_rows("MATRIX1.TXT");
	columns = file_read_matrix_columns("MATRIX1.TXT");
	
	if (rows<=0 || columns <= 0){
		
		printf("\n\nERRO. valor invalido");
		
	}else{
		
		//definir armazenador
		int matrix[rows][columns];
		
		file_read_int_matrix("MATRIX1.TXT", rows, columns, matrix);
		
		printf("\n");
		print_int_matrix(rows, columns, matrix);
		
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}
//só poderá ser guardada a mesma qtd de dados lida no início do arquivo, se houver





//>>>>>>>>>> method_05 <<<<<<<<<<
//copiar matriz com valores inteiros

void copy_int_matrix (int rows, int columns, int matrix2[][columns], int matrix1[][columns]){
	
	int x = 0; int y = 0;
	
	if (rows<=0 || columns <= 0){
		
		printf("\n\nERRO. valor invalido");
		
	}else{
		
		//copiar valores DA matriz1 PARA a matriz2(destino)
		
		for(x=0; x<rows; x++){
			
			for(y=0; y<columns; y++){
				
				matrix2[x][y] = matrix1[x][y];
				
			}
			
		}
		
	}
	
}


void method_05 (void){
	
	int rows = 0; int columns = 0;
	
	//identificar
	printf("\nmethod_05");
	
	rows = file_read_matrix_rows("MATRIX1.TXT");
	columns = file_read_matrix_columns("MATRIX1.TXT");
	
	if (rows<=0 || columns <= 0){
		
		printf("\n\nERRO. valor invalido");
		
	}else{
		
		int partida[rows][columns];
		int destino[rows][columns];
		
		file_read_int_matrix("MATRIX1.TXT", rows, columns, partida);
		
		copy_int_matrix(rows, columns, destino, partida);
		
		printf("\n\noriginal =\n");
		print_int_matrix(rows, columns, partida);
		
		printf("\n\ncopia =\n");
		print_int_matrix(rows, columns, destino);
		
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}
//só poderá ser copiada a mesma qtd de dados, se houver espaço suficiente





//>>>>>>>>>> method_06 <<<<<<<<<<
//transpor valores inteiros em matriz
//@param matrix2 - grupo de calores inteiros (transposto)
//os rows e columns fornecidos sao da matriz 1

void transpose_int_matrix (int rows, int columns, int matrix2[][rows], int matrix1[][columns]){
	
	int x = 0; int y = 0;
	
	//percorrer a matriz
	for(x=0; x<rows; x++){
		
		for(y=0; y<columns; y++){
			
			matrix2[y][x] = matrix1[x][y];
			
		}
		
	}
	
}

void method_06 (void){
	
	int matrix1[][2] = {
		
		{1, 0},
		{0, 1}
		
	};
	
	int matrix2[][2] = {
		
		{0, 0},
		{0, 0}
		
	};
	
	int matrix3[][3] = {
		
		{1, 2, 3},
		{4, 5, 6}
		
	};
	
	int matrix4[][3] = {
		
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
		
	};
	
	//identificar
	printf("\nmethod_06");
	
	//testando dados
	printf("\n\nmatrix1 = \n");
	print_int_matrix(2, 2, matrix1);
	
	transpose_int_matrix(2, 2, matrix2, matrix1);
	
	printf("\n\nmatrix2 = \n");
	print_int_matrix(2, 2, matrix2);
	
	//testando dados
	printf("\n\nmatrix3 = \n");
	print_int_matrix(2, 3, matrix3);
	
	transpose_int_matrix(2, 3, matrix4, matrix3);
	
	printf("\n\nmatrix4 = \n");
	print_int_matrix(3, 2, matrix4);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}
//as quantidade de linha e coluna estarão trocadas na matriz transposta





//>>>>>>>>>> method_07 <<<<<<<<<<
//testar se matriz identidade
//@return - TRUE, se todos os dados forem iguais a zero (verdadeiros). FALSE, caso contrario
/*
An identity matrix is a square matrix in which all elements of the main 
diagonal (from the top-left to the bottom-right) are equal to 1, 
and all other elements are equal to 0.
*/

bool is_identity (int rows, int columns, int matrix[][columns]){
	
	bool result = false;
	int x = 0; int y = 0;
	
	//testar condicao de existencia
	if(rows<=0 || columns <= 0 || rows != columns){
		
		printf("\nERRO. valor invalido");
		
	}else{
		
		//testar valores na matriz
		x = 0;
		result = true;
		
		while(x<rows && result){
			
			y = 0;
			
			while(y<columns && result){
				
				if (x==y){
					
					result = result && (matrix[x][y] == 1);
					
				}else{
					
					result = result && (matrix[x][y] == 0);
					
				}
				
				y = y + 1;
				
			}
			
			x = x + 1;
			
		}
		
	}
	
	return (result);
	
}
//só deverá ser verificada a matriz que for quadrada (quantidade igual de linhas e colunas)


void method_07 (void){
	
	int matrix1[][2] = {
		
		{0, 0},
		{0, 0}
		
	};
	
	int matrix2[][3] = {
		
		{1, 2, 3},
		{4, 5, 6}
		
	};
	
	int matrix3[][2] = {
		
		{1, 0},
		{0, 1}
		
	};
	
	//identificar
	printf("\nmethod_07");
	
	printf("\n\nmatrix1 = \n");
	print_int_matrix(2, 2, matrix1);
	printf("\nis_identity(matrix1) = %d", is_identity(2, 2, matrix1));
	
	printf("\n\nmatrix2 = \n");
	print_int_matrix(2, 3, matrix2);
	printf("\nis_identity(matrix2) = %d", is_identity(2, 3, matrix2));
	
	printf("\n\nmatrix3 = \n");
	print_int_matrix(2, 2, matrix3);
	printf("\nis_identity(matrix3) = %d", is_identity(2, 2, matrix3));
	
	//1 represents TRUE
	//0 represents FALSE
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





//>>>>>>>>>> method_08 <<<<<<<<<<
//testar se matrizes iguais
//@return - TRUE (1), se todos os dados forem iguais; FALSE (0) caso contrário

bool is_equal (int rows, int columns, int matrix1[][columns], int matrix2[][columns]){
	
	bool result = true;
	int x = 0; int y = 0;
	
	x = 0;
	while(x<rows && result){
		
		y = 0;
		while(y<columns && result){
			
			result = result && (matrix1[x][y] == matrix2[x][y]);
			
			y++;
			
		}
		
		x++;
		
	}
	
	return(result);
	
}
//só poderão ser comparadas matrizes com a mesma quantidade de linhas e colunas


void method_08 (void){
	
	int matrix1[][2] = {
		
		{0, 0},
		{0, 0}
		
	};
	
	int matrix2[][2] = {
		
		{1, 2},
		{3, 4}
		
	};
	
	int matrix3[][2] = {
		
		{1, 0},
		{0, 1}
		
	};
	
	//identificar
	printf("\nmethod_08");
	
	printf("\n\nmatrix1 = \n");
	print_int_matrix(2, 2, matrix1);
	
	printf("\n\nmatrix2 = \n");
	print_int_matrix(2, 2, matrix2);
	
	printf("is_equal(matrix1, matrix2) = %d", is_equal(2, 2, matrix1, matrix2));
	
	copy_int_matrix(2, 2, matrix1, matrix3);
	copy_int_matrix(2, 2, matrix2, matrix3);
	
	printf("\n\nmatrix1 = \n");
	print_int_matrix(2, 2, matrix1);
	
	printf("\n\nmatrix2 = \n");
	print_int_matrix(2, 2, matrix2);
	
	printf("is_equal(matrix1, matrix2) = %d", is_equal(2, 2, matrix1, matrix2));
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}
//i = row
//j = column




//>>>>>>>>>> method_09 <<<<<<<<<<
//somar duas matrizes com inteiros
//@param matrix3 - grupo de valores inteiros resultante
//@param k - constante para multiplicar o segundo termo

void add_int_matrix (int rows, int columns, int matrix3[][columns], int matrix1[][columns], int matrix2[][columns], int k){
	
	int x = 0; int y = 0;
	
	for(x=0; x<rows; x++){
		
		for(y=0; y<columns; y++){
			
			//somar valores
			matrix3[x][y] = matrix1[x][y] + k * matrix2[x][y];
			
		}
		
	}
	
}
//só poderão ser operadas matrizes com mesma quantidade de linhas e colunas


void method_09 (void){
	
	int matrix1[][2] = {
		
		{1, 2},
		{3, 4}
		
	};
	
	int matrix2[][2] = {
		
		{1, 0},
		{0, 1}
		
	};
	
	int matrix3[][2] = {
		
		{0, 0},
		{0, 0}
		
	};
	
	//identificar
	printf("\nmethod_09");
	
	printf("\n\nmatrix1 = \n");
	print_int_matrix(2, 2, matrix1);
	
	printf("\n\nmatrix2 = \n");
	print_int_matrix(2, 2, matrix2);
	
	add_int_matrix(2, 2, matrix3, matrix1, matrix2, (-2));
	
	printf("\n\nmatrix3 (soma) = \n");
	print_int_matrix(2, 2, matrix3);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





//>>>>>>>>>> method_10 <<<<<<<<<<
//calcular o produto de 2 matrizes
/*
Matrix multiplication is an operation that takes two matrices and produces another matrix as a result. 
The number of columns in the first matrix must equal the number of rows in the second matrix for the multiplication to be defined. 
If AAA is an m×n matrix and BBB is an n×p matrix, then the product matrix C=AB will be an m×p matrix.
*/
//param matrix3 - grupo de valores inteiros resultante
//param rows3 - qtd de linhas da matriz(3)
//param cols3 - qtd de colunas da matriz(3)

void mult_int_matrix (int rows3, int cols3, int matrix3[][cols3], int rows1, int cols1, int matrix1[][cols1], int rows2, int cols2, int matrix2[][cols2]){
	
	int x = 0; int y = 0; int z = 0;
	int soma = 0;
	
	if(rows1<=0 || cols1<=0 || rows2<=0 || cols2<=0 || rows3<=0 || cols3<=0 || cols1!=rows2 || rows1!=rows3 || cols2!=cols3){
		
		printf("\nERRO. valor invalido");
		
	}else{
		
		for(x=0; x<rows3; x++){
			
			for(y=0; y<cols3; y++){
				
				soma = 0;
				
				for(z=0; z<cols1; z++){//ou z<rows2
					
					soma = soma + matrix1[x][z] * matrix2[z][y];
					
				}
				
				//guardar soma
				matrix3[x][y] = soma;
				
			}
			
		}
		
	}
	
}
/*
Só poderão ser operadas as matrizes com dimensões compatíveis, ou seja, 
cuja a quantidade de colunas da primeira, for igual à quantidade de linhas da segunda.
A matriz resultante terá a mesma quantidade de linhas da primeira matriz,
e a mesma quantidade de colunas da segunda matriz.
*/


void method_10 (void){
	
	int matrix1[][2] = {
		
		{1, 2},
		{3, 4}
		
	};
	
	int matrix2[][2] = {
		
		{1, 0},
		{0, 1}
		
	};
	
	int matrix3[][2] = {
		
		{0, 0},
		{0, 0}
		
	};
	
	//identificar
	printf("\nmethod_10");
	
	printf("\n\nmatrix1 = \n");
	print_int_matrix(2, 2, matrix1);
	
	printf("\n\nmatrix2 = \n");
	print_int_matrix(2, 2, matrix2);
	
	//multiplicar matrizes
	mult_int_matrix(2, 2, matrix3, 2, 2, matrix1, 2, 2, matrix2);
	printf("\n\nmatrix3 = matrix1 * matrix2\n");
	print_int_matrix(2, 2, matrix3);
	
	//outro teste
	mult_int_matrix(2, 2, matrix3, 2, 2, matrix2, 2, 2, matrix1);
	printf("\n\nmatrix3 = matrix2 * matrix1\n");
	print_int_matrix(2, 2, matrix3);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





int main (int argc, char *argv[]){
	
	//identificar o programa
	printf ("%s", "estudo dirigido 09 - exemplos");
	printf ("\n%s\n%s", "autor: raquel de parde motta", "matricula: 854017");
	
	int opcao = 0;
	
	do{
		//mostrar as opcoes
		printf ("\n\n%s", "digite o numero correspondente a opcao desejada: ");
		printf ("\n\n%s", "0 - encerrar");
		printf ("\n\n%s", "1 - method_01");
		printf ("\n\n%s", "2 - method_02");
		printf ("\n\n%s", "3 - method_03");
		printf ("\n\n%s", "4 - method_04");
		printf ("\n\n%s", "5 - method_05");
		printf ("\n\n%s", "6 - method_06");
		printf ("\n\n%s", "7 - method_07");
		printf ("\n\n%s", "8 - method_08");
		printf ("\n\n%s", "9 - method_09");
		printf ("\n\n%s", "10 - method_10");
		
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
