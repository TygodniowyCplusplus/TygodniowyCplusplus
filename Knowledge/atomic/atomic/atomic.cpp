// atomic.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <atomic>
#include <chrono>
#include <thread>
#include <string>

// atomic zapewnia niepodzielność podstawowych operacji
// takich jak przypisania i odczytu.
// atomic mówi kompilatorowi aby nie robił, nadmiernych
// optymalizacji w kontekście data race.
// load() - w atomowy sposób uzyskuje wartość zmiennej
// atomowej.
using namespace std;

atomic<bool> data_ready = false;
string dat = "nie przygotowane dane";

void set_data_ready()
{
    this_thread::sleep_for(chrono::milliseconds(100));
    dat = "przygotowano dane";
    data_ready = true;
}

int main()
{
    thread t1(set_data_ready);
    t1.detach();
    while (!data_ready.load())
    {
        this_thread::sleep_for(chrono::milliseconds(1));
    }
    cout << dat << endl;
}

