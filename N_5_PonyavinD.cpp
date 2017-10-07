#include <iostream>

using namespace std;

int number_of_minimal_element5 (int *a, int n, int begin)
{
    int MinimalElement = a[begin]; /// minimal element in array
    int NumberOfMinimalElement = begin; /// number of minimal element in array
    for (int i = begin + 1; i < n; i++)
        if (a[i] < MinimalElement)
        {
            MinimalElement = a[i];
            NumberOfMinimalElement = i;
        }
    return NumberOfMinimalElement;
}

void buble_sort5 (int *a, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = n - 1; j > i; j--)
            if (a[j] < a[i])
                swap(a[j], a[i]);
}

void selection_sort5 (int *a, int n)
{
    int NumberOfMinimalElement; /// number of minimal element in array
    for (int i = 0; i < n; i++)
    {
        NumberOfMinimalElement = number_of_minimal_element5(a, n, i);
        if (a[i] != a[NumberOfMinimalElement])
            swap(a[i], a[NumberOfMinimalElement]);
    }
}

int sum_line5 (int **a, int n, int NumberOfLine)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[NumberOfLine][i];
    return sum;
}

int sum_column5 (int **a, int n, int NumberOfColumn)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i][NumberOfColumn];
    return sum;
}

int binary_search5(int *a, int left, int right, int x)
{
    int middle;
    while (1)
    {
        middle = (left + right) / 2;
        if (x < a[middle])
            right = middle - 1;
        else
            if (x > a[middle])
                left = middle + 1;
            else
                return middle;

        if (left > right)
            return left;
    }
}

void insert_sort5 (int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int index = binary_search5(a, 0, i - 1, a[i]); /// index
        int x = a[i]; /// variable
        for (int j = i; j > index; j--)
            a[j] = a[j - 1];
        a[index] = x;
    }
}

int* check_subset5(int *A, int nA, int *B, int nB)
{
    if (nB > nA)
        return 0;
    if (nB == 1 && B[0] == A[nA - 1])
        return &A[nA - 1];
    int quantity = 0; /// quantity of identical elements in arrays A and B
    int index = 0; /// index

    for (int i = 0; i < nA - nB; i++)
    {
        if (B[0] == A[i])
        {
            index = i;
            quantity++;
            for (int j = 1; j < nB; j++)
            {
                if (B[j] == A[i + j])
                    quantity++;
                else
                    if (B[j] > A[i + j])
                    {
                        i++;
                        j--;
                    }
                    else
                        return 0;
            }

            if (quantity == nB)
            {
                return &A[0] + index;
            }
            else
                return 0;
        }
    }
}

int main5()
{
    int number = 0;
    cout << "Please, enter the number of task ( 1, 2, 3, 4, 5 )" << endl;
    cout << "1. Array with integers: sort on increase (bubble sort)" << endl;
    cout << "2. Array with integers: minimal element + sort on increase (selection sort)" << endl;
    cout << "3. Is square matrix magic square?" << endl;
    cout << "4. Binary search of the location of a new element in the ordered array + return the index to the place of inclusion of a new element + insert sort" << endl;
    cout << "5. Is the array B a subset of an array A? Return the index for the beginning of the found fragment. If there is no element, returns 0" << endl;
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
            int *a = new int [n]; /// array with integers
            cout << "Please, enter elements of array" << endl;
            for (int i = 0; i < n; i++)
                cin >> a[i];

            buble_sort5(a, n);
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            break;
        }
        case 2:
        {
            int n; /// number of elements
            cout << "Please, enter the number of elements of array" << endl;
            cin >> n;
            int *a = new int [n]; /// array with integers
            cout << "Please, enter elements of array" << endl;
            for (int i = 0; i < n; i++)
                cin >> a[i];

            selection_sort5(a, n);
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            break;
        }
        case 3:
        {
            int n; /// number of elements
            cout << "Please, enter the number of line in square matrix" << endl;
            cin >> n;
            int** a = new int*[n]; /// array with integers
            for(int i = 0; i < n; i++)
                a[i] = new int[n];
            cout << "Please, enter elements of array" << endl;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    cin >> a[i][j];
            int sum = sum_line5(a, n, 0); /// value of sum of first line
            /// Processing and check (line)
            for (int i = 1; i < n; i++)
                if (sum_line5(a, n, i) != sum)
                {
                    cout << "This matrix is not magic square" << endl;
                    return 0;
                }
            /// Processing and check (column)
            for (int i = 0; i < n; i++)
                if (sum_column5(a, n, i) != sum)
                {
                    cout << "This matrix is not a magic square" << endl;
                    return 0;
                }
            cout << "This matrix is a magic square" << endl;
            break;
        }
        case 4:
        {
            int n; /// number of elements
            cout << "Please, enter the number of elements of array" << endl;
            cin >> n;
            int *a = new int [n]; /// array with integers
            cout << "Please, enter elements of array" << endl;
            for (int i = 0; i < n; i++)
                cin >> a[i];

            insert_sort5(a, n);
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            break;
        }
        case 5:
        {
            int nA; /// number of elements of array A
            cout << "Please, enter the number of elements of array A" << endl;
            cin >> nA;
            int *A = new int [nA]; /// array A with integers
            cout << "Please, enter elements of array A" << endl;
            for (int i = 0; i < nA; i++)
                cin >> A[i];

            int nB; /// number of elements of array B
            cout << "Please, enter the number of elements of array B" << endl;
            cin >> nB;
            int *B = new int [nB]; /// array B with integers
            cout << "Please, enter elements of array B" << endl;
            for (int i = 0; i < nB; i++)
                cin >> B[i];

            /// Sorting
            insert_sort5(A, nA);
            insert_sort5(B, nB);

            cout << "Sorted array A: ";
            for (int i = 0; i < nA; i++)
                cout << A[i] << " ";
            cout << endl;

            cout << "Sorted array B: ";
            for (int i = 0; i < nB; i++)
                cout << B[i] << " ";
            cout << endl;

            cout << check_subset5(A, nA, B, nB) << endl;
            break;
        }
    }
    return 0;
}

