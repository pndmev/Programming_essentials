int maxFromPower (int power)
{
    int result = 1;
    for (int i = 0; i < power; i++)
        result *= 10;
    return result;
}

const int MAX_POWER = 4;
const int MAX = maxFromPower(MAX_POWER);

///Fraction
class Fraction
{
    private:
        int integerPart;
        int fractionalPart;
        char sign;
    public:
        Fraction(){integerPart = 0; fractionalPart = 0; sign = '+';};
        Fraction(int integer, int fractional, char c){if(integer >= 0)integerPart = integer; if(fractional >= 0)fractionalPart = fractional; if(c == '-' && integerPart != 0 && fractionalPart != 0) sign = c; else sign = '+';};
        Fraction(const Fraction& f){integerPart = f.integerPart; fractionalPart = f.fractionalPart; sign = f.sign;};

        void operator = (const Fraction& f){integerPart = f.integerPart; fractionalPart = f.fractionalPart; sign = f.sign;};

        friend ostream& operator << (ostream& o, Fraction& f);
        friend istream& operator >> (istream& i, Fraction& f);

        bool operator <= (Fraction);
        bool operator >= (Fraction);
        bool operator < (Fraction f){return (*this) <= f && (*this) != f;};
        bool operator > (Fraction f){return (*this) >= f && (*this) != f;};
        bool operator == (Fraction);
        bool operator != (Fraction);

        Fraction operator + (Fraction);
        Fraction operator - (Fraction);
        Fraction operator * (Fraction);

        void operator += (Fraction);

        friend int transformation(int);
        friend Fraction addition(Fraction, Fraction);
        friend Fraction subtraction(Fraction, Fraction);
        friend Fraction multiplication(Fraction, Fraction);

        ~Fraction(){};
};

string reverseTransformation (int x)
{
    string resultStr;
    for (int i = 0; i < MAX_POWER; i++)
        resultStr += '0';
    for (int i = MAX_POWER - 1; x > 0; i--)
    {
        resultStr[i] = (x % 10) + 48;
        x /= 10;
    }
    return resultStr;
}

int sizeOfString (string str)
{
    int strSize = 0;
    while (str[strSize] != 0)
        strSize++;
    return strSize;
}

bool isStringNumber(string str, int strSize)
{
    bool isItNumber = true;
    for (int i = 0; i < strSize; i++)
    {
        if (str[i] < 48 && str[i] > 57)
            isItNumber = false;
    }
    return isItNumber;
}

int toInt(string str, int strSize)
{
    int coefficient = 1;
    int result = 0;
    for (int i = strSize - 1; i >= 0; i--)
    {
        result += coefficient * (str[i] - 48);
        coefficient *= 10;
    }
    return result;
}

int transformation (string str)
{
    int result = 0;
    int strSize = sizeOfString(str);
    if (isStringNumber(str, strSize))
    {
        int difference = MAX_POWER - strSize;
        while (difference > 0)
        {
            str += '0';
            difference--;
        }
        result = toInt(str, MAX_POWER);
    }
    return result;
}

ostream& operator << (ostream& o, Fraction& f)
{
    o << f.sign;
    o << f.integerPart;
    o << ".";
    o << reverseTransformation(f.fractionalPart);
    return o;
}

istream& operator >> (istream& i, Fraction& f)
{
    string integer;
    string fractional;
    i >> integer;
    i >> fractional;
    int integerSize = sizeOfString(integer);
    if (integer[0] == '-')
    {
        f.sign = integer[0];
        string bufer;
        for (int i = 1; i < integerSize; i++)
            bufer += integer[i];
        integer = bufer;
        integerSize--;
    }
    if (isStringNumber(integer, integerSize))
        f.integerPart = toInt(integer, integerSize);
    else
        f.integerPart = 0;
    f.fractionalPart = transformation(fractional);
    if (f.integerPart == 0 && f.fractionalPart == 0)
        f.sign = '+';
    return i;
}

bool Fraction :: operator <= (Fraction f)
{
    bool isItLessOrEqually;
    bool areThisFractionsNegative = sign == '-' && f.sign == '-';
    bool areThisFractionsPositive = sign == '+' && f.sign == '+';
    bool areThisFractionsNegativeAndPositive = sign == '-' && f.sign == '+';

    if (areThisFractionsNegativeAndPositive || integerPart < f.integerPart && areThisFractionsPositive || integerPart > f.integerPart && areThisFractionsNegative)
        isItLessOrEqually = true;
    else
        if (integerPart == f.integerPart && sign == f.sign)
            isItLessOrEqually = areThisFractionsPositive && fractionalPart <= f.fractionalPart || areThisFractionsNegative && fractionalPart >= f.fractionalPart;
        else
            isItLessOrEqually = false;
    return isItLessOrEqually;
}

