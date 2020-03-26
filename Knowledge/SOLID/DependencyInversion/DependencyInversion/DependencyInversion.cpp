// DependencyInversion.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
using namespace std;

//Dependency inversion principle

//Dependency Injection

class RecepcjonistkaPoczty
{
public:
    void obslugaKlienta()
    {
        cout << "obsluguje klienta" << endl;
    }
};

class Poczta
{
    RecepcjonistkaPoczty recept1;
public:
    void zacznijObslugiwacKlientow()
    {
        cout << "zaczynam obsluge: " << endl;
        recept1.obslugaKlienta();
    }
};
///////////////////////////////////////////////////////

class IRecepcjonistkaPoczty
{
public:
    virtual void obslugaKlienta() = 0;
};

class RecepcjonistkaPoczty2 : public IRecepcjonistkaPoczty
{
public:
    void obslugaKlienta() override
    {
        cout << "obsluguje klienta" << endl;
    }
};

class Poczta2
{
    IRecepcjonistkaPoczty* recept1;
public:
    Poczta2(IRecepcjonistkaPoczty* recept1) : recept1(recept1)
    {
        ;
    }

    void zacznijObslugiwacKlientow()
    {
        cout << "zaczynam obsluge: " << endl;
        recept1->obslugaKlienta();
    }
};

int main()
{
    std::cout << "Hello World!\n";

    Poczta pocz;
    pocz.zacznijObslugiwacKlientow();

    Poczta2 pocz2(new RecepcjonistkaPoczty2());
    pocz2.zacznijObslugiwacKlientow();
}
