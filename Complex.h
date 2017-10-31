#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED



#endif // COMPLEX_H_INCLUDED

class Complex
{
    double Re; /// real
    double Im; /// imaginary

    public:
        Complex(){;};                    /// constructor by default
        Complex(double, double);         /// constructor with parameters
        Complex(const Complex& C);       /// constructor for copying
        double Get_Re(){return Re;}
        double Get_Im(){return Im;}
        void Add(Complex);               /// addition
        void Give(double, double);       /// giving 1
        void Give(Complex);              /// giving 2
        bool Compare(Complex);           /// comparing
        void Print();                    /// output
        ~Complex(){};                    /// destructor
};

Complex :: Complex(double Real, double Imaginary)
{
    Re = Real;
    Im = Imaginary;
}

Complex :: Complex(const Complex& C)
{
    Re = C.Re;
    Im = C.Im;
}

void Complex :: Add(Complex C)
{
    Re += C.Re;
    Im += C.Im;
}

void Complex :: Give (double Real, double Imaginary)
{
    Re = Real;
    Im = Imaginary;
}

void Complex :: Give (Complex C)
{
    Re = C.Re;
    Im = C.Im;
}

bool Complex :: Compare(Complex C)
{
    return Re * Re + Im * Im > C.Re * C.Re + C.Im * C.Im;
}

void Complex :: Print()
{
    cout << Re << " + " << Im << "i";
}
