#include <iostream>

using namespace std;
///Greatest common divisor
int gcd_4 (int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd_4 (b, a % b);
}

int main4()
{
    int number = 0;
    cout << "Please, enter the number of task ( 1, 2, 3, 4, 5 )" << endl;
    cout << "1. We have array with integers. This array have even quantity of numbers a, b, c, ..., m and odd quantity of number x. x - ? " << endl;
    cout << "2. a1, a2, ..., an : maximal result of multiplication with 3 numbers?" << endl;
    cout << "3. A1 and A2 - polynomials : A1 + A2 = ? and A1 x A2 = ?" << endl;
    cout << "4. a1, a2, ..., an : If ax - minimal element, x = ? and sort_on_decrease(a1, ..., ax-1), sort_on_increase(ax+1, ..., an)" << endl;
    cout << "5. A = a1, a2, ..., an -> A + B (= b1, b2, ..., bm (m - minimal))  - arithmetic progression" << endl;
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
            int n; /// number of elements
            cout << "Please, enter the number of elements of array" << endl;
            cin >> n;
            while (n % 2 == 0)
            {
                cout << "Incorrect input data" << endl;
                cin >> n;
            }
            int *a = new int [n]; /// input data (array)
            int *k = new int [n]; /// quantity of numbers
            int quantityOdd = 0; /// quantity of numbers with odd quantity
            int x; /// result
            cout << "Please, enter elements of array" << endl;
            for (int i = 0; i < n; i++)
            {
                cin >> a[i];
                k[i] = 1;
            }
            /// Processing
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (a[j] == a[i])
                    {
                        for (int t = j; t < n - 1; t++)
                            a[t] = a[t + 1];
                        k[i]++;
                        n--;
                        j--;
                    }

                }
                /// Check
                if (k[i] % 2 != 0)
                {
                    x = a[i];
                    quantityOdd++;
                }
            }
            if (quantityOdd == 1)
                cout << x << endl;
            else cout << "Incorrect input data" << endl;
            break;
        }
        case 2:
        {
            int a[5]; /// array: first minimal value, second minimal value, third peak value, second peak value, first peak value
            int x; /// variable
            string answer;
            cout << "Please, enter integers (more than 3)" << endl;
            /// Input and processing
            cin >> x;
            a[4] = x;
            cin >> x;
            if (x > a[4])
            {
                a[3] = a[4];
                a[1] = a[4];
                a[4] = x;
            }
            else
            {
                a[3] = x;
                a[1] = x;
            }
            cin >> x;
            if (x > a[4])
            {
                a[2] = a[3];
                a[3] = a[4];
                a[4] = x;
                a[0] = a[2];
                a[1] = a[3];
            }
            else
                if (x > a[3])
                {
                    a[2] = a[3];
                    a[3] = x;
                    a[0] = a[2];
                    a[1] = a[3];
                }
                else
                {
                    a[2] = x;
                    a[0] = x;
                }
            cout << "If you want to finish input, enter EXIT. Else enter any symbol" << endl;
            cin >> answer;
            while (answer != "EXIT")
            {
                cin >> x;
                if (x > a[4])
                {
                    a[2] = a[3];
                    a[3] = a[4];
                    a[4] = x;
                }
                else
                    if (x > a[3])
                    {
                        a[2] = a[3];
                        a[3] = x;
                    }
                    else
                        if (x > a[2])
                        {
                            a[2] = x;
                            if (x > a[0] && x < a[1])
                                a[1] = x;
                            if (x < a[0])
                            {
                                a[1] = a[0];
                                a[0] = x;
                            }
                        }
                        else
                        {
                            if (x > a[0] && x < a[1])
                            a[1] = x;
                            if (x < a[0])
                            {
                                a[1] = a[0];
                                a[0] = x;
                            }
                        }
                cout << "If you want to finish input, enter EXIT. Else enter any symbol" << endl;
                cin >> answer;
            }
            int multiplication1 = a[0] * a[1] * a[4];
            int multiplication2 = a[2] * a[3] * a[4];
            cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << endl;
            if (multiplication1 > multiplication2)
                cout << a[0] << " x " << a[1] << " x " << a[4] << " = " << multiplication1 << endl;
            else
                cout << a[2] << " x " << a[3] << " x " << a[4] << " = " << multiplication2 << endl;
            break;
        }
        case 3:
        {
            int n1; /// number of elements of array #1
            int n2; /// number of elements of array #2
            cout << "Please, enter the number of elements of array #1 with coefficients" << endl;
            cin >> n1;
            int *a1 = new int [n1]; /// input data (array #1)
            cout << "Please, enter elements of array #1" << endl;
            for (int i = 0; i < n1; i++)
                cin >> a1[i];
            for (int i = 0; i < n1; i++)
                if (i == 0)
                    cout << "1) " << a1[i];
                else
                    cout << " + " << a1[i] << "x^" << i;
            cout << endl;
            cout << "Please, enter the number of elements of array #2 with coefficients" << endl;
            cin >> n2;
            int *a2 = new int [n2]; /// input data (array #2)
            cout << "Please, enter elements of array #2" << endl;
            for (int i = 0; i < n2; i++)
                cin >> a2[i];
            for (int i = 0; i < n2; i++)
                if (i == 0)
                    cout << "2) " << a2[i];
                else
                    cout << " + " << a2[i] << "x^" << i;
            cout << endl;
            int maxN = max(n2, n1); /// maximal number
            int minN = min(n1, n2); /// minimal number
            int maxPower = n1 + n2 - 1; /// maximal power
            int *sum = new int [maxN]; /// sum (result array)
            int *multiplication = new int [maxPower]; /// multiplication (result array)
            for (int i = 0; i < maxPower; i++)
                multiplication[i] = 0;
            /// Sum
            for (int i = 0; i < minN; i++)
                sum[i] = a1[i] + a2[i];
            for (int i = minN; i < maxN; i++)
                if (maxN == n1)
                    sum[i] = a1[i];
                else
                    sum[i] = a2[i];
            for (int i = 0; i < maxN; i++)
                if (i == 0)
                    cout << "SUM: " << sum[i];
                else
                    cout << " + " << sum[i] << "x^" << i;
            cout << endl;
            /// Multiplication
            for (int i = 0; i < n1; i++)
                for (int j = 0; j < n2; j++)
                    multiplication[i + j] += a1[i] * a2[j];
            for (int i = 0; i < maxPower; i++)
                if (i == 0)
                    cout << "MULTIPLACATION: " << multiplication[i];
                else
                    cout << " + " << multiplication[i] << "x^" << i;
            cout << endl;
            break;
        }
        case 4:
        {
            int n; /// number of elements
            cout << "Please, enter the number of elements of array" << endl;
            cin >> n;
            int c = 0; ///counter of minimal elements
            int *a = new int [n]; /// input data (array)
            cout << "Please, enter elements of array" << endl;
            cin >> a[0];
            int min = a[0]; /// minimum value
            int minN = 0; /// number of minimal element
            /// Input and search of minimal element
            for (int i = 1; i < n; i++)
            {
                cin >> a[i];
                if (a[i] < min)
                {
                    min = a[i];
                    minN = i;
                }
            }
            for (int i = 0; i < n; i++)
                if (a[i] == min)
                    c++;
            if (c > 1)
            {
                cout << "Incorrect input data" << endl;
                return 0;
            }
            ///Sort on decrease
            for (int i = 0; i < minN; i++)
            {
                for (int j = minN - 1; j > i; j--)
                    if (a[j - 1] < a[j])
                    {
                        int bufer = a[j - 1];
                        a[j - 1] = a[j];
                        a[j] = bufer;
                    }
            }
            ///Sort on increase
            for (int i = minN + 1; i < n; i++)
            {
                for (int j = n - 1; j > i; j--)
                    if (a[j - 1] > a[j])
                    {
                        int bufer = a[j - 1];
                        a[j - 1] = a[j];
                        a[j] = bufer;
                    }
            }
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
            cout << "Minimal element: " << min << endl;
            cout << "Number of minimal element: " << minN << endl;
            break;
        }
        case 5:
        {
            int n; /// number of elements
            int x; /// variable
            cout << "Please, enter the number of elements of array" << endl;
            cin >> n;
            while (n < 2)
            {
                cout << "n > 1" << endl;
                cin >> n;
            }
            int *a = new int [n]; /// input data (array)
            cout << "Please, enter elements of array" << endl;
            for (int i = 0; i < n; i++)
            {
                cin >> a[i];
                for (int j = i - 1; j >= 0; j--)
                    if (a[i] == a[j])
                    {
                        cout << "Incorrect" << endl;
                        i--;
                        break;
                    }
            }
            ///Sort on increase
            for (int i = 0; i < n; i++)
            {
                for (int j = n - 1; j > i; j--)
                    if (a[j - 1] > a[j])
                    {
                        int bufer = a[j - 1];
                        a[j - 1] = a[j];
                        a[j] = bufer;
                    }
            }
            int *d = new int [n - 1]; /// d[1] = a[2] - a[1], d[2] = a[3] - a[2], ..., d[n-1] = a[n] - a[n-1]
            for (int i = 0; i < n - 1; i++)
                d[i] = a[i + 1] - a[i];
            int i = 0; /// counter
            ///Processing
            for (int i = 0; i < n - 2; i++)
            {
                d[i] = gcd_4(d[i], d[i + 1]);
                d[i + 1] = d[i];
            }
            for (x = a[0]; x <= a[n - 1]; x += d[n - 2])
                cout << x << " ";
            break;
        }
    }
    return 0;
}

