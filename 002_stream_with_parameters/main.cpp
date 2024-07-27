#include<iostream>
#include<string>
#include<chrono>
#include<thread>

using namespace std;

/*
	многопоточное програмирование
	Передача параметров в поток
*/
void DoWork(int a, int b)
{
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout << "===========\t" << "DoWork STARTED\t=========" << endl;
	this_thread::sleep_for(chrono::milliseconds(6000));
	cout << "a+b = " << a + b << endl;
	this_thread::sleep_for(chrono::milliseconds(1000));
	cout << "===========\t" << "DoWork STOPPED\t=========" << endl;

}
int main()
{
	setlocale(LC_ALL, "rus");
	thread th(DoWork, 5, 15);//параметры в поток в функицю
	for (size_t i = 0; true; i++)
	{
		cout << "id потока =  " << this_thread::get_id() << "\tmain\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
	th.join();//независимы поток
	return 0;
}