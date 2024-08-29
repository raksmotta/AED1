/*
PUC MINAS - AEDs1
Abr/2024

Refação Verificação de Aprendizagem 1 (A01)

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: refacao_A01_raquelmotta
Versao: 0.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

//>>>>>>>>>> f_01 - questao 01 <<<<<<<<<<

int f_01 (char p[]) {
	
	int x = 0, y = 0;
	
	bool r = false, s = false, t = false;
	bool u = false, v = false, w = false;
	
	for (x = 0; x < strlen(p); x = x + 1) {
		
		r = ('a' <= p[x] && p[x] <= 'z');
		s = ('A' <= p[x] && p[x] <= 'Z');
		t = ('0' < p[x] && p[x] <= '9');
		
		u = (r || s) && !w; 
		v = !u && t; 
		w = !v;
		
		if (u) y = y + 1; else if (v) y = y - 1;
	}
	return (y);
}

void method01 (void){
	
	printf("\n\nquestao 01\n\n");
	
	printf ("\nresultado = %d\n", f_01 ("5aP4+0_8r4nK0"));
	
	printf("\n\naperte ENTER para continuar\n");
	getchar();
}


//>>>>>>>>>> f_02 - questao 02 <<<<<<<<<<

int f_02 (int a, int b) {
	
	if (a % 2 == 0 && b % 2 == 0) 
		return (f_02(a/2, b/2));
	else
		if 
			(a % 2 != 0 && b % 2 == 0) return (f_02(b % a, b/2));
	else
		if 
			(a % 2 == 0 && b % 2 != 0) return (f_02(a/2, a % b));
	
	return ((a - 1) % (b - 1)/2);
}

void method02 (void){
	
	printf("\n\nquestao 02\n\n");
	
	printf ("\nf_02 (30, 72) = %d\n", f_02 (30, 72));
	
	printf("\n\naperte ENTER para continuar\n");
	getchar();
}




//>>>>>>>>>> p_03 - questao 03 <<<<<<<<<<

void p_03 (void) {
	
	printf("\n\nquestao 03\n\n");
	
	for (int x = 1; x <= 5; x = x + 1) {
		printf ("\nx = %d", 2 * x + 1);
	}
	printf ("\n");
	
	int a = 3;
	int b = 5 * 3;
	int c;
	
	for (int x = a; x <= b; x = x + 3) {
		printf ("\nx = %d", c = (2 * x + 3)/3); 
	}
	
	printf("\n\naperte ENTER para continuar\n");
	getchar();
}





//>>>>>>>>>> p_04 - questao 04 <<<<<<<<<<
//inputar n = 5 para obter a resposta da questao

void p_04 (void) {
	
	printf("\n\nquestao 04\n\n");
	
	int x = 1, y = 1, v = 0, w = 0, m = 2, n = 0;
	
	printf ("\nn = "); scanf ("%d", &n); getchar ();
	
	printf ("%d %d ", x, y);
	
	while (m < n) {
		v = x + y; 
		m = m + 1;
		printf ("%d ", v);
		
		if (m < n - 1) {
			w = x + y + v; 
			m = m + 1; 
			printf ("%d ", w); 
		}
		
		x = v;
		y = w;
	}
	
	printf("\n\naperte ENTER para continuar\n");
	getchar();
}





//>>>>>>>>>> f_05 - questao 05 <<<<<<<<<<

int f_05 (char *s) {
	
	int x = 0, y = strlen(s) - 1;
	
	while (x <= y && s[x] == s[y]) {
		x = x + 1;
		y = y - 1;
	}
	return (x - y + s[x] - s[y]);
}

void method05 (void){
	
	printf("\n\nquestao 05\n\n");
	
	printf("resultado = %d", f_05 ("14641"));
	
	printf("\n\naperte ENTER para continuar\n");
	getchar();
}



//>>>>>>>>>> p_06 - questao 06 <<<<<<<<<<

int semirp (int num) {
	
	int dividers = 0;
	int i = 1;
	for (i = 1; i <= num; i ++) {
		if (num % i == 0) {
			dividers ++;
		}
	}
	if (dividers == 2) {
		return 1;
	} else {
		return 0;
	}
}


void p_06 (void) {
	
	printf("\n\nquestao 06\n\n");
	int sheldon_numbers = 0;
	int n;
	
	printf ("numeros de Sheldon: ");
	for (n = 11; n <= 99; n ++) {
		
		int dezena = n/10;
		int unidade = n % 10;
		int n_espelhado = unidade * 10 + dezena;
		
		if (n != n_espelhado && semirp(n) == 1 && semirp(n_espelhado) == 1) {
			printf ("%d ", n);
			sheldon_numbers ++;
		}
	}
	printf ("\n");
	printf ("no intervalo de 11 a 99, ha %d pares de numeros de Sheldon", sheldon_numbers/2);
	
	printf("\n\naperte ENTER para continuar\n");
	getchar();
}





//>>>>>>>>>> f_07 - questao 07 <<<<<<<<<<

int f_07 (char *cadeia){
	
	char c = 'c';
	int tam = strlen(cadeia);
	int i = 0;
	int t = 0;
	int u = 0;
	
	while(i<tam){
		
		c = cadeia[i];
		
		if(c == 'T'){
			t = t + 1;
		}
		
		if(c == 'U'){
			u = u + 1;
		}
		
		i = i + 1;
	}
	
	if((t>=1)&&(u==0)){
		
		printf("\n\na sequencia eh DNA");
		return(1);
		
	}else if((u>=1)&&(t==0)){
		
		printf("\n\na sequencia eh RNA");
		return(2);
		
	}else if((t==0)&&(u==0)){
		
		printf("\n\nsequencia indefinida");
		return(0);
		
	}else{
		
		printf("\n\nerro");
		return(-1);
		
	}
}

void method07 (void){
	
	printf("\n\nquestao 07\n\n");
	
	printf("saida para sequencia TACAGATA:");
	
	int result = f_07("TACAGATA");
	
	printf("\nretornou o valor [%d]", result);
	
	printf("\n\naperte ENTER para continuar\n");
	getchar();
}





//>>>>>>>>>> f_08 - questao 08 <<<<<<<<<<
//exemplo de sequencia que atende: 153

int testar (char *cadeia){
	
	int produto1 = 0;
	int soma1 = 0;
	int soma2 = 0;
	int i = 0;
	int tam = strlen (cadeia);
	
	do{
		
		if('0'<=cadeia[i] && cadeia[i]<='9'){
			
			soma1 = soma1 + (cadeia[i]-'0');
		}
		
		i = i + 1;
		
	}while(i<tam);
	
	produto1 = soma1 * soma1;
	
	i = 0;
	
	do{
		
		if('0'<=cadeia[i] && cadeia[i]<='9'){
			
			soma2 = soma2 + ((cadeia[i]-'0')*(cadeia[i]-'0')*(cadeia[i]-'0'));
			
		}
		
		i = i + 1;
		
	}while(i<tam);
	
	if (produto1 == soma2){
		
		return(1);
		
	}else{
		
		return(0);
		
	}
	
}

void p_08 (void){
	
	char sequencia[80];
	int resultado = 0;
	
	printf("\n\nquestao 08");
	
	printf("\n\nescreva uma cadeia de algarismos: "); scanf("%s", sequencia); getchar();
	
	resultado = testar(sequencia);
	
	if(resultado==1){
		
		printf("\n\na sequencia ATENDE a afirmativa");
		
	}else{
		
		printf("\n\na sequencia NAO atende a afirmativa");
		
	}
	
	printf("\n\naperte ENTER para continuar\n");
	getchar();
}




int main (int argc, char *argv[]){
	
	//identificar o programa
	printf ("%s", "Refacao A01 - questoes 01 a 08");
	printf ("\n%s\n%s", "autor: raquel de parde motta", "matricula: 854017");
	
	int opcao = 0;
	
	do{
		//mostrar as opcoes
		printf ("\n\n%s", "digite o numero correspondente a opcao desejada: ");
		printf ("\n\n%s", "0 - encerrar");
		printf ("\n\n%s", "1 - f_01 - questao 01");
		printf ("\n\n%s", "2 - f_02 - questao 02");
		printf ("\n\n%s", "3 - p_03 - questao 03");
		printf ("\n\n%s", "4 - p_04 - questao 04");
		printf ("\n\n%s", "5 - f_05 - questao 05");
		printf ("\n\n%s", "6 - p_06 - questao 06");
		printf ("\n\n%s", "7 - f_07 - questao 07");
		printf ("\n\n%s", "8 - f_08 - questao 08");
		
		//ler o valor inputado
		printf ("\n\n%s", "opcao =  ");
		scanf ("%i", &opcao);
		getchar ();
		
		switch (opcao) {
		case 0:
			break;
		case 1:
			method01();
			break;
		case 2:
			method02();
			break;
		case 3:
			p_03 ();
			break;
		case 4:
			p_04 ();
			break;
		case 5:
			method05();
			break;
		case 6:
			p_06 ();
			break;
		case 7:
			method07 ();
			break;
		case 8:
			p_08 ();
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


testes e outputs estao no arquivo "outputs_refacaoA01_raquelmotta.txt"


>>>>>>>>>>>>>>>>>>>>>>>>>>>>> notas e comentarios

*/

