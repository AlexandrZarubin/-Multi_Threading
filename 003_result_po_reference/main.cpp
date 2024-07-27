#include<iostream>
#include<string>
#include<chrono>
#include<thread>

using namespace std;

/*
	многопоточное програмирование
	получение резельтатов работы функций из потока
*/
void DoWork(int& a)
{
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "id потока =  " << this_thread::get_id() << "===========\tDoWork STARTED\t=========" << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));
	a *= 2;
	cout << "id потока =  " << this_thread::get_id() << "===========\tDoWork STOPPED\t=========" << endl;

}
int main()
{
	setlocale(LC_ALL, "rus");
	int q = 5;
	thread t(DoWork, std::ref(q));
	//t.detach();
	//DoWork(q);


	//thread th(DoWork, 5, 15);//параметры в поток в функицю
	for (size_t i = 0; i < 10; i++)
	{
		cout << "id потока =  " << this_thread::get_id() << "\tmain\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
	//t.join();//независимы поток
	cout << q << endl;
	return 0;
}