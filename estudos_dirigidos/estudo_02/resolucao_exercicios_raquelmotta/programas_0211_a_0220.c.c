/*
PUC MINAS - AEDs1
Mar/2024

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: programas_0211_a_0220

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//>>>>>>>>>> method_01 - programa 0211 <<<<<<<<<<

void method_01 (void){
	
	int x = 0;
	
	printf ("\n\n%s", "method_01 - programa 0211");		//identificar programa
	
	printf ("\n\n%s", "digite um numero inteiro:  ");
	scanf ("%d", &x);
	getchar();
	
	printf ("\n%s%d", "numero digitado = ", x);
	
	if (x%2 == 0)
	{
		printf ("\n\n%d%s", x, " eh um numero par");
	}else
	{
		printf ("\n\n%d%s", x, " eh um numero impar");
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_02 - programa 0212 <<<<<<<<<<

void method_02 (void){
	
	int x = 0;
	
	printf ("\n\n%s", "method_02 - programa 0212");		//identificar programa
	
	printf ("\n\n%s", "digite um numero inteiro:  ");
	scanf ("%d", &x);
	getchar();
	
	printf ("\n%s%d", "numero digitado = ", x);
	
	if (x%2 == 0)
	{
		printf ("\n\n%d%s", x, " eh um numero par");
		if(x>25)
		{
			printf ("\n\n%d%s", x, " eh maior que 25");
		}
		
	}else
	{
		printf ("\n\n%d%s", x, " eh um numero impar");
		if(x<-25)
		{
			printf ("\n\n%d%s", x, " eh menor que -25");
		}
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_03 - programa 0213 <<<<<<<<<<

void method_03 (void){
	
	int x = 0;
	
	printf ("\n\n%s", "method_03 - programa 0213");		//identificar programa
	
	printf ("\n\n%s", "digite um numero inteiro:  ");
	scanf ("%d", &x);
	getchar();
	
	printf ("\n%s%d", "numero digitado = ", x);
	
	if ((35<x)&&(x<65))
	{
		printf ("\n\n%d%s", x, " pertence ao intervalo aberto entre (35:65)");
		
	}else
	{
		printf ("\n\n%d%s", x, " NAO pertence ao intervalo aberto entre (35:65)");
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_04 - programa 0214 <<<<<<<<<<

void method_04 (void){
	
	int x = 0;
	
	printf ("\n\n%s", "method_04 - programa 0214");		//identificar programa
	
	printf ("\n\n%s", "digite um numero inteiro:  ");
	scanf ("%d", &x);
	getchar();
	
	printf ("\n%s%d", "numero digitado = ", x);
	
	if ((15<=x)&&(x<=60))
	{
		printf ("\n\n%d%s", x, " pertence ao intervalo fechado entre [15:60]");
		
	}else
	{
		printf ("\n\n%d%s", x, " NAO pertence ao intervalo fechado entre [15:60]");
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_05 - programa 0215 <<<<<<<<<<

void method_05 (void){
	
	int x = 0;
	bool a = false;
	bool b = false;
	
	printf ("\n\n%s", "method_05 - programa 0215");		//identificar programa
	
	printf ("\n\n%s", "digite um numero inteiro:  ");
	scanf ("%d", &x);
	getchar();
	
	printf ("\n%s%d", "numero digitado = ", x);
	
	if ((10<=x)&&(x<=30))	
		a = true;

	if ((25<x)&&(x<50))	
		b = true;
	
	if((a && b) == true)
	{
		printf ("\n\n%d%s", x, " pertence tanto ao intervalo [10:30], quanto ao intervalo (25:50)");
	}else if (a  == true)
	{
		printf ("\n\n%d%s", x, " pertence ao intervalo fechado entre [10:30]");	
	}else if (b == true)
	{
		printf ("\n\n%d%s", x, " pertence ao intervalo aberto entre (25:50)");
	}else{
		printf ("\n\n%d%s", x, " NAO pertence nem ao intervalo [10:30], nem ao intervalo (25:50)");
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_06 - programa 0216 <<<<<<<<<<

void method_06 (void){
	
	int x = 0;
	int y = 0;
	
	printf ("\n\n%s", "method_06 - programa 0216");		//identificar programa
	
	printf ("\n\n%s", "digite um numero inteiro:  ");
	scanf ("%d", &x);
	getchar();
	
	printf ("\n%s%d", "primeiro numero digitado = ", x);
	
	printf ("\n\n%s", "digite um outro numero inteiro:  ");
	scanf ("%d", &y);
	getchar();
	
	printf ("\n%s%d", "segundo numero digitado = ", y);
	
	if (x%2 != 0)
	{
		printf ("\n\n%d%s", x, " eh um numero impar");
	}
	
	if (y%2 == 0)
	{
		printf ("\n\n%d%s", y, " eh um numero par");
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_07 - programa 0217 <<<<<<<<<<

void method_07 (void){
	
	int x = 0;
	int y = 0;
	
	printf ("\n\n%s", "method_07 - programa 0217");		//identificar programa
	
	printf ("\n\n%s", "digite um numero inteiro:  ");
	scanf ("%d", &x);
	getchar();
	
	printf ("\n%s%d", "primeiro numero digitado = ", x);
	
	printf ("\n\n%s", "digite um outro numero inteiro:  ");
	scanf ("%d", &y);
	getchar();
	
	printf ("\n%s%d", "segundo numero digitado = ", y);
	
	if (x%2 == 0)
	{
		printf ("\n\n%d%s", x, " eh um numero par");
	}else
	{
		printf ("\n\n%d%s", x, " nao eh um numero par");
	}
	
	if (x<0){
		printf ("%s"," e eh negativo.");
	}else
	{
		printf ("%s"," e nao eh negativo.");
	}
	
	if (y%2 == 0)
	{
		printf ("\n\n%d%s", y, " nao eh um numero impar");
	}else
	{
		printf ("\n\n%d%s", y, " eh um numero impar");
	}
	
	if (y<0){
		printf ("%s"," e nao eh positivo.");
	}else
	{
		printf ("%s"," e eh positivo.");
	}
	

	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_08 - programa 0218 <<<<<<<<<<

void method_08 (void){
	
	double x = 0.0;
	double y = 0.0;
	
	printf ("\n\n%s", "method_08 - programa 0218");		//identificar programa
	
	printf ("\n\n%s", "digite um numero real:  ");
	scanf ("%lf", &x);
	getchar();
	
	printf ("\n%s%lf", "primeiro numero digitado = ", x);
	
	printf ("\n\n%s", "digite um outro numero real:  ");
	scanf ("%lf", &y);
	getchar();
	
	printf ("\n%s%lf", "segundo numero digitado = ", y);
	
	x = x/3;
	printf ("\n\n%s%lf", "1/3 do primeiro numero digitado = ", x);
	
	if (y<x){
		printf ("\n%lf%s%lf", y, " eh menor que ", x);
	}else if (y>x){
		printf ("\n%lf%s%lf", y, " eh maior que ", x);
	}else{
		printf ("\n%lf%s%lf", y, " eh igual a ", x);
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_09 - programa 0219 <<<<<<<<<<

void method_09 (void){
	
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	
	printf ("\n\n%s", "method_09 - programa 0219");		//identificar programa

	do{
		printf ("\n\n\n%s", "digite um numero real:  ");
		scanf ("%lf", &x);
		getchar();
		
		printf ("\n\n%s", "digite outro numero real:  ");
		scanf ("%lf", &y);
		getchar();
		
		printf ("\n\n%s", "digite outro numero real:  ");
		scanf ("%lf", &z);
		getchar();
		
		if (y == z){
			printf ("\n\n%s", "o segundo e o terceiro valores devem ser diferentes entre si. por favor digite os numeros novamente.");
		} 
		
	}while(y == z);
	
	printf ("\n\n%s%lf", "primeiro numero digitado = ", x);
	printf ("\n%s%lf", "segundo numero digitado = ", y);
	printf ("\n%s%lf", "terceiro numero digitado = ", z);
	
	if ((y<x)&&(x<z)){
		printf ("\n\n%lf esta entre %lf e %lf", x, y, z);
	}else if ((z<x)&&(x<y)){
		printf ("\n\n%lf esta entre %lf e %lf", x, z, y); //no caso de n3 ser menor que n2
	}else{
		printf ("\n\n%lf NAO esta entre %lf e %lf", x, y, z);
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_10 - programa 0220 <<<<<<<<<<

void method_10 (void){
	
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	
	printf ("\n\n%s", "method_10 - programa 0220");		//identificar programa
	
	do{
		printf ("\n\n\n%s", "digite um numero real:  ");
		scanf ("%lf", &x);
		getchar();
		
		printf ("\n\n%s", "digite outro numero real:  ");
		scanf ("%lf", &y);
		getchar();
		
		printf ("\n\n%s", "digite outro numero real:  ");
		scanf ("%lf", &z);
		getchar();
		
		if ((x == y)||(x == z)||(y == z)){
			printf ("\n\n%s", "todos os valores devem ser diferentes entre si. por favor digite os numeros novamente.");
		} 
		
	}while((x == y)||(x == z)||(y == z));
	
	printf ("\n\n%s%lf", "primeiro numero digitado = ", x);
	printf ("\n%s%lf", "segundo numero digitado = ", y);
	printf ("\n%s%lf", "terceiro numero digitado = ", z);
	
	if ((y<x)&&(x<z)){
		printf ("\n\n%lf esta entre %lf e %lf", x, y, z);
	}else if ((z<x)&&(x<y)){
		printf ("\n\n%lf esta entre %lf e %lf", x, z, y); //no caso de n3 ser menor que n2
	}else{
		printf ("\n\n%lf NAO esta entre %lf e %lf", x, y, z);
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}


int main (int argc, char *argv[]){
	
	//identificar o programa
	printf ("%s", "estudo dirigido 02 - programas 0211 a 0220");
	printf ("\n%s\n%s", "autor: raquel de parde motta", "matricula: 854017");
	
	int opcao = 0;
	
	do{
		//mostrar as opcoes
		printf ("\n\n%s", "digite o numero correspondente a opcao desejada: ");
		printf ("\n\n%s", "0 - encerrar");
		printf ("\n\n%s", "1 - method_01 - programa 0211");
		printf ("\n\n%s", "2 - method_02 - programa 0212");
		printf ("\n\n%s", "3 - method_03 - programa 0213");
		printf ("\n\n%s", "4 - method_04 - programa 0214");
		printf ("\n\n%s", "5 - method_05 - programa 0215");
		printf ("\n\n%s", "6 - method_06 - programa 0216");
		printf ("\n\n%s", "7 - method_07 - programa 0217");
		printf ("\n\n%s", "8 - method_08 - programa 0218");
		printf ("\n\n%s", "9 - method_09 - programa 0219");
		printf ("\n\n%s", "10 - method_10 - programa 0220");
		
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

>>>>>>>>>>>>>>>>>>>>>>>>>>>>> previsao de testes


testes e outputs estao no arquivo "outputs_exercicios_ED02_raquelmotta.txt"


>>>>>>>>>>>>>>>>>>>>>>>>>>>>> notas e comentarios


*/
