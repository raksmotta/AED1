/*
PUC MINAS - AEDs1
Mar/2024

Estudo Dirigido 04

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: programas_0411_a_0420
Versao: 0.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

//>>>>>>>>>> method_01 - programa 0411 <<<<<<<<<<
//ler 2 valores reais p definir um intervalo fechado
//ler n valores reais e contar quantos estao dentro e quantos estao fora do intervalo

void method_01 (void){
	
	double inferior = 1.0;
	double superior = 0.0;
	int test = 0;
	int counter = 0;
	int dentro = 0;
	int fora = 0;
	
	//identificar
	printf("\nmethod_01 - programa 0411");

	do{
		printf("\n\n%s", "insira o limite inferior do intervalo: ");
		scanf("%lf", &inferior);
		getchar();
		
		printf("\n\n%s", "insira o limite superior do intervalo: ");
		scanf("%lf", &superior);
		getchar();
	}while(superior<=inferior);
	
	printf("\n\nintervalo definido = [%lf : %lf]", inferior, superior);
	
	do{
		printf("\n\n%s", "quantos valores vc quer testar? ");
		scanf("%d", &test);
		getchar();
	}while(test<=0);
	
	double array[test];
	
	for(counter=0; counter<test; counter++){
		printf("\n\nvalor %d: ", counter+1);
		scanf("%lf", &array[counter]);
		getchar();
	}
	
	for(counter=0; counter<test; counter++){
		
		if(inferior<=array[counter] && array[counter]<=superior){
			dentro++;
			printf("\ndentro: %lf", array[counter]);
		}
	}
	
	printf("\n");

	for(counter=0; counter<test; counter++){
		
		if(array[counter]<inferior || superior<array[counter]){
			fora++;
			printf("\nfora: %lf", array[counter]);
		}
	}
	
	/*
	outra maneira seria criar outras duas cadeias de caracteres: dentros[dentro] e foras[fora]
	assim, faríamos mais 2 loops para cada cadeia:
	
	double dentros [test];
	int dentro =0;
	int fora= 0;
	
	for(dentro=0; dentro<test; counter++{
		
		if(inferior<=array[counter] && array[counter]<=superior){
			dentros[dentro]=array[counter];
			dentro++;
		}
	}
	
	depois tem que fazer uma outra repeticao pra ir lendo o dentros e mostrando 1 por 1
	*/
	
	printf("\n\n%d valores dentro do intervalo e %d valores fora", dentro, fora);
	
	//encerrar
	printf ("\n\n\n%s", "aperte ENTER para continuar");
	getchar();
}


//>>>>>>>>>> method_02 - programa 0412 <<<<<<<<<<
//ler sequencia de caracteres
//contar e mostrar a quantidade de maiusculas maiores que L

