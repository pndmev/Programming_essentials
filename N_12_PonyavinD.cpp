#include <iostream>
#include "Series.h"
#include "Array.h"

using namespace std;

int main12()
{
    cout << "1. Base class: Series. Subclasses: Liner, Exponential" << endl;
    cout << "2. Base class: Array. Subclass: Polynomial" << endl;
    while (do_you_want_to_continue())
    {
        int number = 0;
        cout << "Please, enter the number of task ( 1, 2 )" << endl;
        while (number == 0)
        {
            cin >> number;
            if (number < 1 || number > 2)
            {
                cout << "Incorrect number" << endl;
                number = 0;
            }
        }
        switch (number)
        {
            case 1:
            {
                Liner L;
                Exponential E;
                Series* S1 = &L;
                Series* S2 = &E;
                cout << "Please, enter the linear series: first element, step and quantity of elements" << endl;
                cin >> L;
                cout << "Your linear series: " << L << endl;
                cout << "Please, enter the exponential series: first element, step and quantity of elements" << endl;
                cin >> E;
                cout << "Your exponential series: " << E << endl;
                int i;
                cout << "Please, enter the number of element" << endl;
                cin >> i;
                cout << i << "th element in linear series: " << S1 -> element(i) << endl;
                cout << i << "th element in exponential series: " << S2 -> element(i) << endl;
                cout << "Sum of linear series: " << S1 -> sum() << endl;
                cout << "Sum of exponential series: " << S2 -> sum() << endl;
                break;
            }
            case 2:
            {
                int n;
                do
                {
                    cout << "Please, set the maximal value of size of array" << endl;
                    cin >> n;
                }
                while (n <= 0);
                setMAX_SIZE(n);
                do
                {
                    cout << "Please enter the number of elements of array 1 (n > 0)" << endl;
                    cin >> n;
                }
                while (n <= 0);
                Array a(n);
                cout << "Please, enter the elements of array 1" << endl;
                cin >> a;
                do
                {
                    cout << "Please enter the number of elements of array 2 (n > 0)" << endl;
                    cin >> n;
                }
                while (n <= 0);
                Array b(n);
                cout << "Please, enter the elements of array 2" << endl;
                cin >> b;
                cout << endl << "Your first array: " << a << endl;
                cout << "Your second array: " << b << endl;
                Array c;
                c = a + b;
                cout << "first array + second array = " << c << endl;
                cout << endl;

                do
                {
                    cout << "Please, enter the degree of polynomial 1" << endl;
                    cin >> n;
                }
                while (n < 0);
                cout << "Please, enter the coefficients of first polynomial" << endl;
                Polynomial p1(n + 1);
                cin >> p1;
                p1.dipOfDegree();
                do
                {
                    cout << "Please, enter the degree of polynomial 2" << endl;
                    cin >> n;
                }
                while (n < 0);
                cout << "Please, enter the coefficients of second polynomial" << endl;
                Polynomial p2(n + 1);
                cin >> p2;
                p2.dipOfDegree();
                cout << endl << "Your first polynomial: " << p1 << endl;
                cout << "Your second polynomial: " << p2 << endl;
                Polynomial p;
                p = p1 + p2;
                p.dipOfDegree();
                cout << "first polynomial + second polynomial = " << p << endl;
                p = p1 - p2;
                p.dipOfDegree();
                cout << "first polynomial - second polynomial = " << p << endl;
                p = p1 * p2;
                p.dipOfDegree();
                cout << "first polynomial * second polynomial = " << p << endl;
                cout << endl;
                bool flag;
                flag = p1 > p2;
                cout << "first polynomial > second polynomial ? " << boolalpha << flag << endl;
                flag = p1 < p2;
                cout << "first polynomial < second polynomial ? " << boolalpha << flag << endl;
                flag = p1 == p2;
                cout << "first polynomial == second polynomial ? " << boolalpha << flag << endl;
                flag = p1 != p2;
                cout << "first polynomial != second polynomial ? " << boolalpha << flag << endl;
                cout << endl;
                int x;
                cout << "Please, enter x" << endl;
                cin >> x;
                int result;
                result = p1.value(x);
                cout << "First polynomial in x = " << x << " : " << result << endl;
                break;
            }
        }
    }
    return 0;
}

