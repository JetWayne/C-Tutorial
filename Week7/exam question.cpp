#include <iostream>

using namespace std;

void readData(char[10][2]);
void printData(char[10][2]);

int main ()
{
    char answers[10][2] = {{' ','A'},
                  {' ','B'},
                  {' ','B'},
                  {' ','D'},
                  {' ','C'},
                  {' ','A'},
                  {' ','A'},
                  {' ','D'},
                  {' ','C'},
                  {' ','C',}};

    readData (answers);
    cout << endl;
    printData(answers);

    return 0;
}

void readData (char ans[10][2])
{
    for (int i=0;i<10;i++)
    {
        cout << "Question " <<i+1 <<" You answered :" ;
        cin >> ans[i][0];

        while (ans[i][0]<'A' || ans[i][0]>'D')
        {
            cout <<"Error!\nEnter A,B,C and D please.\n";
            cout << "please do it a gain.\n\n";
            cout << "Question " <<i+1 <<" You answered " ;
            cin >> ans[i][0];
        }
    }
}

void printData(char ans[10][2])
{
    int i=0,grade=0;
    for (i=0;i<10;i++)
    {
        cout << "Question " <<i+1 <<": You entered :" << ans[i][0] <<endl;
        if (ans[i][0] == ans[i][1])
        {
            grade+=10;
            cout << "GJ\n";
        }
        else
            cout << "GG Good luck~\n";
    }
    cout <<endl;
    cout << "your final grade is " << grade <<"%\n";
}


