/*Programmed by Dewayne

This program inputs a string of numbers, then outputs the numbers
in big numbers with dimensions 5x5
*/

#include <iostream>
#include <string>
using namespace std;

int main ()
{     //Double array of every digit 0 to 9
      //Each digit is 5x5
        string bigNumber[10][5]= {{"00000",
                                   "0   0",
                                   "0   0",
                                   "0   0",
                                   "00000"},

                                   {"  1  ",
                                    " 11  ",
                                    "  1  ",
                                    "  1  ",
                                    "11111"},

                                   {"22222",
                                    "    2",
                                    "22222",
                                    "2    ",
                                    "22222"},

                                   {"33333",
                                    "    3",
                                    "  333",
                                    "    3",
                                    "33333"},

                                   {"4   4",
                                    "4   4",
                                    "44444",
                                    "    4",
                                    "    4"},

                                   {"55555",
                                    "5    ",
                                    "55555",
                                    "    5",
                                    "55555"},

                                   {"66666",
                                    "6    ",
                                    "66666",
                                    "6   6",
                                    "66666"},

                                   {"77777",
                                    "   7 ",
                                    "  7  ",
                                    "  7  ",
                                    "  7  "},

                                   {"88888",
                                    "8   8",
                                    "88888",
                                    "8   8",
                                    "88888"},

                                   {"99999",
                                    "9   9",
                                    "99999",
                                    "    9",
                                    "99999"}};

        string number; //Holds the number entered by the user
        int length, //Finds the number of values the user enters
            digit, //Each digit entered by the user - stored in number[i]
            row, //Current row of 5 (since the height is 5 for each big number
            currentNum; //Finds the current number being printed (what is digit)

        //Input
        cout << "Enter your mobile number: ";
        cin >> number;
        cout << "\n\n";

        /*
        Number is a string because I need to be able to look at each digit
        individually.  It is very hard to do this if I store it in an integer.
        Plus, this way I can store a lot of digits without worrying if it
        becomes beyond the range of what an int can hold.
        */

        //Calculates how many digits the user entered
        //We have not learned this function yet but it finds the length
        //of the string entered so I can know how many digits to print
        length = number.length();

        for (row=0; row<5; row++)
        {
            for (digit=0; digit<length; digit++)
            {
                //Change from char '0' to int 0 for example
                //ASCII code for '0' is 48
                //0<=currentNum<=9
                currentNum = (int)(number[digit])-48 ;

                //Print each row of 5 for each big number
                cout<<bigNumber[currentNum][row]<< " ";
            }
            cout << endl; //Go to the next row to be printed
        }

        cout << "\n\n";

        return 0;
}
