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
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    else
        cout << "This array doesn't have elements" << endl;
}

void cout_array_double(double *a, int n)
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

void cout_array_char(char *a, int n)
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
    int middle = (left + right) / 2;

    while (right >= left)
    {
        while (a[right] > a[middle])
            right--;
        while (a[left] < a[middle])
            left++;
        if (left <= right)
        {
            my_swap(a[left], a[right]);
            left++;
            right--;
        }
    }
    if (0 < right)
    {
        quick_sort (a, right + 1);
    }
    if (left < n - 1)
    {
        quick_sort (a + left, n - left);
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

int string_to_int (string s)
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

bool do_you_want_to_continue ()
{
    cout << "Do you want to continue? Y or N" << endl;
    string answer;
    cin >> answer;
    return answer != "N" ? true: false;
}

void delete_array (int* a)
{
    delete a;
}

void delete_array_2 (int** a , int n)
{
    for (int i = 0; i < n; i++)
        delete a[i];
}

struct Node_char
{
    char data;
    Node_char *next;
};

struct My_stack_char
{
    Node_char *ptr;
};

struct Node_int
{
    int data;
    Node_int *next;
};

struct My_stack_int
{
    Node_int *ptr;
};

void add_My_stack_char (My_stack_char& s, char d)
{
    Node_char *newNode_char = new Node_char;
    newNode_char -> next = s.ptr;
    newNode_char -> data = d;
    s.ptr = newNode_char;
}

void add_My_stack_int (My_stack_int& s, int d)
{
    Node_int *newNode_int = new Node_int;
    newNode_int -> next = s.ptr;
    newNode_int -> data = d;
    s.ptr = newNode_int;
}

void delete_last_element_My_stack_char (My_stack_char& s)
{
    s.ptr = s.ptr -> next;
}

void delete_last_element_My_stack_int (My_stack_int& s)
{
    s.ptr = s.ptr -> next;
}

My_stack_char create_My_stack_char()
{
    char c;
    My_stack_char s;
    s.ptr = 0;
    while (do_you_want_to_continue())
    {
        cin >> c;
        add_My_stack_char(s, c);
    }
    return s;
}

void print_My_stack_char (My_stack_char& s)
{
    Node_char *p = s.ptr;
    while (p)
    {
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
}

int size_of_My_stack_char (My_stack_char& s)
{
    Node_char *p = s.ptr;
    int counter = 0;
    while (p)
    {
        counter++;
        p = p -> next;
    }
    return counter;
}

My_stack_char string_to_My_stack_char (string str)
{
    My_stack_char s;
    s.ptr = 0;
    int SizeOfStr = str_size(str);
    for (int i = 0; i < SizeOfStr; i++)
        add_My_stack_char(s, str[i]);
    return s;
}

char* My_stack_char_to_array (My_stack_char& s, int SizeOfStackChar)
{
    Node_char *p = s.ptr;
    char *a = new char [SizeOfStackChar];
    int i = 0;
    while (p)
    {
        a[i] = p -> data;
        p = p -> next;
        i++;
    }
    return a;
}
