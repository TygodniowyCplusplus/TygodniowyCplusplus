// async2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <thread>
#include <future>
#include <chrono>
#include <iostream>

using namespace std;

void waiter(future<string>&& fut)
{
	cout << fut.get() << endl;
}

int main()
{
	//C++11
	promise<string> prom;
	future<string> fut = prom.get_future();
	thread t1(waiter, move(fut));
	t1.detach();
	this_thread::sleep_for(chrono::seconds(5));
	prom.set_value("ustawiamy future");
	this_thread::sleep_for(chrono::seconds(2));
	return 0;
}
