/*
	Exercicio000 - v1.0. - 301 ate 410 - 22/02/2024
	Autor: Raquel de Parde Motta
	Matricula: 854017
*/

// dependencias
#include <stdio.h>	// para as entradas e saidas
#include <stdlib.h> // para outras funcoes de uso geral
#include <stdbool.h> // para valores logicos
#include <string.h> // para lidar com caracteres
#include <math.h>


//-------------------------- exemplo 301 > ler um valor inteiro e verificar se eh zero

void exemplo301 (void) {
	int X = 0;
	
	printf ("EXEMPLO301 - LER E TESTAR UM VALOR INTEIRO");
	printf ("\nFORNECER UM VALOR INTEIRO QUALQUER: ");
	scanf ("%d", &X);
	getchar( ); 
	if (X == 0)
		printf ("\nO VALOR DIGITADO FOI ZERO");
	else
		printf ("\nO VALOR DIGITADO NAO FOI ZERO");
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( ); 
}

/* output:

EXEMPLO301 - LER E TESTAR UM VALOR INTEIRO
FORNECER UM VALOR INTEIRO QUALQUER: 7698

O VALOR DIGITADO NAO FOI ZERO
PRESSIONAR <Enter> PARA TERMINAR.
*/

/*
EXEMPLO301 - LER E TESTAR UM VALOR INTEIRO
FORNECER UM VALOR INTEIRO QUALQUER: 0

O VALOR DIGITADO FOI ZERO
PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 302 > ler um real e testar de diferente de zero

void exemplo302 (void) {
	system ("cls"); 
	
	float X = 0.0;
	
	printf ("EXEMPLO302 - LER E TESTAR UM VALOR REAL");
	printf ("\nFORNECER UM VALOR REAL DIFERENTE DE ZERO: ");
	scanf ("%f", &X);
	getchar( ); 
	if(X != 0.0) //if sem chaves faz com que apenas a proxima expressao seja executada
		printf ("\nO VALOR DIGITADO FOI DIFERENTE DE ZERO");
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );	
}

/* output:

EXEMPLO302 - LER E TESTAR UM VALOR REAL
FORNECER UM VALOR REAL DIFERENTE DE ZERO: -0.666

O VALOR DIGITADO FOI DIFERENTE DE ZERO
PRESSIONAR <Enter> PARA TERMINAR.
*/

/*
EXEMPLO302 - LER E TESTAR UM VALOR REAL
FORNECER UM VALOR REAL DIFERENTE DE ZERO: 0

PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 303 > ler caractere e verificar se eh um algarismo

void clrscr ( ) {
	system ( "cls" );    // para Windows
}

void exemplo303 ( ) {
	clrscr ( ); // funcao para limpar a tela
	
	char X = '0';
	
	printf ("EXEMPLO303 - LER E TESTAR UM CARACTERE");
	printf ("\nFORNECER UM ALGARISMO QUALQUER:   ");
	scanf ("%c", &X);
	getchar( ); 
	if(X >= '0' && X <= '9')
	{
		printf ("\nO VALOR DIGITADO FOI UM ALGARISMO");
		printf ("\nO ALGARISMO DIGITADO FOI: %c", X);
	} 
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );
}

/* output:

EXEMPLO303 - LER E TESTAR UM CARACTERE
FORNECER UM ALGARISMO QUALQUER:   5

O VALOR DIGITADO FOI UM ALGARISMO
O ALGARISMO DIGITADO FOI: 5
PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 304 > ler caractere e testar se nao eh algarismo

void exemplo304 ( ) {
	system ("cls");
	
	char X =0;
	
	printf("EXEMPLO304 - LER E TESTAR CARACTERE");
	printf("\n\nFORNECER UM CARACTERE QUALQUER:   ");
	scanf ("%c", &X);
	getchar ( );
	if(!(X>='0' && X<='9'))
	{
		printf("\nNAO FOI DIGITADO UM ALGARISMO.");
		printf("\n\nFOI DIGITADO O CARACTERE: %c", X);
	}
	printf ("\n\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );
}

/* output:

EXEMPLO304 - LER E TESTAR CARACTERE

FORNECER UM CARACTERE QUALQUER:   y

NAO FOI DIGITADO UM ALGARISMO.

FOI DIGITADO O CARACTERE: y

PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 305 > ler e testar a igualdade de dois inteiros

void exemplo305 ( ) {
	system ("cls");
	
	int X =0, Y =0;
	
	printf ("EXEMPLO305 - LER E TESTAR DOIS VALORES INTEIROS");
	printf ("\nFORNECER UM VALOR INTEIRO QUALQUER: ");
	scanf ("%d", &X);
	getchar ( );
	printf ("\nFORNECER OUTRO VALOR INTEIRO QUALQUER: ");
	scanf ("%d", &Y);
	getchar ( );
	
	if(X==Y)
		printf("\nOS DOIS VALORES SAO IGUAIS");
	else
	{
		printf("\n%d ", X);
		printf("DIFERENTE DE %d", Y);
	}
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR. ");
	getchar( );
}

/* output:

EXEMPLO305 - LER E TESTAR DOIS VALORES INTEIROS
FORNECER UM VALOR INTEIRO QUALQUER: 667

FORNECER OUTRO VALOR INTEIRO QUALQUER: 20

667 DIFERENTE DE 20
PRESSIONAR <Enter> PARA TERMINAR.
*/

