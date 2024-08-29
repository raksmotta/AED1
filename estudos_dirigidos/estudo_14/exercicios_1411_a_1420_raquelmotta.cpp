/*
PUC MINAS - AEDs1
Maio/2024

Estudo Dirigido 14

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: exercicios_1411_a_1420_raquelmotta
Versao: 0.0

*/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cctype>

using std::cout;
using std::cin;



class kelstring{
	
public:
	
	std::string str;
	int tam;
	int shift;	//shift specifies the number of positions each letter should be moved in the alphabet.
	char** words;
	int wordCount;

	
	int stringToInt() {
		
		int check = 0;
		
		for(int x = 0; x < str.length(); x++){
			
			if (!('0' <= str[x] && str[x] <= '9')){
				
				return -1;
				
			}
			
		}
		
		return std::stoi(str);
		
	}
	
	double stringToDouble() {
		
		for(int x = 0; x < str.length(); x++){
			
			if ((!('0' <= str[x] && str[x] <= '9')) && (str[x] != '.')){
				
				return 0.0;
				
			}
			
		}
		
		return std::stod(str);
		
	}
	
	bool getBoolean() {
		
		/*The compare() function returns 0 when the strings are equal, which evaluates to false in boolean expressions. 
		Conversely, it returns a non-zero value (which is true in boolean context) when the strings are different. This is the opposite of what you 
		might expect if you're used to functions that return true for matches.*/
		
		if ( str.compare("true") == 0 || str.compare("T") == 0 || str.compare("1") == 0 ){
			
			cout << "\n\nvalor verdadeiro" << std::endl;
			
			return true;
			
		}else if ( str.compare("false") == 0 || str.compare("F") == 0 || str.compare("0") == 0 ){
			
			cout << "\n\nvalor falso" << std::endl;
			
			return false;
			
		}else{
			
			cout << "\n\nerro. a string fornecida eh invalida. inputs validos: true, false, T, F, 0, 1" << std::endl;
			
			return false;
			
		}	
		
	}
	
	/*std::string::find() searches for a substring within a string and returns the position of the first occurrence of the substring. 
	If the substring is not found, it returns std::string::npos.*/
	bool contains (std::string text){
		
		return str.find(text) != std::string::npos;
		
		//se str.find(text) for IGUAL a std::string::npos, a funcao retorna FALSO
		//se str.find(text) NAO for IGUAL a std::string::npos, a funcao retorna VERDADEIRO
		
	}
	
	std::string toUpperCase(){
		
		std::string result = str;	//copiando a string str para a string resultado, que sera manipulada e modificada para ser retornada
		
		char c = 'a';
		
		int count = 0;
		
		for(int x = 0; x < result.length(); x++){
			
			if ('a'<=result[x] && result[x]<='z'){
				
				c = std::toupper(result[x]);
				
				result[x] = c;
				
				count ++;
				
			}
			
		}
		
		if (count == 0){
			
			cout << "\n\nnao ha letras minusculas a serem convertidas na string fornecida: " << result << std::endl;
			
		}else{
			
			cout << "\n\nstring toda convertida para maiusculas: " << result << std::endl;
			
		}
		
		return result;
		
	}
	
	std::string toLowerCase(){
		
		std::string result = str;
		
		char c = 'a';
		
		int count = 0;
		
		for(int x = 0; x < result.length(); x++){
			
			if ('A'<=result[x] && result[x]<='Z'){
				
				c = std::tolower(result[x]);
				/*The std::tolower function converts a given uppercase letter to its lowercase counterpart if it is an uppercase letter. 
				If the passed character is not an uppercase letter, it returns the character unchanged.*/
				
				result[x] = c;
				
				count ++;
				
			}
			
		}
		
		if (count == 0){
			
			cout << "\n\nnao ha letras maiusculas a serem convertidas na string fornecida: " << result << std::endl;
			
		}else{
			
			cout << "\n\nstring toda convertida para minusculas: " << result << std::endl;
			
		}
		
		return result;
		
	}
	
