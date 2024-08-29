/*
PUC MINAS - AEDs1
Abr/2024

Estudo Dirigido 08

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: exemplos_ed08_raquelmotta
Versao: 0.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <io.h>

//>>>>>>>>>> method_01 <<<<<<<<<<
//mostrar arranjo com valores inteiros
//@param n - quantidade de valores
//@param array - grupo de valores inteiros

void print_int_array (int n, int array[]){
	
	//definir dado local
	int x = 0;
	
	//mostrar valores no arranho
	for(x=0; x<n; x++){
		
		//mostrar valor
		printf("%2d: %d\n", x, array[x]);
		
	}
	
}
/* %2d: Indica que o valor de x será impresso com pelo menos 2 dígitos, preenchendo com espaços
em branco à esquerda, se necessário. Isso é útil para alinhar visualmente os números em uma
coluna, garantindo que ocupem o mesmo espaço na tela, facilitando a leitura dos dados.*/

void method_01 (void){
	
	//definir dado
	int array[] = {1, 2, 3, 4, 5};
	
	//identificar
	printf("\nmethod_01\n\n");
	
	print_int_array(5, array);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}
//a atribuicao direta de todos os valores ao arranjo só é permitida no momento de sua definicao





//>>>>>>>>>> method_02 <<<<<<<<<<
//ler arranjo com valores inteiros
//@param n - quantidade de valores
//@param array - grupo de valores inteiros
//obs.: o array não termina com '\0', apenas a string.

void read_int_array (int n, int array[]){
	
	int x = 0;
	int y = 0;
	char* text = IO_new_chars(STR_SIZE);
	
	//ler e guardar valores em arranjo
	
	for (x=0; x<n; x=x+1){
		
		strcpy(text, STR_EMPTY);
		
		y = IO_readint(IO_concat(IO_concat(text,IO_toString_d(x)),":")); //????????????
		
		//guardar valor
		array[x] = y;
	}
	
}

/**
  Funcao para reservar espaco para guardar cadeia de caracteres.
  @return area reservada, se houver; NULL, caso contrario
  @param size - quantidade de dados

chars IO_new_chars ( int size )
{
	return ( (chars) malloc ( (size+1)*sizeof(char) ) );
} 
  
const   char STR_EMPTY [] =  "" ;   // definir cadeia de caracteres vazia
  

Funcao para concatenar cadeias de caracteres.
@return cadeia com o resultado
@param text1 - primeira cadeia
@param text2 - segunda  cadeia

chars IO_concat ( const char * const text1, const char * const text2 )
{                               // reservar area
	chars buffer = IO_new_chars ( strlen(text1)+strlen(text2)+1 );
	strcpy ( buffer, text1 );
	strcat ( buffer, text2 );
	return ( buffer );
}
*/

void method_02 (void){
	
	int n = 5;
	int array[n];
	
	//identificar
	printf("\nmethod_02\n\n");
	
	read_int_array(n, array);
	
	printf("\n");
	print_int_array(n, array);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}
//só poderá ser mostrado o arranjo que existir algum conteúdo (diferente de NULL = inexistência de dados)





//>>>>>>>>>> method_03 <<<<<<<<<<
//gravar arranjo com valores inteiros
//@param fileName - nome do arquivo
//@param n - qtd de valores
//@param array - grupo de valores inteiros

void file_print_int_array (char *fileName, int n, int array[]){
	
	FILE *arquivo = fopen (fileName, "wt");
	int x = 0;
	
	fprintf(arquivo, "%d\n", n);
	
	for(x=0; x<n; x++){
		
		fprintf(arquivo, "%d\n", array[x]);
		
	}
	
	fclose(arquivo);
	
}



void method_03 (void){
	
	int n = 5;
	int array[n];
	
	//identificar
	printf("\nmethod_03\n\n");
	
	read_int_array(n, array);
	
	printf("\n");
	file_print_int_array("ARRAY1.TXT", n, array);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}
//se existir dados no arranjo original, eles serão sobrescritos





//>>>>>>>>>> method_04 <<<<<<<<<<
//ler tamanho do arranjo com valores inteiros
//@return qtd de valores lidos

int file_read_array_size (char *fileName){
	
	int n = 0;
	FILE *arquivo = fopen(fileName, "rt");
	
	fscanf(arquivo, "%d", &n);
	
	if(n<=0){
		
		printf("%s\n", "ERRO. valor invalido");
		
		n = 0;
		
	}
	
	return (n);
	
}
/**
  Metodo para mostrar uma linha com certo texto
  e mudar de linha.
  @param text - texto a ser exibido

void IO_println ( const char * const text )
{
	IO_printf ( "%s\n", text );
//  puts ( text ); putchar ( '\n' );
} 
*/

