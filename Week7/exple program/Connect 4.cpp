/*
Programmed by Dewayne

This program is the game Connect 4.  This game is a 2-player game
in which each player chooses a column to play their piece.  Each
piece is placed at the lowest available spot in that column.
Player 1 is 'X' and player 2 is 'O'.  The game continues until one
player gets 4 in a row in any direction.  To play connect 4, set the
NUM_ROWS to 6, the NUM_COL to 7, and NUM_IN_A_ROW to 4.

In this program you really only need to test 4 directions:
1.  North or South
2.  East or West
3.  NorthEast or SouthWest
4.  NorthWest or SouthEast

However, I decided to include all 8 directions so that the program
could easily be modified if you wanted to program Othello (which will
need all 8 directions or Wu Zi Qi which is very similar to connect 4.

This particular program is set up so that the board size can be however
many of rows and columns you need.  A typical connect 4 board has 6 rows
and 7 columns but a Wu Zi Qi board typically has 19 rows and 19 columns.

To play Wu Zi Qi, you will need to read in a row as well as a column and
change the program so that it can play anywhere on the board.  As it is
now, it can only be played at the base of the columns.  You will also need
to set NUM_IN_A_ROW to 5, NUM_ROWS to 19, NUM_COL to 19.
*/

#include <iostream>
#include <iomanip>
#include <windows.h>  //Used for the system("cls") to clear screen

using namespace std;

//global variables
const int NUM_ROWS = 6;  //Sets the number of playable rows for the board
const int NUM_COL = 7;   //Sets the number of columns for the board (Do not exceed 26)
const int NUM_IN_A_ROW = 4;  //Sets how many pieces must be in a row to win
const char FILL_CHARACTER = '*';  //Allows you to change the default character
char board[NUM_ROWS+2][NUM_COL];  //2-D array for the board
                                  //Add 2 to rows to account for the first 2 rows which
                                  //are not playable - Only a heading

//Function Prototypes
char choosePlayer(int &);  //Decides who is playing currently
int playerChoice(char);    //Get the players column choice
void changeBoard(int, char);  //changes board to match player choice
bool decideWinner(char);  //Determines if someone wins
void printBoard();        //Display the board on screen
void initializeBoard();   //Set the board at the beginning
bool testNorth (int, int, char);  //Tests the up direction for a winner
bool testSouth (int, int, char);  //Tests the down direction for a winner
bool testEast (int, int, char);  //Tests right for a winner
bool testWest (int, int, char);  //Tests left for a winner
bool testNorthEast (int, int, char);  //Tests up and to the right for a winner
bool testNorthWest (int, int, char); //Tests up and to the left for a winner
bool testSouthEast (int, int, char); //Tests down and to the right for a winner
bool testSouthWest (int, int, char);  //Tests down and to the left for a winner

int main ()
{
    //Variables
    char currentPlayer;  //'X' is player 1 and 'O' is player 2
    int columnChoice, //Holds the users choice
        numPlays; //Holds the number of total choices
    bool winner = false; //True if someone wins
    char playAgain;  //Holds 'y' or 'Y' if the user wants to play again

    do
    {
        numPlays = 0;  //At the beginning of each game numPlays is 0
        initializeBoard();  //Set up board
        system("cls"); //Clear the screen
        printBoard(); //Print on-screen

        do //loop to cycle through until no more plays exist or someone wins
        {
            currentPlayer = choosePlayer(numPlays);  //decide whose turn it is
            columnChoice = playerChoice(currentPlayer); //get user choice
            changeBoard (columnChoice, currentPlayer); //change the board to fit users choice
            system("cls");                             //Clear the screen
            printBoard();                              //print board on-screen
            winner = decideWinner(currentPlayer);      //decide if currentPlayer has won

            if (winner)
            {
                if (currentPlayer == 'X')
                    cout << "\nPlayer 1 wins.\n";
                else
                    cout << "\nPlayer 2 wins.\n";
            }

        } while (!winner && numPlays != NUM_ROWS*NUM_COL);  //test to see if someone won or it's a tie

        if (numPlays == NUM_COL*NUM_ROWS && !winner)  //It's a tie if no one wins and maximum
                                                      //number of plays has been reached
            cout << "\nIt\'s a tie.  No one wins.\n";

        cout << "\nWould you like to play again?  Y or N: "; //Ask user if they want to go again
        cin >> playAgain;
        cout << endl;

    } while (playAgain == 'Y' or playAgain == 'y');  //Repeat program if 'y' or 'Y' is entered

    cout << "Thank you for playing...\n\n";

    return 0;
}

