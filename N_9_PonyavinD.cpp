#include <iostream>
#include <fstream>

#include "List.h"

using namespace std;

ofstream fout("Output.txt");

struct Product
{
    string ProductID;
    string Name;
    int UPC;
    string Producer;
    double Price;
    int Period;
    int Quantity;
};

void printNewProduct (Product P, string code)
{
    int s = str_size(code);
    bool head = false;
    for (int i = 0; i < s; i++)
    {
        switch (code[i])
        {
            case '0':
            {
                if (head)
                {
                    cout << "ProductID" << "\t";
                    fout << "ProductID" << "\t";
                }
                else
                {
                    cout << P.ProductID << "\t";
                    fout << P.ProductID << "\t";
                }
                break;
            }
            case '1':
            {
                if (head)
                {
                    cout << "Name" << "\t";
                    fout << "Name" << "\t";
                }
                else
                {
                    cout << P.Name << "\t";
                    fout << P.Name << "\t";
                }
                break;
            }
            case '2':
            {
                if (head)
                {
                    cout << "UPC" << "\t";
                    fout << "UPC" << "\t";
                }
                else
                {
                    cout << P.UPC << "\t";
                    fout << P.UPC << "\t";
                }
                break;
            }
            case '3':
            {
                if (head)
                {
                    cout << "Producer" << "\t";
                    fout << "Producer" << "\t";
                }
                else
                {
                    cout << P.Producer << "\t";
                    fout << P.Producer << "\t";
                }
                break;
            }
            case '4':
            {
                if (head)
                {
                    cout << "Price" << "\t";
                    fout << "Price" << "\t";
                }
                else
                {
                    cout << P.Price << "\t";
                    fout << P.Price << "\t";
                }
                break;
            }
            case '5':
            {
                if (head)
                {
                    cout << "Period" << "\t";
                    fout << "Period" << "\t";
                }
                else
                {
                    cout << P.Period << "\t";
                    fout << P.Period << "\t";
                }
                break;
            }
            case '6':
            {
                if (head)
                {
                    cout << "Qty" << "\t";
                    fout << "Qty" << "\t";
                }
                else
                {
                    cout << P.Quantity << "\t";
                    fout << P.Quantity << "\t";
                }
                break;
            }
            case '-':
            {
                head = true;
                break;
            }
        }
    }
    cout << endl;
    fout << endl;
}

void printListProduct (List <Product> L, string code)
{
    int s = L.size();
    Product P;
    printNewProduct(P, "-"+code);
    for (int i = 0; i < s; i++)
        printNewProduct(L.element(i), code);
}

bool alphabetS1S2 (string s1, string s2)
{
    int ss1 = str_size(s1);
    int ss2 = str_size(s2);
    int ss = ss2;
    if (ss1 < ss2)
        ss = ss1;
    for (int i = 0; i < ss; i++)
    {
        if (s1[i] < s2[i])
            return true;
        if (s1[i] > s2[i])
            return false;
    }
    return true;
}

void swapInList (List <Product> &L, Product bufer1, Product bufer2, int i1, int i2)
{
    L.new_data(bufer2, i1);
    L.new_data(bufer1, i2);
}

void sortPrice (List <Product> &L)
{
    int n = L.size();
    int left = 0;
    int right = n - 1;
    for (left = 0; left < right; left++)
    {
        for (int i = left; i < right; i++)
        {
            Product bufer1 = L.element(i), bufer2 = L.element(i + 1);
            if (bufer1.Price > bufer2.Price)
                swapInList(L, bufer1, bufer2, i, i + 1);
        }
        right--;
        for (int i = right; i > left; i--)
        {
            Product bufer1 = L.element(i), bufer2 = L.element(i - 1);
            if (bufer1.Price < bufer2.Price)
                swapInList(L, bufer1, bufer2, i, i - 1);
        }
    }
}

void sortPeriod (List <Product> &L)
{
    int n = L.size();
    int left = 0;
    int right = n - 1;
    for (left = 0; left < right; left++)
    {
        for (int i = left; i < right; i++)
        {
            Product bufer1 = L.element(i), bufer2 = L.element(i + 1);
            if (bufer1.Period > bufer2.Period)
                swapInList(L, bufer1, bufer2, i, i + 1);
        }
        right--;
        for (int i = right; i > left; i--)
        {
            Product bufer1 = L.element(i), bufer2 = L.element(i - 1);
            if (bufer1.Period < bufer2.Period)
                swapInList(L, bufer1, bufer2, i, i - 1);
        }
    }
}

