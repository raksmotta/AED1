/*
	Exercicio000 - v3.0. - 506 ate 508 - 23/02/2024
	Autor: Raquel de Parde Motta
	Matricula: 854017
*/

// dependencias
#include <stdio.h>	// para as entradas e saidas
#include <stdlib.h> // para outras funcoes de uso geral
#include <stdbool.h> // para valores logicos
#include <string.h> // para lidar com caracteres
#include <math.h>


//-------------------------- exemplo 506 > mostrar passagens de parametros


void P2 (int X); // PROTOTIPO DE PROCEDIMENTO

void P1 (int X)
{
	printf ( "CHAMADO O PROCEDIMENTO P1 COM X = %d\n", X );
	if ( X < 5 )
		P2 ( X );
	printf ( "RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = %d\n", X );
	getchar ( ); // para esperar
} 	// fim do procedimento P1( )


void P2 (int X)
{
	printf ( "CHAMADO O PROCEDIMENTO P2 COM X = %d\n", X );
	X = X+1;
	printf ( "RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = %d\n", X );
	getchar ( ); // para esperar
	P1 ( X );
} 	// fim do procedimento P2( )


int main ( void )
{
	printf ( "EXEMPLO0506 - CHAMADA/RETORNO COM PARAMETRO\n\n" );
	P1 ( 1 ); // OBSERVAR RECURSIVIDADE INDIRETA !
	printf ( "\n" );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar ( ); // para esperar
	return ( EXIT_SUCCESS );
}


//-------------------------- exemplo 507 > mostrar passagem de parametro por referencia

/*
void P1 ( int* X )
{
	*X = *X + 1; // AVANCAR O CONTEXTO NA REFERENCIA
	
	printf ( "\nCHAMADO O PROCEDIMENTO P1 %d VEZ(ES)\n", *X );
	
	if ( *X < 5 )
		P1 ( X );
	
	printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA %d", *X );
	
	*X = *X - 1; // RETORNAR AO CONTEXTO DA REFERENCIA ANTERIOR
	
	getchar ( ); // para esperar
} // fim procedimento P1( )


int main ( void )
{
// PROGRAMA PARA MOSTRAR PASSAGEM DE PARAMETRO POR REFERENCIA
// VARIAVEL LOCAL
	int X;
	
	printf ( "EXEMPLO0507 - CHAMADA/RETORNO COM REFERENCIA\n" );
	
	X = 0;
	P1 ( &X ); // OBSERVAR REPETICAO FINITA !
	
	printf ( "\n" );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar ( ); // para esperar
	return ( EXIT_SUCCESS);
}


//-------------------------- exemplo 508 


void P2 ( int X ); // PROTOTIPO DE PROCEDIMENTO

void P1 ( int X )
{
	X = X + 1;
	
	printf ( "CHAMADO O PROCEDIMENTO P1 COM X = %d\n", X );
	
	if ( X < 4 )
	{
		P1 ( X );
		P2 ( X );
	}
	
	printf ( "\nRETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = %d\n", X );
	getchar ( ) ; // para esperar
} // fim do procedimento P1( )


void P2 ( int X )
{
	printf ( "CHAMADO O PROCEDIMENTO P2 COM X = %d\n", X );
	
	if ( X > 1 )
		P2 ( X - 1 );
	
	printf ( "RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = %d", X );
	getchar ( ); // para esperar
} // fim procedimento P2( )


int main ( void )
{
// PROGRAMA PARA MOSTRAR PASSAGENS DE PARAMETROS
	printf ( "EXEMPLO0508 - MULTIPLAS CHAMADAS/RETORNOS\n\n" );
	
	P1 ( 1 );

	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar ( ); // para esperar
	return ( EXIT_SUCCESS );
} 
*/

/*
---------------------------------------------- documentacao complementar


>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> OUTPUT506:

EXEMPLO0506 - CHAMADA/RETORNO COM PARAMETRO

CHAMADO O PROCEDIMENTO P1 COM X = 1
CHAMADO O PROCEDIMENTO P2 COM X = 1
RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 2

CHAMADO O PROCEDIMENTO P1 COM X = 2
CHAMADO O PROCEDIMENTO P2 COM X = 2
RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 3

CHAMADO O PROCEDIMENTO P1 COM X = 3
CHAMADO O PROCEDIMENTO P2 COM X = 3
RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 4

CHAMADO O PROCEDIMENTO P1 COM X = 4
CHAMADO O PROCEDIMENTO P2 COM X = 4
RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 5

CHAMADO O PROCEDIMENTO P1 COM X = 5
RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = 5

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = 4

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = 3

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = 2

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = 1



PRESSIONAR <Enter> PARA TERMINAR.



>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> OUTPUT507:

EXEMPLO0507 - CHAMADA/RETORNO COM REFERENCIA

CHAMADO O PROCEDIMENTO P1 1 VEZ(ES)

CHAMADO O PROCEDIMENTO P1 2 VEZ(ES)

CHAMADO O PROCEDIMENTO P1 3 VEZ(ES)

CHAMADO O PROCEDIMENTO P1 4 VEZ(ES)

CHAMADO O PROCEDIMENTO P1 5 VEZ(ES)

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 5

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 4

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 3

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 2

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA 1


PRESSIONAR <Enter> PARA TERMINAR.



>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> OUTPUT508:

EXEMPLO0508 - MULTIPLAS CHAMADAS/RETORNOS

CHAMADO O PROCEDIMENTO P1 COM X = 2
CHAMADO O PROCEDIMENTO P1 COM X = 3
CHAMADO O PROCEDIMENTO P1 COM X = 4

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = 4

CHAMADO O PROCEDIMENTO P2 COM X = 3
CHAMADO O PROCEDIMENTO P2 COM X = 2
CHAMADO O PROCEDIMENTO P2 COM X = 1
RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 1
RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 2
RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 3

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = 3

CHAMADO O PROCEDIMENTO P2 COM X = 2
CHAMADO O PROCEDIMENTO P2 COM X = 1
RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 1
RETORNANDO AO PROCEDIMENTO P2 PARA A CHAMADA COM X = 2

RETORNANDO AO PROCEDIMENTO P1 PARA A CHAMADA COM X = 2


PRESSIONAR <Enter> PARA TERMINAR.


---------------------------------------------- notas / observacoes / comentarios


---------------------------------------------- previsao de testes

a.) Compilacao sem erros e verificacao das saidas de acordo com o codigo

b.) insercao de valores e verificacao de retornos e operacoes

---------------------------------------------- historico

Versao  Data     Modificacao

 0.0    21/02    exemplos de 101 a 110
 1.0    22/02    exemplos de 301 a 410
 2.0    23/02    exemplos de 501 a 505
 3.0    23/02    exemplos de 506 a 508

---------------------------------------------- testes

Versao    Teste
 0.0        01. ( OK )    a.) exemplos 101 a 105
 0.0        02. ( OK )    a.) exemplos 106 a 110
 0.0        03. ( fail )  erro ao compilar, pois eu tinha declarado as variaveis fora das funcoes de cada exemplo.
 0.0        04. ( OK )    b.) exemplos 201 a 210

 1.0        01. ( OK )    b.) exemplos 301 a 310
 1.0        02. ( OK )    b.) exemplos 401 a 410
 
 2.0        01. ( OK )    a.) exemplos 501 a 505
 
 3.0        01. ( OK )    a.) exemplo 506
 3.0        02. ( OK )    a.) exemplo 507
 3.0        03. ( OK )    a.) exemplo 508
*/
