#include <iostream>

using namespace std;

struct XY
{
	double X;
	double Y;
};

void dispXY(XY xy)
{
	cout << "(" << xy.X << "," << xy.Y << ")" << endl;
}

void ktimeXY(XY& xy, double k)
{
	xy.X *= k;
	xy.Y *= k;
}

void dispXY(XY xy[], int n)
{
	for (int i = 0; i < n; i++)
	{
		dispXY(xy[i]);
	}
}

int main()
{
	XY pt[3] =
	{
		{1.0,2.0},
		{3.0,4.0},
		{5.0,6.0}
	};
	dispXY(pt,3);

	return 0;
}