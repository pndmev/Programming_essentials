///Series
class Series
{
    protected:
        double first;
        double step;
        int length;
    public:
        virtual double element(int) = 0;
        virtual double sum() = 0;
	   ~Series(){;};
};

class Liner: public Series
{
    public:
    Liner(){;};
    Liner(double f, double s, int l){first = f; step = s; if (l > 0) length = l; else length = 1;};
    Liner(Liner& L){first = L.first; step = L.step; length = L.length;}

    void operator = (Liner& L){first = L.first; step = L.step; length = L.length;};

    friend ostream& operator << (ostream& o, Liner& L){double var = L.first; for (int i = 0; i < L.length; i++) {o << var << " "; var += L.step;} return o;};
    friend istream& operator >> (istream& i, Liner& L){double f, s; int l; i >> f; i >> s; i >> l; Liner LL(f,s,l); L = LL;};

    double element(int j){return first + step * (j - 1);};
    double sum(){double eN = element(length); return ((first + eN) * length) / 2;};

    ~Liner(){;};
};

class Exponential: public Series
{
    public:
    Exponential(){;};
    Exponential(double f, double s, int l){if (f != 0) first = f; else first = 1; if (s != 0) step = s; else step = 1; if (l > 0) length = l; else length = 1;};
    Exponential(Exponential& E){first = E.first; step = E.step; length = E.length;}

    void operator = (Exponential& E){first = E.first; step = E.step; length = E.length;};

    friend ostream& operator << (ostream& o, Exponential& E){double var = E.first; for (int i = 0; i < E.length; i++) {o << var << " "; var *= E.step;} return o;};
    friend istream& operator >> (istream& i, Exponential& E){double f, s; int l; i >> f; i >> s; i >> l; Exponential EE(f,s,l); E = EE;};

    double element(int j){double s = 1; for (int i = 1; i < j; i++) s *= step; return first * s;};
    double sum(){if (step == 1) return length * first; else {double sN = 1; for (int i = 0; i < length; i++) sN *= step; return (first * (1 - sN)) / (1 - step);}};

    ~Exponential(){;};
};
