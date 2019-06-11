#include <iostream>
using namespace std;

#define MAX(T) T max_##T(T x, T y)\
		{\
			return x > y ? x : y;\
		}

MAX(int)    
MAX(double)
MAX(string)

#define Max(T) max_##T

int main()
{
	int nx = 10, ny = 20;
	cout << Max(int)(nx,ny) << endl;
	double dx = 12.3, dy = 45.6;
	cout << Max(double)(dx, dy) << endl;
	string sx = "world", sy = "hello";
	cout << Max(string)(sx,sy) << endl;

	char cx[256] = "world", cy[256] = "hello";

	cout << Max(string)(cx,cy) << endl;
	
	return 0;
}
