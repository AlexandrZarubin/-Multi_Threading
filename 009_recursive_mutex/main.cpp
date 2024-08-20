#include<iostream>
#include<mutex>
#include<thread>
#include"Timer.h"
using namespace std;
/*
		Многопоточное програмирование

				recursive_mutex

		  рекурсивная блокировка

			защита разделяемых данных

			синхронизация потоков
*/
recursive_mutex rm;
mutex m;
void Foo(int a)
{
	rm.lock();
	cout << a << " ";
	this_thread::sleep_for(chrono::milliseconds(300));
	if (a <= 1)
	{
		cout << endl;
		
		rm.unlock();
		return;
	}
	a--;
	Foo(a);
	rm.unlock();
}
int main()
{
	Timer timer;
	setlocale(LC_ALL, "");
	thread t1(Foo, 10);
	thread t2(Foo, 10);

	t1.join();
	t2.join();
	//Foo(10);
	return 0;
}