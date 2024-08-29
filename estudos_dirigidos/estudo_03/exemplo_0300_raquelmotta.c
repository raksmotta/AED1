/*
PUC MINAS - AEDs1
Mar/2024

Estudo Dirigido 03

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: exemplo_0300
Versao: 0.0

*/

#include <io.h>

//>>>>>>>>>> method_01 - repeticao com teste no inicio <<<<<<<<<<

void method_01 (void){
	
	//definir dado
	int x = 0;
	
	//identificar
	printf("\n\n%s", "method_01 - v 0.0");
	
	//ler do teclado o valor inicial
	x = IO_readint("\n\nentrar com uma quantidade: ");
	
	//repetir (x) vezes
	while (x>0){
		
		//mostrar valor atual
		IO_println(IO_toString_d(x));
		
		//passar ao proximo valor
		x = x - 1;
	}
	
	printf("\n\no valor de x = %d", x); //conferir se perdeu dados
	
	//encerrar
	IO_pause("\n\naperte ENTER para continuar");
}

//obs: Ao terminar a repetição, a quantidade será zero. 
//O valor lido inicialmente não será mais conhecido.
//Haverá potencial perda de informação, o que se recomenda evitar.


//>>>>>>>>>> method_02 - repeticao com teste no inicio <<<<<<<<<<

