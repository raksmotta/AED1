/*
> Pontificia Universidade Catolica de Minas Gerais
> Curso de Ciencia da Computacao
> Algoritmos e Estruturas de Dados I

> Autor: RAQUEL DE PARDE MOTTA  
> Matricula: 854017  
> Nome: exemplo0109
> Versao:  9.0              
> Data: 29/02/2024

*/

// -------------------------- classes nativas ou auxiliares

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //para valores logicos. em alguns compiladores pode haver problemas com relacao a essa biblioteca, caso acontecer considerar o uso de definicoes alternativas.
#include <string.h>	//para cadeias de caracteres
#include <math.h> 	//para funcoes matematicas: pow(), sqrt(), sin(), cos()...


// >>>>>>>>>> method 09 <<<<<<<<<<

void method_09 ( void )
{
// definir dados singulares
	int x = 0 ;      // definir variavel com valor inicial para guardar inteiro
	double y = 3.5;  // definir variavel com valor inicial para guardar real
	char z = 'A';    // definir variavel com valor inicial para guardar caractere (simbolo)
	bool w = false;  // definir variavel com valor inicial para guardar falso ou verdadeiro

// definir dados com mais de um valor
	char s [80] = "";   // definir espaco de armazenamento para ate' 80 caracteres (simbolos)

// identificar
	printf ( "\n%s\n", "method_09" );

// mostrar valores iniciais
	printf ( "01. %s%d\n" , "x = ", x );
	printf ( "02. %s%lf\n" , "y = ", y );
	printf ( "03. %s%c\n" , "z = ", z );

// converter entre tipos de dados (type casting)
	x = (int) z;     // codigo inteiro equivalente ao caractere
	printf ( "04. %s%d -> %c\n" , "x = ", x, z );
	
	x = (int) y;     // parte inteira de real
	printf ( "05. %s%d -> %lf\n", "x = ", x, y );
	
	x = 97;
	z = (char) x;     // símbolo equivalente ao codigo inteiro
	printf ( "06. %s%c -> %d\n" , "z = ", z, x );
	
	x = (int) '0';     // codigo inteiro equivalente ao caractere
	z = (char) x;     // caractere equivalente ao codigo inteiro
	printf ( "07. %s%c -> %d\n" , "z = ", z, x );
	
	x = w;     // codigo inteiro equivalente ao logico
	printf ( "08. %s%d -> %d\n" , "x = ", x, w );
	
	w = true;
	x = w;     // codigo inteiro equivalente ao logico
	printf ( "09. %s%d -> %d\n" , "x = ", x, w );
	
	x = (w==false);     // equivalente 'a comparacao de igualdade (true igual a false)
	printf ( "10. %s%d -> %d\n" , "x = ", x, w );
	
	x = ! (w==false);     // equivalente ao contrario da comparacao de valores (true igual a false)
	printf ( "11. %s%d -> %d\n" , "x = ", x, w );
	
	x = (w!=false);     // equivalente 'a comparacao de diferenca (true diferente de false)
	printf ( "12. %s%d -> %d\n" , "x = ", x, w );
	
	w = (x == 0);     // equivalente 'a comparacao de igualdade entre (x) e zero
	printf ( "13. %s%d == %d = %d\n" , "w = ", x, 0, w );
	
	w = (x != 0);     // equivalente 'a comparacao de diferenca entre (x) e zero
	printf ( "14. %s%d != %d = %d\n" , "w = ", x, 0, w );
	
	w = (x < y);     // equivalente 'a comparacao entre (x) e (y)
	printf ( "15. %s%d < %lf = %d\n" , "w = ", x, y, w );
	
	w = (x <= y);     // equivalente 'a comparacao entre (x) e (y)
	printf ( "16. %s%d <= %lf = %d\n" , "w = ", x, y, w );
	
	w = (y > x);     // equivalente 'a comparacao entre (x) e (y)
	printf ( "17. %s%lf > %d = %d\n" , "w = ", y, x, w );
	
	w = (y >= x);     // equivalente 'a comparacao entre (x) e (y)
	printf ( "18. %s%lf >= %d = %d\n" , "w = ", y, x, w );
	
	x = 4;
	w = (x % 2 == 0);     // equivalente a testar se é par ou
	                      // resto inteiro (%) da divisao por 2 igual a zero
	printf ( "19. %s (%d%%2) ? %d\n" , "e' par ", x, w );
	
	x = 4;
	w = (x % 2 != 0);     // equivalente a testar se é ímpar ou
	                      // resto inteiro (%) da divisao por 2 diferente de zero
	printf ( "20. %s (%d%%2) ? %d\n" , "e' impar ", x, w );
	
	z = '5';
	w = ('0'<=z && z<='9');     // equivalente a testar se e' algarismo/digito
                                // pertence a [‘0’:’9’] (é igual ou esta’ entre ‘0’ e ‘9’)
	printf ( "21. %s (%c) ? %d\n" , "e' digito", z, w );
	
	z = 'x';
	w = ('a'<=z && z<='z');     // equivalente a testar se e' letra minuscula,
                                // pertence a [‘a’:’z’] (é igual ou esta’ entre ‘a’ e ‘z’)
	printf ( "22. %s (%c) ? %d\n" , "e' minuscula ", z, w );
	
	z = 'X';
	w = ( ! ('a'<=z && z<='z' ) );     // equivalente a testar se NAO (!) e' letra minuscula
	printf ( "23. %s (%c) ? %d\n" , "nao e' minuscula ", z, w );
	
	z = 'x';
	w = ('A'<=z && z<='Z');     // equivalente a testar se e' letra maiuscula
	printf ( "24. %s (%c) ? %d\n" , "e' maiuscula ", z, w );
	
	z = 'X';
	w = ( (z < 'A') || ('Z' < z) );     // equivalente a testar se NAO e' letra maiuscula,
                                        // esta’ fora do intervalo [’a’:’z’], ou e’ menor que ‘a’ ou e’ maior que ‘z’
	printf ( "25. %s (%c) ? %d\n" , "nao e' maiuscula ", z, w );
	
	z = '0';
	w = ('0'==z || '1'==z); // equivalente a testar se e' igual a '0' ou a '1'
	printf ( "26. %s (%c) ? %d\n" , "e' 0 ou 1 ", z, w );
	strcpy ( s, "zero" ); // copiar para (s) <- "zero" (NAO usar '=' com caracteres);
	printf ( "27. palavra = %s\n", s );
	
	w = (strcmp ( "zero", s ) == 0);    // comparar se caracteres iguais (NAO usar '==' com caracteres);
                                        // Nota: O resultado da comparação sempre devera' ser avaliado
                                        // em relacao a zero, e sera' igual caso coincida.
	printf ( "28. palavra == %s ? %d\n", s, w );
	
	strcpy ( s, "um e dois" );     // copiar para (s) <- "outras palavras" (NAO usar '=' com caracteres);
	
	printf ( "29. palavras = %s\n", s );
	
	w = (strcmp ( "zero", s ) != 0);     // comparar se caracteres diferentes (NAO usar '!=' com caracteres);
                                         // Nota: O resultado da comparação sempre devera' ser avaliado
                                         // em relacao a zero, e sera' diferente caso NAO coincidir.
	
	printf ( "30. palavra == %s ? %d\n", s, w );

// encerrar
	printf ( "\n\nApertar ENTER para continuar." );
	getchar( ); // aguardar por ENTER	
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
		printf ("\n\n%s", "9 - method_09");
		
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
			
		case 9:
			method_09 ();
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

teste A - compilacao sem erros e escolha do method_09

----------------------------- outputs

>>>>>>>>>> teste A <<<<<<<<<<

exemplo0108 - programa = v8.0

autor: RAQUEL DE PARDE MOTTA



opcoes:

0 - terminar

9 - method_09

opcao = 9


opcao selecionada = 9
method_09
01. x = 0
02. y = 3.500000
03. z = A
04. x = 65 -> A
05. x = 3 -> 3.500000
06. z = a -> 97
07. z = 0 -> 48
08. x = 0 -> 0
09. x = 1 -> 1
10. x = 0 -> 1
11. x = 1 -> 1
12. x = 1 -> 1
13. w = 1 == 0 = 0
14. w = 1 != 0 = 1
15. w = 1 < 3.500000 = 1
16. w = 1 <= 3.500000 = 1
17. w = 3.500000 > 1 = 1
18. w = 3.500000 >= 1 = 1
19. e' par  (4%2) ? 1
20. e' impar  (4%2) ? 0
21. e' digito (5) ? 1
22. e' minuscula  (x) ? 1
23. nao e' minuscula  (X) ? 1
24. e' maiuscula  (x) ? 0
25. nao e' maiuscula  (X) ? 0
26. e' 0 ou 1  (0) ? 1
27. palavra = zero
28. palavra == zero ? 1
29. palavras = um e dois
30. palavra == um e dois ? 1


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
	7.0	       29/02		criacao method_07
	8.0	       29/02		criacao method_08
	9.0	       29/02		criacao method_09


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

	9.0	       A. ( OK )
*/

