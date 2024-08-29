/*
	Exercicio000 - 101 ate 210 - v0.0. - 21/02/2024
	Autor: Raquel de Parde Motta
	Matricula: 854017
*/

// dependencias
#include <stdio.h>	// para as entradas e saidas
#include <stdlib.h> // para outras funcoes de uso geral
#include <stdbool.h> // para valores logicos
#include <string.h> // para lidar com caracteres
#include <math.h>


//-------------------------- exemplo 101

void exemplo101 (void) {
	printf ("EXEMPLO101 - PRIMEIRO EXEMPLO EM C");
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar ( ); // para esperar
}

/* output:

EXEMPLO101 - PRIMEIRO EXEMPLO EM C
PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 102

void exemplo102 (void) {
	system ("cls"); // (Windows) para limpar a tela
	printf ("EXEMPLO102 - PRIMEIRO EXEMPLO EM C\n");
	system ("pause"); // (Windows) para esperar
	// getchar( ); // para esperar
}

/* output:

EXEMPLO102 - PRIMEIRO EXEMPLO EM C
Press any key to continue . . .
*/

//-------------------------- exemplo 103

void clrscr ( ) {
	system ( "cls" );    // para Windows
}

void exemplo103 ( ) {
	clrscr ( ); // funcao para limpar a tela
	printf ("EXEMPLO103 - PRIMEIRO EXEMPLO EM C");
	printf ("\n");
	printf ("MATRICULA: 854017  ALUNO : Raquel de Parde Motta");
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );
}

