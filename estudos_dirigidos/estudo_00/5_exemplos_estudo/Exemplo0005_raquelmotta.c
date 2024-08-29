/*
	Exemplo0005 - v0.0. - 21/02/2024
	Author: Raquel de Parde Motta
	
	Para compilar em terminal (janela de comandos):
	Linux : gcc -o exemplo0005 exemplo0005.c
	Windows: gcc -o exemplo0005 exemplo0005.c
	
	Para executar em terminal (janela de comandos):
	Linux : ./exemplo0005
	Windows: exemplo0005
*/

// dependencias
#include <stdio.h>	// para as entradas e saidas
#include <stdlib.h> // para outras funcoes de uso geral

/**
Metodo 01
*/

void method_01 (void)
{
	//identificar
	printf ("\n%s\n", "Metodo 01");
	
	//encerrar
	printf ("\nApertar ENTER para continuar.\n");
	getchar();
} //end method_01 ()


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
	
	printf ("%s\n", "Exemplo0005 - Programa = v0.0");
	printf ("%s\n", "Autor: Raquel de Parde Motta");
	printf ("\n");	// mudar de linha
	
	//acoes
	
	//repetir
	do
	{
	
		//para mostrar opcoes
		
		printf ("\n%s\n", "Opcoes:");
		printf ("\n%s", "0 - Terminar");
		printf ("\n%s", "1 - Metodo 01");
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
			case 1:
				method_01 ();
				break;
			default:	//comportamento padrao
				printf ("\nERRO: Opcao invalida.\n");
				break;
		} //end switch
	} 
	while (opcao != 0);
	
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
	
Exemplo0005.c: In function 'main':
Exemplo0005.c:89:13: error: expected ')' before '!' token
   89 | while (opcao! = 0)
      |       ~     ^
      |             )
Exemplo0005.c:89:24: error: expected ';' before 'printf'
   89 | while (opcao! = 0)
      |                   ^
      |                        ;
......
   93 |         printf ("\n\nApertar ENTER para terminar.");


---------------------------------------------- previsao de testes

a.) 800
b.) palavra
c.) -1
d.) 0
e.) 1

---------------------------------------------- historico

Versao  Data     Modificacao

 0.0    20/02    esboco
 0.1    20/02    mudanca de versao
 0.2    20/02    leitura e exibicao de inteiro
 0.3    20/02    leitura e exibicao mediante escolha
 0.4    21/02    leitura e exibicao mediante escolha - metodo 01
 0.5    21/02    leitura e exibicao mediante escolha com repeticao
 
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
 
 0.4        01. ( OK )    leitura e exib mediante escolha - teste a
 0.4        02. ( OK )    leitura e exib mediante escolha - teste b
 0.4        03. ( OK )    leitura e exib mediante escolha - teste c
 0.4        04. ( OK )    leitura e exib mediante escolha - teste d
 0.4        05. ( fail )  string lida como 0 - teste e
 
 0.5        01. ( fail )  erro ao compilar
 0.5        02. ( OK )    leitura e exib mediante escolha - teste a
 0.5        03. ( fail )  nao aceita input de string - teste b
 0.5        04. ( OK )    leitura e exib mediante escolha - teste c
 0.5        05. ( OK )    leitura e exib mediante escolha - teste d
 0.5        06. ( OK )    leitura e exib mediante escolha - teste e

*/