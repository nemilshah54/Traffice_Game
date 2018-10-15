


/* --------------------------------------------------------
* Traffic.cpp
*     Text-based version of the game RushHour, where the
*     object is to move the vehicles such that the small
*     car can exit the right of the board.
*
* System: DEV C++.
* Author: Nemil R Shah
*/

#include <iostream>
#include <cctype>      // for toupper()
using namespace std;

// Global variables and constants
// Variables to store the board pieces

char P1, P2, P3, P4, P5, P6;
char P7, P8, P9, P10, P11, P12;
char P13, P14, P15, P16, P17, P18;
char P19, P20, P21, P22, P23, P24;
char P25, P26, P27, P28, P29, P30;
char P31, P32, P33, P34, P35, P36;

void displayIDInfo();
void displayInstructions();
void displayBoard();
void move(char ch, char dir, int pos);
int getPos(char car, char dir);
void resetBoard();

int main()
{
	P1 = 'G'; P2 = 'G'; P3 = '.'; P4 = '.'; P5 = '.', P6 = 'Y';
	P7 = 'P'; P8 = '.'; P9 = '.'; P10 = 'B'; P11 = '.', P12 = 'Y';
	P13 = 'P'; P14 = 'R'; P15 = 'R'; P16 = 'B'; P17 = '.'; P18 = 'Y';
	P19 = 'P'; P20 = '.'; P21 = '.'; P22 = 'B'; P23 = '.'; P24 = '.';
	P25 = 'O'; P26 = '.'; P27 = '.'; P28 = '.'; P29 = 'T'; P30 = 'T';
	P31 = 'O'; P32 = '.'; P33 = 'F'; P34 = 'F'; P35 = 'F', P36 = '.';

	char car = 'A'; char dir ='B';         // Variables declared for userinput for car, direction and number of moves.
	int noMoves;

	displayIDInfo();        // Display ID info
	displayInstructions();  // Display game instructions
	displayBoard();

	int countMove = 0;                        // To count the number of moves.

	while (P18 != 'R')          // Loop terminates when P18 is red car.
	{

		countMove++;
		cout << countMove << ". ";
		cout << "Your move -> ";

		cin >> car;
		if (car == 'x')                      // Condition to exit the game.
		{

			cout << " Exiting the game";
			return 1;
		}

		if (car == '-')                 // Userinput condition to reset the board.
		{
			cout << " You have chosen to reset the board" << endl;
			cout << "Enter 36 characters for the new board" << endl;

			resetBoard();            // Function called to reset the board and tell user to enter 36 new characters.

			break;
		}
		cin >> dir;
		cin >> noMoves;

		move(toupper(car), toupper(dir), noMoves);       // Function call to make a move.

		displayBoard();          //  Function call to display the board again after making a move.
	}

	if (P18 == 'R')                      // Prompts out win game when P18 is equal to 'R'.
	{
		cout << " Congratulations!! You win the game." << endl;
		cout << " Thank you for playing. Exciting..";
	}

	system("pause");
	return 0;
}
// Display ID Information.
void displayIDInfo()
{
	printf("Author: Nemil R Shah        \n");
	printf(" TRAFFIC GAME \n");
	printf(" \n\n");
} // End displayID info.

  // Display Instructions
void displayInstructions()
{
	cout << "Welcome to the traffic game!                          " << endl
		<< "                                                      " << endl
		<< "Move the vehicles so that the Red car (RR) can exit   " << endl
		<< "the board to the right. Each move should be of the    " << endl
		<< "of the form:   CDN   where:                           " << endl
		<< "   C  is the vehicle to be moved                      " << endl
		<< "   D  is the direction (u=up, d=down, l=left or r=right)" << endl
		<< "   N  is the number of squares to move it             " << endl
		<< "For example GR2  means move the G vehicle to the right" << endl
		<< "2 squares.  Lower-case input such as   gr2  is also   " << endl
		<< "accepted.  Enter '-' to reset board, or 'x' to exit.  " << endl;
}//end displayInstructions()

 // Function to move all poosible cars in board.

