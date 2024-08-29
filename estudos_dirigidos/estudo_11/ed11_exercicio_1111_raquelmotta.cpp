/*
PUC MINAS - AEDs1
Mai/2024

Estudo Dirigido 11

Autor: Raquel de Parde Motta
Matricula: 854017

Nome: ed11_exercicio_1111_raquelmotta
Versao: 0.0

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

class RandomNumberGenerator {
private:
	int N; // Quantidade de números a serem gerados
	int lowerLimit; // Limite inferior do intervalo
	int upperLimit; // Limite superior do intervalo
	std::vector<int> numbers; // Vetor para armazenar os números gerados
	
public:
	// Construtor que inicializa a quantidade de números a serem gerados
	RandomNumberGenerator(int n) : N(n) {
		// Semente para o gerador de números aleatórios
		std::srand(std::time(0));
		
		// Definindo os limites inferior e superior do intervalo aleatoriamente
		lowerLimit = std::rand() % 100;
		upperLimit = lowerLimit + (std::rand() % 100) + 1; // Garantindo que o upperLimit seja maior que o lowerLimit
		
		// Gerar os números aleatórios
		generateNumbers();
	}
	
	// Função para gerar N números aleatórios dentro do intervalo [lowerLimit, upperLimit]
	void generateNumbers() {
		for (int i = 0; i < N; ++i) {
			int randomNumber = lowerLimit + std::rand() % (upperLimit - lowerLimit + 1);
			numbers.push_back(randomNumber);
		}
	}
	
	// Função para salvar os números gerados no arquivo "DADOS.TXT"
	void saveToFile(const std::string& filename) {
		
		std::ofstream outFile(filename);
		
		if (outFile.is_open()) {
			outFile << N << std::endl; // Primeira linha: quantidade de números
			for (int number : numbers) {
				outFile << number << std::endl;
			}
			outFile.close();
		} else {
			std::cerr << "nao foi possivel abrir o arquivo" << std::endl;
		}
	}
	
	// Função para imprimir os números gerados (opcional, para verificação)
	void printNumbers() {
		std::cout << "Quantidade de numeros: " << N << std::endl;
		std::cout << "Intervalo: [" << lowerLimit << ", " << upperLimit << "]" << std::endl;
		for (int number : numbers) {
			std::cout << number << std::endl;
		}
	}
};

int main() {
	int N;
	std::cout << "Digite a quantidade de numeros a serem gerados: ";
	std::cin >> N;
	
	// Criando o gerador de números aleatórios
	RandomNumberGenerator rng(N);
	
	// Opcional: imprimir os números gerados no console
	rng.printNumbers();
	
	// Salvando os números no arquivo "DADOS.TXT"
	rng.saveToFile("DADOS.TXT");
	
	return 0;
}



