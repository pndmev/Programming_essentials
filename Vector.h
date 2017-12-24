///Vector
template <class T>
class Vector
{
    public:
	   Vector (int n){size = n; p = new T [size];};
	   Vector (const Vector <T> &v){size = v.size; p = new T[size]; for(int i = 0; i < size; i++) p[i] = v.p[i];};
	   Vector (const T* a, int n){size = n; T* p = new T [size]; for(int i = 0; i < size; i++) p[i] = a[i];};
	   T& operator[](int i){return p[i];};
	   void operator = (const Vector <T> &v){size = v.size; p = new T[size]; for(int i = 0; i < size; i++) p[i] = v.p[i];};
	protected:
	   T* p;
	   int size;
	   ~Vector() {delete []p;};
};

template <class T>
class Vectorex: public Vector <T>
{
    public:
    Vectorex(int n) : Vector <T> (n){;};
    void push_front (T data)
    {
        int oldSize = this -> size;
        this -> size *= 2;
        T* newP = new T [this -> size];
        newP[0] = data;
        for (int i = 0; i < oldSize; i++)
            newP[i + 1] = this -> p[i];
        this -> p = newP;
    }
    void pop_front ()
    {
        for (int i = 0; i < this -> size; i++)
        {
            this -> p[i] = this -> p[i + 1];
        }
        this -> size--;
    }
    int VectorSize(){return this -> size;};

    friend ostream& operator << (ostream& o, Vectorex& v){int Size = v.VectorSize(); for(int j = 0; j < Size; j++){o << v[j]; o << " ";} return o;};
    friend istream& operator >> (istream& i, Vectorex& v){int Size = v.VectorSize(); for(int j = 0; j < Size; j++)i >> v[j]; return i;};

    ~Vectorex(){delete []this -> p;};
};
