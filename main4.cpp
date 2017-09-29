#include <iostream>

using namespace std;
///Greatest common divisor
int gcd (int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd (b, a % b);
}

int main4()
{
    int number = 0;

    while (number == 0)
    {
        cout << "Please, enter the number of task ( 1, 2, 3, 4, 5 )" << endl;
        cout << "1. We have array with integers. This array have even quantity of numbers a, b, c, ..., m and odd quantity of number x. x - ? " << endl;
        cout << "2. a1, a2, ..., an : maximal result of multiplication with 3 numbers?" << endl;
        cout << "3. A1 and A2 - polynomials : A1 + A2 = ? and A1 x A2 = ?" << endl;
        cout << "4. a1, a2, ..., an : If ax - minimal element, x = ? and sort_on_decrease(a1, ..., ax-1), sort_on_increase(ax+1, ..., an)" << endl;
        cout << "5. A = a1, a2, ..., an -> A + B (= b1, b2, ..., bm (m - minimal))  - arithmetic progression" << endl;
        cin >> number;
        if (number < 1 || number > 5)
            number = 0;
    }
    switch (number)
    {
        case 1:
        {
            int n; /// number of elements
            cout << "Please, enter the number of elements of array" << endl;
            cin >> n;
            int a[n]; /// input data (array)
            int k[n]; /// quantity of numbers
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
                    cout << a[i];
                    break;
                }
            }
            break;
        }
        case 2:
        {
            int max1 = 0; /// first peak value
            int max2 = 0; /// second peak value
            int minNegative1 = 0; /// first minimal negative number
            int minNegative2 = 0; /// second minimal negative number
            int max3 = 0; /// third peak value
            int x; /// variable
            cout << "Please, enter integers (more than 3). If you want to finish input, enter 0" << endl;
            /// Input and processing
            cin >> x;
            if (x >= 0)
                max1 = x;
            else
                minNegative1 = x;
            cin >> x;
            if (x >= 0)
            {
                if (x > max1)
                {
                    max2 = max1;
                    max1 = x;
                }
                else
                    max2 = x;
            }
            else
            {
                if (x < minNegative1)
                {
                    minNegative2 = minNegative1;
                    minNegative1 = x;
                }
                else
                    minNegative2 = x;
            }
            cin >> x;
            if (x >= 0)
            {
                if (x > max1)
                {
                    max3 = max2;
                    max2 = max1;
                    max1 = x;
                }
                else
                    if (x > max2)
                    {
                        max3 = max2;
                        max2 = x;
                    }
                    else
                        max3 = x;
            }
            else
            {
                if (x < minNegative1)
                {
                    minNegative2 = minNegative1;
                    minNegative1 = x;
                }
                else
                    if (x < minNegative2)
                        minNegative2 = x;
            }
            cin >> x;
            while (x != 0)
            {
                if (x > 0)
                {
                    if (x > max1)
                    {
                        max3 = max2;
                        max2 = max1;
                        max1 = x;
                    }
                    else
                        if (x > max2)
                        {
                            max3 = max2;
                            max2 = x;
                        }
                        else
                            if (x > max3)
                                max3 = x;
                }
                else
                {
                    if (x < minNegative1)
                    {
                        minNegative2 = minNegative1;
                        minNegative1 = x;
                    }
                    else
                        if (x < minNegative2)
                            minNegative2 = x;
                }
                cin >> x;
            }
            if (minNegative1 * minNegative2 * max1 > max1 * max2 * max3)
                cout << minNegative1 << " x " << minNegative2 << " x " << max1 << " = " << minNegative1 * minNegative2 * max1 << endl;
            else
                cout << max1 << " x " << max2 << " x " << max3 << " = " << max1 * max2 * max3 << endl;
            break;
        }
        case 3:
        {
            int n1; /// number of elements of array #1
            int n2; /// number of elements of array #2
            cout << "Please, enter the number of elements of array #1 with coefficients" << endl;
            cin >> n1;
            int a1[n1]; /// input data (array #1)
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
            int a2[n2]; /// input data (array #2)
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
            int sum[maxN]; /// sum (result array)
            int multiplication[maxPower]; /// multiplication (result array)
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
            int a[n]; /// input data (array)
            cout << "PLease, enter elements of array" << endl;
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
            int copyN; /// number of elements (copy)
            int x; /// variable
            cout << "Please, enter the number of elements of array" << endl;
            cin >> n;
            copyN = n;
            int a[n]; /// input data (array)
            cout << "Please, enter elements of array" << endl;
            for (int i = 0; i < n; i++)
                cin >> a[i];
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
            int d[n - 1]; /// d[1] = a[2] - a[1], d[2] = a[3] - a[2], ..., d[n-1] = a[n] - a[n-1]
            for (int i = 0; i < n - 1; i++)
                d[i] = a[i + 1] - a[i];
            int i = 0; /// counter
            ///Processing
            while (copyN > 1)
            {
                d[i] = gcd(d[i], d[i + 1]);
                for (int j = i + 1; j < copyN - 2; j++)
                    d[j] = d[j + 1];
                copyN--;
                i++;
                if (i == copyN - 1)
                    i = 0;
            }
            for (x = a[0]; x <= a[n - 1]; x += d[0])
                cout << x << " ";
            break;
        }
    }
    return 0;
}

