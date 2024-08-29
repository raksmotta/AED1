/*
> Pontificia Universidade Catolica de Minas Gerais
> Curso de Ciencia da Computacao
> Algoritmos e Estruturas de Dados I

> Autor: RAQUEL DE PARDE MOTTA  
> Matricula: 854017  
> Nome: exemplo0106
> Versao:  6.0              
> Data: 28/02/2024

*/

// -------------------------- classes nativas ou auxiliares

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //para valores logicos. em alguns compiladores pode haver problemas com relacao a essa biblioteca, caso acontecer considerar o uso de definicoes alternativas.
#include <string.h>	//para cadeias de caracteres
#include <math.h>

// >>>>>>>>>> method 06 <<<<<<<<<<

void method_06 ( void )
{	
	//definir dados. atribuir valor inicial as variaveis
	int x =0;
	int y =0;
	int z =0;
	
	int *py = &y;	//definir acesso a y via endereco
	
	printf ( "\n\n%s"  , "method_06" );	//identificar
	
	//mostrar valores iniciais. formato para int eh %d ou %i
	printf ("\n\n%s%d", "x = ", x);
	printf ("\n\n%s%i", "y = ", y);
	
	printf ("\n\nentrar com um valor inteiro: ");
	scanf ("%d", &x);	//ler do teclado. necessario indicar o endereco com &.
	getchar();	//limpar entrada de dados
	
	printf ("\n\nentrar com outro valor inteiro: ");
	scanf ("%i", py);	//ler do teclado. NAO necessario indicar o endereco.
	getchar();	//limpar entrada de dados
	
	//operar valores
	z = x * y;	//guardar em z o produto de x por y
	
	printf ("\n\n%s(%i)*(%i)=(%d)", "z = ", x, y, z);
	
	//encerrar
    printf ( "\n\n%s", "Apertar ENTER para continuar." );
    getchar( );
} 



int main (int argc, char*argv[])
{
	int opcao =0;
	
	printf ("%s\n\n", "exemplo0106 - programa = v6.0");
	printf ("%s\n\n", "autor: RAQUEL DE PARDE MOTTA");
	
	//actions
	
	do
	{
		//para mostrar opcoes
		printf ("\n\n%s", "opcoes:");
		printf ("\n\n%s", "0 - terminar");
		printf ("\n\n%s", "6 - method_06");
		
		//ler a opcao do teclado
		printf ("\n\n%s", "opcao = ");
		scanf ("%d", &opcao);
		getchar();
		
		//mostrar a opcao lida
		printf ("\n\n%s%d", "opcao selecionada = ", opcao);
		
		//escolher acao dependente da opcao escolhida
		switch (opcao)
		{
		case 0:
			break;
			
		case 6:
			method_06 ();
			break;
			
		default:
			printf ("\n\nERRO: opcao invalida");
			break;	
		}
			
	} while (opcao !=0);
	
	//encerrar
	printf ("\n\n\napertar ENTER para terminar");
	getchar();
	
	return (0); //voltar ao SO (sem erros)	
}


/*
DOCUMENTACAO COMPLEMENTAR

----------------------------- previsao de testes

teste A - compilacao sem erros e escolha do method_04

----------------------------- outputs

>>>>>>>>>> teste A <<<<<<<<<<

exemplo0106 - programa = v6.0

autor: RAQUEL DE PARDE MOTTA



opcoes:

0 - terminar

6 - method_06

opcao = 6


opcao selecionada = 6

method_06

x = 0

y = 0

entrar com um valor inteiro: 14


entrar com outro valor inteiro: 3


z = (14)*(3)=(42)

Apertar ENTER para continuar.

----------------------------- erros


----------------------------- notas / observacoes / comentarios


----------------------------- historico

	Versao	    Data        Modificacao
	  
	0.0	       26/02		criacao method_01
	1.0	       27/02		edicao method_01
	2.0	       28/02		criacao method_02
	3.0	       28/02		criacao method_03
	4.0	       28/02		criacao method_04
	5.0	       28/02		criacao method_05
	6.0	       29/02		criacao method_06


----------------------------- testes

	Versao	    Teste
    
    0.0	       A. ( OK )
	1.0	       A. ( OK )
	2.0	       A. ( OK )
	3.0	       A. ( OK )
	4.0	       A. ( OK )
	5.0	       A. ( fail ) -> o programa nao aceita string com espaco em branco
	5.0	       B. ( OK )
	5.0	       C. ( OK )
	6.0	       A. ( OK )
*/

