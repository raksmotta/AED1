/*
PUC MINAS - AEDs1
Mar/2024

Estudo Dirigido 03

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: exercicios_0311_a_0320
Versao: 0.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <io.h>

//>>>>>>>>>> method_01 - programa 0311 <<<<<<<<<<
//ler palavra do teclado e mostrar as letras maiusculas

void method_01 (void){
	
	//identificar
	IO_printf("\n\nmethod_01 - programa 0311");
	
	char palavra[80];
	int tamanho = 0;
	int y = 0;
	
	IO_printf("\n\nescreva uma palavra: ");
	scanf("%s", palavra);
	getchar();
	
	tamanho = strlen(palavra);

	for(y=0; y<tamanho; y++){
		
		if ('A'<=palavra[y]&&palavra[y]<='Z'){
			printf("\n\n%c eh uma letra maiuscula", palavra[y]);
		}
	}	
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_02 - programa 0312 <<<<<<<<<<
//ler palavra do teclado e contar e mostrar as letras maiusculas

void method_02 (void){
	
	//identificar
	IO_printf("\n\nmethod_02 - programa 0312");
	
	char palavra[80];
	int tamanho = 0;
	int y = 0;
	int counter = 0;
	
	IO_printf("\n\nescreva uma palavra: ");
	scanf("%s", palavra);
	getchar();
	
	tamanho = strlen(palavra);
	
	for(y=0; y<tamanho; y++){
		
		if ('A'<=palavra[y]&&palavra[y]<='Z'){
			printf("\n\nposicao %d - [%c]",y, palavra[y]);
			counter++;
		}
	}	
	
	printf("\n\ntotal de letras maiusculas = %d", counter);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_03 - programa 0313 <<<<<<<<<<
//ler palavra do teclado e contar e mostrar as letras maiusculas - de trás pra frente

void method_03 (void){
	
	//identificar
	IO_printf("\n\nmethod_03 - programa 0313");
	
	char palavra[80];
	int tamanho = 0;
	int y = 0;
	int counter = 0;
	
	IO_printf("\n\nescreva uma palavra: ");
	scanf("%s", palavra);
	getchar();
	
	tamanho = strlen(palavra)-1;
	
	for(y=tamanho; y>=0; y--){
		
		if ('A'<=palavra[y]&&palavra[y]<='Z'){
			printf("\n\nposicao %d - [%c]",y, palavra[y]);
			counter++;
		}
	}	
	
	printf("\n\ntotal de letras maiusculas = %d", counter);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_04 - programa 0314 <<<<<<<<<<
//ler cadeia de caracteres e contar e mostrar apenas simbolos que forem letras (maiusculas ou minusculas)

void method_04 (void){
	
	//identificar
	IO_printf("\n\nmethod_04 - programa 0314");
	
	char palavra[80];
	int tamanho = 0;
	int y = 0;
	int counter = 0;
	
	IO_printf("\n\nescreva uma palavra: ");
	scanf("%s", palavra);
	getchar();
	
	tamanho = strlen(palavra);
	
	for(y=0; y<tamanho; y++){
		
		if ('A'<=palavra[y]&&palavra[y]<='z'){
			printf("\n\nposicao %d - [%c]",y, palavra[y]);
			counter++;
		}
	}	
	
	printf("\n\ntotal de letras = %d", counter);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_05 - programa 0315 <<<<<<<<<<
//ler cadeia de caracteres e contar e mostrar apenas os digitos (de  tras pra frente)

void method_05 (void){
	
	//identificar
	IO_printf("\n\nmethod_05 - programa 0315");
	
	char palavra[80];
	int tamanho = 0;
	int y = 0;
	int counter = 0;
	
	IO_printf("\n\nescreva uma palavra: ");
	scanf("%s", palavra);
	getchar();
	
	tamanho = strlen(palavra)-1;
	
	for(y=tamanho; y>=0; y--){
		
		if ('0'<=palavra[y]&&palavra[y]<='9'){
			printf("\n\nposicao %d - [%c]",y, palavra[y]);
			counter++;
		}
	}	
	
	printf("\n\ntotal de digitos = %d", counter);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_06 - programa 0316 <<<<<<<<<<
//contar e mostrar tudo o que nao for digito nem letra

void method_06 (void){
	
	//identificar
	IO_printf("\n\nmethod_06 - programa 0316");
	
	char palavra[80];
	int tamanho = 0;
	int y = 0;
	int counter = 0;
	
	IO_printf("\n\nescreva uma palavra: ");
	scanf("%s", palavra);
	getchar();
	
	tamanho = strlen(palavra);
	
	for(y=0; y<tamanho; y++){
		
		if ((palavra[y]<'A'||'z'<palavra[y])&&(palavra[y]<'0'||'9'<palavra[y])){
			printf("\n\nposicao %d - [%c]",y, palavra[y]);
			counter++;
		}
	}	
	
	printf("\n\ntotal de caracteres (nem digito, nem letra) = %d", counter);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_07 - programa 0317 <<<<<<<<<<
//ler n valores em um intervalo de valores inteiros [a:b]. sao multiplos de 6 E estao dentro do intervalo?

void method_07 (void){
	
	int inferior = 1;
	int superior = 0;
	int n = 0;
	int x = 0;
	
	//identificar
	IO_printf("\n\nmethod_07 - programa 0317");
	
	do{
		printf("\n\ninsira o limite inferior do intervalo: ");
		scanf("%d", &inferior);
		getchar();
		
		printf("\ninsira o limite superior do intervalo: ");
		scanf("%d", &superior);
		getchar();
	}while(superior<=inferior);
	
	printf("\n\nintervalo escolhido = [%d:%d]", inferior, superior);
	
	do{
		printf("\n\ninsira a quantidade de valores que vc quer testar: ");
		scanf("%d", &n);
		getchar();
	}while(n<=0);
	
	int array[n];
	int temp;
	int last_pos = -1;
	
	for(x=0;x<n;x++){
		
		printf("\nvalor %d: ", x+1);
		scanf("%d", &temp);
		getchar();
		
		if (temp%6==0 && inferior<=temp && temp<=superior){
			last_pos++;
			array[last_pos]=temp;
		}
		
	}	
	
	if(last_pos!=-1){
		printf("\n\n%d valores dentro do intervalo E multiplos de 6: ", last_pos+1);
	}else{
		printf("\n\nnenhum valor multiplo de 6 E dentro do intervalo");
	}

	
	for(x=0;x<=last_pos;x++){
		
		printf("[%d] ", array[x]);
		
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//se nao usasse a variavel temp, iria guardar todas as variaveis inputadas (sendo divisiveis por 6 ou nao) no array
//aí, teria que fazer outro loop de for para ler uma por uma e validar
//entretanto, se não quisesse imprimir uma de cada vez, e sim todas juntas, teria que criar outro array para ir guardando os valores validos

//se nao usasse a variavel last_pos, ficariam "caixinhas vazias" em posicoes da string quando o user inputasse valores invalidos
//a last_pos tambem acabou sendo muito util para contar, ja que nao posso usar um strlen no int array
//primeiro tinha definido last_pos=0, mas o -1 serviu para validar a conta e identificar quando nenhum valor valido fosse inputado


//>>>>>>>>>> method_08 - programa 0318 <<<<<<<<<<
//ler n valores em um intervalo de valores inteiros [a:b]. sao multiplos de 4 E nao sao multiplos de 5 E estao dentro do intervalo?

void method_08 (void){
	
	int inferior = 1;
	int superior = 0;
	int n = 0;
	int x = 0;
	
	//identificar
	IO_printf("\n\nmethod_08 - programa 0318");
	
	do{
		printf("\n\ninsira o limite inferior do intervalo: ");
		scanf("%d", &inferior);
		getchar();
		
		printf("\ninsira o limite superior do intervalo: ");
		scanf("%d", &superior);
		getchar();
	}while(superior<=inferior);
	
	printf("\n\nintervalo escolhido = [%d:%d]", inferior, superior);
	
	do{
		printf("\n\ninsira a quantidade de valores que vc quer testar: ");
		scanf("%d", &n);
		getchar();
	}while(n<=0);
	
	int array[n];
	int temp;
	int last_pos = -1;
	
	for(x=0;x<n;x++){
		
		printf("\nvalor %d: ", x+1);
		scanf("%d", &temp);
		getchar();
		
		if (temp%4==0 && inferior<=temp && temp<=superior && temp%5!=0){
			last_pos++;
			array[last_pos]=temp;
		}
		
	}	
	
	if(last_pos!=-1){
		printf("\n\n%d valores dentro do intervalo E multiplos de 4 E nao multiplos de 5: ", last_pos+1);
	}else{
		printf("\n\nnenhum valor dentro do intervalo E multiplo de 4 E nao multiplo de 5");
	}
	
	
	for(x=0;x<=last_pos;x++){
		
		printf("[%d] ", array[x]);
		
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_09 - programa 0319 <<<<<<<<<<
//ler n valores em um intervalo de valores reais (a:b). parte inteira é par E estao dentro do intervalo?

void method_09 (void){
	
	double inferior = 1;
	double superior = 0;
	int n = 0;
	int x = 0;
	
	//identificar
	IO_printf("\n\nmethod_09 - programa 0319");
	
	do{
		printf("\n\ninsira o limite inferior do intervalo: ");
		scanf("%lf", &inferior);
		getchar();
		
		printf("\ninsira o limite superior do intervalo: ");
		scanf("%lf", &superior);
		getchar();
	}while(superior<=inferior);
	
	printf("\n\nintervalo escolhido = (%lf:%lf)", inferior, superior);
	
	do{
		printf("\n\ninsira a quantidade de valores que vc quer testar: ");
		scanf("%d", &n);
		getchar();
	}while(n<=0);
	
	double array[n];
	double temp;
	int last_pos = -1;
	
	for(x=0;x<n;x++){
		
		printf("\nvalor %d: ", x+1);
		scanf("%lf", &temp);
		getchar();
		
		int inteiro = (int)temp;
		
		if (inteiro%2==0 && inferior<=temp && temp<=superior){
			last_pos++;
			array[last_pos]=temp;
		}
		
	}	
	
	if(last_pos!=-1){
		printf("\n\n%d valores dentro do intervalo E com parte inteira par: ", last_pos+1);
	}else{
		printf("\n\nnenhum valor dentro do intervalo E com parte inteira par");
	}
	
	
	for(x=0;x<=last_pos;x++){
		
		printf("[%lf] ", array[x]);
		
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_10 - programa 0320 <<<<<<<<<<
//ler n valores em um intervalo de valores reais definido entre 0 e 1. parte fracionaria esta fora do intervalo?

void method_10 (void){
	
	double inferior = 1;
	double superior = 0;
	int n = 0;
	int x = 0;
	
	//identificar
	IO_printf("\n\nmethod_10 - programa 0320");
	
	do{
		printf("\n\ninsira o limite inferior do intervalo: ");
		scanf("%lf", &inferior);
		getchar();
		
		printf("\ninsira o limite superior do intervalo: ");
		scanf("%lf", &superior);
		getchar();
	}while(superior<=inferior || inferior<=0 || 1<=superior);
	
	printf("\n\nintervalo escolhido = (%lf:%lf)", inferior, superior);
	
	do{
		printf("\n\ninsira a quantidade de valores que vc quer testar: ");
		scanf("%d", &n);
		getchar();
	}while(n<=0);
	
	double array[n];
	double temp;
	int last_pos = -1;
	
	for(x=0;x<n;x++){
		
		printf("\nvalor %d: ", x+1);
		scanf("%lf", &temp);
		getchar();
		
		int inteiro = (int)temp;
		
		temp = temp-inteiro;
		
		//printf("\n%lf", temp); 
		
		if (temp<inferior || superior<temp){ //tem que usar OU, pois n tem como ser maior e menor ao mesmo tempo
			last_pos++;
			array[last_pos]=temp;
		}
		
	}	
	
	if(last_pos!=-1){
		printf("\n\n%d valores com parte fracionaria fora do intervalo: ", last_pos+1);
	}else{
		printf("\n\nnenhum valor com parte fracionaria fora do intervalo");
	}
	
	
	for(x=0;x<=last_pos;x++){
		
		printf("[%lf] ", array[x]);
		
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}


int main (int argc, char *argv[]){
	
	//identificar o programa
	printf ("%s", "estudo dirigido 03 - programas_0311_a_0320");
	printf ("\n%s\n%s", "autor: raquel de parde motta", "matricula: 854017");
	
	int opcao = 0;
	
	do{
		//mostrar as opcoes
		printf ("\n\n%s", "digite o numero correspondente a opcao desejada: ");
		printf ("\n\n%s", "0 - encerrar");
		printf ("\n\n%s", "1 - method_01 - programa 0311");
		printf ("\n\n%s", "2 - method_02 - programa 0312");
		printf ("\n\n%s", "3 - method_03 - programa 0313");
		printf ("\n\n%s", "4 - method_04 - programa 0314");
		printf ("\n\n%s", "5 - method_05 - programa 0315");
		printf ("\n\n%s", "6 - method_06 - programa 0316");
		printf ("\n\n%s", "7 - method_07 - programa 0317");
		printf ("\n\n%s", "8 - method_08 - programa 0318");
		printf ("\n\n%s", "9 - method_09 - programa 0319");
		printf ("\n\n%s", "10 - method_10 - programa 0320");
		
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

testes e outputs estao no arquivo "outputs_exercicios_ED03_raquelmotta.txt"


>>>>>>>>>>>>>>>>>>>>>>>>>>>>> notas e comentarios


*/
