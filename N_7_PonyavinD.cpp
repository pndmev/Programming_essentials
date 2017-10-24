#include <iostream>

using namespace std;

bool are_brackets_placed_correct (My_stack_char s)
{
    string StringWithBrackets;
    int counter[2] = {0, 0};
    Node_char *p = s.ptr;
    while (p)
    {
        switch (p -> data)
        {
            case '(': case ')': case '[': case ']':
            {
                StringWithBrackets += p -> data;
                Node_char *pp = p -> next;
                break;
            }
        }
        p = p -> next;
    }
    int SizeOfString = str_size(StringWithBrackets);
    cout << StringWithBrackets << endl;
    for (int i = 0; i < SizeOfString; i++)
        switch (StringWithBrackets[i])
        {
            case '(':
            {
                if (StringWithBrackets[i + 1] == ']')
                    return false;
                counter[0]++;
                break;
            }
            case ')':
            {
                if (StringWithBrackets[i - 1] == '[')
                    return false;
                counter[0]--;
                break;
            }
            case '[':
            {
                if (StringWithBrackets[i + 1] == ')')
                    return false;
                counter[1]++;
                break;
            }
            case ']':
            {
                if (StringWithBrackets[i - 1] == '(')
                    return false;
                counter[1]--;
                break;
            }
        }
    if (counter[0] == 0 && counter [1] == 0)
        return true;
    else
        return false;
}



string reverse_Polish_notation(string str)
{
    My_stack_char s; /// stack with operators
    add_My_stack_char(s, '|');
    string resultString;
    int sizeStr = str_size(str);
    for (int i = 0; i < sizeStr; i++)
    {
        if (str[i] > 47 && str[i] < 58)
        {
            resultString += str[i];
            if (str[i + 1] < 48 || str[i + 1] > 57)
                resultString += " ";
        }
        else
        {
            switch (str[i])
            {
                case '+': case '-':
                {
                    while (s.ptr -> data == '+' || s.ptr -> data == '-' || s.ptr -> data == '*' || s.ptr -> data == '/')
                    {
                        resultString += s.ptr -> data;
                        resultString += " ";
                        delete_last_element_My_stack_char(s);
                    }
                    add_My_stack_char(s, str[i]);
                    break;
                }
                case '*': case '/':
                {
                    while (s.ptr -> data == '*' || s.ptr -> data == '/')
                    {
                        resultString += s.ptr -> data;
                        resultString += " ";
                        delete_last_element_My_stack_char(s);
                    }
                    add_My_stack_char(s, str[i]);
                    break;
                }
                case '(':
                {
                    add_My_stack_char(s, str[i]);
                    break;
                }
                case ')':
                {
                    while (s.ptr -> data != '(')
                    {
                        resultString += s.ptr -> data;
                        resultString += " ";
                        delete_last_element_My_stack_char(s);
                    }
                    delete_last_element_My_stack_char(s);
                    break;
                }
            }
        }
    }
    while (s.ptr -> data != '|')
    {
        resultString += s.ptr -> data;
        delete_last_element_My_stack_char(s);
    }
    return resultString;
}

int calculation_mathematical_expression (string str)
{
    str = reverse_Polish_notation(str);
    int sizeStr = str_size(str);
    My_stack_int s;
    s.ptr = 0;
    for (int i = 0; i < sizeStr; i++)
    {
        string bufer;
        while (str[i] > 47 && str[i] < 58)
        {
            bufer += str[i];
            i++;
        }
        if (bufer != "")
            add_My_stack_int(s, string_to_int(bufer));
        else
        {
            switch (str[i])
            {
                case '+':
                {
                    int x = s.ptr -> data;
                    delete_last_element_My_stack_int(s);
                    s.ptr -> data += x;
                    break;
                }
                case '-':
                {
                    int x = s.ptr -> data;
                    delete_last_element_My_stack_int(s);
                    s.ptr -> data -= x;
                    break;
                }
                case '*':
                {
                    int x = s.ptr -> data;
                    delete_last_element_My_stack_int(s);
                    s.ptr -> data *= x;
                    break;
                }
                case '/':
                {
                    int x = s.ptr -> data;
                    delete_last_element_My_stack_int(s);
                    s.ptr -> data /= x;
                    break;
                }
            }
        }
    }
    return s.ptr -> data;
}

int main7()
{
    int number = 0;
    cout << "Please, enter the number of task ( 1, 2, 3, 4, 5 )" << endl;
    cout << "1. Input: mathematical expression X. Are brackets () and [] placed correct?" << endl;
    cout << "2. Input: mathematical expression X (only integers, +, -, *, /). X = ?" << endl;
    cout << "3. Input: mathematical expression X (only integers, +, -, *, / and brackets () and []). X = ?" << endl;
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
            string str; /// string with mathematical expression
            cout << "Please, enter the mathematical expression" << endl;
            cin >> str; /// Input
            My_stack_char s = string_to_My_stack_char(str); /// String to stack with char

            int n = size_of_My_stack_char(s); /// number of elements of array
            char *a = My_stack_char_to_array(s, n); /// Create array with char
            cout_array_char(a, n); /// Output array with char

            if (are_brackets_placed_correct(s))
                cout << "Brackets are placed correct" << endl;
            else
                cout << "Brackets aren't placed correct" << endl;
            break;
        }
        case 2: case 3:
        {
            string str; /// string with mathematical expression
            cout << "Please, enter the mathematical expression" << endl;
            cin >> str; /// Input

            cout << calculation_mathematical_expression(str);
            break;
        }
    }
    return 0;
}

