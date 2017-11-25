#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int SIZE = 3;
void input_Matrix (float [][SIZE]);
void output_Matrix(float [][SIZE]);
void sum_Matrix (float [][SIZE],float [][SIZE]);
void matrix_Product (float [][SIZE],float [][SIZE]);
    float matrixA [SIZE][SIZE]={0};
    float matrixB [SIZE][SIZE]={0};
    float matrixC [SIZE][SIZE]={0};
    float matrixD [SIZE][SIZE]={0};

int main()
{
    input_Matrix (matrixA);
    input_Matrix (matrixB);

    sum_Matrix (matrixA,matrixB);
    cout << "this is the sum of the matrix A and B: \n";
    output_Matrix (matrixC);
    cout << "this is the product of matrix A and B: \n";
    matrix_Product (matrixA,matrixB);
    output_Matrix (matrixD);
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

//output function
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

//sum of matrix A and B
void sum_Matrix (float matrixA[SIZE][SIZE],float matrixB[SIZE][SIZE])
{
    int i,j;
    for (i=0;i<SIZE;i++)
    {
        for (j=0;j<SIZE;j++)
        {
            matrixC[i][j]=matrixA[i][j]+matrixB[i][j];
        }
    }
}

void matrix_Product (float matrixA[SIZE][SIZE],float matrixB[SIZE][SIZE])
{
    int i,j,k;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            for(k=1;k<SIZE;k++)
            {
                matrixD[i][j]=matrixD[i][j]+matrixA[i][k]*matrixB[k][j];
            }
        }
    }
}
