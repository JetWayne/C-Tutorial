// Tutorial 6 Question 2
// Calculate the angle between two vectors
#include<iostream>;
using namespace std;
#include<cmath>
#include<iomanip>

// Constant definitions
const int SIZE=10;
const float PI=3.141592;

// Function headers
void input_vector(int[],int);
int dot_prod(int[], int[], int);

int main()
{
    // Variable definitions
    int a[SIZE],b[SIZE];
    int n;
    float cos_theta;
    float angle;

    // Input the value of n 1<=n<=SIZE
    do
    {
        cout<<"Input n: ";
        cin>>n;
    }while(n<=0||n>SIZE);

    // Input vectors a and b
    cout<<"Input vector a"<<endl;
    input_vector(a,n);
    cout<<"Input vector b"<<endl;
    input_vector(b,n);

    // Calculate and output the angle between a and b (degrees)
    cos_theta=dot_prod(a,b,n)/sqrt(dot_prod(a,a,n)*dot_prod(b,b,n));
    angle=180*acos(cos_theta)/PI;
    cout<<"The angle between the two vectors is "<<fixed<<setprecision(2)<<angle<<" degrees";
}

// Input a vector of size m
void input_vector(int vec[],int m)
{
    int i;

    for (i=0;i<m;i++)
    {
        cout<<"Input element "<<i+1<<" : ";
        cin>>vec[i];
    }
}

// Calculate the dot product vec1.vec2
int dot_prod(int vec1[], int vec2[], int m)
{
    int answer=0;
    int i;

    for (i=0; i<m; i++)
    {
        answer+=vec1[i]*vec2[i];
    }

    return answer;
}
