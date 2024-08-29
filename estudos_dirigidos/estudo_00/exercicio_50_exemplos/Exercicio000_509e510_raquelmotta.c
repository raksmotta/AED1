/*
	Exercicio000 - v4.0. - 509 e 510 - 24/02/2024
	Autor: Raquel de Parde Motta
	Matricula: 854017
*/

//-------------------------- exemplo 509 > programa para mostrar o uso de modulos

// bibliotecas de funcoes auxiliares
#include "my_lib.h" 	// para funcoes proprias

int main ( void )
{
	println ( "EXEMPLO0509 - USO DE MODULOS" );
	pause ( "PRESSIONAR <Enter> PARA TERMINAR." );
	return ( EXIT_SUCCESS );
} // fim do programa

/*	output:

EXEMPLO0509 - USO DE MODULOS

PRESSIONAR <Enter> PARA TERMINAR.

*/


//-------------------------- exemplo 510 > programa para mostrar o uso de modulos

// bibliotecas de funcoes auxiliares
/*#include "my_def.h" // para definicoes globais, constantes ...
#include "my_lib.h"

int main ( void )
{
// VARIAVEIS :
	chars text = "MUDAR DE LINHA";
	println ( "EXEMPLO0509 - USO DE MODULOS" );
	printf ( "%c", EOL );
	printf ( "%s%c", text, EOL );
	pause ( "PRESSIONAR <Enter> PARA TERMINAR." );
	return ( EXIT_SUCCESS );
} // fim do programa

/*	output:

EXEMPLO0509 - USO DE MODULOS

MUDAR DE LINHA

PRESSIONAR <Enter> PARA TERMINAR.

*/

/*
---------------------------------------------- documentacao complementar


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
 4.0    24/02    exemplos 509 e 510

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

 4.0        01. ( OK )    a.) exemplo 509
 4.0        02. ( OK )    a.) exemplo 510
*/