/*
EXEMPLO305 - LER E TESTAR DOIS VALORES INTEIROS
FORNECER UM VALOR INTEIRO QUALQUER: 43

FORNECER OUTRO VALOR INTEIRO QUALQUER: 43

OS DOIS VALORES SAO IGUAIS
PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 306 > ler e testar dois valores reais

void exemplo306 ( ) {
	system ("cls");
	
	double X =0.0, Y =0.0;
	
	printf ("EXEMPLO306 - LER E TESTAR DOIS VALORES REAIS");
	printf ("\n\nFORNECER UM VALOR REAL QUALQUER: ");
	scanf ("%lf", &X);
	getchar( );
	printf ("\nFORNECER OUTRO VALOR REAL QUALQUER: ");
	scanf ("%lf", &Y);
	getchar( ); 
	
	if(!(X==Y))
	{
		printf ("\n%lf", X);
		printf (" DIFERENTE DE ");
		printf ("%lf", Y);
	}
	else
	{
		printf ("VALORES IGUAIS");
	}
	
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );
}

/* output:

EXEMPLO306 - LER E TESTAR DOIS VALORES REAIS

FORNECER UM VALOR REAL QUALQUER: -25.7

FORNECER OUTRO VALOR REAL QUALQUER: -25.7
VALORES IGUAIS
PRESSIONAR <Enter> PARA TERMINAR.
*/

/*
EXEMPLO306 - LER E TESTAR DOIS VALORES REAIS

FORNECER UM VALOR REAL QUALQUER: 2

FORNECER OUTRO VALOR REAL QUALQUER: 1

2.000000 DIFERENTE DE 1.000000
PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 307 > tratar alternativas com valores logicos

void exemplo307 ( ) {
	system("cls");

	int X =0, Y =0;
	bool Z = false;
	
	printf ("EXEMPLO307 - TRATAR VALORES LOGICOS");
	printf ("\n\nFORNECER UM VALOR INTEIRO QUALQUER: ");
	scanf ("%d", &X);
	getchar( );
	printf ("\n\nFORNECER OUTRO VALOR INTEIRO QUALQUER: ");
	scanf ("%d", &Y);
	getchar( );
	
	Z = (X==Y); //== comparacao. se x e y forem iguais, z vai receber o valor 1, que significa true.
	if (Z)      // abreviacao de if (Z==true). a abreviacao de (Z==false) eh !(Z)
		printf("\n\nVALORES IGUAIS");
	else
		printf("\n\nVALORES DIFERENTES");
	
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );
}

/* output:

EXEMPLO307 - TRATAR VALORES LOGICOS

FORNECER UM VALOR INTEIRO QUALQUER: 500


FORNECER OUTRO VALOR INTEIRO QUALQUER: 1000


VALORES DIFERENTES
PRESSIONAR <Enter> PARA TERMINAR.
*/

/*
EXEMPLO307 - TRATAR VALORES LOGICOS

FORNECER UM VALOR INTEIRO QUALQUER: 678


FORNECER OUTRO VALOR INTEIRO QUALQUER: 678


VALORES IGUAIS
PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 308 > ler e testar uma letra

void exemplo308 ( ) {
	system ("cls");
	
	char X ='0';
	
	printf ("EXEMPLO308 - LER E TESTAR UMA LETRA");
	printf ("\n\nFORNECER UMA LETRA QUALQUER: ");
	scanf ("%c", &X);
	getchar ( );
	
	if(X>='A' && X<='Z')
		printf("\n\nFOI DIGITADA UMA LETRA MAIUSCULA");
	else if(X>='a' && X<='z') //ASCII table
		printf("\n\nFOI DIGITADA UMA LETRA MINUSCULA");
	else
		printf("NAO FOI DIGITADA UMA LETRA");
	
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );
}

/* output:

EXEMPLO308 - LER E TESTAR UMA LETRA

FORNECER UMA LETRA QUALQUER: g


FOI DIGITADA UMA LETRA MINUSCULA
PRESSIONAR <Enter> PARA TERMINAR.
*/

