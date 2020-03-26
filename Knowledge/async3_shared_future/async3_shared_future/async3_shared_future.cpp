// async2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <thread>
#include <future>
#include <chrono>
#include <iostream>

using namespace std;

void waiter(shared_future<string> fut)
{
	cout << fut.get() << endl;
}

int main()
{
	//C++11
	promise<string> prom;
	shared_future<string> fut = prom.get_future();
	thread t1(waiter, fut);
	thread t2(waiter, fut);
	thread t3(waiter, fut);
	t1.detach();
	t2.detach();
	t3.detach();
	this_thread::sleep_for(chrono::seconds(5));
	prom.set_value("ustawiamy future");
	this_thread::sleep_for(chrono::seconds(2));
	return 0;
}
