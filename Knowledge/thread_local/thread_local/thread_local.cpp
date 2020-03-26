// thread_local.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <thread>

//using namespace std;

void f(int n)
{
    thread_local int i = n;
    int j = n;
    static int k = n;
    std::cout << i++ << " " << j++ << " " << k++ << std::endl;
}


int main()
{
    std::thread t([] { f(1); f(1); f(1); });
    t.join();
    std::thread t2([] { f(1); f(1); f(1); });
    t2.join();
    return 0;
}