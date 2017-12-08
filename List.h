/// List
template <typename T>
class List
{
    struct Node
    {
        T data;
        Node *next;
    };

    Node *firstElement;
    Node *lastElement;
    int sizeList = 0;

    public:
        List(){;};
        void push_back(T);
        void push_front(T);
        void insert(T, int);
        void pop_back();
        void pop_front();
        void erase(int);
        void new_data(T, int);
        T element(int);
        T first();
        T last();
        bool empty();
        int size();
        void destroy();
        ~List(){};
};

template <typename T>
void List <T> :: push_back (T d)
{
    Node *newNode = new Node;
    newNode -> data = d;
    if (!sizeList)
    {
        firstElement = newNode;
    }
    else
        newNode -> next = lastElement;
    lastElement = newNode;
    sizeList++;
}

template <typename T>
void List <T> :: push_front (T d)
{
    Node *newNode = new Node;
    newNode -> data = d;
    if (!sizeList)
    {
        lastElement = newNode;
    }
    else
        firstElement -> next = newNode;
    firstElement = newNode;
    sizeList++;
}

template <typename T>
void List <T> :: insert (T d, int p)
{
    if (p < sizeList + 1 && p > -1)
    {
        Node *newNode = new Node;
        newNode -> data = d;
        if (p == 0)
        {
            if (!sizeList)
            {
                lastElement = newNode;
            }
            else
                firstElement -> next = newNode;
            firstElement = newNode;
        }
        else
            if (p == sizeList)
            {
                if (!sizeList)
                {
                    firstElement = newNode;
                }
                else
                    newNode -> next = lastElement;
                lastElement = newNode;
            }
            else
            {
                Node* ptr = lastElement;
                for (int i = sizeList - 1; i > p + 1; i--)
                {
                    ptr = ptr -> next;
                }
                newNode -> next = ptr -> next;
                ptr -> next = newNode;
            }
        sizeList++;
    }
}

template <typename T>
void List <T> :: pop_back ()
{
    if (sizeList)
    {
        delete lastElement;
        sizeList--;
    }
}

template <typename T>
void List <T> :: pop_front ()
{
    if (sizeList)
    {
        delete firstElement;
        sizeList--;
    }
}

template <typename T>
void List <T> :: erase (int p)
{
    if (p < sizeList && p > -1)
    {
        if (p == 0)
        {
            delete firstElement;
        }
        else
            if (p == sizeList - 1)
            {
                delete lastElement;
            }
            else
            {
                Node* ptr = lastElement;
                for (int i = sizeList - 1; i > p + 1; i--)
                    ptr = ptr -> next;
                Node* temp = ptr -> next;
                ptr -> next = temp -> next;
                delete temp;
            }
        sizeList--;
    }
}

template <typename T>
void List <T> :: new_data (T nd, int p)
{
    Node* ptr = lastElement;
    for (int i = sizeList - 1; i > p; i--)
        ptr = ptr -> next;
    ptr -> data = nd;
}

template <typename T>
T List <T> :: element (int p)
{
    Node* ptr = lastElement;
    for (int i = sizeList - 1; i > p; i--)
        ptr = ptr -> next;
    return ptr -> data;
}

template <typename T>
T List <T> :: first ()
{
    return firstElement -> data;
}

template <typename T>
T List <T> :: last ()
{
    return lastElement -> data;
}

template <typename T>
bool List <T> :: empty ()
{
    return !sizeList;
}

template <typename T>
int List <T> :: size ()
{
    return sizeList;
}

template <typename T>
void List <T> :: destroy ()
{
    if (sizeList)
    {
        Node* ptr = lastElement;
        for (int i = 0; i < sizeList; i++)
        {
            Node* temp = ptr;
            ptr = ptr -> next;
            delete temp;
        }
        sizeList = 0;
    }
}
