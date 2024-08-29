/*
PUC MINAS - AEDs1
Mai/2024

Estudo Dirigido 10

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: exemplos_ed10_raquelmotta
Versao: 0.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <io.h>

//>>>>>>>>>> method_01 <<<<<<<<<<

//definicao de tipo arranjo com inteiros baseado em estrutura
typedef struct s_int_array
{
	int length;
	int* data;
	int ix;
}
int_array;	//nome do tipo


//definicao de referencia para arranjo com inteiros baseado em estrutura
typedef int_array* ref_int_array;

//char_Array* = ref_char_Array
//ao invés de escrever o apontador com asterisco, trocamos esse símbolo pela palavra ref
//o contrário do ref é DEreferenciar, não quero o lugar, mas sim o conteúdo (*coisa)


//reservar espaço para arranjos com inteiros
//@return referencia para arranjo com inteiros
//@param n - quantidade de dados
ref_int_array new_int_array (int n)
{
	//reserva de espaço
	ref_int_array tmp_array =  (ref_int_array)malloc(sizeof(int_array));
	
	//estabelecer valores padroes
	if(tmp_array == NULL){
		
		printf("\nERRO. falta espaco");
		
	}else{
		
		tmp_array->length = 0;
		tmp_array->data = NULL;
		tmp_array->ix = -1;
		
		if(n>0){
			
			//guardar a quantidade de dados
			tmp_array->length = n;
			
			//reservar espaco para os dados
			tmp_array->data = (int*)malloc(n*sizeof(int));
			
			//definir indicador do primeiro elemento
			tmp_array->ix = 0;
			
		}
		
	}
	
	//retornar referencia para espaco reservado
	return(tmp_array);
	
}


//dispensar espaco para arranjo com inteiros
//@param tmp_array - referencia para grupo de valores inteiros
void free_int_array (ref_int_array tmp_array){
	
	//testar se ha dados, antes de reciclar o espaco
	if(tmp_array != NULL){
		
		if(tmp_array->data != NULL){
			
			free (tmp_array->data);
			
		}
		
		free (tmp_array);
		
	}
	
}


//mostrar arranjo com valores inteiros
//@param array - grupo de valores inteiros
void print_int_array (int_array array){
	
	//mostrar valores no arranjo
	if(array.data){
		
		for(array.ix=0; array.ix<array.length; array.ix=array.ix+1){
			
			//mostrar valor
			printf("%2d: %d\n", array.ix, array.data[array.ix]);
			
			
		}
		
	}
	
}


//mostrar certa quantidade de valores
void method_01 (void){
	
	//definir dado 
	int_array array;
	
	//montar arranjo em estrutura
	array.length = 5;
	array.data = (int*)malloc(array.length*sizeof(int));
	
	//testar existencia de dados
	if(array.data){
		
		array.data[0] = 1;
		array.data[1] = 2;
		array.data[2] = 3;
		array.data[3] = 4;
		array.data[4] = 5;
		
	}
	
	//identificar
	printf("\nmethod_01");
	
	//executar metodo auxiliar
	print_int_array(array);
	
	//reciclar o espaço
	if(array.data){
		
		free(array.data);
		
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}
/*
as definições iniciais servirão para especificar um tipo de armazenador composto por vários
tipos de dados, os quais serão usados sempre em conjunto.

um desses dados será a quantidade de valores armazenados; outro, uma referência para onde serão
guardados; e um terceiro para permitir o acesso a cada um desses valores.

dois métodos acompanharão o uso desse novo tipo de armazenador: o que servirá para proceder
a reserva de espaço e estabelecer os valores iniciais (construir a identidade), e o que servirá
para liberar e reciclar o espaço reservado, quando esse não tiver mais utilidade para o programa
*/





//>>>>>>>>>> method_02 <<<<<<<<<<

//ler arranjo com valores inteiros
//@return arranjo com valores lidos
int_array IO_readintArray (){
	
	//definir dados locais
	char* text = (char*)malloc(81*sizeof(char));
	static int_array array;
	
	//ler a qtd de dados
	do{
		
		array.length = IO_readint("\nlength = ");
		
	}while(array.length<=0);
	
	//reservar espaco para armazenar
	array.data = (int*)malloc(array.length*sizeof(int));
	
	//testar se há espaço
	if(array.data == NULL){
		
		array.length = 0;	//não há espaço
		
	}else{
		
		//ler e guardar valores em arranjo
		for(array.ix=0; array.ix<array.length; array.ix=array.ix+1){
			
			//ler valor
			printf("\n%2d : ", array.ix);
			scanf("%d", &array.data[array.ix]); getchar();
			
		}
		
	}
	
	//retornar arranjo
	return(array);
	
}


