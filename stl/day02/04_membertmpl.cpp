#include <iostream>
using namespace std;

template<class T>
class Array
{
public:
	T& operator[](size_t i)
	{
		return m_s[i];
	}
private:
	T m_s[10];
};

template<class D, template<class E>class C>
class Sum
{
public:
	Sum(C<D> const& s):m_s(s){}

	D add()
	{
		D d = 0;
		for(int i = 0; i < 10 ; i++)
		{
			d += m_s[i];
		}
		return d;
	}
private:
	C<D> m_s;
};
int main()
{
	Array<int> a;
	for(int i = 0; i < 10; i++)
	{
		a[i] = i + 1;
	}
	Sum<int,Array> sum(a);
	cout << sum.add() << endl;
	return 0;
}
