// bind.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <functional>
using namespace std;

void napisz(int a, string str)
{
    cout << "int a:" << a
        << ", string :" << str << endl;
}

void napisz2(int a, string str, int b)
{
    cout << "int a:" << a
        << ", string :" << str
        << ", int b:" << b << endl;
}

int napisz3(int a, string str)
{
    cout << "int a:" << a << " ,string :" << str << endl;
    return 3;
}

int napisz4() { return 3; }

int main()
{
    std::cout << "Hello World!\n";

    auto f = bind(napisz, 2, "rr");
    f();

    int b = 4;
    auto f2 = bind(napisz, ref(b), "rr");
    b = 9;
    f2();

    auto f3 = bind(napisz2, 2, placeholders::_1, placeholders::_2);
    f3("tt",4);
    auto f4 = bind(napisz2, 2, placeholders::_2, placeholders::_1);
    f4(4,"zamiana", 4, 5, "werwerwe"); //polykanie

    auto f5 = bind(f4, 7, "zamiana2");
    f5();

    auto f6 = bind(napisz3, ref(b), "rr");
    cout << f6() << endl;

    auto f7 = bind(napisz2, placeholders::_2,"gg", placeholders::_1);
    f7(4,5);

    auto f8 = bind(napisz4);
    cout << f8() << endl;
}