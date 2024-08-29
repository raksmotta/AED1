/*
PUC MINAS - AEDs1
Mar/2024

Estudo Dirigido 06

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: programas_0600_a_0611
Versao: 0.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>


//>>>>>>>>>> method_01 - programa 0611 <<<<<<<<<<

int ler_quant (void){
	
	int n = 0;
	
	do{
		printf("\n\ninsira um numero inteiro:  ");
		scanf("%d", &n);
		getchar();
	}while(n<=0);
	
	return (n);
}

void method_01_a (int x){
	
	if(x>0){
		
		method_01_a(x-1);
		printf("%d ",6*x);
		
	}
}

void method_01 (void){
	
	//identificar
	printf("\nmethod_01 - programa 0611");
	
	int quantidade = ler_quant();
	
	method_01_a(quantidade);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



//>>>>>>>>>> method_02 - programa 0612 <<<<<<<<<<

void method_02_a (int x){
	
	if(x>0){
		
		printf("%d ",6*x);
		method_02_a(x-1);
		
	}
}

void method_02 (void){
	
	//identificar
	printf("\nmethod_02 - programa 0612");
	
	int quantidade = ler_quant();
	
	method_02_a(quantidade);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



//>>>>>>>>>> method_03 - programa 0613 <<<<<<<<<<

void method_03_a (int x){
	
	if(x==1){
		printf("1/%d ", x);
	}
	
	if(x>0){
		
		method_03_a(x-1);
		printf("1/%d ",6*x);
		
	}
}

void method_03 (void){
	
	//identificar
	printf("\nmethod_03 - programa 0613");
	
	int quantidade = ler_quant();
	
	quantidade = quantidade-1;
	
	method_03_a(quantidade);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



//>>>>>>>>>> method_04 - programa 0614 <<<<<<<<<<

void method_04_a (int x){
	
	if(x>0){
		
		printf("1/%d ",6*x);
		method_04_a(x-1);
		
	}
	
	if(x==1){
		printf("1/%d ", x);
	}
}

void method_04 (void){
	
	//identificar
	printf("\nmethod_04 - programa 0614");
	
	int quantidade = ler_quant();
	
	quantidade = quantidade-1;
	
	method_04_a(quantidade);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



//>>>>>>>>>> method_05 - programa 0615 <<<<<<<<<<
//calcular a soma de valores gerados pela adição dos primeiros valores pares positivos ao valor 6

int method_05_a (int x){
	
	int soma = 0;
	
	if(x>0){
		
		soma = (6+x*(x-1)) + method_05_a(x-1);
		
		printf("[%d] + ", (6+x*(x-1)));
		
	}
	
	return(soma);
}

void method_05 (void){	
	
	//identificar
	printf("\nmethod_05 - programa 0615");
	
	int resultado = 0;
	
	int quantidade = ler_quant();
	
	resultado = method_05_a(quantidade);
	
	printf("\nresultado = %d", resultado);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



//>>>>>>>>>> method_06 - programa 0616 <<<<<<<<<<

double method_06_a (int x){
	
	double soma = 0.0;
	
	if(x>0){
		
		soma = (1.0/(6*x)) + method_06_a(x-1); 
		//um dos números da divisão tem que ter casa decimal!! se nao, o resultado aparecerá 0
		
		printf("[1/%d] + ", (6*x));
		
	}
	
	return(soma);
}

void method_06 (void){	
	
	//identificar
	printf("\nmethod_06 - programa 0616");
	
	double resultado = 0.0;
	
	int quantidade = ler_quant();
	
	resultado = method_06_a(quantidade);
	
	printf("\nresultado = %lf", resultado);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



//>>>>>>>>>> method_07 - programa 0617 <<<<<<<<<<

void method_07_a (char* cadeia, int x){
	
	//testar se contador valido
	if(x>=0){
		
		method_07_a(cadeia, x-1);
		
		printf("\n%c", cadeia[x]);
		
	}
	
}

void method_07 (void){
	
	char palavra[80];
	
	//identificar
	printf("\nmethod_07 - programa 0617");
	
	printf("\n\nescreva uma palavra: ");
	scanf("%s", palavra);
	getchar();
	
	printf("\na palavra que vc digitou foi:\n");
	
	method_07_a(palavra, strlen(palavra));
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



//>>>>>>>>>> method_08 - programa 0618 <<<<<<<<<<

int method_08_a (char* cadeia, int x){
	
	//definir dado
	int resposta = 0;
	
	//testar se contador valido
	if(0<=x && x<strlen(cadeia)){
		
		//testar se o digito tem valor par
		if(cadeia[x]%2==0){
			//fazer de novo com valor absoluto
			resposta = 1;
		}
		
		resposta = resposta + method_08_a(cadeia, x+1);
		
	}
	
	return(resposta);	
}

void method_08 (void){
	
	char palavra[80];
	
	int resultado = 0;
	
	//identificar
	printf("\nmethod_08 - programa 0618");
	
	printf("\n\nescreva uma palavra: ");
	scanf("%s", palavra);
	getchar();
	
	resultado = method_08_a(palavra, 0);
	
	printf("\no numero de digitos com valores pares na palavra = %d", resultado);

	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



//>>>>>>>>>> method_09 - programa 0619 <<<<<<<<<<

int method_09_a (char* cadeia, int x){
	
	//definir dado
	int resposta = 0;
	
	//testar se contador valido
	if(0<=x && x<strlen(cadeia)){
		
		//testar se o digito tem valor par
		if('A'<=cadeia[x]&&cadeia[x]<'L'){
			//fazer de novo com valor absoluto
			resposta = 1;
		}
		
		resposta = resposta + method_09_a(cadeia, x+1);
		
	}
	
	return(resposta);	
}

void method_09 (void){
	
	char palavra[80];
	
	int resultado = 0;
	
	//identificar
	printf("\nmethod_09 - programa 0619");
	
	printf("\n\nescreva uma palavra: ");
	scanf("%s", palavra);
	getchar();
	
	resultado = method_09_a(palavra, 0);
	
	printf("\na qtd de maisuculas menores que L na palavra que vc digitou = %d", resultado);
	
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



//>>>>>>>>>> method_10 - programa 0620 <<<<<<<<<<


int fibonacci (int x){
	
	//definir dado
	int resposta = 0;
	
	//testar se contador válido
	if(x==1 || x==2){
		
		//primeiros dois valores iguais a 1
		resposta = 1; //bases
		
	}else{
		
		if(x>1){
			
			//fazer de novo com valor absoluto
			resposta = fibonacci(x-1) + fibonacci(x-2);
			printf("resp : %d - x :  %d \n", resposta, x);
			
		}
		
	}
	
	return(resposta);
	
}

void method_10 (void){
	
	int resultado = 0;
	
	//identificar
	printf("\nmethod_10 - programa 0620");
	
	int quantidade = ler_quant();
	
	int soma = 0;
	
	int counter = 0;
	
	int numero = 1;
	
	do{
		resultado = fibonacci(numero);
		numero++;
		
		if(resultado%2==0){
			
			printf("%d + ", resultado);
			soma=soma+resultado;
			counter++;
		}
		
	}while(counter<quantidade);
	
	
	printf("\nsoma = %d", soma);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





int main (int argc, char *argv[]){
	
	//identificar o programa
	printf ("%s", "estudo dirigido 06 - programas_0611_a_0620");
	printf ("\n%s\n%s", "autor: raquel de parde motta", "matricula: 854017");
	
	int opcao = 0;
	
	do{
		//mostrar as opcoes
		printf ("\n\n%s", "digite o numero correspondente a opcao desejada: ");
		printf ("\n\n%s", "0 - encerrar");
		printf ("\n\n%s", "1 - method_01 - programa 0611");
		printf ("\n\n%s", "2 - method_02 - programa 0612");
		printf ("\n\n%s", "3 - method_03 - programa 0613");
		printf ("\n\n%s", "4 - method_04 - programa 0614");
		printf ("\n\n%s", "5 - method_05 - programa 0615");
		printf ("\n\n%s", "6 - method_06 - programa 0616");
		printf ("\n\n%s", "7 - method_07 - programa 0617");
		printf ("\n\n%s", "8 - method_08 - programa 0618");
		printf ("\n\n%s", "9 - method_09 - programa 0619");
		printf ("\n\n%s", "10 - method_10 - programa 0620");
		
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

testes e outputs estao no arquivo "outputs_exercicios_ED06_raquelmotta.txt"


>>>>>>>>>>>>>>>>>>>>>>>>>>>>> notas e comentarios

*/