//ler arranjo com valores inteiros
//@param fileName - nome do arquivo
//@param n - quantidade de valores
//@param array - grupo de valores inteiros 

void file_read_int_array (char *fileName, int n, int array[]){
	
	int x = 0;
	int y = 0;
	FILE *arquivo = fopen (fileName, "rt");
	
	fscanf(arquivo, "%d", &x);
	
	if (n<=0 || n>x){
		
		printf("%s\n", "ERRO. valor invalido");
		
	}else{
		
		x = 0;
		
		while(!feof(arquivo) && x<n){
			
			fscanf(arquivo, "%d", &y);
			
			array[x] = y;
			
			x++;
		}
		
	}
	
}
/*
feof() returns true if an attempt has been made to read past the end of the file. 
It does not indicate whether the next read operation will reach the end of the file or not. 
So, when you use feof() as the loop condition with fscanf(), the loop may terminate prematurely,
causing the last line to be missed.

Loop Termination: The loop terminates only after fscanf() tries to read beyond the end of 
the file and fails. At this point, feof() returns true, and the loop exits. This means that 
the last successful read operation might not be processed.

File Position: feof() doesn't check the end-of-file condition until after a read operation 
has failed. So, when fscanf() reaches the end of the file, it doesn't know it's at the end 
until it tries to read past it.
*/

