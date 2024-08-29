/*
PUC MINAS - AEDs1
Mar/2024

Estudo Dirigido 05

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: programas_0511_a_0520
Versao: 0.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

//>>>>>>>>>> method_01 - programa 0511 <<<<<<<<<<
//ler uma quantidade inteira (n) do teclado e, mediante um procedimento,
//mostrar essa quantidade em valores múltiplos de 6 em ordem crescente.

int ler_quant (void){
	
	int n = 0;
	
	do{
		printf("\n\ninsira um numero inteiro:  ");
		scanf("%d", &n);
		getchar();
	}while(n<=0);
	
	return (n);
}

void method_01 (void){
	
	int quantidade = 0;
	
	int base = 6;
	
	int multiplicador = 1;
	
	//identificar
	printf("\nmethod_01 - programa 0511");
	
	quantidade = ler_quant();
	
	printf("\n\nmultiplos de 6 em ordem crescente:\n");
	
	do{
		printf("[%d]  ", base*multiplicador);
		multiplicador++;
		
	}while(multiplicador<=quantidade);
	
	//encerrar
	printf ("\n\n\n%s", "aperte ENTER para continuar");
	getchar();
}




//>>>>>>>>>> method_02 - programa 0512 <<<<<<<<<<
//para ler uma quantidade inteira do teclado e, mediante um procedimento,
//mostrar essa quantidade em valores múltiplos de 3 e 5 em ordem crescente.

void method_02 (void){
	
	int quantidade = 0;
	
	int base = 15;		//mmc de 3 e 5
	
	int multiplicador = 1;
	
	//identificar
	printf("\nmethod_02 - programa 0512");
	
	quantidade = ler_quant();
	
	printf("\n\nmultiplos de 3 e 5 em ordem crescente:\n");
	
	do{
		printf("[%d]  ", base*multiplicador);
		multiplicador++;
		
	}while(multiplicador<=quantidade);
	
	//encerrar
	printf ("\n\n\n%s", "aperte ENTER para continuar");
	getchar();
}

/*outra maneira:

int multiplicador = 1;
int multiplo = 0
int multiplos_encontrados;


do{
	multiplo = multiplicador*5;
	if(multiplo % 3 == 0){
		printf(multiplo);
		multiplos_encontrados++;
	}
	multiplicador ++;
}while(multiplos_encontrados<=quantidade)
*/




//>>>>>>>>>> method_03 - programa 0513 <<<<<<<<<<
//mostrar essa quantidade em potências de 4 em ordem decrescente

