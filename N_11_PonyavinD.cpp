#include <iostream>
#include "Set.h"
#include "Fraction.h"
#include "Vector.h"

using namespace std;

void swap (Fraction* fArr, int p1, int p2)
{
    Fraction bufer = fArr[p1];
    fArr[p1] = fArr[p2];
    fArr[p2] = bufer;
}

void sort (Fraction* fArr, int fArrSize)
{
    int left = 0;
    int right = fArrSize - 1;
    for (left = 0; left < right; left++)
    {
        for (int i = left; i < right; i++)
        {
            if (fArr[i] >= fArr[i + 1])
                swap(fArr, i, i + 1);
        }
        right--;
        for (int i = right; i > left; i--)
        {
            if (fArr[i] <= fArr[i - 1])
                swap(fArr, i, i - 1);
        }
    }
}

int main11()
{
    cout << "1. Class 'Set'" << endl;
    cout << "2. Class 'Fraction'" << endl;
    cout << "3. Class 'Vector'" << endl;
    while (do_you_want_to_continue())
    {
        int number = 0;
        cout << "Please, enter the number of task ( 1, 2, 3)" << endl;
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
                Set s1, s2;
                cout << "Please, enter the first set and second set" << endl;
                cin >> s1 >> s2;
                cout << "Your first set: s1 = " << s1 << endl;
                cout << "Your second set: s2 = " << s2 << endl;
                Set s = s1 + s2;
                cout << "s1 + s2 = " << s << endl;
                s = s1 - s2;
                cout << "s1 - s2 = " << s << endl;
                s = s1 * s2;
                cout << "s1 * s2 = " << s << endl;
                bool flag = s1 == s2;
                cout << "s1 == s2 = " << boolalpha << flag << endl;
                flag = s1 < s2;
                cout << "s1 < s2 = " << boolalpha << flag << endl;
                break;
            }
            case 2:
            {
                /// Test 1: input/output, addition/subtraction/multiplication, comparing
                Fraction f1, f2;
                cout << "Please, enter the first fraction and second fraction" << endl;
                cin >> f1 >> f2;
                cout << f1 << " " << f2 << endl;
                Fraction result;
                result = f1 + f2;
                cout << "f1 + f2 = " << result << endl;
                result = f1 - f2;
                cout << "f1 - f2 = " << result << endl;
                result = f1 * f2;
                cout << "f1 * f2 = " << result << endl;
                bool flag;
                flag = f1 <= f2;
                cout << "f1 <= f2 ? " << boolalpha << flag << endl;
                flag = f1 >= f2;
                cout << "f1 >= f2 ? " << boolalpha << flag << endl;

                /// Test 2: array, sorting
                int n = 0;
                while (n <= 0)
                {
                    cout << "Please, enter the number of elements of array with fractions (n > 0)" << endl;
                    cin >> n;
                }
                Fraction* fArr = new Fraction [n];
                for (int i = 0; i < n; i++)
                    cin >> fArr[i];
                sort(fArr, n);
                for (int i = 0; i < n; i++)
                    cout << fArr[i] << " ";
                cout << endl;

                /// Test 3: sum
                Fraction left, right, step;
                cout << "Please, enter the following data:" << endl;
                cout << "1) Left border: ";
                cin >> left;
                cout << "2) Right border: ";
                cin >> right;
                cout << "3) Step: ";
                cin >> step;
                Fraction null(0, 0, '+');
                if (left <= right && step > null)
                {
                    Fraction f, sum(0, 0, '+');
                    for (f = left; f <= right; f += step)
                        sum += f;
                    cout << "sum = " << sum << endl;
                }
                else
                    cout << "Incorrect input data" << endl;
                break;
            }
            case 3:
            {
                int size;
                do
                {
                    cout << "Please, enter the number of elements of vector" << endl;
                    cin >> size;
                }
                while (size <= 0);
                Vectorex <int> v(size);
                cout << "Please, enter the elements of vector" << endl;
                cin >> v;
                cout << "Your vector: " << v << endl;
                cout << "Please, enter the element for inserting" << endl;
                int x;
                cin >> x;
                v.push_front(x);
                cout << "Please, enter yet " << size - 1 << " elements" << endl;
                int newSize = v.VectorSize();
                for (int i = size + 1; i < newSize; i++)
                    cin >> v[i];
                cout << "Your new vector: " << v << endl;
                int quantity;
                do
                {
                    cout << "Please, enter the number of elements for deleting" << endl;
                    cin >> quantity;
                }
                while (quantity <= 0 && quantity > newSize);
                for (int i = 0; i < quantity; i++)
                    v.pop_front();
                cout << "Your new vector: " << v << endl;
                break;
            }
        }
    }
    return 0;
}

