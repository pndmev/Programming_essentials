#include <iostream>
#include <cmath>

using namespace std;

int* search_prime_numbers6 (int *a, int &n)
{
    int *b = new int [n];
    int counter = 0;
    int quantity = 0;
    for (int i = 0; i < n; i++)
    {
        quantity = 0;
        if (a[i] > 1)
        {
            double sqrtA = sqrt(a[i]);
            for (int j = int(sqrtA); j > 1; j--)
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
    cout << "Array with prime numbers: " << endl;
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
    cout << "Sorted array: " << endl;
    return b;
}

void function_for_search_of_median6 (int* a, int n, int center, int& position)
{
    int left = 0;
    int right = n - 1;
    int middle = (left + right) / 2;
    int quantityElementsRight = middle;
    while (right >= left)
    {
        while (a[right] > a[middle])
            right--;
        while (a[left] < a[middle])
            left++;
        if (left <= right)
        {
            my_swap(a[left], a[right]);
            quantityElementsRight += ((left == middle) - (right == middle)) * (right - left);
            left++;
            right--;
        }
    }
    if (quantityElementsRight == center)
    {
        position += quantityElementsRight;
        return;
    }
    if (quantityElementsRight > center)
    {
        function_for_search_of_median6 (a, quantityElementsRight + 1, center, position);
    }
    else
    {
        position += quantityElementsRight;
        function_for_search_of_median6 (a + quantityElementsRight, n - quantityElementsRight, center - quantityElementsRight, position);
    }
}

int* search_of_median6 (int *a, int &n)
{
    int center = (n - 1) / 2;
    int position = 0;
    function_for_search_of_median6(a, n, center, position);
    n = 1;
    return a + position;
}

int** insert_row(int **a, int *x, int position, int &nRowA, int nColumnA)
{
    nRowA++;
    int** b = new int* [nRowA];
    int i;
    for (i = 0; i < position; i++)
        b[i] = a[i];
    b[i] = x;
    for (i = i + 1; i < nRowA; i++)
        b[i] = a[i - 1];
    delete a;
    return b;
}

int** delete_row(int **a, int *x, int position, int &nRowA, int nColumnA)
{
    nRowA--;
    int** b = new int* [nRowA];
    delete_array(a[position]);
    for (int i = 0; i < position; i++)
        b[i] = a[i];
    for (int i = i; i < nRowA; i++)
        b[i] = a[i + 1];
    delete a;
    return b;
}

bool check_char_digit6 (char c)
{
    return c > 47 && c < 58;
}

bool check_char_digit_or_point6 (char c)
{
    return  c == '.' || (c > 47 && c < 58);
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

int array_char_to_int6 (char *c, int n)
{
    int coefficient = 1;
    int result = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        result += coefficient * (c[i] - 48);
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

int* search_of_decimal_constants_char6 (char *c, int n, int &quantity)
{
    char *StringWithConst = new char [n];
    int counter = 0;
    quantity = 0;
    for (int i = 0; i < n; i++)
    {
        if (check_char_digit6(c[i]))
        {
            bool flag = true;
            while (flag)
            {
                StringWithConst[counter] = c[i];
                counter++;
                i++;
                flag = check_char_digit6(c[i]);
            }
            StringWithConst[counter] = ' ';
            counter++;
            quantity++;
        }
    }
    int *a = new int [quantity];
    int j = 0;
    for (int i = 0; i < quantity; i++)
    {
        char *StringWithNumber = new char [n];
        int counter2 = 0;
        while (StringWithConst[j] != ' ')
        {
            StringWithNumber[counter2] = StringWithConst[j];
            j++;
            counter2++;
        }
        j++;
        a[i] = array_char_to_int6(StringWithNumber, counter2);
        delete StringWithNumber;
    }
    delete StringWithConst;
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
        while (s[i] == '.' && !(i > 0 && check_char_digit6(s[i-1]) || i < sSize - 1 && check_char_digit6(s[i+1])))
            i++;
        if (check_char_digit_or_point6(s[i]))
        {
            bool isDigitOrPoint = true;
            counter = 0;
            while (isDigitOrPoint)
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
                isDigitOrPoint = check_char_digit_or_point6(s[i]);
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
            while (1)
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
                        f = search_of_median6;
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

                delete_array(a);
                delete_array(b);

                if (!do_you_want_to_continue())
                    break;
            }
            break;
        }
        case 2:
        {
            while (1)
            {
                int nRowA; /// number of rows
                int nColumnA; /// number of columns
                int **a = cin_array_2(nRowA, nColumnA); /// input array
                int *x; /// row for insert
                int position; /// position of insert OR position of delete
                int** (*f)(int**, int*, int, int&, int); /// pointer for functions
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
                        while (position < 0 || position > nRowA)
                        {
                            cout << "Incorrect position (position >= 0 and position <= " << nRowA << ")" << endl;
                            cout << "Please, enter the number of position of this row in array" << endl;
                            cin >> position;
                        }
                        break;
                    }
                    case '2':
                    {
                        f = delete_row;
                        cout << "Please, enter number of row for deleting" << endl;
                        cin >> position;
                        if (position < 0 || position > nRowA - 1) /// TODO
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

                delete_array_2(a, nRowA);

                if (!do_you_want_to_continue())
                    break;
            }
            break;
        }
        case 3:
        {
            cout << "String or char? Please, enter 1 or 2" << endl;
            string answer;
            cin >> answer;
            if (answer == "1")
            {
                while (1)
                {
                    string s; /// string with decimal constants
                    cout << "Please, enter string" << endl;
                    cin >> s; /// Input
                    int quantity; /// quantity of constants
                    int *a; /// array with constants
                    a = search_of_decimal_constants6(s, quantity); /// Processing

                    cout << "Array with decimal constants:" << endl;
                    cout_array(a, quantity); /// Output

                    if (!do_you_want_to_continue())
                        break;
                }
            }
            else
            {
                while (1)
                {
                    cout << "Please, enter number of elements of array with char" << endl;
                    int n;
                    cin >> n; /// Input
                    cout << "Please, enter the elements of array with char" << endl;
                    char *c = new char [n]; /// array with char
                    for (int i = 0; i < n; i++)
                        cin >> c[i];
                    int quantity; /// quantity of constants
                    int *a; /// array with constants
                    a = search_of_decimal_constants_char6(c, n, quantity); /// Processing

                    cout << "Array with decimal constants:" << endl;
                    cout_array(a, quantity); /// Output

                    if (!do_you_want_to_continue())
                        break;
                }
            }
            break;
        }
        case 4:
        {
            while (1)
            {
                string s; /// string with real constants
                cout << "Please, enter string" << endl;
                cin >> s; /// Input
                int quantity; /// quantity of constants
                double *a; /// array with constants
                a = search_of_real_constants6(s, quantity); /// Processing

                cout << "Array with real constants:" << endl;
                cout_array_double(a, quantity); /// Output

                if (!do_you_want_to_continue())
                    break;
            }
            break;
        }
    }
    return 0;
}

