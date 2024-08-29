/*
> Pontificia Universidade Catolica de Minas Gerais
> Curso de Ciencia da Computacao
> Algoritmos e Estruturas de Dados I

> Autor: RAQUEL DE PARDE MOTTA  
> Matricula: 854017  
> Nome: exemplo0105
> Versao:  5.0              
> Data: 28/02/2024

*/

// -------------------------- classes nativas ou auxiliares

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //para valores logicos. em alguns compiladores pode haver problemas com relacao a essa biblioteca, caso acontecer considerar o uso de definicoes alternativas.
#include <string.h>	//para cadeias de caracteres
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

// >>>>>>>>>> method 05 <<<<<<<<<<

void method_05 ( void )
{
	char x[80]="abc";	//definir variavel com tamanho e valor inicial. aspas duplas
	
	char *px = &x[0];	//definir alternativa para acesso via endereco
	
	printf ( "\n\n%s"  , "method_05" );	//identificar
	
	printf ("\n\n%s%s", "x = ", x); //mostrar valor incial. formato para caracteres eh %s
	
	printf ("\n\nentrar com uma cadeia de caracteres: ");
	scanf ("%s", x);	//NAO devera ser usado o endereco dessa vez!! o tamanho do valor NAO devera ultrapassar 80 simbolos	
	getchar();
	
	printf ("\n%s%s", "x digitado = ", x);	//mostrar valor  lido
	
	// FORMA ALTERNATIVA PARA ACESSO VIA ENDERECO!!!
	printf ("\n\nentrar com outra cadeia de caracteres: ");
	scanf ("%s", px);
	getchar();
	
	printf ("\n%s%s", "x digitado = ", px);
	
	//encerrar
	printf ( "\n\n%s", "Apertar ENTER para continuar." );
	getchar( );
}

int main (int argc, char*argv[])
{
	int opcao =0;
	
	printf ("%s\n\n", "exemplo0105 - programa = v5.0");
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
		printf ("\n\n%s", "5 - method_05");
		
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
			
		case 5:
			method_05 ();
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

teste A - input no method_05 -> estudando algoritmos
teste B - input no method_05 -> estudandoalgoritmos
teste C - input no method_05 -> estudando_algoritmos

----------------------------- outputs

>>>>>>>>>> teste A <<<<<<<<<<

exemplo0105 - programa = v5.0

autor: RAQUEL DE PARDE MOTTA



opcoes:

0 - terminar

1 - method_01

2 - method_02

3 - method_03

4 - method_04

5 - method_05

opcao = 5


opcao selecionada = 5

method_05

x = abc

entrar com uma cadeia de caracteres: estudando algoritmos

x digitado = estudando

entrar com outra cadeia de caracteres:
x digitado = algoritmos

Apertar ENTER para continuar.'


>>>>>>>>>> teste B <<<<<<<<<<

exemplo0105 - programa = v5.0

autor: RAQUEL DE PARDE MOTTA



opcoes:

0 - terminar

1 - method_01

2 - method_02

3 - method_03

4 - method_04

5 - method_05

opcao = 5


opcao selecionada = 5

method_05

x = abc

entrar com uma cadeia de caracteres: estudandoalgoritmos

x digitado = estudandoalgoritmos

entrar com outra cadeia de caracteres: eusouraquel

x digitado = eusouraquel

Apertar ENTER para continuar.


>>>>>>>>>> teste C <<<<<<<<<<

exemplo0105 - programa = v5.0

autor: RAQUEL DE PARDE MOTTA



opcoes:

0 - terminar

1 - method_01

2 - method_02

3 - method_03

4 - method_04

5 - method_05

opcao = 5


opcao selecionada = 5

method_05

x = abc

entrar com uma cadeia de caracteres: estudando_algoritmos

x digitado = estudando_algoritmos

entrar com outra cadeia de caracteres: raquel!!!

x digitado = raquel!!!

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
*/
