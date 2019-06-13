#include <iostream>
using namespace std;

void Max(int x, int y)
{
	cout << "1: Max(int,int)" << endl;
}

template<class T>
void Max(T x, T Y)
{
	cout << "2:Max(T,T)" << endl;
}

int main()
{
	int nx = 10, ny = 20;
	Max(nx,ny);
	return 0;
}
