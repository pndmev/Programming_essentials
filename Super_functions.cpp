#include <iostream>

using namespace std;

int* cin_array(int &n)
{
    cout << "Please, enter the number of elements of array" << endl;
    cin >> n;
    int *a = new int [n];
    cout << "Please, enter elements of array" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    return a;
}

int** cin_array_2(int &nRow, int &nColumn)
{
    cout << "Please, enter the number of rows in array" << endl;
    cin >> nRow;
    cout << "Please, enter the number of columns in array" << endl;
    cin >> nColumn;
    int** a = new int*[nRow];
    for(int i = 0; i < nRow; i++)
        a[i] = new int[nColumn];
    cout << "Please, enter elements of array" << endl;
    for (int i = 0; i < nRow; i++)
        for (int j = 0; j < nColumn; j++)
            cin >> a[i][j];
    return a;
}

int** cin_square_matrix(int &n)
{
    cout << "Please, enter the number of rows in square matrix" << endl;
    cin >> n;
    int** a = new int*[n];
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

void cout_array_double(double *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void cout_array_2(int **a, int nRow, int nColumn)
{
    for (int i = 0; i < nRow; i++)
    {
        for (int j = 0; j < nColumn; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int *copy_array (int *a, int n)
{
    int *b = new int [n];
    for (int i = 0; i < n; i++)
        b[i] = a[i];
    return b;
}

int **copy_array_2 (int **a, int nRow, int nColumn)
{
    int** b = new int*[nRow]; /// array with integers
    for(int i = 0; i < nRow; i++)
        b[i] = new int[nColumn];

    for (int i = 0; i < nRow; i++)
        for (int j = 0; j < nColumn; j++)
            b[i][j] = a[i][j];
    return b;
}

void my_swap (int &a, int &b)
{
    int bufer = a;
    a = b;
    b = bufer;
}

void buble_sort (int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (a[j] > a[j + 1])
                my_swap(a[j], a[j + 1]);
        }
    }
}

void shaker_sort (int *a, int n)
{
    int left = 0;
    int right = n - 1;
    for (left = 0; left < right; left++)
    {
        for (int i = left; i < right; i++)
        {
            if (a[i] > a[i + 1])
                my_swap(a[i], a[i + 1]);
        }
        right--;
        for (int i = right; i > left; i--)
        {
            if (a[i] < a[i - 1])
                my_swap(a[i], a[i - 1]);
        }
    }
}

void quick_sort (int *a, int n)
{
    int left = 0;
    int right = n - 1;
    int middle = n / 2;

    while (left < right)
    {
        while (a[left] <= a[middle])
            left++;
        while (a[right] >= a[middle])
            right--;
        if (left < right)
            my_swap(a[left], a[right]);
    }
    if (left > 0)
    {
        quick_sort (a + left, middle);
    }
    if (right < n - 1)
    {
        quick_sort (a + middle, right);
    }
}

int number_of_minimal_element (int *a, int n)
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

void selection_sort (int *a, int n)
{
    int NumberOfMinimalElement; /// number of minimal element in array
    for (int i = 0; i < n; i++)
    {
        NumberOfMinimalElement = number_of_minimal_element(a + i, n - i) + i;
        if (a[i] != a[NumberOfMinimalElement])
            my_swap(a[i], a[NumberOfMinimalElement]);
    }
}

int* my_binary_search(int *a, int left, int right, int x)
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

void insert_sort (int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int *ptr = my_binary_search(a, 0, i - 1, a[i]); /// index
        int x = a[i]; /// variable
        for (int j = i; j > ptr - &a[0]; j--)
            a[j] = a[j - 1];
        *ptr = x;
    }
}

int str_size(string s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;

}
