#include <iostream>
using namespace std;

class Integer
{
public:
	Integer():m_i(0){}
	friend ostream& operator<<(ostream& os, Integer const& that)
	{
		return os << that.m_i;
	}
private:
	int m_i;

};

template<class T>
void Func()
{
	T t = T();//零值初始化 每种数据类型都有零值
	cout << "t = " << t << endl;
}

template<class T>
class CMath
{
public:
	CMath():m_t(T()){};
private:
	T m_t;
};
int main()
{
	Func<int>();
	Func<Integer>();
	return 0;
}
