#include <iostream>
using namespace std;

class A{
public:
	void foo(
	{
		cout << "A: foo()" << endl;
	}
}

template<typename T>void Func()
{
	A a;
	a.foo();
	T t;
	//未知类型调用能通过
	t.foo();
}

int main()
{
	Func<A> a;
	return 0;
}
