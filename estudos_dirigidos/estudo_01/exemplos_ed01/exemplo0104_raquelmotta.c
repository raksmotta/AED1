/*
> Pontificia Universidade Catolica de Minas Gerais
> Curso de Ciencia da Computacao
> Algoritmos e Estruturas de Dados I

> Autor: RAQUEL DE PARDE MOTTA  
> Matricula: 854017  
> Nome: exemplo0104
> Versao:  4.0              
> Data: 28/02/2024

*/

// -------------------------- classes nativas ou auxiliares

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //para valores logicos. em alguns compiladores pode haver problemas com relacao a essa biblioteca, caso acontecer considerar o uso de definicoes alternativas.
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

// >>>>>>>>>> method 03 <<<<<<<<<<

void method_03 ( void )
{
	char x ='A';	//indispensavel usar apostrofos
	
	printf ( "\n\n%s"  , "method_03" );	//identificar
	
	printf ("\n\n%s%c", "x = ", x); //o formato para char eh %c
	
	printf ("\n\nentrar com um caractere: ");
	scanf ("%c", &x);	
	getchar();
	
	printf ("\n%s%c", "x digitado = ", x);	//mostrar valor  lido
	
	//encerrar
	printf ( "\n\n%s", "Apertar ENTER para continuar." );
	getchar( );
}

// >>>>>>>>>> method 04 <<<<<<<<<<

void method_04 ( void )
{
	bool x =false;	//definir variavel com valor incial. indispensavel usar minusculas
	
	int y =0;	//definir variavel auxiliar
	
	printf ( "\n\n%s"  , "method_04" );	//identificar
	
	printf ("\n\n%s%d", "x = ", x); //o formato para equivalente inteiro eh %d
	
	printf ("\n\nentrar com um valor logico: ");
	scanf ("%d", &y);	//usar equivalente inteiro -> 0=false	
	getchar();
	
	x = (y!=0);	//garantir valor logico no intervalo [0:1]
	
	// The result of the comparison (y != 0) is assigned to the variable x. If y is not equal to 0, x will be assigned true (1), and if y is equal to 0, x will be assigned false (0).
	
	printf ("\n%s%d", "x digitado = ", x);	//mostrar valor  lido
	
	//encerrar
	printf ( "\n\n%s", "Apertar ENTER para continuar." );
	getchar( );
} 

int main (int argc, char*argv[])
{
	int opcao =0;
	
	printf ("%s\n\n", "exemplo0104 - programa = v4.0");
	printf ("%s\n\n", "autor: RAQUEL DE PARDE MOTTA");
	
	//actions
	
	do
	{
		//para mostrar opcoes
		printf ("\n\n%s", "opcoes:");
		printf ("\n\n%s", "0 - terminar");
		printf ("\n\n%s", "1 - method_01");
		printf ("\n\n%s", "2 - method_02");
		printf ("\n\n%s", "3 - method_03");
		printf ("\n\n%s", "4 - method_04");
		
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
			
		case 3:
			method_03 ();
			break;
			
		case 4:
			method_04 ();
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


exemplo0104 - programa = v4.0

autor: RAQUEL DE PARDE MOTTA



opcoes:

0 - terminar

1 - method_01

2 - method_02

3 - method_03

4 - method_04

opcao = 4


opcao selecionada = 4

method_04

x = 0

entrar com um valor logico: 9

x digitado = 1

Apertar ENTER para continuar.


opcoes:

0 - terminar

1 - method_01

2 - method_02

3 - method_03

4 - method_04

opcao = 1


opcao selecionada = 1

method_01

x = 0
&x = 0000000347BFF84C

entrar com um valor inteiro: 435

x digitado = 435

Apertar ENTER para continuar.


opcoes:

0 - terminar

1 - method_01

2 - method_02

3 - method_03

4 - method_04

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
	3.0	       28/02		criacao method_03
	4.0	       28/02		criacao method_04


----------------------------- testes

	Versao	    Teste
    
    0.0	       A. ( OK )
	1.0	       A. ( OK )
	2.0	       A. ( OK )
	3.0	       A. ( OK )
	4.0	       A. ( OK )

*/