void initializeBoard ()
{
    //Top row - Show numbers 1 through NUM_COL
    for(int i=0; i<NUM_COL; i++)
        board[0][i] = char(48+(i+1)%10);  //Prints only characters '0' to '9'

    //Second row filled with spaces
    for (int i=0; i<NUM_COL; i++)
        board [1][i] = ' ';

    //The playable part of the board - set to * to begin with
    for (int i=2; i<NUM_ROWS+2; i++)
        for (int j=0; j<NUM_COL; j++)
            board[i][j] = FILL_CHARACTER;

    return;
}

void printBoard ()
{
    cout << endl;
    for (int i=0; i<NUM_ROWS+2; i++)
    {
        cout << setw((79-NUM_COL*3)/2) << " ";  //Center board on screen
        for (int j=0; j<NUM_COL; j++)
            cout << board[i][j] << "  ";  //2 spaces between each piece
        cout << endl;
    }

    return;
}

char choosePlayer(int &numPlays)
{
    numPlays++;

    if (numPlays % 2 == 1) //If numPlays is odd it is player 1's turn
        return 'X';
    else
        return 'O';  //Player 2's turn
}

int playerChoice (char player)
{
    char columnChoice[2];  //Players selection
    bool goodPlay; //determines if the players choice is valid
    int column = 0;

    do
    {
        //Let user know who's turn it is
        cout << "\n";
        cout << "Player";
        if (player == 'X')
            cout << " 1";
        else
            cout << " 2";
        cout << ", enter a column (1-"<<NUM_COL<<") you want to play: ";
        cin >> columnChoice;  //Reads as an array of 2 characters to keep from crashing

        if (columnChoice[0] >= '0' and columnChoice[0] <= '9') //valid input for 1st number
        {
            if(columnChoice[1] >= '0' and columnChoice[1] <= '9') //user enters 10-99
                column = (int(columnChoice[0])-48)*10 + (int(columnChoice[1])-48); //change to integer
            else if (columnChoice[1] == '\0') //user enters 0-9 (does not enter a second character")
                column = (int(columnChoice[0])-48);  //change to integer
        }

        //Assume it is a bad play
        goodPlay = false;

        if (column>=1 && column<=NUM_COL)
        {
            for (int i=2; i<NUM_ROWS+2; i++)
            {
                if (board[i][column-1]==FILL_CHARACTER)  //Good play is true if there is a spot open in that column
                    goodPlay = true;
            }
        }

        if (!goodPlay)  //Entered a bad column number or the column is full
        {
            cout << "\nPlease enter another column.  That column is full or ";
            cout << "does not exist.\n";
        }

    } while (!goodPlay);  //Continute until a valid column is entered

    return column;  //Returns users choice
}

void changeBoard (int column, char player)
{
    int i=0;

    while (board[NUM_ROWS+2-i][column-1] != FILL_CHARACTER) //loop to find what piece to change
        i++;

    board[NUM_ROWS+2-i][column-1] = player;  //change board to match players choice

    return;
}

bool decideWinner (char player)
{
    bool win = false;   //Assume no winner

    for (int i=2; i<NUM_ROWS+2; i++) //Start with row 3, since the 1st two rows are headings
    {
        for (int j=0; j<NUM_COL; j++)  //Must test every playable piece
        {
            if (!win)
                win = testNorth(i,j, player);
            if (!win)
                win = testSouth(i, j, player);
            if (!win)
                win = testEast(i, j, player);
            if (!win)
                win = testWest(i, j, player);
            if (!win)
                win = testNorthEast (i, j, player);
            if (!win)
                win = testNorthWest (i, j, player);
            if (!win)
                win = testSouthEast (i, j, player);
            if (!win)
                win = testSouthWest (i, j, player);
        }
    }

    return win; //win is false unless there are NUM_IN_A_ROW in a row
}

bool testNorth (int row, int col, char player)
{
    bool win = false;  //Assume no winner
    int numPieces = 0;  //Holds the number of pieces in a row

    if (row>=NUM_IN_A_ROW+1 && NUM_ROWS>=NUM_IN_A_ROW)
    {
        for (int i=0; i<NUM_IN_A_ROW; i++)  //Test NUM_IN_A_ROW places up
        {
            if (board[row-i][col]==player) //Must equal the current player
                numPieces++;
        }
    }

    if (numPieces == NUM_IN_A_ROW) //If NUM_IN_A_ROW in a row
        win = true;

    return win;
}

