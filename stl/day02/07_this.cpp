#include <iostream>
using namespace std;

template<class T>
class Base
{
public:
	int m_i;
	void foo()
	{
		cout << "Base<T>::foo()" << endl;
	}

};

template<class T,class D>
class Derived : public Base<T>
{
public:
	void func()
	{
		Base<T>::m_i = 10;
		this->foo();
	}


};

int main()
{
	Derived<int,int> d;
	d.foo();
	return 0;
}
