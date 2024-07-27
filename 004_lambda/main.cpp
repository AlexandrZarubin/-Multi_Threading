#include<iostream>
#include<chrono>
#include<thread>
using namespace std;

/*
	многопоточное програмирование
	Получение результатов работы функций из потока
*/
int Sum(int a, int b)
{
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "id потока =  " << this_thread::get_id() << "===========\tDoWork STARTED\t=========" << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));

	cout << "id потока =  " << this_thread::get_id() << "===========\tDoWork STOPPED\t=========" << endl;
	return a + b;
}
int main()
{
	setlocale(LC_ALL, "rus");
	//int result = Sum(2, 5);
	//cout << "Sum result = " << result << endl;
	int result;
	//thread t([]() {});
	/*

		auto f=[&result]()
		{
		result=Sum(2,5);
		};


	*/


	thread t([&result]() {result = Sum(2, 5); });
	for (size_t i = 0; i < 10; i++)
	{
		cout << "id потока =  " << this_thread::get_id() << "\tmain\t" << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
	t.join();
	cout << "Sum result = " << result << endl;
	return 0;
}