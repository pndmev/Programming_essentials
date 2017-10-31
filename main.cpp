#include <iostream>

#include "Super_functions.cpp"

#include "N_1_PonyavinD.cpp"
#include "N_2_PonyavinD.cpp"
#include "N_3_PonyavinD.cpp"
#include "N_4_PonyavinD.cpp"
#include "N_5_PonyavinD.cpp"
#include "N_6_PonyavinD.cpp"
#include "N_7_PonyavinD.cpp"
#include "N_8_PonyavinD.cpp"

using namespace std;

int main()
{
    int number;
    cout << "Please, enter the number of laboratory work (1 - 8)" << endl;
    cin >> number;
    while (number < 1 || number > 8)
    {
        cout << "Incorrect number" << endl;
        cin >> number;
    }
    switch (number)
    {
        case 1:
        {
            main1();
            break;
        }
        case 2:
        {
            main2();
            break;
        }
        case 3:
        {
            main3();
            break;
        }
        case 4:
        {
            main4();
            break;
        }
        case 5:
        {
            main5();
            break;
        }
        case 6:
        {
            main6();
            break;
        }
        case 7:
        {
            main7();
            break;
        }
        case 8:
        {
            main8();
            break;
        }
    }
    return 0;
}
