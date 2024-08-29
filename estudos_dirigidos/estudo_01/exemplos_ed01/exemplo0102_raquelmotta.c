/*
> Pontificia Universidade Catolica de Minas Gerais
> Curso de Ciencia da Computacao
> Algoritmos e Estruturas de Dados I

> Autor: RAQUEL DE PARDE MOTTA  
> Matricula: 854017  
> Nome: exemplo0102
> Versao:  2.0              
> Data: 28/02/2024

*/

// -------------------------- classes nativas ou auxiliares

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// >>>>>>>>>> method 01 <<<<<<<<<<

void method_01 ( void )
{
	int x =0; //definir variavel com valor inicial
	
	printf ( "\n\n%s"  , "method_01" );	//identificar
	
	printf ("\n\n%s%d", "x = ", x); //mostrar valor incial. o formato para int eh %d ou %i
	
	printf ("\n&%s%p", "x = ", &x);	//o formato para endereco eh %p
	
	printf ("\n\nentrar com um valor inteiro: ");
	scanf ("%d", &x);	//ler do teclado. necessario indicar o endereco com &.
	getchar();	//limpar entrada de dados
	
	printf ("\n%s%i", "x digitado = ", x);
	
	//encerrar
    printf ( "\n\n%s", "Apertar ENTER para continuar." );
    getchar( );
} 

// >>>>>>>>>> method 02 <<<<<<<<<<

void method_02 ( void )
{
	double x =0.0;	//definir variavel com valor incial. definir a parte fracionaria eh util
	
	printf ( "\n\n%s"  , "method_02" );	//identificar
	
	printf ("\n\n%s%lf", "x = ", x); //mostrar valor incial. o formato para double eh %lf
	
	printf ("\n\nentrar com um valor real: ");
	scanf ("%lf", &x);	
	getchar();
	
	printf ("\n%s%lf", "x digitado = ", x);	//mostrar valor  lido
	
	//encerrar
	printf ( "\n\n%s", "Apertar ENTER para continuar." );
	getchar( );
} 


int main (int argc, char*argv[])
{
	int opcao =0;
	
	printf ("%s\n\n", "exemplo0102 - programa = v2.0");
	printf ("%s\n\n", "autor: RAQUEL DE PARDE MOTTA");
	
	//actions
	
	do
	{
		//para mostrar opcoes
		printf ("\n\n%s", "opcoes:");
		printf ("\n\n%s", "0 - terminar");
		printf ("\n\n%s", "1 - method_01");
		printf ("\n\n%s", "2 - method_02");
		
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
		
		case 1:
			method_01 ();
			break;
		
		case 2:
			method_02 ();
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

teste A - compilacao sem erros e escolha do method_02

----------------------------- outputs

>>>>>>>>>> teste A <<<<<<<<<<

exemplo0102 - programa = v2.0

autor: RAQUEL DE PARDE MOTTA



opcoes:

0 - terminar

1 - method_01

2 - method_02

opcao = 2


opcao selecionada = 2

method_02

x = 0.000000

entrar com um valor real: 0.76

x digitado = 0.760000

Apertar ENTER para continuar.


opcoes:

0 - terminar

1 - method_01

2 - method_02

opcao = 1


opcao selecionada = 1

method_01

x = 0
&x = 0000007C987FFCFC

entrar com um valor inteiro: -90

x digitado = -90

Apertar ENTER para continuar.


opcoes:

0 - terminar

1 - method_01

2 - method_02

opcao = 0


opcao selecionada = 0


apertar ENTER para terminar

----------------------------- erros


----------------------------- notas / observacoes / comentarios


----------------------------- historico

	Versao	    Data        Modificacao
	  
	0.0	       26/02		criacao method_01
	1.0	       27/02		edicao method_01
	2.0	       28/02		criacao method_02


----------------------------- testes

	Versao	    Teste
    
    0.0	       A. ( OK )
	1.0	       A. ( OK )
	2.0	       A. ( OK )

*/
