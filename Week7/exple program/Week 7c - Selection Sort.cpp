#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 100000; //Num Elements to be sorted
const int MAX = 10000; //All elements are 1<=x<=MAX
int quickSortSwaps = 0;

void selectionSort (int [], int);
void bubbleSort (int [], int);
void quickSort (int [], int, int);

int main ()
{
    int array1[SIZE]; //Bubble Sort Array
    int array2[SIZE]; //Selection Sort Array
    int array3[SIZE]; //Quick Sort Array

    //Create a random number
    srand (time(0));
    rand();

    //Random number is 20 sf accuracy
    cout << setprecision(20);

    //Fill first array with random numbers
    for (int i=0; i<SIZE; i++)
        array1[i] = 1+rand()/32767.0*MAX;

    //Get an exact copy of the first array
    for (int i=0; i<SIZE; i++)
        array2[i] = array1[i];

    //Get an exact copy of the first array
    for (int i=0; i<SIZE; i++)
        array3[i] = array1[i];

    //Sort array using bubble sort
    bubbleSort (array1, SIZE);

    //Sort array using selection sort
    selectionSort (array2, SIZE);

    //Sort array using Quick sort
    quickSort (array3, 0, SIZE-1);
    cout << "Quick Sort =     " << quickSortSwaps << " total swaps."<< endl;

    //for (int i=0; i<SIZE; i++)
      //  cout << array1[i] << "\t" << array2[i] << "\t" << array3[i] << endl;
    return 0;
}

void selectionSort (int array[], int numElements)
{
    int temp;
    double numSwaps = 0;

    for (int i=0; i<numElements-1; i++)
    {
        for (int j=i+1; j<numElements; j++)
        {
            if (array[j] < array[i])
            {
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
                numSwaps++;
            }
        }
    }

    cout << "Selection Sort = " << numSwaps << " total swaps."<< endl;
    return;
}

void bubbleSort (int array[], int numElements)
{
    bool swap;
    int temp;
    double numSwaps = 0;

    do
    {
        swap = false;
        for (int i=0; i<numElements - 1; i++)
        {
            if (array[i] > array[i+1])
            {
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                swap = true;
                numSwaps++;
            }
        }
    } while (swap);

    cout << "Bubble Sort =    " << numSwaps << " total swaps."<< endl;
    return;
}

void quickSort(int array[], int left, int right)
{
      int i = left, j = right;
      int tmp;
      int pivot = array[(left + right) / 2];

      /* partition */
      while (i <= j)
      {
            while (array[i] < pivot)
                  i++;
            while (array[j] > pivot)
                  j--;
            if (i <= j)
            {
                  tmp = array[i];
                  array[i] = array[j];
                  array[j] = tmp;
                  quickSortSwaps++;
                  i++;
                  j--;
            }
      }

      /* recursion */
      if (left < j)
            quickSort(array, left, j);
      if (i < right)
            quickSort(array, i, right);
}
