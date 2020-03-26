// open_closed_principle.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//open for extension, but closed for modification

enum class TypPrzesylki
{
	Lux,
	Kur,
	StdPlus,
	Std
};

class Listonosz
{
	string opLux = "*****************\n";
	string opKurierskie = "+++++++++++++++++\n";
	string opStdPlus = "&&&&&&&&&&&&&&&&&\n";
	string opStandard = "-----------------\n";
public:
	void  wyslij(string doWyslania, TypPrzesylki typ)
	{
		if (typ == TypPrzesylki::Lux)
			cout << opLux << doWyslania << opLux << endl;
		else if (typ == TypPrzesylki::Kur)
			cout << opKurierskie << doWyslania << opKurierskie << endl;
		else if (typ == TypPrzesylki::StdPlus)
			cout << opStdPlus << doWyslania << opStdPlus << endl;
		else
			cout << opStandard << doWyslania << opStandard << endl;
	}
};


class IWysylka
{
public:
	virtual void wyslij(string doWyslania) = 0;
};

class WysylkaLux : public IWysylka
{
	string opLux = "*****************\n";
public:
	void wyslij(string doWyslania) override
	{
		cout << opLux << doWyslania << opLux << endl;
	}
};

class WysylkaKur : public IWysylka
{
	string opKurierskie = "+++++++++++++++++\n";
public:
	void wyslij(string doWyslania) override
	{
		cout << opKurierskie << doWyslania << opKurierskie << endl;
	}
};

class WysylkaStdPlus : public IWysylka
{
	string opStandardPlus = "&&&&&&&&&&&&&&&&&\n";
public:
	void wyslij(string doWyslania) override
	{
		cout << opStandardPlus << doWyslania << opStandardPlus << endl;
	}
};

class WysylkaStd : public IWysylka
{
	string opStandard = "-----------------\n";
public:
	void wyslij(string doWyslania) override
	{
		cout << opStandard << doWyslania << opStandard << endl;
	}
};

class Listonosz2
{
	IWysylka* wysylka;
public:
	Listonosz2(IWysylka* Wysylka)
	{
		wysylka = Wysylka;
	}

	void wyslij(string doWyslania)
	{
		wysylka->wyslij(doWyslania);
	}
};


int main()
{
    std::cout << "Hello World!\n";
	Listonosz listonoszNr1;
	listonoszNr1.wyslij("List do Tomka\n", TypPrzesylki::StdPlus);

	Listonosz2 listonoszNr2(new WysylkaStdPlus);
	listonoszNr2.wyslij("List do Maćka\n");
}
