#include<iostream>
#include<mutex>
#include<thread>
#include"Timer.h"
using namespace std;
/*
		Многопоточное програмирование

	  Взаиманая блокировка или deadlock

		  защита разделльных данных

			синхронизация потоков
*/

mutex mtx1;
mutex mtx2;

void Print()
{
	mtx1.lock();

	this_thread::sleep_for(chrono::milliseconds(1));
	mtx2.lock();

	
		//mtx.lock();
		cout << "id потока =  " << this_thread::get_id() << "\tstart" << endl;
		for (size_t i = 0; i < 5; i++)
		{
			for (size_t i = 0; i < 10; i++)
			{
				cout << "*";
				this_thread::sleep_for(chrono::milliseconds(10));
			}
			cout << endl;
		}
		cout << "id потока =  " << this_thread::get_id() << "\tstop\n" << endl;
		mtx1.unlock();
		mtx2.unlock();

	//this_thread::sleep_for(chrono::milliseconds(2000));

}
void Print2()
{
	mtx1.lock();
	mtx2.lock();

	this_thread::sleep_for(chrono::milliseconds(1));


	//mtx.lock();
	cout << "id потока =  " << this_thread::get_id() << "\tstart" << endl;
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t i = 0; i < 10; i++)
		{
			cout << "*";
			this_thread::sleep_for(chrono::milliseconds(10));
		}
		cout << endl;
	}
	cout << "id потока =  " << this_thread::get_id() << "\tstop\n" << endl;
	mtx1.unlock();
	mtx2.unlock();

	//this_thread::sleep_for(chrono::milliseconds(2000));

}
int main()
{
	setlocale(LC_ALL, "rus");
	Timer timer;

	thread t1(Print);
	thread t2(Print2);


	t1.join();
	t2.join();

	return 0;
}