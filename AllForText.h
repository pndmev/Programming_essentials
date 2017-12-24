/// Symbol
class Symbol
{
    public:
        char symbol;
        Symbol(){;};
        Symbol(char c){symbol = c;}
        Symbol(const Symbol& s){symbol = s.symbol;};
        void print(){cout << symbol;};
        ~Symbol(){};
};

///Punctuation mark
class PunctuationMark : public Symbol
{
    public:
        bool isExclamationMark(){return symbol == '!';};
        bool isQuestionMark(){return symbol == '?';};
        bool isPoint(){return symbol == '.';};
        bool isComma(){return symbol == ',';};
        bool isSemicolon(){return symbol == ';';};
        bool isColon(){return symbol == ':';};
};

///Word
class Word
{
    public:
        Symbol *word;
        int size = 0;
        Word(int n){word = new Symbol [n]; size = n;};
        Word(Symbol *s, int n){word = s; size = n;}
        Word(const Word& w){word = w.word; size = w.size;};
        void print(){for(int i = 0; i < size; i++) word[i].print(); cout << " ";};
        ~Word(){};
};

///Word-number
Symbol* toWordNumber (double n, int &size)
{
    int counter1 = 0;
    double n1 = n * 10;
    while (int(n1) % 10 != 0)
    {
        n1 *= 10;
        counter1++;
    }

    int n2 = int(n);
    int counter2 = 0;
    while (n2 > 0)
    {
        n2 /= 10;
        counter2++;
    }

    n2 = int(n);
    size = counter2 + 1;
    Symbol *c = new Symbol [size];
    for (int i = 0; i < counter1; i++)
    {
        c[size - 1 - i] = (n2 % 10) + 48;
        n2 /= 10;
    }
    c[size - 1 - counter1] = '.';
    for (int i = size - 2 - counter1; i >= 0; i--)
    {
        c[i] = (n2 % 10) + 48;
        n2 /= 10;
    }
    if (!counter1)
    {
        Symbol *cc = new Symbol [--size];
        for (int i = 0; i < size; i++)
            cc[i] = c[i];
        return cc;
    }
    return c;
}

class WordNumber
{
    public:
        Symbol *word;
        int size = 0;
        WordNumber(int n){word = new Symbol [n]; size = n;};
        WordNumber(Symbol *s, int n){word = s; size = n;}
        WordNumber(Word& w){word = w.word; size = w.size;};
        WordNumber(double n){word = toWordNumber(n, size);};
        double toDouble();
        ~WordNumber(){};
};

double WordNumber :: toDouble ()
{
    double coefficient = 1;
    double result = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        if (word[i].symbol != '.')
        {
            result += coefficient * (word[i].symbol - 48);
            coefficient *= 10;
        }
    }
    coefficient = 1;
    for (int i = 0; i < size; i++)
    {
        if (word[i].symbol == '.')
        {
            for (int j = 0; j < size - i - 1; j++)
                coefficient /= 10;
        }
    }
    return result * coefficient;
}

class Sentence
{
    public:
        Word *sentence;
        int size = 0;
        Sentence(int n){sentence = new Word [n]; size = n;};
        Sentence(Word *w, int n){sentence = w; size = n;};
        Sentence(const Sentence& s){sentence = s.sentence; size = s.size;};
        ~Sentence(){};
};

/*class Paragraph
{
    public:
        Sentence *paragraph;
        int size = 0;
        Paragraph(int n){paragraph = new Sentence [n]; size = n;};
        Paragraph(Sentence *s, int n){paragraph = s; size = n;};
        Paragraph(const Paragraph& p){paragraph = p.paragraph; size = p.size;};
        ~Paragraph(){};
};

class Text
{
    public:
        Paragraph *text;
        int size = 0;
        Text(int n){text = new Paragraph [n]; size = n;};
        Text(Paragraph *p, int n){text = p; size = n;};
        Text(const Text& t){text = t.text; size = t.size;};
        ~Text(){};
};
*/
