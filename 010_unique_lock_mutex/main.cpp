#include<iostream>
#include<thread>
#include<mutex>
#include"Timer.h"

using namespace std;
/*
	многопоточное програмирование

			unique_lock

	  защита разделяемых данных

	    синхронизация потокав
*/

mutex mx;

void Print(char ch)
{
	
	unique_lock<mutex>ul(mx,std::defer_lock);
	this_thread::sleep_for(chrono::milliseconds(2000));
	//lock_guard<mutex>lg(mx);
	//mx.lock();
	ul.lock();
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t i = 0; i < 10; i++)
		{
			cout << ch;
			this_thread::sleep_for(chrono::milliseconds(10));
		}
		cout << endl;
	}
	cout << endl;
	ul.unlock();
	
	//mx.unlock();
	this_thread::sleep_for(chrono::milliseconds(2000));
}

int main()
{
	Timer timer;
	setlocale(LC_ALL, "rus");
	thread t1(Print, '*');
	thread t2(Print, '#');
	t1.join();
	t2.join();

	return 0;
}