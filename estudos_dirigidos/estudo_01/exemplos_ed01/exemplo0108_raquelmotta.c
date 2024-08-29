/*
> Pontificia Universidade Catolica de Minas Gerais
> Curso de Ciencia da Computacao
> Algoritmos e Estruturas de Dados I

> Autor: RAQUEL DE PARDE MOTTA  
> Matricula: 854017  
> Nome: exemplo0108
> Versao:  8.0              
> Data: 29/02/2024

*/

// -------------------------- classes nativas ou auxiliares

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //para valores logicos. em alguns compiladores pode haver problemas com relacao a essa biblioteca, caso acontecer considerar o uso de definicoes alternativas.
#include <string.h>	//para cadeias de caracteres
#include <math.h> 	//para funcoes matematicas: pow(), sqrt(), sin(), cos()...

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

// >>>>>>>>>> method 07 <<<<<<<<<<

void method_07 ( void )
{	
	//definir dados. atribuir tamanho e valor inicial as variaveis
	char x [80] = "abc";
	char y [80] = "def";
	char z [80];
	strcpy (z, "");	//copiar para z a representacao de vazio
	
	printf ( "\n\n%s"  , "method_07" );	//identificar
	
	//mostrar valores iniciais e comprimentos das cadeias
	printf ("\n\n%s%s(%d)", "x = ", x, strlen(x));
	printf ("\n\n%s%s(%d)", "y = ", y, strlen(y));
	
	printf ("\n\nentrar com caracteres: ");
	scanf ("%s", x);	//nao indicar o endereco
	getchar();
	
	printf ("\n\nentrar com outros caracteres: ");
	scanf ("%s", y);	//nao indicar o endereco
	getchar();
	
	
	//operar valores
	strcpy(z,x);	//copiar x para z
	strcat(z,y);	//concatenar (juntar) y a z (forma mais eficiente)
	
	//mostrar valor resultante
	printf ("\n\n%s[%s]*[%s]=[%s]", "z = ", x, y, z);
	
	//operar valores (forma alternativa)
	strcpy(z, strcat (strdup(x), y));
	//copiar para z o resultado de concatenar a copia de x com y
	//obs.: se nao duplicar, o valor x sera alterado
	
	//mostrar valor resultante
	printf ("\n\n%s[%s]*[%s]=[%s]", "z = ", x, y, z);
	
	//encerrar
	printf ( "\n\n%s", "Apertar ENTER para continuar." );
	getchar( );
}

// >>>>>>>>>> method 08 <<<<<<<<<<

void method_08 ( void )
{	
	//definir dados. atribuir valor inicial as variaveis
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	
	printf ( "\n\n%s"  , "method_08" );	//identificar
	
	//mostrar valores iniciais.
	printf ("\n\n%s%lf", "x = ", x);
	printf ("\n\n%s%lf", "y = ", y);
	
	printf ("\n\nentrar com um valor real: ");
	scanf ("%lf", &x);	//ler do teclado. necessario indicar o endereco com &.
	getchar();	//limpar entrada de dados
	
	printf ("\n\nentrar com outro valor real: ");
	scanf ("%lf", & y);	
	getchar();
	
	//operar valores
	z = pow(x, y);	//x eh a base e y eh o expoente
	
	printf ("\n\n%s(%lf) elevado a (%lf) = (%lf)", "z = ", x, y, z);
	
	//operar valores
	z = sqrt(x);
	
	printf ("\n\n%s raiz (%lf) = (%lf)", "z =", x, z);
	
	//encerrar
	printf ( "\n\n%s", "Apertar ENTER para continuar." );
	getchar( );
} 

int main (int argc, char*argv[])
{
	int opcao =0;
	
	printf ("%s\n\n", "exemplo0108 - programa = v8.0");
	printf ("%s\n\n", "autor: RAQUEL DE PARDE MOTTA");
	
	//actions
	
	do
	{
		//para mostrar opcoes
		printf ("\n\n%s", "opcoes:");
		printf ("\n\n%s", "0 - terminar");
		printf ("\n\n%s", "6 - method_06");
		printf ("\n\n%s", "7 - method_07");
		printf ("\n\n%s", "8 - method_08");
		
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
			
		case 7:
			method_07 ();
			break;
		
		case 8:
		method_08 ();
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

teste A - input no method_08 -> 2.0 e 3.0
teste B - input no method_08 -> -3.0 e 2.0
teste C - input no method_08 -> 5.55 e 5.55
teste D - input no method_08 -> -5.0 e -5.0

----------------------------- outputs

>>>>>>>>>> teste A <<<<<<<<<<

exemplo0108 - programa = v8.0

autor: RAQUEL DE PARDE MOTTA



opcoes:

0 - terminar

6 - method_06

7 - method_07

8 - method_08

opcao = 8


opcao selecionada = 8

method_08

x = 0.000000

y = 0.000000

entrar com um valor real: 2.0


entrar com outro valor real: 3.0


z = (2.000000) elevado a (3.000000) = (8.000000)

z = raiz (2.000000) = (1.414214)

Apertar ENTER para continuar.


>>>>>>>>>> teste B <<<<<<<<<<

exemplo0108 - programa = v8.0

autor: RAQUEL DE PARDE MOTTA



opcoes:

0 - terminar

6 - method_06

7 - method_07

8 - method_08

opcao = 8


opcao selecionada = 8

method_08

x = 0.000000

y = 0.000000

entrar com um valor real: -3.0


entrar com outro valor real: -2.0


z = (-3.000000) elevado a (-2.000000) = (0.111111)

z = raiz (-3.000000) = (-nan(ind))

Apertar ENTER para continuar.


>>>>>>>>>> teste C <<<<<<<<<<

exemplo0108 - programa = v8.0

autor: RAQUEL DE PARDE MOTTA



opcoes:

0 - terminar

6 - method_06

7 - method_07

8 - method_08

opcao = 8


opcao selecionada = 8

method_08

x = 0.000000

y = 0.000000

entrar com um valor real: 5.55


entrar com outro valor real: 5.55


z = (5.550000) elevado a (5.550000) = (13515.311394)

z = raiz (5.550000) = (2.355844)


>>>>>>>>>> teste D <<<<<<<<<<

exemplo0108 - programa = v8.0

autor: RAQUEL DE PARDE MOTTA



opcoes:

0 - terminar

6 - method_06

7 - method_07

8 - method_08

opcao = 8


opcao selecionada = 8

method_08

x = 0.000000

y = 0.000000

entrar com um valor real: -5.0


entrar com outro valor real: -5.0


z = (-5.000000) elevado a (-5.000000) = (-0.000320)

z = raiz (-5.000000) = (-nan(ind))

Apertar ENTER para continuar.

----------------------------- erros


----------------------------- notas / observacoes / comentarios

como a raiz de numero negativo nao existe no conj. dos numeros reais, o programa exibe: (-nan(ind))

----------------------------- historico

	Versao	    Data        Modificacao
	  
	0.0	       26/02		criacao method_01
	1.0	       27/02		edicao method_01
	2.0	       28/02		criacao method_02
	3.0	       28/02		criacao method_03
	4.0	       28/02		criacao method_04
	5.0	       28/02		criacao method_05
	6.0	       29/02		criacao method_06
	7.0	       29/02		criacao method_07
	8.0	       29/02		criacao method_08


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

	7.0	       A. ( OK )
	7.0	       B. ( OK )
	7.0	       C. ( OK )
	7.0	       D. ( OK )

	8.0	       A. ( OK )
	8.0	       B. ( OK )
	8.0	       C. ( OK )
	8.0	       D. ( OK )
*/

