#include <iostream>

using namespace std;

struct hms
{
    //時間
    int hour;
    //分
    int min;
    //秒
    int sec;
};

//サンプル
void disphms(hms t)
{
    cout << t.hour << "時間";
    cout << t.min << "分";
    cout << t.sec << "秒" << endl;
}

//Kadai1
//全てのメンバ変数を初期値0にして返します。
hms createhms()
{
    hms nhms = { 0,0,0 };
    return nhms;
}

//Kadai2
//時間と分を分単位の合計を返します。秒単位は無視します。
int hmstomin(hms t)
{
    return t.hour * 60 + t.min;
}

//Kadai3
//時間、分、秒を秒単位の合計を返します。
int hmstosec(hms t)
{
    return t.hour * (60 * 60) + t.min * 60 + t.sec;
}

//Kadai4
//時間の構造体のメンバ変数の値をそれぞれの変数に格納します。
void gethms(hms t, int& h, int& m, int& s)
{
    h = t.hour;
    m = t.min;
    s = t.sec;
}

//Kadai5
//秒数から時間の構造体を作成し返します。
hms createhms(int s)
{
    hms nhms =
    {
        s / 3600,
        (s % 3600) / 60,
        (s % 3600) % 60
    };
    return nhms;
}

//Kadai6
//時間の構造体に指定した秒数を加算した時間を格納します。
void addsec(hms& t, int s)
{
    t.sec += s;
    t.min += t.sec / 60;
    t.hour += t.min / 60;
    t.sec = t.sec % 60;
    t.min = t.min % 60;
}

//Kadai7
//二つの時間を比較し、t1がt2よりも早い時刻の場合は、1
//t2よりも遅い時刻の場合は-1,等しい場合には0を返します。
int comphms(hms t1, hms t2)
{
    unsigned int t1s = t1.hour * 3600 + t1.min * 60 + t1.sec;
    unsigned int t2s = t2.hour * 3600 + t2.min * 60 + t2.sec;
    if (t1s < t2s)  return 1;
    else if (t1s > t2s) return -1;
    else return 0;
}

//Kadai8
//それぞれの時間を加算した時間(構造体)を返します。
hms addhms(hms t1, hms t2)
{
    hms nhms =
    {
        t1.hour + t2.hour,
        t1.min + t2.min,
        t1.sec + t2.sec
    };
    nhms.min += nhms.sec / 60;
    nhms.hour += nhms.min / 60;
    nhms.sec = nhms.sec % 60;
    nhms.min = nhms.min % 60;
    return nhms;
}

//独自に追加した関数
//「-----------Kadai----------」と指定した課題番号を出力します。
void DispKadai(int KadaiNum)
{
    cout << "----------Kadai" << KadaiNum << "----------" << endl;
}

int main()
{
    hms a = { 1,20,30 };
    disphms(a);

    //Kadai1
    DispKadai(1);
    hms t = createhms();
    disphms(t);

    //Kadai2
    DispKadai(2);
    t = { 1,23,45 };
    cout << hmstomin(t) << endl;

    //Kadai3
    DispKadai(3);
    t = { 1,23,45 };
    cout << hmstosec(t) << endl;

    //Kadai4
    DispKadai(4);
    int h, m, s;
    t = { 10,5,0 };
    gethms(t,h,m,s);
    cout << "h:" << h << "m:" << m << "s:" << s << endl;

    //Kadai5
    DispKadai(5);
    disphms(createhms(5025));

    //Kadai6
    DispKadai(6);
    t = { 1,59,59 };
    addsec(t, 1);
    disphms(t);

    //Kadai7
    DispKadai(7);
    hms t1 = { 9,0,0 };//9:00
    hms t2 = { 9,30,0 };//9:30
    cout << comphms(t1, t2) << endl;

    //Kadai8
    DispKadai(8);
    t1 = { 2,30,30 };
    t2 = { 1,30,30 };
    disphms(addhms(t1, t2));

    return 0;
}