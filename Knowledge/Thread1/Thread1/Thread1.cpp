// Thread1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void sleep(const int sec)
{
    this_thread::sleep_for(chrono::seconds(sec));
    cout << "funkcja sleep" << endl;
}

void sleep2(const int sec)
{
    this_thread::sleep_for(chrono::seconds(sec));
    cout << "funkcja sleep2" << endl;
}
struct Functor
{
    void operator()(int a)
    {
        cout << "podalismy liczbe:" << a << endl;
    }

    static void staticFun(int a)
    {
        cout << "Static:podalismy liczbe:" << a << endl;
    }

    void noStaticFun(int a)
    {
        cout << "NOStatic:podalismy liczbe:" << a << endl;
    }
};

int main()
{
    std::cout << "Hello World!\n";

    Functor Fun;
    thread t1(&Functor::noStaticFun, Fun, 3);
    std::cout << t1.get_id() << endl;
    std::cout << t1.joinable() << endl;
    t1.detach();
    std::cout << t1.joinable() << endl;
    std::cout << "main1\n";
    //sleep2(5);
    
    
    return 0;
}
