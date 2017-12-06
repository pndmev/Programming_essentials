/// Stack
template <typename TS>
class Stack
{
    protected:
        struct Node
        {
            TS data;
            Node *next;
        };

        Node *last;
        //int sizeStack = 0;

    public:
        Stack(){last = NULL;};
        void push(TS);
        void pop();
        TS top();
        bool empty();
        //int size();
        ~Stack(){};
};

template <typename TS>
void Stack <TS> :: push (TS d)
{
    Node *newNode = new Node;
    newNode -> next = last;
    newNode -> data = d;
    last = newNode;
    //sizeStack++;
}

template <typename TS>
void Stack <TS> :: pop ()
{
    Node* temp = last;
    last = last -> next;
    delete temp;
    //sizeStack--;
}

template <typename TS>
TS Stack <TS> :: top ()
{
    return last -> data;
}

template <typename TS>
bool Stack <TS> :: empty ()
{
    return last == NULL;
}

/*template <typename TS>
int Stack <TS> :: size ()
{
    return sizeStack;
}*/
