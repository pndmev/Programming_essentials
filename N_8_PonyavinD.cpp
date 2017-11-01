#include <iostream>
#include "Complex.h"
#include "StackComplex.h""

using namespace std;

bool Comparing (Complex C1, Complex C2)
{
    double C1Re = C1.Get_Re();
    double C1Im = C1.Get_Im();
    double C2Re = C2.Get_Re();
    double C2Im = C2.Get_Im();
    return C1Re * C1Re + C1Im * C1Im > C2Re * C2Re + C2Im * C2Im;
}

bool CheckAnswer ()
{
    string answer;
    cout << "If you want to exit, enter EXIT. Else enter other symbol" << endl;
    cin >> answer;
    return answer != "EXIT";
}

int main8()
{
    cout << "1. Class 'Complex number': constructors by default and for copying, addition, setting, comparing (modulus of a vector); testing for array with complex numbers; the class interface in heading the file; function for comparing (parameters: complex numbers)" << endl;
    cout << "2. Class 'Stack for complex numbers'" << endl;

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
                int n;
                cout << "Please, enter the number of elements of array of complex numbers" << endl;
                cin >> n;
                Complex *C = new Complex [n];
                cout << "Please, enter the elements of array of complex numbers (Re1 Im1 Re2 Im2 ...)" << endl;
                double Re, Im;
                for (int i = 0; i < n; i++)
                {
                    cin >> Re >> Im;
                    C[i].Set(Re, Im);
                }

                /// Test 1: Addition
                Complex SumC(0,0);
                for (int i = 0; i < n; i++)
                {
                    SumC.Add(C[i]);
                }
                cout << "Sum: ";
                SumC.Print();
                cout << endl;

                /// Test 2: Giving
                cout << "Cloned array: ";
                Complex *CC = new Complex [n];
                for (int i = 0; i < n; i++)
                {
                    CC[i].Set(C[i]);
                    CC[i].Print();
                    cout << "; ";
                }
                cout << endl;

                /// Test 3.1: Comparing 1
                Complex maxC = C[0];
                for (int i = 1; i < n; i++)
                {
                    if (C[i].Compare(maxC))
                        maxC.Set(C[i]);
                }
                cout << "Max: ";
                maxC.Print();
                cout << endl;

                /// Test 3.2: Comparing 2
                Complex minC = C[0];
                for (int i = 1; i < n; i++)
                {
                    if (Comparing(minC, C[i]))
                        minC.Set(C[i]);
                }
                cout << "Min: ";
                minC.Print();
                cout << endl;
                break;
            }
            case 2:
            {
                StackComplex S;
                cout << "Please, enter the elements of stack with complex numbers (Re1 Im1 Re2 Im2 ...)" << endl;
                double Re, Im;
                while (CheckAnswer())
                {
                    cin >> Re >> Im;
                    S.push(Re, Im);
                }
                cout << "Top: ";
                if (!S.empty())
                    S.top().Print();
                else
                    cout << "This stack is empty";
                cout << endl;

                cout << "Stack without top element: ";
                S.pop();
                S.print();
                break;
            }
        }
    }
    return 0;
}

