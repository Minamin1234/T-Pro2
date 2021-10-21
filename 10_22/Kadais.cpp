#include<iostream>;
#include<string>;

using namespace std;

void disparray(int s[5])
{
    for (int i = 0; i < 5; i++)
    {
        cout << s[i] << ", ";
    }
    cout << endl;
}

void disparray(int s[], int n)
{
    for (int i = 0; i < n ; i++)
    {
        cout << s[i] << ", ";
    }
    cout << endl;
}

void set0(int s[], int n)//配列を引数に取る場合は参照渡し?
{
    for (int i = 0; i < n; i++)
    {
        s[i] = 0;
    }
}

int sumof(int s[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += s[i];
    }

    return sum;
}

int maxof(int a[], int n)
{
    int max_a = a[0];
    for (int i = 1; i < n; i++)
    {
        if (max_a < a[i])
        {
            max_a = a[i];
        }
    }
    
    return max_a;
}

int count0(int a[], int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0) cnt++;
    }

    return cnt;
}

int find0(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0) return i;
    }
    return -1;
}

//KadaiFuncs

//Kadai_01
void setk(int a[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = k;
    }
}

//Kadai_02
double averageof(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return (double)sum / n;
}

//Kadai_03
int minof(int a[], int n)
{
    int min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (min > a[i]) min = a[i];
    }
    return min;
}

//Kadai_04
int countk(int a[], int n, int k)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == k) c++;
    }

    return c;
}

//Kadai_05;
int findk(int a[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == k) return i;
    }

    return -1;
}

//Kadai_06
void copyarray(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
}

//Kadai_07
int innerproduct(int a[], int b[], int n)
{
    //ex.二つの二次元ベクトルの内積は(a1 * b1) + (a2 * b2).
    int value = 0;
    for (int i = 0; i < n; i++)
    {
        value += a[i] * b[i];
    }

    return value;
}

//Kadai_08
int findc(char s[], char c)
{
    for (int i = 0;s[i] != '\0'; i++)
    {
        if (s[i] == c) return i;
    }

    return -1;
}

//Sample01
/*
int main()
{
    int a[5] = { 10,30,50,70,90 };
    disparray(a);//>> 10, 30, 50, 70, 90,

    return 0;
}
*/

//Sample02
/*
int main()
{
    int a[5] = { 10,30,50,70,90 };
    disparray(a, 5);//>> 10, 30, 50, 70, 90,

    return 0;
}
*/

//Sample03
/*
int main()
{
    int a[5] = { 10,30,50,70,90 };
    set0(a, 5);//参照渡しの現象。
    disparray(a, 5);//>> 0, 0, 0, 0, 0,
    return 0;
}
*/

//Sample04_(1)
/*
int main()
{
    int a[3] = { 1,2,3 };
    cout << sumof(a, 3) << endl;//>> 6
    return 0;
}
*/

//Sample05_(2)
/*
int main()
{
    int a[5] = { 3,5,2,6,1 };
    cout << maxof(a, 5) << endl;

    return 0;
}
*/

//Kadai_01
int main()
{
    //Kadai_01
    const int arraysize = 10;
    int a[arraysize];
    setk(a, arraysize, 5);
    disparray(a, arraysize);

    //Kadai_02
    int a2[] = { 1,1,3,4,5 };
    cout << averageof(a2, 5) << endl;

    //Kadai_03
    int a3[] = { 3,2,8,1,6 };
    cout << minof(a3, 5) << endl;

    //Kadai_04
    int a4[] = { 1,5,6,6,7,4 };
    cout << countk(a4, 6, 6) << endl;

    //Kadai_05
    int a5[] = { 8,1,4,6,1 };
    cout << findk(a5, 5, 1) << endl;

    //Kadai_06
    int a6[] = { 8,3,6,3,7 };
    int a6_1[5];
    copyarray(a6, a6_1, 5);
    disparray(a6_1, 5);

    //Kadai_07
    int a7[] = { 1,4 };
    int a7_1[] = { 5,3 };
    cout << innerproduct(a7, a7_1, 2) << endl;

    //Kadai_08
    char a8[] = "HT21A099";
    cout << findc(a8, 'A');

    return 0;
}