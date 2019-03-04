#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

int main()
{
	// Changes the title of the program to NSA Hangman.
	system("title NSA Hangman");
	// Changes the background to black and the font color green.
	system("color 0A");
	// A boolean variable for the while statement so the program can keep running until the user doesn't want to.
	bool playAgain = true;
	// A integer variable for the if else statement to figure out whether the user want's to play again or not.
	int result = 0;
	// Set-up.
	while (playAgain == true)
	{
		const int MAX_WRONG = 8;  // Maximum number of incorrect guesses allowed

		vector<string> words;  // Collection of possible words to guess
		words.push_back("NSA");
		words.push_back("ESPIONAGE");
		words.push_back("UNDERCOVER");
		words.push_back("OPERATION");
		words.push_back("CLASSIFIED");
		words.push_back("HACKER");
		words.push_back("ENCRYPTION");
		words.push_back("MONITOR");
		words.push_back("MALWARE");
		words.push_back("DATA");

		// An srand to put a seed in random generator.
		srand(static_cast<unsigned int>(time(0)));
		random_shuffle(words.begin(), words.end());
		const string THE_WORD = words[0];            // Word to guess.
		int wrong = 0;                               // Number of incorrect guesses.
		string soFar(THE_WORD.size(), '*');          // Word guessed so far.
		string used = "";                            // Letters already guessed.

		// Introduction.
		cout << "Welcome to Hangman Code Breaker, agent. Good luck!\n";
		// NSA ASCII.
		cout << "\t\t\tNNNNNNNN        NNNNNNNN   SSSSSSSSSSSSSSS              AAA               \n\n";
		cout << "\t\t\tN:::::::N       N::::::N SS:::::::::::::::S            A:::A              \n\n";
		cout << "\t\t\tN::::::::N      N::::::NS:::::SSSSSS::::::S           A:::::A             \n\n";
		cout << "\t\t\tN:::::::::N     N::::::NS:::::S     SSSSSSS          A:::::::A            \n\n";
		cout << "\t\t\tN::::::::::N    N::::::NS:::::S                     A:::::::::A           \n\n";
		cout << "\t\t\tN:::::::::::N   N::::::NS:::::S                    A:::::A:::::A          \n\n";
		cout << "\t\t\tN:::::::N::::N  N::::::N S::::SSSS                A:::::A A:::::A         \n\n";
		cout << "\t\t\tN::::::N N::::N N::::::N  SS::::::SSSSS          A:::::A   A:::::A        \n\n";
		cout << "\t\t\tN::::::N  N::::N:::::::N    SSS::::::::SS       A:::::A     A:::::A       \n\n";
		cout << "\t\t\tN::::::N   N:::::::::::N       SSSSSS::::S     A:::::AAAAAAAAA:::::A      \n\n";
		cout << "\t\t\tN::::::N    N::::::::::N            S:::::S   A:::::::::::::::::::::A     \n\n";
		cout << "\t\t\tN::::::N     N:::::::::N            S:::::S  A:::::AAAAAAAAAAAAA:::::A    \n\n";
		cout << "\t\t\tN::::::N      N::::::::NSSSSSSS     S:::::S A:::::A             A:::::A   \n\n";
		cout << "\t\t\tN::::::N       N:::::::NS::::::SSSSSS:::::SA:::::A               A:::::A  \n\n";
		cout << "\t\t\tN::::::N        N::::::NS:::::::::::::::SSA:::::A                 A:::::A \n\n";
		cout << "\t\t\tNNNNNNNN         NNNNNNN SSSSSSSSSSSSSSS AAAAAAA                   AAAAAAA\n\n";

		// Main loop
		while ((wrong < MAX_WRONG) && (soFar != THE_WORD))
		{
			// Informing the uer how many guesses they have left.
			cout << "\n\nYou have " << (MAX_WRONG - wrong);
			cout << " incorrect guesses left.\n";
			// Informing the user which letters they've already picked.
			cout << "\nYou've used the following letters:\n" << used << endl;
			// Informing the user what they have solved so far in the word.
			cout << "\nSo far, the word is:\n" << soFar << endl;

			// Letter variable guess declared.
			char guess;
			// Asking the user to guess a letter.
			cout << "\n\nEnter your guess: ";
			// Collecting the letter guessed by user.
			cin >> guess;
			guess = toupper(guess); // Make uppercase since secret word in uppercase.
			// While loop to figure out and collect what the user guessed. (TELL USER THEY'VE ALREADY PICKED THE SAME LETTER).
			while (used.find(guess) != string::npos)
			{
				// Informing the user they've already guessed that letter.
				cout << "\nYou've already guessed " << guess << endl;
				// Asking the user to guess a letter.
				cout << "Enter your guess: ";
				// Collecting the letter guessed by user.
				cin >> guess;
				// Make uppercase since secret word in uppercase.
				guess = toupper(guess);
			}

			// Used and guess are equal by incrementing.
			used += guess;

			// An if else statement to inform user if they are correct or incorrect.
			if (THE_WORD.find(guess) != string::npos)
			{
				// Informing the user that they guessed correctly.
				cout << "That's right! " << guess << " is in the word.\n";

				// Update soFar to include newly guessed letter
				for (unsigned int i = 0; i < THE_WORD.length(); ++i)
				{
					if (THE_WORD[i] == guess)
					{
						soFar[i] = guess;
					}
				}
			}
			else
			{
				// Informing the user that they guessed incorrectly.
				cout << "Sorry, " << guess << " isn't in the word.\n";
				// Increment the value of wrong once this else statement is executed.
				++wrong;
			}
		}

		// Shut down (FINAL CONCLUSION OF PROGRAM)
		// An if statement to tell user they lost as they have reached the amount of wrong guesses.
		if (wrong == MAX_WRONG)
		{
			// Informing the user they've lost as they've reached the amount of wrong guesses.
			cout << "\nYou've been hanged! Mission Failed You'll get them next time!";
		}
		// An else statement to tell user they won.
		else
		{
			// Informing the user they guessed the word.
			cout << "\nYou guessed it! Congratulations agent!";
			// Showing the user what the word was.
			cout << "\nThe word was " << THE_WORD << endl;
		}
		cout << "Would you like to try the simulation again?" << endl;
		// A cout statement that tell's the user that if they type 1 then the program will run again.
		cout << "1: Yes" << endl;
		// A cout statement that tell's the user that if they type 2 then the program will not run again.
		cout << "2: No" << endl;
		// A cout statement that just point's at the "1: Yes" and "2: No".
		cout << ">";
		// A cin to gather the results on whether the user typed 1 or 2.
		cin >> result;
		// The if else statement that will either make the program loop back or not.
		if (result == 1)
		{
			// The user has typed 1 which mean's the program will run again.
			playAgain = true;
		}
		else if (result == 2)
		{
			// The user has typed 2 which mean's the the program will not run again
			playAgain = false;
		}
		else
		{
			// The user typed something else besides 1 or 2. So the program will still not run again.
			playAgain = false;
		}
	}
	// Prevents the program from just running and not showing the user the console box.
	system("pause");
	// A exit number for the program. If zero is returned at the of the program, then the program ran successfully.
	return 0;
}