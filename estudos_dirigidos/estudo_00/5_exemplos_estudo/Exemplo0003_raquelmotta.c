/*
	Exemplo0003 - v0.0. - 20/02/2024
	Author: Raquel de Parde Motta
	
	Para compilar em terminal (janela de comandos):
	Linux : gcc -o exemplo0003 exemplo0003.c
	Windows: gcc -o exemplo0003 exemplo0003.c
	
	Para executar em terminal (janela de comandos):
	Linux : ./exemplo0003
	Windows: exemplo0003
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
	
	printf ("%s\n", "Exemplo0003 - Programa = v0.0");
	printf ("%s\n", "Autor: Raquel de Parde Motta");
	printf ("\n");	// mudar de linha
	
	//acoes
	
	//para mostrar opcoes
	
	printf ("\n%s\n", "Opcoes:");
	printf ("\n%s", "0 - Terminar");
	printf ("\n");	
	
	//ler a opcao do teclado
	
	printf ("\n%s", "Opcao =");
	scanf ("%d", &opcao);
	getchar();	// para limpar a entrada de dados/resultados
	
	//para mostrar a opcao lida
	
	printf ("\n%s%d", "Opcao =", opcao);
	
	//escolher a acao dependente da opcao
	
	switch (opcao)
	{
		case 0:		//nao fazer nada
			break;
		default:	//comportamento padrao
			printf ("\nERRO: Opcao invalida.\n");
			break;
	} //end switch
	
	//encerrar
	
	printf ("\n\nApertar ENTER para terminar.");
	getchar();	// aguardar por ENTER
	return (0);	// voltar ao SO (sem erros)	
	
} // end main()

/*
---------------------------------------------- documentacao complementar

---------------------------------------------- notas / observacoes / comentarios
	
Nos testes D e E, pensei que receberia a mensagem de "ERRO: Opcao invalida.", pois são inputs diferentes do caso em que a opcao == 0. No entanto, por algum motivo o programa le/armazena caracteres e strings como o valor 0, e entao recebo o seguinte output:

Exemplo0003 - Programa = v0.0
Autor: Raquel de Parde Motta


Opcoes:

0 - Terminar

Opcao =quinze

Opcao =0

Apertar ENTER para terminar.

---------------------------------------------- previsao de testes

a.) 15
b.) 0
c.) -3
d.) x
e.) quinze

---------------------------------------------- historico

Versao  Data     Modificacao

 0.0    20/02    esboco
 0.1    20/02    mudanca de versao
 0.2    20/02    leitura e exibicao de inteiro
 0.3    20/02    leitura e exibicao mediante escolha
 
---------------------------------------------- testes

Versao    Teste
 0.0        01. ( OK )    identificacao de programa
 
 0.1        01. ( OK )    identificacao de programa
 
 0.2        01. ( fail )  erro ao compilar - ; faltante
 0.2        02. ( OK )    leitura e exibicao de int - teste a
 0.2        03. ( OK )    leitura e exibicao de int - teste b
 0.2        04. ( OK )    leitura e exibicao de int - teste c
 
 0.3        01. ( OK )    leitura e exib mediante escolha - teste a
 0.3        02. ( OK )    leitura e exib mediante escolha - teste b
 0.3        03. ( OK )    leitura e exib mediante escolha - teste c
 0.3        04. ( fail )  caractere lido como 0 - teste d
 0.3        05. ( fail )  string lida como 0 - teste e

*/