	std::string replace (char original, char novo){
		
		std::string result = str;
		
		for(int x = 0; x < result.length(); x++){
			
			if(result[x] == original){
				
				result[x] = novo;
				
			}
			
		}
		
		return result;
		
	}
	
	std::string cesarEncrypt (){
		
		std::string result = str;
		
		/*Range-based For Loop: This loop iterates over each character in result. c is a variable that will hold an element from the container. 
		Each character c in result is accessed by reference, meaning changes to c will directly affect the result string. Ou seja: mesma ideia que o
		for com str.length() que eu estava fazendo anteriormente*/
		for (char &c : result){
			
			/*The isalpha() function checks if c is an alphabetic letter (either lowercase or uppercase).
			Ou seja: substitui aquele if (('a' <= result[x] && result[x] <= 'z') || ('A' <= result[x] && result[x] <= 'Z'))*/
			if (isalpha(c)) {
				
				char base = isupper(c) ? 'A' : 'a';
				//se c for uma letra maiuscula, isto é, se isupper(c) retornar TRUE, o caractere base será igual a 'A'.
				//se c for minuscula e isupper(c) retornar FALSE, o caractere base será igual a 'a'.
				/*outra maneira de escrever seria:
				if (isupper(c)) {
				base = 'A';
				} else {
				base = 'a';
				}
				*/
				
				c = static_cast<char>((c - base + shift) % 26 + base);
				//subtrair a base (A ou a) do caractere c nos dá um inteiro entre 0 e 25, representando a posicao da letra no alfabeto
				//somamos o valor de shift para mover as posicoes do caractere no alfabeto
				//depois de calcular a nova posicao, adicionamos DE VOLTA o valor base para converter essa posicao inteira no caractere equivalente do alfabeto.
				
				//se c-base+shift dividido por 26 apresentar resto 0, é porque a letra shiftada excedeu o fim do alfabeto (passou do caractere z)
				//assim, voltamos ao inicio do alfabeto
				//('Z' - 'A' + 1) % 26 = 26 % 26 = 0 (deu uma "volta completa" no alfabeto)
				/*
				Modulo Operation: The result of x % 26 is the remainder when x is divided by 26.
				Effect of Modulo 26: This ensures that the result is always between 0 and 25, which perfectly maps to the indices of the letters in the alphabet.
				*/
				
				//static_cast<char>: Ensures that the result of the calculation is cast back to a character type before assigning it back to c.
				
			}
			
		}
		
		return result;
		
	}
	
	std::string cesarDecrypt (){
		
		std::string result = str;
		
		for (char &c : result){
			
			if (isalpha(c)) {
				
				char base = isupper(c) ? 'A' : 'a';
				
				c = static_cast<char>((c - base - shift + 26) % 26 + base);
				//já que antes shiftei para frente, agora para reverter devo shiftar para trás
				//+26 certifica-se de que o argumento para %26 não será negativo
				//nao faz diferenca adicionar 26 porque é como se fosse "uma volta completa no alfabeto que para no mesmo lugar"
				/*exemplo: vamos supor que o caractere encriptado é B e o shift original é 1
				('B' - 'A') = 1.
				(1 - 1 + 26) % 26 = 26 % 26 = 0.
				0 + 'A' = 'A'.
				*/
				
			}
			
		}
		
		return result;
		
	}
	
	int split (const std::string& input){
		
		int length = input.length();
		int idx = 0; // para iterar sobre a input string
		int numWords = 1; // começo a contar as palavras no 1 assumindo que tem pelo menos 1 palavra
		
		// contar as palavras baseado nos espaços
		while (input[idx] != '\0') {
			
			if (input[idx] == ' ') {
				numWords++;
			}
			
			idx++;
		}
		
		// alocar espaço para ponteiros para cada palavra
		words = new char*[numWords];
		
		wordCount = numWords; // guardar o numero de palavras encontrado
		
		int charIndex = 0; // Character index for the input string
		int wordIndex = 0; // Index for each word
		int letterIndex = 0; // Letter index within each word
		
		// Allocate and fill words
		while (input[charIndex] != '\0' && wordIndex < numWords) {
			
			words[wordIndex] = new char[100]; // Assume each word has a maximum length of 100
			
			letterIndex = 0;
			
			// Copy characters until a space or end of string is reached
			while (input[charIndex] != '\0' && input[charIndex] != ' ') {
				
				words[wordIndex][letterIndex] = input[charIndex];
				letterIndex++;
				charIndex++;
				
			}
			
			words[wordIndex][letterIndex] = '\0'; // Null-terminate the current word
			
			wordIndex++;
			charIndex++; // Move past the space
		}
		
		return numWords; // Return the number of words
		
	}
	
