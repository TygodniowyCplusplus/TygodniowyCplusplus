// templates.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

/*void print(int n)
{
    std::cout << n << std::endl;
}
void print(double n)
{
    std::cout << n << std::endl;
}
void print(float n)
{
    std::cout << n << std::endl;
}*/

template<typename T = int>
void print(T n)
{
    std::cout << n << std::endl;
}

//Jeśli, parametry wywołania funkcji w jakiś sposób zależą od
//parametrów szablonu, funkcja szablonowa sama wydedukuje typy
/*template <typename T, int count = 3> void print(int n)
{
    T a = 100.4;
    std::cout << a << " " << n << " " << count << std::endl;
}*/

template <typename T>
class MyClass
{
public:
    T a;
    void printMyClass()
    {
        std::cout << a << std::endl;
    }
};

template <typename T = int>
struct MyClass2
{
public:
    T a;
    void printMyClass();
};

template <typename T>
void MyClass2<T>::printMyClass()
{
    std::cout << a << std::endl;
}

template<int ilosc = 100>
struct Tab
{
    int tab[ilosc];
};

template< template<int N> typename C, int K>
void f(C<K>) {
    std::cout << K << std::endl;
};

template<int N>
class SomeClass {};

template<typename T>
T Sum(const T& a,const T& b)
{
    return a + b;
}

template<>
char Sum(const char& a, const char& b) //specializacja 
{
    return 0;
}

template <typename T, typename D = int> T funkcja(D number)
{
    T a = 1;
    return number * a;
}
template double funkcja<double, int>(int); //konkretyzacja 
//jawna, jak chcemy aby
//kompilator utworzył podaną instancje szablonu, nawet 
//jak nie została on użyta.
//Przy podziale kodu na pliki, może to skrócić czas kompilacji.
//Wariant 1:
//main.cpp -> używamy funkcja
//tools.h -> deklaracje szablonu
//tools.cpp -> definicje szablonu
//Przy czymś takim nie skąpiluje się program.
//Wariant 2:
//main.cpp -> używamy funkcja
//tools.h -> deklaracje i definicje szablonu
//Skompiluje się, ale z każdą zmianą w main.cpp będą 
//kompilowane też definicje szablonów.
//Wariant 3:
//main.cpp -> używamy funkcja
//tools.h -> deklaracje szablonu
//tools.cpp -> definicje szablonu i uzyto konkretyzacji jawnej
//Będzie się komilowało i nie będzie się kompilowało nadmiarowo.

template <typename T> T funkcja(double number) //specializacja 
//częściowa
{
    T a = 1;
    return number * a;
}

template <> double funkcja(double number) //specializacja 
{
    double a = 1;
    return number * a;
}

template <typename T, typename D> 
bool porownywarka(T object1, D object2)
{
    if (typeid(object1) == typeid(object2))
        return true;
    else
        return false;
}

void print2()
{
    std::cout << "Nie ma argumentow.\n";
}

//Parameter pack(since C++11) to te ...
template <typename T, typename... D>
void print2(T param1, D ... param2)
{
    std::cout << param1 << std::endl;

    print2(param2 ...);
}

template<typename ... Param>
void print3(Param ... param)
{
    auto to_string_one = [](auto t) {
        std::stringstream ss;
        ss << t;
        return ss.str();
    };
    std::vector<std::string> v{ to_string_one(param)... };
    //std::initializer_list
    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << std::endl;
    }
}

int main()
{
    std::cout << "Hello World!\n";

    /*MyClass<double> My;
    My.a = 10.1;
    My.printMyClass();

    MyClass2<> My2;
    My2.a = 10.1;
    My2.printMyClass();

    Tab<> tab;
    tab.tab[4] = 5;

    print<>(6);*/
    /*print<int>(6);
    print<int>(6.8);
    print<int>(6.7f);*/
    /*print<double,20>(6.8);
    print<float,30>(6.5f);*/

    /*SomeClass<1>  c1;
    SomeClass<2>  c2;

    f(c1); //C = SomeClass K = 1
    f(c2); //C = SomeClass K = 2*/
    
    int s = Sum<int>(10, 20);
    int s2 = Sum<char>('a', 'b');
    
    int k = 0;
    double l = 0;
    std::cout << porownywarka<decltype(k), 
        decltype(l)>(k, l) << std::endl << std::endl;
    
    print2("hello", 1, 5.3, "World");
    print2(1, 'g', "ff");
    print3("ala", 1, 5.3, "ma kota");
}