/* output:

EXEMPLO103 - PRIMEIRO EXEMPLO EM C
MATRICULA: 854017  ALUNO : Raquel de Parde Motta
PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 104

void exemplo104 ( ) {
	printf ("\n\nEXEMPLO104 - PRIMEIRO EXEMPLO EM C");
	printf ("\n");
	printf ("MATRICULA: 854017 ALUNO : Raquel de Parde Motta");
	printf ("\n");
	printf ("PRESSIONAR <Enter> PARA TERMINAR. ");
	getchar( ); // para esperar
}

/* output:

EXEMPLO104 - PRIMEIRO EXEMPLO EM C
MATRICULA: 854017 ALUNO : Raquel de Parde Motta
PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 105

void exemplo105 ( ) {
	printf ("\n\nEXEMPLO105 - PRIMEIRO EXEMPLO EM C");
	printf ("\nMATRICULA: 854017 ALUNO : Raquel de Parde Motta");
	printf ("\nEXEMPLOS DE VALORES : ");
	printf ("\nCARACTERE : %c", 'A'); // letra ou simbolo
	printf ("\nINTEIRO : %d", 10);    // valor sem parte fracionaria
	printf ("\nREAL : %f", 3.1415);   // valor com parte fracionaria
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR. ");
	getchar( );
}

/* output:

EXEMPLO105 - PRIMEIRO EXEMPLO EM C
MATRICULA: 854017 ALUNO : Raquel de Parde Motta
EXEMPLOS DE VALORES :
CARACTERE : A
INTEIRO : 10
REAL : 3.141500
PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 106

#define PI 3.1415 //definicao de macro (nome para substiuir um valor constante)

void exemplo106 ( ) {
	printf ("\n\nEXEMPLO106 - PRIMEIRO EXEMPLO EM C ");
	printf ("\nMATRICULA: 854017 ALUNO : Raquel de Parde Motta");
	printf ("\nEXEMPLOS DE VALORES : ");
	printf ("\nCARACTERE : %c", 'A'); // letra ou simbolo
	printf ("\nINTEIRO : %d", 10); // valor sem parte fracionaria
	printf ("\nREAL : %f", PI); // emprego de macro
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );
}

/* output:

EXEMPLO106 - PRIMEIRO EXEMPLO EM C
MATRICULA: 854017 ALUNO : Raquel de Parde Motta
EXEMPLOS DE VALORES :
CARACTERE : A
INTEIRO : 10
REAL : 3.141500
PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 107

void exemplo107 ( ) {
	const float PIfloat = 3.14; //com nome e tipo (melhor)
	printf ("\n\nEXEMPLO107 - PRIMEIRO EXEMPLO EM C");
	printf ("\nMATRICULA: 854017 ALUNO : Raquel de Parde Motta");
	printf ("\nEXEMPLOS DE VALORES : ");
	printf ("\nCARACTERE : %c", 'A'); // letra ou simbolo
	printf ("\nINTEIRO : %d", 10); // valor sem parte fracionaria
	printf ("\nREAL : %f", PIfloat);  // constante real
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );
}

/* output:

EXEMPLO107 - PRIMEIRO EXEMPLO EM C
MATRICULA: 854017 ALUNO : Raquel de Parde Motta
EXEMPLOS DE VALORES :
CARACTERE : A
INTEIRO : 10
REAL : 3.140000
PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 108

void exemplo108 ( ) {
	const float PIfloat = 3.14;
	float X = 10.01;	//definicao de variavel real com atribuicao de valor inicial
	printf ("\n\nEXEMPLO108 - PRIMEIRO EXEMPLO EM C");
	printf ("\nMATRICULA: 854017 ALUNO : Raquel de Parde Motta");
	printf ("\nEXEMPLOS DE VALORES : ");
	printf ("\nCARACTERE : %c", 'A'); // letra ou simbolo
	printf ("\nINTEIRO : %d", 10); // valor sem parte fracionaria
	printf ("\nREAL : %f", PIfloat); // constante real
	printf ("\nREAL : %f", X); // variavel real
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );
}

/* output:

EXEMPLO108 - PRIMEIRO EXEMPLO EM C
MATRICULA: 854017 ALUNO : Raquel de Parde Motta
EXEMPLOS DE VALORES :
CARACTERE : A
INTEIRO : 10
REAL : 3.140000
REAL : 10.010000
PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 109

void exemplo109 ( ) {
	int I = 10; //definicao de variavel inteira
	const float PIfloat = 3.14;
	float X = 10.01;
	printf ("\n\nEXEMPLO109 - PRIMEIRO EXEMPLO EM C");
	printf ("\nMATRICULA: 854017 ALUNO : Raquel de Parde Motta");
	printf ("\nEXEMPLOS DE VALORES : ");
	printf ("\nINTEIRO : %i", I);
	printf ("\nREAL : %f", X);
	printf ("\nREAL : %f", PIfloat);
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );
}

/* output:

EXEMPLO109 - PRIMEIRO EXEMPLO EM C
MATRICULA: 854017 ALUNO : Raquel de Parde Motta
EXEMPLOS DE VALORES :
INTEIRO : 10
REAL : 10.010000
REAL : 3.140000
PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 110


void exemplo110 ( ) {
	int I = 10;
	float X = 10.01;
	const double PIdouble = 3.14;	//definicao de constante com nome e tipo (melhor)
	char N = '\n';
	printf ("\n\nEXEMPLO110 - PRIMEIRO EXEMPLO EM C");
	printf ("\nMATRICULA: 854017 ALUNO : Raquel de Parde Motta");
	printf ("%c%s", N, "EXEMPLOS DE VALORES : ");
	printf ("%c%s%i", N, "INTEIRO : ", I);
	printf ("%c%s%f", N, "REAL : ", X);
	printf ("%c%s%lf", N, "REAL : ", PIdouble);
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );
}

/* output:

EXEMPLO110 - PRIMEIRO EXEMPLO EM C
MATRICULA: 854017 ALUNO : Raquel de Parde Motta
EXEMPLOS DE VALORES :
INTEIRO : 10
REAL : 10.010000
REAL : 3.140000
PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 201

void exemplo201 ( ) {
	system ("cls");

	int Z = 0; //variavel

	printf ("EXEMPLO201 - LER E IMPRIMIR UM VALOR INTEIRO");
	printf("\nFORNECER UM VALOR INTEIRO QUALQUER:");
	scanf ("%d", &Z);
	getchar ( );
	printf ("O VALOR DIGITADO FOI: %d", Z);
	printf ("\nPRESSIONAR ENTER PARA TERMINAR");
	getchar ( );
}

/* output:

EXEMPLO201 - LER E IMPRIMIR UM VALOR INTEIRO
FORNECER UM VALOR INTEIRO QUALQUER:70
O VALOR DIGITADO FOI: 70
PRESSIONAR ENTER PARA TERMINAR
*/

//-------------------------- exemplo 202

void exemplo202 ( ) {
	system ("cls");

	double A = 0.0;

	printf ("EXEMPLO202 - LER E IMPRIMIR UM VALOR REAL");
	printf ("\nFORNECER UM VALOR REAL QUALQUER:");
	scanf ("%lf", &A);
	getchar ( );
	printf ("O VALOR DIGITADO foi %lf", A);
	printf ("\nPRESSIONAR ENTER PARA TERMINAR");
	getchar ( );
}