void sortName (List <Product> &L)
{
    int n = L.size();
    int left = 0;
    int right = n - 1;
    for (left = 0; left < right; left++)
    {
        for (int i = left; i < right; i++)
        {
            Product bufer1 = L.element(i), bufer2 = L.element(i + 1);
            if (!alphabetS1S2(bufer1.Name, bufer2.Name))
                swapInList(L, bufer1, bufer2, i, i + 1);
        }
        right--;
        for (int i = right; i > left; i--)
        {
            Product bufer1 = L.element(i), bufer2 = L.element(i - 1);
            if (alphabetS1S2(bufer1.Name, bufer2.Name))
                swapInList(L, bufer1, bufer2, i, i - 1);
        }
    }
}

void sortProducer (List <Product> &L)
{
    int n = L.size();
    int left = 0;
    int right = n - 1;
    for (left = 0; left < right; left++)
    {
        for (int i = left; i < right; i++)
        {
            Product bufer1 = L.element(i), bufer2 = L.element(i + 1);
            if (!alphabetS1S2(bufer1.Producer, bufer2.Producer))
                swapInList(L, bufer1, bufer2, i, i + 1);
        }
        right--;
        for (int i = right; i > left; i--)
        {
            Product bufer1 = L.element(i), bufer2 = L.element(i - 1);
            if (alphabetS1S2(bufer1.Producer, bufer2.Producer))
                swapInList(L, bufer1, bufer2, i, i - 1);
        }
    }
}

void sortPriceName (List <Product> &L)
{
    int n = L.size();
    int left = 0;
    int right = n - 1;
    for (left = 0; left < right; left++)
    {
        for (int i = left; i < right; i++)
        {
            Product bufer1 = L.element(i), bufer2 = L.element(i + 1);
            if (bufer1.Price > bufer2.Price)
                swapInList(L, bufer1, bufer2, i, i + 1);
            else
                if (bufer1.Price == bufer2.Price && !alphabetS1S2(bufer1.Name, bufer2.Name))
                    swapInList(L, bufer1, bufer2, i, i + 1);
        }
        right--;
        for (int i = right; i > left; i--)
        {
            Product bufer1 = L.element(i), bufer2 = L.element(i - 1);
            if (bufer1.Price < bufer2.Price)
                swapInList(L, bufer1, bufer2, i, i - 1);
            if (bufer1.Price == bufer2.Price && alphabetS1S2(bufer1.Name, bufer2.Name))
                swapInList(L, bufer1, bufer2, i, i - 1);
        }
    }
}


List <Product> NamePrice (List <Product> L, string NAME, double PRICE, bool Parameter)
{
    List <Product> NP;
    int s = L.size();
    Product bufer;
    for (int i = 0; i < s; i++)
    {
        bufer = L.element(i);
        if (bufer.Name == NAME && (Parameter || bufer.Price <= PRICE))
            NP.push_back(bufer);
    }
    sortPrice(NP);
    return NP;
}

int findInListString (string str, List <string> StrL)
{
    int s = StrL.size();
    for (int i = 0; i < s; i++)
        if (str == StrL.element(i))
            return i; /// there is this name in our list
    return -1; /// this name is new
}

List <Product> a9 (List <Product> L, string NAME)
{
    return NamePrice(L, NAME, 0, true);
}

List <Product> d9 (List <Product> L, string NAME, double PRICE)
{
    return NamePrice(L, NAME, PRICE, false);
}

List <Product> b9 (List <Product> L)
{
    List <string> NamesL;
    List <double> SumL;
    List <int> QuantityL;
    int s = L.size();
    Product bufer;
    for (int i = 0; i < s; i++)
    {
        bufer = L.element(i);
        int position = findInListString(bufer.Name, NamesL);
        if (position != -1)
        {
            SumL.new_data(SumL.element(position) + bufer.Price, position);
            QuantityL.new_data(QuantityL.element(position) + 1, position);
        }
        else
        {
            NamesL.push_back(bufer.Name);
            SumL.push_back(bufer.Price);
            QuantityL.push_back(1);
        }
    }
    List <Product> bL;
    int sNamesL = NamesL.size();
    for (int i = 0; i < sNamesL; i++)
    {
        Product bufer;
        bufer.Name = NamesL.element(i);
        bufer.Price = SumL.element(i) / QuantityL.element(i);
        bL.push_back(bufer);
    }
    sortName(bL);
    return bL;
}

