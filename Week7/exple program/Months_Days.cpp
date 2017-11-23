#include <iostream>

using namespace std;

void printInfo (string[12], int[12]);

int main ()
{
    string months[12] = {"January",
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

    printInfo(months,days);

    return 0;
}

void printInfo(string months[12], int days[12])
{
    int i=0;

    for (i=0; i<12; i++)
        cout << months[i] << " has " << days[i] << " days.\n";

}
