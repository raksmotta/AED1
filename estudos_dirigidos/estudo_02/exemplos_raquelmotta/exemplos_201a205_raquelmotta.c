/*
> Pontificia Universidade Catolica de Minas Gerais
> Curso de Ciencia da Computacao
> Algoritmos e Estruturas de Dados I

> Autor: RAQUEL DE PARDE MOTTA  
> Matricula: 854017  
> Nome: exemplos 201 a 205
> Versao:  1.0              
> Data: 05/03/2024

*/

// -------------------------- dependencias
#include "io.h"	//bibliotecas e outras definicoes


// >>>>>>>>>> method 01 <<<<<<<<<<

void method_01 ( void )
{	
	int x = 0;
	
	//identificar
	IO_id ("\n\nmethod_01 - exemplo0201");
	
	//ler do teclado
	x = IO_readint ("entre com um valor inteiro: ");
	
	//testar valor
	if (x==0)
	{
		IO_printf ("%s(%d)\n", "valor igual a zero", x);
	}
	if (x != 0)
	{
		IO_printf ("%s(%d)\n", "valor diferente de zero", x);
	}
	//end if
	
	//encerrar
    IO_pause ("\napertar ENTER para continuar\n");
} 


// >>>>>>>>>> method 02 <<<<<<<<<<

void method_02 ( void )
{	
	int x = 0;
	
	//identificar
	IO_id ("\n\nmethod_02 - exemplo0201");
	
	//ler do teclado
	x = IO_readint ("entre com um valor inteiro: ");
	
	//testar valor
	if (x==0)
	{
		IO_printf ("%s(%d)\n", "valor igual a zero", x);
	}
	else  //equivalente a "caso diferente do ja testado"
	{
		IO_printf ("%s(%d)\n", "valor diferente de zero", x);
	}
	//end if
	
	//encerrar
	IO_pause ("\napertar ENTER para continuar\n");
} 


// >>>>>>>>>> method 03 <<<<<<<<<<

void method_03 ( void )
{	
	int x = 0;
	
	//identificar
	IO_id ("\n\nmethod_03 - exemplo0201");
	
	//ler do teclado
	x = IO_readint ("entre com um valor inteiro: ");
	
	//testar valor
	if (x==0)
	{
		IO_printf ("%s(%d)\n", "valor igual a zero", x);
	}
	else 
	{
		IO_printf ("%s(%d)\n", "valor diferente de zero", x);
		
		if (x>0)
		{
			IO_printf ("%s(%d)\n", "valor maior que zero", x);
		}
		else
		{
			IO_printf ("%s(%d)\n", "valor menor que zero", x);	
		}//end if
	}//end if

	
	//encerrar
	IO_pause ("\napertar ENTER para continuar\n");
} 


// >>>>>>>>>> method 04 <<<<<<<<<<

void method_04 ( void )
{	
	double x = 0.0;
	
	//identificar
	IO_id ("\n\nmethod_04 - exemplo0201");
	
	//ler do teclado
	x = IO_readdouble ("entre com um valor real: ");
	
	//testar valor
	if ((1.0<=x)&&(x<=10.0))
	{
		IO_printf ("%s(%lf)\n", "valor dentro do intervalo [1:10]", x);
	}
	else 
	{
		IO_printf ("%s(%lf)\n", "valor fora do intervalo [1:10]", x);
		
		if (x<1.0)
		{
			IO_printf ("%s(%lf)\n", "valor abaixo do intervalo [1:10]", x);
		}
		else
		{
			IO_printf ("%s(%lf)\n", "valor acima do intervalo [1:10]", x);	
		}//end if
	}//end if
	
	
	//encerrar
	IO_pause ("\napertar ENTER para continuar\n");
} 

// >>>>>>>>>> method 05 <<<<<<<<<<

void method_05 ( void )
{	
	char x = '_';
	
	//identificar
	IO_id ("\n\nmethod_05 - exemplo0201");
	
	//ler do teclado
	x = IO_readchar ("entre com um caractere: ");
	
	//testar valor
	if (('a'<=x) && (x<='z'))
	{
		IO_printf ("%s (%c)\n", "letra minuscula", x);
	}
	else 
	{
		IO_printf ("%s (%c)\n", "valor diferente de minuscula", x);
		
		if (('A'<=x)&&(x<='Z'))
		{
			IO_printf ("%s (%c)\n", "letra maiuscula", x);
		}
		else
		{	
			if (('0'<=x)&&(x<='9'))
			{
				IO_printf ("%s (%c)\n", "algarismo", x);
			}
			else
			{
				IO_printf ("%s (%c)\n", "valor diferente de algarismo", x);
			}
		}//end if
	}//end if
	
	
	//encerrar
	IO_pause ("\napertar ENTER para continuar\n");
} 



int main (int argc, char*argv[])
{
	int opcao =0;
	
	printf ("%s\n\n", "exemplo0201 - programa = v1.0");
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

obs.: OUTPUTS estao no arquivo outputs_exemplosED02.txt


teste A - input no method_01 = 6

teste B - input no method 01 = 0 ; method 02 = 7

teste C - input no method 01 = -6 ; method 02 = 29.5


teste D - input no method 03 = 4

teste E - input no method 03 = -3


teste F - input no method 04 = 5

teste G - input no method 04 = 10.645

teste H - input no method 04 = -9


teste I - input no method 05 = r

teste J - input no method 05 = R

teste K - input no method 05 = 4

teste L - input no method 05 = 100



----------------------------- erros


----------------------------- notas / observacoes / comentarios

obs.: nao fiz a partir do exemplo206


----------------------------- historico

	Versao	    Data        Modificacao
	  
	0.0	       05/03		criacao method_01
	1.0	       05/03		edicao method_01
	1.0	       05/03		criacao method_02
	1.0	       05/03		criacao method_03
	1.0	       05/03		criacao method_04
	1.0	       07/03		criacao method_05


----------------------------- testes

	Versao	    Teste
    
    0.0	       A. ( OK )

	1.0	       A. ( OK )
	1.0	       B. ( OK )
	1.0	       C. ( fail ) -> nao le a parte decimal do numero inputado
	
	1.0	       D. ( OK )
	1.0	       E. ( OK )
	
	1.0	       F. ( OK )
	1.0	       G. ( OK )
	1.0	       H. ( OK )

	1.0	       I. ( OK )
	1.0	       J. ( OK )
	1.0	       K. ( OK )
	1.0	       L. ( fail ) -> leu apenas o digito 1 do numero 100
*/
