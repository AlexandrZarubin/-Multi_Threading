#include<iostream>
#include<mutex>
#include<thread>
#include"Timer.h"
using namespace std;

/*
	Многопоточное програмирование

		      mutex

	 защита разделяемых данных

       синхронизация потоков
*/
mutex mtx;
void Print(char ch)
{
	this_thread::sleep_for(chrono::milliseconds(2000));
	mtx.lock();
	cout << "id потока =  " << this_thread::get_id()<<"\tstart" << endl;
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t i = 0; i < 10; i++)
		{
			cout << ch;
			this_thread::sleep_for(chrono::milliseconds(20));
		}
		cout << endl;
	}
	cout << "id потока =  " << this_thread::get_id()<<"\tstop\n" << endl;
	mtx.unlock();
	this_thread::sleep_for(chrono::milliseconds(2000));
}
int main()
{
	setlocale(LC_ALL, "rus");
	Timer timer;
	thread t1(Print, '*');
	thread t2(Print, '#');
	
	t1.join();
	t2.join();
	/*Print('*');
	Print('#');*/

	return 0;
}