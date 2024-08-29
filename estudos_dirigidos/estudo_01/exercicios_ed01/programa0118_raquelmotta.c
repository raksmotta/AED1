/*
PUC MINAS - AEDs1
Mar/2024

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: programa0118

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//>>>>>>>>>> method_01 - programa 0118 <<<<<<<<<<

void method_01 (void){
	double comp = 0.0;
	double larg = 0.0;
	double alt = 0.0;
	double vol = 0.0;
	bool a = true;
	
	printf ("\n\n%s", "method_01 - programa 0118");		//identificar programa
	
	printf ("\n\n%s", "por favor escolha as dimensoes de um paralelepipedo");
	
	while (a){
		
		printf ("\n\n\n%s", "entre o valor do comprimento: ");
		scanf ("%lf", &comp);
		getchar();
		
		printf ("\n%s", "entre o valor da largura: ");
		scanf ("%lf", &larg);
		getchar();
		
		printf ("\n%s", "entre o valor da altura: ");
		scanf ("%lf", &alt);
		getchar();
		
		if (comp>0 && larg>0 && alt>0) {
			a = false;
		}else{
			printf ("\n\nvalor invalido. insira apenas numeros positivos.");
		}	
	}
	
	//mostrar medidas lidas
	printf ("\n\n%s", "medidas escolhidas para o paralelepipedo:");
	printf ("\n%s%lf", "comprimento =  ", comp);
	printf ("\n%s%lf", "largura =  ", larg);
	printf ("\n%s%lf", "altura =  ", alt);
	
	comp = comp/8;
	larg = larg/8;
	alt = alt/8;
	
	vol= comp*larg*alt;
	
	printf ("\n\n%s%lf", "o volume de um paralelepipedo com 1/8 das medidas escolhidas =  ", vol);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();	
}


int main (int argc, char*argv[]){
	
	int opcao = 0;
	
	//identificar o programa
	printf ("%s", "estudo dirigido 01 - programa 0118");
	printf ("\n%s\n%s", "autor: raquel de parde motta", "matricula: 854017");
	
	do{
		
		printf ("\n\n%s", "digite o numero correspondente a opcao desejada: ");
		printf ("\n\n%s", "0 - encerrar");
		printf ("\n\n%s", "1 - method_01 - programa 0118");
		
		//ler o valor inputado
		printf ("\n\n%s", "opcao =  ");
		scanf ("%i", &opcao);
		getchar ();
		
		switch(opcao){	
		case 0:
			break;
		case 1:
			method_01 ();
			break;
		default:
			printf ("\n\n%s", "erro - opcao invalida");
		}
	} while (opcao !=0);
	
	return(0);	
}


/*
DOCUMENTACAO COMPLEMENTAR



>>>>>>>>>>>>>>>>>>>>>>>>>>>>> previsao de testes

A) input no method_01 -> 30, 40 e 50 (digitar alguns inputs invalidos antes para checar a validacao)


>>>>>>>>>>>>>>>>>>>>>>>>>>>>> outputs

------------------- teste A -------------------

estudo dirigido 01 - programa 0118
autor: raquel de parde motta
matricula: 854017

digite o numero correspondente a opcao desejada:

0 - encerrar

1 - method_01 - programa 0118

opcao =  1


method_01 - programa 0118

por favor escolha as dimensoes de um paralelepipedo


entre o valor do comprimento: 0

entre o valor da largura: 5

entre o valor da altura: 8


valor invalido. insira apenas numeros positivos.


entre o valor do comprimento: 30

entre o valor da largura: 40

entre o valor da altura: 50


medidas escolhidas para o paralelepipedo:
comprimento =  30.000000
largura =  40.000000
altura =  50.000000

o volume de um paralelepipedo com 1/8 das medidas escolhidas =  117.187500


>>>>>>>>>>>>>>>>>>>>>>>>>>>>> notas e comentarios



>>>>>>>>>>>>>>>>>>>>>>>>>>>>> testes

A --- OK

*/
