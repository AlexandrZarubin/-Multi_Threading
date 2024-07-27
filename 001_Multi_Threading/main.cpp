#include<iostream>
#include<thread> //потоки 
#include<chrono>//со временем

using namespace std;

/*
	многопоточное програмирование
	потоки
	thread
*/
void DoWork()
{
	for (size_t i = 0; i < 10; i++)
	{
		cout << "id потока =  " << this_thread::get_id() << "\tDoWork\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(2000));
	}
}
int main()
{
	setlocale(LC_ALL, "rus");

	//cout << "strat main" << endl;
	thread th(DoWork);
	thread th2(DoWork);
	//thread th3(DoWork);
	//th.detach();//пока работает основной поток

	//DoWork();


	for (size_t i = 0; i < 10; i++)
	{
		cout << "id потока =  " << this_thread::get_id() << "\tmain\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
	th.join();//независимы поток
	th2.join();//независимы поток
	//th3.join();//независимы поток



	return 0;
}