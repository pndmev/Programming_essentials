#include <iostream>
#include "StackStructArray.h"

using namespace std;

bool are_brackets_placed_correct(string str)
{
    int n = str_size(str);
    StackStructArray <char> S;

    for (int i = 0; i < n; i++)
    {
        switch (str[i])
        {
            case '(': case '[': case '{':
            {
                push(S, str[i]);
                break;
            }
            case ')':
            {
                if (top(S) == '(')
                    pop(S);
                else
                    return false;
                break;
            }
            case ']':
            {
                if (top(S) == '[')
                    pop(S);
                else
                    return false;
                break;
            }
            case '}':
            {
                if (top(S) == '{')
                    pop(S);
                else
                    return false;
                break;
            }
        }
    }
    if (empty(S) == true)
        return true;
    else
        return false;
}

bool isNextSymbolBracketOrAsteriskOrSlashOrEnd (int iSymbol, char symbol, int size)
{
    return iSymbol >= size || symbol == ')' || symbol == ']' || symbol == '}' || symbol == '*' || symbol == '/';
}

bool isPrevSymbolBracketOrBegin (int iSymbol, char symbol)
{
    return iSymbol < 0 || symbol == '(' || symbol == '[' || symbol == '{';
}

bool isSymbolDigit (char symbol)
{
    return symbol > 47 && symbol < 58;
}

bool is_it_mathematical_expression (string str)
{
    int SizeOfString = str_size(str);
    int QuantityNumbers = 0;
    for (int i = 0; i < SizeOfString; i++)
    {
        switch (str[i])
        {
            case '+': case '-':
            {
                if (isNextSymbolBracketOrAsteriskOrSlashOrEnd(i + 1, str[i + 1], SizeOfString) || (str[i + 1] == '-' || str[i + 1] == '+') && (i + 2 >= SizeOfString || !isSymbolDigit(str[i + 2])))
                    return false;
                break;
            }
            case '*': case '/':
            {
                if (isNextSymbolBracketOrAsteriskOrSlashOrEnd(i + 1, str[i + 1], SizeOfString))
                    return false;
                if (isPrevSymbolBracketOrBegin(i - 1, str[i - 1]))
                    return false;
                break;
            }
            case '(': case '[': case '{':
            {
                if (isNextSymbolBracketOrAsteriskOrSlashOrEnd(i + 1, str[i + 1], SizeOfString))
                    return false;
                if (isSymbolDigit(str[i - 1]))
                    return false;
                break;
            }
            case ')': case ']': case '}':
            {
                if (isPrevSymbolBracketOrBegin(i - 1, str[i - 1]))
                    return false;
                if (isSymbolDigit(str[i + 1]))
                    return false;
                break;
            }
            default:
            {
                if (!isSymbolDigit(str[i]))
                    return false;
                else
                    QuantityNumbers++;
                break;
            }
        }
    }
    if (QuantityNumbers == 0)
        return false;
    return true;
}

bool check_mathematical_expression (string str)
{
    if (!are_brackets_placed_correct(str))
    {
        cout << "Brackets aren't placed correct" << endl;
        return false;
    }
    if (!is_it_mathematical_expression(str))
    {
        cout << "It isn't mathematical expression" << endl;
        return false;
    }
    return true;
}

void modificationResultString (string &resultString, StackStructArray <char> &S)
{
    resultString += top(S);
    resultString += " ";
    pop(S);
}

string reverse_Polish_notation(string str)
{
    StackStructArray <char> S;
    string resultString;
    int sizeStr = str_size(str);
    for (int i = 0; i < sizeStr; i++)
    {
        if ((i - 1 < 0 || str[i - 1] == '(' || str[i - 1] == '[' || str[i - 1] == '{' || str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == '*' || str[i - 1] == '/') && (str[i] == '-' || str[i] == '+'))
        {
            string bufer;
            for (int j = 0; j < i; j++)
                bufer += str[j];
            bufer += "(0";
            sizeStr += 3;
            for (int j = i; j < sizeStr; j++)
                bufer += str[j];
            bufer += ")";
            str = bufer;
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
                    while (top(S) == '+' || top(S) == '-' || top(S) == '*' || top(S) == '/')
                    {
                        modificationResultString(resultString, S);
                    }
                    push(S, str[i]);
                    break;
                }
                case '*': case '/':
                {
                    while (top(S) == '*' || top(S) == '/')
                    {
                        modificationResultString(resultString, S);
                    }
                    push(S, str[i]);
                    break;
                }
                case '(': case '[': case '{':
                {
                    push(S, str[i]);
                    break;
                }
                case ')':
                {
                    while (top(S) != '(')
                    {
                        modificationResultString(resultString, S);
                    }
                    pop(S);
                    break;
                }
                case ']':
                {
                    while (top(S) != '[')
                    {
                        modificationResultString(resultString, S);
                    }
                    pop(S);
                    break;
                }
                case '}':
                {
                    while (top(S) != '{')
                    {
                        modificationResultString(resultString, S);
                    }
                    pop(S);
                    break;
                }
            }
        }
    }
    while (!empty(S))
    {
        resultString += top(S);
        pop(S);
    }
    return resultString;
}

int calculation_mathematical_expression (string str)
{
    str = reverse_Polish_notation(str);
    int sizeStr = str_size(str);
    StackStructArray <int> S;
    for (int i = 0; i < sizeStr; i++)
    {
        string bufer;
        while (str[i] > 47 && str[i] < 58)
        {
            bufer += str[i];
            i++;
        }
        if (bufer != "")
            push(S, string_to_int(bufer));
        else
        {
            int x = top(S);
            pop(S);
            switch (str[i])
            {
                case '+':
                {
                    x = top(S) + x;
                    pop(S);
                    break;
                }
                case '-':
                {
                    x = top(S) - x;
                    pop(S);
                    break;
                }
                case '*':
                {
                    x = top(S) * x;
                    pop(S);
                    break;
                }
                case '/':
                {
                    x = top(S) / x;
                    pop(S);
                    break;
                }
            }
            push(S, x);
        }
    }
    return top(S);
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

