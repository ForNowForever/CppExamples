// test1.cpp: 定义控制台应用程序的入口点。
//
#include <iostream>
using namespace std;

class Base
{
public:
	Base(int val = 0) :m_x(val) {}
	Base(const Base& oth) :m_x(oth.m_x) {}
public:
	int m_x;
};
class Derived :public Base
{
public:
	Derived(int val) :Base(val), m_y(val) {}
	Derived(const Derived& oth) :m_y(oth.m_y) {}
public:
	int m_y;
};

int main(int argc, char *argv[])
{
	Derived d1(10);
	Derived d2 = d1;
	cout << d2.m_x << "," << d2.m_y << endl;

	getchar();
	return 0;
}
