#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

/// Symbol
class Symbol
{
    public:
        char symbol;
        Symbol(){;};
        Symbol(char chr){symbol = chr;}
        Symbol(const Symbol& sym){symbol = sym.symbol;};
        bool isExclamationMark(){return symbol == '!';};
        bool isQuestionMark(){return symbol == '?';};
        bool isPoint(){return symbol == '.';};

        bool operator == (Symbol sym){return symbol == sym.symbol;};
        bool operator != (Symbol sym){return symbol != sym.symbol;};
        bool operator >= (Symbol sym){return symbol >= sym.symbol;};
        bool operator <= (Symbol sym){return symbol <= sym.symbol;};
        bool operator > (Symbol sym){return symbol > sym.symbol;};
        bool operator < (Symbol sym){return symbol < sym.symbol;};

        void operator + (int i){symbol += i;}

        friend ostream& operator << (ostream& o, Symbol& sym) {o << sym.symbol; return o;};
        friend istream& operator >> (istream& i, Symbol& sym) {i >> sym.symbol; return i;};

        void get (char chr){symbol = chr;};
        ~Symbol(){};
};

///Word
class Word
{
    public:
        Symbol *word;
        int size = 0;
        Word(){;};
        Word(Symbol *sym, int n){word = sym; size = n;}
        Word(const Word& wrd){word = wrd.word; size = wrd.size;};

        void operator += (Symbol);
        bool operator == (Word);

        bool isPalindrome();
        bool alphabet(Word);

        friend ostream& operator << (ostream& o, Word& wrd) {for(int i = 0; i < wrd.size; i++) o << wrd.word[i]; return o;};

        void get (string);
        void get (char);
        ~Word(){};
};

void Word :: operator += (Symbol sym)
{
    Symbol * newWord = new Symbol [++size];
    if (size > 1)
        newWord = word;
    newWord[size - 1] = sym;
    word = newWord;
    delete newWord;
}

bool Word :: operator == (Word wrd)
{
    bool result = true;
    if (size != wrd.size)
        result = false;
    else
        for (int i = 0; i < size; i++)
            if (word[i] != wrd.word[i])
                result = false;
    return result;
}

bool Word :: isPalindrome()
{
    bool isPalindrome = true;
    int halfSize = size / 2;
    for (int i = 0; i < halfSize; i++)
        if (word[i] != word[halfSize - 1 - i])
            isPalindrome = false;
    return isPalindrome;
}

bool Word :: alphabet(Word wrd)
{
    int i = 0;
    while (word[i] == wrd.word[i])
        i++;
    return i == size || word[i] < wrd.word[i];
}

void Word :: get (string str)
{
    size = str.size();
    Symbol* newWord = new Symbol [size];
    for (int i = 0; i < size; i++)
        newWord[i].get(str[i]);
    word = newWord;
    delete newWord;
}

void Word :: get (char c)
{
    size = 1;
    Symbol* newWord = new Symbol [1];
    newWord[0].get(c);
    word = newWord;
    delete newWord;
}

///Word-number
class WordNumber : public Word
{
    public:
        Symbol *wordNumber;
        int size = 0;
        WordNumber(){;};
        WordNumber(Symbol *, int);
        WordNumber(Word& wrd){wordNumber = wrd.word; size = wrd.size;};
        WordNumber(WordNumber& wrdN){wordNumber = wrdN.wordNumber; size = wrdN.size;};
        WordNumber(int);
        int toInt();

        bool operator == (WordNumber wrdN) {return toInt() == wrdN.toInt();};
        bool operator != (WordNumber wrdN) {return toInt() != wrdN.toInt();};
        bool operator >= (WordNumber wrdN) {return toInt() >= wrdN.toInt();};
        bool operator <= (WordNumber wrdN) {return toInt() <= wrdN.toInt();};
        bool operator > (WordNumber wrdN) {return toInt() > wrdN.toInt();};
        bool operator < (WordNumber wrdN) {return toInt() < wrdN.toInt();};

        int operator + (WordNumber wrdN) {return toInt() + wrdN.toInt();};
        int operator - (WordNumber wrdN) {return toInt() - wrdN.toInt();};
        ~WordNumber(){};
};

WordNumber :: WordNumber(int number)
{
    if (number >= 0)
    {
        int counter = 0;
        int copyNumber = number;
        do
        {
            copyNumber /= 10;
            counter++;
        }
        while (copyNumber > 0);

        Symbol * newSym = new Symbol [counter];
        for (int i = counter - 1; i >= 0; i--)
        {
            newSym[i].symbol = number % 10 + 48;
            number /= 10;
        }

        wordNumber = newSym;
    }
}

bool isItNumber (Symbol* sym, int n)
{
    bool isItNumber = true;
    for (int i = 0; i < n; i++)
    {
        if (sym[i].symbol < 48 || sym[i].symbol > 57)
            isItNumber = false;
    }
    return isItNumber;
}

WordNumber :: WordNumber(Symbol *sym, int n)
{
    if (isItNumber(sym, n))
    {
        wordNumber = sym;
        size = n;
    }
}

