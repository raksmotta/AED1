/*
PUC MINAS - AEDs1
Abr/2024

Estudo Dirigido 07

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: exemplos_ed07_raquelmotta
Versao: 0.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <io.h>

//writeInts - gravar em arquivo texto certa quantidade de valores
//@param fileName - nome do arquivo
//@param x - quantidade de valores

void writeInts (chars fileName, int x){
	
	//definir dados
	FILE* arquivo = fopen (fileName, "wt");
	int y = 0;
	
	//repetir para a quantidade de dados
	for (y=1; y<=x; y=y+1){
		
		//gravar valor
		fprintf(arquivo, "%d\n", y);
		
	}
	
	//fechar arquivo (INDISPENSAVEL para gravacao)
	fclose (arquivo);
	
}



//method01 - mostrar certa quantidade de valores

void method01 (){
	
	//identificar
	printf("\n\nmetodo01\n");
	
	//executar metodo auxiliar
	writeInts("DADOS1.TXT", 10);
	
	//encerrar
	IO_pause("apertar ENTER para continuar");
	
}



//readInts - ler de arquivo texto certa quantidade de valores
//@param fileName - nome do arquivo
//@param x - quantidade de valores

void readInts (chars fileName){
	
	//definir dados
	FILE* arquivo = fopen (fileName, "rt");
	int x = 0;
	
	//tentar ler o primeiro
	fscanf(arquivo, "%d", &x);
	
	//repetir enquanto houver dados
	while(!feof(arquivo)){
		
		//mostrar valor
		printf("%d\n", x);
		
		//tentar ler o proximo
		fscanf(arquivo, "%d", &x);
		
	}
	
	//fechar arquivo (RECOMENDAVEL para leitura)
	fclose(arquivo);	
	
}

void method02 (){
	
	//identificar
	printf("\n\nmetodo02\n");
	
	//executar o metodo auxiliar
	readInts("DADOS1.TXT");
	
	//encerrar
	IO_pause ("apertar ENTER para continar");
	
}//obs.: todo o conteudo sera lido como texto, sem distincoes



//writeDoubles - gravar em um arquivo certa quantidade de valores

void writeDoubles (chars fileName, int x){
	
	//definir dados
	FILE* arquivo = fopen (fileName,"wt");
	int y = 0;
	
	//gravar quantidade de valores
	IO_fprintf(arquivo, "%d\n", x);
	
	//repetir para a quantidade de dados
	for(y=1; y<=x; y=y+1){
		
		//gravar valor
		IO_fprintf(arquivo, "%lf\n", (0.1*y));
		
	}
	
	//fechar arquivo (INDISPENSAVEL para gravacao)
	fclose (arquivo);
	
}

void method03 (){
	
	//identificar
	printf("\n\nmetodo03\n");
	
	//executar o metodo auxiliar
	writeDoubles("DADOS2.TXT", 10);
	
	//encerrar
	IO_pause ("apertar ENTER para continar");
	
}//obs.: observar a necessidade de incluir mudança de linha



//>>>>>>>>>>>>>>>>>>>>> readDoubles

void readDoubles (chars fileName){
	
	//definir dados
	FILE* arquivo = fopen (fileName, "rt");
	int x = 0;
	int y = 1;
	double z = 0.0;
	
	//tentar ler a quantidade de dados
	fscanf(arquivo, "%d", &x);
	
	//repetir enquanto houver dados e quantidade nao tiver sido alcancada
	while(!feof(arquivo)&&y<=x){
		
		//tentar ler
		fscanf(arquivo, "%lf", &z);
		
		//mostrar valor
		printf("%2d: %lf\n", y, z);
		
		//passar ao proximo
		y = y + 1;
		
	}
	
	//fechar arquivo (RECOMENDAVEL para leitura)
	fclose(arquivo);
	
}

void method04 (){
	
	//identificar
	printf("\n\nmetodo04\n");
	
	readDoubles("DADOS2.TXT");
	
	//encerrar
	IO_pause ("apertar ENTER para continar");
	
}



//>>>>>>>>>>>>>>>>>>>>> writeText

void writeText (chars fileName){
	
	//definir dados
	FILE* arquivo = fopen (fileName, "wt");
	chars linha = IO_new_chars(STR_SIZE);
	//(char*) malloc(5*sizeof(char))
	
	//repetir ate desejar parar
	IO_println("\ngravar linhas. para terminar, digitar PARAR:\n");
	
	do{
		
		//ler do teclado
		strcpy(linha, IO_readln(""));
		
		//gravar valor
		IO_fprintf(arquivo, "%s\n", linha);
		
	}while (strcmp("PARAR", linha)!=0);
	
	//fechar arquivo (INDISPENSAVEL para gravacao)
	fclose (arquivo);
	
}

void method05 (){
	
	//identificar
	printf("\n\nmetodo05\n");
	
	writeText("DADOS3.TXT");
	
	//encerrar
	IO_pause ("apertar ENTER para continar");
	
}//observar a comparacao de cadeias de caracteres



//>>>>>>>>>>>>>>>>>>>>> readText

void readText (chars fileName){
	
	FILE* arquivo = fopen (fileName, "rt");
	chars linha = IO_new_chars(STR_SIZE);
	
	//tentar ler o primeiro
	strcpy(linha, IO_freadln(arquivo));
	
	//repetir enquanto houver dados
	while (!feof(arquivo) && strcmp ("PARAR", linha)!=0){
		
		//mostrar valor
		printf("\n%s\n", linha);
		
		//tentar ler o proximo
		strcpy (linha, IO_freadln(arquivo));
		
	}
	
	//fechar arquivo (RECOMENDAVEL para leitura)
	fclose(arquivo);
	
}

void method06 (){
	
	//identificar
	printf("\n\nmetodo06\n");
	
	readText("DADOS3.TXT");
	
	//encerrar
	IO_pause ("apertar ENTER para continar");
	
}



//>>>>>>>>>>>>>>>>>>>>> copyText
//copiar dados em arquivo texto
//@param fileOut - nome do arquivo de saída (destino)
//@param fileIn - nome do arquivo de entrada (origem)

void copyText (chars fileOut, chars fileIn){
	
	//definir dados
	FILE* saida = fopen (fileOut, "wt");
	
	FILE* entrada = fopen (fileIn, "rt");
	
	chars linha = IO_new_chars(STR_SIZE);
	
	int contador = 0;
	
	//ler da origem
	strcpy (linha, IO_freadln(entrada));
	
	//repetir enquanto houver dados
	while (!(feof(entrada))){
		
		//contar linha lida
		contador = contador + 1;
		
		//gravar no destino
		//EXCEPCIONALMENTE sem a ultima linha, nesse caso
		if (strcmp("PARAR",  linha)!=0){
			
			IO_fprintln(saida, linha);
			
		}
		
		//ler da origem
		strcpy (linha, IO_freadln(entrada));
	}
	
	//informar total de linhas copiadas
	IO_printf("\n\nlines read = %d\n", contador);
	
	//fechar arquivos
	fclose(saida);
	fclose(entrada);
	
}

void method07 (){
	
	//identificar
	printf("\n\nmetodo07\n");
	
	copyText("DADOS4.TXT","DADOS3.TXT");
	
	//encerrar
	IO_pause ("apertar ENTER para continar");
	
}
/*deve-se observar a ordem dos parametros, pois o primeiro nome indicará
o arquivo que será gravado. se o arquivo já existir, isso resultará na 
perda de dados.
para evitar problemas de perda de dados, recomenda-se verificar a 
existencia do arquivo antes de tentar abrí-lo para gravação
*/



