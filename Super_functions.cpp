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