int WordNumber :: toInt()
{
    int coefficient = 1;
    int result = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        result += coefficient * (wordNumber[i].symbol - 48);
        coefficient *= 10;
    }
    return result;
}

/// Sentence
class Sentence
{
    public:
        Word *sentence;
        Symbol punctuationMark = '.';
        int size = 0;
        Sentence(){;};
        Sentence(Word *wrd, int n, Symbol pm){sentence = wrd; size = n; punctuationMark = pm;};
        Sentence(const Sentence& sen){sentence = sen.sentence; size = sen.size; punctuationMark = sen.punctuationMark;};

        void operator += (Word);
        void operator += (string);
        void operator += (char);

        Sentence findWordNumber();
        Sentence findSortWordNumber();

        int findWordFromPosition(Word, int);
        void deleteWordFromPosition(Word, int);
        void deleteWord(Word);
        void insertAfterWord(Word, Word);
        void exchange(int, int);
        void replacement(Word, Word);
        void sort();
        void sortQ();

        bool isInterrogative(){return punctuationMark.isQuestionMark();};
        bool isIncentive(){return punctuationMark.isExclamationMark();};

        friend ostream& operator << (ostream& o, Sentence& sen) {int size1 = sen.size -1; for(int i = 0; i < size1; i++) {o << sen.sentence[i]; o << " ";} o << sen.sentence[size1]; o << sen.punctuationMark; return o;};

        int sum();
        void clear();
        ~Sentence(){};
};

void Sentence :: operator += (Word wrd)
{
    Word* newSentence = new Word [size + 1];
    for (int i = 0; i < size; i++)
        newSentence[i] = sentence[i];
    newSentence[size] = wrd;
    size++;
    sentence = newSentence;
    delete newSentence;
}

void Sentence :: operator += (string str)
{
    Word wrd;
    wrd.get(str);
    *this += wrd;
}

void Sentence :: operator += (char c)
{
    Word wrd;
    wrd.get(c);
    *this += wrd;
}

Sentence Sentence :: findWordNumber ()
{
    Sentence wordNumberSentence;
    for (int i = 0; i < size; i++)
        if (isItNumber(sentence[i].word, sentence[i].size))
        {
            wordNumberSentence += sentence[i];
        }
    return wordNumberSentence;
}

int compareWordNumber (const void* a, const void* b)
{
    WordNumber w1(*(Word*)a), w2(*(Word*)b);
    if (w1.toInt() < w2.toInt())
        return -1;
    if (w1.toInt() > w2.toInt())
        return 1;
    if (w1.toInt() == w2.toInt())
        return 0;
}

Sentence Sentence :: findSortWordNumber ()
{
    Sentence wordNumberSentence = findWordNumber();
    qsort(wordNumberSentence.sentence, wordNumberSentence.size, sizeof(Word), compareWordNumber);
    return wordNumberSentence;
}

int Sentence :: sum()
{
    Sentence wordNumberSentence = findWordNumber();
    int sum = 0;
    for (int i = 0; i < wordNumberSentence.size; i++)
    {
        WordNumber buferWordNumber(wordNumberSentence.sentence[i]);
        sum += buferWordNumber.toInt();
    }
    return sum;
}

int Sentence :: findWordFromPosition(Word wrd, int position)
{
    int resultPosition = -1;
    for (int i = position; i < size; i++)
        if (sentence[i] == wrd)
            resultPosition = i;
    return resultPosition;
}

void Sentence :: deleteWordFromPosition(Word wrd, int position)
{
    int positionX = findWordFromPosition(wrd, position);
    if (positionX > -1)
    {
        for (int i = positionX; i < size - 1; i++)
            sentence[i] = sentence[i + 1];
    }
    size--;
}

void Sentence :: deleteWord(Word wrd)
{
    deleteWordFromPosition(wrd, 0);
}

void Sentence :: insertAfterWord (Word wrd, Word wrdV)
{
    int positionV = findWordFromPosition(wrd, 0) + 1;
    if (positionV > 0)
    {
        int buferSize = size + 1;
        Word* newSentence = new Word [buferSize];
        newSentence = sentence;
        newSentence[positionV] = wrdV;
        for (int i = positionV + 1; i < buferSize; i++)
            newSentence[i] = sentence[i - 1];
        sentence = newSentence;
        delete newSentence;
    }
}

void Sentence :: exchange(int position1, int position2)
{
    if (position1 > -1 && position1 < size && position2 > -1 && position2 < size)
    {
        Word buferWord = sentence[position1];
        sentence[position1] = sentence[position2];
        sentence[position2] = buferWord;
    }
}

void Sentence :: replacement(Word wrd, Word newWrd)
{
    int position = findWordFromPosition(wrd, 0);
    if (position > -1)
        sentence[position] = newWrd;
}

void Sentence :: sort()
{
    int left = 0;
    int right = size - 1;
    for (left = 0; left < right; left++)
    {
        for (int i = left; i < right; i++)
        {
            if (!sentence[i].alphabet(sentence[i + 1]))
                exchange(i, i + 1);
        }
        right--;
        for (int i = right; i > left; i--)
        {
            if (sentence[i].alphabet(sentence[i - 1]))
                exchange(i, i - 1);
        }
    }
}

