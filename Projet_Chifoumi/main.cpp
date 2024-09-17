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
void displayInstruction();
int askVerifyChoice();
int randomChoice();
std::string displayOption(int choice);
void revealGame(int playerChoice, int computerChoice);
Option translateNumber(int choice);

//Main function.
int main() {
	int playerChoice, computerChoice;

	displayInstruction();
	playerChoice = askVerifyChoice();
	computerChoice = randomChoice();
	revealGame(playerChoice, computerChoice);

	return 0;
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