/* output:

EXEMPLO202 - LER E IMPRIMIR UM VALOR REAL
FORNECER UM VALOR REAL QUALQUER:89.324
O VALOR DIGITADO foi 89.324000
PRESSIONAR ENTER PARA TERMINAR
*/

//-------------------------- exemplo 203

void exemplo203 ( ) {
	system ("cls");

	char C = '0';

	printf ("EXEMPLO203 - LER E IMPRIMIR UM CARACTERE");
	printf ("\nFORNECER UM CARACTERE QUALQUER: ");
	scanf ("%c", &C);
	getchar( );
	printf ("\nO VALOR DIGITADO FOI: %c", C);
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );
}

/* output:

EXEMPLO203 - LER E IMPRIMIR UM CARACTERE
FORNECER UM CARACTERE QUALQUER: t

O VALOR DIGITADO FOI: t
PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 204

void exemplo204 ( ) {
	system ("cls");

	char D[10];

	printf ("EXEMPLO204 - LER E IMPRIMIR, NO MAXIMO, 09 CARACTERES");
	printf ("\nDIGITE, NO MAXIMO, 09 CARACTERES QUAISQUER: ");
	scanf ("%s", D);
	getchar ( );
	printf ("\nFOI DIGITADO: %s", D);
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar ( );
}

/* output:

EXEMPLO204 - LER E IMPRIMIR, NO MAXIMO, 09 CARACTERES
DIGITE, NO MAXIMO, 09 CARACTERES QUAISQUER: palavras

FOI DIGITADO: palavras
PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 205 > ler e somar dois valores inteiros

void exemplo205 ( ) {
	system ("cls");

	int X = 0, Y = 0, Z = 0;

	printf ("EXEMPLO205 - LER E SOMAR DOIS VALORES INTEIROS");
	printf ("\nFORNECER UM VALOR INTEIRO QUALQUER: ");
	scanf ("%d", &X);
	getchar( );
	printf ("\nFORNECER OUTRO VALOR INTEIRO QUALQUER: ");
	scanf ("%d", &Y);
	getchar( );

	Z = X + Y;

	printf ("\nA SOMA DOS DOIS = %d", Z);
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );
}

/* output:

EXEMPLO205 - LER E SOMAR DOIS VALORES INTEIROS
FORNECER UM VALOR INTEIRO QUALQUER: 4

FORNECER OUTRO VALOR INTEIRO QUALQUER: -9

A SOMA DOS DOIS = -5
PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 206 > ler e subtrair dois valores reais

void exemplo206 ( ) {
	system ("cls");

	float X = 0.0, Y = 0.0, Z = 0.0;

	printf ("EXEMPLO206 - LER E SUBTRAIR DOIS VALORES REAIS");
	printf ("\nFORNECER UM VALOR REAL QUALQUER: ");
	scanf ("%f", &X);
	getchar( );
	printf ("\nFORNECER OUTRO VALOR REAL QUALQUER: ");
	scanf ("%f", &Y);
	getchar( );

	Z = X - Y;

	printf ("\nA DIFERENCA ENTRE OS DOIS = %f", Z);
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar ( );
}

/* output:

EXEMPLO206 - LER E SUBTRAIR DOIS VALORES REAIS
FORNECER UM VALOR REAL QUALQUER: 76534

FORNECER OUTRO VALOR REAL QUALQUER: 2000

A DIFERENCA ENTRE OS DOIS = 74534.000000
PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 207 > operar valores logicos variaveis

void exemplo207 ( ) {
	system ("cls");

	bool X = false, Y = false, Z = false;

	printf ("EXEMPLO207 - OPERAR VALORES LOGICOS");

	X = true;
	Y = false;

	Z = X || Y; //OU

	printf ("\nA DISJUNCAO ENTRE VERDADEIRO E FALSO = %d", Z);

	Z = X && Y; //E

	printf ("\nA CONJUNCAO ENTRE VERDADEIRO E FALSO = %d", Z);
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar ( );
}

/* output:

EXEMPLO207 - OPERAR VALORES LOGICOS
A DISJUNCAO ENTRE VERDADEIRO E FALSO = 1
A CONJUNCAO ENTRE VERDADEIRO E FALSO = 0
PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 208 > programa para calcular a velocidade de um veiculo

void exemplo208 ( ) {
	system ("cls");

	double D = 0.0,	//distancia
	       T = 0.0,	//tempo
	       V = 0.0;	//velocidade

	printf ("EXEMPLO208 - CALCULAR A VELOCIDADE DE UM VEICULO");
	printf ("\nFORNECER UMA DISTANCIA QUALQUER EM METROS: ");
	scanf ("%lf", &D);
	getchar ( );
	printf ("\nFORNECER O TEMPO PARA PERCORRE-LA EM SEGUNDOS: ");
	scanf ("%lf", &T);
	getchar ( );

	V = D / T;

	printf ("\n V = D / T = %lf%s", V, "m/s");
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );
}

/* output:

EXEMPLO208 - CALCULAR A VELOCIDADE DE UM VEICULO
FORNECER UMA DISTANCIA QUALQUER EM METROS: 300

FORNECER O TEMPO PARA PERCORRE-LA EM SEGUNDOS: 30

V = D / T = 10.000000m/s
PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 209 > programa para comparar caracteres com uma senha constante

void exemplo209 ( ) {
	system ("cls");

	const char SENHA[5] = "XXXX"; //constante
	char S[10];			          //variavel
	
	printf("DIGITE SUA SENHA DE 4 CARACTERES E APERTE ENTER:\n");
	scanf("%s", &S); // OBS.: NAO usar o (&) para caracteres !
	getchar( );
	printf("\nA COMPARACAO COM A SENHA = %d", (strcmp(S, SENHA) == 0) ? 1 : 0);
	//se o resultado retornado pela strcmp = 0, significa que as strings sao iguais.
	//o operador ternario faz aparecer 1 na tela se esse retorno de 0 ocorrer.
	printf ("\n\nSe apareceu 1 na sua tela, as senhas sao iguais. Caso contario, sao diferentes.");
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );
}

/* output:

DIGITE SUA SENHA DE 4 CARACTERES E APERTE ENTER:
diyg

A COMPARACAO COM A SENHA = 0
Se apareceu 1 na sua tela, as senhas sao iguais. Caso contario, sao diferentes.
PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 210 > para calcular o arco trigonometrico de um seno

void exemplo210 ( ) {
	system ("cls");

	const double PI_ = 3.14;

	double arco = 0.0, cosseno = 0.0, seno = 0.0, tangente = 0.0;

	printf ("EXEMPLO210 - CALCULAR O ARCO TRIGONOMETRICO DE UM SENO");
	printf ("\nFORNECER O VALOR DO SENO: ");
	scanf ("%lf", &seno);
	getchar ( );

	cosseno = sqrt(1.0 - pow(seno, 2));
	tangente = seno / cosseno;
	arco = atan(tangente);

	printf ("\nO ARCO TRIGONOMETRICO EM GRAUS = %lf", (arco*180.0/PI_) );
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );
}

/* output:
EXEMPLO210 - CALCULAR O ARCO TRIGONOMETRICO DE UM SENO
FORNECER O VALOR DO SENO: 0.707

O ARCO TRIGONOMETRICO EM GRAUS = 45.014169
PRESSIONAR <Enter> PARA TERMINAR.
*/

