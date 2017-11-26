/*************************************************
* Author: Emmet Cooke
* Date: 11/25/2017
* Description: This file contains the definitions
* for the functions declared in the lab9Functions
* header file. There are two files that go through
* a queue and output details pertaining to user input
* data and another function that turns an input string
* into a palindrome.
*************************************************/
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setprecision;
using std::fixed;

#include <string>
using std::string;

#include <stack>
using std::stack;

#include <queue>
using std::queue;

#include "validateInput.hpp"
#include "lab9Functions.hpp"

/*************************************************
* Description: This function asks the user for
* a number of rounds and the chance to add and remove
* numbers from the queue. Once it has this data,
* it runs through the given number of rounds with
* a random chance of adding and removing a random
* number.
*************************************************/
void queueBuffer()
{
	string validateInput;

	// Get the number of rounds
	int rounds;
	do
	{
		cout << "How many rounds are there? ";
		getline(cin, validateInput);
		rounds = getInt(validateInput);
		if (rounds < 0)
		{
			cout << "Please enter a positive int." << endl;
		}
	} while (rounds < 0);

	// Get the percentage chance to put a randomly
	// generated number at the end of the buffer
	int putRandom;
	do
	{
		cout << "Please enter the percentage change for a random number to\n";
		cout << "be put at the end of the buffer as a whole int: ";
		getline(cin, validateInput);
		putRandom = getInt(validateInput);
		if (putRandom < 0 || putRandom > 100)
		{
			cout << "Please enter a whole int between 0 and 100." << endl;
		} 
	}while (putRandom < 0 || putRandom > 100);

	// Get the percentage chance to take out a randomly
	// generated number at the front of the buffer
	int takeRandom;
	do
	{
		cout << "Please enter the percentage change for a random number to\n";
		cout << "be taken out at the front of the buffer as a whole int: ";
		getline(cin, validateInput);
		takeRandom = getInt(validateInput);
		if (takeRandom < 0 || takeRandom > 100)
		{
			cout << "Please enter a whole int between 0 and 100." << endl;
		}
	} while (takeRandom < 0 || takeRandom > 100);

	int N,
		appendingNumber,
		removingNumber;
	double averageLength;
	queue<int> iQueue;

	// Loop through the desired number of rounds
	for (int i = 0; i < rounds; i++)
	{
		cout << "Round " << i + 1 << endl;
		cout << "------------" << endl;
		N = rand() % 1000 + 1;	// Random number to be placed into queue

		// Add a number to the back of the queue
		// Outputs message to easily tell which happened
		appendingNumber = rand() % 100 + 1;
		if (appendingNumber <= putRandom)
		{
			cout << "Appending number..." << endl;
			iQueue.push(N);
		}
		else
		{
			cout << "Did not add number to queue" << endl;
		}

		// Removes a number from the front of the queue
		// Outputs message to easily tell which happened
		removingNumber = rand() % 100 + 1;
		if (removingNumber <= takeRandom
			&& !iQueue.empty())
		{
			cout << "Removing number at front..." << endl;
			iQueue.front();
			iQueue.pop();
		}
		else
		{
			cout << "Did not remove a number from the queue" << endl;
		}

		// Prints the queue without affecting it
		printIntQueue(iQueue);

		// Output the length
		cout << "Queue Length: " << iQueue.size() << endl;
		
		// Outputs the average length
		cout << "Average Length: ";
		cout << fixed << setprecision(2);
		if (i > 0)
		{
			averageLength = (averageLength * ((i + 1) - 1) + iQueue.size()) / (i + 1);
			cout << averageLength;
		}
		else	// First round is equal to the first size
		{
			averageLength = iQueue.size();
			cout << averageLength;
		}
		cout << endl << endl;
	}
}

/*************************************************
* Description: This function takes in an int queue
* and then goes through it and prints the values.
* Because a copy is created when it is passed to
* the function, the original queue is unchanged.
*************************************************/
void printIntQueue(queue<int> queueIn)
{
	cout << "Your queue: ";
	while (!queueIn.empty())
	{
		cout << queueIn.front() << " ";
		queueIn.pop();
	}
	cout << endl;
}

/*************************************************
* Description: This function asks the user for 
* a string to be turned into a palindrome. The input
* string is pushed onto the stack by character and
* then those characters are printed in reverse order
* after the initial string.
*************************************************/
void stackPalindrome()
{
	string userInput;
	cout << "Please enter a string to be turned into a palindrome." << endl;
	cout << "Your string: ";
	getline(cin, userInput);	// Get the string from the user

	stack<char> palindromeString;	// Stack for the characters

	// Put the string characters onto the stack
	for (char c : userInput)
	{
		palindromeString.push(c);
	}

	// Output the palindrome
	cout << "Your palindrome: " << userInput;
	while (!palindromeString.empty())
	{
		cout << palindromeString.top();
		palindromeString.pop();
	}
	cout << endl << endl;
}