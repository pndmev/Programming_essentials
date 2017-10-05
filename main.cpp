#include <iostream>

#include "N_1_PonyavinD.cpp"
#include "N_2_PonyavinD.cpp"
#include "N_3_PonyavinD.cpp"
#include "N_4_PonyavinD.cpp"

using namespace std;

int main()
{
    int number;
    cout << "Please, enter the number of laboratory work (1 - 4)" << endl;
    cin >> number;
    while (number < 1 || number > 4)
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
    }
    return 0;
}
