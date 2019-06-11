#include <iostream>
using namespace std;

template<class T>
T Max(T x, T y)
{
	return x > y ? x : y;
}

int main()
{
	int nx = 10, ny = 20;
	cout << Max<int>(nx, ny) << endl;

	double dx = 12.3, dy = 45.6;
	cout << Max<double>(dx, dy) << endl;

	string sx = "world", sy = "hello";
	cout << Max<string>(sx,sy) << endl;
	return 0;
}