void method_02 (void){
	
	//definir dado
	int x = 0;
	int y = 0;
	
	//identificar
	printf("\n\n%s", "method_02 - v 0.0");
	
	//ler do teclado o valor inicial
	x = IO_readint("\n\nentrar com uma quantidade: ");
	
	//repetir (x) vezes
	y = x;
	while (y>0){
		//mostrar valor atual
		IO_println(IO_toString_d(x));
		
		//passar ao proximo valor
		y = y - 1;
	}
	
	printf("\n\no valor de x = %d", x); //conferir se perdeu dados
	
	//encerrar
	printf("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//obs.: desse jeito nao alteramos o valor de x.
//podemos perguntar qual o valor de x inputado mesmo depois que o loop terminar. nao ha perda de dados.
//mas assim nao conseguimos mostrar a contagem de algarismos
//fica só repetindo o mesmo valor de x por x vezes
//se colocassemos y na hora de mostrar o valor atual, teriamos uma contagem decrescente


//>>>>>>>>>> method_03 - repeticao com teste no inicio <<<<<<<<<<

void method_03 (void){
	
	//definir dado
	int x = 0;
	int y = 0;
	
	//identificar
	printf("\n\n%s", "method_03 - v 0.0");
	
	//ler do teclado
	x = IO_readint("\n\nentrar com uma quantidade: ");
	
	//repetir (x) vezes
	y = 1;
	while (y<=x){
		//mostrar valor atual
		IO_println(IO_toString_d(y));
		
		//passar ao proximo valor
		y = y + 1;
	}
	
	printf("\n\no valor de x = %d", x); //conferir dados
	printf("\n\no valor de y = %d", y); //conferir dados
	
	//encerrar
	printf("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//assim conseguimos mostrar os numeros na sequencia crescente
//o valor final de y sera x+1


//>>>>>>>>>> method_04 - repeticao com teste no inicio e variacao <<<<<<<<<<
//forma mais compacta de enunciar a repeticao com variacao

void method_04 (void){
	
	//definir dado
	int x = 0;
	int y = 0;
	int z = 0;
	
	//identificar
	printf("\n\n%s", "method_04 - v 0.0");
	
	//ler do teclado
	x = IO_readint("\n\nentrar com uma quantidade: ");
	
	//repetir (x) vezes;
	//for(inicio;teste;variacao)
	//quero dizer: na primeira vez que o loop for rodar, inicialize tornando y igual a 1.
	//teste a condicao e rode o loop enquanto y for menor ou igual a x
	//ao completar um loop, adicione uma unidade ao valor de y
	
	for(y=1;y<=x;y++){
		
		//ler valor do teclado
		z = IO_readint("valor = ");
		
		//mostrar valor atual
		IO_printf ("\n\n%d.%d\n", y, z);
	}
	
	//conferir dados
	printf("\n\no valor de x = %d", x); 
	printf("\n\no valor de y = %d", y); 
	printf("\n\no valor de z = %d", z); 
	
	//encerrar
	printf("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//primeiro entro com a quantidade, que é armazenada em x.
//depois,o programa me pedirá para inputar um valor (x) vezes.
//exemplo: se eu digitei 3 na quantidade, aparecerá 3 vezes na tela "valor ="
//o primeiro numero antes do ponto significa a contagem crescene ate chegar no valor de x
//o segundo numero depois do ponto significa o valor anterior que eu inputei (guarado em z)
//prevalece em z o ultimo valor inputado


//>>>>>>>>>> method_05 - repeticao com teste no inicio e variacao <<<<<<<<<<
//forma mais compacta de repeticao com variacao DEcrescente

void method_05 (void){
	
	//definir dado
	int x = 0;
	int y = 0;
	int z = 0;
	
	//identificar
	printf("\n\n%s", "method_05 - v 0.0");
	
	//ler do teclado
	x = IO_readint("\n\nentrar com uma quantidade: ");
	
	//repetir (x) vezes;
	//for(inicio;teste;variacao)
	//nesse caso, como trabalhamos apenas com inteiros, y>=1 é a mesma coisa que y>0
	
	for(y=x;y>=1;y--){ 
		
		//ler valor do teclado
		z = IO_readint("valor = ");
		
		//mostrar valor atual
		IO_printf ("\n\n%d.%d\n", y, z);
	}
	
	//conferir dados
	printf("\n\no valor de x = %d", x); 
	printf("\n\no valor de y = %d", y); 
	printf("\n\no valor de z = %d", z); 
	
	//encerrar
	printf("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//nesse caso o valor final de y eh 0


//>>>>>>>>>> method_06 - repeticao sobre cadeia de caracteres <<<<<<<<<<

void method_06 (void){
	
	//definir dado
	int y = 0;
	
	chars palavra = IO_new_chars(STR_SIZE);
	int tamanho = 0;
	
	//identificar
	printf ("\n\n%s", "method_06 - v 0.0");
	
	//ler do teclado
	palavra = IO_readstring("\n\nentrar com uma palavra: ");
	
	//para desconsiderar o \0 na posicao final que "fecha" a string
	tamanho = strlen(palavra)-1;
	
	//só para checar
	//a cadeia de caracteres inicia sua posicao em zero
	printf("tamanho da palavra = %d\n", tamanho); 
	
	//repetir para cada letra

	for(y=tamanho;y>=0;y--){ 
		
		//mostrar valor atual
		IO_printf("\n%d: [%c]\n", y, palavra[y]);
	}
	
	//encerrar
	printf("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//imprime a palavra de trás pra frente, da última posição (sem contar o \0) até a posição 0.


//>>>>>>>>>> method_07 - repeticao sobre cadeia de caracteres com variacao crescente <<<<<<<<<<

void method_07 (void){
	
	//definir dado
	int y = 0;
	
	char palavra [STR_SIZE];
	int tamanho = 0;
	
	//identificar
	printf ("\n\n%s", "method_07 - v 0.0");
	
	//ler do teclado
	IO_printf ("\n\nentrar com uma palavra: ");
	scanf ("%s", palavra);
	getchar();
	
	//para desconsiderar o \0 na posicao final que "fecha" a string
	tamanho = strlen(palavra);
	
	//só para checar
	//a cadeia de caracteres inicia sua posicao em zero
	printf("tamanho da palavra = %d\n", tamanho); 
	
	
	//como colocamos a condicao y menor que tamanho (e nao igual), o loop se encerrará quando
	//y for 1 unidade menor que o tamanho contado pelo strlen (que inclui o \0).
	//assim, nao se imprime caractere que ocupa a ultima posicao, o \0
	
	//dessa maneira, o numero printado quando perguntamos o valor de tamanho
	//equivale ao numero de caracteres (humanos) da palarva
	
	for(y=0;y<tamanho;y++){ 
		
		//mostrar valor atual
		IO_printf ("\n%d: [%c]\n", y, palavra[y]);
	}
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}


//>>>>>>>>>> method_08 - repeticao sobre intervalo de valores (variacao crescente) <<<<<<<<<<

void method_08 (void){
	
	//definir dado
	int inferior = 0;
	int superior = 0;
	int x = 0;
	
	//identificar
	printf("\n\n%s", "method_08 - v 0.0");
	
	//ler do teclado
	inferior = IO_readint("\n\nlimite inferior do intervalo: ");
	superior = IO_readint("\n\nlimite superior do intervalo: ");
	
	for(x=inferior;x<=superior;x++){ 
		
		//mostrar valor atual
		IO_printf ("\n\n%d", x);
	}

	//encerrar
	printf("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//>>>>>>>>>> method_09 - repeticao sobre intervalo de valores (variacao decrescente)<<<<<<<<<<

void method_09 (void){
	
	//definir dado
	double inferior = 0.0;
	double superior = 0.0;
	double passo = 0.0;
	double x = 0.0;
	
	//identificar
	printf("\n\n%s", "method_09 - v 0.0");
	
	//ler do teclado
	inferior = IO_readdouble("\n\nlimite inferior do intervalo: ");
	superior = IO_readdouble("\n\nlimite superior do intervalo: ");
	passo = IO_readdouble("\n\nvariacao no intervalo (passo): ");
	
	for(x=superior;x>=inferior;x=x-passo){ 
		
		//mostrar valor atual
		IO_printf ("\n\n%lf", x);
	}
	
	//encerrar
	printf("\n\n%s", "aperte ENTER para continuar");
	getchar();
}

//o valor do superior é mostrado. depois, subtrai-se dele o valor do passo.
//do valor do superior-passo, subtrai-se passo novamente. 
//até que a subtração dê um numero menor que o numero inferior.
//se passo for 0, o loop nao se encerra nunca e o programa buga


//>>>>>>>>>> method_10 - repeticao para confirmacao de caracteristicas de dados<<<<<<<<<<

void method_10 (void){
	
	//definir dado
	double inferior = 0.0;
	double superior = 0.0;
	double passo = 0.0;
	double x = 0.0;
	
	//identificar
	printf("\n\n%s", "method_10 - v 0.0");
	
	//ler do teclado
	inferior = IO_readdouble("\n\nlimite inferior do intervalo: ");
	
	//repetir ate haver confirmacao de validade
	do{
		superior = IO_readdouble("\n\nlimite superior do intervalo: ");
	}while(inferior>=superior);
	
	do{
		passo = IO_readdouble("\n\nvariacao no intervalo (passo): ");
	}while(passo<=0.0);
	
	for(x=superior;x>=inferior;x=x-passo){ 
		
		//mostrar valor atual
		IO_printf ("\n\n%lf", x);
	}
	
	//encerrar
	printf("\n\n%s", "aperte ENTER para continuar");
	getchar();
}




int main (int argc, char *argv[]){
	
	//identificar o programa
	printf ("%s", "estudo dirigido 03 - exemplo300");
	printf ("\n%s\n%s", "autor: raquel de parde motta", "matricula: 854017");
	
	int opcao = 0;
	
	do{
		//mostrar as opcoes
		printf ("\n\n%s", "digite o numero correspondente a opcao desejada: ");
		printf ("\n\n%s", "0 - encerrar");
		printf ("\n\n%s", "1 - method_01 - repeticao com teste no inicio");
		printf ("\n\n%s", "2 - method_02 - repeticao com teste no inicio (sem perda de dados)");
		printf ("\n\n%s", "3 - method_03 - repeticao com teste no inicio (comparando y com x no while)");
		printf ("\n\n%s", "4 - method_04 - repeticao com teste no inicio e variacao");
		printf ("\n\n%s", "5 - method_05 - repeticao com teste no inicio (variacao decrescente)");
		printf ("\n\n%s", "6 - method_06 - repeticao sobre cadeia de caracteres (variacao decrescente)");
		printf ("\n\n%s", "7 - method_07 - repeticao sobre cadeia de caracteres (variacao crescente)");
		printf ("\n\n%s", "8 - method_08 - repeticao sobre intervalo de valores (variacao crescente)");
		printf ("\n\n%s", "9 - method_09 - repeticao sobre intervalo de valores (variacao decrescente)");
		printf ("\n\n%s", "10 - method_10 - repeticao com confirmacao");
		
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


>>>>>>>>>>>>>>>>>>>>>>>>>>>>> notas e comentarios

em todos os casos, não dá certo colocar espaço em branco entre os caracteres.
ou imprime só as primeiras letras, ou só as últimas
o campo de entrada de dados fica "sujo" e a informacao inputada "pula" para outros procedimentos
ou entao o dado é perdido


*/
