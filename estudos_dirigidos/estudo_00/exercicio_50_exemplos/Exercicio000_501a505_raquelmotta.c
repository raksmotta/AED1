/*
	Exercicio000 - v2.0. - 501 ate 505 - 23/02/2024
	Autor: Raquel de Parde Motta
	Matricula: 854017
*/

// dependencias
#include <stdio.h>	// para as entradas e saidas
#include <stdlib.h> // para outras funcoes de uso geral
#include <stdbool.h> // para valores logicos
#include <string.h> // para lidar com caracteres
#include <math.h>


//-------------------------- exemplo 501 > chamada de procedimento sem parametros

void P1 (void)
{
	printf ("\n");
	printf ("\nCHAMADO O PROCEDIMENTO P1 SEM PARAMETROS");
	printf ("\n");
}

void exemplo501 (void) 
{
	printf ("EXEMPLO0501 - CHAMADA A UM PROCEDIMENTO");
	P1( ); 	// chamada ao procedimento
	printf ("\n");
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( ); 
}

/* output:

*/

//-------------------------- exemplo 502 > mostrar passagens de parametros

int A=0;	//variavel em contexto global

void P2 (void)
{
	printf ("\n");
	printf ("\nCHAMADO O PROCEDIMENTO P2 %d VEZ(ES)", A);
	printf ("\n");	
}

void exemplo502 (void) 
{
	system ("cls"); 
	
	printf ("EXEMPLO0502 - CHAMADA COM VARIAVEL GLOBAL\n");
	
	for (A=1; A<=5; A++)
		P2( ); // chamar 5 vezes
	printf ("\n");

	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );	
}

/* output:

EXEMPLO0502 - CHAMADA COM VARIAVEL GLOBAL


CHAMADO O PROCEDIMENTO P2 1 VEZ(ES)


CHAMADO O PROCEDIMENTO P2 2 VEZ(ES)


CHAMADO O PROCEDIMENTO P2 3 VEZ(ES)


CHAMADO O PROCEDIMENTO P2 4 VEZ(ES)


CHAMADO O PROCEDIMENTO P2 5 VEZ(ES)


PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 503 > ler caractere e verificar se eh um algarismo

int B=0;	//variavel em contexto global

void P3 ( ) 
{
	B=B+1;	//avancar o contexto
	
	printf ("\nCHAMADO O PROCEDIMENTO P3 %d VEZ(ES)", B);
	printf ("\n");
	
	if(B<5)
		P3( );	//chamar o  procedimento recursivamente
	printf ("\nRETORNANDO AO PROCEDIMENTO P3 PARA A CHAMADA %d", B);
	
	B=B-1; 	//retornar ao contexto anterior
	getchar ( ); 
}

void exemplo503 ( ) 
{
	system ("cls"); 
	
	printf ("EXEMPLO0503 - CHAMADA/RETORNO COM VARIAVEL GLOBAL\n");
	
	B=0;
	P3( ); 	// OBSERVAR A RECURSIVIDADE !
	
	printf ("\n");
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );
}

/* output:

EXEMPLO0503 - CHAMADA/RETORNO COM VARIAVEL GLOBAL
CHAMADO O PROCEDIMENTO P3 1 VEZ(ES)

CHAMADO O PROCEDIMENTO P3 2 VEZ(ES)

CHAMADO O PROCEDIMENTO P3 3 VEZ(ES)

CHAMADO O PROCEDIMENTO P3 4 VEZ(ES)

CHAMADO O PROCEDIMENTO P3 5 VEZ(ES)

RETORNANDO AO PROCEDIMENTO P3 PARA A CHAMADA 5

RETORNANDO AO PROCEDIMENTO P3 PARA A CHAMADA 4

RETORNANDO AO PROCEDIMENTO P3 PARA A CHAMADA 3

RETORNANDO AO PROCEDIMENTO P3 PARA A CHAMADA 2

RETORNANDO AO PROCEDIMENTO P3 PARA A CHAMADA 1


PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 504 > mostrar passagens de parametros

void P4 (int C)
{
	printf ("\nCHAMADO O PROCEDIMENTO P4 %d VEZ(ES)\n", C);

	if(C<5)
		P4(C+1); // chamar recursivamente com parametro
	
	printf ("\nRETORNANDO AO PROCEDIMENTO P4 PARA A CHAMADA %d", C);
	getchar ( );
}

void exemplo504 ( ) {
	system ("cls");

	printf ("EXEMPLO0504 - CHAMADA/RETORNO COM PARAMETRO\n");
	P4(1); 	// OBSERVAR REPETICAO FINITA, SEM VARIAVEL GLOBAL !
	
	printf ("\n");
	printf ("\n\nPRESSIONAR <Enter> PARA TERMINAR.");
	getchar( );
}

/* output:

EXEMPLO0504 - CHAMADA/RETORNO COM PARAMETRO

CHAMADO O PROCEDIMENTO P4 1 VEZ(ES)

CHAMADO O PROCEDIMENTO P4 2 VEZ(ES)

CHAMADO O PROCEDIMENTO P4 3 VEZ(ES)

CHAMADO O PROCEDIMENTO P4 4 VEZ(ES)

CHAMADO O PROCEDIMENTO P4 5 VEZ(ES)

RETORNANDO AO PROCEDIMENTO P4 PARA A CHAMADA 5

RETORNANDO AO PROCEDIMENTO P4 PARA A CHAMADA 4

RETORNANDO AO PROCEDIMENTO P4 PARA A CHAMADA 3

RETORNANDO AO PROCEDIMENTO P4 PARA A CHAMADA 2

RETORNANDO AO PROCEDIMENTO P4 PARA A CHAMADA 1



PRESSIONAR <Enter> PARA TERMINAR.
*/

