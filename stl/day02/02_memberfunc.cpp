#include <iostream>
using namespace std;

template<class T> 
class CMath
{
public:
	template<class D>
	void foo();
	//{
	//	cout << "CMath<T>::foo<D>()" << endl;
	//}
private:
};

template<class T>
template<class D>
void CMath<T>::foo()
{
	cout << "CMath<T>::foo<D>()" << endl;
}
int main()
{
	CMath<double> m;
	m.foo<int>();
	return 0;
}
