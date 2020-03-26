// SingleResponsibility.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <string>

//single responsibility principle
//Nigdy nie powinno być więcej niż 
//jednego powodu do modyfikacji klasy.


using namespace std;

class Poczta
{
	string opakowanie = "*****************\n";
	vector<string> dziennikBledow;

	void zapiszBlad(string doZapisu)
	{
		dziennikBledow.push_back(doZapisu);
	}
public:
	void  wyslij(string doWyslania)
	{
		try
		{
			cout << opakowanie << doWyslania << opakowanie << endl;
		}
		catch (...)
		{
			zapiszBlad("z tym listem jest problem: \n" + doWyslania);
		}
	}

	void  wypiszBledy()
	{
		for (auto iter = dziennikBledow.begin(); iter != dziennikBledow.end(); ++iter)
		{
			cout << *iter << endl;
		}
	}
};

class Listonosz
{
	string opakowanie = "*****************\n";
public:
	void  wyslij(string doWyslania)
	{
		cout << opakowanie << doWyslania << opakowanie << endl;
	}
};

class Nadzor
{
	vector<string> dziennikBledow;
public:
	void zapiszBlad(string doZapisu)
	{
		dziennikBledow.push_back("z tym listem jest problem: \n" + doZapisu);
	}

	void  wypiszBledy()
	{
		for (auto iter = dziennikBledow.begin(); iter != dziennikBledow.end(); ++iter)
		{
			cout << *iter << endl;
		}
	}
};

class Poczta2
{
	Listonosz listonoszNr1;
	Nadzor nadzorca;
public:
	void wyslij(string doWyslania)
	{
		try
		{
			listonoszNr1.wyslij(doWyslania);
		}
		catch (...)
		{
			nadzorca.zapiszBlad(doWyslania);
		}
	}

	void  wypiszBledy()
	{
		nadzorca.wypiszBledy();
	}
};


int main()
{
    std::cout << "Hello World!\n";
	Poczta PosterunekNr1;
	PosterunekNr1.wyslij("Droga Agato.\nPozdrawiam.\n");
	PosterunekNr1.wypiszBledy();

	Poczta2 PosterunekNr2;
	PosterunekNr2.wyslij("Droga Julio.\nPozdrawiam.\n");
	PosterunekNr2.wypiszBledy();
}