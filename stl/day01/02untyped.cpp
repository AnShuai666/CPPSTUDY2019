#include <iostream>
using namespace std;
#define MAX(x,y) (x>y?x:y)
int main()
{
	int nx = 10, ny = 20;
	cout << MAX(nx,ny) << endl;

	double dx = 12.3, dy = 45.6;
	cout << MAX(dx,dy) << endl;

	string sx = "world", sy = "hello";
	cout << MAX(sx,sy) << endl;
	return 0;
}
