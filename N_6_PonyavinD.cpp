#include <iostream>
#include <vector>

using namespace std;

int* search_prime_numbers6 (int *a, int &n)
{
    int *b = new int [n];
    int counter = 0;
    int quantity = 0;
    for (int i = 0; i < n; i++)
    {
        quantity = 0;
        if (a[i] != 1)
        {
            for (int j = a[i] - 1; j > 1; j--)
            {
                if (a[i] % j == 0)
                    quantity++;
            }
            if (quantity == 0)
            {
                b[counter] = a[i];
                counter++;
            }
        }
    }
    n = counter;
    return b;
}

int* shaker_sort6 (int *a, int &n)
{
    int *b = copy_array(a, n);
    int left = 0;
    int right = n - 1;
    for (left = 0; left < right; left++)
    {
        for (int i = left; i < right; i++)
        {
            if (b[i] > b[i + 1])
                my_swap(b[i], b[i + 1]);
        }
        right--;
        for (int i = right; i > left; i--)
        {
            if (b[i] < b[i - 1])
                my_swap(b[i], b[i - 1]);
        }
    }
    return b;
}

int* search_median6 (int *a, int &n)
{
    int *b = copy_array(a, n);
    quick_sort(b, n);
    int *median = new int [1];
    median = b + n/2;
    n = 1;
    return median;
}

int** insert_row(int **a, int *x, int position, int &nRowA, int &nColumnA)
{
    nRowA++;
    int** b = new int* [nRowA];
    for (int i = 0; i < nRowA; i++)
        b[i] = new int [nColumnA];
    for (int i = 0; i < nRowA; i++)
    {
        if (i < position)
        {
            for (int j = 0; j < nColumnA; j++)
                b[i][j] = a[i][j];
        }
        else
            if (i == position)
            {
                for (int j = 0; j < nColumnA; j++)
                    b[i][j] = x[j];
            }
            else
            {
                for (int j = 0; j < nColumnA; j++)
                    b[i][j] = a[i - 1][j];
            }
    }
    return b;
}

int** delete_row(int **a, int *x, int position, int &nRowA, int &nColumnA)
{
    nRowA--;
    int** b = new int* [nRowA];
    for (int i = 0; i < nRowA; i++)
        b[i] = new int [nColumnA];
    for (int i = 0; i < nRowA; i++)
    {
        if (i < position)
        {
            for (int j = 0; j < nColumnA; j++)
                b[i][j] = a[i][j];
        }
        else
        {
            for (int j = 0; j < nColumnA; j++)
                b[i][j] = a[i - 1][j];
        }
    }
    return b;
}

bool check_char_digit6 (char c)
{
    return c > 47 && c < 58 ? true: false;
}

bool check_char_digit_and_point6 (char c)
{
    return  c == '.' || (c > 47 && c < 58)? true: false;
}

int string_to_int6 (string s)
{
    int sSize = str_size(s);
    int coefficient = 1;
    int result = 0;
    for (int i = sSize - 1; i >= 0; i--)
    {
        result += coefficient * (s[i] - 48);
        coefficient *= 10;
    }
    return result;
}

double string_to_double6 (string s)
{
    int sSize = str_size(s);
    double coefficient = 1;
    double result = 0;
    for (int i = sSize - 1; i >= 0; i--)
    {
        if (s[i] != '.')
        {
            result += coefficient * (s[i] - 48);
            coefficient *= 10;
        }
    }
    coefficient = 1;
    for (int i = 0; i < sSize; i++)
    {
        if (s[i] == '.')
        {
            for (int j = 0; j < sSize - i - 1; j++)
                coefficient /= 10;
        }
    }
    return result * coefficient;
}

int* search_of_decimal_constants6 (string s, int &quantity)
{
    int sSize = str_size(s);
    string StringWithConst;
    quantity = 0;
    for (int i = 0; i < sSize; i++)
    {
        if (check_char_digit6(s[i]))
        {
            bool flag = true;
            while (flag)
            {
                StringWithConst += s[i];
                i++;
                flag = check_char_digit6(s[i]);
            }
            StringWithConst += " ";
            quantity++;
        }
    }
    int *a = new int [quantity];
    int j = 0;
    for (int i = 0; i < quantity; i++)
    {
        string StringWithNumber;
        while (StringWithConst[j] != ' ')
        {
            StringWithNumber += StringWithConst[j];
            j++;
        }
        j++;
        a[i] = string_to_int6(StringWithNumber);
    }
    return a;
}

