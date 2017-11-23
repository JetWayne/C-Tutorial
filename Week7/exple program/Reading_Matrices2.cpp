#include <iostream>

using namespace std;

void readData (int[2][3]);
void printData (int[2][3]);

int main ()
{
    int matrix[2][3]={0};

    readData(matrix);
    printData(matrix);

    return 0;
}

void printData(int array[2][3])
{
    int i=0,j=0;

    cout << endl << endl;
    cout << "The matrix you entered is: \n";

    for (i=0;i<2;i++)
    {
        for (j=0;j<3;j++)
            cout << "\t" << array[i][j];
        cout << endl;
    }
}

void readData(int array[2][3])
{
    int i=0,j=0;

    cout << "This is the second way to read a matrix: ";
    cout << endl << endl;

    for (i=0; i<2; i++)
    {
        cout << "Enter the elements in row " << i+1;
        cout << " separated by spaces: ";
        for (j=0; j<3; j++)
            cin >> array[i][j];
    }
}
