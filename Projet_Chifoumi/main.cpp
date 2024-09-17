/**************************************/
/*  Project : PIERRE-FEUILLE-CISEAUX  */
/*  Author : Elliissa01               */
/*  Date : 2024                       */
/**************************************/

#include <iostream>
#include <string>
#include <limits>
#include<cstdlib>
#include<ctime>

//Global variable.
enum Option { PIERRE, FEUILLE, CISEAUX };

//Functions.
int askNumberGames();
void displayGame(int game, int total);
void displayInstruction();
int askVerifyChoice();
int randomChoice();
std::string displayOption(int choice);
void revealGame(int playerChoice, int computerChoice);
Option translateNumber(int choice);
void checkWinner(int playerChoice, int computerChoice, int& scorePlayer, int& scoreComputer);
void displayScore(int scorePlayer, int scoreComputer);
void displayResult(int scorePlayer, int scoreComputer);

//Main function.
int main() {
	int playerChoice, computerChoice;
	int scorePlayer = 0, scoreComputer = 0;
	int game = askNumberGames();
	
	//Play as many times as wanted.
	for (int i = 0; i < game; i++) {
		displayGame(i, game);
		displayInstruction();
		playerChoice = askVerifyChoice();
		computerChoice = randomChoice();
		revealGame(playerChoice, computerChoice);
		checkWinner(playerChoice, computerChoice, scorePlayer, scoreComputer);
		displayScore(scorePlayer, scoreComputer);
	}

	//See the result.
	displayResult(scorePlayer, scoreComputer);

	return 0;
}

//Ask for the number of games.
int askNumberGames() {
	int number;

	std::cout << " Combien de parties voulez-vous faire ? : ";
	std::cin >> number;

	while (!std::cin.good()) {
		//Ignore the remaining input.
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//Ask again.
		std::cout << " Nombre invalide." << std::endl << std::endl;
		std::cout << " Combien de parties voulez-vous faire ? : ";
		std::cin >> number;
	}

	std::cout << std::endl;
	return number;
}

//Display game.
void displayGame(int game, int total) {
	std::cout << " - Partie " << ++game << " / " << total << " -" << std::endl;
}

//Display instruction to player.
void displayInstruction() {
	std::cout << "======================" << std::endl;
	std::cout << " Tapez 0 pour PIERRE " << std::endl << " Tapez 1 pour FEUILLE " << std::endl << " Tapez 2 pour CISEAUX " << std::endl;
	std::cout << "======================" << std::endl;
}

//Ask choice to player and verify it.
int askVerifyChoice() {
	int choice;
	
	std::cout << std::endl << " CHOIX : ";
	std::cin >> choice;
	std::cout << std::endl;
	
	while (!std::cin.good() || (choice != 0 && choice != 1 && choice != 2)) {
		//Ignore the remaining input.
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//Ask again.
		std::cout << " Choix invalide." << std::endl;
		displayInstruction();
		std::cout << std::endl << " CHOIX : ";
		std::cin >> choice;
		std::cout << std::endl;
	}

	return choice;
}

//Random choice made by the computer.
int randomChoice() {
	std::srand(std::time(NULL));
	int choice = std::rand() % 3;

	return choice;
}

//Display the option as text.
std::string displayOption(int choice) {
	std::string option = "";
	
	switch (choice) {
		case 0:
			option = "PIERRE";
			break;
		case 1:
			option = "FEUILLE";
			break;
		case 2:
			option = "CISEAUX";
			break;
	}

	return option;
}

//Reveal the choices made.
void revealGame(int playerChoice, int computerChoice) {
	std::cout << " VOUS --> |" << displayOption(playerChoice) << "|   VS   |" << displayOption(computerChoice) << "| <-- ORDI" <<  std::endl ;
}

//Translate number in option.
Option translateNumber(int choice) {
	Option option;

	switch (choice) {
	case 0:
		return option = PIERRE;
	case 1:
		return option = FEUILLE;
	case 2:
		return option = CISEAUX;
	}
}

//Check the victory and defeat conditions.
//Change the score.
void checkWinner(int playerChoice, int computerChoice, int &scorePlayer, int &scoreComputer) {
	Option player = translateNumber(playerChoice);
	Option computer = translateNumber(computerChoice);

	if (player == computer) {
		std::cout << " Match nul." << std::endl;
	}
	else if ((player == PIERRE && computer == CISEAUX) || (player == FEUILLE && computer == PIERRE) || (player == CISEAUX && computer == FEUILLE)) {
		std::cout << " Victoire !" << std::endl;
		scorePlayer++;
	}
	else {
		std::cout << " Perdu ..." << std::endl;
		scoreComputer++;
	}
}

//Display the scores.
void displayScore(int scorePlayer, int scoreComputer) {
	std::cout << std::endl;
	std::cout << " Score personnel : " << scorePlayer << std::endl;
	std::cout << " Score ordinateur : " << scoreComputer << std::endl;
	std::cout << std::endl;
	std::cout << "----------------------------------------------";
	std::cout << std::endl << std::endl;
}

//Display the final result.
void displayResult(int scorePlayer, int scoreComputer) {
	if (scorePlayer > scoreComputer) {
		std::cout << " JOUEUR GAGNANT !!! " << std::endl;
	}
	else if (scorePlayer == scoreComputer) {
		std::cout << " MATCH NUL. " << std::endl;
	}
	else {
		std::cout << " JOUEUR PERDANT ... " << std::endl;
	}
}