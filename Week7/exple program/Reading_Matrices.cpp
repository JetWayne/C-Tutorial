#include <iostream>

using namespace std;

int main ()
{
    int matrix[2][3]={0};
    int i=0,j=0;

    //Way #1
    cout << "This is the first way to read a matrix: ";
    cout << endl << endl;

    for (i=0; i<2; i++)
    {
        for (j=0; j<3; j++)
        {
            cout << "Enter element A["<<i+1<<"]["<<j+1<<"]: ";
            cin >> matrix [i][j];
        }
    }

    //Way #2
    cout << "This is the second way to read a matrix: ";
    cout << endl << endl;

    for (i=0; i<2; i++)
    {
        cout << "Enter the elements in row " << i+1;
        cout << " separated by spaces: ";
        for (j=0; j<3; j++)
            cin >> matrix[i][j];
    }



    return 0;
}
