/*
PUC MINAS - AEDs1
Mar/2024

Estudo Dirigido 00

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: exercicios_0000_a_0000_raquelmotta
Versao: 0.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//>>>>>>>>>> method_01 - programa 0000 <<<<<<<<<<

void method_01 (void){
	
	//identificar
	printf("\nmethod_01 - programa 0511");
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_02 - programa 0000 <<<<<<<<<<

void method_02 (void){
	
	//identificar
	printf("\nmethod_02 - programa 0512");
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_03 - programa 0000 <<<<<<<<<<

void method_03 (void){
	
	//identificar
	printf("\nmethod_03 - programa 0513");
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_04 - programa 0000 <<<<<<<<<<

void method_04 (void){
	
	//identificar
	printf("\nmethod_04 - programa 0514");
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_05 - programa 000 <<<<<<<<<<

void method_05 (void){
	
	//identificar
	printf("\nmethod_05 - programa 0515");
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_06 - programa 0000 <<<<<<<<<<

void method_06 (void){
	
	//identificar
	printf("\nmethod_06 - programa 0516");
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_07 - programa 0000 <<<<<<<<<<

void method_07 (void){
	
	//identificar
	printf("\nmethod_07 - programa 0517");
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_08 - programa 0000 <<<<<<<<<<

void method_08 (void){
	
	//identificar
	printf("\nmethod_08 - programa 0518");
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_09 - programa 0009 <<<<<<<<<<

void method_09 (void){
	
	//identificar
	printf("\nmethod_09 - programa 0519");
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_10 - programa 0000 <<<<<<<<<<

void method_10 (void){
	
	//identificar
	printf("\nmethod_10 - programa 0520");
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}




int main (int argc, char *argv[]){
	
	//identificar o programa
	printf ("%s", "estudo dirigido 00 - programas_0000_a_0000");
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
