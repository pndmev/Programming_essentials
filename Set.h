///Set
class Set
{
    private:
        const int MAX_SIZE = 256;
        int size = 0;
    public:
        char* set;
        Set(){;};
        Set(char* s, int sSize){if (sSize <= MAX_SIZE) {set = s; size = sSize; this -> sort();}};
        Set(const Set& s){char* newSet = new char [s.size]; for (int i = 0; i < s.size; i++) newSet[i] = s.set[i]; set = newSet; size = s.size;};

        void operator = (const Set& s){char* newSet = new char [s.size]; for (int i = 0; i < s.size; i++) newSet[i] = s.set[i]; set = newSet; size = s.size;};

        void operator += (char);
        bool operator == (Set);
        Set operator * (Set);
        bool operator < (Set);
        Set operator + (Set);
        Set operator - (Set);

        friend ostream& operator << (ostream&, Set&);
        friend istream& operator >> (istream&, Set&);

        void sort();

        ~Set(){delete set;};
};

ostream& operator << (ostream& o, Set& s)
{
    for (int i = 0; i < s.size; i++)
        o << s.set[i];
    return o;
}

istream& operator >> (istream& i, Set& s)
{
    string str;
    i >> str;
    int strSize = 0;
    while (str[strSize] != 0)
        strSize++;
    if (strSize <= s.MAX_SIZE)
    {
        char* c = new char [strSize];
        for (int j = 0; j < strSize; j++)
            c[j] = str[j];
        s.set = c;
        s.size = strSize;
        s.sort();
    }
    return i;
}

void Set :: operator += (char c)
{
    if (size == 0)
    {
        set = new char [++size];
        set[0] = c;
    }
    else
    if (size < MAX_SIZE)
    {
        char * newSet = new char [++size];
        int counter = 0;
        while (set[counter] < c && counter < size - 1)
        {
            newSet[counter] = set[counter];
            counter++;
        }
        newSet[counter] = c;
        for (counter += 1; counter < size; counter++)
            newSet[counter] = set[counter - 1];
        set = newSet;
    }
}

bool Set :: operator == (Set s)
{
    bool result = true;
    if (size != s.size)
        result = false;
    else
        for (int i = 0; i < size; i++)
            if (set[i] != s.set[i])
                result = false;
    return result;
}

void swap (Set &s, int p1, int p2)
{
    char bufer = s.set[p1];
    s.set[p1] = s.set[p2];
    s.set[p2] = bufer;
}

void Set :: sort ()
{
    int left = 0;
    int right = size - 1;
    for (left = 0; left < right; left++)
    {
        for (int i = left; i < right; i++)
        {
            if (set[i] > set[i + 1])
                swap(*this, i, i + 1);
        }
        right--;
        for (int i = right; i > left; i--)
        {
            if (set[i] < set[i - 1])
                swap(*this, i, i - 1);
        }
    }
}

Set Set :: operator * (Set s)
{
    Set resultSet;
    int j = 0;
    for (int i = 0; i < size && j < s.size; i++)
    {
        while (set[i] > s.set[j])
            j++;
        if (j >= s.size)
            break;
        if (set[i] == s.set[j])
        {
            resultSet += set[i];
            j++;
        }
    }
    return resultSet;
}

bool Set :: operator < (Set s)
{
    return s == *this * s;
}

Set Set :: operator + (Set s)
{
    Set iS1 = (*this) * s;
    Set iS2 = s - iS1;
    Set nS;
    int newSize = size + iS2.size;
    if (newSize <= MAX_SIZE)
    {
        char * newSet = new char [newSize];
        for (int i = 0; i < size; i++)
            newSet[i] = set[i];
        for (int i = size; i < newSize; i++)
            newSet[i] = iS2.set[i - size];
        nS.set = newSet;
        nS.size = newSize;
    }
    return nS;
}

Set Set :: operator - (Set s)
{
    Set resultSet;
    int j = 0;
    for (int i = 0; i < size && j < s.size; i++)
    {
        while (set[i] > s.set[j])
            j++;
        if (j >= s.size)
        {
            resultSet += set[i];
            i++;
            while (i < size)
                resultSet += set[i++];
            break;
        }
        if (set[i] != s.set[j])
        {
            resultSet += set[i];
        }
    }
    return resultSet;
}
