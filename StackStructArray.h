const int SIZE = 100;

template <typename T>
struct StackStructArray
{
    int top = -1;
    T *a = new T[SIZE];
};

template <typename T>
void push (StackStructArray <T>& S, T d)
{
    S.a[++S.top] = d;
}

template <typename T>
void pop (StackStructArray <T>& S)
{
    S.top--;
}

template <typename T>
T top (StackStructArray <T>& S)
{
    return S.a[S.top];
}

template <typename T>
void destroy (StackStructArray <T>& S)
{
    delete S.a;
}

template <typename T>
bool empty (StackStructArray <T>& S)
{
    return S.top == -1;
}