	void cleanSplit () {
		
		for (int i = 0; i < wordCount; i++) {
			delete[] words[i];
		}
		
		delete[] words;
	}
	
};



//>>>>>>>>>> metodo_01 - exercicio 1411 <<<<<<<<<<

void metodo_01 (){
	
	cout << "\nmetodo_01\n";
	
	kelstring* dados = new kelstring;
	
	dados -> str = "574";
	//dados->str = "57a4"; // teste com caractere nao numerico
	
	int result = dados -> stringToInt();
	
	if(result == -1){
		
		cout << "\n\nerro. a string fornecida nao possui apenas digitos" << std::endl;
		
	}else{
		
		cout << "\n\nstring convertida para inteiro: " << result << std::endl;
		
	}
	
	delete dados;
}



//>>>>>>>>>> metodo_02 - exercicio 1412 <<<<<<<<<<

void metodo_02 (){
	
	cout << "\nmetodo_02\n";
	
	kelstring* dados = new kelstring;
	
	//dados -> str = "574";	//teste com inteiro
	//dados -> str = "57a4"; // teste com caractere nao numerico
	dados -> str = "44.098";
	
	double result = dados -> stringToDouble();
	
	if(result == 0.0){
		
		cout << "\n\nerro. a string fornecida nao possui apenas digitos" << std::endl;
		
	}else{
		
		cout << "\n\nstring convertida para valor real: " << result << std::endl;
		
	}
	
	delete dados;
	
}



//>>>>>>>>>> metodo_03 - exercicio 1413 <<<<<<<<<<

void metodo_03 (){
	
	cout << "\nmetodo_03\n";
	
	kelstring* dados = new kelstring;
	
	//dados -> str = "574";	//teste com valor invalido
	//dados->str = "abc"; // teste com valor invalido
	//dados -> str = "true";
	//dados -> str = "T";
	//dados -> str = "1";
	//dados -> str = "false";
	//dados -> str = "F";
	dados -> str = "0";
	
	bool result = dados -> getBoolean();
	
	delete dados;
	
}



//>>>>>>>>>> metodo_04 - exercicio 1414 <<<<<<<<<<

void metodo_04 (){
	
	cout << "\nmetodo_04\n";
	
	kelstring* dados = new kelstring;
	
	dados -> str = "raquel";
	
	//para testar
	std::string t1 = "quel";
	std::string t2 = "raq";
	std::string t3 = "leuq";
	std::string t4 = "raqwxyz";
	
	bool result = dados -> contains(t4);
	
	if (result){
		
		cout << "\n\na substring passada como parametro esta contida na string original" << std::endl;
		
	}else{
		
		cout << "\n\na substring passada como parametro NAO esta contida na string original" << std::endl;
		
	}
	
	delete dados;
	
}



//>>>>>>>>>> metodo_05 - exercicio 1415 <<<<<<<<<<

void metodo_05 (){
	
	cout << "\nmetodo_05\n";
	
	kelstring* dados = new kelstring;
	
	//dados -> str = "574";
	//dados->str = "abc"; 
	//dados -> str = "TRUE";
	dados -> str = "raqUEL!123";

	std::string result = dados -> toUpperCase();
	
	delete dados;
	
}



//>>>>>>>>>> metodo_06 - exercicio 1416 <<<<<<<<<<