int compareWord (const void* a, const void* b)
{
    Word w1 = *(Word*)a, w2 = *(Word*)b;
    if (w1 == w2)
        return 0;
    if (w1.alphabet(w2))
        return -1;
    else
        return 1;
}

void Sentence :: sortQ()
{
    qsort(sentence, size, sizeof(Word), compareWord);
}

void Sentence :: clear()
{
    Word *newSentence;
    Word *oldSentence = sentence;
    sentence = newSentence;
    delete oldSentence;
    size = 0;
}

/// Paragraph
class Paragraph
{
    public:
        Sentence *paragraph;
        int size = 0;
        Paragraph(){;};
        Paragraph(Sentence *sen, int n){paragraph = sen; size = n;};
        Paragraph(const Paragraph& par){paragraph = par.paragraph; size = par.size;};

        friend ostream& operator << (ostream& o, Paragraph& par) {for(int i = 0; i < par.size; i++) {o << par.paragraph[i]; o << " ";} return o;};
        void operator += (Sentence);
        ~Paragraph(){};
};

void Paragraph :: operator += (Sentence sen)
{
    Sentence* newParagraph = new Sentence [size + 1];
    for (int i = 0; i < size; i++)
        newParagraph[i] = paragraph[i];
    newParagraph[size] = sen;
    size++;
    paragraph = newParagraph;
    delete newParagraph;
}

/// Text
class Text
{
    public:
        Paragraph *text;
        int size = 0;
        Text(){;};
        Text(Paragraph *par, int n){text = par; size = n;};
        Text(const Text& txt){text = txt.text; size = txt.size;};
        ~Text(){};
};

void BIG_to_small (Word wrd)
{
    for (int i = 0; i < wrd.size; i++)
        if (wrd.word[i] > 64 && wrd.word[i] < 91)
            wrd.word[i] + 32;
}

bool isPunctuationMarkInSentence (char c)
{
    switch (c)
    {
        case '(': case '[': case '{': case ')': case ']': case '}': case ',': case ';': case ':':
        {
            return true;
            break;
        }
        default:
        {
            return false;
        }
    }
}

bool isPunctuationMark (char c)
{
    switch (c)
    {
        case '.': case '?': case '!':
        {
            return true;
            break;
        }
        default:
        {
            return false;
        }
    }
}

int main10()
{
    ifstream fin ("Input10.txt");
    ofstream fout ("Output10.txt");

    string bufer;
    Word w;
    Sentence s;
    Paragraph p;

    while (!fin.eof())
    {
        fin >> bufer;
        int last = bufer.size() - 1;

        bool isFirstSymbolPunctuationMark = isPunctuationMarkInSentence(bufer[0]);
        bool isThisWordLast = isPunctuationMark(bufer[last]);
        bool isLastSymbolPunctuationMark;
        if (isThisWordLast)
            isLastSymbolPunctuationMark = isThisWordLast;
        else
            isLastSymbolPunctuationMark = isPunctuationMarkInSentence(bufer[last]);

        string buferMiddle;
        for (int i = 1; i < last; i++)
            buferMiddle += bufer[i];
        string addBufer;
        switch (isFirstSymbolPunctuationMark + 2 * isLastSymbolPunctuationMark)
        {
            case 0:
            {
                addBufer += bufer[0];
                addBufer += buferMiddle;
                addBufer += bufer[last];
                s += addBufer;
                break;
            }
            case 1:
            {
                s += bufer[0];
                addBufer += buferMiddle;
                addBufer += bufer[last];
                s += addBufer;
                break;
            }
            case 2:
            {
                addBufer += bufer[0];
                addBufer += buferMiddle;
                s += addBufer;
                if (isThisWordLast)
                {
                    s.punctuationMark.get(bufer[last]);
                    p += s;
                    s.clear();
                }
                else
                    s += bufer[last];
                break;
            }
            case 3:
            {
                s += bufer[0];
                s += buferMiddle;
                if (isThisWordLast)
                {
                    s.punctuationMark.get(bufer[last]);
                    p += s;
                    s.clear();
                }
                else
                    s += bufer[last];
                break;
            }
        }
    }

    Sentence resultSentence;
    int length;
    do
    {
        cout << "Please, enter the length of word (more than 0)" << endl;
        cin >> length;
    }
    while (length < 1);

    for (int i = 0; i < p.size; i++)
        if (p.paragraph[i].isInterrogative())
            for (int j = 0; j < p.paragraph[i].size; j++)
                if (p.paragraph[i].sentence[j].size == length && !isPunctuationMarkInSentence(p.paragraph[i].sentence[j].word[0].symbol))
                {
                    Word buferWord = p.paragraph[i].sentence[j];
                    BIG_to_small(buferWord);
                        if (resultSentence.findWordFromPosition(buferWord, 0) == -1)
                    resultSentence += buferWord;
                }
    if (resultSentence.size)
    {
        cout << resultSentence << endl;
        fout << resultSentence << endl;
    }
    else
    {
        cout << "Not found" << endl;
        fout << "Not found" << endl;
    }

    fin.close();
    fout.close();

    return 0;
}

