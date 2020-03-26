// vptr_vTable.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Przesylka //vtable vptr
{
public:
	virtual void dodajObudowe()
	{
		cout << "dodaj obudowe" << endl;
	}
	virtual void  napiszAdres()
	{
		cout << "pisze adres" << endl;
	}
	virtual void  dodajznaczek()
	{
		cout << "dodaje znaczek" << endl;
	}
};

class List2 : public Przesylka //vtable vptr
{
public:
	void dodajObudowe() override
	{
		//Przesylka::dodajObudowe();
		cout << "wkladam w koperte" << endl;
	}
};

int main()
{
    std::cout << "Hello World!\n";

	Przesylka* prze;
	prze = new List2;
	prze->dodajObudowe();
	//prze->Przesylka::dodajObudowe();
	prze->napiszAdres();
	prze->dodajznaczek();
}