void method_04 (void){
	
	int n = 0;
	
	//identificar
	printf("\nmethod_04\n\n");
	
	n = file_read_array_size("ARRAY1.TXT");
	
	if(n<=0){
		printf("\nERRO. valor invalido");
	}else{
		
		//definir armazenador
		int array[n];
		
		file_read_int_array("ARRAY1.TXT", n, array);
		
		printf("\n");
		
		print_int_array(n, array);
		
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}
//só poderá ser guardada a mesma qtd de dados lida no início do arquivo, se houver



//>>>>>>>>>> method_05 <<<<<<<<<<
//copiar dados de um arranjo com inteiros para outro
//@param n - qtd de valores
//@param copy - cópia do grupo de valores inteiros
//@param array - grupo de valores inteiros

void copy_int_array (int n, int copy[], int array[]){
	
	int x = 0;
	int y = 0;
	
	if(n<=0){
		
		printf("\nERRO. valor invalido");
		n = 0;
		
	}else{
		
		//copiar valores em arranjo
		for(x=0; x<n; x++){
			
			copy[x]=array[x];
			
		}
		
	}
	
}



void method_05 (void){
	
	int n = 0;
	
	//identificar
	printf("\nmethod_05\n\n");
	
	//ler a qtd de dados
	n = file_read_array_size("ARRAY1.TXT");
	
	if(n<=0){
		
		printf("\nERRO. valor invalido");
		
	}else{
		
		//definir armazenador
		int array[n];
		int other[n];
		
		//ler dados
		file_read_int_array("ARRAY1.TXT", n, array);
		
		//copiar dados
		copy_int_array(n, other, array);
		
		//mostrar dados
		printf("\noriginal:\n");
		print_int_array(n, array);
		
		printf("\ncopia:\n");
		print_int_array(n, other);
		
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





//>>>>>>>>>> method_06 <<<<<<<<<<
//somar valores em arranjo com inteiros
//@return - soma dos valores
//@param n - qtd de valores
//@param array - grupo de valores inteiros

int sum_int_array (int n, int array[]){

	int soma = 0;
	int x = 0;
	
	//mostrar valores no arranjo
	for(x=0; x<n; x++){
		
		soma = soma + array[x];
		
	}
	
	return(soma);
}



void method_06 (void){
	
	int n = 0;
	
	//identificar
	printf("\nmethod_06\n\n");
	
	n = file_read_array_size("ARRAY1.TXT");
	
	if(n<=0){
		
		printf("\nERRO. valor invalido");
		
	}else{
		
		int array[n];
		
		file_read_int_array("ARRAY1.TXT", n, array);
		
		printf("\nsoma = %d\n", sum_int_array(n, array));
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





//>>>>>>>>>> method_07 <<<<<<<<<<
//testar valores inteiros em arranjo e dizer se sao todos iguais a 0
//@return TRUE se todos os dados forem iguais a zero. FALSE caso contrario

bool is_all_zeros (int n, int array[]){
	
	bool result = true;
	int x = 0;
	
	while(x<n && result){
		
		//testar valor
		result = result && (array[x]==0);
		
		x++;
		
	}
	
	return(result);
	
}



void method_07 (void){
	
	int n = 5;
	int a1[] = {0, 0, 0, 0, 0};
	int a2[] = {1, 2, 3, 4, 5};
	int a3[] = {11, 12, 0, 40, 50};
	
	//identificar
	printf("\nmethod_07\n\n");
	
	printf("\n\narray1: ");
	print_int_array(n, a1);
	printf("\n\nis_all_zeros (a1) = %d", is_all_zeros(n, a1));
	
	printf("\n\narray2: ");
	print_int_array(n, a2);
	printf("\n\nis_all_zeros (a2) = %d", is_all_zeros(n, a2));
	
	printf("\n\narray3: ");
	print_int_array(n, a3);
	printf("\n\nis_all_zeros (a3) = %d", is_all_zeros(n, a3));
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}
//só deverá ser verificado o arranjo que possuir dados (n ser vazio)





//>>>>>>>>>> method_08 <<<<<<<<<<
//somar inteiros em 2 arranjos, posicao por posicao
//@return - arranjo com a soma resultante
//@param n - qtd de valores
//@param a3 - soma de grupo de valores inteiros
//@param a1 - grupo de valores inteiros 1
//@param a2 - grupo de valores inteiros 2
//@param k - constante para multiplicar o segundo arranjo

void add_int_array (int n, int a3[], int a1[], int k, int a2[]){
	
	int x = 0;
	
	for(x=0; x<n; x++){
		
		a3[x] = a1[x] + k * a2[x];
		
	}
	
}



void method_08 (void){
	
	int n = 0;
	
	//identificar
	printf("\nmethod_08\n\n");
	
	n = file_read_array_size("ARRAY1.TXT");
	
	
	if(n<=0){
		
		printf("\nERRO. valor invalido");
		
	}else{
		
		int array [n];
		int other [n];
		int sum [n];
		
		file_read_int_array("ARRAY1.TXT", n, array);
		
		copy_int_array(n, other, array);
		
		printf("\noriginal:\n");
		print_int_array(n, array);
		
		printf("\ncopia:\n");
		print_int_array(n, other);
		
		add_int_array(n, sum, array, (-2), other);
		
		printf("\nsoma = \n");
		print_int_array(n, sum);
		
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}
//só poderão ser operados arranjos com a mesma qtd de dados





//>>>>>>>>>> method_09 <<<<<<<<<<
//testar se 2 arranjos com inteiros sao iguais, posicao por posicao
//@return TRUE se todos os dados forem iguais. FALSE caso contrario

bool is_equal (int n, int a1[], int a2[]){
	
	bool result = true;
	int x = 0;
	
	while (x<n && result){
		
		result = result && (a1[x] == a2[x]);
		
		x++;
		
	}
	
	return(result);
	
}



void method_09 (void){
	
	int n = 0;
	
	//identificar
	printf("\nmethod_09\n\n");
	
	n = file_read_array_size("ARRAY1.TXT");
	
	
	if(n<=0){
		
		printf("\nERRO. valor invalido");
		
	}else{
		
		int array[n];
		int other[n];
		
		file_read_int_array("ARRAY1.TXT", n, array);
		
		copy_int_array(n, other, array);
		
		printf("\noriginal:\n");
		print_int_array(n, array);
		
		printf("\ncopia:\n");
		print_int_array(n, other);
		
		printf("\niguais = %d\n", is_equal(n, array, other));
		
		//modificar um valor
		other[0] = (-1)*other[0];
		
		printf("\ncopia alterada:\n");
		print_int_array(n, other);
		
		printf("\niguais = %d\n", is_equal(n, array, other));
		
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}
//só poderão ser operados arranjos com a mesma qtd de dados





//>>>>>>>>>> method_10 <<<<<<<<<<
//procurar certo valor em arranjo
//@return TRUE se encontrar. FALSE caso contrario
//@param value - valor a ser encontrado


bool search_array (int value, int n, int array[]){
	
	bool result = false;
	int x = 0;
	
	while(x<n && !result){
		
		result = (value == array[x]);
		
		x++;
		
	}
	
	return(result);
	
}

void method_10 (void){
	
	int n = 0;
	int value = 0;
	
	//identificar
	printf("\nmethod_10\n\n");
	
	n = file_read_array_size("ARRAY1.TXT");
	
	if(n<=0){
		
		printf("\nERRO. valor invalido");
		
	}else{
		
		int array[n];
		
		file_read_int_array("ARRAY1.TXT", n, array);
		
		printf("\noriginal:\n");
		print_int_array(n, array);
		
		value = array[0];
		printf("\nprocurar por (%d) = %d\n", value, search_array(value, n, array));
		
		value = array[n/2];
		printf("\nprocurar por (%d) = %d\n", value, search_array(value, n, array));
		
		value = array[n-1];
		printf("\nprocurar por (%d) = %d\n", value, search_array(value, n, array));
		
		value = (-1);
		printf("\nprocurar por (%d) = %d\n", value, search_array(value, n, array));
	}
	
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
