#include <thread>
#include <iostream>
#include "Philosopher.h"

namespace {
using namespace std;

void func1(Philosopher&& p1)
{
	p1.takeLeftCk();
	p1.takeRightCk();
	cout << "func1 end" << endl;
}
void func2(Philosopher && p2)
{
	p2.takeLeftCk();
	p2.takeRightCk();
	cout << "func2 end" << endl;
}
void func3(Philosopher && p1, Philosopher && p2)
{
	this_thread::sleep_for(chrono::seconds(1));
	p1.dropLeftCk();
	this_thread::sleep_for(chrono::seconds(1));
	p2.dropLeftCk();
	p2.dropRightCk();
	cout << "func3 end" << endl;
}

}

int main()
{

	Chopstick cstk1("ck1"), cstk2("ck2");
	Philosopher pper1("ph1", &cstk1, &cstk2), pper2("ph2", &cstk2, &cstk1);

	thread /*t3*/(func3, pper1, pper2).detach();
	//t3.join();

	thread t1(func1, pper1);
	thread t2(func2, pper2);
	//t1.detach();
	//t2.detach();
	t1.join();
	t2.join();


	cout << ".............." << endl;

	getchar();
    return 0;
}

