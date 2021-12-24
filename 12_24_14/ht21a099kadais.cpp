#include <iostream>
#include <random>

using namespace std;

#define LINE cout << "--------------------" << endl;
#define KADAI(n) cout << "----------Kadai" << n << "----------" << endl;
#define ARYLOOP for(int i = 0;i < n;i++){
#define END }


//Kadai2
//���t��\���\����
struct ymd
{
	int year;
	int month;
	int day;
};

//�Ǝ��ɒǉ������֐��B

//���t�\���̔z���S�ďo�͂���֐��B
void dispymd(ymd dt[], int n)
{
	ARYLOOP;
	cout << dt[i].year << "/"
		<< dt[i].month << "/"
		<< dt[i].day << endl;
	END;
}

//�K���ȓ��t��ݒ肵�܂��B
void SetRandymd(ymd& dt, int ymax = 2030, int mmax = 12, int dmax = 30)
{
	random_device randdev;
	dt.year = randdev() % ymax + 1;
	dt.month = randdev() % mmax + 1;
	dt.day = randdev() % dmax + 1;
}

//�\���̔z��ɓK���ȓ��t���i�[���܂��B
void SetRandymds(ymd dts[], int n, int ymax = 2030, int mmax = 12, int dmax = 30)
{
	ARYLOOP;
	random_device randdev;
	dts[i].year = randdev() % ymax + 1;
	dts[i].month = randdev() % mmax + 1;
	dts[i].day = randdev() % dmax + 1;
	END;
}

//�w�肵�����t��S�Ă̔z��v�f�Ɋi�[���܂��B
void SetYMDs(ymd dts[], int n, int y, int m, int d)
{
	ARYLOOP;
	dts[i] = { y,m,d };
	END;
}

//���t����A�S�Ă���t�ɕϊ������l��Ԃ��܂��B
//���ɑ傫�Ȓl���\�������̂ŁA�ő�l���傫������^��I���B
unsigned int GetDay(ymd dt)
{
	unsigned int sday = 
		dt.year * 365 + 
		dt.month * 30 +
		dt.day;
	return sday;
}

//�z����Ŏw�肵����v�f�����ւ��܂��B
template<typename T> void Swap(T values[], int n, int IdxA, int IdxB)
{
	T value = values[IdxA];
	values[IdxA] = values[IdxB];
	values[IdxB] = value;
}

//-------------------------------------------------------------------------------------------

//Kadai1
//���邤�N���ǂ�����Ԃ��֐��B
int uru(int y)
{
	if (y % 4 == 0) return 1;
	return 0;
}

//Kadai3
//���t�̍\���̂�����t��\������֐��B
void dispymd(ymd dt)
{
	cout << dt.year << "/"
		<< dt.month << "/"
		<< dt.day << endl;
}

//Kadai4
//�w�肵���N�ƍ��v������t�̌���Ԃ��֐��B
int countyear(ymd dt[], int n, int y)
{
	int cnt = 0;
	ARYLOOP;
	if (dt[i].year == y) cnt++;
	END;
	return cnt;
}

//Kadai5
//���t�Ƃ��Ă̐��������m�F����֐��B�������Ȃ��ꍇ��1��Ԃ��A
//�������ꍇ�ɂ�0��Ԃ��܂��B
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
//��̓��t���r���Adt2��葁�����t�̏ꍇ��1�A
//dt2���x�����t�̏ꍇ�ɂ́|1�A�������ꍇ�ɂ�0��Ԃ��܂��B
int compymd(ymd dt1, ymd dt2)
{
	unsigned int sdt1 =
		dt1.year * 365 +
		dt1.month * 30 +
		dt1.day;
	unsigned int sdt2 =
		dt2.year * 365 +
		dt2.month * 30+
		dt2.day;
	if (sdt1 == sdt2) return 0;
	else if (sdt1 < sdt2) return 1;
	return -1;
}

//Kadai7
//�w�肵�����t�ƍ��v����ŏ��̃C���f�b�N�X�ԍ���Ԃ��֐��B
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
//���t���~���Ƀ\�[�g���܂��B
void sortymd(ymd dt[], int n)
{
	ARYLOOP;
	for (int ii = i; ii < n; ii++)
	{
		auto pivt = GetDay(dt[i]);
		auto tagt = GetDay(dt[ii]);
		if (pivt < tagt) Swap(dt, n, i, ii);
	}
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
	ymd dt3 = { 2002,11,13 };
	dispymd(dt3);

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
	const int ymdslen = 10;
	ymd dt8s[ymdslen];
	SetRandymds(dt8s, ymdslen);
	dispymd(dt8s, ymdslen);
	LINE;
	sortymd(dt8s, ymdslen);
	dispymd(dt8s, ymdslen);

	return 0;
}