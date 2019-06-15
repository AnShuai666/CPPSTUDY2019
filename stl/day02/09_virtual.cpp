#include <iostream>
using namespace std;

template<class T>
class Base
{
public:
	virtual void foo()
	{
		cout << "Base<T>::foo()" << endl;
	}
};

template<class T, class D>
class Derived : public Base<T>
{
public:
	virtual void foo()
	{
		cout << "Derived<T,D>::foo()" << endl;
	}
	
	//virtual template<class C> void func(){}//成员函数模板不可以加virtual
};

int main()
{
	Derived<int,int> d;
	Base<int> *pBase = &d;
	
	pBase->foo();
	return 0;
}
