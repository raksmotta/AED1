/*
PUC MINAS - AEDs1
Mar/2024

Estudo para prova 01

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: programas_0000_a_0000
Versao: 0.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <io.h>

//>>>>>>>>>> method_01 - LISTA 01 EXTRA 01 <<<<<<<<<<

void method_01 (void){
	
	double area = 0.0;
	double raio = 0.0;
	
	//identificar
	printf("\nmethod_01 - 01E1");
	
	printf("\n\nsigite a area da circunferencia: ");
	scanf("%lf",&area);
	getchar();
	
	area = area/7;
	
	raio = sqrt(M_PI/area);
	
	printf("o raio de 1/7 dessa area = %lf", raio);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_02 method_03 method_04 - LAB DIA 15 DE ABRIL <<<<<<<<<<

void method_02 (void){
	
	int n = 0;
	int x = 0;
	
	FILE * arquivo = NULL;
	arquivo = fopen ("dados.txt", "wt");
	
	//identificar
	printf("\nmetodo 02");
	
	//acoes
	printf("\n = ");
	scanf("%d", &n);
	getchar();
	
	for(x=1;x<=n;x++){
		
		printf("%d\n", x);
		fprintf(arquivo, "%d\n", x);
		
	}
	
	fclose(arquivo);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}

void method_03 (void){
	
	int n = 0;
	int x = 0;
	
	FILE * arquivo = NULL;
	
	arquivo = fopen ("dados.txt", "rt");
	
	//identificar
	printf("metodo 03");
	
	//acoes
	printf("\n = ");
	scanf("%d", &n);
	getchar();
	
	for(x=1;x<=n;x++){
		
		printf("%d\n", x);
		fprintf(arquivo, "%d\n", x);
		
	}
	
	fclose(arquivo);
	
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}

void method_04 (void){
	
	int n = 0;
	int x = 0;
	
	FILE * arquivo = NULL;
	
	arquivo = fopen ("dados.txt", "at");
	
	//identificar
	printf("\nmetodo 04");
	
	//acoes
	printf("\n = ");
	scanf("%d", &n);
	getchar();
	
	for(x=1;x<=n;x++){
		
		printf("%d\n", 10+x);
		fprintf(arquivo, "%d\n", 10+x);
		
	}
	
	fclose(arquivo);
	
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}



//>>>>>>>>>> method_05 - LISTA 01 EXTRA 02 <<<<<<<<<<

void method_05 (void){
	
	double volume = 0.0;
	double area = 0.0;
	double raio = 0.0;
	
	//identificar
	printf("\nmethod_05 - 01E2");
	
	printf("\n\nvolume da esfera = ");
	scanf("%lf",&volume);
	getchar();
	
	raio = cbrt(volume/(4*M_PI/3));
	
	area = 4*M_PI*pow(raio,2.0);
	
	printf("\n\narea da superficie da esfera = %lf", area);
	
	raio = cbrt((5*volume/8)/(4*M_PI/3));
	
	printf("\n\nraio de 5/8 do volume da esfera = %lf", raio);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}



//>>>>>>>>>> method_06 - LISTA 02 EXTRA 01 <<<<<<<<<<

void method_06 (void){
	
	char palavra[3];
	
	//identificar
	printf("\nmethod_06 - 02E1");
	
	printf("\n\ndigite o primeiro caractere: ");
	scanf("%c", &palavra[0]);
	getchar();
	
	printf("\n\ndigite o segundo caractere: ");
	scanf("%c", &palavra[1]);
	getchar();
	
	printf("\n\ndigite o terceiro caractere: ");
	scanf("%c", &palavra[2]);
	getchar();
	
	if((palavra[1]==palavra[0])&&(palavra[0]==palavra[2])){
		
		printf("\n\nos tres caracteres sao iguais");
		
	}else if((palavra[1]<palavra[0])&&(palavra[0]<palavra[2])){
		
		printf("\n\n%c esta entre %c e %c", palavra[0], palavra[1], palavra[2]);
		
	}else if((palavra[2]<palavra[0])&&(palavra[0]<palavra[1])){
		
		printf("\n\n%c esta entre %c e %c", palavra[0], palavra[2], palavra[1]);
		
	}else if(palavra[0]==palavra[1]){
		
		printf("\n\n%c é igual a %c", palavra[0], palavra[1]);
		
	}else if(palavra[0]==palavra[2]){
		
		printf("\n\n%c é igual a %c", palavra[0], palavra[2]);
		
	}else{
		
		printf("\n\no primeiro caractere nao esta ente os outros dois NEM eh igual a um deles");
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



//>>>>>>>>>> method_07 - LISTA 02 EXTRA 02 <<<<<<<<<<

void method_07 (void){
	
	char palavra[3];
	
	//identificar
	printf("\nmethod_07 - 02E2");
	
	printf("\n\ndigite o primeiro caractere: ");
	scanf("%c", &palavra[0]);
	getchar();
	
	printf("\n\ndigite o segundo caractere: ");
	scanf("%c", &palavra[1]);
	getchar();
	
	printf("\n\ndigite o terceiro caractere: ");
	scanf("%c", &palavra[2]);
	getchar();
	
	if((palavra[0]==palavra[1])&&(palavra[0]==palavra[2])){
		
		printf("\n\nos 3 caracteres sao iguais");
		
	}else if(palavra[1]==palavra[2]){
		
		printf("\n\no segundo e o terceiro caracteres sao iguais");
		
	}else if((palavra[0]==palavra[1])||(palavra[0]==palavra[2])){
		
		printf("\n\no primeiro valor eh igual a um dos demais valores");
		
		
	}else if(((palavra[0]>palavra[1])&&(palavra[0]>palavra[2]))||((palavra[0]<palavra[2])&&(palavra[0]<palavra[1]))){
		
		printf("\n\no primeiro valor lido esta fora do intervalo definido pelos outros 2");
		
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}



//>>>>>>>>>> method_08 - LISTA 03 EXTRA 01 <<<<<<<<<<

void method_08 (void){
	
	char text[80];
	int y = 0;
	int p = 0;
	
	//identificar
	printf("\nmethod_08 - 03E1");
	
	printf("\n\nescreva uma linha:  ");
	fgets(text,80,stdin);	//input from the terminal console
	
	//printf("\n\nvc escreveu:\n%s", text);
	
	int tam = strlen(text);
	
	char nao_alfa[tam];
	
	do{
		
		if(text[y]==' '){
			
			y++;
			
		}else if ((('a'<=text[y])&&(text[y]<='z'))||(('A'<=text[y])&&(text[y]<='Z'))||(('0'<=text[y])&&(text[y]<='9'))){
			
			y++;
			
		}else{
			
			nao_alfa[p]=text[y];
			
			y++;
			
			p++;
		}
		
	}while(y<tam);
	
	printf("\n\nsimbolos nao-alfanumericos (que nao sao letras nem digitos): %s", nao_alfa);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}



//>>>>>>>>>> method_09 - LISTA 03 EXTRA 02 <<<<<<<<<<

void method_09 (void){
	
	char text[80];
	int nao_letra = 0;
	int y = 0;
	
	//identificar
	printf("\nmethod_09 - 03E2");
	
	printf("\n\ndigite uma cadeia de caracteres: ");
	//fgets(text,80,stdin); melhor usar fgets so quando tiver espaco em branco
	scanf("%s",text);
	getchar();
	
	printf("\n\nvc escreveu:\n%s", text);
	
	do{
		if((('a'<=text[y])&&(text[y]<='z'))||(('A'<=text[y])&&(text[y]<='Z'))){
			
			y++;
			
		}else{
			
			nao_letra++;
			y++;
			
		}
		
	}while(y<strlen(text));
	
	if(nao_letra==0){
		
		printf("\n\na sequencia contem APENAS simbolos que sao letras");
		
	}else{
		
		printf("\n\na sequencia contem simbolos que NAO sao letras");
		
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}



//>>>>>>>>>> method_10 - LISTA 04 EXTRA 01 <<<<<<<<<<

void method_10 (void){
	
	int y = 0;
	int alfa = 0;
	int blank = 0;
	char text[80];
	
	
	//identificar
	printf("\nmethod_10 - 04E1");
	
	printf("\n\nescreva algo: ");
	fgets(text,80,stdin);
	
	int tam = strlen(text);
	
	do{
		
		if((('a'<=text[y])&&(text[y]<='z'))||(('A'<=text[y])&&(text[y]<='Z'))||(('0'<=text[y])&&(text[y]<='9'))){
			
			alfa++;
			y++;
			
		}else if(text[y]==' '){
			
			blank++;
			y++;
			
		}else{
			
			y++;
			
		}
		
	}while(y<tam);
	
	printf("\n\nqtd de simbolos alfanumericos = %d", alfa);
	printf("\n\nqtd de espacos em branco = %d", blank);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}



//>>>>>>>>>> method_11 - LISTA 04 EXTRA 02 <<<<<<<<<<

void menor_dig (char*text1, char*text2){
	
	int qt1 = strlen(text1);
	int qt2 = strlen(text2);
	
	if(qt1==qt2){
		
		printf("\n\nas sequencias possuem a mesma quantidade de digitos");
		
	}else if(qt1<qt2){
		
		printf("\n\na primeira sequencia [%s] possui menor quantidade de digitos [%d]", text1, qt1);
		
	}else{
		
		printf("\n\na segunda sequencia [%s] possui menor quantidade de digitos [%d]", text2, qt2);
		
	}
	
}

void method_11 (void){
	
	char t1[80];
	char t2[80];
	
	//identificar
	printf("\nmethod_11 - 04E2");
	
	printf("\n\nprimeira palavra = ");
	scanf("%s", t1);
	getchar();
	
	printf("\n\nsegunda palavra = ");
	scanf("%s", t2);
	getchar();
	
	menor_dig(t1,t2);
	
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}



//>>>>>>>>>> method_12 - LISTA 05 EXTRA 01 <<<<<<<<<<

int fatorial (int base){
	
	int x = 0;
	int fatorial = base;
	
	if(base==0){
		
		fatorial=1;
		
	}else{
		
		
		for(x=base;x>1;x--){
			
			fatorial = fatorial * (x-1);
			
		}
		
	}
	
	return(fatorial);
	
}


int fatorial_recursivo (int base){
	
	if(base==0){
		
		return(1);
		
	}else{
		
		return(base*fatorial_recursivo(base-1));
		
	}
	
}


void method_12 (void){
	
	int resultado1 = fatorial(7);
	
	int resultado2 = fatorial_recursivo(7);
	
	printf("\n\n%d", resultado1);
	
	printf("\n\n%d", resultado2);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}




//>>>>>>>>>> method_13 - LISTA 05 EXTRA 02 <<<<<<<<<<

double funcao (int qtd){
	
	double mult = 1.0;
	double num = 0.0;
	double den = 0.0;
	double n = 1.0;
	int d = 0;
	double d_fat = 0.0;
	
	while(qtd>0){
		
		num = pow(2,n);
		den = 5+d;
		
		printf("\n\nnumerador = [%lf]", num);
		printf("\n\ndenominador = [%lf!]", den);
		
		d_fat = fatorial_recursivo(den);
		
		mult = mult * (1+(num/d_fat));
		
		qtd--;
		n++;
		d+=2;
		
	}
	
	return(mult);
}

void method_13 (void){
	
	int quantidade = 0;
	double result = 0.0;
	
	//identificar
	printf("\nmethod_13 - 05E2");
	
	printf("\n\ndigite um inteiro: ");
	scanf("%d", &quantidade);
	getchar();
	
	result=funcao(quantidade);
	
	printf("\n\no produto final eh igual a = %lf",result);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}






//>>>>>>>>>> method_14 - PROVA ANTIGA Q06 <<<<<<<<<<

int repeticao_letras (char*word){
	
	int y = 0;
	int check = 0;
	int i = 0;
	char c = 'c';
	int tam = strlen(word);
	
	for(y=0;y<tam;y++){
		
		c = word[y];
		i = 1;
		
		do{
			
			if(c==word[y+i]){
				
				check++;
				
			}
			
			i++;
			
		}while(i<tam);
		
	}
	
	return(check);
	
}

void method_14 (void){
	
	int n = 0;
	char text [80];
	int repete = 0;
	
	//identificar
	printf("\nmethod_14 - PROVA ANTIGA Q06");
	
	do{
		
		printf("\n\ndigite uma palavra:   ");
		scanf("%s", text);
		getchar();
		
		repete=repeticao_letras(text);
		
		if(repete==0){
			
			printf("\nNAO tem letras repetidas");
			n++;
			
		}else{
			
			printf("\nTEM letras repetidas");
			
		}
		
	}while(n<2);
	
	printf("\n\n\nparabens! vc digitou 2 palavras sem letras repetidas");
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}



//>>>>>>>>>> method_15 - PROVA ANTIGA Q07 <<<<<<<<<<

void method_15 (void){
	
	int n = 0;
	
	//identificar
	printf("\nmethod_15 - PROVA ANTIGA Q07");
	
	do{
		printf("\n\nvalor inteiro positivo maior que 2 = ");
		scanf("%d",&n);
		getchar();
	}while(n<=2);
	
	
	if(n%2!=0){
		n=n+1;
	}
	
	int max_points = n/2;
	int line = 1;	//numero de pontos na linha = numero da linha (primeira, segunda, terceira..)
	int i = 1;
	
	printf("\n\n");
	
	//crescente ate o meio
	while(line<=max_points){
		
		for(i=1;i<=line;i++){
			printf("*");
		}

		printf("\n");
		
		line= line+1;
		
	}
	
	line = max_points - 1;
	
	while(line>=1){
		
		for(i=line;i>0;i--){
			printf("*");
		}
		
		printf("\n");
		
		line= line-1;
		
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
	
}



//>>>>>>>>>> method_16 - LISTA 06 EXTRA 01 <<<<<<<<<<

int f06e1 (int x, int n, int a){
	
	int soma = 0;

	if(n>0){
		
		soma = (x^a) + f06e1(x,(n-1),(a+2));
		
	}

	
	return(soma);
}


void method_16 (void){
	
	int x = 0;
	int n = 0;
	int result = 0;
	
	//identificar
	printf("\nmethod_16 - 06E1");
	
	printf("\n\ninsira o valor de x = ");
	scanf("%d", &x);
	getchar();
	
	printf("\n\ninsira o valor de n = ");
	scanf("%d", &n);
	getchar();
	
	result = f06e1(x,n,3);
	
	printf("\n\nresultado da soma = %d", result);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





int main (int argc, char *argv[]){
	
	//identificar o programa
	printf ("%s", "estudo para prova 01");
	printf ("\n%s\n%s", "autor: raquel de parde motta", "matricula: 854017");
	
	int opcao = 0;
	
	do{
		//mostrar as opcoes
		printf ("\n\n%s", "digite o numero correspondente a opcao desejada: ");
		printf ("\n\n%s", "0 - encerrar");
		printf ("\n\n%s", "1 - method_01 - 01E1");
		printf ("\n\n%s", "2 - method_02 - lab 15/04");
		printf ("\n\n%s", "3 - method_03 - lab 15/04");
		printf ("\n\n%s", "4 - method_04 - lab 15/04");
		printf ("\n\n%s", "5 - method_05 - 01E2");
		printf ("\n\n%s", "6 - method_06 - 02E1");
		printf ("\n\n%s", "7 - method_07 - 02E2");
		printf ("\n\n%s", "8 - method_08 - 03E1");
		printf ("\n\n%s", "9 - method_09 - 03E2");
		printf ("\n\n%s", "10 - method_10 - 04E1");
		printf ("\n\n%s", "11 - method_11 - 04E2");
		printf ("\n\n%s", "12 - method_12 - 05E1");
		printf ("\n\n%s", "13 - method_13 - 05E2");
		printf ("\n\n%s", "14 - method_14 - PROVA ANTIGA Q06");
		printf ("\n\n%s", "15 - method_15 - PROVA ANTIGA Q07");
		printf ("\n\n%s", "16 - method_16 - 06E1");
		
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
		case 11:
			method_11 ();
			break;
		case 12:
			method_12 ();
			break;
		case 13:
			method_13 ();
			break;
		case 14:
			method_14 ();
			break;
		case 15:
			method_15 ();
			break;
		case 16:
			method_16 ();
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


>>>>>>>>>>>>>>>>>>>>>>>>>>>>> notas e comentarios

*/