double* search_of_real_constants6 (string s, int &quantity)
{
    int sSize = str_size(s);
    int counter; /// counter of points
    string StringWithConst;
    quantity = 0;
    for (int i = 0; i < sSize; i++)
    {
        if (check_char_digit_and_point6(s[i]))
        {
            bool flag = true;
            counter = 0;
            while (flag)
            {
                if (s[i] == '.')
                {
                    if (counter == 1)
                    {
                        i--;
                        break;
                    }
                    else
                        counter++;
                }
                StringWithConst += s[i];
                i++;
                flag = check_char_digit_and_point6(s[i]);
            }
            StringWithConst += " ";
            quantity++;
        }
    }
    double *a = new double [quantity];
    int j = 0;
    for (int i = 0; i < quantity; i++)
    {
        string StringWithNumber;
        while (StringWithConst[j] != ' ')
        {
            StringWithNumber += StringWithConst[j];
            j++;
        }
        j++;
        a[i] = string_to_double6(StringWithNumber);
    }
    return a;
}

int main6()
{
    int number = 0;
    cout << "Please, enter the number of task ( 1, 2, 3, 4, 5 )" << endl;
    cout << "1. 3 functions for array with integers. 1) Search of prime numbers; 2) Sorting; 3) Search of median of array" << endl;
    cout << "2. 2 functions for array. 1) Insert string; 2) Delete string" << endl;
    cout << "3. Search of decimal constants" << endl;
    cout << "4. Search of real constants" << endl;
    while (number == 0)
    {
        cin >> number;
        if (number < 1 || number > 4)
        {
            cout << "Incorrect number" << endl;
            number = 0;
        }
    }
    switch (number)
    {
        case 1:
        {
            int na; /// quantity of elements of array a
            int nb; /// quantity of elements of array b
            int *a = cin_array(na); /// input array
            int *b; /// result array
            nb = na;
            int* (*f)(int*, int&); /// pointer for functions
            cout << "1) Search of prime numbers in array; 2) Sorting array; 3) Search of median of array. Please, enter 1, 2 or 3" << endl;
            char answer;
            cin >> answer;
            /// Checking answer
            switch (answer)
            {
                case '1':
                {
                    f = search_prime_numbers6;
                    break;
                }
                case '2':
                {
                    f = shaker_sort6;
                    break;
                }
                case '3':
                {
                    f = search_median6;
                    break;
                }
                default:
                {
                    cout << "Incorrect" << endl;
                    return 0;
                }
            }
            b = (*f)(a, nb); /// Processing
            cout_array(b, nb); /// Output
            break;
        }
        case 2:
        {
            int nRowA; /// number of rows
            int nColumnA; /// number of columns
            int **a = cin_array_2(nRowA, nColumnA); /// input array
            int *x; /// row for insert
            int position; /// position of insert OR position of delete
            int** (*f)(int**, int*, int, int&, int&); /// pointer for functions
            cout << "1) Insert row; 2) Delete row. Please, enter 1 or 2" << endl;
            char answer;
            cin >> answer;
            /// Checking answer
            switch (answer)
            {
                case '1':
                {
                    f = insert_row;
                    cout << "Please, enter the elements of row for inserting" << endl;
                    x = new int [nColumnA];
                    for (int i = 0; i < nColumnA; i++)
                        cin >> x[i];
                    cout << "Please, enter the number of position of this row in array" << endl;
                    cin >> position;
                    break;
                }
                case '2':
                {
                    f = delete_row;
                    cout << "Please, enter number of row for deleting" << endl;
                    cin >> position;
                    if (position < 0 || position > nRowA)
                    {
                        cout << "Incorrect" << endl;
                        return 0;
                    }
                    break;
                }
                default:
                {
                    cout << "Incorrect" << endl;
                    return 0;
                }
            }
            a = (*f)(a, x, position, nRowA, nColumnA); /// Processing
            cout_array_2(a, nRowA, nColumnA); /// Output
            break;
        }
        case 3:
        {
            string s; /// string with decimal constants
            cout << "Please, enter string" << endl;
            cin >> s; /// Input
            int quantity; /// quantity of constants
            int *a; /// array with constants
            a = search_of_decimal_constants6(s, quantity); /// Processing
            cout_array(a, quantity); /// Output
            break;
        }
        case 4:
        {
            string s; /// string with real constants
            cout << "Please, enter string" << endl;
            cin >> s; /// Input
            int quantity; /// quantity of constants
            double *a; /// array with constants
            a = search_of_real_constants6(s, quantity); /// Processing
            cout_array_double(a, quantity); /// Output
            break;
        }
    }
    return 0;
}

