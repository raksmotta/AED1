/*
	Exemplo0002 - v0.0. - 20/02/2024
	Author: Raquel de Parde Motta
	
	Para compilar em terminal (janela de comandos):
	Linux : gcc -o exemplo0002 exemplo0002.c
	Windows: gcc -o exemplo0002 exemplo0002.c
	
	Para executar em terminal (janela de comandos):
	Linux : ./exemplo0002
	Windows: exemplo0002
*/

// dependencias
#include <stdio.h>	// para as entradas e saidas
#include <stdlib.h> // para outras funcoes de uso geral

/*
 Funcao principal.
 @return codigo de encerramento
 @param argc - quantidade de parametros na linha de comandos
 @param argv - arranjo com o grupo de parametros na linha de comandos
*/

int main ( int argc, char* argv[] )
{
	//definir dados/resultados
	
	int opcao = 0;
	
	//identificar
	
	printf ("%s\n", "Exemplo0002 - Programa = v0.0");
	printf ("%s\n", "Autor: Raquel de Parde Motta");
	printf ("\n");	// mudar de linha
	
	//acoes
	
	//ler a opcao do teclado
	
	printf ("\n%s", "Opcao =");
	scanf ("%d", &opcao);
	getchar();	// para limpar a entrada de dados/resultados
	
	//para mostrar a opcao lida
	
	printf ("\n%s%d", "Opcao =", opcao);
	
	
	//encerrar
	
	printf ("\n\nApertar ENTER para terminar.");
	getchar();	// aguardar por ENTER
	return (0);	// voltar ao SO (sem erros)	
	
} // end main()

/*
---------------------------------------------- documentacao complementar

---------------------------------------------- notas / observacoes / comentarios

	>>>> tinha esquecido do ; na linha 47.
	quando fui compilar o programa, apareceu o seguinte:
	
	 Exemplo0002.c: In function 'main':
Exemplo0002.c:47:44: error: expected ';' before 'printf'
   47 |         printf ("\n%s%d", "Opcao =", opcao)
      |                                            ^
      |                                            ;
......
   51 |         printf ("\n\nApertar ENTER para terminar.");
      |         ~~~~~~
	
	
	>>>> na linha 47, ao inves de printf ("\n%s%d", "Opcao =", opcao); poderia emitir o %s e escrever de outra forma: 
	printf("\nOpcao = %d", opcao); ? 
	testei e verifiquei que sim, da na mesma
	

---------------------------------------------- previsao de testes

a.) 5
b.) -5
c.) 123456789

---------------------------------------------- historico

Versao  Data     Modificacao

 0.0    20/02    esboco
 0.1    20/02    mudanca de versao
 0.2    20/02    leitura e exibicao de inteiro
 
---------------------------------------------- testes

Versao    Teste
 0.0        01. ( OK )    identificacao de programa
 
 0.1        01. ( OK )    identificacao de programa
 
 0.2        01. ( fail )  erro ao compilar - ; faltante
 0.2        02. ( OK )    leitura e exibicao de int - teste a
 0.2        03. ( OK )    leitura e exibicao de int - teste b
 0.2        04. ( OK )    leitura e exibicao de int - teste c

*/