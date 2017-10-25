#include <iostream>

using namespace std;

bool are_brackets_placed_correct (string str)
{
    My_stack_char s;
    add_My_stack_char(s, '|');
    int SizeOfString = str_size(str);
    for (int i = 0; i < SizeOfString; i++)
    {
        switch (str[i])
        {
            case '(': case '[': case '{':
            {
                add_My_stack_char(s, str[i]);
                break;
            }
            case ')':
            {
                if (s.ptr -> data == '(')
                    delete_last_element_My_stack_char(s);
                else
                    return false;
                break;
            }
            case ']':
            {
                if (s.ptr -> data == '[')
                    delete_last_element_My_stack_char(s);
                else
                    return false;
                break;
            }
            case '}':
            {
                if (s.ptr -> data == '{')
                    delete_last_element_My_stack_char(s);
                else
                    return false;
                break;
            }
        }
    }
    return true;
}

bool is_it_mathematical_expression (string str)
{
    int SizeOfString = str_size(str);
    int QuantityOperators = 0;
    int QuantityNumbers = 0;
    for (int i = 0; i < SizeOfString; i++)
    {
        switch (str[i])
        {
            case '+': case '-':
            {
                QuantityOperators++;
                if (i + 1 >= SizeOfString || str[i + 1] == ')' || str[i + 1] == ']' || str[i + 1] == '}' || str[i + 1] == '+' || str[i + 1] == '-')
                    return false;
                break;
            }
            case '*': case '/':
            {
                QuantityOperators++;
                if (i + 1 >= SizeOfString || str[i + 1] == ')' || str[i + 1] == ']' || str[i + 1] == '}' || str[i + 1] == '*' || str[i + 1] == '/')
                    return false;
                if (i - 1 < 0 || str[i - 1] == '(' || str[i - 1] == '[' || str[i - 1] == '{')
                    return false;
                break;
            }
            case '(': case '[': case '{':
            {
                if (str[i + 1] == ')' || str[i + 1] == ']' || str[i + 1] == '}')
                    return false;
                if (str[i - 1] >= 47 && str[i - 1] <= 58)
                    return false;
                break;
            }
            case ')': case ']': case '}':
            {
                if (str[i + 1] == '(' || str[i + 1] == '[' || str[i + 1] == '{')
                    return false;
                if (str[i + 1] >= 47 && str[i + 1] <= 58)
                    return false;
                break;
            }
            default:
            {
                if (str[i] < 48 || str[i] > 57)
                    return false;
                else
                    QuantityNumbers++;
                break;
            }
        }
    }
    if (QuantityNumbers * QuantityOperators == 0)
        return false;
    return true;
}

bool check_mathematical_expression (string str)
{
    if (!is_it_mathematical_expression(str))
    {
        cout << "It isn't mathematical expression" << endl;
        return false;
    }
    if (!are_brackets_placed_correct(str))
    {
        cout << "Brackets aren't placed correct" << endl;
        return false;
    }
    return true;
}

string reverse_Polish_notation(string str)
{
    My_stack_char s; /// stack with operators
    add_My_stack_char(s, '|');
    string resultString;
    int sizeStr = str_size(str);
    for (int i = 0; i < sizeStr; i++)
    {
        if ((i - 1 < 0 || str[i - 1] == '(' || str[i - 1] == '[') && (str[i] == '-' || str[i] == '+'))
        {
            string bufer;
            for (int j = 0; j < i; j++)
                bufer += str[j];
            bufer += "0";
            sizeStr++;
            for (int j = i; j < sizeStr; j++)
                bufer += str[j];
            str = bufer;
            i--;
        }
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
                case '(': case '[': case '{':
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
                case ']':
                {
                    while (s.ptr -> data != '[')
                    {
                        resultString += s.ptr -> data;
                        resultString += " ";
                        delete_last_element_My_stack_char(s);
                    }
                    delete_last_element_My_stack_char(s);
                    break;
                }
                case '}':
                {
                    while (s.ptr -> data != '{')
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

            if (are_brackets_placed_correct(str))
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
            while (!check_mathematical_expression(str))
            {
                cout << "Please, enter the mathematical expression" << endl;
                cin >> str; /// Input
            }
            cout << calculation_mathematical_expression(str);
            break;
        }
    }
    return 0;
}