//-------------------------- exemplo 505 > mostrar passagem de parametro por valor

void P5 (int D)
{
	printf ("\nCHAMADO O PROCEDIMENTO P5 %d VEZ(ES)\n", D);
	
	if(D>1)
		P5(D-1);
	
	printf ("\nRETORNANDO AO PROCEDIMENTO P5 PARA A CHAMADA %d", D);
	getchar ( );	
}

void exemplo505 ( ) 
{
	system ("cls");

	printf ("EXEMPLO0505 - CHAMADA/RETORNO COM PARAMETRO\n");
	P5(5); 	// OBSERVAR REPETICAO FINITA, SEM VARIAVEL GLOBAL !
	
	printf ("\n");
	printf ("\nPRESSIONAR <Enter> PARA TERMINAR. ");
	getchar( );
}

/* output:

EXEMPLO0505 - CHAMADA/RETORNO COM PARAMETRO

CHAMADO O PROCEDIMENTO P5 5 VEZ(ES)

CHAMADO O PROCEDIMENTO P5 4 VEZ(ES)

CHAMADO O PROCEDIMENTO P5 3 VEZ(ES)

CHAMADO O PROCEDIMENTO P5 2 VEZ(ES)

CHAMADO O PROCEDIMENTO P5 1 VEZ(ES)

RETORNANDO AO PROCEDIMENTO P5 PARA A CHAMADA 1

RETORNANDO AO PROCEDIMENTO P5 PARA A CHAMADA 2

RETORNANDO AO PROCEDIMENTO P5 PARA A CHAMADA 3

RETORNANDO AO PROCEDIMENTO P5 PARA A CHAMADA 4

RETORNANDO AO PROCEDIMENTO P5 PARA A CHAMADA 5


PRESSIONAR <Enter> PARA TERMINAR.
*/


//chamando os metodos

int main ( int argc, char* argv[] ) {
	exemplo501( );
	exemplo502( );
	exemplo503( );
	exemplo504( );
	exemplo505( );

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
 2.0    23/02    exemplos de 501 a 505

---------------------------------------------- testes

Versao    Teste
 0.0        01. ( OK )    a.) exemplos 101 a 105
 0.0        02. ( OK )    a.) exemplos 106 a 110
 0.0        03. ( fail )  erro ao compilar, pois eu tinha declarado as variaveis fora das funcoes de cada exemplo.
 0.0        04. ( OK )    b.) exemplos 201 a 210

 1.0        01. ( OK )    b.) exemplos 301 a 310
 1.0        02. ( OK )    b.) exemplos 401 a 410
 
 2.0        01. ( OK )    a.) exemplos 501 a 505
*/
