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

int main()
{
    int a[5] = { 10,30,50,70,90 };
    disparray(a);//>> 10, 30, 50, 70, 90,

    return 0;
}
