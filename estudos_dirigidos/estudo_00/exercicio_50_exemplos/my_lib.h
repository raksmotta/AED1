/*
Exercicio000 - header para exemplo 509 - 24/02/2024
Autor: Raquel de Parde Motta
*/

// ------------------------------------ my_lib.h

// bibliotecas de funcoes auxiliares

#include <stdio.h> // para entradas e saídas
#include <stdlib.h> // para outras funcoes de uso geral

void pause ( char message [ ] )
{
	printf ( "\n%s", message );
	fflush ( stdin ); // limpar a entrada de dados
	getchar ( ); // para esperar
} // fim pause ( )

void println ( char text [ ] )
{ printf ( "%s\n", text ); }
