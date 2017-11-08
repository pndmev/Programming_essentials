#include <iostream>

///1. Из текста удалить все слова заданной длины, начинающиеся на согласную.
///2. Дана матрица размера m x n. Перестроить матрицу, переставляя в ней строки так,
/// чтобы сумма элементов в строках полученной матрицы возрастала.

using namespace std;

void cin_char_array(char *str, int& strSize)
{
    for (int i = 0; i < strSize; i++)
    {
        cin >> str[i];
    }
}

void cout_char_array(char *str, int& strSize)
{
    for (int i = 0; i < strSize; i++)
    {
        cout << str[i];
    }
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

bool check_symbol (char c)
{
    switch (c)
    {
        case ' ': case ',': case '.': case ';': case ':': case '!': case '?': case '(': case ')': case '/n': case '/t':
        {
            return true;
            break;
        }
    }
    return false;
}

void deleting (char *str, int& strSize, int &length)
{
    char agreeSymbols[21] = {'q', 'w', 'r', 't', 'y', 'p', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm'};
    for (int i = 0; i < strSize; i++)
    {
        bool flag = check_symbol(str[i - 1]) || i == 0;
        if (flag)
        {
            flag = false;
            for (int j = 0; j < 21; j++)
            {
                if (str[i] == agreeSymbols[j])
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                flag = false;
                if (i + length <= strSize)
                {
                    for (int j = i + 1; j < i + length; j++)
                    {
                        flag = check_symbol(str[j]);

                        if (j != i + length - 1 && flag)
                        {
                            flag = false;
                            break;
                        }
                    }
                }
                else
                    flag = false;
                if (flag)
                {
                    for (int j = i; j <= strSize; j++)
                    {
                        str[j] = str[j + length];
                    }
                    strSize -= length;

                }
            }
        }

    }
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

void my_swap (int &a, int &b)
{
    int bufer = a;
    a = b;
    b = bufer;
}

void cout_array(int *a, int n)
{
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    else
        cout << "This array doesn't have elements" << endl;
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

int main()
{
    int NumberOfTask = 0;
    cout << "Please, enter the number of task (1 or 2)" << endl;
    cin >> NumberOfTask;
    switch (NumberOfTask)
    {
        case 1:
        {
            int strSize;
            cout << "Please, enter the number of symbols in text" << endl;
            cin >> strSize;

            char *str = new char [strSize];
            cout << "Please, enter the text" << endl;
            cin_char_array(str, strSize);

            int length;
            cout << "Please, enter the length of words for deleting" << endl;
            cin >> length;

            deleting(str, strSize, length);
            cout_char_array(str, strSize);

            delete str;
            break;
        }
        case 2:
        {
            int m, n;
            int **a = cin_array_2(m, n);
            int *sum = new int [m];
            int *copySum = new int [m];


            for (int i = 0; i < m; i++)
            {
                sum[i] = 0;
                for (int j = 0; j < n; j++)
                    sum[i] += a[i][j];
            }

            for (int i = 0; i < m; i++)
            {
                copySum[i] = sum[i];
            }

            shaker_sort(sum, m);
            int counter = 0;
            int *arrayIndex = new int [m];
            while (counter < m)
            {
                for (int i = 0; i < m; i++)
                    if (copySum[i] == sum[counter])
                    {
                        arrayIndex[counter] = i;
                        counter++;
                    }
            }

            int **b = new int* [m];
            for (int i = 0; i < m; i++)
                b[i] = a[arrayIndex[i]];

            cout_array_2(b, m, n);
            break;
        }
    }
    return 0;
}
