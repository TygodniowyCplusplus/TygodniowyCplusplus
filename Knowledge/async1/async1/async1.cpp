// async1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <future>
#include <thread>

using namespace std;

int fun(int a)
{
	this_thread::sleep_for(chrono::seconds(a));
	return a + 1;
}

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

int main()
{
	cout << "Hello World!\n";
	
	std::future<int> result0 = async(launch::async, fun, 1);
	cout << "async: " << result0.get() << endl;

	packaged_task<int(int)> task{ fun };
	future<int> result = task.get_future();
	thread t1(move(task), 2);
	t1.detach();
	cout << "thread: " << result.get() << endl;
	return 0;
}