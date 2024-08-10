#include<iostream>
#include<thread>
using namespace std;

/*
	ћногопоточное програмирование
	«апуск метода класса в отдельно потоке
*/

class MyClass
{
public:
	void DoWork()
	{
		this_thread::sleep_for(chrono::milliseconds(2000));

		cout << "id потока =  " << this_thread::get_id() << "===========\tDoWork STARTED\t=========" << endl;

		this_thread::sleep_for(chrono::milliseconds(5000));

		cout << "id потока =  " << this_thread::get_id() << "===========\tDoWork STOPPED\t=========" << endl;
	}
	void DoWork2(int a)
	{
		this_thread::sleep_for(chrono::milliseconds(2000));

		cout << "id потока =  " << this_thread::get_id() << "===========\tDoWork2 STARTED\t=========" << endl;

		this_thread::sleep_for(chrono::milliseconds(5000));

		cout << "DoWork2 знчение параметра\t" << a << endl;

		cout << "id потока =  " << this_thread::get_id() << "===========\tDoWork2 STOPPED\t=========" << endl;
	}
	int Sum(int a, int b)
	{
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "id потока =  " << this_thread::get_id() << "===========\tSum STARTED\t=========" << endl;
		this_thread::sleep_for(chrono::milliseconds(5000));

		cout << "id потока =  " << this_thread::get_id() << "===========\tSum STOPPED\t=========" << endl;
		return a + b;
	}


};
int main()
{
	setlocale(LC_ALL, "rus");
	int result;
	MyClass m;
	//result=m.Sum(2, 5);
	thread t([&]() {result = m.Sum(2, 5);});
	
	thread t1([&]() {m.DoWork(); });
	thread t2(&MyClass::DoWork,m);

	thread t3(&MyClass::DoWork2,m,5);


	for (size_t i = 0; i <= 10; i++)
	{
		cout << "id потока =  " << this_thread::get_id() << "\tmain works\t"<<i << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
	t.join();
	t1.join();
	t2.join();
	t3.join();
	cout << "RESULT\t" << result << endl;
	return 0;
}