//chamando os metodos

int main ( int argc, char* argv[] ) {
	exemplo101( );
	exemplo102( );
	exemplo103( );
	exemplo104( );
	exemplo105( );
	exemplo106( );
	exemplo107( );
	exemplo108( );
	exemplo109( );
	exemplo110( );
	
	exemplo201( );
	exemplo202( );
	exemplo203( );
	exemplo204( );
	exemplo205( );
	exemplo206( );
	exemplo207( );
	exemplo208( );
	exemplo209( );
	exemplo210( );

	return (0);
}

/*
---------------------------------------------- documentacao complementar


---------------------------------------------- notas / observacoes / comentarios

Organizei o codigo de maneira a descrever cada exemplo em um metodo vazio e depois chama-los na main, testando varios exemplos de uma vez so, para ja cumprir o que foi pedido na tarefa extra E2.

---------------------------------------------- previsao de testes

a.) Compilacao sem erros e verificacao das saidas de acordo com o codigo

b.) insercao de valores e verificacao de retornos e operacoes
----> ao executar, notei alguns erros pequenos como mandar imprimir a mesma frase duas vezes, ou esquecer de imprimir uma frase. as operacoes e funcoes, no entanto, todas funcionaram adequadamente.

---------------------------------------------- historico

Versao  Data     Modificacao

 0.0    21/02    exemplos de 101 a 110

---------------------------------------------- testes

Versao    Teste
 0.0        01. ( OK )    a.) exemplos 101 a 105
 0.0        02. ( OK )    a.) exemplos 106 a 110
 0.0        03. ( fail )  erro ao compilar, pois eu tinha declarado as variaveis fora das funcoes de cada exemplo.
 0.0        04. ( OK )    b.) exemplos 201 a 210


*/
