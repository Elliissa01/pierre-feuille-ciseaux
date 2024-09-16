/**************************************/
/*  Project : PIERRE-FEUILLE-CISEAUX  */ 
/*  Author : Elliissa01               */
/*  Date : 2024                       */
/**************************************/

#include <iostream>
#include <string>
using namespace std;

//Functions.
void displayInstruction();

//Global variable.
enum Choix {PIERRE, FEUILLE, CISEAUX};

//Main function.
int main() {
	displayInstruction();
	return 0;
}

//Display instruction to player.
void displayInstruction() {
	cout << "=====================" << endl;
	cout << " Tape 1 pour PIERRE " << endl << " Tape 2 pour FEUILLE " << endl << " Tape 3 pour CISEAUX " << endl;
	cout << "=====================" << endl;
}