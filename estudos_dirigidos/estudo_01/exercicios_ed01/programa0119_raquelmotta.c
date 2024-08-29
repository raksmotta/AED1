/*
PUC MINAS - AEDs1
Mar/2024

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: programa0119

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//>>>>>>>>>> method_01 - programa 0119 <<<<<<<<<<

void method_01 (void){
	
	double raio = 0.0;
	double area = 0.0;
	bool a = true;
	
	printf ("\n\n%s", "method_01 - programa 0119");		//identificar programa
	
	printf ("\n\n%s", "por favor escolha o raio de um circulo.");
	
	while(a){
		printf ("\n\n%s", "raio:   ");
		scanf ("%lf", &raio);
		getchar();
		
		if (raio>0){		//apenas SE base E altura forem maior que zero, o loop se encerra
			a = false;
		}else{
			printf ("\n\n%s", "valor invalido. insira numeros positivos");
		}
	}
	
	printf ("\n\nvalor escolhido: raio = (%lf)", raio);
	
	raio = raio/6;
	
	area = M_PI * pow(raio, 2);
	
	area = area/2;
	
	printf ("\n\n%s%lf", "a area de um semicirculo com 1/6 do raio escolhido = ", area);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

int main (int argc, char *argv[]){
	
	//identificar o programa
	printf ("%s", "estudo dirigido 01 - programa 0119");
	printf ("\n%s\n%s", "autor: raquel de parde motta", "matricula: 854017");
	
	int opcao = 0;
	
	do{
		//mostrar as opcoes
		printf ("\n\n%s", "digite o numero correspondente a opcao desejada: ");
		printf ("\n\n%s", "0 - encerrar");
		printf ("\n\n%s", "1 - method_01 - programa 0119");
		
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

A) input no method_01 -> 60 (digitar alguns inputs invalidos antes para checar a validacao)



>>>>>>>>>>>>>>>>>>>>>>>>>>>>> outputs

------------------- teste A -------------------

estudo dirigido 01 - programa 0119
autor: raquel de parde motta
matricula: 854017

digite o numero correspondente a opcao desejada:

0 - encerrar

1 - method_01 - programa 0119

opcao =  1


method_01 - programa 0119

por favor escolha o raio de um circulo.

raio:   -9


valor invalido. insira numeros positivos

raio:   60


valor escolhido: raio = (60.000000)

a area de um semicirculo com 1/6 do raio escolhido = 157.079633

aperte ENTER para continuar


>>>>>>>>>>>>>>>>>>>>>>>>>>>>> notas e comentarios



>>>>>>>>>>>>>>>>>>>>>>>>>>>>> testes

A --- OK

*/