/*
EXEMPLO308 - LER E TESTAR UMA LETRA

FORNECER UMA LETRA QUALQUER: G


FOI DIGITADA UMA LETRA MAIUSCULA
PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 309 > comparar caracteres < , = e >

void exemplo309 ( ) {
	system ("cls");
	
	char X ='0';
	
	printf ("EXEMPLO309 - COMPARAR CARACTERES < , = , >");
	printf ("\nFORNECER UM DOS CARACTERES CITADOS: ");
	scanf ("%c", &X);
	getchar( ); 
	
	switch(X)
	{
		case'>': printf("FOI DIGITADO SINAL DE MAIOR");
			break; //sair do switch  imediatamente.
		case'=': printf("FOI DIGITADO SINAL DE IGUAL");
			break;
		case'<': printf("FOI DIGITADO SINAL DE MENOR");
			break;
		default: printf("FOI DIGITADO UM OUTRO CARACTERE QUALQUER");
	}
	
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );
}

/* output:

EXEMPLO309 - COMPARAR CARACTERES < , = , >
FORNECER UM DOS CARACTERES CITADOS: j
FOI DIGITADO UM OUTRO CARACTERE QUALQUER
PRESSIONAR <Enter> PARA TERMINAR.
*/

/*
EXEMPLO309 - COMPARAR CARACTERES < , = , >
FORNECER UM DOS CARACTERES CITADOS: =
FOI DIGITADO SINAL DE IGUAL
PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 310


void exemplo310 ( ) {
	system ("cls");

	char R ='0';
	
	printf ("EXEMPLO310 - IDENTIFICAR CARACTERES");
	printf ("\nFORNECER UM CARACTERE QUALQUER: ");
	scanf ("%c", &R);
	getchar( ); 
	
	switch (R)
	{
		case'A':
		case'E':
		case'I':
		case'O':
		case'U': printf("\nFOI DIGITADA UMA VOGAL");
			break;
		
		case'0':
		case'1':
		case'2':
		case'3':
		case'4':
		case'5':
		case'6':
		case'7':
		case'8':
		case'9': printf("\nFOI DIGITADO UM ALGARISMO");
			     printf ("\nO NUMERO CORRESPONDENTE = %d",(R-48)); //ASCII table
		         break;
		
		default: printf("\nFOI DIGITADO UM OUTRO CARACTERE QUALQUER");
	}
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );
}

/* output:

EXEMPLO310 - IDENTIFICAR CARACTERES
FORNECER UM CARACTERE QUALQUER: r

FOI DIGITADO UM OUTRO CARACTERE QUALQUER
PRESSIONAR <Enter> PARA TERMINAR.
*/

/*
EXEMPLO310 - IDENTIFICAR CARACTERES
FORNECER UM CARACTERE QUALQUER: a

FOI DIGITADO UM OUTRO CARACTERE QUALQUER
PRESSIONAR <Enter> PARA TERMINAR.
*/
//obs.: nao reconhece a como vogal, apenas A

//-------------------------- exemplo 401 > ler e imprimir 3 valores inteiros

void exemplo401 ( ) {
	system ("cls");
	
	int X=0, CONTADOR=0;
	
	printf ("EXEMPLO401 - LER E IMPRIMIR 03 VALORES INTEIROS");
	printf ("\n"); 
	
	CONTADOR=1;
	while (CONTADOR<=3)	//repetir
	{
		printf("\n");
		printf("%d. FORNECER UM VALOR INTEIRO: ", CONTADOR);
		scanf("%d", &X);
		getchar ( );
		printf("\nO VALOR DIGITADO FOI: %d\n", X);
		CONTADOR = CONTADOR+1;
	}	//vai repetir esse processo ate que na terceira vez o contador vire 4 e interrompa o while
	
	printf ("\nPRESSIONAR ENTER PARA TERMINAR");
	getchar ( );
}

