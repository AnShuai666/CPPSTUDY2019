#include <iostream>
using namespace std;

template<class T, class D>
class CMath
{
public:
	static void foo()
	{
		cout << "1:CMath<T,D>::foo()" << endl;
	}
private:

};

template<class T>
class CMath<T,short>
{
public:
	static void foo()
	{
		cout << "2:CMath<T,short>::foo()" << endl;
	}
};

template<class T>
class CMath<T,T>
{
public:
	static void foo()
	{
		cout << "3:CMath<T,T>::foo()"<< endl;
	}
};


template<class T,class D>
class CMath<T*,D*>
{
public:
	static void foo()
	{
		cout << "4:CMath<T*,D*>::foo()" << endl;
	}
};

int main()
{
	CMath<int,double>::foo();
	CMath<int,short>::foo();
//	CMath<short,short>::foo();
	
	//匹配歧义
//	CMath<short,short>::foo()
	
	return 0;
}
