#include <iostream>
#include <random>

#define ARYLOOP for(int i = 0;i < n;i++){ 
#define NARYLOOP(n) for(int i = 0;i < n;i++){
#define NLOOP(init) for(int t = init;t < n;t++){ 
#define DO_N(n) for(int i = 1;i <= n;i++){  
#define END } 
#define KADAI(num) cout << "----------Kadai" << num << "----------" << endl; 
//ARYLOOP 全ての配列内要素を取り出すためのループ
//NARYLOOP(n) n個の長さの配列の要素を取り出す為のループ
//NLOOP(init) initから始まるインデックスのループ
//DO_N 回ループします。iは現在回数を表します。
//END ループ内の処理の終端を表します。
//KADAI(num) 課題番号を出力する。

using namespace std;

struct XY
{
	double X;
	double Y;
};

//スライドでの関数

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

//独自に追加した関数

//構造体のメンバ変数を全て0に設定します。
void Initialize(XY& xy)
{
	xy = { 0,0 };
}

// 構造体配列の要素全てを0にした構造体にします。
void Initialize(XY xy[], int n)
{
	ARYLOOP
		xy[i] = { 0,0 };
	END
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

//指定したインデックスの要素を末尾に移動させます。
void ReplaceValue(XY Points[], int n, int Index)
{
	if (n - 1 == Index) return;
	XY cxy = Points[Index];
	Points[Index] = Points[n - 1];
	Points[n - 1] = cxy;
}

//指定した構造体のメンバ変数のそれぞれの合計を返します。
double GetSum(XY A)
{
	return A.X + A.Y;
}

//課題----------------------------------------------------------

//Kadai1
//構造体配列のメンバ変数yの平均値を返します。
double aveofy(XY xy[], int n)
{
	double sum = 0;
	ARYLOOP
		sum += xy[i].Y;
	END;
	sum /= n;
	return sum;
}

//Kadai2
//指定した引数から構造体を作成します。
XY createXY(double xx, double yy)
{
	XY nxy = { xx,yy };
	return nxy;
}

//Kadai3
//構造体配列xy2の要素全てを構造体x1に格納します。
void copyXY(XY xy1, XY xy2[], int n)
{
	ARYLOOP
		xy2[i] = xy1;
	END
}

//Kadai4
//指定した構造体配列の要素全てに指定した値を格納します。
void setXY(XY xy[], int n, double xx, double yy)
{
	ARYLOOP
		xy[i] = { xx,yy };
	END
}

//Kadai5
//構造体配列のそれぞれのメンバ変数の平均値を格納した構造体を返します。
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
//格納した点配列を全て順番に結んだ距離を返します。
double lengthof(XY xy[], int n)
{
	double SLen = 0;
	XY CLen = { 0,0 };
	ARYLOOP
		if (i >= n - 1) break;
		CLen.X = abs(xy[i].X - xy[i + 1].X);
		CLen.Y = abs(xy[i].Y - xy[i + 1].Y);
		SLen += sqrt(pow(CLen.X, 2) + pow(CLen.Y, 2));
	END
	return SLen;
}

//Kadai7
//三点からなる三角形の面積を返します。
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
		ReplaceValue(xy, 3, IdxNearest);
	double Area =
		abs(xy[0].X * xy[1].Y) +
		abs(xy[1].X * xy[0].Y);
	Area /= 2;
	return Area;
}

//Kadai8
//２点それぞれを結んだ際の距離を求め、最短距離を返します。
double nearestdist(XY xy[], int n)
{
	double cLength;
	double nearest = GetLengthAB(xy[0], xy[1]);
	ARYLOOP
		NLOOP(i + 1)
		if (i == t) continue;
	cLength = GetLengthAB(xy[i], xy[t]);
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
	SetRandXY(V1, 5, 10);
	dispXY(V1, 5);
	cout << lengthof(V1, 5) << endl;

	//Kadai7
	KADAI(7);
	XY Trngle[3];
	SetRandXY(Trngle, 3, 15);
	dispXY(Trngle, 3);
	cout << areaof(Trngle) << endl;

	//Kadai8
	KADAI(8);
	XY Points[10];
	SetRandXY(Points, 10, 50);
	dispXY(Points, 10);
	cout << nearestdist(Points, 10) << endl;

	return 0;
}