/*Programmed by Dewayne

This is the classic 2-person game of Tic-Tac-Toe
*/

#include <iostream>
#include <iomanip>

using namespace std;

void printArray (char [3][3]); //Prints the game board
void decidePlay (char [3][3], int); //Who's turn
bool decideWinner (char [3][3]); //Is there a winner?
void displayWinner (char [3][3],int, int); //Show who wins
void intializeBoard (char [3][3]); //Set up board at the beginning

int main()
{
    char gameBoard [3][3]; //3x3 grid filled with X, O, or *
    int numPlays=1; //Holds how many plays currently
    bool winner = false; //At the start, there is no winner

    intializeBoard (gameBoard); //Set up 3x3 grid
    printArray (gameBoard); //Print the grid
    while (numPlays<=9 && !winner)
    {
        decidePlay(gameBoard, numPlays); //Whose turn is it
        printArray (gameBoard); //Print the grid
        winner = decideWinner (gameBoard); //Is there a winner?
        numPlays++;
    } //Stop when there is a winner or when there have been 9 plays

    if (!winner) //Means there have been 9 plays
        cout <<"\n\nIt's a tie - no one wins!\n";

    return 0;
}

void intializeBoard (char board [3][3])
{
    int i, j;

    //Give each position the value of *
    for (i=0;i<3;i++)
    {
        for (j=0; j<3; j++)
            board[i][j] = '*';
    }
}

bool decideWinner (char board [3][3])
{
    //Check 1st row
    if (board[0][0]==board[0][1] && board[0][0]==board[0][2] && board[0][0]!='*')
    {
        displayWinner(board, 0, 0);
        return true;
    }
    //Check L/R diagonal
    else if (board[0][0]==board[1][1] && board[0][0]==board[2][2] && board[0][0]!='*')
    {
        displayWinner(board, 0, 0);
        return true;
    }
    //Check 1st column
    else if (board[0][0]==board[1][0] && board[0][0]==board[2][0] && board[0][0]!='*')
    {
        displayWinner(board, 0, 0);
        return true;
    }
    //Check 2nd column
    else if (board[0][1]==board[1][1] && board[0][1]==board[2][1] && board[0][1]!='*')
    {
        displayWinner(board, 0, 1);
        return true;
    }
    //Check 3rd column
    else if (board[0][2]==board[1][2] && board[0][2]==board[2][2] && board[0][2]!='*')
    {
        displayWinner(board, 0, 2);
        return true;
    }
    //Check R/L diagonal
    else if (board[0][2]==board[1][1] && board[0][2]==board[2][0] && board[0][2]!='*')
    {
        displayWinner(board, 0, 2);
        return true;
    }
    //Check 2nd row
    else if (board[1][0]==board[1][1] && board[1][0]==board[1][2] && board[1][0]!='*')
    {
        displayWinner(board, 1, 0);
        return true;
    }
    //Check 3rd row
    else if (board[2][0]==board[2][1] && board[2][0]==board[2][2] && board[2][0]!='*')
    {
        displayWinner(board, 2, 0);
        return true;
    }
    else
        return false;
}

void displayWinner (char board[3][3], int row, int col)
{
    cout << "\nCongratulations.....";

    //Who wins
    if (board[row][col] == 'X')
        cout << "Player 1 wins.";
    else
        cout << "Player 2 wins.";
    cout << endl;
    return;
}

void decidePlay (char gameBoard [3][3], int player)
{
    //Whose turn is it?  If numplays is odd, it is X
    //If numPlays is even it is O
    char player1 = 'X';
    char player2 = 'O';
    char piece; //Holds X or O depending on whose turn it is
    int row, col; //Row/Col the player wants to play
    bool goodMove = false; //Assume row,col have been chosen before

    cout << endl;

    do
    {
        //Decide whose turn
        if (player % 2 == 1)
        {
            piece = player1;
            cout << "Player 1, ";
        }
        else
        {
            piece = player2;
            cout << "Player 2, ";
        }

        //Get Input
        cout<<"Enter a position (ex. 1 2 is the middle of the 1st row):  ";
        cin >> row >> col;

        //If the position has not been chosen
        if (gameBoard [row-1][col-1] == '*')
        {
            gameBoard [row-1][col-1] = piece;
            goodMove = true;
        }
    }while (!goodMove); //Continue until user enters a good play

    return;
}

void printArray (char gameBoard[3][3])
{
    int i, j;
    cout << endl;

    //Print board
    for (i=0; i<3; i++)
    {
        //Print 36 spaces to center the board on the screen
        cout << setw(36) << " ";

        //Output each row
        for (j=0; j<3; j++)
        {
            cout << gameBoard[i][j] << " ";
        }
        cout << endl;
    }

    return;
}
