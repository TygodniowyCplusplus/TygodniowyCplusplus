// condition_variable.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex m;
condition_variable cv;
bool ready = false;

string dat = "data";

void task() 
{
	unique_lock<mutex> ul(m);
	cv.wait(ul, [] {return ready; });
	dat += " task";
	cout << dat << endl;
	dat = "data";
}

int main()
{
	thread t1(task), t2(task), t3(task);
	t1.detach();
	t2.detach();
	t3.detach();
	char k;
	{
		lock_guard<mutex> lg(m);
		cin >> k;
		dat += " main";
		cout << dat << endl;
		dat = "data";
		ready = true;
	}
	cv.notify_all();
	cin >> k;
	return 0;
}