//>>>>>>>>>>>>>>>>>>>>> appendText
//adicionar texto ao arquivo (gravar em arq texto certa quant de valores)
//@param fileName - nome do arquivo
//@param x - quantidade de valores

void appendText (chars fileName){
	
	//definir dados
	FILE* arquivo = fopen (fileName, "at");
	chars linha = IO_new_chars(STR_SIZE);
	
	//repetir ate desejar parar
	IO_println("\n\ngravar linhas. para terminar, entrar com PARAR\n\n");
	
	do{
		
		//ler do teclado
		strcpy(linha, IO_readln(""));
		
		//gravar valor
		IO_fprintln(arquivo, linha);
		
	}while (strcmp("PARAR", linha)!=0);
	
	fclose(arquivo);
	
}

void method08 (){
	
	//identificar
	printf("\n\nmetodo08\n");
	
	appendText("DADOS4.TXT");
	
	//encerrar
	IO_pause ("apertar ENTER para continar");
	
}



//>>>>>>>>>>>>>>>>>>>>> readWords
//ler palavras de arquivo, uma por vez

void readWords (chars fileName){
	
	
	FILE* arquivo = fopen(fileName, "rt");
	chars linha = IO_new_chars(STR_SIZE);
	
	//tentar ler a primeira
	strcpy(linha, IO_fread(arquivo));
	
	//repetir enquanto houver dados
	while(!feof(arquivo) && strcmp("PARAR", linha)!=0){
		
		fprintf(arquivo, "\n%s\n", linha);
		
		//tentar ler o proximo
		strcpy (linha, IO_fread(arquivo));
		
	}
	
	fclose(arquivo);
	
}

