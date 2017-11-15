template <typename T>
class Stack
{
    struct Node
    {
        T data;
        Node *next;
    };

    Node *ptr;
    int sizeStack = 0;

    public:
        Stack(){;};
        void push(T);
        void pop();
        T top();
        bool empty();
        int size();
        ~Stack(){};
};

template <typename T>
void Stack <T> :: push (T d)
{
    Node *newNode = new Node;
    newNode -> next = ptr;
    newNode -> data = d;
    ptr = newNode;
    sizeStack++;
}

template <typename T>
void Stack <T> :: pop ()
{
    Node* temp = ptr;
    ptr = ptr -> next;
    delete temp;
    sizeStack--;
}

template <typename T>
T Stack <T> :: top ()
{
    return ptr -> data;
}

template <typename T>
bool Stack <T> :: empty ()
{
    return sizeStack == 0;
}

template <typename T>
int Stack <T> :: size ()
{
    return sizeStack;
}