bool testSouth (int row, int col, char player)
{
    bool win = false;   //Assume no winner
    int numPieces = 0;  //Holds the number of pieces in a row

    if (row<=NUM_ROWS+2-NUM_IN_A_ROW && NUM_ROWS>=NUM_IN_A_ROW)
    {
        for (int i=0; i<NUM_IN_A_ROW; i++)  //Test NUM_IN_A_ROW places down
        {
            if (board[row+i][col]==player)  //Must equal the current player
                numPieces++;
        }
    }

    if (numPieces == NUM_IN_A_ROW) //If NUM_IN_A_ROW in a row
        win = true;

    return win;
}

bool testEast (int row, int col, char player)
{
    bool win = false;   //Assume no winner
    int numPieces = 0;  //Holds the number of pieces in a row

    if (col<=NUM_COL+1-NUM_IN_A_ROW && NUM_COL>=NUM_IN_A_ROW)
    {
        for (int i=0; i<NUM_IN_A_ROW; i++)  //Test NUM_IN_A_ROW places to the right
        {
            if (board[row][col+i]==player)  //Must equal the current player
                numPieces++;
        }
    }

    if (numPieces == NUM_IN_A_ROW) //If NUM_IN_A_ROW in a row
        win = true;

    return win;
}

bool testWest (int row, int col, char player)
{
    bool win = false;   //Assume no winner
    int numPieces = 0;  //Holds the number of pieces in a row

    if (col>=NUM_IN_A_ROW-1 && NUM_COL>=NUM_IN_A_ROW)
    {
        for (int i=0; i<NUM_IN_A_ROW; i++)  //Test NUM_IN_A_ROW places to the left
        {
            if (board[row][col-i]==player)  //Must equal the current player
                numPieces++;
        }
    }

    if (numPieces == NUM_IN_A_ROW) //If NUM_IN_A_ROW in a row
        win = true;

    return win;
}

bool testNorthWest (int row, int col, char player)
{
    bool win = false;   //Assume no winner
    int numPieces = 0;  //Holds the number of pieces in a row

    if (col>=NUM_IN_A_ROW-1 && row>=NUM_IN_A_ROW+1 && NUM_ROWS>=NUM_IN_A_ROW && NUM_COL>=NUM_IN_A_ROW)
    {
        for (int i=0; i<NUM_IN_A_ROW; i++)  //Test NUM_IN_A_ROW places up and to the left
        {
            if (board[row-i][col-i]==player)  //Must equal the current player
                numPieces++;
        }
    }

    if (numPieces == NUM_IN_A_ROW) //If NUM_IN_A_ROW in a row
        win = true;

    return win;
}

bool testNorthEast (int row, int col, char player)
{
    bool win = false;   //Assume no winner
    int numPieces = 0;  //Holds the number of pieces in a row

    if (col<=NUM_COL+1-NUM_IN_A_ROW && row>=NUM_IN_A_ROW+1 && NUM_ROWS>=NUM_IN_A_ROW && NUM_COL>=NUM_IN_A_ROW)
    {
        for (int i=0; i<NUM_IN_A_ROW; i++)  //Test NUM_IN_A_ROW places up and to the right
        {
            if (board[row-i][col+i]==player)  //Must equal the current player
                numPieces++;
        }
    }

    if (numPieces == NUM_IN_A_ROW) //If NUM_IN_A_ROW in a row
        win = true;

    return win;
}

bool testSouthEast (int row, int col, char player)
{
    bool win = false;   //Assume no winner
    int numPieces = 0;  //Holds the number of pieces in a row

    if (col<=NUM_COL+1-NUM_IN_A_ROW && row<=NUM_ROWS+2-NUM_IN_A_ROW && NUM_ROWS>=NUM_IN_A_ROW && NUM_COL>=NUM_IN_A_ROW)
    {
        for (int i=0; i<NUM_IN_A_ROW; i++)  //Test NUM_IN_A_ROW places down and to the right
        {
            if (board[row+i][col+i]==player)  //Must equal the current player
                numPieces++;
        }
    }

    if (numPieces == NUM_IN_A_ROW) //If NUM_IN_A_ROW in a row
        win = true;

    return win;
}

bool testSouthWest (int row, int col, char player)
{
    bool win = false;   //Assume no winner
    int numPieces = 0;  //Holds the number of pieces in a row

    if (col>=NUM_IN_A_ROW-1 && row<=NUM_ROWS+2-NUM_IN_A_ROW && NUM_ROWS>=NUM_IN_A_ROW && NUM_COL>=NUM_IN_A_ROW)
    {
        for (int i=0; i<NUM_IN_A_ROW; i++)  //Test NUM_IN_A_ROW places down and to the left
        {
            if (board[row+i][col-i]==player)  //Must equal the current player
                numPieces++;
        }
    }

    if (numPieces == NUM_IN_A_ROW) //If NUM_IN_A_ROW in a row
        win = true;

    return win;
}
