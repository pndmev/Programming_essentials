#include <iostream>
#include <cmath>

using namespace std;

int main1()
{
	int number = 0; /// number of task
	cout << "Please, enter the number of task ( 1, 2, 3 )" << endl;
	cout << "1. Square in circle/circle in square" << endl;
	cout << "2. ax^2 + bx + c = 0 : x1,2 = ?" << endl;
	cout << "3. max_even(a1, a2, ..., an) = ?" << endl;
	/// Input
	while (number == 0)
	{
		cin >> number;
		if (number < 1 || number > 3)
        {
            cout << "Incorrect number" << endl;
            number = 0;
        }
	}

	switch (number)
	{
        case 1:
        {
            double sSquare = 0; /// square of square
            double sCircle = 0; /// square of circle
            /// Input
            while (1)
            {
                cout << "Please, enter the square of a square" << endl;
                cin >> sSquare;
                if (sSquare > 0)
                    break;
                else cout << "Square > 0" << endl;
            }
            while (1)
            {
                cout << "Please, enter the square of a circle" << endl;
                cin >> sCircle;
                if (sCircle > 0)
                    break;
                else cout << "Square > 0" << endl;
            }
            float r2 = sCircle / M_PI; /// radius^2
            /// Check
            if (sSquare <= 2 * r2)
                cout << "a) Square in circle: YES" << endl;
            else cout << "a) Square in circle: NO" << endl;

            if (sSquare >= 4 * r2)
                cout << "b) Circle in square: YES" << endl;
            else cout << "b) Circle in square: NO" << endl;
            break;
        }
        case 2:
        {
            double a; /// quadratic coefficient
            double b; /// linear coefficient
            double c; /// constant
            /// Input
            cout << "ax^2 + bx + c = 0" << endl;
            cout << "a = ";
            cin >> a;
            cout << "b = ";
            cin >> b;
            cout << "c = ";
            cin >> c;
            /// If quadratic equation
            if (a == 0)
            {
                double d = b * b - 4 * a * c;
                if (d >= 0)
                {
                    double x1;
                    double x2;
                    x1 = (-1 * b + sqrt(d)) / (2 * a);
                    x2 = (-1 * b - sqrt(d)) / (2 * a);
                    if (x1 == x2)
                        cout << "x = " << x1;
                    else
                        cout << "x1 = "<< x1 << "; x2 = " << x2;
                }
                else
                    cout << "There aren't solutions of an equation" << endl;
            }
            /// If simple equation
            else
            {
                if (b != 0)
                    cout << (-1 * c) / b;
                else
                    if (c == 0)
                        cout << "x = R" << endl;
                    else
                        cout << "There aren't solutions of equation" << endl;
            }

            break;
        }
        case 3:
        {
            cout << "Please, enter integers" << endl;
            int max = -1; /// peak value
            int x; /// variable
            /// Input and processing
            string answer;
            cin >> x;
            if (!(x % 2) && ((max != -1 && x > max) || (max == -1)))
                max = x;
            cout << "If you want to finish input, enter EXIT. Else enter any symbol" << endl;
            cin >> answer;
            while (answer != "EXIT")
            {
                cin >> x;
                if (!(x % 2) && ((max != -1 && x > max) || (max == -1)))
                    max = x;
                cout << "If you want to finish input, enter EXIT. Else enter any symbol" << endl;
                cin >> answer;
            }
            if (max == -1)
                cout << "Not found" << endl;
            else
                cout << "Max_even = " << max << endl;
            break;
        }
	}
}
