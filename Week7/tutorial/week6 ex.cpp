#include <iostream>
using namespace std;

void getInf (int &, double &, char &);
void prinInf (int,double,char);

int main ()
{
    int num1;
    double price;
    char letter;
    getInf (num1, price, letter);
    prinInf (num1, price, letter);
    return 0;
}

void getInf (int &value, double &cost, char &character)
{
    cin >> value;
    cin >> cost;
    cin >> character;
}

void prinInf (int value, double cost,char character)
{
    cout << value <<endl;
    cout << cost <<endl;
    cout << character ;
}
