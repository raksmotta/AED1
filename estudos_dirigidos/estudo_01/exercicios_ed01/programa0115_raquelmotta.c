/*
PUC MINAS - AEDs1
Mar/2024

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: programa0115

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//>>>>>>>>>> method_01 - programa 0115 <<<<<<<<<<

void method_01 (void){
	
	double base = 0.0;
	double altura = 0.0;
	double area = 0.0;
	bool a = true;
	
	printf ("\n\n%s", "method_01 - programa 0115");		//identificar programa
	
	printf ("\n\n%s", "por favor escolha as medidas de um triangulo.");
	
	while(a){
		printf ("\n\n%s", "base:   ");
		scanf ("%lf", &base);
		getchar();
		
		printf ("\n\n%s", "altura:   ");
		scanf ("%lf", &altura);
		getchar();
		
		if (base>0 && altura>0){		//apenas SE base E altura forem maior que zero, o loop se encerra
			a = false;
		}else{
			printf ("\n\n%s", "valor invalido. insira numeros positivos");
		}
	}
	
	printf ("\n\nvalores escolhidos: base = (%lf) e altura = (%lf)", base, altura);
	
	area = ((altura*2)*base)/2;
	
	
	printf ("\n\n%s%lf", "a area de um triangulo com o dobro da altura escolhida = ", area);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

int main (int argc, char *argv[]){
	
	//identificar o programa
	printf ("%s", "estudo dirigido 01 - programa 0115");
	printf ("\n%s\n%s", "autor: raquel de parde motta", "matricula: 854017");
	
	int opcao = 0;
	
	do{
		//mostrar as opcoes
		printf ("\n\n%s", "digite o numero correspondente a opcao desejada: ");
		printf ("\n\n%s", "0 - encerrar");
		printf ("\n\n%s", "1 - method_01 - programa 0115");
		
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



>>>>>>>>>>>>>>>>>>>>>>>>>>>>> previsao de testes

A) input no method_01 -> 5 e 3.76 (digitar alguns inputs invalidos antes para checar a validacao)


>>>>>>>>>>>>>>>>>>>>>>>>>>>>> outputs

------------------- teste A -------------------

estudo dirigido 01 - programa 0115
autor: raquel de parde motta
matricula: 854017

digite o numero correspondente a opcao desejada:

0 - encerrar

1 - method_01 - programa 0115

opcao =  1


method_01 - programa 0115

por favor escolha as medidas de um triangulo.

base:   0


altura:   5


valor invalido. insira numeros positivos

base:   9


altura:   -3


valor invalido. insira numeros positivos

base:   5


altura:   3.76


valores escolhidos: base = (5.000000) e altura = (3.760000)

a area de um triangulo com o dobro da altura escolhida = 18.800000

aperte ENTER para continuar



>>>>>>>>>>>>>>>>>>>>>>>>>>>>> notas e comentarios



>>>>>>>>>>>>>>>>>>>>>>>>>>>>> testes

A --- OK

*/
