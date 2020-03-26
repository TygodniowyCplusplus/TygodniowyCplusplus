// liskov_substitution.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Liskov substitution - Zasada podstawiania Liskov

//W miejscu klasy bazowej można użyć dowolnej klasy pochodnej

//Łamiemy tę zasadę np gdy metody w klasie bazowej po której 
//dziedziczymy nie mają nic wspólnego z klasą pochodną

//chodzi o to aby nie zgubić sensu klasy bazowej

class Paczka
{
public:
	virtual void owinPapierem()
	{
		cout << "owijam paczke papierem" << endl;
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

class List : public Paczka
{
public:
	void wlozWKoperte()
	{
		cout << "wkladam w koperte" << endl;
	}
	void owinPapierem() override
	{
		;//listów się nie wowija papierem
	}
};

class Przesylka
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

class List2 : public Przesylka
{
public:
	void dodajObudowe() override
	{
		cout << "wkladam w koperte" << endl;
	}
};

int main()
{
    std::cout << "Hello World!\n";

	Paczka* pacz;
	pacz = new List;

	pacz->owinPapierem();
	pacz->napiszAdres();
	pacz->dodajznaczek();

	Przesylka* prze;
	prze = new List2;
	prze->dodajObudowe();
	prze->napiszAdres();
	prze->dodajznaczek();
}