bool Fraction :: operator >= (Fraction f)
{
    bool isItMoreOrEqually;
    bool areThisFractionsNegative = sign == '-' && f.sign == '-';
    bool areThisFractionsPositive = sign == '+' && f.sign == '+';
    bool areThisFractionsPositiveAndNegative = sign == '+' && f.sign == '-';

    if (areThisFractionsPositiveAndNegative || integerPart > f.integerPart && areThisFractionsPositive || integerPart < f.integerPart && areThisFractionsNegative)
        isItMoreOrEqually = true;
    else
        if (integerPart == f.integerPart && sign == f.sign)
            isItMoreOrEqually = areThisFractionsPositive && fractionalPart >= f.fractionalPart || areThisFractionsNegative && fractionalPart <= f.fractionalPart;
        else
            isItMoreOrEqually = false;
    return isItMoreOrEqually;
}

bool Fraction :: operator == (Fraction f)
{
    return sign == f.sign && integerPart == f.integerPart && fractionalPart == f.fractionalPart;
}

bool Fraction :: operator != (Fraction f)
{
    return !((*this) == f);
}

Fraction addition (Fraction f1, Fraction f2)
{
    Fraction resultFraction;

    resultFraction.integerPart = f1.integerPart + f2.integerPart;
    resultFraction.fractionalPart = f1.fractionalPart + f2.fractionalPart;

    if (resultFraction.fractionalPart >= MAX)
    {
        resultFraction.fractionalPart -= MAX;
        resultFraction.integerPart += 1;
    }
    return resultFraction;
}

Fraction subtraction (Fraction f1, Fraction f2)
{
    Fraction resultFraction;
    resultFraction.integerPart = f1.integerPart - f2.integerPart;
    resultFraction.fractionalPart = f1.fractionalPart - f2.fractionalPart;

    if (resultFraction.integerPart <= 0 && resultFraction.fractionalPart <= 0)
    {
        resultFraction.sign = '-';
        resultFraction.integerPart *= -1;
        resultFraction.fractionalPart *= -1;
    }
    else
        if (resultFraction.integerPart <= 0 && resultFraction.fractionalPart > 0)
        {
            resultFraction.sign = '-';
            resultFraction.integerPart += 1;
            resultFraction.integerPart *= -1;
            resultFraction.fractionalPart = MAX - resultFraction.fractionalPart;
        }
        else
            if (resultFraction.integerPart > 0 && resultFraction.fractionalPart <= 0)
            {
                resultFraction.integerPart -= 1;
                resultFraction.fractionalPart += MAX;
            }
    return resultFraction;
}

Fraction multiplication (Fraction f1, Fraction f2)
{
    /// *this = a + b/max; f = c + d/max
    int ac, adANDbc, bd, integer, fractional;
    ac = f1.integerPart * f2.integerPart;
    adANDbc = f1.integerPart * f2.fractionalPart + f1.fractionalPart * f2.integerPart;
    bd = f1.fractionalPart * f2.fractionalPart;
    integer = ac + adANDbc / MAX;
    fractional = adANDbc % MAX + bd / MAX;
    Fraction resultFraction;
    if (integer > MAX)
    {
        resultFraction.integerPart = MAX;
        resultFraction.fractionalPart = 0;
    }
    else
        if (fractional > MAX)
        {
            integer += 1;
            fractional -= MAX;
        }
    resultFraction.integerPart = integer;
    resultFraction.fractionalPart = fractional;
    return resultFraction;
}

Fraction Fraction :: operator + (Fraction f)
{
    Fraction resultFraction;
    if (sign != '-' && f.sign != '-')
        resultFraction = addition(*this, f);
    else
        if (sign == '-' && f.sign != '-')
            resultFraction = subtraction(f, *this);
        else
            if (sign != '-' && f.sign == '-')
                resultFraction = subtraction(*this, f);
            else
            {
                Fraction result = addition(*this, f);
                result.sign = '-';
                resultFraction = result;
            }
    if (resultFraction.integerPart == 0 && resultFraction.fractionalPart == 0)
        resultFraction.sign = '+';
    return resultFraction;
}

Fraction Fraction :: operator - (Fraction f)
{
    Fraction resultFraction;
    if (sign != '-' && f.sign != '-')
        resultFraction = subtraction(*this, f);
    else
        if (sign == '-' && f.sign != '-')
        {
            Fraction result = addition(*this, f);
            result.sign = '-';
            resultFraction = result;
        }
        else
            if (sign != '-' && f.sign == '-')
                resultFraction = addition(*this, f);
            else
                resultFraction = subtraction(f, *this);
    if (resultFraction.integerPart == 0 && resultFraction.fractionalPart == 0)
        resultFraction.sign = '+';
    return resultFraction;
}

Fraction Fraction :: operator * (Fraction f)
{
    Fraction resultFraction;
    if (sign != '-' && f.sign != '-')
        resultFraction = multiplication(*this, f);
    else
        if (sign == '-' && f.sign != '-' )
        {
            Fraction result = multiplication(*this, f);
            result.sign = '-';
            resultFraction = result;
        }
        else
            if (sign != '-' && f.sign == '-')
            {
                Fraction result = multiplication(*this, f);
                result.sign = '-';
                resultFraction = result;
            }
            else
                resultFraction = multiplication(*this, f);
    if (resultFraction.integerPart == 0 && resultFraction.fractionalPart == 0)
        resultFraction.sign = '+';
    return resultFraction;
}

void Fraction :: operator += (Fraction f)
{
    Fraction resultFraction;
    resultFraction = (*this) + f;
    (*this) = resultFraction;
}
