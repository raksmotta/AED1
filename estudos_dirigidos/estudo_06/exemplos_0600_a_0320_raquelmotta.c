/*
PUC MINAS - AEDs1
Mar/2024

Estudo Dirigido 06

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: exemplos_0600_a_0610
Versao: 0.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//>>>>>>>>>> programa 0600 <<<<<<<<<<


//mostrar certa quantidade de valores recursivamente
//@param x - quantidade de valores a serem mostrados

void method_01a (int x){
	
	if(x>0){	//repetir enquanto valor maior que zero
		
		printf("\n%s%d\n", "valor = ", x);	//mostrar valor
		
		method_01a (x-1);	//passar ao proximo. motor da recursividade
	}
	
}


//mostrar certa quatidade de valores

void method_01 (void){
	
	//definir dado
	int quantidade = 0;
	int valor = 0;
	int controle = 0;
	
	
	//identificar
	printf("\nmethod_01 - programa 0600\n");
	
	method_01a(5);	//executar metodo auxiliar. o motor da recursividade está incluido nele
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}




//>>>>>>>>>> programa 0601 <<<<<<<<<<


//mostrar certa quantidade de valores recursivamente
//@param x - quantidade de valores a serem mostrados

void method_02a (int x){
	
	if(x>0){
		
		method_02a (x-1);	//motor da recursividade
		
		printf("\n%s%d\n", "valor = ", x);	//mostrar valor
		
	}
	
}
//nesse caso, os sucessivos valores de x serão processador e armazenadados até que a condição x>0 se torne falsa
//uma vez que isso ocorre, passa-se para a próxima ação, inputando nela do último valor obtido até o primeiro obtido
//portanto, se fornecermos o valor 5 para a funcao, o output será 1 2 3 4
//ou seja: a exibicao do primeiro valor nao ocorrera enquanto o parametro x nao chegar a zero,
//e nao for iniciar o processo de retorno. os valores pendentes serao conhecidos durante o retorno

void method_02 (void){
	
	//identificar
	printf("\nmethod_02 - programa 0601\n");
	
	method_02a(5);	//executar metodo auxiliar. o motor da recursividade está incluido nele
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}




//>>>>>>>>>> programa 0602 <<<<<<<<<<


//mostrar certa quantidade de valores positivos recursivamente, mas em outra ordem
//@param x - quantidade de valores a serem mostrados

void method_03a (int x){
	
	if(x>1){	//repetir enquanto valor maior que 1
		
		method_03a (x-1);	//passar ao proximo valor. motor da recursividade
		
		printf("\n%s%d\n", "valor = ", x);	//mostrar valor
		
	}else{
		
		//base da recursividade
		printf("\n%s\n", "valor = [1]");	//mostrar o ultimo
		
	}
}

void method_03 (void){
	
	//identificar
	printf("\nmethod_03 - programa 0602\n");
	
	method_03a(5);	//executar metodo auxiliar. o motor da recursividade está incluido nele
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}




//>>>>>>>>>> programa 0603 <<<<<<<<<<


//mostrar valores da sequencia 1 2 4 6 8
//@param x - quantidade de valores a serem mostrados


int main (int argc, char *argv[]){
	
	//identificar o programa
	printf ("%s", "estudo dirigido 06 - exemplos_0600_a_0610");
	printf ("\n%s\n%s", "autor: raquel de parde motta", "matricula: 854017");
	
	int opcao = 0;
	
	do{
		//mostrar as opcoes
		printf ("\n\n%s", "digite o numero correspondente a opcao desejada: ");
		printf ("\n\n%s", "0 - encerrar");
		printf ("\n\n%s", "1 - method_01 - programa 0600");
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
