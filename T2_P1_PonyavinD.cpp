#include <iostream>
#include <forward_list>
#include <algorithm>

using namespace std;

template <class T>
class Array;
template <class T>
class ArrayIterator;

template <class T>
class Array
{
    private:
        forward_list <T> List;
    public:
        T& operator [](int);
        T& back(){return (*this)[size() - 1];};
        T& front(){return *List.begin();};
        bool empty(){return List.empty();};
        int size(){return distance(List.begin(), List.end());};
        ArrayIterator <T> begin(){ArrayIterator <T> ai(List.begin()); return ai;};
        ArrayIterator <T> end(){ArrayIterator <T> ai(List.end()); return ai;};
        void insert(ArrayIterator <T>, T);
        void erase(ArrayIterator <T> ai);
        void push_back(T t){insert(end(), t);};
        void push_front(T t){List.push_front(t);};
        void pop_back(){erase(begin() + (size() - 1));};
        void pop_front(){List.pop_front();};
};

template <class T>
T& Array<T> :: operator [](int position)
{
    ArrayIterator <T> it = List.begin();
    for (int i = 0; i < position; i++)
        it++;
    return *it;
}

template <class T>
void Array<T> :: insert (ArrayIterator <T> ai, T t)
{
    if (ai == begin())
        push_front(t);
    else
    {
        if (ai == end())
        {
            ArrayIterator <T> it;
            it = begin() + (size() - 1);
            List.insert_after(it.it, t);
        }
        else
        {
            List.insert_after(ai.it, t);
            ArrayIterator <T> next(ai);
            next++;
            *next = *ai;
            *ai = t;
        }
    }
}

template <class T>
void Array<T> :: erase (ArrayIterator <T> ai)
{
    if (ai == begin())
        pop_front();
    else
    {
        ArrayIterator <T> it;
        it = begin() + (distance(List.begin(), ai.it) - 1);
        List.erase_after(it.it);
    }
}

template <class T>
class ArrayIterator
{
    friend class Array <T>;
    private:
        typename forward_list <T> :: iterator it;
    public:
        ArrayIterator(){;};
        ArrayIterator(const typename forward_list <T> :: iterator &other){it = other;};
        ArrayIterator(const ArrayIterator <T> &other){it = other.it;};
        bool operator != (ArrayIterator <T> other){return it != other.it;};
        bool operator == (ArrayIterator <T> other){return it == other.it;};
        T& operator * (){return *it;}
        ArrayIterator& operator ++(int){it++; return *this;};
        ArrayIterator& operator +(int n){for (int i = 0; i < n; i++) it++; return *this;}
};

void printArray (Array <int> A)
{
    cout << "Your array:" << endl;
    ArrayIterator <int> it;
    for (it = A.begin(); it != A.end(); it++)
        cout << *it << " ";
    cout << endl;
}

int main()
{
    Array <int> A;
    cout << "Please, enter the quantity of elements" << endl;
    int quantity;
    cin >> quantity;
    int bufer;
    cout << "Please, enter the elements of array" << endl;
    for (int i = 0; i < quantity; i++)
    {
        cin >> bufer;
        A.push_back(bufer);
    }
    printArray(A);
    cout << "Please, enter the value for inserting" << endl;
    cin >> bufer;
    cout << "Please, enter the number of position for inserting" << endl;
    int position;
    cin >> position;
    A.insert(A.begin() + position, bufer);
    printArray(A);
    cout << "Please, enter the number of element for modification" << endl;
    cin >> position;
    cout << "Please, enter new value for this element" << endl;
    cin >> bufer;
    A[position] = bufer;
    printArray(A);
    cout << "Please, enter the number of position for deleting" << endl;
    cin >> position;
    A.erase(A.begin() + position);
    printArray(A);
    if (!A.empty())
    {
        cout << "Array without last element:" << endl;
        A.pop_back();
        printArray(A);
    }
    if (!A.empty())
    {
        cout << "Array without first element:" << endl;
        A.pop_front();
        printArray(A);
    }
    return 0;
}
