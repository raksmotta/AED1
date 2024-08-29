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

void method_01 (void){
	
	//identificar
	printf("\nmethod_01");
	
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
