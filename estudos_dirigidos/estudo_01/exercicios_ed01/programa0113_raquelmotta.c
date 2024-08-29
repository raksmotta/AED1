/*
PUC MINAS - AEDs1
Mar/2024

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: programa0113

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//>>>>>>>>>> method_01 - programa 0113 <<<<<<<<<<

void method_01 (void){
	
	double lado1 = 0.0;
	double lado2 = 0.0;
	double area = 0.0;
	bool a = true;
	
	printf ("\n\n%s", "method_01 - programa 0113");		//identificar programa
	
	printf ("\n\n%s", "por favor escolha as medidas dos lados de um retangulo.");
	
	while(a){
		printf ("\n\n%s", "lado 1:   ");
		scanf ("%lf", &lado1);
		getchar();
		
		printf ("\n\n%s", "lado 2:   ");
		scanf ("%lf", &lado2);
		getchar();
		
		if (lado1>0 && lado2>0){		//apenas SE lado1 E lado2 forem maior que zero, o loop se encerra
			a = false;
		}else{
			printf ("\n\n%s", "valor invalido. insira numeros positivos");
		}
	}
	
	printf ("\n\nvalores escolhidos: (%lf) e (%lf)", lado1, lado2);
	
	area = (lado1*6) * (lado2*6);
	
	printf ("\n\n%s%lf", "a area de um retangulo 6x maior que o escolhido = ", area);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

int main (int argc, char *argv[]){
	
	//identificar o programa
	printf ("%s", "estudo dirigido 01 - programa 0113");
	printf ("\n%s\n%s", "autor: raquel de parde motta", "matricula: 854017");
	
	int opcao = 0;
	
	do{
		//mostrar as opcoes
		printf ("\n\n%s", "digite o numero correspondente a opcao desejada: ");
		printf ("\n\n%s", "0 - encerrar");
		printf ("\n\n%s", "1 - method_01 - programa 0113");
		
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

A) input no method_01 -> 2 e 4 (digitar alguns inputs invalidos antes para checar a validacao)



>>>>>>>>>>>>>>>>>>>>>>>>>>>>> outputs

------------------- teste A -------------------

estudo dirigido 01 - programa 0113
autor: raquel de parde motta
matricula: 854017

digite o numero correspondente a opcao desejada:

0 - encerrar

1 - method_01 - programa 0113

opcao =  1


method_01 - programa 0113

por favor escolha as medidas dos lados de um retangulo.

lado 1:   -9


lado 2:   10


valor invalido. insira numeros positivos

lado 1:   4


lado 2:   -2


valor invalido. insira numeros positivos

lado 1:   2


lado 2:   4


valores escolhidos: (2.000000) e (4.000000)

a area de um retangulo 6x maior que o escolhido = 288.000000

aperte ENTER para continuar



>>>>>>>>>>>>>>>>>>>>>>>>>>>>> notas e comentarios



>>>>>>>>>>>>>>>>>>>>>>>>>>>>> testes

A --- OK

*/
