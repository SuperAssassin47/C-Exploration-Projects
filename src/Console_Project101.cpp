// FIRST OUTING WITH C++ AFTER A FEW YEARS.

// list of included internal and external libraries
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <limits>

void MainMenu(const std::string& name)
{
	// initialising the main menu interface
	system("cls");
	std::cout << "Welcome, " << name << " to the C++ Application.\n";
	std::cout << "How should you proceed?: \n";
	std::cout << "1. Do some math\n";
	std::cout << "2. String concatenation\n";
	std::cout << "3. Option 3\n";
	std::cout << "4. Option 4\n";
	std::cout << "5. Exit\n";
}

int main()
{
	std::ofstream log("logs.txt", std::ios::app); // append new logs to log file

	// display error message if no TXT file is detected
	if (!log)
	{
		std::cout << "[!] Failed to open log dump [!]";
		return 1;
	}

	// confirming the user identity
	std::cout << "Enter your name: ";
	std::string name;
	std::cin >> name;

	//variable declaration and initialisation
	int choice = 0;

	int num1 = 0;
	int num2 = 0;

	std::string word1; // declaring a variable and telling it to store strings, not singular characters
	std::string word2; // declaring a variable and telling it to store strings, not singular characters

	while (choice != 5)
	{
		MainMenu(name);
		std::cin >> choice;
		
		// clears the newline from the input buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		switch (choice)
		{
			case 1:
				system("cls"); // clear the console
				std::cout << "Enter a number: ";
				std::cin >> num1;

				std::cout << "Enter a second number: ";
				std::cin >> num2;

				log << "Your answer is: " << num1 * num2; // log to TXT file

				std::cout << "Log Written\n"; // confirmation message
				break; // BREAK to prevent accidental fall-throughs
			case 2:
				system("cls");
				std::cout << "Enter a word: ";
				std::cin >> word1;

				std::cout << "Enter another word: ";
				std::cin >> word2;

				log << word1 << " " << word2 << "\n";

				std::cout << "Log Written\n";
				break;
			case 3:
				system("cls");
				log << "You have selected Option 3\n";

				std::cout << "Log Written\n";
				break;
			case 4:
				system("cls");
				log << "You have selected Option 4\n";
				
				std::cout << "Log Written\n";
				break;
			case 5:
				system("cls");
				log << "Exiting Application";
				
				std::cout << "Log Written\n";
				break;
			default: // switches always need default case statement if all others return FALSE
				log << "Invalid Option. Terminating Application\n";
				break;
		}
	}
	return 0; // tell the compiler that this is the END of the main() function
}

// END OF FILE
