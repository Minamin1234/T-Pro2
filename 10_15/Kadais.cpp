#include <iostream>
#include <string>

using namespace std;

//(1)
void set0(int a, int& b)
{
    a = 0;
    b = 0;
}

/*int main()
{
    int x = 10,y = 20;
    set0(x,y);
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
*/

//(2)
void myswap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

/*
int main()
{
    int x = 10, y = 20;
    myswap(x,y);
    cout << "x = " <<  x << ", y = " << y << endl;
    return 0;
}
*/

void sort2(int& a, int& b)
{
    if (a > b) myswap(a, b);
}

/*
int main()
{
    int x = 20,y = 10;
    sort2(x,y);
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
*/

void setstars(string& str, int n)
{
    str.clear();
    for (int i = 0; i < n; i++) str += '*';
}

string getstars(int n)
{
    string str;
    for (int i = 0; i < n; i++) str += '*';

    return str;
}

//Kadai01
void qoutrem(int a, int b, int& q, int& r)
{
    q = a / b;
    r = a % b;
}


//Kadai02
void rotate(int& a, int& b, int& c)
{
    int tmp = a;
    a = b;
    b = c;
    c = tmp;
}

//Kadai03
void absof(int& a, int& b)
{
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
}

//Kadai04
void setchars(string& str, char c, int n)
{
    str = "";
    for (int i = 0; i < n; i++) str += c;
}

//Kadai05
void sort3(int& a, int& b, int& c)
{
    int maxab = a < b ? b : a, minab = a < b ? a : b;
    if (minab < c) a = minab;
    else a = c;
    if (maxab < c) b = maxab;
    else if (minab < c) b = c;
    else b = minab;
    if (maxab < c) c = c;
    else c = maxab;
}

//Kadai06
void gethms(int t, int& h, int& m, int& s)
{
    h = t / (3600);
    m = (t - (h * 3600)) / 60;
    s = t % ((h * 3600) + (m * 60));
}

//Kadai07
void sort4(int& a, int& b, int& c, int& d)
{
    sort2(a, b);
    sort2(c, d);
    sort2(a, c);
    sort2(b, d);
    sort2(a, d);
    sort2(b, c);
}

//Kadai08
int decomposite(int a, int& b1, int& b2)
{
    for (int i = 2; i < a; i++)
    {
        if (a % i == 0) return 1;
    }
    return 0;
}

/*
int main()
{
    string str1,str2;
    setstars(str1,10);
    cout << str1 << endl;
    str2 = getstars(10);
    cout << str2 << endl;

    return 0;
}
*/

//Kadais no Tests

int main()
{
    //Kadai_01
    int a = 10, b = 3;
    int q, r;
    qoutrem(a, b, q, r);
    cout << q << "," << r << endl;

    //Kadai02
    int c = 1;
    a = 10, b = 3;
    rotate(a, b, c);//10,3,1
    cout << a << "," << b << "," << c << endl;

    //Kadai03
    a = -10, b = 5;
    absof(a, b);
    cout << a << "," << b << "," << c << endl;

    //Kadai04
    string st = "";
    setchars(st, 'A', 5);
    cout << st << endl;

    //Kadai05
    a = 3, b = 1, c = 2;
    sort3(a, b, c);
    cout << a << "," << b << "," << c << endl;

    //Kadai06
    int t = 1200, h, m, s;//20•ª
    gethms(t, h, m, s);
    cout << "H: " << h << ", " << "M: " << m << ", S:" << s << endl;

    //Kadai07
    int d;
    a = 2, b = 6, c = 1, d = 10;
    sort4(a, b, c, d);
    cout << a << "," << b << "," << c << "," << d << endl;

    //Kadai08
    a = 0, b = 0;
    cout << decomposite(27, a, b) << endl;

    return 0;
}