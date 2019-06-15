#include <iostream>
using namespace std;

class A
{
public:
	class B
	{
	public:
		void foo()
		{
			cout << "A::B::foo()" << endl;
		}
	};
};

template<class T>
void Func()
{
	typename T::B b; //生命Ｂ不是静态成员变量，而是嵌套类型
	b.foo();
}

int main()
{
	return 0;
}