void method09 (){
	
	//identificar
	printf("\n\nmetodo09\n");
	
	readWords("DADOS4.TXT");
	
	//encerrar
	IO_pause ("apertar ENTER para continar");
	
}



//>>>>>>>>>>>>>>>>>>>>> searchWord
//prcurar palavra em arquivo, uma por vez
//@return true, se encontrar. retorna false se NÃO encontrar.
//@param fileName - nome do arquivo
//@param word - palavra a procurar

bool searchWord (chars fileName, chars word){
	
	FILE* arquivo = fopen(fileName,"rt");
	chars linha = IO_new_chars(STR_SIZE);
	
	//tentar ler a primeira
	strcpy(linha, IO_fread(arquivo));
	
	//repetir enquanto houver dados
	while(!feof(arquivo) && strcmp(word, linha)!=0){
		
		//tentar ler o proximo
		strcpy(linha, IO_fread(arquivo));
		
	}
	
	fclose(arquivo);
	
	//retornar resultado
	return(strcpy(word,linha)==0);
	//se word e linha forem iguais, o resultado é zero, valor de TRUE
	//se nunca houver word = linha, o valor é FALSO
}

void method10 (){
	
	//identificar
	printf("\n\nmetodo10\n");
	
	IO_printf("\nprocurar (\"%s\") = %d\n", "pqr", searchWord("DADOS4.TXT", "pqr"));
	
	IO_printf("\nprocurar (\"%s\") = %d\n", "pqs", searchWord("DADOS4.TXT", "pqs"));
	
	//encerrar
	IO_pause ("apertar ENTER para continar");
	
}//observar a necessidade de verificar a existencia de dado antes de testa-lo







int main (int argc, char *argv[]){
	
	//identificar o programa
	printf ("%s", "estudo dirigido 07 - exemplos");
	printf ("\n%s\n%s", "autor: raquel de parde motta", "matricula: 854017");
	
	int opcao = 0;
	
	do{
		//mostrar as opcoes
		printf ("\n\n%s", "digite o numero correspondente a opcao desejada: ");
		printf ("\n\n%s", "0 - encerrar");
		printf ("\n\n%s", "1 - method_01");
		printf ("\n\n%s", "2 - method_02");
		printf ("\n\n%s", "3 - method_03");
		printf ("\n\n%s", "4 - method_04");
		printf ("\n\n%s", "5 - method_05");
		printf ("\n\n%s", "6 - method_06");
		printf ("\n\n%s", "7 - method_07");
		printf ("\n\n%s", "8 - method_08");
		printf ("\n\n%s", "9 - method_09");
		printf ("\n\n%s", "10 - method_10");
		
		//ler o valor inputado
		printf ("\n\n%s", "opcao =  ");
		scanf ("%i", &opcao);
		getchar ();
		
		switch (opcao) {
		case 0:
			break;
		case 1:
			method01 ();
			break;
		case 2:
			method02 ();
			break;
		case 3:
			method03 ();
			break;
		case 4:
			method04 ();
			break;
		case 5:
			method05 ();
			break;
		case 6:
			method06 ();
			break;
		case 7:
			method07 ();
			break;
		case 8:
			method08 ();
			break;
		case 9:
			method09 ();
			break;
		case 10:
			method10 ();
			break;
		default:
			printf ("\n\n%s", "erro - opcao invalida");
			break;
		}
	}while(opcao !=0);
	
	return (0);
}

/*
DOCUMENTACAO COMPLEMENTAR


>>>>>>>>>>>>>>>>>>>>>>>>>>>>> outputs


>>>>>>>>>>>>>>>>>>>>>>>>>>>>> notas e comentarios

explicacao da monitoria para exercicio 09 do ed07:
nao entendi muito bem para ser sincera

char linha[256];
int cont = 0;
	ler prox linha com fgets ate o \n;
while (!feof(arquivo)){
	for(int i = 0; i < 256; i++){
	
		if(linha[i] == '\0' || linha[i] == '\n'){
			i = 257;
			printar numero de maiusculas arq;
	
		}else{
	
			if(linha[i] == ' '){
				printar numero de maiusculas arq;
				cont = 0;
			}else if('A' <= linha[i] && linha[i]<='Z'){
				cont++;
			}
		}
	}
	ler prox linha com fgets ate o \n;
}

*/