/* output:
EXEMPLO401 - LER E IMPRIMIR 03 VALORES INTEIROS

1. FORNECER UM VALOR INTEIRO: 5

O VALOR DIGITADO FOI: 5

2. FORNECER UM VALOR INTEIRO: 198

O VALOR DIGITADO FOI: 198

3. FORNECER UM VALOR INTEIRO: 6

O VALOR DIGITADO FOI: 6

PRESSIONAR ENTER PARA TERMINAR
*/

//-------------------------- exemplo 402 > ler e imprimir N valores inteiros

void exemplo402 ( ) {
	system ("cls");
	
	int X=0, N=0, CONTADOR=0;
	
	printf("EXEMPLO402 - LER E IMPRIMIR (N) VALORES INTEIROS\n\n");
	printf("FORNECER O NUMERO DE VEZES QUE QUER INPUTAR VALORES (N): ");
	scanf("%d", &N);
	getchar ( );
	
	CONTADOR=1;
	while (CONTADOR<=N)
	{
		printf("\n%d.", CONTADOR);
		printf("\n");
		printf("\nFORNECER UM VALOR INTEIRO QUALQUER: ");
		scanf("%d", &X);
		getchar ( );
		printf("\nO VALOR DIGITADO FOI: %d\n", X);
		CONTADOR = CONTADOR+1;	
	}	//vai repetir esse processo enquanto CONTADOR for menor ou igual a N

	printf ("\nPRESSIONAR ENTER PARA TERMINAR");
	getchar ( );
}

/* output:
EXEMPLO402 - LER E IMPRIMIR (N) VALORES INTEIROS

FORNECER O NUMERO DE VEZES QUE QUER INPUTAR VALORES (N): 5

1.

FORNECER UM VALOR INTEIRO QUALQUER: 3

O VALOR DIGITADO FOI: 3

2.

FORNECER UM VALOR INTEIRO QUALQUER: 78

O VALOR DIGITADO FOI: 78

3.

FORNECER UM VALOR INTEIRO QUALQUER: 3456

O VALOR DIGITADO FOI: 3456

4.

FORNECER UM VALOR INTEIRO QUALQUER: 5

O VALOR DIGITADO FOI: 5

5.

FORNECER UM VALOR INTEIRO QUALQUER: 3

O VALOR DIGITADO FOI: 3

PRESSIONAR ENTER PARA TERMINAR
*/

//-------------------------- exemplo 403 > ler e imprimir N valores inteiros

void exemplo403 ( ) {
	system ("cls");

	int X=0, N=0;
	
	printf ("EXEMPLO403 - LER E IMPRIMIR (N) VALORES INTEIROS\n");
	printf ("\nFORNECER O NUMERO DE VEZES (N): ");
	scanf ("%d", &N);
	getchar ( );
	
	while (N>0)
	{
		printf("\n%d.", N);
		printf("\nFORNECER UM VALOR INTEIRO QUALQUER: ");
		scanf("%d", &X);
		getchar ( );
		printf("\nO VALOR DIGITADO FOI: %d\n", X);
		N = N-1;
	}	//vai repetir ate que N se iguale a 0 (ou enquanto N<0)

	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );
}

/* output:
EXEMPLO403 - LER E IMPRIMIR (N) VALORES INTEIROS

FORNECER O NUMERO DE VEZES (N): 2

2.
FORNECER UM VALOR INTEIRO QUALQUER: 30

O VALOR DIGITADO FOI: 30

1.
FORNECER UM VALOR INTEIRO QUALQUER: -7

O VALOR DIGITADO FOI: -7

PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 404 > ler e imprimir 3 valores inteiros

void exemplo404 ( ) {
	system ("cls");

	int R=0, CONTADOR=0;
	
	printf("EXEMPLO404 - LER E IMPRIMIR 03 VALORES INTEIROS\n\n");
	
	for(CONTADOR=1; CONTADOR<=3; CONTADOR=CONTADOR+1)
	{
		printf("\n%d. FORNECER UM VALOR INTEIRO: ", CONTADOR);
		scanf("%d", &R);
		getchar ( );
		printf("\nO VALOR DIGITADO FOI: %d\n", R);
	}	
		/*
		The syntax of the for loop is for (initialization; condition; update) {loop body}.
		- a inicializacao que torna a variavel CONTADOR=1 ocorre apenas uma vez antes do loop comecar.
		- depois vem a condicao, e em seguida a iteracao, que acontece repetidamente ate que a condicao NAO seja mais verdadeira/se torne FALSA
		*/

	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar ( );
}

