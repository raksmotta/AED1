/*
> Pontificia Universidade Catolica de Minas Gerais
> Curso de Ciencia da Computacao
> Algoritmos e Estruturas de Dados I

> Autor: RAQUEL DE PARDE MOTTA  
> Matricula: 854017  
> Nome: exemplo0200
> Versao:  0.0              
> Data: 05/03/2024

*/

// -------------------------- dependencias
#include "io.h"	//bibliotecas e outras definicoes


// >>>>>>>>>> method 01 <<<<<<<<<<

void method_01 ( void )
{
	//identificar
	IO_id ("\n\nmethod_01 - exemplo0200");
	
	//encerrar
    IO_pause ("\napertar ENTER para continuar\n");
} 


int main (int argc, char*argv[])
{
	int opcao =0;
	
	printf ("%s\n\n", "exemplo0200 - programa = v0.0");
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

teste A - compilacao e execucao do method_01

----------------------------- outputs

>>>>>>>>>> teste A <<<<<<<<<<

exemplo0200 - programa = v0.0

autor: RAQUEL DE PARDE MOTTA



opcoes:

0 - terminar

1 - method_01

2 - method_02

3 - method_03

4 - method_04

5 - method_05

opcao = 1


opcao selecionada = 1

method_01 - exemplo0200
Autor: Raquel de Parde Motta



apertar ENTER para continuar

----------------------------- erros


----------------------------- notas / observacoes / comentarios


----------------------------- historico

	Versao	    Data        Modificacao
	  
	0.0	       05/03		criacao method_01

----------------------------- testes

	Versao	    Teste
    
    0.0	       A. ( OK )
*/
