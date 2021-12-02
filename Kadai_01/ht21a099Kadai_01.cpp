#include <iostream>

using namespace std;

int main()
{
    const int x = 10, y = 10;
    int a[x][y];
    for (int i = 0; i < x; i++)
    {
        for (int ii = 0; ii < y; ii++)
        {
            a[i][ii] = 0;
        }
    }

    for (int i = 0; i < x; i++)
    {
        for (int ii = 0; ii < y; ii++)
        {
            cout << i << "," << ii << ":";
            cout << a[i][ii] << endl;
        }
    }
    return 0;
}