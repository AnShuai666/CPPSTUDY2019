#include <iostream>
using namespace std;

template<class T>
class A
{
public:
	static void print()
	{
		cout << "&m_i:" << &m_i << "," << "&m_t" << &m_t << endl;
	}
	static int m_i;
	static T m_t;
};

template<class T> int A<T>::m_i = 0;
template<class T> T A<T>::m_t;

int main()
{
	A<int> a,b;
	a.print();
	b.print();
	A<int>::print();
	A<double> a1,b1;
	a1.print();
	b1.print();
	A<double>::print();
	return 0;
}
