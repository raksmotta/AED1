/*
	Exemplo0001 - v0.0. - 20/02/2024
	Author: Raquel de Parde Motta
	
	Para compilar em terminal (janela de comandos):
	Linux : gcc -o exemplo0001 exemplo0001.c
	Windows: gcc -o exemplo0001 exemplo0001.c
	
	Para executar em terminal (janela de comandos):
	Linux : ./exemplo0001
	Windows: exemplo0001
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
	
	//identificar
	
	printf ("%s\n", "Exemplo0001 - Programa = v0.0");
	printf ("%s\n", "Autor: Raquel de Parde Motta");
	printf ("\n");	// mudar de linha
	
	//acoes
	
	//encerrar
	
	printf ("\n\nApertar ENTER para terminar.");
	getchar();	// aguardar por ENTER
	return (0);	// voltar ao SO (sem erros)	
	
} // end main()

/*
---------------------------------------------- documentacao complementar

---------------------------------------------- notas / observacoes / comentarios

---------------------------------------------- previsao de testes

a.) 5
b.) -5
c.) 123456789

---------------------------------------------- historico

Versao  Data     Modificacao

 0.0    20/02    esboco
 0.1    20/02    mudanca de versao
 
---------------------------------------------- testes

Versao    Teste
 0.0        01. ( OK )    identificacao de programa
 0.1        01. ( OK )    identificacao de programa

*/