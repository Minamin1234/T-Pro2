#include <iostream>
#include <random>

#define ARYLOOP for(int i = 0;i < n;i++){
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

//

//
void Initialize(XY& xy)
{
	xy = { 0,0 };
}

// 
void Initialize(XY xy[], int n)
{
	ARYLOOP
		xy[i] = { 0,0 };
	END
}

//Å‘å’lˆÈ‰º‚Å“K“–‚È¬”‚ðŠi”[‚µ‚Ü‚·B
void SetRandXY(XY& xy, int max)
{
	random_device randdev;
	xy.X = randdev() % max;
	xy.Y = randdev() % max;
	xy.X += (randdev() % 10) / 10.0;
	xy.Y += (randdev() % 10) / 10.0;
}

void SetRandXY(XY xy[], int n, int max)
{
	ARYLOOP
		SetRandXY(xy[i], max);
	END
}

double GetRandD(int max)
{
	random_device randev;
	double randD = randev() % max;
	randD += (randev() % 10) / 10.0;
	return randD;
}

double GetLengthAB(XY A, XY B)
{
	XY dxy =
	{
		abs(A.X - B.X),
		abs(A.Y - B.Y)
	};
	return sqrt(pow(dxy.X, 2) + pow(dxy.Y, 2));
}

//Kadai1
double aveofy(XY xy[], int n)
{
	double sum = 0;
	NLOOP(0)
		sum += xy[t].Y;
	END;
	sum /= n;
	return sum;
}

//Kadai2
XY createXY(double xx, double yy)
{
	XY nxy = { xx,yy };
	return nxy;
}

//Kadai3
void copyXY(XY xy1, XY xy2[], int n)
{
	ARYLOOP
		xy2[i] = xy1;
	END
}

//Kadai4
void setXY(XY xy[], int n, double xx, double yy)
{
	ARYLOOP
		xy[i] = { xx,yy };
	END
}

//Kadai5
XY aveofxy(XY xy[], int n)
{
	XY aveXY = { 0,0 };
	ARYLOOP
		aveXY.X += xy[i].X;
		aveXY.Y += xy[i].Y;
	END;
	aveXY.X /= n;
	aveXY.Y /= n;
	return aveXY;
}

//Kadai6
double lengthof(XY xy[], int n)
{
	double SLen = 0;
	XY CLen = { 0,0 };
	ARYLOOP
		CLen.X = abs(xy[i].X - xy[i + 1].X);
		CLen.Y = abs(xy[i].Y - xy[i + 1].Y);
		SLen += sqrt(pow(CLen.X, 2) + pow(CLen.Y, 2));
		if (i >= n - 1) break;
	END
	return SLen;
}

//Kadai7
double areaof(XY xy[])
{
	double lowrLen = abs(xy[0].X - xy[2].X);
	double height = abs(xy[0].Y - xy[1].Y);
	return (lowrLen * height) / 2;
}

//Kadai8
double nearestdist(XY xy[], int n)
{
	double cLength;
	double nearest = GetLengthAB(xy[0], xy[1]);
	ARYLOOP
		NLOOP(0)
			if(i == t) continue;
			cLength = GetLengthAB(xy[i],xy[t]);
			if (cLength < nearest) nearest = cLength;
		END
	END
	return nearest;
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

	//Kadai1
	KADAI(1)
	cout << aveofy(pt, 3) << endl;

	//Kadai2
	KADAI(2)
	double x = GetRandD(50);
	double y = GetRandD(50);
	cout << x << "," << y << endl;
	XY v = createXY(x, y);
	dispXY(v);

	//Kadai3
	KADAI(3);
	XY v1 = { 20,2 };
	XY V[5];
	copyXY(v1, V, 5);
	dispXY(v1);
	dispXY(V, 5);

	//Kadai4
	KADAI(4);
	XY V1[5];
	setXY(V1, 5, 1, 2);
	dispXY(V1, 5);

	//Kadai5
	KADAI(5);
	SetRandXY(V1, 5, 10);
	dispXY(V1, 5);
	dispXY(aveofxy(V1, 5));

	//Kadai6
	KADAI(6);

	KADAI(7);
	KADAI(8);

	return 0;
}