// Tutorial 6 Question 4
// Calculate the average numbers in the range 0-100
// Input stops when input is outside this range

#include<iostream>;
using namespace std;
#include<iomanip>

// Constant definitions
const int SIZE=10;

// Function prototypes
void input_vector(int[]);
void calculate_average(int[], int&, float&);

int main()
{
    // Variable definitions
    int a[SIZE];
    int n=0;
    float average=0;

    // Input max SIZE numbers in the range 0-110
    input_vector(a);

    // Calculate the average
    calculate_average(a,n,average);

    // Output
    cout<<"The average of the "<<n<<" numbers is "<<average;
}

// Input numbers function header file
void input_vector(int vec[])
{
    int score;
    int n=0;

    cout<<"Input: "<<endl;
    do{
        cout<<"Score "<<n+1<<": ";
        cin>>vec[n];
        n++;
    }while (vec[n-1]>=0 && vec[n-1]<=100 && n<SIZE);
}

// Calculate average function header file
void calculate_average(int vec[], int &n, float &xbar)
{
    do{
        xbar+=vec[n];
        n++;
    }while(vec[n]>=0 && vec[n]<=100);

    xbar/=n;
}