void method_02 (void){
	
	//definir dados
	int_array array;
	
	//identificar
	printf("\nmethod_02");
	
	//ler dados
	array = IO_readintArray();
	
	//testar a existencia de dados
	if(array.data){
		
		//mostrar dados
		printf("\n");
		print_int_array(array);
		
		//reciclar espaço
		free(array.data);
		
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}
/*
reparar que as definições para uso são mais simples que as outras anteriormente apresentadas.

uma definição estática (static) preservará a existência do dado fora do contexto de declaração.

só poderá ser mostrado o arranjo em que existir algum conteúdo.
(diferente de NULL = inexistência de dados)
*/





//>>>>>>>>>> method_03 <<<<<<<<<<

//gravar arranjo de inteiros em arquivo
//@param fileName - nome do arquivo
void file_print_int_array (char* fileName, int_array array){
	
	FILE* arquivo = fopen(fileName, "wt");
	
	//gravar quantidade de dados
	fprintf(arquivo, "%d\n", array.length);
	
	//gravar valores no arquivo, se existirem
	if(array.data){
		
		for(array.ix=0; array.ix<array.length; array.ix=array.ix+1){
			
			fprintf(arquivo, "%d\n", array.data[array.ix]);
			
		}
		
	}
	
	fclose(arquivo);
}


void method_03 (void){
	
	int_array array;
	
	//identificar
	printf("\nmethod_03");
	
	array = IO_readintArray();
	
	//testar existencia de dados
	if(array.data){
		
		//mostrar e gravar dados
		printf("\n");
		print_int_array(array);
		file_print_int_array("ARRAY1.TXT", array);
		
		//reciclar o espaco
		free(array.data);
		
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}
//se existir dados no arranjo original, eles serao sobrescritos





//>>>>>>>>>> method_04 <<<<<<<<<<

//ler tamanho de arranjo com inteiros em arquivo
//@return qtd de valores lidos
int file_read_array_size (char* fileName){
	
	int n = 0;
	FILE* arquivo = fopen(fileName, "rt");
	
	if(arquivo){
		
		//ler qtd de dados (que está escrita na primeira linha do arquivo)
		fscanf(arquivo, "%d", &n);
		
		if(n<=0){
			
			printf("\nERRO. valor invalido\n");
			
			n = 0;
			
		}
		
		fclose(arquivo);
		
	}
	
	return(n);
	
}

//ler arranjo com inteiros de arquivo
//@return arranjo com os valores lidos
int_array fileO_readintarray (char* fileName){
	
	int x = 0; int y = 0;
	FILE* arquivo = fopen(fileName, "rt");
	static int_array array;
	
	if(arquivo){
		
		//ler a qtd de dados
		fscanf(arquivo, "%d", &array.length);
		
		if(array.length<=0){
			
			printf("\nERRO. valor  invalido\n");
			array.length = 0; 
			
		}else{
			
			//reservar espaço
			array.data = (int*)malloc(array.length*sizeof(int));
			
			if(array.data){
				
				array.ix = 0;
				while(!feof(arquivo) && array.ix<array.length){
					
					fscanf(arquivo, "%d", &(array.data[array.ix]));
					
					array.ix - array.ix + 1;
					
				}
				
			}
			
		}
		
	}
	
	return(array);
	
}


void method_04 (void){
	
	int_array array; //arranjo sem tamanho definido
	
	//identificar
	printf("\nmethod_01");
	
	//ler dados
	array = fileO_readintarray("ARRAY1.TXT");
	
	if(array.data){
		
		printf("\n");
		print_int_array(array);
		
		free(array.data);
		
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}
//só poderá ser guardada a mesma quantidade de dados lida no início do arquivo





//>>>>>>>>>> method_05 <<<<<<<<<<

//copiar arranjo com valores inteiros
//@return referência para cópia do arranjo
ref_int_array copy_int_array (int_array array){
	
	int x = 0; int y = 0;
	ref_int_array copy;
	
	if(array.length<=0){
		
		printf("\nERRO. valor invalido\n");
		array.length = 0;
		
	}else{
		
		copy - new_int_array(array.length);
		
		//testar se há descritor
		if(copy){
			
			copy->length = array.length;
			copy->data = (int*)malloc(copy->length*sizeof(int));
			
			//testar se há espaço e dados
			if(copy->data == NULL || array.data == NULL){
				
				printf("\nERRO. falta espaco ou dadods\n");
				
			}else{
				
				//ler e copiar valores
				for(array.ix=0; array.ix<array.length; array.ix=array.ix+1){
					
					//copiar valor
					copy->data[array.ix] = array.data[array.ix];
					
				}
				
			}
			
			
		}
		
	}
	
	return(copy);
	
}


void method_05 (void){
	
	int_array array; //arranjo sem tamanho definifo
	ref_int_array other; //referencia para arranjo sem tamanho definido
	
	//identificar
	printf("\nmethod_05");
	
	array = fileO_readintarray("ARRAY1.TXT");
	
	other = copy_int_array(array);
	
	if(array.data){
		
		printf("\noriginal:\n");
		print_int_array(array);
		
		
		printf("\n\ncopia:\n");
		print_int_array(*other); //dereferenciar a copia
		
		//reciclar os espaços
		free(array.data);
		free(other->data);
		free(other);
		
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}
//só poderá ser copiada a mesma qtd de dados





//>>>>>>>>>> method_06 <<<<<<<<<<

//definição de tipo arranjo bidimensional com inteiros baseado em estrutura
typedef
struct s_int_matrix
{
	
	int rows;
	int cols;
	int** data;
	int ix, iy;	
	
}
int_matrix;

//definição de referência para arranjo bidimensional com inteiros baseado em estrutura
//typedef int_matrix* ref_int_matrix


//reservar espaço para arranjo bidimensional com inteiros
//@return referência para arranjo com inteiros

int_matrix* new_int_matrix (int rows, int cols){
	
	//reserva de espaço
	int_matrix* tmp_matrix = (int_matrix*)malloc(sizeof(int_matrix));
	
	//estabelecer valores padrões
	if(tmp_matrix != NULL){
		
		tmp_matrix->rows = 0;
		tmp_matrix->cols = 0;
		tmp_matrix->data = NULL;
		
		//reservar espaço
		if(rows>0 && cols>0){
			
			tmp_matrix->rows = rows;
			tmp_matrix->cols = cols;
			tmp_matrix->data = malloc(rows*sizeof(int*));
			
			if(tmp_matrix->data){
				
				for(tmp_matrix->ix=0; tmp_matrix->ix<tmp_matrix->rows; tmp_matrix->ix++){
					
					tmp_matrix->data [tmp_matrix->ix] = (int*)malloc(cols*sizeof(int));
					
				}
				
			}
		}
		
		(*tmp_matrix).ix = 0;
		tmp_matrix->iy = 0;
		
	}
	
	return(tmp_matrix);
	
}


//liberar espaço para arranjo com inteiros
void free_int_matrix (int_matrix* matrix){
	
	if(matrix != NULL){
		
		if(matrix->data != NULL){
			
			for(matrix->ix=0; matrix->ix<matrix->rows; matrix->ix++){
				
				free(matrix->data[matrix->ix]);
				
			}
			
			free(matrix->data);
			
		}
		
		free(matrix);
		
	}
	
}


//imprimir matriz com valores inteiros
void print_int_matrix (int_matrix* matrix){
	
	if(matrix != NULL && matrix->data != NULL){
		
		//mostrar valores na matriz
		
		for(matrix->ix=0; matrix->ix<matrix->rows; matrix->ix++){
			
			for(matrix->iy=0; matrix->iy<matrix->cols; matrix->iy++){
				
				//mostrar valor
				printf("%3d\t", matrix->data[matrix->ix][matrix->iy]);
				
			}
			
			printf("\n");
			
		}
		
	}
	
}


void method_06 (void){
	
	int_matrix* matrix = new_int_matrix(3,3);
	
	if(matrix!=NULL && matrix->data!=NULL){
		
		matrix->data[0][0] = 1;	matrix->data[0][1] = 2;	matrix->data[0][2] = 3;
		matrix->data[1][0] = 3;	matrix->data[1][1] = 4;	matrix->data[1][2] = 5;
		matrix->data[2][0] = 6;	matrix->data[2][1] = 7;	matrix->data[2][2] = 8;
		
	}
	
	//identificar
	printf("\nmethod_06");
	
	//executar o método auxiliar
	print_int_matrix(matrix);
	
	//reciclar espaço
	free_int_matrix(matrix);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}
/*
as definições iniciais servirão para especificar um tipo de armazenador composto por vários
tipos de dados, os quais serão usados sempre em conjunto, tal como nos arranjos unidimensionais.

dentre esses dados estarão a quantidade de linhas e de colunas; uma referência para onde serão
guardados; e facilitadores para o acesso.

dois métodos acompanharão o uso desse novo tipo de armazenador: o que servirá para proceder
a reserva de espaço e estabelecer os valores iniciais (construir a identidade), e o que servirá
para liberar e reciclar o espaço reservado, quando esse não tiver mais utilidade para o programa.

destaca-se a necessidade de se lidar individualmente com cada linha de dados.

diferente do exemplo com arranjo unidimensional, destaca-se aqui também o uso da referência,
a necessidade da reserva de espaço e a liberação de seu uso para a reciclagem
*/





//>>>>>>>>>> method_07 <<<<<<<<<<

//ler arranjo bidimensional com valores inteiros
//@return referência para o grupo de valores inteiros
int_matrix* read_int_matrix(){
	
	int rows = 0; int cols = 0; int x = 0;
	
	//ler a quantidade de dados
	do{
		
		printf("\nrows = ");
		scanf("%d", &x); getchar();
		
		rows = x;
		
	}while(rows<=0);
	
	do{
		
		printf("\ncolumns = ");
		scanf("%d", &x); getchar();
		
		cols = x;
		
	}while(cols<=0);
	
	//reservar espaço para armazenar valores
	int_matrix* matrix = new_int_matrix(rows, cols);
	
	//testar se há espaço
	if(matrix != NULL){
		
		if(matrix->data == NULL){
			
			//não há espaço
			matrix->rows = 0;
			matrix->cols = 0;
			matrix->ix = 0;
			matrix->iy=0;
			
		}else{
			
			//ler e guardar valores na matriz
			for(matrix->ix = 0; matrix->ix < matrix->rows;  matrix->ix = matrix->ix+1){
				
				for(matrix->iy = 0; matrix->iy < matrix->cols;  matrix->iy = matrix->iy+1){
					
					//ler e guardar valor
					printf("%d, %d = ", matrix->ix, matrix->iy);
					scanf("%d", &x); getchar();
					matrix->data[matrix->ix][matrix->iy] = x;
				}
				
				printf("\n");
				
			}
			
		}
		
	}
	
	return (matrix);
	
}


void method_07 (void){
	
	int_matrix* matrix = NULL;
	
	//identificar
	printf("\nmethod_07");
	
	matrix = read_int_matrix();
	
	//mostrar dados
	printf("\n");
	print_int_matrix(matrix);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}
//diferente do exemplo com arranjo unidimensional, destaca-se aqui o uso da referência





//>>>>>>>>>> method_08 <<<<<<<<<<

//gravar em arquivo arranjo bidimensional com valores inteiros
void file_print_int_matrix (char* fileName, int_matrix* matrix){
	
	FILE* arquivo = fopen (fileName, "wt");
	
	if (matrix == NULL){
		
		printf("\nERRO. nao ha dados");
		
	}else{
		
		//gravar quantidade de dados nas primeiras linhas do arquivo
		fprintf(arquivo, "%d\n", matrix->rows);
		fprintf(arquivo, "%d\n", matrix->cols);
		
		if(matrix->data != NULL){
			
			//gravar valores no arquivo
			for(matrix->ix = 0; matrix->ix < matrix->rows;  matrix->ix = matrix->ix+1){
				
				for(matrix->iy = 0; matrix->iy < matrix->cols;  matrix->iy = matrix->iy+1){
					
					//gravar valor, um por linha
					fprintf(arquivo, "%d\n", matrix->data[matrix->ix][matrix->iy]);
				}
				
			}
			
		}
		
		fclose(arquivo);
		
	}
	
}


void method_08 (void){
	
	int_matrix* matrix = NULL;
	
	//identificar
	printf("\nmethod_08");
	
	//ler dados
	matrix = read_int_matrix();
	
	//gravar dados
	file_print_int_matrix("MATRIX1.TXT", matrix);
	
	//reciclar espaço
	free_int_matrix(matrix);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}
//só poderão ser operados arranjos com a mesma quantidade de dados





//>>>>>>>>>> method_09 <<<<<<<<<<

//ler dados de arquivo para armazenar em matriz
//@return referência para grupo de valores inteiros
int_matrix* file_read_int_matrix (char* fileName){
	
	int_matrix* matrix = NULL;
	int rows = 0;
	int cols = 0;
	FILE* arquivo  = fopen(fileName, "rt");
	
	//ler a qtd de dados impressa anteriormente nas primeiras duas linhas do arquivo
	fscanf(arquivo, "%d", &rows);
	fscanf(arquivo, "%d", &cols);
	
	if(rows<=0 || cols<=0){
		
		printf("ERRO. valor invalido");
		
	}else{
		
		//reservar espaço para armazenar
		matrix = new_int_matrix(rows, cols);
		
		//testar se há espaço
		if (matrix!=NULL && matrix->data == NULL){
			
			//não há espaço
			matrix->rows = 0;
			matrix->cols = 0;
			matrix->ix = 0;
			matrix->iy=0;
			
		}else{
			
			//testar a existencia
			if(matrix!=NULL){
				
				//ler e guardar valores na matrix
				matrix->ix = 0;
				
				while(!feof(arquivo) && matrix->ix < matrix->rows){
					
					matrix->iy = 0;
					
					while(!feof(arquivo) && matrix->iy < matrix->cols){
						
						//guardar valor
						fscanf(arquivo, "%d", &(matrix->data[matrix->ix][matrix->iy]));
						
						//passar ao próximo
						matrix->iy = matrix->iy + 1;
						
					}
					
					//passar ao próximo
					matrix->ix = matrix->ix + 1;
					
				}
				
				matrix->ix = 0;
				matrix->iy = 0;
				
			}
			
		}
		
	}
	
	//retornar referencia para matriz lida
	return(matrix);
	
}


void method_09 (void){
	
	//identificar
	printf("\nmethod_09");
	
	//ler dados
	int_matrix* matrix = file_read_int_matrix("MATRIX1.TXT");
	
	//mostrar dados
	printf("\n");
	print_int_matrix(matrix);
	
	//reciclar espaço
	free_int_matrix(matrix);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}
//a leitura de dados foi utilizada na definição da referência para o armazenamento





//>>>>>>>>>> method_10 <<<<<<<<<<

//copiar matriz com valores inteiros
int_matrix* copy_int_matrix (int_matrix* matrix){
	
	//definir dados locais
	int_matrix* copy = NULL;
	
	if(matrix == NULL || matrix->data == NULL){
		
		printf("ERRO. faltam dados\n");
		
	}else{
		
		if(matrix->rows <= 0 || matrix->cols <=0){
			
			printf("ERRO. valor invalido\n");
			
		}else{
			
			//reservar espaço
			copy = new_int_matrix(matrix->rows, matrix->cols);
			
			//testar se há espaço e dados
			if(copy == NULL || copy->data == NULL){
				
				printf("ERRO. falta espaco");
				
			}else{
				
				//copiar valores
				for(copy->ix = 0; copy->ix < copy->rows;  copy->ix = copy->ix+1){
					
					for(copy->iy = 0; copy->iy < copy->cols;  copy->iy = copy->iy+1){
						
						copy->data[copy->ix][copy->iy] = matrix->data[copy->ix][copy->iy];
					}
					
				}
				
				
			}
			
		}
		
	}
	
	//retornar cópia
	return (copy);
	
}


void method_10 (void){
	
	int_matrix* matrix = NULL;
	int_matrix* other = NULL;
	
	//identificar
	printf("\nmethod_10");
	
	//ler dados
	matrix = file_read_int_matrix("MATRIX1.TXT");
	
	//copiar dados
	other = copy_int_matrix(matrix);
	
	//mostrar dados
	printf("\n\noriginal:\n");
	print_int_matrix(matrix);
	
	printf("\n\ncopia:\n");
	print_int_matrix(other);
	
	//reciclar espaço
	free_int_matrix(matrix);
	free_int_matrix(other);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}




int main (int argc, char *argv[]){
	
	//identificar o programa
	printf ("%s", "estudo dirigido 08 - exemplos");
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
