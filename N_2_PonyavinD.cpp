#include <iostream>
#include <cmath>

using namespace std;

int main2()
{
    int number = 0; /// number of task
    cout << "Please, enter the number of task ( 1, 2, 3, 4, 5 )" << endl;
    cout << "1. n = 2^x ?" << endl;
    cout << "2. x * 1.1n >= y : n = ?" << endl;
    cout << "3. n = ab..z : a + b + ... + z = ?" << endl;
    cout << "4. 1/0! + 1/1! + ... + 1/n! = ?" << endl;
    cout << "5. Input: current date. Output: tomorrow's date." << endl;
    /// Input
    while (number == 0)
    {
        cin >> number;
        if (number < 1 || number > 5)
        {
            cout << "Incorrect number" << endl;
            number = 0;
        }
    }

    switch (number)
    {
        case 1:
        {
            int n = 0; /// input data
            bool even = true; /// flag
            /// Input
            while (n == 0)
            {
                cout << "n = ";
                cin >> n;
                if (n < 1)
                    n = 0;
            }
            /// Is n power of 2?
            while (n > 1)
            {
                if (n % 2)
                {
                    even = false;
                    break;
                }
                n /= 2;
            }
            /// Output
            if (even)
                cout << n << " is power of 2" << endl;
            else
                cout << n << " isn't power of 2" << endl;
            break;
        }
        case 2:
        {
            double x = 0; /// starting value
            double y = 0; /// finite value
            double n = 1; /// number of day
            /// Input
            while (x == 0)
            {
                cout << "x = ";
                cin >> x;
                if (x <= 0)
                    x = 0;
            }
            while (y == 0)
            {
                cout << "y = ";
                cin >> y;
                if (y <= 0)
                    y = 0;
            }
            /// Processing
            if (x < y)
                n = int(log(y / x) / log(1.1)) + 2;
            cout << "Number of day: " << n << endl;
            break;
        }
        case 3:
        {
            int n = 0; /// input data
            int sum = 0; /// sum of digits of number
            /// Input
            while (n == 0)
            {
                cout << "n = ";
                cin >> n;
                if (n < 1)
                    n = 0;
            }
            /// Processing
            while (n > 0)
            {
                sum += n % 10;
                n /= 10;
            }
            cout << "Sum of digits of number " << n << ": " << sum <<endl;
            break;
        }
        case 4:
        {
            int i = 1; /// counter
            int factorial = 1; /// current value of factorial
            int n = -1; /// input data
            double sum = 1; /// sum of sequence
            /// Input
            while (n == -1)
            {
                cout << "n = ";
                cin >> n;
                if (n < 0 || n > 12)
                    n = -1;
                if (n == -1)
                    cout << "n = [0 , 12]" << endl;
            }
            /// Processing
            while (i <= n)
            {
                sum += 1./factorial;
                i++;
                factorial *= i;
            }
            cout << sum << endl;
            break;
        }
        case 5:
        {
            int day = 0; /// day
            int month = 0; /// month
            int year = 0; /// year
            /// Input
            cout << "Please, enter the date" << endl;
            cin >> day >> month >> year;
            if (year < 1)
            {
                cout << "Incorrect date" << endl;
                return 1;
            }
            /// Check and processing
            switch (month)
            {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    {
                        if (day > 31)
                        {
                            cout << "Incorrect date" << endl;
                            return 1;
                        }
                        else
                        {
                            day++;
                            if (day == 32)
                            {
                                day = 1;
                                month++;
                            }
                        }
                        break;
                    }
                case 4:
                case 6:
                case 9:
                case 11:
                    {
                        if (day > 30)
                        {
                            cout << "Incorrect date" << endl;
                            return 1;
                        }
                        else
                        {
                            day++;
                            if (day == 31)
                            {
                                day = 1;
                                month++;
                            }
                        }
                        break;
                    }
                case 2:
                    {
                        if ((day > 28 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))) || (day > 29 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
                        {
                            cout << "Incorrect date" << endl;
                            return 1;
                        }
                        else
                        {
                            day++;
                            if ((day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))) || (day == 30 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
                            {
                                day = 1;
                                month++;
                            }
                        }
                        break;
                    }
                default:
                {
                    cout << "Incorrect date" << endl;
                    return 1;
                }
            }
            if (month == 13)
            {
                month = 1;
                year += 1;
            }
            /// Output
            if (day < 10)
                cout << "0" << day << ".";
            else
                cout << day << ".";
            if (month < 10)
                cout << "0" << month << ".";
            else
                cout << month << ".";
            cout << year;
            break;
        }
    }
    return 0;
}

