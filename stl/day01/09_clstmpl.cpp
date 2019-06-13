#include <iostream>
using namespace std;

template<class T>
class CMath
{
public:
	CMath(T const& t1, T const& t2)
		:m_t1(t1),m_t2(t2)
	{
	}

	T sum()
	{
		return m_t1 + m_t2;
	}
private:
	T m_t1;
	T m_t2;
	
};

class Integer
{
public:
	Integer(int const& i):m_i(i){}

	Integer operator+(Integer const& rh)
	{
		return m_i + rh.m_i;
	}

	friend ostream& operator<<(ostream& os, Integer const& rh)
	{
		return os << rh.m_i;
	}
private:
	int m_i;
};


int main()
{
	Integer ix = 100, iy = 200;
	CMath<Integer> math4(ix,iy);
	cout << math4.sum() << endl;

	return 0;
}