void move(char ch, char dir, int distance)
{
	//For CAR G.
	if (ch == 'G' && (dir == 'L' || dir == 'R') && (distance>0))     // Check for car, direction and number of moves that are attempted.
	{

		int posG = getPos('G', dir);       // Function returning the integer value, that indicates in which position the car
										   // green is in board.

		int flag = 0;             // Variable that will help us further to break the loop when move was not valid.

		int x = 0;                 // Useful variable to swap the values in board.

		if (dir == 'R')           // Condition to make right moves.
		{
			x = posG + 1;          // For right car, we will increment x value by 1 to make 1 right move.

			for (int i = 1; i <= distance; i++)         // This loop makes step by step move when the user makes a move which is greater
														//  than or equal to one. For example if the move is gr3, then the loop does the step by step
														// move three times( logically if it is gr3, then it does gr1 three times).
			{

				switch (x)              // All possible cases in switch to make right moves for green car.
				{

				case 3:if (P3 == '.')       // One right move for green car from P1P2 to P2P3.
				{
					P3 = 'G';
					P1 = '.';
					break;
				}
					   else                    // Else means if it is not dot,then it might hit with some car; hence move is invalid.
					   {
						   cout << "*** Move was attempted, but couldn't be completed. ***\n";
						   flag = 1;                // Flag assigned one, that will further help us to make immediate exit.
						   break;
					   }

				case 4:if (P4 == '.')     // One right move for green car from P2P3 to P3P4. All below cases have similar procedures.
				{
					P4 = 'G';
					P2 = '.';
					break;
				}
					   else
					   {
						   cout << "*** Move was attempted, but couldn't be completed. ***\n";
						   flag = 1;
						   break;
					   }

				case 5:if (P5 == '.')
				{
					P5 = 'G';
					P3 = '.';
					break;
				}
					   else
					   {
						   cout << "*** Move was attempted, but couldn't be completed. ***\n";
						   flag = 1;
						   break;
					   }

				case 6:if (P6 == '.')
				{
					P6 = 'G';
					P4 = '.';
					break;
				}
					   else
					   {
						   cout << "*** Move was attempted, but couldn't be completed. ***\n";
						   flag = 1;
						   break;
					   }
				default:
				{
					cout << "*** Move was attempted, but couldn't be completed. ***\n";
					flag = 1;
					break;
				}

				}
				x++;            // Incrementing x in for loop helps to make move further. This is when moves are greater than 1.

				if (flag == 1)         // Immediate exit to the loop when the move was not valid.
					break;
			}

		}

		if (dir == 'L')         // If condition when user did left move for green car.
		{
			x = posG - 1;          // As we are going left, x will be decremented by one value.

			for (int i = 1; i <= distance; i++)
			{
				switch (x)           // Switch case for all possible left moves for green car.
				{

				case 4:if (P4 == '.')         // One left move from P5P6 to P5P4.
				{
					P4 = 'G';
					P6 = '.';
					break;
				}
					   else
					   {
						   cout << "*** Move was attempted, but couldn't be completed. ***\n";
						   flag = 1;
						   break;
					   }

				case 3:if (P3 == '.')       // One left move from P5P4 to P4P3.
				{
					P3 = 'G';
					P5 = '.';
					break;
				}
					   else
					   {
						   cout << "*** Move was attempted, but couldn't be completed. ***\n";
						   flag = 1;
						   break;
					   }

				case 2:if (P2 == '.')
				{
					P2 = 'G';
					P4 = '.';
					break;
				}
					   else
					   {
						   cout << "*** Move was attempted, but couldn't be completed. ***\n";
						   flag = 1;
						   break;
					   }

				case 1:if (P1 == '.')
				{
					P1 = 'G';
					P3 = '.';
					break;
				}
					   else
					   {
						   cout << "*** Move was attempted, but couldn't be completed. ***\n";
						   flag = 1;
						   break;
					   }
				default:
				{
					cout << "*** Move was attempted, but couldn't be completed. ***\n";
					flag = 1;
					break;
				}

				}
				x--;

				if (flag == 1)             // // Immediate exit to the loop when the move was not valid.
					break;
			}
		}
	}

	// For car T. Below all conditions,loops and statements are for other cars. Everything is similar, it's just car is different.

	if (ch == 'T' && (dir == 'L' || dir == 'R') && (distance>0))
	{

		int pos = getPos('T', dir);
		int flag = 0;

		int x = 0;

		if (dir == 'R')
		{
			x = pos + 1;

			for (int i = 1; i <= distance; i++)
			{

				switch (x)
				{
				case 27:if (P27 == '.')
				{
					P27 = 'T';
					P25 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 28:if (P28 == '.')
				{
					P28 = 'T';
					P26 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 29:if (P29 == '.')
				{
					P29 = 'T';
					P27 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 30:if (P30 == '.')
				{
					P30 = 'T';
					P28 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}
				default:
				{
					cout << "*** Move was attempted, but couldn't be completed. ***\n";
					flag = 1;
					break;
				}
				}
				x++;

				if (flag == 1)
					break;
			}
		}

		if (dir == 'L')
		{
			x = pos - 1;

			for (int i = 1; i <= distance; i++)
			{
				switch (x)
				{

				case 25:if (P25 == '.')
				{
					P25 = 'T';
					P27 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 26:if (P26 == '.')
				{
					P26 = 'T';
					P28 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 27:if (P27 == '.')
				{
					P27 = 'T';
					P29 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 28:if (P28 == '.')
				{
					P28 = 'T';
					P30 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}
				default:
				{
					cout << "*** Move was attempted, but couldn't be completed. ***\n";
					flag = 1;
					break;
				}
				}
				x--;

				if (flag == 1)
					break;
			}
		}
	}

	// car F
	if (ch == 'F' && (dir == 'L' || dir == 'R') && (distance>0))
	{
		int pos = getPos('F', dir);
		int flag = 0;
		int x = 0;

		if (dir == 'R')
		{
			x = pos + 1;
			for (int i = 1; i <= distance; i++)
			{
				switch (x)
				{

				case 34:if (P34 == '.')
				{
					P34 = 'F';
					P31 = '.';
					break;
				}
						else
						{
							cout << "move attempted but not successfull\n";
							flag = 1;
							break;
						}

				case 35:if (P35 == '.')
				{
					P35 = 'F';
					P32 = '.';
					break;
				}
						else
						{
							cout << "move attempted but not successfull\n";
							flag = 1;
							break;
						}

				case 36:if (P36 == '.')
				{
					P36 = 'F';
					P33 = '.';
					break;
				}
						else
						{
							cout << "move attempted but not successfull\n";
							flag = 1;
							break;
						}
				default:
				{
					cout << "*** Move was attempted, but couldn't be completed. ***\n";
					flag = 1;
					break;
				}
				}
				x++;

				if (flag == 1)
					break;
			}
		}

		if (dir == 'L')
		{
			x = pos - 1;

			for (int i = 1; i <= distance; i++)
			{
				switch (x)
				{

				case 33:if (P33 == '.')
				{
					P33 = 'F';
					P36 = '.';
					pos--;
					break;
				}
						else
						{
							cout << "move attempted but not successfull\n";
							flag = 1;
							break;
						}

				case 32:if (P32 == '.')
				{
					P32 = 'F';
					P35 = '.';
					break;
				}
						else
						{
							cout << "move attempted but not successfull\n";
							flag = 1;
							break;
						}

				case 31:if (P31 == '.')
				{
					P31 = 'F';
					P34 = '.';
					break;
				}
						else
						{
							cout << "move attempted but not successfull\n";
							flag = 1;
							break;
						}
				default:
				{
					cout << "*** Move was attempted, but couldn't be completed. ***\n";
					flag = 1;
					break;
				}
				}
				x--;

				if (flag == 1)
					break;
			}
		}
	}

	//car R
	if (ch == 'R' && (dir == 'L' || dir == 'R') && (distance>0))
	{
		int pos = getPos('R', dir);
		int flag = 0;
		int x = 0;

		if (dir == 'R')
		{
			x = pos + 1;

			for (int i = 1; i <= distance; i++)
			{
				switch (x)
				{

				case 15:if (P15 == '.')
				{
					P15 = 'R';
					P13 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 16:if (P16 == '.')
				{
					P16 = 'R';
					P14 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 17:if (P17 == '.')
				{
					P17 = 'R';
					P15 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 18:if (P18 == '.')
				{
					P18 = 'R';
					P16 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}
				default:
				{
					cout << "*** Move was attempted, but couldn't be completed. ***\n";
					flag = 1;
					break;
				}
				}
				x++;

				if (flag == 1)
					break;
			}
		}

		if (dir == 'L')
		{
			x = pos - 1;

			for (int i = 1; i <= distance; i++)
			{

				switch (x)
				{

				case 16:if (P16 == '.')
				{
					P16 = 'R';
					P18 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 15:if (P15 == '.')
				{
					P15 = 'R';
					P17 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 14:if (P14 == '.')
				{
					P14 = 'R';
					P16 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 13:if (P13 == '.')
				{
					P13 = 'R';
					P15 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}
				default:
				{
					cout << "*** Move was attempted, but couldn't be completed. ***\n";
					flag = 1;
					break;
				}
				}
				x--;
				if (flag == 1)
					break;
			}
		}
	}

	//Car B
	if (ch == 'B' && (dir == 'U' || dir == 'D') && (distance>0))
	{

		int posB = getPos('B', dir);
		int flag = 0;
		int x = 0;

		if (dir == 'D')
		{
			x = posB + 6;

			for (int i = 1; i <= distance; i++)
			{
				switch (x)
				{

				case 22:if (P22 == '.')
				{
					P22 = 'B';
					P4 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 28:if (P28 == '.')
				{
					P28 = 'B';
					P10 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 34:if (P34 == '.')
				{
					P34 = 'B';
					P16 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}
				default:
				{
					cout << "*** Move was attempted, but couldn't be completed. ***\n";
					flag = 1;
					break;
				}
				}
				x = x + 6;

				if (flag == 1)
					break;
			}

		}

		if (dir == 'U')
		{
			x = posB - 6;
			for (int i = 1; i <= distance; i++)
			{
				switch (x)
				{

				case 16:if (P16 == '.')
				{
					P16 = 'B';
					P34 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 10:if (P10 == '.')
				{
					P10 = 'B';
					P28 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 4:if (P4 == '.')
				{
					P4 = 'B';
					P22 = '.';
					break;
				}
					   else
					   {
						   cout << "*** Move was attempted, but couldn't be completed. ***\n";
						   flag = 1;
						   break;
					   }
				default:
				{
					cout << "*** Move was attempted, but couldn't be completed. ***\n";
					flag = 1;
					break;
				}
				}
				x = x - 6;

				if (flag == 1)
					break;
			}
		}
	}

	// CAR P

	if (ch == 'P' && (dir == 'U' || dir == 'D') && (distance>0))
	{
		int posP = getPos('P', dir);
		int flag = 0;
		int x = 0;

		if (dir == 'D')
		{
			x = posP + 6;
			for (int i = 1; i <= distance; i++)
			{
				switch (x)
				{
				case 19:if (P19 == '.')
				{
					P19 = 'P';
					P1 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 25:if (P25 == '.')
				{
					P25 = 'P';
					P7 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 31:if (P31 == '.')
				{
					P31 = 'P';
					P13 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}
				default:
				{
					cout << "*** Move was attempted, but couldn't be completed. ***\n";
					flag = 1;
					break;
				}
				}
				x = x + 6;

				if (flag == 1)
					break;
			}
		}

		if (dir == 'U')
		{
			x = posP - 6;
			for (int i = 1; i <= distance; i++)
			{
				switch (x)
				{

				case 13:if (P13 == '.')
				{
					P13 = 'P';
					P31 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 7:if (P7 == '.')
				{
					P7 = 'P';
					P25 = '.';
					break;
				}
					   else
					   {
						   cout << "*** Move was attempted, but couldn't be completed. ***\n";
						   flag = 1;
						   break;
					   }

				case 1:if (P1 == '.')
				{
					P1 = 'P';
					P19 = '.';
					break;
				}
					   else
					   {
						   cout << "*** Move was attempted, but couldn't be completed. ***\n";
						   flag = 1;
						   break;
					   }
				default:
				{
					cout << "*** Move was attempted, but couldn't be completed. ***\n";
					flag = 1;
					break;
				}

				}
				x = x - 6;

				if (flag == 1)
					break;
			}
		}
	}

	// CAR O

	if (ch == 'O' && (dir == 'U' || dir == 'D') && (distance>0))
	{
		int posO = getPos('O', dir);
		int flag = 0;
		int x = 0;

		if (dir == 'D')
		{
			x = posO + 6;
			for (int i = 1; i <= distance; i++)
			{
				switch (x)
				{

				case 13:if (P13 == '.')
				{
					P13 = 'O';
					P1 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 19:if (P19 == '.')
				{
					P19 = 'O';
					P7 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 25:if (P25 == '.')
				{
					P25 = 'O';
					P13 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}
				case 31:if (P31 == '.')
				{
					P31 = 'O';
					P19 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}
				default:
				{
					cout << "*** Move was attempted, but couldn't be completed. ***\n";
					flag = 1;
					break;
				}

				}
				x = x + 6;

				if (flag == 1)
					break;
			}

		}

		if (dir == 'U')
		{
			x = posO - 6;

			for (int i = 1; i <= distance; i++)
			{
				switch (x)
				{

				case 19:if (P19 == '.')
				{
					P19 = 'O';
					P31 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 13:if (P13 == '.')
				{
					P13 = 'O';
					P25 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 7:if (P7 == '.')
				{
					P7 = 'O';
					P19 = '.';
					break;
				}
					   else
					   {
						   cout << "*** Move was attempted, but couldn't be completed. ***\n";
						   flag = 1;
						   break;
					   }

				case 1:if (P1 == '.')
				{
					P1 = 'O';
					P13 = '.';
					break;
				}
					   else
					   {
						   cout << "*** Move was attempted, but couldn't be completed. ***\n";
						   flag = 1;
						   break;
					   }
				default:
				{
					cout << "*** Move was attempted, but couldn't be completed. ***\n";
					flag = 1;
					break;
				}
				}
				x = x - 6;
				if (flag == 1)
					break;
			}
		}
	}
	//Car Y

	if (ch == 'Y' && (dir == 'U' || dir == 'D') && (distance>0))
	{
		int posY = getPos('Y', dir);
		int flag = 0;
		int x = 0;

		if (dir == 'D')
		{
			x = posY + 6;
			for (int i = 1; i <= distance; i++)
			{
				switch (x)
				{

				case 24:if (P24 == '.')
				{
					P24 = 'Y';
					P6 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 30:if (P30 == '.')
				{
					P30 = 'Y';
					P12 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 36:if (P36 == '.')
				{
					P36 = 'Y';
					P18 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}
				default:
				{
					cout << "*** Move was attempted, but couldn't be completed. ***\n";
					flag = 1;
					break;
				}
				}
				x = x + 6;

				if (flag == 1)
					break;
			}
		}

		if (dir == 'U')
		{
			x = posY - 6;

			for (int i = 1; i <= distance; i++)
			{
				switch (x)
				{

				case 18:if (P18 == '.')
				{
					P18 = 'Y';
					P36 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 12:if (P12 == '.')
				{
					P12 = 'Y';
					P30 = '.';
					break;
				}
						else
						{
							cout << "*** Move was attempted, but couldn't be completed. ***\n";
							flag = 1;
							break;
						}

				case 6:if (P6 == '.')
				{
					P6 = 'Y';
					P24 = '.';
					break;
				}
					   else
					   {
						   cout << "*** Move was attempted, but couldn't be completed. ***\n";
						   flag = 1;
						   break;
					   }
				default:
				{
					cout << "*** Move was attempted, but couldn't be completed. ***\n";
					flag = 1;
					break;
				}
				}
				x = x - 6;

				if (flag == 1)
					break;
			}
		}
	}

	return;

}

int getPos(char car, char dir)    // Function to get the specific location of car in board. ( 6*6).
{
	int start = 0;            	// Variable declared to locate the starting position of its row or coloumn.
	char move = ' ';            	// Variable helpful to divide all cars into horizontal and vertical cars.
	int pos = 0;              	// Variable to assign position to car.
	int flag = 0;             	// Variable that helps to make immediate exit from the loop.

	switch (car) {             	// Following cases declared to locate the possible starting position of its row or coloumn.

	case 'G': start = 1;    	// For green car the possible starting location will be 1 ( i.e it starts from P1).
		move = 'H';    	// To declare it horizontal car.
		break;

	case 'Y': start = 6;        // Since Y Car is vertical its starting position is 6 in board.
		move = 'V';        // To declare it vertical car. 
		break;
		// Now similar declaration for all cars.
	case 'B': start = 4;
		move = 'V';
		break;

	case 'P': start = 1;
		move = 'V';
		break;

	case 'R': start = 13;
		move = 'H';
		break;

	case 'O': start = 19;
		move = 'V';
		break;

	case 'F': start = 31;
		move = 'H';
		break;

	case 'T': start = 25;
		move = 'H';
		break;

	}

	if (move == 'H')                        // If condition for all horizontal cars.
	{

		for (int i = 1; i<6; i++)               // Loop to check all possible locations of specific car in its entire row or coloumn.  
		{                                  // Note here loop repeats only 5 times, and not 6.

			switch (start)                 // All possible cases of location of cars in its entire row or coloumn. 
			{                             // For green car it is P1 To P5. ( row 1)
										  // P1 to P5 can assign six location to car. For example if P1 is G car, 
										  // then pos is 1 for left and pos is 2 for right. If P5 is G car, then pos is
										  // 5 for left and 6 for right (Basically P1 to P5 has range of 6 possible locations.

										  // CAR G
			case 1:if (P1 == 'G' && dir == 'L')    // If green car is in P1 position and if its left,then position assigned is 1.
			{
				pos = 1;
				flag = 1;                      // Flag assigned one, which later helps to make an immediate exit from the loop.
			}
				   else if (P1 == 'G' && dir == 'R')   // If green car is in P1 position and if its right, then position assigned is 2.
				   {
					   pos = 2;
					   flag = 1;
				   }
				   break;
			case 2:if (P2 == 'G' && dir == 'L')     //If green car is in P2 position and if its left,then position assigned is 2.
			{
				pos = 2;
				flag = 1;
			}
				   else if (P2 == 'G' && dir == 'R')   // If green car is in P2 position and if its left,then position assigned is 3.
				   {
					   pos = 3;
					   flag = 1;
				   }
				   break;

			case 3:if (P3 == 'G' && dir == 'L')
			{
				pos = 3;
				flag = 1;
			}
				   else if (P3 == 'G' && dir == 'R')
				   {
					   pos = 4;
					   flag = 1;
				   }
				   break;

			case 4:if (P4 == 'G' && dir == 'L')
			{
				pos = 4;
				flag = 1;
			}
				   else if (P4 == 'G' && dir == 'R')
				   {
					   pos = 5;
					   flag = 1;
				   }
				   break;

			case 5:if (P5 == 'G' && dir == 'L')             // Last case for green car is P5. If green car is P5 to left, then pos is 5.
			{                                      // If green car is P5 to right then pos is 6.

				pos = 5;
				flag = 1;
			}
				   else if (P5 == 'G' && dir == 'R')
				   {
					   pos = 6;
					   flag = 1;
				   }
				   break;
				   // Similarly assigning positions for all cars in 6*6 board by above procedure.

				   //CAR R
			case 13:if (P13 == 'R' && dir == 'L')
			{
				pos = 13;
				flag = 1;
			}
					else if (P13 == 'R' && dir == 'R')
					{
						pos = 14;
						flag = 1;
					}
					break;
			case 14:if (P14 == 'R' && dir == 'L')
			{
				pos = 14;
				flag = 1;
			}
					else if (P14 == 'R' && dir == 'R')
					{
						pos = 15;
						flag = 1;
					}
					break;

			case 15:if (P15 == 'R' && dir == 'L')
			{
				pos = 15;
				flag = 1;
			}
					else if (P15 == 'R' && dir == 'R')
					{
						pos = 16;
						flag = 1;
					}
					break;

			case 16:if (P16 == 'R' && dir == 'L')
			{
				pos = 16;
				flag = 1;
			}
					else if (P16 == 'R' && dir == 'R')
					{
						pos = 17;
						flag = 1;
					}
					break;

			case 17:if (P17 == 'R' && dir == 'L')
			{
				pos = 17;
				flag = 1;
			}
					else if (P17 == 'R' && dir == 'R')
					{
						pos = 18;
						flag = 1;
					}
					break;

					// CAR T         
			case 25:if (P25 == 'T' && dir == 'L')
			{
				pos = 25;
				flag = 1;
			}
					else if (P25 == 'T' && dir == 'R')
					{
						pos = 26;
						flag = 1;
					}
					break;
			case 26:if (P26 == 'T' && dir == 'L')
			{
				pos = 26;
				flag = 1;
			}
					else if (P26 == 'T' && dir == 'R')
					{
						pos = 27;
						flag = 1;
					}
					break;

			case 28:if (P28 == 'T' && dir == 'L')
			{
				pos = 28;
				flag = 1;
			}
					else if (P28 == 'T' && dir == 'R')
					{
						pos = 29;
						flag = 1;
					}
					break;

			case 27:if (P27 == 'T' && dir == 'L')
			{
				pos = 27;
				flag = 1;
			}
					else if (P27 == 'T' && dir == 'R')
					{
						pos = 28;
						flag = 1;
					}
					break;

			case 29:if (P29 == 'T' && dir == 'L')
			{
				pos = 29;
				flag = 1;
			}
					else if (P29 == 'T' && dir == 'R')
					{
						pos = 30;
						flag = 1;
					}
					break;

					// CAR F   
			case 31:if (P31 == 'F' && dir == 'L')
			{
				pos = 31;
				flag = 1;
			}
					else if (P31 == 'F' && dir == 'R')
					{
						pos = 33;
						flag = 1;
					}
					break;

			case 32:if (P32 == 'F' && dir == 'L')
			{
				pos = 32;
				flag = 1;
			}
					else if (P32 == 'F' && dir == 'R')
					{
						pos = 34;
						flag = 1;
					}
					break;

			case 33:if (P33 == 'F' && dir == 'L')
			{
				pos = 33;
				flag = 1;
			}
					else if (P33 == 'F' && dir == 'R')
					{
						pos = 35;
						flag = 1;
					}
					break;

			case 34:if (P34 == 'F' && dir == 'L')
			{
				pos = 34;
				flag = 1;
			}
					else if (P34 == 'F' && dir == 'R')
					{
						pos = 36;
						flag = 1;
					}
					break;

			case 35:if (P35 == 'F' && dir == 'L')
			{

				pos = 35;
				flag = 1;
			}
					else if (P35 == 'F' && dir == 'R')
					{
						pos = 37;
						flag = 1;
					}
					break;
			}
			start++;                  // Incrementing start will check the next case, and assign location accordingly.   

			if (flag == 1)
				break;
		}
	}
	// In vertical cars, procedure is same to horizontal cars, but here positions assigned will be in coloumns rather than rows.

	if (move == 'V')                          // If condition for all vertical cars.
	{

		for (int i = 1; i<6; i++)
		{

			switch (start)
			{
				// CAR Y
			case 6:if (P6 == 'Y' && dir == 'U')
			{
				pos = 6;
				flag = 1;
			}
				   else if (P6 == 'Y' && dir == 'D')
				   {
					   pos = 18;
					   flag = 1;
				   }
				   break;
			case 12:if (P12 == 'Y' && dir == 'U')
			{
				pos = 12;
				flag = 1;
			}
					else if (P12 == 'Y' && dir == 'D')
					{
						pos = 24;
						flag = 1;
					}
					break;

			case 18:if (P18 == 'Y' && dir == 'U')
			{
				pos = 18;
				flag = 1;
			}
					else if (P18 == 'Y' && dir == 'D')
					{
						pos = 30;
						flag = 1;
					}
					break;

			case 24:if (P24 == 'Y' && dir == 'U')
			{
				pos = 24;
				flag = 1;
			}
					else if (P24 == 'Y' && dir == 'D')
					{
						pos = 36;
						flag = 1;
					}
					break;
					// CAR P     
			case 1:if (P1 == 'P' && dir == 'U')
			{
				pos = 1;
				flag = 1;
			}
				   else if (P1 == 'P' && dir == 'D')
				   {
					   pos = 13;
					   flag = 1;
				   }
				   break;
			case 7:if (P7 == 'P' && dir == 'U')
			{
				pos = 7;
				flag = 1;
			}
				   else if (P7 == 'P' && dir == 'D')
				   {
					   pos = 19;
					   flag = 1;
				   }
				   break;

			case 13:if (P13 == 'P' && dir == 'U')
			{
				pos = 13;
				flag = 1;
			}
					else if (P13 == 'P' && dir == 'D')
					{
						pos = 25;
						flag = 1;
					}
					break;

			case 19:if (P19 == 'P' && dir == 'U')
			{
				pos = 19;
				flag = 1;
			}
					else if (P19 == 'P' && dir == 'D')
					{
						pos = 31;
						flag = 1;
					}

					if (P19 == 'O' && dir == 'U')
					{
						pos = 19;
						flag = 1;
					}
					else if (P19 == 'O' && dir == 'D')
					{
						pos = 25;
						flag = 1;
					}
					break;


					// CAR B
			case 4:if (P4 == 'B' && dir == 'U')
			{
				pos = 4;
				flag = 1;
			}
				   else if (P4 == 'B' && dir == 'D')
				   {
					   pos = 16;
					   flag = 1;
				   }
				   break;
			case 10:if (P10 == 'B' && dir == 'U')
			{
				pos = 10;
				flag = 1;
			}
					else if (P10 == 'B' && dir == 'D')
					{
						pos = 22;
						flag = 1;
					}
					break;

			case 16:if (P16 == 'B' && dir == 'U')
			{
				pos = 16;
				flag = 1;
			}
					else if (P16 == 'B' && dir == 'D')
					{
						pos = 28;
						flag = 1;
					}
					break;

			case 22:if (P22 == 'B' && dir == 'U')
			{
				pos = 22;
				flag = 1;
			}
					else if (P22 == 'B' && dir == 'D')
					{
						pos = 34;
						flag = 1;
					}
					break;

					// FOR CAR 0
			case 25:if (P25 == 'O' && dir == 'U')
			{
				pos = 25;
				flag = 1;
			}
					else if (P25 == 'O' && dir == 'D')
					{
						pos = 31;
						flag = 1;
					}
					break;

			}
			start = start + 6;

			if (flag == 1)
				break;
		}
	}
	return pos;
}
// DisplayBoard
void displayBoard()
{
	cout << "- - - - - - -" << endl;
	cout << "|" << P1 << " " << P2 << " " << P3 << " " << P4 << " " << P5 << " " << P6 << "|" << endl;
	cout << "|" << P7 << " " << P8 << " " << P9 << " " << P10 << " " << P11 << " " << P12 << "|" << endl;
	cout << "|" << P13 << " " << P14 << " " << P15 << " " << P16 << " " << P17 << " " << P18 << endl;
	cout << "|" << P19 << " " << P20 << " " << P21 << " " << P22 << " " << P23 << " " << P24 << "|" << "\n";
	cout << "|" << P25 << " " << P26 << " " << P27 << " " << P28 << " " << P29 << " " << P30 << "|" << "\n";
	cout << "|" << P31 << " " << P32 << " " << P33 << " " << P34 << " " << P35 << " " << P36 << "|" << "\n";
	cout << "- - - - - - -" << endl;
	return;
}
// ResetBoard.
void resetBoard()
{
	cin >> P1; cin >> P2; cin >> P3; cin >> P4; cin >> P5; cin >> P6;
	cin >> P7;  cin >> P8; cin >> P9; cin >> P10; cin >> P11; cin >> P12;
	cin >> P13; cin >> P14; cin >> P15; cin >> P16; cin >> P17; cin >> P18;
	cin >> P19; cin >> P20; cin >> P21; cin >> P22; cin >> P23; cin >> P24;
	cin >> P25; cin >> P26; cin >> P27; cin >> P28;  cin >> P29; cin >> P30;
	cin >> P31; cin >> P32; cin >> P33; cin >> P34; cin >> P35; cin >> P36;

	displayBoard();
	return;
}














