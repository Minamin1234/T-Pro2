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

void set0(int s[], int n)//”z—ñ‚ğˆø”‚Éæ‚éê‡‚ÍQÆ“n‚µ?
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

    }
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
    set0(a, 5);//QÆ“n‚µ‚ÌŒ»ÛB
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

int main()
{
    int a[5] = { 3,5,2,6,1 };
    cout << maxof(a, 5) << endl;

    return 0;
}