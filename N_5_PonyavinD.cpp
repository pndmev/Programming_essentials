#include <iostream>

using namespace std;

int* cin_array(int &n)
{
    cout << "Please, enter the number of elements of array" << endl;
    cin >> n;
    int *a = new int [n]; /// array with integers
    cout << "Please, enter elements of array" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    return a;
}

int** cin_square_matrix(int &n)
{
    cout << "Please, enter the number of rows in square matrix" << endl;
    cin >> n;
    int** a = new int*[n]; /// array with integers
    for(int i = 0; i < n; i++)
        a[i] = new int[n];
    cout << "Please, enter elements of matrix" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    return a;
}

void cout_array(int *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void swap5 (int &a, int &b)
{
    int bufer = a;
    a = b;
    b = bufer;
}

int number_of_minimal_element5 (int *a, int n)
{
    int MinimalElement = *a; /// minimal element in array
    int NumberOfMinimalElement = 0; /// number of minimal element in array
    for (int i = 1; i < n; i++)
        if (*(a + i) < MinimalElement)
        {
            MinimalElement = *(a + i);
            NumberOfMinimalElement = i;
        }
    return NumberOfMinimalElement;
}

void buble_sort5 (int *a, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = n - 1; j > i; j--)
            if (a[j] < a[i])
                swap5(a[j], a[i]);
}

void selection_sort5 (int *a, int n)
{
    int NumberOfMinimalElement; /// number of minimal element in array
    for (int i = 0; i < n; i++)
    {
        NumberOfMinimalElement = number_of_minimal_element5(a + i, n - i) + i;
        if (a[i] != a[NumberOfMinimalElement])
            swap5(a[i], a[NumberOfMinimalElement]);
    }
}

int sum_row5 (int *a, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

int sum_column5 (int **a, int n, int NumberOfColumn)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i][NumberOfColumn];
    return sum;
}

int* binary_search5(int *a, int left, int right, int x)
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
                return &a[0] + middle;

        if (left > right)
            return &a[0] + left;
    }
}

void insert_sort5 (int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int *ptr = binary_search5(a, 0, i - 1, a[i]); /// index
        int x = a[i]; /// variable
        for (int j = i; j > ptr - &a[0]; j--)
            a[j] = a[j - 1];
        *ptr = x;
    }
}

bool check_magic_square (int **a, int n)
{
    int sum = sum_row5(a[0], n); /// value of sum of first line
    /// Processing and check (line)
    for (int i = 1; i < n; i++)
        if (sum_row5(a[i], n) != sum)
        {
            return false;
        }
    /// Processing and check (column)
    for (int i = 0; i < n; i++)
        if (sum_column5(a, n, i) != sum)
        {
            return false;
        }
    return true;
}

int* check_subset5(int *A, int nA, int *B, int nB)
{
    if (nB > nA)
        return 0;
    if (nB == 1 && B[0] == A[nA - 1])
        return &A[nA - 1];
    int quantity = 0; /// quantity of identical elements in arrays A and B
    int index = 0; /// index

    for (int i = 0; i < nA; i++)
    {
        if (B[0] == A[i])
        {
            index = i;
            quantity++;
            if (nA - i < nB)
                return 0;
            for (int j = 1; j < nB; j++)
            {
                if (B[j] == A[i + j])
                    quantity++;
                else
                    if (B[j] < A[i + j])
                        return 0;
                    else
                        if (i + j < nA - 1)
                        {
                            i++;
                            j--;
                        }

            }

            if (quantity == nB)
            {
                return &A[0] + index;
            }
            else
                return 0;
        }
        else
            if (i == nA - 1)
                return 0;
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
    cout << "5. Is the array B a subset of an array A? Return the pointer for the beginning of the found fragment. If there is no element, returns 0" << endl;
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
            int *a = cin_array(n); /// Input
            buble_sort5(a, n); /// Bubble sorting
            cout_array(a, n); /// Output
            break;
        }
        case 2:
        {
            int n; /// number of elements
            int *a = cin_array(n); /// Input
            selection_sort5(a, n); /// Selection sorting
            cout_array(a, n); /// Output
            break;
        }
        case 3:
        {
            int n; /// number of elements
            int **a = cin_square_matrix(n); /// Input
            if (check_magic_square(a, n))
                cout << "This matrix is magic square" << endl;
            else
                cout << "This matrix is not magic square" << endl;
            break;
        }
        case 4:
        {
            int n; /// number of elements
            int *a = cin_array(n); /// Input
            insert_sort5(a, n); /// Insert sorting
            cout_array(a, n); /// Output
            break;
        }
        case 5:
        {
            int nA; /// number of elements of array A
            cout << "Array A:" << endl;
            int *A = cin_array(nA); /// Input A

            int nB; /// number of elements of array B
            cout << "Array B:" << endl;
            int *B = cin_array(nB); /// Input B

            /// Sorting
            insert_sort5(A, nA);
            insert_sort5(B, nB);

            /// Output 1
            cout << "Sorted array A: ";
            cout_array(A, nA);

            cout << "Sorted array B: ";
            cout_array(B, nB);

            /// Processing and output result
            int *ptr = check_subset5(A, nA, B, nB);
            if (ptr != 0)
                cout << ptr << " - pointer of element " << *ptr << endl;
            else
                cout << ptr << endl;
            break;
        }
    }
    return 0;
}

