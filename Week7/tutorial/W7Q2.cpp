#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//const SIZE to fit any other use and other function prototype
const int SIZE=10;
void input(int[],int,char);
int dot_Product (int[],int[],int);
float absolute (int[],int[],int);

int main()
{
    //variables
    int i,n,a[SIZE]={0},b[SIZE]={0},sum;
    double vec_angle,abs;

    //filter for n 1-10
    do
    {
        cout << "input n(1-10): ";
        cin >> n;
    }while (n<1 || n>SIZE);
    //call input function
    input (a,n,'a');
    input (b,n,'b');

    //ust function:dot_product to calculate the result
    sum = dot_Product (a,b,n);
    abs = absolute (a,b,n);


    //question here!!!!
    // (1,1) and (-1,-1)
    //sum / abs = -1;
    //why acos (sum/abs) is not a number
    vec_angle = (acos(sum/abs)*360)/(2*3.1415);
    cout <<"the dot product is :"<< sum;
    cout << endl;
    cout <<"the angle between two vector is :"<<setprecision(4) << vec_angle <<endl;
    cout << "sum/abs = " << sum/abs;
    cout <<"\nacos" << acos(-1);


}
//input function
void input (int vec[SIZE],int m,char letter)
{
    int i;
    cout << "Input vector"<< letter<<": "<<endl;

    for (i=0;i<m;i++)
    {
        cout << "vector" <<i+1 <<": ";
        cin >> vec[i];
    }
    cout << endl;
}
//dot product calculation function
int dot_Product (int a[],int b[],int m)
{
    int i,sum=0;
    for (i=0;i<m;i++)
    {
        sum = sum + a[i]*b[i];
    }
    return sum;
}
//calculation for |a| and |b|;
float absolute (int a[],int b[],int m)
{
    int i;
    float abs_a=0,abs_b=0;
    float abs;
    for (i=0;i<m;i++)
    {
        abs_a = pow(a[i],2) + abs_a;
        abs_b = pow(b[i],2) + abs_b;
    }
    abs = sqrt(abs_a)*sqrt(abs_b);
    return abs;
}