void method_02 (void){
	
	int tamanho = 0;
	int counter = 0;
	char word [80];
	int maiusculas = 0;
	
	//identificar
	printf("\nmethod_02 - programa 0412");
	
	printf("\n\ninsira uma palavra: ");
	scanf("%s", word);
	getchar();
	
	tamanho = strlen(word);
	
	//int maiuscula (char* text){
	
	for(counter=0; counter<tamanho; counter ++){
	
		if(76<word[counter] && word[counter]<90){
			printf("\n\n%c eh uma letra maiuscula maior que L", word[counter]);
			maiusculas++;
		}
	}

	printf("\n\ntotal de letras maiusculas maiores que L = %d", maiusculas);
	
	//encerrar
	printf ("\n\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_03 - programa 0413 <<<<<<<<<<
//ler sequencia de caracteres
//mostrar a quantidade de letras maiúsculas maiores que 'L' contadas por uma função definida para receber uma cadeia de caracteres como parâmetro

int contar_maiusculas (char* word){
	
	int maiusculas = 0;
	int counter = 0;
	int tamanho = 0;
	
	tamanho = strlen(word);
	
	for(counter=0; counter<tamanho; counter ++){
		
		if(76<word[counter] && word[counter]<90){
			//printf("\n\n%c eh uma letra maiuscula maior que L", word[counter]);
			maiusculas++;
		}
	}
	
	return (maiusculas);
}

void method_03 (void){
	
	char word [80];
	int maiores_l = 0;
	
	//identificar
	printf("\nmethod_03 - programa 0413");
	
	printf("\n\ninsira uma palavra: ");
	scanf("%s", word);
	getchar();
	
	maiores_l = contar_maiusculas(word);
	
	printf("\n\ntotal de letras maiusculas maiores que L = %d", maiores_l);
	
	//encerrar
	printf ("\n\n\n%s", "aperte ENTER para continuar");
	getchar();
}


//>>>>>>>>>> method_04 - programa 0414 <<<<<<<<<<
//mostrar as letras maiúsculas maiores que 'L' separadas por uma função que recebe uma cadeia de caracteres como parâmetro

int contar_maiusculas4 (char* word){
	
	int maiusculas = 0;
	int counter = 0;
	int tamanho = 0;
	
	tamanho = strlen(word);
	
	printf("\n\nletras maiusculas maiores que L =  ");
	
	for(counter=0; counter<tamanho; counter ++){
		
		if(76<word[counter] && word[counter]<90){
			printf("[%c]  ", word[counter]);
			maiusculas++;
		}
	}
	
	return (maiusculas);
}

void method_04 (void){
	
	char word [80];
	int maiores_l = 0;
	
	//identificar
	printf("\nmethod_04 - programa 0414");
	
	printf("\n\ninsira uma palavra: ");
	scanf("%s", word);
	getchar();
	
	maiores_l = contar_maiusculas4(word);
	
	printf("\n\ntotal de letras maiusculas maiores que L = %d", maiores_l);
	
	//encerrar
	printf ("\n\n\n%s", "aperte ENTER para continuar");
	getchar();
}


//>>>>>>>>>> method_05 - programa 0415 <<<<<<<<<<
//mostrar a quantidade de letras (tanto maiúsculas, quanto minúsculas) menores que 'L' e 'l'

//achei a questão formulada de maneira confusa. para mim o "E" nao faz sentido, deveria ser usado o "OU".

//as letras menores que 'l' E menores que 'L' serão simplesmente as menores que 'L' (maiúsculas de A até K).
//pois na lista ascii podemos ver que TODAS as maiúsculas já são menores que 'l' e TODAS as minúsculas são maiores que 'L'
//qual o sentido da comparação com o 'l' minúsculo? 
//para uma letra satisfazer simultaneamente as condições de ser menor que 'l' e menor que 'L', basta ser menor que 'L'.
//dessa maneira, não haverão letras minúsculas contadas, pois elas são maiores que 'L'.

//inclusive, se fosse escrito: "letras (maiúsculas ou minúsculas) que são menores que 'L' OU menores que 'l'." também não faria sentido.
//pois as letras maiúsculas que são maiores que 'L', por outro lado são menores que 'l' , entao simplesmente todas as maiúsculas da palavra 
//seriam contadas (de A até Z). SEM necessidade de comparação com o 'L'.

//ao meu ver, a comparacão faria sentido se tivéssemos:  "letras maiúsculas que são menores que 'L' OU letras minúsculas menores que 'l'."
//pois aí selecionaríamos o intervalo [A , L) E O INTERVALO [a, l).
//resolverei a questão dessa maneira para que o código mude em relação aos exercícios anteriores.

int contar_letras5 (char* word){
	
	int letras = 0;
	int counter = 0;
	int tamanho = 0;
	
	tamanho = strlen(word);
	
	printf("\n\nletras maiusculas menores que 'L' =  ");
	
	for(counter=0; counter<tamanho; counter ++){
		
		if(('A'<=word[counter] && word[counter]<'L')){
			printf("[%c]  ", word[counter]);
			letras++;
		}
	}
	
	printf("\n\nletras minusculas menores que 'l' =  ");
	
	for(counter=0; counter<tamanho; counter ++){
		
		if(('a'<=word[counter] && word[counter]<'l')){
			printf("[%c]  ", word[counter]);
			letras++;
		}
	}
	
	return (letras);
}

void method_05 (void){
	
	//identificar
	printf("\nmethod_05 - programa 0415");
	
	char word [80];
	int letras = 0;

	
	printf("\n\ninsira uma palavra: ");
	scanf("%s", word);
	getchar();
	
	letras = contar_letras5(word);
	
	printf("\n\ntotal de letras no intervalo [A , L) + letras no intervalo [a, l) = %d", letras);
	
	//encerrar
	printf ("\n\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_06 - programa 0416 <<<<<<<<<<
//mostrar as letras (tanto maiúsculas, quanto minúsculas) menores que 'L' e lk'
//mesma dúvida em relação ao enunciado que tive na questão anterior. portanto, farei a mesma abordagem.
//acho que seria 'k' e não lk', né? porque se for comparar se é menor que 'l' E 'k', basta verificar se é menor que k

int contar_letras6 (char* word){
	
	int letras = 0;
	int counter = 0;
	int tamanho = 0;
	
	tamanho = strlen(word);
	
	printf("\n\nletras maiusculas menores que 'L' =  ");
	
	for(counter=0; counter<tamanho; counter ++){
		
		if(('A'<=word[counter] && word[counter]<'L')){
			printf("[%c]  ", word[counter]);
			letras++;
		}
	}
	
	printf("\n\nletras minusculas menores que 'k' =  ");
	
	for(counter=0; counter<tamanho; counter ++){
		
		if(('a'<=word[counter] && word[counter]<'k')){
			printf("[%c]  ", word[counter]);
			letras++;
		}
	}
	
	return (letras);
}

void method_06 (void){
	
	//identificar
	printf("\nmethod_06 - programa 0416");
	
	char word [80];
	int letras = 0;
	
	
	printf("\n\ninsira uma palavra: ");
	scanf("%s", word);
	getchar();
	
	letras = contar_letras6(word);
	
	printf("\n\ntotal de letras no intervalo [A , L) + letras no intervalo [a, k) = %d", letras);
	
	//encerrar
	printf ("\n\n\n%s", "aperte ENTER para continuar");
	getchar();
}


//>>>>>>>>>> method_07 - programa 0417 <<<<<<<<<<
//mostrar a quantidade de dígitos pares em uma cadeia de caracteres
//considerar o valor inteiro do código equivalente (type casting) para teste. 

int contar_digitos_pares(char* palavra) {
	
	int counter = 0;
	
	int tamanho= strlen(palavra);
	
	int pares = 0;
	
	for(counter=0; counter<tamanho; counter++){

		// Converte o caractere para o valor inteiro do código ASCII
		int ascii_value = (int)palavra[counter];
		
		if ((48<=ascii_value)&&(ascii_value<=57)&&(palavra[counter]%2 == 0)) {
			pares++;
		}
	}
	
	return(pares);
}

void method_07 (void) {
	
	//identificar
	printf("\nmethod_07 - programa 0417");
	
	char word[80];
	int pares = 0;
	
	printf("\n\ninsira uma palavra: ");
	scanf("%s", word);
	getchar();
	
	pares = contar_digitos_pares(word);
	
	printf("\n\ntotal de digitos pares = %d", pares);
	
	//encerrar
	printf ("\n\n\n%s", "aperte ENTER para continuar");
	getchar();
}


//>>>>>>>>>> method_08 - programa 0418 <<<<<<<<<<
//mostrar todos os símbolos não alfanuméricos (que n sejam letras e dígitos) em uma cadeia de caracteres separados por meio de uma função

int contar_nao_alfa(char* palavra){
	
	int counter = 0;
	int Nalfa = 0;
	char Nalfas [80];
	int tamanho= strlen(palavra);
	
	
	for(counter=0; counter<tamanho; counter++){
		
		// Converte o caractere para o valor inteiro do código ASCII
		int ascii_value = (int)palavra[counter];
		
		if(((65<=ascii_value)&&(ascii_value<=90))||((97<=ascii_value)&&(ascii_value<=122))||((48<=ascii_value)&&(ascii_value<=57))){
			printf(" ");
		}
		else{
			Nalfas[Nalfa]=palavra[counter]; 
			Nalfa++;
		}
	}
	
	printf("\n\nsimbolos nao alfanumericos: ");
	for(counter=0; counter<Nalfa; counter++){
		printf("[%c] ", Nalfas[counter]);
	}

	return(Nalfa);
}

void method_08 (void){
	
	//identificar
	printf("\nmethod_08 - programa 0418");
	
	char word[80];
	int nao_alfa = 0;
	
	printf("\n\ninsira uma palavra: ");
	scanf("%s", word);
	getchar();
	
	nao_alfa = contar_nao_alfa(word);
	
	printf("\n\ntotal de simbolos nao-alfanumericos = %d", nao_alfa);
	
	//encerrar
	printf ("\n\n\n%s", "aperte ENTER para continuar");
	getchar();	
	
}

//>>>>>>>>>> method_09 - programa 0419 <<<<<<<<<<
//mostrar todos os símbolos alfanuméricos (letras e dígitos) em uma cadeia de caracteres separados por meio de uma função

int contar_alfa(char* palavra){
	
	int counter = 0;
	int alfa = 0;
	char alfas [80];
	int tamanho= strlen(palavra);
	
	
	for(counter=0; counter<tamanho; counter++){
		
		// Converte o caractere para o valor inteiro do código ASCII
		int ascii_value = (int)palavra[counter];
		
		if(((65<=ascii_value)&&(ascii_value<=90))||((97<=ascii_value)&&(ascii_value<=122))||((48<=ascii_value)&&(ascii_value<=57))){
			alfas[alfa]=palavra[counter]; 
			alfa++;
		}
		else{
			printf(" ");
		}
	}
	
	printf("\n\nsimbolos alfanumericos: ");
	for(counter=0; counter<alfa; counter++){
		printf("[%c] ", alfas[counter]);
	}
	
	return(alfa);
}

void method_09 (void){
	
	//identificar
	printf("\nmethod_09 - programa 0419");
	
	char word[80];
	int alfa = 0;
	
	printf("\n\ninsira uma palavra: ");
	scanf("%s", word);
	getchar();
	
	alfa = contar_alfa(word);
	
	printf("\n\ntotal de alfanumericos (letras e digitos) = %d", alfa);
	
	//encerrar
	printf ("\n\n\n%s", "aperte ENTER para continuar");
	getchar();	
	
}


//>>>>>>>>>> method_10 - programa 0420 <<<<<<<<<<
//ler certa quantidade de cadeias de caracteres do teclado, uma por vez;
//mostrar e contar a quantidade de símbolos alfanuméricos (letras e dígitos) em cada palavra, por meio de uma função, e calcular o total acumulado de todas as palavras.


void method_10 (void){
	
	int test = 0;
	int counter = 0;
	int alfa = 0;
	
	//identificar
	printf("\nmethod_10 - programa 0420");
	
	do{
		printf("\n\n%s", "quantas palavras vc quer testar? ");
		scanf("%d", &test);
		getchar();
	}while(test<=0);

	do{
		printf("\n\n\npalavra %d: ", counter+1);
		
		char word[80];
		
		scanf("%s", &word[0]);
		getchar();
		
		alfa+=contar_alfa(word);
		
		counter++;
		
	}while(counter<test);

	printf("\n\n\ntotal de alfanumericos (letras e digitos) = %d", alfa);
	
	//encerrar
	printf ("\n\n\n%s", "aperte ENTER para continuar");
	getchar();	
	
}










int main (int argc, char *argv[]){
	
	//identificar o programa
	printf ("%s", "estudo dirigido 00 - programas_0000_a_0000");
	printf ("\n%s\n%s", "autor: raquel de parde motta", "matricula: 854017");
	
	int opcao = 0;
	
	do{
		//mostrar as opcoes
		printf ("\n\n%s", "digite o numero correspondente a opcao desejada: ");
		printf ("\n\n%s", "0 - encerrar");
		printf ("\n\n%s", "1 - method_01 - programa 0411");
		printf ("\n\n%s", "2 - method_02 - programa 0412");
		printf ("\n\n%s", "3 - method_03 - programa 0413");
		printf ("\n\n%s", "4 - method_04 - programa 0414");
		printf ("\n\n%s", "5 - method_05 - programa 0415");
		printf ("\n\n%s", "6 - method_06 - programa 0416");
		printf ("\n\n%s", "7 - method_07 - programa 0417");
		printf ("\n\n%s", "8 - method_08 - programa 0418");
		printf ("\n\n%s", "9 - method_09 - programa 0419");
		printf ("\n\n%s", "10 - method_10 - programa 0420");
		
		//ler o valor inputado
		printf ("\n\n%s", "opcao =  ");
		scanf ("%i", &opcao);
		getchar ();
		
		switch (opcao) {
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
		case 6:
			method_06 ();
			break;
		case 7:
			method_07 ();
			break;
		case 8:
			method_08 ();
			break;
		case 9:
			method_09 ();
			break;
		case 10:
			method_10 ();
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

testes e outputs estao no arquivo "outputs_exercicios_ED04_raquelmotta.txt"


>>>>>>>>>>>>>>>>>>>>>>>>>>>>> notas e comentarios

*/