/* output:
EXEMPLO404 - LER E IMPRIMIR 03 VALORES INTEIROS


1. FORNECER UM VALOR INTEIRO: 347856657

O VALOR DIGITADO FOI: 347856657

2. FORNECER UM VALOR INTEIRO: 2

O VALOR DIGITADO FOI: 2

3. FORNECER UM VALOR INTEIRO: 4

O VALOR DIGITADO FOI: 4

PRESSIONAR <Enter> PARA TERMINAR.
*/

/*
EXEMPLO404 - LER E IMPRIMIR 03 VALORES INTEIROS


1. FORNECER UM VALOR INTEIRO: 5.876

O VALOR DIGITADO FOI: 5

2. FORNECER UM VALOR INTEIRO: 876
O VALOR DIGITADO FOI: 876

3. FORNECER UM VALOR INTEIRO: 2

O VALOR DIGITADO FOI: 2

PRESSIONAR <Enter> PARA TERMINAR.
*/
//eu nao inseri o valor 876. apenas escrevi 5.876 e o programa "separou" em dois inteiros.
//testei inputar "abc" ao inves de um valor inteiro. nao aceitou, o programa todo simplesmente finalizou.

//-------------------------- exemplo 405 > ler e imprimir N valores inteiros

void exemplo405 ( ) {
	system ("cls");

	int Z=0, N=0, CONTADOR=0;
	
	printf ("EXEMPLO405 - LER E IMPRIMIR (N) VALORES INTEIROS\n");
	printf ("\n\nFORNECER O NUMERO DE VEZES (N): ");
	scanf ("%d", &N);
	getchar ( );
	
	for(CONTADOR=1; CONTADOR<=N; CONTADOR++) //mesma coisa de escrever contador=contador+1
	{
		printf("\n%d. FORNECER UM VALOR INTEIRO: ", CONTADOR);
		scanf("%d", &Z);
		getchar ( );
		printf("\nO VALOR DIGITADO FOI: %d\n", Z);	
	}
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );
}

