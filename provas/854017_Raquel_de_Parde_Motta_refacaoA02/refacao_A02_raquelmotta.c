/*
PUC MINAS - AEDs1
Jun/2024

Avaliação 02

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: refacao_A02_raquelmotta
Versao: 0.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

//>>>>>>>>>> method_01 - questão 01 <<<<<<<<<<

int q_01 (int m, int n, int a[]){
	
	int x = 0;
	
	if (0<m && m<n-1 && a[m-1]-a[m]>0 && a[m]-a[m+1]<0){
		
		x = 1;
		
	}
	
	if (0<m && m<n){
		
		if(x>=0){
			
			x = x + q_01(m-1, n, a);
			
		}else{
			
			x = -m;
			
		}
		
	}
	
	return (x);
	
}

void method_01 (void){
	
	//identificar
	printf("\nmethod_01 - questao 01");
	
	int array [6] = {7, 9, 6, 8, 3, 5};
	
	int n  = 6;
	
	printf("\nq01 = %d", q_01(n-1, n, array));
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



//>>>>>>>>>> method_02 - questão 02 <<<<<<<<<<

void q_02 (char* p, char* q){
	
	char *r = calloc (strlen(p) * strlen(q) + 1, sizeof(char));
	
	int k = 0;
	
	for (int x = 0; x < strlen(p); x++){
		
		for (int y = 0; y < strlen(q); y++){
			
			if (x==strlen(p)/2){
				
				r[k] = p[x];
				
				r[k+1] = q[y];
				
				k = k+2;
				
				if (k > 6){
					
					y = strlen(q); 
					
					x = strlen(p);
					
				}
				
			}
			
		}
		
	}
	
	printf("\n[%s]", r);
	
}

void method_02 (void){
	
	//identificar
	printf("\nmethod_02 - questao 02");
	
	char* p = "goiabada";
	
	char* q = "queijo";
	
	q_02(p, q);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



//>>>>>>>>>> method_03 - questão 03 <<<<<<<<<<

void q_03 (int a, int b, int c, char m[][3][7]){
	
	for (int x=0; x<a; x++){
		
		for (int y=0; y<b; y++){
			
			if ('A'<m[x][0][0] && m[x][0][0]<'Z'){
				
				printf("\n%8s", m[x][2]);
				
				y = b;
				
			}
			
			printf("\n");
			
		}
		
	}
	
}

void method_03 (void){
	
	//identificar
	printf("\nmethod_03 - questao 03");
	
	char m[][3][7] = {{{"Azul"}, {"Blue"}, {"Blau"}},
		             {{"Branco"}, {"White"}, {"Weiss"}},
					 {{"Verde"}, {"Green"}, {"Grun"}}};
	
	q_03(3, 3, 7, m);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



//>>>>>>>>>> method_04 - questão 04 <<<<<<<<<<

void q_04 (char* p){
	
	int x = 0;
	
	for (int y=0; y<strlen(p); y=y+1){
		
		if (y<strlen(p)-1 && p[y]=='a' || p[y]=='o'){
			
			for (int z=y; z<strlen(p); z=z+1){
				
				p[z] = p[z+1];
				
			}
			
		}
		
		printf("\n[%s]", p);
		
	}
	
}

void method_04 (void){
	
	//identificar
	printf("\nmethod_04 - questao 04");
	
	char p[] = "acastanholada";
	
	q_04(p);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



//>>>>>>>>>> method_05 - questão 05 <<<<<<<<<<

char* q_05 (int x, int y, char* p){
	
	char c = '_';
	
	if (0<=x && x<strlen(p) && 0<=y && y<strlen(p)){
		
		c = p[x];
		
		p[x] = p[y];
		
		p[y] = c;
		
	}
	
	return (p);
	
}

void method_05 (void){
	
	//identificar
	printf("\nmethod_05 - questao 05");
	
	char p[] = "perda";
	
	q_05(1, 4, q_05(2, 3, p));
	
	printf("\n[%s]", p);
	
	q_05(2, 3, q_05(1, 4, p));
	
	printf("\n[%s]", p);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



//>>>>>>>>>> method_06 - questão 06 <<<<<<<<<<

int somarNome (char* p){
	
	int r = 0;
	
	for (int x=0; x<strlen(p); x++){
		
		if (p[x] == 'A' || p[x] == 'J' || p[x] == 'S'){ r = r + 1;}
		if (p[x] == 'B' || p[x] == 'K' || p[x] == 'T'){ r = r + 2;}
		if (p[x] == 'C' || p[x] == 'L' || p[x] == 'U'){ r = r + 3;}
		if (p[x] == 'D' || p[x] == 'M' || p[x] == 'V'){ r = r + 4;}
		if (p[x] == 'E' || p[x] == 'N' || p[x] == 'W'){ r = r + 5;}
		if (p[x] == 'F' || p[x] == 'O' || p[x] == 'X'){ r = r + 6;}
		if (p[x] == 'G' || p[x] == 'P' || p[x] == 'Y'){ r = r + 7;}
		if (p[x] == 'H' || p[x] == 'Q' || p[x] == 'Z'){ r = r + 8;}
		if (p[x] == 'I' || p[x] == 'R'){ r = r + 9;}
		
	}
	
	int a = 0;
	int b = 0;
	
	while (r>=10 && r!=11 && r!=22){
		
		a = r % 10;		//unidades
		b = (r-a)/10;	//dezenas
		
		r = a + b;
		
	}
	
	return (r);
	
}

void method_06 (void){
	
	//identificar
	printf("\nmethod_06 - questao 06");
	
	char* n1 = "MARIA DA SILVA";
	char* n2 = "ZIRALDO";
	
	int m = somarNome(n1);
	
	int z = somarNome(n2);
	
	printf("\nsoma de MARIA DA SILVA = %d", m);
	
	printf("\nsoma de ZIRALDO = %d", z);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



//>>>>>>>>>> method_07 - questão 07 <<<<<<<<<<

typedef struct Datas {
	
	int dias [3];
	
	struct Data{
		
		int dia;
		int mes;
		int ano;
		
	}data[3];
	
} sDatas;

void method_07 (void){
	
	//identificar
	printf("\nmethod_07 - questao 07");
	
	sDatas s;
	
	/*
	As listas de inicializadores só podem ser usadas no momento da declaração.
	No contexto fornecido da sua função method_07, s.dias já foi declarado como parte da estrutura sDatas.
	Para atribuir valores ao array s.dias após ele ter sido declarado, você deve atribuir valores a cada elemento individualmente dentro do array.
	*/
	s.dias[0] = 9876;
	s.dias[1] = 8967;
	s.dias[2] = 6789;
	
	for (int x=0; x<3; x++){
		
		s.data[x].dia = s.dias[x] % 365;
		
		if (s.data[x].dia == 0){
			
			s.data[x].ano = 1;
			
		}
		
		if (s.data[x].dia >= 31){
			
			s.data[x].mes = (int)s.data[x].dia / 31;
			
			s.data[x].dia = s.data[x].dia % 31;
			
		}
		
	}
	
	/*
	Minha configuração de loop inicial tinha uma limitação onde só poderia atualizar o pos_firstbday com base em comparações diretas entre pessoas 
	consecutivas (da primeira para a segunda, depois da segunda para a terceira).
	Assim, a iteração nunca daria pos_firstbday = 3;
	Agora, corrigi para que compare entre a primeira e a segunda pessoa e, depois, compare a terceira com aquela dentre as duas que está mais próxima do aniversário.
	*/
	int pos_firstbday = 0;
	
	for (int i=1; i<3; i++){
		
		if (s.data[i].ano > s.data[pos_firstbday].ano){
			
			pos_firstbday = i;
			
		}else if (s.data[i].mes > s.data[pos_firstbday].mes){
			
			pos_firstbday = i;
			
		}else if (s.data[i].dia > s.data[pos_firstbday].dia){
			
			pos_firstbday = i;
			
		}
		
	}
	
	printf("\no professor que fara aniversario primeiro eh o que viveu %d dias", s.dias[pos_firstbday]);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}



