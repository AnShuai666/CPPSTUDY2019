#include <iostream>
#include <string.h>
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

template<> 
class CMath<char* const>
{
public:
	CMath(char* const& t1,char* const& t2):m_t1(t1),m_t2(t2){}
	char *const sum()
	{
		return strcat(m_t1,m_t2);
	}
private:
	char* const m_t1;
	char* const m_t2;
};


int main()
{
	int nx = 100, ny = 200;
	CMath<int> math(nx,ny);
	cout << math.sum() << endl;

	double dx = 12.3, dy = 45.6;
	CMath<double> math2(dx,dy);
	cout << math2.sum() << endl;

	string sx = "hello", sy = "world";
	CMath<string> math3(sx,sy);
	cout << math3.sum() << endl;

	char cx[256] = "hello";
	char cy[256] = "world";
	CMath<char* const> math4(cx,cy);
	cout << math4.sum() << endl;

	return 0;
}