/* output:
EXEMPLO405 - LER E IMPRIMIR (N) VALORES INTEIROS

FORNECER O NUMERO DE VEZES (N): 2

1. FORNECER UM VALOR INTEIRO: 1

O VALOR DIGITADO FOI: 1

2. FORNECER UM VALOR INTEIRO: -6

O VALOR DIGITADO FOI: -6

PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 406 > ler e imprimir 3 valores inteiros

void exemplo406 ( ) {
	system ("cls");

	int W=0, COUNTER=0;
	
	printf("EXEMPLO406 - LER E IMPRIMIR 03 VALORES INTEIROS\n");
	
	COUNTER=1;
	do
	{
		printf("\n\n%d. FORNECER UM VALOR INTEIRO: ", COUNTER);
		scanf("%d", &W);
		getchar ( );
		printf("\nO VALOR DIGITADO FOI: %d", W);
		COUNTER++;
	}
	while(COUNTER<=3); //FAZER ENQUANTO essa condicao for true 
	
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar ( );
}

/* output:
EXEMPLO406 - LER E IMPRIMIR 03 VALORES INTEIROS


1. FORNECER UM VALOR INTEIRO: 2

O VALOR DIGITADO FOI: 2

2. FORNECER UM VALOR INTEIRO: -7

O VALOR DIGITADO FOI: -7

3. FORNECER UM VALOR INTEIRO: 3265

O VALOR DIGITADO FOI: 3265
PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 407 > ler e imprimir N valores inteiros

void exemplo407 ( ) {
	system ("cls");
	
	int X=0, COUNTER=0;
	
	printf("EXEMPLO407 - LER E IMPRIMIR (N) VALORES INTEIROS\n");
	printf("\nFORNECER O NUMERO DE VEZES (N) : ");
	scanf("%d", &COUNTER);
	getchar ( );
	
	do
	{
		printf("\n\n%d. FORNECER UM VALOR INTEIRO: ", COUNTER);
		scanf("%d", &X);
		getchar ( );
		printf("\nO VALOR DIGITADO FOI: %d", X);
		COUNTER=COUNTER-1;
	}
	while (COUNTER>0);
	
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar ( );
}

/* output:
EXEMPLO407 - LER E IMPRIMIR (N) VALORES INTEIROS

FORNECER O NUMERO DE VEZES (N) : 2


2. FORNECER UM VALOR INTEIRO: 3

O VALOR DIGITADO FOI: 3

1. FORNECER UM VALOR INTEIRO: 4

O VALOR DIGITADO FOI: 4
PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 408 > ler e imprimir inteiros diferentes de zero

void exemplo408 ( ) {
	system ("cls");

	int X=0;
	
	printf ("EXEMPLO408 - LER E IMPRIMIR INTEIROS NAO NULOS\n");
	printf ("\nFORNECER UM VALOR INTEIRO (0 = PARAR) : ");
	scanf ("%d", &X);
	getchar( ); 
	
	while(X!=0)
	{
		printf("\nO VALOR DIGITADO FOI: %d", X);
		printf("\n\nDIGITE UM OUTRO VALOR INTEIRO QUALQUER: ");
		scanf("%d", &X);
		getchar ( );
	}

	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );
}

/* output:
EXEMPLO408 - LER E IMPRIMIR INTEIROS NAO NULOS

FORNECER UM VALOR INTEIRO (0 = PARAR) : 3

O VALOR DIGITADO FOI: 3

DIGITE UM OUTRO VALOR INTEIRO QUALQUER: 5

O VALOR DIGITADO FOI: 5

DIGITE UM OUTRO VALOR INTEIRO QUALQUER: 0

PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 409 > ler um inteiro diferente de zero

void exemplo409 ( ) {
	system ("cls");
	
	int V=0;
	
	printf ("EXEMPLO409 - PARA LER UM INTEIRO NAO NULO\n");
	printf ("\nFORNECER UM VALOR DIFERENTE DE ZERO : ");
	scanf ("%d", &V);
	getchar( );
	
	while (V==0) //coloca 2 = pois esta fazendo uma comparacao, nao esta atribuindo valor
	{
		printf("\n\nFORNECER UM VALOR DIFERERNTE DE ZERO: ");
		scanf("%d", &V);
		getchar( );
	}
	
	printf("\n\nFOI DIGITADO UM NUMERO DIFERENTE DE ZERO\n");
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );
}

/* output:
EXEMPLO409 - PARA LER UM INTEIRO NAO NULO

FORNECER UM VALOR DIFERENTE DE ZERO : 2


FOI DIGITADO UM NUMERO DIFERENTE DE ZERO

PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 410 > ler um inteiro diferente de zero

void exemplo410 ( ) {
	system ("cls");
	
	int X=0;
	
	printf("EXEMPLO410 - LER UM INTEIRO NAO NULO\n\n");
	
	do
	{
		printf("\n\nFORNECER UM VALOR DIFERERNTE DE ZERO: ");
		scanf("%d", &X);
		getchar( );	
	}
	while (X==0);
	
	printf("\n\nFOI DIGITADO UM NUMERO DIFERENTE DE ZERO\n");
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );
}

/* output:
EXEMPLO410 - LER UM INTEIRO NAO NULO



FORNECER UM VALOR DIFERERNTE DE ZERO: 2


FOI DIGITADO UM NUMERO DIFERENTE DE ZERO

PRESSIONAR <Enter> PARA TERMINAR.
*/

//chamando os metodos

int main ( int argc, char* argv[] ) {
	exemplo301( );
	exemplo302( );
	exemplo303( );
	exemplo304( );
	exemplo305( );
	exemplo306( );
	exemplo307( );
	exemplo308( );
	exemplo309( );
	exemplo310( );
	
	exemplo401( );
	exemplo402( );
	exemplo403( );
	exemplo404( );
	exemplo405( );
	exemplo406( );
	exemplo407( );
	exemplo408( );
	exemplo409( );
	exemplo410( );

	return (0);
}

/*
---------------------------------------------- documentacao complementar


---------------------------------------------- notas / observacoes / comentarios

Organizei o codigo de maneira a descrever cada exemplo em um metodo vazio e depois chama-los na main, testando varios exemplos de uma vez so, para ja cumprir o que foi pedido na tarefa extra E2.

---------------------------------------------- previsao de testes

a.) Compilacao sem erros e verificacao das saidas de acordo com o codigo

b.) insercao de valores e verificacao de retornos e operacoes

---------------------------------------------- historico

Versao  Data     Modificacao

 0.0    21/02    exemplos de 101 a 110
 1.0    22/02    exemplos de 301 a 410

---------------------------------------------- testes

Versao    Teste
 0.0        01. ( OK )    a.) exemplos 101 a 105
 0.0        02. ( OK )    a.) exemplos 106 a 110
 0.0        03. ( fail )  erro ao compilar, pois eu tinha declarado as variaveis fora das funcoes de cada exemplo.
 0.0        04. ( OK )    b.) exemplos 201 a 210

 1.0        01. ( OK )    b.) exemplos 301 a 310
 1.0        02. ( OK )    b.) exemplos 401 a 410
*/
