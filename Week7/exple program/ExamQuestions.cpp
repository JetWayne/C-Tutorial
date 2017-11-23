#include <iostream>

using namespace std;

void readData(char[10][2]);
void printData(char[10][2]);

int main ()
{
    char answers[10][2] = {{' ', 'A'},
                           {' ', 'B'},
                           {' ', 'B'},
                           {' ', 'D'},
                           {' ', 'C'},
                           {' ', 'A'},
                           {' ', 'A'},
                           {' ', 'D'},
                           {' ', 'C'},
                           {' ', 'C'}};

    readData (answers);
    cout << endl;
    printData (answers);

    return 0;
}

void printData (char ans[10][2])
{
    int i=0, grade=0;

    for (i=0;i<10;i++)
    {
        cout << "Question " << i+1 << ": You entered " << ans[i][0];
        cout << ". The correct answer is: " << ans[i][1]<<endl;

        if (ans[i][0]==ans[i][1])
        {
            grade+=10;
            cout << "Good job\n";
        }
        else
            cout << "Better luck next time.\n";
    }
    cout << endl;
    cout << "You scored " << grade << "%.\n";
}

void readData (char ans[10][2])
{
    int i=0;

    for(i=0;i<10;i++)
    {
        cout << "Enter your answer to question "<<i+1<<": ";
        cin>>ans[i][0];
        while (ans[i][0]<'A' || ans[i][0]>'D')
        {
            cout << "\nError! Please re-enter A, B, C, or D...\n\n";
            cout << "Enter your answer to question "<<i+1<<": ";
            cin>>ans[i][0];
        }
    }
}









