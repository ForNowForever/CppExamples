// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;

class X
{
	int a, b;
	union
	{
		int c;
		char d[4];
		int e;
	};
public:
	int getb() { return b; }
	int getc() { return c; }
	int gete() { return e; }
};

class vClass
{
public:
	vClass() {};
	virtual ~vClass() {};
private:
	int m_i;
public:
	int get() {};
	int set(int i) {};
};

int main()
{
	//X x;

	//*((int*)(&x) + 1) = *((int*)(&x) + 2) = 10;
	//cout << x.getb() << endl;
	//cout << x.gete() << endl;

	cout << sizeof(vClass) << endl;
	cout << sizeof(int) << endl;



	getchar();

    return 0;
}

