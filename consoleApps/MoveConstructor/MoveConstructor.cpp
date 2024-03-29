// MoveConstructor.cpp: 定义控制台应用程序的入口点。
//
#include <iostream>
#include <vector>

class A
{
public:
	int x;
	A(int x) { this->x = x; std::cout << "Constructor, this->x="<< this->x<< std::endl ; }
	A(const A&a) {  x = a.x; std::cout << "Copy Constructor, a.x=" << a.x << std::endl; }
	A(const A&&a) noexcept { x = a.x; std::cout << "Move Constructor, a.x=" << a.x << std::endl; }
	A& operator = (const A&) { std::cout << "Assign Constructor" << std::endl; return *this; }
	//~A() {}
};


A getA()
{
	A a(10);
	return a;
}
A getA(A a)
{
	std::cout << "getA(A a), x =  " << a.x << std::endl;
	//a.x *= 10;
	return a;
}

int main()
{
	//A c = 100;
	////A b = A(11);
	////A a = c;
	//getA(c);
	////getA(A(2));
	////A a = getA();
	////std::cout << "a.x = " << a.x << std::endl;
	//
	////A b;
	////b = getA();

	std::vector<A> vec(1,-1);
	vec.emplace_back(1);
	//vec.emplace_back(12);
	//vec.push_back(123);


	getchar();
	return 0;
}