void metodo_06 (){
	
	cout << "\nmetodo_06\n";
	
	kelstring* dados = new kelstring;
	
	//dados -> str = "574";
	//dados->str = "abc"; 
	//dados -> str = "TRUE";
	dados -> str = "raqUEL!123";
	
	std::string result = dados -> toLowerCase();
	
	delete dados;
	
}



//>>>>>>>>>> metodo_07 - exercicio 1417 <<<<<<<<<<

void metodo_07 (){
	
	cout << "\nmetodo_07\n";
	
	kelstring* dados = new kelstring;

	dados -> str = "elefante";
	//dados -> str = "raqUEL!123";
	
	std::string result = dados -> replace('e', 'y');
	
	cout << "\n\nstring com substituicao: " << result << std::endl;
	
	delete dados;
	
}



//>>>>>>>>>> metodo_08 - exercicio 1418 <<<<<<<<<<

void metodo_08 (){
	
	cout << "\nmetodo_08\n";
	
	kelstring* dados = new kelstring;
	
	dados -> str = "elefante";
	//dados -> str = "raqUEL!123";
	
	dados -> shift = 10;
	
	std::string result = dados -> cesarEncrypt( );
	
	cout << "\n\nstring codificada: " << result << std::endl;
	
	delete dados;
	
}



//>>>>>>>>>> metodo_09 - exercicio 1419 <<<<<<<<<<

void metodo_09 (){
	
	cout << "\nmetodo_09\n";
	
	kelstring* dados = new kelstring;
	
	dados -> str = "elefante";
	//dados -> str = "raqUEL!123";
	
	dados -> shift = 10;
	
	std::string codificada = dados -> cesarEncrypt( );
	
	cout << "\n\nstring codificada: " << codificada << std::endl;
	
	dados -> str = codificada;
	
	std::string DEcodificada = dados -> cesarDecrypt();
	
	cout << "\n\nstring DEcodificada: " << DEcodificada << std::endl;
	
	delete dados;
	
}



//>>>>>>>>>> metodo_10 - exercicio 1420 <<<<<<<<<<

void metodo_10 (){
	
	cout << "\nmetodo_10\n";
	
	kelstring dados;
	
	std::string input = "Meu nome eh Raquel Motta";
	
	int wordnumber = dados.split(input);
	
	std::cout << "numero de palavras: " << wordnumber << std::endl;
	
	for (int i = 0; i < wordnumber; i++) {
		
		std::cout << dados.words[i] << std::endl;
		
	}
	
	dados.cleanSplit();
	
}



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

int main (){
	
	int opcao = 0;
	
	//identificar o programa
	cout << "estudo dirigido 00\n";
	cout << "autor: raquel de parde motta - matricula: 854017";
	
	do{
		//mostrar as opcoes
		cout << "\n\n--------------------------------------------------------";
		cout << "\n0 - encerrar";
		cout << "\n1 - metodo_01";
		cout << "\n2 - metodo_02";
		cout << "\n3 - metodo_03";
		cout << "\n4 - metodo_04";
		cout << "\n5 - metodo_05";
		cout << "\n6 - metodo_06";
		cout << "\n7 - metodo_07";
		cout << "\n8 - metodo_08";
		cout << "\n9 - metodo_09";
		cout << "\n10 - metodo_10";
		
		
		//ler o valor inputado
		cout << "\n\nescolha o metodo:  ";
		cin >> opcao;
		
		switch (opcao) {
		case 0:
			break;
		case 1:
			metodo_01 ();
			break;
		case 2:
			metodo_02 ();
			break;
		case 3:
			metodo_03 ();
			break;
		case 4:
			metodo_04 ();
			break;
		case 5:
			metodo_05 ();
			break;
		case 6:
			metodo_06 ();
			break;
		case 7:
			metodo_07 ();
			break;
		case 8:
			metodo_08 ();
			break;
		case 9:
			metodo_09 ();
			break;
		case 10:
			metodo_10 ();
			break;
		default:
			cout << "erro. opcao invalida.";
			break;
		}
		
	}while(opcao !=0);
	
	return 0;
}

