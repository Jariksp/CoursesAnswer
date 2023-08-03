#include <iostream>
#include <functional>
#include <array>
#include <random>
#include <map>

enum NVariants {Paper, Stone, Scissors};
enum NRezult {Victory, Lose, Draw};

std::map<NVariants, std::string> conteiner {{Paper, "Paper"}, {Stone, "Stone"}, {Scissors, "Scissors"}};

NVariants ChooseAIVariant() {
	int ChoosedVariant;
	srand(static_cast<unsigned int>(time(nullptr)));
	ChoosedVariant = rand() % 3;
	std::cout << "Your oponent choosed " << conteiner[(NVariants) ChoosedVariant] << "\n"; 
	return  (NVariants) ChoosedVariant; 
}

NVariants ChooseVariant() {
	int Choosen;
	std::cout << "Choose your variant: 0 - Paper; 1 - Stone; 2 - Scissors;\n";
	std::cin >> Choosen;
	return (NVariants)Choosen;
}

std::map <std::pair<NVariants, NVariants>, NRezult > BattleContainer  { { {Paper, Stone}, Lose }, {{Paper, Scissors}, Victory}, {{Paper, Paper}, Draw}, \
																		{ {Stone, Paper}, Victory }, {{Stone, Scissors}, Lose}, {{Stone, Stone}, Draw}, \
																		{ {Scissors, Paper}, Lose }, {{Scissors, Stone}, Victory}, {{Scissors, Scissors}, Draw} };

std::map<NRezult, std::string> Rezult {{Victory, "You Win\n"}, {Lose, "You Lose\n"}, {Draw, "Draw\n"}};

int flag = 1;

void Game() {
	std::pair<NVariants, NVariants> ChoosenConteiner;
	ChoosenConteiner = std::make_pair<NVariants, NVariants>(ChooseAIVariant(), ChooseVariant());
	std::cout << Rezult[BattleContainer[ChoosenConteiner]];
	std::cout << "\nDo you wonna play again: 0 - no; 1 - Yes;\n";
	std::cin >> flag;
}

void Loop();

std::array<std::function<void()>, 2> GameState = {
	[]{},
	[]{ Game(); Loop(); }
};

void Loop() {
	GameState[flag]();
}

int main() {
	Loop();

	return 0;
}