void method_03 (void){
	
	int quantidade = 0;
	
	int base = 4;
	
	int exp = 0;
	
	//identificar
	printf("\nmethod_03 - programa 0513");
	
	quantidade = ler_quant();
	
	printf("\n\npotencias de 4 em ordem decresente:\n");
	
	for(exp=quantidade;exp>=0;exp--){
		
		printf("[%d]  ", (int)pow(base,exp));
		
	}

	//encerrar
	printf ("\n\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//Keep in mind that the pow() function returns a double, 
//so if you need an integer result, you may need to cast the result to an integer type after using pow().




//>>>>>>>>>> method_04 - programa 0514 <<<<<<<<<<
//mostrar essa quantidade em valores crescentes nos denominadores
//(sequência dos inversos) múltiplos de 7.

void method_04 (void){
	
	int quantidade = 0;
	
	int base = 7;
	
	int multiplicador = 1;
	
	//identificar
	printf("\nmethod_04 - programa 0514");
	
	quantidade = ler_quant();
	
	printf("\n\nvalores crescentes multiplos de 7 nos denominadores:\n");
	
	do{
		printf("[1/%d]  ", base*multiplicador);
		multiplicador++;
		
	}while(multiplicador<=quantidade);
	
	//encerrar
	printf ("\n\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//se eu simplesmente fizesse o calculo 1/base o resultado mostrado iria ser em decimal
//If you want to display the inverse of a number as a fraction (e.g., 1/7) instead of its decimal approximation
//you would need to handle the numerator and denominator separately. 
//OBS: o exemplo da questao mostra um output que apareceria se fossem multiplos de SEIS




//>>>>>>>>>> method_05 - programa 0515 <<<<<<<<<<
//ler um valor real real (x) do teclado;
//ler uma quantidade inteira do teclado e, mediante um procedimento,
//mostrar essa quantidade em valores pares crescentes nos denominadores da sequencia

double ler_real (void){
	
	double n = 0;
	
	do{
		printf("\n\ninsira um numero real:  ");
		scanf("%lf", &n);
		getchar();
	}while(n<=0);
	
	return (n);
}

void method_05 (void){
	
	int quantidade = 0;
	
	double real = 0;
	
	int exp = 2;

	int counter = 1;
	
	double potencia = 0.0;
	
	//identificar
	printf("\nmethod_05 - programa 0515");
	
	real=ler_real();
	
	quantidade=ler_quant();
	
	
	do{
		
		potencia = pow(real, exp);
		
		printf("[1/%lf]  ", potencia);
		
		exp = exp+2;
		
		counter++;
		
	}while(counter<=quantidade);
	
	//encerrar
	printf ("\n\n\n%s", "aperte ENTER para continuar");
	getchar();	
}




//>>>>>>>>>> method_06 - programa 0516 <<<<<<<<<<
//calcular a soma dos primeiros valores positivos começando no valor 3,
//múltiplos de 3 e não múltiplos de 5.

void method_06 (void){
	
	//identificar
	printf("\nmethod_06 - programa 0516");
	
	int quantidade = 0;
	
	int multiplicador = 0;
	
	int multiplos_encontrados = 0;
	
	int resultado = 0;
	
	int soma = 0;
	
	quantidade=ler_quant();
	
	printf("\n\nsoma dos valores de 3 em 3 (exceto multiplos de 5):\n\n");
	
	do{
		resultado = 3+(multiplicador*3);
		
		multiplicador++;
		
		if(resultado % 5 != 0){
			printf("[%d] + ", resultado);
			multiplos_encontrados++;
			soma = soma + resultado;
		}
		
	}while(multiplos_encontrados<quantidade);
	
	printf("\n\ntotal = %d", soma);
	
	//encerrar
	printf ("\n\n\n%s", "aperte ENTER para continuar");
	getchar();
}




//>>>>>>>>>> method_07 - programa 0517 <<<<<<<<<<
//calcular a soma dos inversos (1/x) dos primeiros valores positivos,
//começando no valor 6, múltiplos de 6 e não múltiplos de 5.

double soma_inversos (int valor, int quantidade){
	
	int multiplicador = 0;
	
	int multiplos_encontrados = 0;
	
	int resultado = 0;
	
	double soma = 0.0;
	
	do{
		resultado = valor+(multiplicador*valor);
		
		multiplicador++;
		
		if(resultado % 5 != 0){
			printf("[1/%d] + ", resultado);
			multiplos_encontrados++;
			soma = soma + (1.0/resultado); //usar a constante no tipo double!! faz diferença
		}
		
	}while(multiplos_encontrados<quantidade);
	
	return(soma);
}

void method_07 (void){
	
	//identificar
	printf("\nmethod_07 - programa 0517");
	
	double soma = 0.0;
	
	int quantidade = ler_quant();
	
	printf("\n\nsoma dos valores de 6 em 6 (exceto multiplos de 5):\n\n");

	soma = soma_inversos(6, quantidade);
	
	printf("\n\ntotal = %lf", soma);
	
	//encerrar
	printf ("\n\n\n%s", "aperte ENTER para continuar");
	getchar();
}




//>>>>>>>>>> method_08 - programa 0518 <<<<<<<<<<
//calcular a soma da adição dos primeiros números naturais começando no valor 6

int soma_valores (int valor, int quantidade){
	
	int naturais_encontrados = 0;
	
	int resultado = 0;
	
	int soma = 1;
	
	do{	
		
		resultado = valor + naturais_encontrados;
		
		valor = resultado;
		
		printf("[%d] + ", resultado);
		
		naturais_encontrados++;
		
		soma = soma + resultado;
		
	}while(naturais_encontrados<quantidade);
	
	return(soma);
}

void method_08 (void){
	
	//identificar
	printf("\nmethod_08 - programa 0518");
	
	int soma = 0;
	
	int quantidade = ler_quant();
	
	printf("\n\nsoma da adicao dos primeiros valores naturais começando no valor 6:\n\n");
	
	soma = soma_valores(6, quantidade);
	
	printf("\n\ntotal = %d", soma);
	
	//encerrar
	printf ("\n\n\n%s", "aperte ENTER para continuar");
	getchar();
}




//>>>>>>>>>> method_09 - programa 0519 <<<<<<<<<<
//calcular a soma dos quadrados da adição dos números naturais começando no valor 6

double soma_quadrados (double valor, int quantidade){
	
	int naturais_encontrados = 0;
	
	double resultado = 0;
	
	double soma = 0.0;
	
	do{	
		
		resultado = pow((valor + naturais_encontrados),2);
		
		printf("[%lf] + ", resultado);
		
		naturais_encontrados++;
		
		soma = soma + resultado;
		
	}while(naturais_encontrados<quantidade);
	
	return(soma);
}

void method_09 (void){
	
	//identificar
	printf("\nmethod_09 - programa 0519");
	
	double soma = 1.0;
	
	int quantidade = ler_quant();
	
	printf("\n\nsoma dos quadrados da adicao dos numeros naturais comecando no valor 6:\n\n");
	
	soma = soma_quadrados(6.0, quantidade);
	
	printf("\n\ntotal = %lf", soma);
	
	//encerrar
	printf ("\n\n\n%s", "aperte ENTER para continuar");
	getchar();
}




//>>>>>>>>>> method_10 - programa 0520 <<<<<<<<<<
//calcular a soma dos inversos (1/x) das adições de números naturais terminando no valor 6

double soma_inv_2 (int valor, int quantidade){
	
	int multiplos_encontrados = 0;
	
	int resultado = 0;
	
	double soma = 0.0;
	
	int counter = 0;
	
	int guardar[quantidade];
	
	do{	
		
		resultado = valor + multiplos_encontrados;
		
		valor = resultado;
		
		guardar[multiplos_encontrados]=resultado;
		
		multiplos_encontrados++;

		soma = soma + (1.0/resultado); //usar a constante no tipo double!! faz diferença
		
	}while(multiplos_encontrados<quantidade);
	
	for(counter=quantidade-1; counter>=0; counter--){ //coloquei o -1 para nao ler o /0 (que esta na ultima posicao)
		
		printf("[1/%d] + ", guardar[counter]);
	}
	
	return(soma);
}

void method_10 (void){
	
	//identificar
	printf("\nmethod_10 - programa 0520");
	
	double soma = 1.0;
	
	int quantidade = ler_quant();
	
	printf("\n\nsoma dos inversos (1/x) das adicoes de numeros naturais terminando no valor 6:\n\n");
	
	soma = soma_inv_2(6.0, quantidade);
	
	printf("\n\ntotal = %lf", soma);
	
	//encerrar
	printf ("\n\n\n%s", "aperte ENTER para continuar");
	getchar();
}








int main (int argc, char *argv[]){
	
	//identificar o programa
	printf ("%s", "estudo dirigido 05 - programas_0511_a_0520");
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

testes e outputs estao no arquivo "outputs_exercicios_ED05_raquelmotta.txt"


>>>>>>>>>>>>>>>>>>>>>>>>>>>>> notas e comentarios

*/
