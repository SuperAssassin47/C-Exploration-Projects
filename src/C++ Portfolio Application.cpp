#include <iostream>
#include <limits>
#include <cstdlib>
#include <fstream>

using namespace std;

void game()
{
	srand(time(nullptr));
	while (true) // beginning of game loop, running whilst TRUE
	{
		enum Choice {rock, paper, scissors}; // the available choices

		Choice player, computer;
		system("cls"); // clear the console every time the player wishes to continue

		// main interface
		cout << "|| == ROCK PAPER SCISSORS GAME == ||\n\n";

		string input;
		cout << "Make your selection (rock/paper/scissors): \n";
		cin >> input;

		//
		if (input == "rock") player = rock;
		else if (input == "paper") player = paper;
		else if (input == "scissors") player = scissors;
		else {
			cout << "Invalid choice. Try again";
			continue;
		}

		computer = static_cast<Choice>(rand() % 3);

		if (player == computer) {
			cout << "Tie!! Better luck next time :|";
		}
		else if ((player == rock && computer == scissors) ||
			(player == paper && computer == rock) ||
			(player == scissors && computer == paper)) {
			cout << "Victory!! You've won :)";
		}
		else {
			cout << "Bah Humbug!! You've lost :(";
		}

		string play_again;
		cout << "\n\nPlay Again? (yes/no): \n";
		cin >> play_again;

		if (play_again == "yes") {
			continue;
		}
		else {
			break;
		}
	}
}

void MainMenu() // main menu initialisation
{
	system("cls"); // clear console window when applicable
	cout << "|| ===== C++ Exploration Project Showcase ===== ||\n";
	cout << "|| =====          Main Menu v1.0.0        ===== ||\n\n";
	cout << "How would like to proceed?: \n";
	cout << "1. Calculate Zodiac Sign\n";
	cout << "2. Calculate Star Sign\n";
	cout << "3. Rock Paper Scissors Game\n";
	cout << "4. Exit\n";
}

void LogSystem(const string& message)
{
	ofstream logger("Zodiac and Star.txt", ios::app);

	if (!logger.is_open())
	{
		cout << "[!] No file exists [!]";
		return;
	}

	logger << message << "\n";
	cout << message << "\n";
}

int main()
{
	int choice = 0;
	int year = 0;
	int month = 0;
	int day = 0;

	/* always put "true" as a loop condition to avoid the compiler assuming that a variable
	* hasn't been initialised when it clearly has */
	while (true) {
		MainMenu();
		cin >> choice;

		if (!cin) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Try again";
			continue;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (choice)
		{
		case 1: {
			system("cls");
			cout << "Enter your year of birth: ";
			cin >> year;

			// perform math
			int math = (year - 1900) % 12;

      // the 12 different zodiac signs (animals)
			string animals[12] = {
				"Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake",
				"Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig"
			};

			LogSystem("Your Zodiac Sign is: " + animals[math]); // output to screen and TXT file
			break;
		}
			case 2:
			{
				system("cls");
				cout << "Enter your birth month (1-12): ";
				cin >> month;
				cout << "Enter your birth day (1-31): ";
				cin >> day;

				string sign; // string variable declaration

				if ((month == 3 && day >= 21) || (month == 4 && day <= 19))
				{
					sign = "Aries";
				}
				else if ((month == 4 && day >= 20) || (month == 5 && day <= 20))
				{
					sign = "Taurus";
				}
				else if ((month == 5 && day >= 21) || (month == 6 && day <= 20))
				{
					sign = "Gemini";
				}
				else if ((month == 6 && day >= 21) || (month == 7 && day <= 22))
				{
					sign = "Cancer";
				}
				else if ((month == 7 && day >= 23) || (month == 8 && day <= 22))
				{
					sign = "Leo";
				}
				else if ((month == 8 && day >= 23) || (month == 9 && day <= 22))
				{
					sign = "Virgo";
				}
				else if ((month == 9 && day >= 23) || (month == 10 && day <= 22))
				{
					sign = "Libra";
				}
				else if ((month == 10 && day >= 23) || (month == 11 && day <= 21))
				{
					sign = "Scorpio";
				}
				else if ((month == 11 && day >= 22) || (month == 12 && day <= 21))
				{
					sign = "Sagittarius";
				}
				else if ((month == 12 && day >= 22) || (month == 1 && day <= 19))
				{
					sign = "Capricorn";
				}
				else if ((month == 1 && day >= 20) || (month == 2 && day <= 18))
				{
					sign = "Aquarius";
				}
				else if ((month == 2 && day >= 19) || (month == 3 && day <= 20))
				{
					sign = "Pisces";
				}
				else
				{
					sign = "Invalid date"; // if an invalid date is detected, output this
				}

				// final message after star sign is calculated
				LogSystem("Your Star Sign is (Western Zodiac Sign): " + sign); // output to screen and TXT file
				break; // exit the switch case
			}
			break;
			case 3:
				game(); // call game() function
				break;
			case 4:
			{
        // asking user if they want to proceed with exiting the app
				string confirm;
				cout << "Hold up!! Are you sure you want to quit (y/n): \n";
				cin >> confirm;

				if (confirm == "y" || confirm == "Y") {
					cout << "Exiting Application..."; // if user answered y or Y, output exit message safely terminate program
					exit(0);
				}
				break;
			}
			default:
				cout << "Invalid option. Try again\n"; // if an invalid option is detected, warn user and re-prompt
				break;
		}
	}
}
