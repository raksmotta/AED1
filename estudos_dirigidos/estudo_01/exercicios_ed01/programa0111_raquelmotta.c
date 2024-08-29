/*
PUC MINAS - AEDs1
Mar/2024

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: programa0111

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//>>>>>>>>>> method_01 - programa 0111 <<<<<<<<<<

void method_01 (void){
	
	double lado = 0.0;		//definindo variavel com tipo e valor inicial
	double area = 0.0;
	int erro = 0.0;
	
	printf ("\n\n%s", "method_01 - programa 0111");		//identificar programa
	
	do{
		if (erro>0)
			printf ("\n\n%s", "valor invalido. insira um numero positivo");	
		
		printf ("\n\n%s", "escolha a medida do lado do quadrado:   ");
		scanf ("%lf", &lado);
		getchar();
		
		erro++;
		
	}while(lado<=0);
	
	printf ("\n%s%lf", "valor escolhido para o lado: ", lado);
	
	//operar valores
	
	lado = lado * 3;
	
	area = pow(lado, 2);
	
	printf ("\n\n%s%lf", "a area de um quadrado com lado 3x maior que o escolhido = ", area);
	
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

int main (int argc, char *argv[]){
	
	//identificar o programa
	printf ("%s", "estudo dirigido 01 - programa 0111");
	printf ("\n%s\n%s", "autor: raquel de parde motta", "matricula: 854017");
	
	int opcao = 0;
	
	do{
		//mostrar as opcoes
		printf ("\n\n%s", "digite o numero correspondente a opcao desejada: ");
		printf ("\n\n%s", "0 - encerrar");
		printf ("\n\n%s", "1 - method_01 - programa0111");
		
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

A) input no method_01 -> 2
B) input no method_01 -> -3



>>>>>>>>>>>>>>>>>>>>>>>>>>>>> outputs

------------------- teste A -------------------

estudo dirigido 01 - programas 0111 a 0xxx
autor: raquel de parde motta
matricula: 854017

digite o numero correspondente a opcao desejada:

0 - encerrar

1 - method_01

opcao =  1


method_01 - programa 0111

escolha a medida do lado do quadrado:   2

valor escolhido para o lado: 2.000000

a area de um quadrado com lado 3x maior que o escolhido = 36.000000

aperte ENTER para continuar

------------------- teste B -------------------

estudo dirigido 01 - programas 0111 a 0xxx
autor: raquel de parde motta
matricula: 854017

digite o numero correspondente a opcao desejada:

0 - encerrar

1 - method_01

opcao =  1


method_01 - programa 0111

escolha a medida do lado do quadrado:   -2


valor invalido. insira um numero positivo

escolha a medida do lado do quadrado:   5

valor escolhido para o lado: 5.000000

a area de um quadrado com lado 3x maior que o escolhido = 225.000000

aperte ENTER para continuar



>>>>>>>>>>>>>>>>>>>>>>>>>>>>> notas e comentarios



>>>>>>>>>>>>>>>>>>>>>>>>>>>>> testes

A --- OK
B --- OK


*/