//>>>>>>>>>> method_08 - questão 08 <<<<<<<<<<

void method_08 (void){
	
	//identificar
	printf("\nmethod_08 - questao 08");
	
	FILE* origem = fopen("dados.txt", "rt");
	FILE* destino = fopen("resultado.txt", "wt");
	FILE* par = fopen("pares.txt", "wt");
	
	int temp = 0;
	int qtd_pares = 0;
	
	while(fscanf(origem, "%d", &temp) == 1){
		
		if (temp%2 !=0){
			
			fprintf(destino, "%d\n", temp);
			
		}else{
			
			fprintf(par, "%d\n", temp);
			qtd_pares++;
			
		}
		
	}
	
	fclose(par);
	fclose(origem);
	
	FILE* par2 = fopen("pares.txt", "rt");
	
	int y = 0;
	
	while(fscanf(par2, "%d", &temp) == 1 && y < qtd_pares){
		
		fprintf(destino, "%d\n", temp);	
		
		y++;
		
	}
	
	fclose(destino);
	fclose(par2);
	
	//encerrar
	printf ("\n\n%s", "aperte ENTER para continuar");
	getchar();
}





int main (int argc, char *argv[]){
	
	//identificar o programa
	printf ("%s", "refacao da avaliacao 02");
	printf ("\n%s\n%s", "autor: raquel de parde motta", "matricula: 854017");
	
	int opcao = 0;
	
	do{
		//mostrar as opcoes
		printf ("\n\n%s", "digite o numero correspondente a opcao desejada: ");
		printf ("\n\n%s", "0 - encerrar");
		printf ("\n\n%s", "1 - questao 01");
		printf ("\n\n%s", "2 - questao 02");
		printf ("\n\n%s", "3 - questao 03");
		printf ("\n\n%s", "4 - questao 04");
		printf ("\n\n%s", "5 - questao 05");
		printf ("\n\n%s", "6 - questao 06");
		printf ("\n\n%s", "7 - questao 07");
		printf ("\n\n%s", "8 - questao 08");
		
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

testes e outputs estao no arquivo "outputs_refacaoA02_raquelmotta.txt"


>>>>>>>>>>>>>>>>>>>>>>>>>>>>> notas e comentarios

*/
