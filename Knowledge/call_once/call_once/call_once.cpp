// call_once.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <mutex>
using namespace std;

//call_once może jeszcze raz zostać wywołane jeśli poprzednim razem 
//zakończyło się rzuceniem wyjątku

once_flag flag, flag1, flag3;

void prosta_funkcja()
{
    call_once(flag, []() { cout << 
        "Wywolanie Lambdy w prosta_funkcja\n"; });
    call_once(flag1, [](int a) { cout <<
        "Wywolanie Lambdy w prosta_funkcja, int a:" << a <<
        "\n"; }, 4);
}

void prosta_funkcja2(bool ifThrow)
{
    try {
        call_once(flag3, [](bool IfThrow)
            {
                std::cout << "Wywolanie Lambdy w prosta_funkcja2\n";
                if (IfThrow)
                    throw exception();
            }, ifThrow);
    }
    catch (...) {
    }
}

int main()
{
    cout << "Hello World!\n";
    thread st1(prosta_funkcja);
    thread st2(prosta_funkcja);
    thread st3(prosta_funkcja);
    thread st4(prosta_funkcja);
    st1.join();
    st2.join();
    st3.join();
    st4.join();
    prosta_funkcja();
    prosta_funkcja();

    prosta_funkcja2(true);
    prosta_funkcja2(true);
    prosta_funkcja2(false);
    prosta_funkcja2(true);
    prosta_funkcja2(true);
}