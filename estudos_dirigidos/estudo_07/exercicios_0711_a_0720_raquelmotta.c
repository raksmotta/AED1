/*
PUC MINAS - AEDs1
Abr/2024

Estudo Dirigido 07

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: exercicios_0711_a_0720_raquelmotta
Versao: 0.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <io.h>


//>>>>>>>>>> method_01 - programa 0711 <<<<<<<<<<

void method_01 (void){
	
	//definir dados
	int y = 0;
	int x = 0;
	int counter = 1;
	chars fileName = "METODO01.TXT";
	FILE* arquivo = fopen (fileName, "wt");
	
	//identificar
	printf("\nmethod_01 - programa 0711");
	
	printf("\n\nquantos multiplos de 4 vc deseja gravar?  ");
	scanf("%d", &x);
	getchar();
	
	//repetir para a quantidade de dados
	for (y=4; counter<=x; counter++){
		
		//gravar valor
		fprintf(arquivo, "%d\n", y*counter);
		
	}
	
	//fechar arquivo (INDISPENSAVEL para gravacao)
	fclose (arquivo);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





//>>>>>>>>>> method_02 - programa 0712 <<<<<<<<<<

void method_02 (void){
	
	//definir dados
	int y = 5;
	int x = 0;
	int counter = 0;
	int result = 0;
	int mult = 5;
	int array [80];
	
	char fileName[] = "METODO02.TXT";
	FILE* arquivo = fopen (fileName, "wt");
	
	//identificar
	printf("\nmethod_02 - programa 0712");
	
	printf("\n\nquantos multiplos de 5 vc deseja gravar?  ");
	scanf("%d", &x);
	getchar();
	
	fprintf(arquivo, "%s\n", "multiplos de 5 impares, em ordem decrescente, encerrando em 25:\n");
	
	//guardar em ordem crescente
	while(counter<x){
		
		result = y*mult;
		
		if(result%2!=0){

			array[counter]=result;
			
			counter++;
			
		}
		
		mult++;
	}
	
	//imprimir em ordem descrescente
	while(counter>0){
		
		fprintf(arquivo, "%d\n", array[counter-1]);
		
		counter--;
		
	}
	
	//fechar arquivo (INDISPENSAVEL para gravacao)
	fclose (arquivo);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





//>>>>>>>>>> method_03 - programa 0713 <<<<<<<<<<

void method_03 (void){
	
	//definir dados
	int x = 0;
	int counter = 1;
	int mult = 5;
	
	chars fileName = "METODO03.TXT";
	FILE* arquivo = fopen (fileName, "wt");
	
	//identificar
	printf("\nmethod_03 - programa 0713");
	
	printf("\n\nquantos valores vc deseja gravar?  ");
	scanf("%d", &x);
	getchar();
	
	fprintf(arquivo, "%d\n", 1);
	fprintf(arquivo, "%d\n", 5);
	
	while(counter<=(x-2)){
		
		mult = mult * 5;
		
		fprintf(arquivo, "%d\n", mult);
		
		counter++;
	}
	
	//fechar arquivo (INDISPENSAVEL para gravacao)
	fclose (arquivo);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





//>>>>>>>>>> method_04 - programa 0714 <<<<<<<<<<

/*OBS.: Professor, nesse exercício 04 o senhor pediu para gravarmos as potências
de 5 em FRAÇÕES (1/625, 1/125, 1/25 ...).

Entretanto, no exercício 07 o senhor pede para calcularmos a soma dos INVERSOS do
exercício 04 e escreve como exemplo de output NOVAMENTE as frações (1/625 + 1/125 + 1/25 ...).

Portanto, um dos enunciados precisa ser modificado para que a transformação de inverso 
possa ser realizada. 

Tendo isso em mente, elaborei o exercício 04 apenas como (625, 125, 25..), sem 
transformar as potências no denominador de uma fração*/

