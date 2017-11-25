#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//function declear;
const int SIZE = 2;
void input_Matrix (float [][SIZE]);
void inverse_Matrix(float [][SIZE]);
void transpose_Matrix(float [][SIZE]);
void output_Matrix(float [][SIZE]);
    float matrixA [SIZE][SIZE]={0};
    float matrixI [SIZE][SIZE]={0};

int main()
{
    //declear the array to use;
    //float matrixA [SIZE][SIZE]={0};
    //float matrixI [SIZE][SIZE]={0};
    //call the fuction to input matrix
    input_Matrix(matrixA);
    cout << "The matrix A : \n";
    output_Matrix(matrixA);

    inverse_Matrix(matrixA);
    cout << "The inverse of matrix I : \n";
    output_Matrix(matrixI);

    cout << "The transpose of matrix A :\n";
    transpose_Matrix(matrixA);
    output_Matrix(matrixA);
}
//input matrix function
void input_Matrix (float matrixA[SIZE][SIZE])
{
    int i,j;
    //loop to input the matrix element 1 by 1
    for (i=0; i<SIZE; i++)
    {
        cout << "Enter the elements in row " << i+1;
        cout << " separated by spaces: ";
        for (j=0; j<SIZE; j++)
            cin >> matrixA [i][j];
    }
}
//function to inverse
void inverse_Matrix(float matrixA[SIZE][SIZE])
{
    //variable would be used in this scope
    int det,temp,i,j;
    //calculate the determinant
    det = matrixA[0][0]*matrixA[1][1] - matrixA[0][1]*matrixA[1][0];
    //juge the determinant is it exist
    if (det==0)
        cout << "inverse matrix does not exist.\n";
    else
    {
        matrixI [0][0] = matrixA [1][1]/det;
        matrixI [1][1] = matrixA [0][0]/det;
        matrixI [0][1] = -matrixA[0][1]/det;
        matrixI [1][0] = -matrixA[1][0]/det;
    }
}
//function to transpose matrix
void transpose_Matrix(float matrixA[2][2])
{
    //use temp to store the value that switched temporaray.
    int temp;
    temp = matrixA[0][1];
    matrixA[0][1] = matrixA[1][0];
    matrixA[1][0] = temp;
}

void output_Matrix (float matrix[SIZE][SIZE])
{
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        for (j=0;j<SIZE;j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout <<endl;
    }
}
