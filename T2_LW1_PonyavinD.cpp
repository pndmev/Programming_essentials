#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <fstream>
#include <algorithm>
#include <numeric>

using namespace std;

class Initial
{
    public:
        char symbol;
        bool operator ()(string str){return str[0] == symbol;};
};

class NotInitial
{
    public:
        char symbol;
        bool operator ()(string str){return str[0] != symbol;};
};

class Equal
{
    public:
        int number;
        bool operator ()(int x){return number == x;};
};

class Greater
{
    public:
        int number;
        bool operator ()(int x){return x > number;};
};

int main()
{
    bool DoYouWantToContinue;
    do
    {
        cout << "Please, enter the number of task" << endl;
        int NumberOfTask = 0;
        while (!NumberOfTask)
            cin >> NumberOfTask;
        switch (NumberOfTask)
        {
            case 1:
            {
                vector <char> v;
                char symbol = 'a';
                for (int i = 0; i < 26; i++)
                {
                    v.push_back(symbol);
                    symbol++;
                }
                vector <char> :: iterator it;
                vector <char> :: reverse_iterator rit;
                for (it = v.begin(); it != v.end(); it++)
                    cout << *it << " ";
                cout << endl;
                for (rit = v.rbegin(); rit != v.rend(); rit++)
                    cout << *rit << " ";
                cout << endl;
                break;
            }
            case 2:
            {
                ifstream fin("input2.txt");
                list <string> l;
                while (!fin.eof())
                {
                    string bufer;
                    fin >> bufer;
                    l.push_back(bufer);
                }
                l.sort();
                list <string> :: iterator it;
                list <string> :: iterator not_it;
                for (it = l.begin(); it != l.end(); it++)
                    cout << *it << " ";
                cout << endl;

                cout << "Please, enter the symbol" << endl;
                char symbol;
                cin >> symbol;
                Initial initial;
                NotInitial not_initial;
                initial.symbol = symbol;
                not_initial.symbol = symbol;
                it = find_if(l.begin(), l.end(), initial);
                if (it != l.end())
                {
                    not_it = find_if(it, l.end(), not_initial);
                    for (; it != not_it; it++)
                        cout << *it << " ";
                    cout << endl;
                    l.erase(it, not_it);
                    for (it = l.begin(); it != l.end(); it++)
                        cout << *it << " ";
                    cout << endl;
                }
                else
                {
                    cout << "Not found" << endl;
                }
                break;
            }
            case 3:
            {
                ifstream fin("input3.txt");
                deque <int> d;
                while (!fin.eof())
                {
                    int bufer;
                    fin >> bufer;
                    d.push_back(bufer);
                }
                cout << "Please, enter the number" << endl;
                int number;
                cin >> number;
                Equal equal;
                equal.number = number;
                int equalNumber = count_if(d.begin(), d.end(), equal);
                cout << equalNumber << " numbers = " << number << endl;

                cout << "Please, enter the number" << endl;
                cin >> number;
                Greater greater;
                greater.number = number;
                int greaterNumber = count_if(d.begin(), d.end(), greater);
                cout << greaterNumber << " numbers > " << number << endl;

                int quantity = d.size();
                cout << "Quantity of numbers = " << quantity << endl;

                int sum = accumulate(d.begin(), d.end(), 0);
                cout << "Sum of numbers = " << sum << endl;

                double AM = double(sum) / quantity;
                cout << "Arithmetic middling of numbers = " << AM << endl;
                break;
            }
        }
        cout << "Do you want to continue?" << endl;
        string answer;
        cin >> answer;
        DoYouWantToContinue = !(answer == "NO");
    }
    while (DoYouWantToContinue);
    return 0;
}
