// Tutorial 6 Question 1
// Sort an array of integers into
// ascending numerical order

#include <iostream>
using namespace std;
#include<iomanip>

int main()
{
    // Variable definitions
    const int SIZE=10;
    int array[SIZE];
    int n;
    int i,j;
    int old;

    // Input 1<=n<=size
    do
    {
        cout<<"Input n: ";
        cin>>n;
    }while(n<=0||n>SIZE);

    // Input the n integers
    for (i=0;i<n;i++)
    {
        cout<<"Input number "<<i+1<<" : ";
        cin>>array[i];
    }

    // Output the unsorted array
    for(i=0; i<n;i++)
    {
        cout<<setw(5)<<array[i];
    }
    cout<<endl;

    // Sort the array into ascending order
    for (i=0;i<n-1;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if(array[i]>array[j])
            {
                old=array[i];
                array[i]=array[j];
                array[j]=old;
            }
        }
    }

    // Output the sorted array
    for(i=0; i<n;i++)
    {
        cout<<setw(5)<<array[i];
    }
    return 0;
}