List <Product> c9 (List <Product> L)
{
    List <string> ProducersL;
    List <string> NamesL;
    int s = L.size();
    for (int i = 0; i < s; i++)
    {
        Product bufer = L.element(i);
        int position = findInListString(bufer.Producer, ProducersL);
        if (position == -1)
            ProducersL.push_back(bufer.Producer);
        position = findInListString(bufer.Name, NamesL);
        if (position == -1)
            NamesL.push_back(bufer.Name);
    }
    int sP = ProducersL.size(), sN = NamesL.size();
    bool ProducerName [sP][sN];
    for (int i = 0; i < sP; i++)
        for (int j = 0; j < sN; j++)
            ProducerName[i][j] = 0;
    for (int i = 0; i < s; i++)
    {
        Product bufer = L.element(i);
        int positionP = findInListString(bufer.Producer, ProducersL);
        int positionN = findInListString(bufer.Name, NamesL);
        ProducerName[positionP][positionN] = 1;
    }
    List <Product> cL;
    for (int i = 0; i < sP; i++)
    {
        Product bufer;
        bufer.Producer = ProducersL.element(i);
        int sum = 0;
        for (int j = 0; j < sN; j++)
            sum += ProducerName[i][j];
        bufer.Quantity = sum;
        cL.push_back(bufer);
    }
    sortProducer(cL);
    return cL;
}

List <Product> e9 (List <Product> L)
{
    List <Product> eL;
    int s = L.size();
    for (int i = 0; i < s; i++)
        eL.push_back(L.element(i));
    sortPriceName(eL);
    return eL;
}

List <Product> f9 (List <Product> L, int PERIOD)
{
    List <Product> fL;
    int s = L.size();
    Product bufer;
    for (int i = 0; i < s; i++)
    {
        bufer = L.element(i);
        if (bufer.Period > PERIOD)
            fL.push_back(bufer);
    }
    sortPeriod(fL);
    return fL;
}

int main9()
{
    cout << "1. Input.txt with information about products (ProductID, Name, UPC, Producer, Price, Period (period of storage), Quantity)" << endl;
    cout << "Output: " << endl;

    List <Product> L;

    Product P;
    string bufer;
    int counter = 0;

    ifstream fin("Input.txt");
    for (int i = 0; i < 7; i++)
        fin >> bufer;

    while (!fin.eof())
    {
        fin >> bufer;
        switch (counter)
        {
            case 0:
            {
                P.ProductID = bufer;
                break;
            }
            case 1:
            {
                P.Name = bufer;
                break;
            }
            case 2:
            {
                P.UPC = string_to_int(bufer);
                break;
            }
            case 3:
            {
                P.Producer = bufer;
                break;
            }
            case 4:
            {
                P.Price = string_to_double(bufer);
                break;
            }
            case 5:
            {
                P.Period = string_to_int(bufer);
                break;
            }
            case 6:
            {
                P.Quantity = string_to_int(bufer);
                counter = -1;
                L.push_back(P);
                break;
            }
        }
        counter++;
    }

    cout << endl; /// a)

    cout << "a) The list of items for the set name " << endl;
    cout << "Please, enter the name: ";
    string NAME;
    cin >> NAME;
    fout << "a) " << endl;
    printListProduct(a9(L, NAME), "1465023");

    cout << endl; /// b)
    fout << endl; /// b)

    cout << "b) Average price of each name of a product " << endl;
    fout << "b) " << endl;
    printListProduct(b9(L), "14");

    cout << endl; /// c)
    fout << endl; /// c)

    cout << "c) Total of names of each producer " << endl;
    fout << "c) " << endl;
    printListProduct(c9(L), "36");

    cout << endl; /// d)
    fout << endl; /// d)

    cout << "d) The list of items for the set name which price doesn't surpass the set price " << endl;
    cout << "Please, enter the name: ";
    cin >> NAME;
    cout << "Please, enter the price: ";
    double PRICE;
    cin >> PRICE;
    fout << "d) " << PRICE << endl;
    printListProduct(d9(L, NAME, PRICE), "1465023");

    cout << endl; /// e)
    fout << endl; /// e)

    cout << "e) The general list of items (Price, Name, ProductID, UPC, Producer) ordered at the price and the name " << endl;
    fout << "e) " << endl;
    printListProduct(e9(L), "41023");

    cout << endl; /// f)
    fout << endl; /// f)

    cout << "f) The list of products (PeriodOfStorage, Quantity, Name, ProductID, UPC, Producer) with service life (is more than set service life), the list is ordered on a period of storage " << endl;
    cout << "Please, enter the period of storage: ";
    int PERIOD;
    cin >> PERIOD;
    fout << "f) " << endl;
    printListProduct(f9(L, PERIOD), "561023");
    return 0;
}