void method_04 (void){
	
	//definir dados
	int y = 1;
	int x = 0;
	int counter = 0;
	int array [80];
	
	char fileName[] = "METODO04.TXT";
	FILE* arquivo = fopen (fileName, "wt");
	
	//identificar
	printf("\nmethod_04 - programa 0714");
	
	printf("\n\nquantos valores da sequencia vc deseja gravar?  ");
	scanf("%d", &x);
	getchar();
	
	//guardar em ordem crescente
	while(counter<x-1){
		
		y = y * 5;
		
		array[counter]=y;
		
		counter++;
		
	}
	
	//imprimir em ordem descrescente
	while(counter>0){
		
		fprintf(arquivo, "%d\n", array[counter-1]);
		
		counter--;
		
	}
	
	fprintf(arquivo, "%d\n", 1);
	
	//fechar arquivo (INDISPENSAVEL para gravacao)
	fclose (arquivo);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





//>>>>>>>>>> method_05 - programa 0715 <<<<<<<<<<

void method_05 (void){
	
	//definir dados
	double x = 0.0;
	int n = 0;
	int counter = 1;
	double result = 0.0;
	int pot = 3;
	
	chars fileName = "METODO05.TXT";
	FILE* arquivo = fopen (fileName, "wt");
	
	//identificar
	printf("\nmethod_05 - programa 0715");
	
	printf("\n\nquantos valores vc deseja gravar?  ");
	scanf("%d", &n);
	getchar();

	printf("\n\ndigite um valor real:  ");
	scanf("%lf", &x);
	getchar();
	
	fprintf(arquivo, "%d\n", 1);
	
	while(counter<=(n-1)){
		
		result = 1/pow(x, pot);
		
		fprintf(arquivo, "%lf\n", result);
		
		counter++;
		
		pot = pot+2;
	}
	
	//fechar arquivo (INDISPENSAVEL para gravacao)
	fclose (arquivo);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





//>>>>>>>>>> method_06 - programa 0716 <<<<<<<<<<

int ler_valores_6 (chars fileName, int qtd){
	
	//definir dados
	FILE* arquivo = fopen (fileName, "rt");
	FILE* arquivo_destino = fopen ("RESULTADO06.TXT", "wt");
	double x = 0.0;
	int counter = 1;
	double soma = 0;
	
	//tentar ler o primeiro
	fscanf(arquivo, "%lf + \n", &x);
	
	//repetir enquanto houver dados
	while(!feof(arquivo) && counter<=qtd){
		
		fprintf(arquivo_destino, "%lf + \n", x);
		
		soma = soma + x;
		
		fscanf(arquivo, "%lf", &x);
		
		counter++;
	}
	
	fprintf(arquivo_destino, "\n\nsoma = %lf\n", soma);
	
	fclose(arquivo);	
	fclose(arquivo_destino);	
	
	return(soma);
	
}

void method_06 (void){
	
	int qtd = 0;
	double result = 0.0;
	
	//identificar
	printf("\nmethod_06 - programa 0716");
	
	printf("\n\nquantos valores vc deseja ler e somar?  ");
	scanf("%d", &qtd);
	getchar();
	
	result = ler_valores_6("METODO05.TXT", qtd);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}





//>>>>>>>>>> method_07 - programa 0717 <<<<<<<<<<

int ler_valores_7 (chars fileName, int qtd){
	
	//definir dados
	FILE* arquivo = fopen (fileName, "rt");
	FILE* arquivo_destino = fopen ("RESULTADO07.TXT", "wt");
	double x = 0.0;
	int counter = 1;
	double soma = 0;
	
	//tentar ler o primeiro
	fscanf(arquivo, "%lf + \n", &x);
	
	//repetir enquanto houver dados
	while(!feof(arquivo) && counter<=qtd){
		
		fprintf(arquivo_destino, "%lf + \n", 1/x);
		
		soma = soma + 1/x;
		
		fscanf(arquivo, "%lf", &x);
		
		counter++;
	}
	
	fprintf(arquivo_destino, "\n\nsoma = %lf\n", soma);
	
	fclose(arquivo);	
	fclose(arquivo_destino);	
	
	return(soma);
	
}

void method_07 (void){
	
	int qtd = 0;
	double result = 0.0;
	
	//identificar
	printf("\nmethod_07 - programa 0717");
	
	printf("\n\nquantos valores vc deseja ler e somar?  ");
	scanf("%d", &qtd);
	getchar();
	
	result = ler_valores_7("METODO04.TXT", qtd);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}





//>>>>>>>>>> method_08 - programa 0718 <<<<<<<<<<

int PegandoValor() {
	int tam;
	printf("quantos termos pares de fibonacci vc deseja? ");
	scanf("%d", &tam);
	getchar();
	return tam;
}


void Fibonacci(int fibonacci[], int tam) {
	
	FILE* arquivo = fopen ("RESULTADO08.TXT", "wt");
	int par = 0;
	int contador = 1;
	int array [tam];
	
	
	do{ 
		
		if (contador == 0) {
			fibonacci[contador] = 0;
			
		} else if (contador == 1 || contador == 2) {
			fibonacci[contador] = 1;
			
		} else {
			fibonacci[contador] = fibonacci[contador - 1] + fibonacci[contador - 2];
		}
		
		//printf("\n%d", fibonacci[contador]);
		
		if (fibonacci[contador] % 2 == 0) {
			array[par] = fibonacci[contador];
			fprintf(arquivo, "\nPar [%i]: %i\n", par, array[par]);
			par++;
		}
		
		contador ++;
		
	}while(par<tam);
	
	fclose(arquivo);
	
}


void method_08 (void){
	
	int tam = 0;
	
	//identificar
	printf("\nmethod_08 - programa 0718\n");
	
	tam = PegandoValor();
	
	int fibonacci[tam];
	
	Fibonacci(fibonacci, tam);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





//>>>>>>>>>> method_09 - programa 0719 <<<<<<<<<<

void ler_maiusculas_palavra (chars fileName){
	
	int i = 0;
	int maiuscula = 0;
	FILE* arquivo = fopen(fileName, "rt");
	FILE* arquivo_destino = fopen ("RESULTADO09.TXT", "wt");
	chars linha = IO_new_chars(STR_SIZE);
	
	//tentar ler a primeira
	strcpy(linha, IO_fread(arquivo));
	
	//repetir enquanto houver dados
	while(!feof(arquivo) && strcmp("PARAR", linha)!=0){
		
		maiuscula = 0;
		i = 0;
		
		fprintf(arquivo_destino, "\n%s\n", linha);
		
		while(linha[i]!='\0'){
			
			if('A'<=linha[i] && linha[i]<='Z'){
				
				maiuscula ++;
				
			}
			
			i++;
			
		}

		fprintf(arquivo_destino, "maiusculas = %d\n", maiuscula);
		
		//tentar ler o proximo
		strcpy (linha, IO_fread(arquivo));
		
	}
	
	fclose(arquivo);
	fclose(arquivo_destino);
}
/*
o IO_fread é baseado no >>fscanf<<

chars IO_fread ( FILE* filePtr )
{
chars buffer = IO_new_chars ( STR_SIZE+1 );

IO_fscanf ( filePtr, "%s", buffer ); // ler uma cadeia
return ( buffer );
} 

*/

void method_09 (){
	
	//identificar
	printf("\nmethod_09 - programa 0719\n");
	
	ler_maiusculas_palavra("TESTE09.TXT");
	
	//encerrar
	IO_pause ("apertar ENTER para continar");
	
}





//>>>>>>>>>> method_10 - programa 0720 <<<<<<<<<<

void ler_maiores5_palavra (chars fileName){
	
	int i = 0;
	int n = 0; //conta a qtd de digitos maiores ou iguais a 5
	FILE* arquivo = fopen(fileName, "rt");
	FILE* arquivo_destino = fopen ("RESULTADO10.TXT", "wt");
	chars linha = IO_new_chars(STR_SIZE);
	
	//tentar ler a primeira
	strcpy(linha, IO_fread(arquivo));
	
	//repetir enquanto houver dados
	while(!feof(arquivo)){
		
		n = 0;
		i = 0;
		
		fprintf(arquivo_destino, "\n%s\n", linha);
		
		while(linha[i]!='\0' && strcmp("PARAR", linha)!=0){
			
			if('5'<=linha[i] && linha[i]<='9'){
				
				n ++;
				
			}
			
			i++;
			
		}
		
		fprintf(arquivo_destino, "qtd de digitos maiores ou iguais a 5 = %d\n", n);
		
		//tentar ler o proximo
		strcpy (linha, IO_fread(arquivo));
		
	}
	
	fclose(arquivo);
	fclose(arquivo_destino);
}
//nao entendi pq nao lê a ultima linha do arquivo se fizer o esquema de escrever o PARAR e comparar com ele
//pq apenas o !feof faz o programa nao ler a ultima linha do arquivo texto?

/*
o IO_fread é baseado no >>fscanf<<

chars IO_fread ( FILE* filePtr )
{
chars buffer = IO_new_chars ( STR_SIZE+1 );

IO_fscanf ( filePtr, "%s", buffer ); // ler uma cadeia
return ( buffer );
} 

*/

void method_10 (){
	
	//identificar
	printf("\nmethod_10 - programa 0720\n");
	
	ler_maiores5_palavra("TESTE10.TXT");
	
	//encerrar
	IO_pause ("apertar ENTER para continar");
	
}





int main (int argc, char *argv[]){
	
	//identificar o programa
	printf ("%s", "estudo dirigido 07 - programas_0711_a_0720");
	printf ("\n%s\n%s", "autor: raquel de parde motta", "matricula: 854017");
	
	int opcao = 0;
	
	do{
		//mostrar as opcoes
		printf ("\n\n%s", "digite o numero correspondente a opcao desejada: ");
		printf ("\n\n%s", "0 - encerrar");
		printf ("\n\n%s", "1 - method_01 - programa 0711");
		printf ("\n\n%s", "2 - method_02 - programa 0712");
		printf ("\n\n%s", "3 - method_03 - programa 0713");
		printf ("\n\n%s", "4 - method_04 - programa 0714");
		printf ("\n\n%s", "5 - method_05 - programa 0715");
		printf ("\n\n%s", "6 - method_06 - programa 0716");
		printf ("\n\n%s", "7 - method_07 - programa 0717");
		printf ("\n\n%s", "8 - method_08 - programa 0718");
		printf ("\n\n%s", "9 - method_09 - programa 0719");
		printf ("\n\n%s", "10 - method_10 - programa 0720");
		
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


outputs estao nos arquivos txt gerados por cada método.


>>>>>>>>>>>>>>>>>>>>>>>>>>>>> notas e comentarios

*/
