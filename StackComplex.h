class StackComplex
{
    struct NodeComplex
    {
        double dataRe;
        double dataIm;
        NodeComplex *next;
    };

    NodeComplex *ptr;
    int sizeStack = 0;

    public:
        StackComplex(){;};
        void push(double, double);
        void push(Complex);
        void pop();
        Complex top();
        bool empty();
        void print();
        ~StackComplex(){};
};

void StackComplex :: push (double dRe, double dIm)
{
    NodeComplex *newNodeComplex = new NodeComplex;
    newNodeComplex -> next = ptr;
    newNodeComplex -> dataRe = dRe;
    newNodeComplex -> dataIm = dIm;
    ptr = newNodeComplex;
    sizeStack++;
}

void StackComplex :: push (Complex C)
{
    NodeComplex *newNodeComplex = new NodeComplex;
    newNodeComplex -> next = ptr;
    newNodeComplex -> dataRe = C.Get_Re();
    newNodeComplex -> dataIm = C.Get_Im();
    ptr = newNodeComplex;
    sizeStack++;
}

void StackComplex :: pop ()
{
    ptr = ptr -> next;
    sizeStack--;
}

Complex StackComplex :: top ()
{
    Complex C(ptr -> dataRe, ptr -> dataIm);
    return C;
}

bool StackComplex :: empty ()
{
    return sizeStack == 0;
}

void StackComplex :: print ()
{
    if (sizeStack)
    {
        NodeComplex *p = ptr;
        for (int i = 0; i < sizeStack; i++)
        {
            cout << p -> dataRe << " + " << p -> dataIm << "i; ";
            p = p -> next;
        }
        cout << endl;
    }
    else
        cout << "This stack is empty" << endl;
}
