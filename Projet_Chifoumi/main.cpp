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

//Functions.
void displayInstruction();
int askVerifyChoice();
int randomChoice();

//Global variable.
enum Choix {PIERRE, FEUILLE, CISEAUX};

//Main function.
int main() {
	int playerChoice, computerChoice;

	displayInstruction();
	playerChoice = askVerifyChoice();
	computerChoice = randomChoice();

	return 0;
}

//Display instruction to player.
void displayInstruction() {
	std::cout << "=====================" << std::endl;
	std::cout << " Tape 0 pour PIERRE " << std::endl << " Tape 1 pour FEUILLE " << std::endl << " Tape 2 pour CISEAUX " << std::endl;
	std::cout << "=====================" << std::endl;
}

//Ask choice to player and verify it.
int askVerifyChoice() {
	int choice;
	
	std::cout << std::endl << "--> CHOIX : ";
	std::cin >> choice;
	
	while (!std::cin.good() || (choice != 0 && choice != 1 && choice != 2)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Ignore the remaining input.
		std::cout << std::endl << "--> CHOIX : ";
		std::cin >> choice;
	}

	return choice;
}

//Random choice made by the computer.
int randomChoice() {
	std::srand(std::time(NULL));
	int choice = std::rand() % 3;

	return choice;
}