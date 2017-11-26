/*************************************************
* Program: Lab 9 - Stack and Queue STL Containers
* Author: Emmet Cooke
* Date: 11/25/2017
* Description: This is the main file from Lab9.
* It holds a menu that allows the user to choose
* which function they would like to use and then
* calls that function.
*************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <ctime>

#include "lab9Functions.hpp"
#include "validateInput.hpp"
#include "Menu.hpp"

int main()
{
	// Generate random numbers
	srand(time(nullptr));

	Menu mainMenu("Please choose an option.", 3);
	mainMenu.setOption(0, "Test the Buffer");
	mainMenu.setOption(1, "Create a Palindrome");
	mainMenu.setOption(2, "Exit");
	bool exitMenu = false;
	string validateInput;
	int menuChoice;

	// Go through the menu until the user chooses to leave
	do
	{
		mainMenu.printPrompt();
		mainMenu.printOptions();
		cout << "Your choice: ";
		getline(cin, validateInput);
		menuChoice = getInt(validateInput);

		switch (menuChoice)
		{
		case 1: // queue
			queueBuffer();
			break;
		case 2: // stack
			stackPalindrome();
			break;
		case 3: // exit
			exitMenu = true;
			break;
		default:
			cout << "Please choose an option between 1 and 3." << endl;
		}
	} while (!exitMenu);
	return 0;
}