/*
PUC MINAS - AEDs1
Mar/2024

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: programa0116

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//>>>>>>>>>> method_01 - programa 0116 <<<<<<<<<<

void method_01 (void){
	
	double lado = 0.0;
	double perim = 0.0;
	double area = 0.0;
	double h = 0.0;
	bool a = true;
	
	printf ("\n\n%s", "method_01 - programa 0116");		//identificar programa
	
	printf ("\n\n%s", "por favor escolha a  medida dos lados de um triangulo equilatero.");
	
	while(a){
		printf ("\n\n%s", "lado:   ");
		scanf ("%lf", &lado);
		getchar();
		
		
		if (lado>0){		
			a = false;
		}else{
			printf ("\n\n%s", "valor invalido. insira um numero positivo");
		}
	}
	
	printf ("\n\nvalor escolhido: lado = (%lf)", lado);

	lado = lado * 3;
	
	perim = lado * 3;
	
	area = (pow(lado,2))/2;
	
	h = (sqrt(3)*lado)/2;
	
	printf ("\n\n%s", "se triplicarmos essa medida, entao teremos um triangulo com:"); 
	
	printf ("\n\n%s%lf", "perimetro = ", perim);
	printf ("\n\n%s%lf", "area = ", area);
	printf ("\n\n%s%lf", "altura = ", h);
	
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
		printf ("\n\n%s", "1 - method_01 - programa 0116");
		
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

A) input no method_01 -> 5 (digitar alguns inputs invalidos antes para checar a validacao)


>>>>>>>>>>>>>>>>>>>>>>>>>>>>> outputs

------------------- teste A -------------------

estudo dirigido 01 - programa 0115
autor: raquel de parde motta
matricula: 854017

digite o numero correspondente a opcao desejada:

0 - encerrar

1 - method_01 - programa 0116

opcao =  1


method_01 - programa 0116

por favor escolha a  medida dos lados de um triangulo equilatero.

lado:   0


valor invalido. insira um numero positivo

lado:   -3


valor invalido. insira um numero positivo

lado:   5


valor escolhido: lado = (5.000000)

se triplicarmos essa medida, entao teremos um triangulo com:

perimetro = 45.000000

area = 112.500000

altura = 12.990381

aperte ENTER para continuar


>>>>>>>>>>>>>>>>>>>>>>>>>>>>> notas e comentarios



>>>>>>>>>>>>>>>>>>>>>>>>>>>>> testes

A --- OK

*/
