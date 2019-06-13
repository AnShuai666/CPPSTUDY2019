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

//类模板的帽子不能丢，一定要用类名引用成员函数

int main()
{
	int nx = 10, ny = 20;
	CMath<int> math1(nx,ny);
	cout << math1.sum() << endl;

	double dx = 12.3, dy = 45.6;
	CMath<double> math2(dx,dy);
	cout << math2.sum() << endl;

	string sx = "hello", sy = "world";
	CMath<string> math3(sx,sy);
	cout << math3.sum() << endl;
	
	return 0;
}
