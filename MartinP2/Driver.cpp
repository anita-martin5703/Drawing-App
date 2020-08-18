// Anita Martin amartin98@cnm.edu
// Project 2: Colorful Drawing App
// Driver.cpp

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main() {
	cout << "\n\t\t\t\tHello welcome to Anita's Colorful Drawing App.\n";
	cout << "\n";
	cout << "\t\tWith your input we will be creating some colorful, pictures for your enjoyment. Let us begin.\n";

	// Declaring variables and constants
	const int BLUE{ 9 };
	const int GREEN{ 10 };
	const int CYAN{ 11 };
	const int RED{ 12 };
	const int PURPLE{ 13 };
	const int QUIT{ 6 };
	char goAgain{ 'y' };
	int picture{ 3 };
	int colorchoice{ 0 };
	int picturechoice{ 0 };

	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

	// Plays loop	
	do {

		while (colorchoice < 1 || colorchoice > 6) {
			cout << "\n\nFirst choose a color to draw:\n\n";
			cout << "Select from the following:" << endl;
			cout << "\t (1) Blue" << endl;
			cout << "\t (2) Green" << endl;
			cout << "\t (3) Cyan" << endl;
			cout << "\t (4) Red" << endl;
			cout << "\t (5) Purple" << endl;
			cout << "\t (6) QUIT\n";
			cout << endl;
			cin >> colorchoice;
			cin.ignore();
			if (colorchoice < 1 || colorchoice > 6)
				cout << "\nThat is not a valid choice, please try again.\n";
			if (colorchoice == 6) {
				cout << "\n\tWe hate to see you go.\n";
			}
		} 

		if (colorchoice != 6) {
			// Selecting a picture
			cout << "\n\nSecondly choose a picture to draw:\n\n";
			while (picturechoice != 1 && picturechoice != 2 && picturechoice != 3) {
				cout << "Select from the following:" << endl;
				cout << "\t (1) for Smiley Face" << endl;
				cout << "\t (2) for a Pyramid" << endl;
				cout << "\t (3) for Diamond" << endl;
				cout << endl;
				cin >> picturechoice;
				if (picturechoice != 1 && picturechoice != 2 && picturechoice != 3) {
					cout << "\n That is not a valid choice, please try again\n";
				}
			}

			int rows{ 20 };
			int columns{ 20 };
			int space{ 0 };
			const int SMILEY_FACE{ 1 };
			const int PYRAMID{ 2 };
			const int DIAMOND{ 3 };

			// selecting the different picture options
			switch (picturechoice) {
			case SMILEY_FACE:
				SetConsoleTextAttribute(screen, colorchoice);
				cout << endl << endl;
				cout << "                 * * * * * * *      " << endl;
				cout << "             *                  *     " << endl;
				cout << "         *                         *    " << endl;
				cout << "      *                               *   " << endl;
				cout << "    *              *         *           *  " << endl;
				cout << "  *               ***       ***            * " << endl;
				cout << " *                 *         *              *" << endl;
				cout << " *                                          *" << endl;
				cout << " *                                          *" << endl;
				cout << " *                 *         *              *" << endl;
				cout << "  *                  *     *              *" << endl;
				cout << "    *                  ***              *" << endl;
				cout << "      *                               * " << endl;
				cout << "         *                         *  " << endl;
				cout << "             *                  *  " << endl;
				cout << "                * * * * * * *      " << endl;

				cout << endl;
				break;
			case PYRAMID:
				SetConsoleTextAttribute(screen, colorchoice);
				cout << endl << endl;
				for (int i = 1; i <= rows; i++) {
					for (space = i; space < rows; space++) {
						cout << " ";
					}
					for (int j = 1; j <= (2 * i - 1); j++) {
						cout << "*";
					}
					cout << endl;
				}
				break;
			case DIAMOND:
				SetConsoleTextAttribute(screen, colorchoice);
				cout << endl << endl;
				for (int i = 1; i <= columns; i++) {
					for (int j = columns; j >= i; j--) {
						cout << " ";
					}
					for (int k = 1; k <= i; k++) {
						cout << "*";
					}
					for (int l = 2; l <= i; l++) {
						cout << "*";
					}
					cout << endl;
				}
				for (int m = columns - 1; m >= 1; m--) {
					cout << "  ";
					for (int n = columns - 1; n > m; n--) {
						cout << " ";
					}
					for (int o = 1; o <= m; o++) {
						cout << "*";
					}
					for (int p = 2; p <= m; p++) {
						cout << "*";
					}
					cout << endl;
				}
				break;
			default:
				break;
			}
			SetConsoleTextAttribute(screen, 7);
			cout << "\n Do you want to draw some more pictures? y/n\n";
			cin >> goAgain;
			colorchoice = picturechoice = 0;
		}
	} while (goAgain == 'y' && colorchoice != 6);

	// Say goodbye
	cout << "\nThank you for drawing with us today, good-bye.\n";

	cout << endl << endl;

	return 0;

}