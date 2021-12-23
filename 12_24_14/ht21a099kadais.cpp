#include <iostream>
#include <random>

using namespace std;

#define KADAI(n) cout << "----------Kadai" << n << "----------" << endl;
#define ARYLOOP for(int i = 0;i < n;i++){
#define END }

//Kadai2
struct ymd
{
	int year;
	int month;
	int day;
};

//Kadai1
int uru(int y)
{
	if (y % 4 == 0) return 1;
	return 0;
}

//Kadai3
void dispymd(ymd dt)
{
	cout << dt.year << "/"
		<< dt.month << "/"
		<< dt.day << endl;
}

//Kadai4
int countyear(ymd dt[], int n, int y)
{
	int cnt = 0;
	ARYLOOP;
	if (dt[i].year == y) cnt++;
	END;
	return cnt;
}

//Kadai5
int checkymd(ymd dt)
{
	switch (dt.month)
	{
	case 2:
		if (dt.year % 4 == 0)
		{
			if (dt.day <= 0 || dt.day > 28) return 1;
		}
		else
		{
			if (dt.day <= 0 || dt.day > 29) return 1;
		}
	case 4:
	case 6:
	case 9:
	case 11:
		if (dt.day <= 0 || dt.day > 30) return 1;
	default:
		if (dt.day <= 0 || dt.day > 31) return 1;
	}
	if (dt.month <= 0 || dt.month > 12) return 1;
	return 0;
}

//Kadai6
int compymd(ymd dt1, ymd dt2)
{
	unsigned int sdt1 =
		dt1.year +
		dt1.month +
		dt1.day;
	unsigned int sdt2 =
		dt2.year +
		dt2.month +
		dt2.day;
	if (sdt1 == sdt2) return 0;
	else if (sdt1 < sdt2) return 1;
	return -1;
}

//Kadai7
int findymd(ymd dt[], int n, ymd comp)
{
	ARYLOOP;
	if (dt[i].year != comp.year) continue;
	if (dt[i].month != comp.month) continue;
	if (dt[i].day != comp.day) continue;
	return i;
	END;
	return -1;
}

//Kadai8


//
void dispymd(ymd dt[],int n)
{
	ARYLOOP;
	dispymd(dt[i]);
	END;
}

ymd GetRandymd(int ymax=2030, int mmax=12, int dmax=30)
{
	random_device randdev;
	ymd nymd =
	{
		randdev() % ymax + 1,
		randdev() % mmax + 1,
		randdev() % dmax + 1
	};
	return nymd;
}

void SetRandymd(ymd &dt,int ymax = 2030, int mmax = 12, int dmax = 30)
{
	random_device randdev;
	dt.year = randdev() % ymax + 1;
	dt.month = randdev() % mmax + 1;
	dt.day = randdev() % dmax + 1;
}

void SetRandymds(ymd dts[],int n, int ymax = 2030, int mmax = 12, int dmax = 30)
{
	ARYLOOP;
	random_device randdev;
	dts[i].year = randdev() % ymax + 1;
	dts[i].month = randdev() % mmax + 1;
	dts[i].day = randdev() % dmax + 1;
	END;
}

void SetYMDs(ymd dts[], int n, int y, int m, int d)
{
	ARYLOOP;
	dts[i] = { y,m,d };
	END;
}

int main()
{
	KADAI(1);
	cout << uru(2020) << "," << uru(2021) << endl;

	KADAI(2);
	ymd dt1 = { 2021,12,24 };
	dispymd(dt1);

	KADAI(3);
	dispymd(GetRandymd());

	KADAI(4);
	ymd dts[10];
	SetYMDs(dts, 10, 2022, 1, 1);
	dispymd(dts, 10);
	cout << countyear(dts, 10, 2022) << endl;

	KADAI(5);
	ymd dt5 = { 2021,12,24 };
	ymd dt52 = { 2020,2,29 };
	cout << checkymd(dt5) << endl;
	cout << checkymd(dt52) << endl;

	KADAI(6);
	ymd dt6 = { 2021,12,24 };
	ymd dt62 = { 2021,12,25 };
	cout << compymd(dt6, dt62) << endl;

	KADAI(7);
	const int ymdleng = 10;
	ymd dt7s[ymdleng];
	ymd dt7 = { 2021,12,24 };
	//SetRandymds(dt7s, ymdleng);
	SetYMDs(dt7s, ymdleng, 2021, 12, 24);
	dispymd(dt7s, ymdleng);
	cout << findymd(dt7s, ymdleng, dt7);

	KADAI(8);
	return 0;
}