#include <iostream>
using namespace std;

template<class X>
class A
{
public:
	template<class Y>
	class B
	{
	public:
		template<class Z> class C;
	};
private:
};

template<class X>
template<class Y>
template<class Z>
class A<X>::B<Y>::C
{
public:
	template<class M>
	void foo()
	{
		cout << "A<X>::B<Y>::C<Z>::foo<M>" << endl;
	}
};

int main()
{
	A<int>::B<double>::C<float> c;
	c.foo<int>();
	return 0;
}
