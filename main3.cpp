#include <iostream>
#include <cmath>

using namespace std;

/// Sum of dividers of number
int decomposition (int x)
{
    int i; /// counter
    int sum = 1; /// sum of dividers
    int sqrtX = sqrt(x); /// square root of x
    /// Search of dividers and calculation
    for (i = 2; i <= sqrtX; i++)
        if (x % i == 0)
            sum += i + x/i;
    return sum;
}
/// Definition of the greatest common divisor
int gcd (int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd (b, a % b);
}
/// Number of various digits
int function_1 (int N)
{
    int number = 0; /// number of various digits
    bool digits[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; /// array of flags
    /// Processing
    while (N > 0)
    {
        if (!digits[N % 10])
        {
            digits[N % 10] = true;
            number++;
        }
        N /= 10;
    }
    return number;
}
/// Search of automorphic numbers
void function_2 (int N)
{
    int i; /// counter
    int i2; /// counter^2
    int coefficient; /// coefficient of power
    int  sum; /// sum
    /// 0 - automorphic number, 0 < 1, 2, ..., n = N
    cout << "0 ";
    /// Check
    for (i = 1; i < N; i++)
    {
        i2 = i * i;
        sum = 0;
        coefficient = 1;
        /// Sum and check
        while (i2 > 0)
        {
            sum += coefficient * (i2 % 10);
            if (i == sum)
            {
                cout << i << " ";
                break;
            }
            coefficient *= 10;
            i2 /= 10;
        }
    }
    cout << endl;
}
/// Search of nonreducible fractions, denominator < N
void function_3 (int N)
{
    int numerator; /// numerator
    int denominator; /// denominator
    int number = 0; /// number of nonreducible fractions
    /// Search
    for (denominator = 2; denominator < N; denominator++)
    {
        for (numerator = 1; numerator < denominator; numerator++)
        {
            if (gcd(numerator, denominator) == 1)
            {
                cout << numerator << "/" << denominator << " ";
                number++;
            }
        }
    }
    if (number != 0)
        cout << endl;
    else cout << "Not found" << endl;
}
/// Search of perfect numbers
void function_4 (int N)
{
    int i; /// counter
    int number = 0; /// number of perfect numbers
    /// Search
    for (i = 2; i < N; i++)
        if (i == decomposition(i))
        {
            number++;
            cout << i << " ";
        }
    if (number != 0)
        cout << endl;
    else cout << "Not found" << endl;
}
/// Is this date correct or incorrect?
bool function_5 (int day, int month, int year)
{
    if (year < 1)
    {
        cout << "Incorrect date" << endl;
        return 0;
    }
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
                    return 0;
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
                    return 0;
                }
                break;
            }
        case 2:
            {
                if ((day > 28 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))) || (day > 29 && year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
                {
                    cout << "Incorrect date" << endl;
                    return 0;
                }
                break;
            }
        default:
        {
            cout << "Incorrect date" << endl;
            return 0;
        }
    }
    return 1;
}
int main3()
{
    int number = 0; /// number of task
    cout << "Please, enter the number of task ( 1, 2, 3, 4, 5 )" << endl;
    cout << "1. N : number of various digits?" << endl;
    cout << "2. N : all automorphic numbers < N" << endl;
    cout << "3. N : all nonreducible fractions, denominator < N" << endl;
    cout << "4. N : all perfect numbers < N" << endl;
    cout << "5. Input: date of birth, current date. Output: number of lived days, 1(number of lived days), 2(number of lived days), 4 (number of lived days)" << endl;
    /// Input
    while (number == 0)
    {
        cin >> number;
        if (number < 1 || number > 5)
            number = 0;
    }

    switch (number)
    {
        case 1:
        {
            int N = 0; /// input date
            /// Input
            while (N == 0)
            {
                cout << "N = ";
                cin >> N;
                if (N < 1)
                    N = 0;
            }
            /// Processing and output
            cout << function_1(N) << endl;
            break;
        }
        case 2:
        {
            int N = 0; /// input date
            /// Input
            while (N == 0)
            {
                cout << "N = ";
                cin >> N;
                if (N < 1 || N > 46340)
                    N = 0;
            }
            /// Processing and output
            function_2(N);
            break;
        }
        case 3:
        {
            int N = 0; /// input date
            /// Input
            while (N == 0)
            {
                cout << "N = ";
                cin >> N;
                if (N < 1)
                    N = 0;
            }
            /// Processing and output
            function_3(N);
            break;
        }
        case 4:
        {
            int N = 0; /// input date
            /// Input
            while (N == 0)
            {
                cout << "N = ";
                cin >> N;
                if (N < 1 || N > 1000000)
                    N = 0;
            }
            /// Processing and output
            function_4(N);
            break;
        }
        case 5:
        {
            int d1; /// day of birth
            int d2; /// current day
            int m1; /// month of birth
            int m2; /// current month
            int y1; /// year of birth
            int y2; /// current year

            int month1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; /// for not leap year
            int month2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; /// for leap year

            int i; /// counter
            int subproduct1 = 0; /// number of days which have passed in year of birth
            int subproduct2 = 0; /// number of days which have passed in current year
            int result = 0; /// number of lived days
            /// Input and check
            cout << "Please, enter the date of birth" << endl;
            cin >> d1 >> m1 >> y1;

            while (!function_5(d1, m1, y1))
                cin >> d1 >> m1 >> y1;

            cout << "Please, enter the current date" << endl;
            cin >> d2 >> m2 >> y2;

            while (!function_5(d2, m2, y2))
                cin >> d2 >> m2 >> y2;
            /// The number of days from the begin of year of birth
            if (y1 % 4 != 0 || (y1 % 100 == 0 && y1 % 400 != 0))
                for (i = 0; i < m1-1; i++)
                    subproduct1+= month1[i];
            else
                for (i = 0; i < m1-1; i++)
                    subproduct1 += month2[i];
            subproduct1 += d1;
            /// The number of days from the begin of current year
            if (y2 % 4 != 0 || (y1 % 100 == 0 && y1 % 400 != 0))
                for (i = 0; i < m2-1; i++)
                    subproduct2 += month1[i];
            else
                for (i = 0; i < m2-1; i++)
                    subproduct2 += month2[i];
            subproduct2 += d2;
            /// Sum of days in intermediate years
            for (i = y1 + 1; i < y2; i++)
            {
                if (i % 4 != 0)
                    result += 365;
                else result += 366;
            }
            /// Processing
            if (y1 == y2)
                result += subproduct2 - subproduct1;
            else
            {
                if (y1 % 4 != 0 || (y1 % 100 == 0 && y1 % 400 != 0))
                    subproduct1 = 365 - subproduct1;
                else
                    subproduct1 = 366 - subproduct1;
                result += subproduct1 + subproduct2;
            }
            /// Output
            cout << result << endl;
            /// Processing and output
            cout << "1) " << function_1(result) << endl;
            cout << "2) ";
            if (result <= 46340)
                function_2(result);
            else
                cout << "Too large number" << endl;
            cout << "4) ";
            if (result < 1000000)
                function_4(result);
            else
                cout << "Too large number" << endl;
            break;
        }
    }
    return 0;
}

