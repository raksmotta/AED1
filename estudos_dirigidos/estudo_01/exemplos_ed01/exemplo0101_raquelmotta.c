/*
> Pontificia Universidade Catolica de Minas Gerais
> Curso de Ciencia da Computacao
> Algoritmos e Estruturas de Dados I

> Autor: RAQUEL DE PARDE MOTTA  
> Matricula: 854017  
> Nome: exemplo0101
> Versao:  1.0              
> Data: 27/02/2024

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

int main (int argc, char*argv[])
{
	int opcao =0;
	
	printf ("%s\n\n", "exemplo0101 - programa = v1.0");
	printf ("%s\n\n", "autor: RAQUEL DE PARDE MOTTA");
	
	//actions
	
	do
	{
		//para mostrar opcoes
		printf ("\n\n%s", "opcoes:");
		printf ("\n\n%s", "0 - terminar");
		printf ("\n\n%s", "1 - method_01");
		
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
			
		default:
			printf ("\n\nERRO: opcao invalida");
			break;	
		}
			
	} while (opcao !=0);
	
	//encerrar
	printf ("\n\n\napertar ENTER para terminar");
	getchar();
	
	return (0);	
}


/*
DOCUMENTACAO COMPLEMENTAR

----------------------------- previsao de testes

teste A - compilacao sem erros e escolha do method_01

----------------------------- outputs

>>>>>>>>>> teste A <<<<<<<<<<

exemplo0100 - programa = v0.0

autor: RAQUEL DE PARDE MOTTA



opcoes:

0 - terminar

1 - method_01

opcao = 1


opcao selecionada = 1

method_01

x = 0
&x = 00000073CABFFDFC

entrar com um valor inteiro: 5

x digitado = 5

Apertar ENTER para continuar.


opcoes:

0 - terminar

1 - method_01

opcao = 0


opcao selecionada = 0


apertar ENTER para terminar

----------------------------- erros


----------------------------- notas / observacoes / comentarios


----------------------------- historico

	Versao	    Data        Modificacao
	  
	0.0	       26/02		criacao method_01
	1.0	       27/02		edicao method_01


----------------------------- testes

	Versao	    Teste
    
    0.0	       A. ( OK )
	1.0	       A. ( OK )

*/
