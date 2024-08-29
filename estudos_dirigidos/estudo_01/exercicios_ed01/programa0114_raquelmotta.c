/*
PUC MINAS - AEDs1
Mar/2024

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: programa0114

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//>>>>>>>>>> method_01 - programa 0114 <<<<<<<<<<

void method_01 (void){
	
	double lado1 = 0.0;		//definindo variavel com tipo e valor inicial
	double lado2 = 0.0;	
	double area = 0.0;
	double perim = 0.0;
	int erro = 0;
	int erro2 = 0;
	
	printf ("\n\n%s", "method_01 - programa 0114");		//identificar programa
	
	printf ("\n\n%s", "por favor escolha as medidas dos lados de um retangulo.");
	do{
		if (erro>0)
			printf ("\n\n%s", "valor invalido. insira um numero positivo");	
		
		printf ("\n\n%s", "lado 1:   ");
		scanf ("%lf", &lado1);
		getchar();
		
		erro++;
		
	}while(lado1<=0);
	
	do{
		if (erro2>0)
			printf ("\n\n%s", "valor invalido. insira um numero positivo");	
		
		printf ("\n\n%s", "lado 2:   ");
		scanf ("%lf", &lado2);
		getchar();
		
		erro2++;
		
	}while(lado2<=0);
	
	printf ("\n\nvalores escolhidos: (%lf) e (%lf)", lado1, lado2);
	
	//operar valores
	
	lado1 = lado1 / 4;
	
	lado2 = lado2 / 4;
	
	perim = (lado1 * 2) + (lado2 * 2);
	
	area = lado1 * lado2;
	
	printf ("\n\n%s%lf", "o perimetro de um retangulo com 1/4 do tamanho que o escolhido = ", perim);
	printf ("\n\n%s%lf", "a area de um retangulo com 1/4 do tamanho que o escolhido = ", area);
	
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

int main (int argc, char *argv[]){
	
	//identificar o programa
	printf ("%s", "estudo dirigido 01 - programa 0114");
	printf ("\n%s\n%s", "autor: raquel de parde motta", "matricula: 854017");
	
	int opcao = 0;
	
	do{
		//mostrar as opcoes
		printf ("\n\n%s", "digite o numero correspondente a opcao desejada: ");
		printf ("\n\n%s", "0 - encerrar");
		printf ("\n\n%s", "1 - method_01 - programa 0114");
		
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

A) input no method_01 -> 10 e 20 (digitar alguns inputs invalidos antes para checar a validacao)

>>>>>>>>>>>>>>>>>>>>>>>>>>>>> outputs

------------------- teste A -------------------

estudo dirigido 01 - programa 0114
autor: raquel de parde motta
matricula: 854017

digite o numero correspondente a opcao desejada:

0 - encerrar

1 - method_01 - programa 0114

opcao =  1


method_01 - programa 0114

por favor escolha as medidas dos lados de um retangulo.

lado 1:   -5


valor invalido. insira um numero positivo

lado 1:   -9


valor invalido. insira um numero positivo

lado 1:   10


lado 2:   -2


valor invalido. insira um numero positivo

lado 2:   -6


valor invalido. insira um numero positivo

lado 2:   20


valores escolhidos: (10.000000) e (20.000000)

o perimetro de um retangulo com 1/4 do tamanho que o escolhido = 15.000000

a area de um retangulo com 1/4 do tamanho que o escolhido = 12.500000

aperte ENTER para continuar




>>>>>>>>>>>>>>>>>>>>>>>>>>>>> notas e comentarios



>>>>>>>>>>>>>>>>>>>>>>>>>>>>> testes

A --- OK

*/
