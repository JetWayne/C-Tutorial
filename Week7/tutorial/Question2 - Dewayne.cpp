/* Programmed by Dewayne

This program finds and displays the dot product of two vectors
and the angle between them.

*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Change this value to allow bigger sizes of vectors
const int MAX = 10;

void readVector(int[MAX], int);           //Read vector into array
void printVector(int[MAX], int);          //Output on screen the vector
int dotProduct(int[MAX], int[MAX], int);  //Finds dot Product of 2 vectors
float findAngle(int[MAX], int[MAX], int); //Finds the acute angle between 2 vectors

int main ()
{
    int size=0; //Size of the vector (Must be 0<x<=MAX)
    int vectorA[MAX] = {0};
    int vectorB[MAX] = {0};

    //Loop to validate the size
    do
    {
        cout << "Please enter the size of the vector: ";
        cin >> size;
        if (size<=0)
            cout << "Error. Please enter a positive value.\n";
        if (size>MAX)
            cout << "Error. Maximum size is "<<MAX<<". Please enter again.\n";
    }while (size<0 || size>MAX);

    //Input section
    cout << "\nFor vectorA:\n";
    readVector(vectorA, size);
    cout << "\nFor vectorB:\n";
    readVector(vectorB, size);

    //Output the dotProduct
    cout << endl;
    cout << "The dot product is:\n";
    printVector(vectorA, size);
    cout << ".";
    printVector(vectorB, size);
    cout << " = " << dotProduct(vectorA, vectorB, size);
    cout << endl;

    //Change to 2dp accuracy
    cout << setprecision(2) << fixed;

    //Output the angle between the vectors
    cout << endl;
    cout << "The angle between ";
    printVector(vectorA, size);
    cout << " and ";
    printVector(vectorB, size);
    cout << " is: ";
    cout << findAngle (vectorA, vectorB, size);
    cout << " degrees.\n\n";

    return 0;
}

//Formula is ɵ=cosˉ¹(a.b/√(a.a*b.b))
float findAngle(int array1[MAX], int array2[MAX], int num)
{
    float angle=0, numerator=0, denominator=0;

    numerator = dotProduct(array1, array2, num);
    denominator = dotProduct(array1, array1, num)*dotProduct(array2, array2, num);

    angle = acos(numerator/sqrt(denominator));

    //Change to degrees
    angle *= 180/3.1415926;

    //Find the acute angle only
    if (angle>90)
        return 180-angle;
    else
        return angle;
}


int dotProduct(int array1[MAX], int array2[MAX], int num)
{
    int i=0, sum=0;

    //Finds the dot product
    for (i=0; i<num; i++)
        sum += array1[i]*array2[i];

    return sum;
}

void readVector (int array[MAX], int num)
{
    int i=0;

    //Enter information from the user
    for (i=0; i<num; i++)
    {
        cout << "Enter element " << i+1 << " of the vector: ";
        cin >> array[i];
    }
}

void printVector (int array[], int num)
{
    int i=0;

    cout << "[";
    for (i=0; i<num; i++)
    {
        cout << array[i];
        if (i!=num-1)
            cout << ", ";
    }
    cout << "]";
}
