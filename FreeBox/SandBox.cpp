#include <iostream>
#include <random>
#define ARYLOOP for(int i = 0;i < n;i++){ 
#define NARYLOOP(n) for(int i = 0;i < n;i++){
#define NLOOP(init) for(int t = init;t < n;t++){ 
#define DO_N(n) for(int i = 1;i <= n;i++){  
#define END } 
#define KADAI(num) cout << "----------Kadai" << num << "----------" << endl; 

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

//最大値以下で適当な小数を格納します。
void SetRandXY(XY& xy, int max)
{
	random_device randdev;
	xy.X = randdev() % max;
	xy.Y = randdev() % max;
	xy.X += (randdev() % 10) / 10.0;
	xy.Y += (randdev() % 10) / 10.0;
}
//最大値以下で適当な小数を要素全てに格納します。
void SetRandXY(XY xy[], int n, int max)
{
	ARYLOOP
		SetRandXY(xy[i], max);
	END
}

//最大値以下で適当な小数を返します。
double GetRandD(int max)
{
	random_device randev;
	double randD = randev() % max;
	randD += (randev() % 10) / 10.0;
	return randD;
}

//2点間の距離を返します。
double GetLengthAB(XY A, XY B)
{
	XY dxy =
	{
		abs(A.X - B.X),
		abs(A.Y - B.Y)
	};
	return sqrt(pow(dxy.X, 2) + pow(dxy.Y, 2));
}

double GetSum(XY A)
{
	return A.X + A.Y;
}

XY GetNearest(XY Points[], int n)
{
	XY Nearest = Points[0];
	ARYLOOP
		if (GetSum(Points[i]) < GetSum(Nearest)) Nearest = Points[i];
	END
	return Nearest;
}

XY GetFarest(XY Points[], int n)
{
	XY Farest = Points[0];
	ARYLOOP
		if (GetSum(Points[i]) > GetSum(Farest)) Farest = Points[i];
	END
	return Farest;
}

XY GetHighest(XY Points[], int n)
{
	XY Highest = Points[0];
	ARYLOOP
		if (Points[i].Y > Highest.Y) Highest = Points[i];
	END
	return Highest;
}

void ReplaceValue(XY Points[], int n, int Index)
{
	if (n - 1 == Index) return;
	XY cxy = Points[Index];
	Points[Index] = Points[n - 1];
	Points[n - 1] = cxy;
}

//
double areaof(XY xy[3])
{
	int IdxNearest = 0;
	NARYLOOP(3)
		if (GetSum(xy[i]) < GetSum(xy[IdxNearest])) IdxNearest = i;
	END
	NARYLOOP(3)
		xy[i] =
		{
			abs(xy[i].X - xy[IdxNearest].X),
			abs(xy[i].Y - xy[IdxNearest].Y)
		};
	END
	ReplaceValue(xy,3,IdxNearest);
	double Area =
		abs(xy[0].X * xy[1].Y) +
		abs(xy[1].X * xy[0].Y);
	Area /= 2;
	return Area;
}

int main()
{
	//Kadai7
	KADAI(7);
	XY Trngle[3];
	SetRandXY(Trngle, 3, 15);
	dispXY(Trngle, 3);
	cout << areaof(Trngle) << endl;
	return 0;
}
