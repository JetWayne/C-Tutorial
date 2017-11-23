#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string month[12] = {"January",
                         "February",
                         "March",
                         "April",
                         "May",
                         "June",
                         "July",
                         "August",
                         "September",
                         "October",
                         "November",
                         "December"};

    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    cout << setw(10) << "month" << setw(10) << "days" <<endl;

    int i;

    for (i=0;i<12;i++)
        cout << setw(10) <<month[i] <<setw(10) << days[i] <<endl;

    return 0;

}
