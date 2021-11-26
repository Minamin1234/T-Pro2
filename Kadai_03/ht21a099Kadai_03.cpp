#include <iostream>

using namespace std;

int main()
{
    const int x = 10, y = 10;
    int rmax = 50;
    int a[x][y];
    for (int i = 0; i < x; i++)
    {
        for (int ii = 0; ii < y; ii++)
        {
            a[i][ii] = rand() % rmax; //0~49
            cout << i << "," << ii << ":" << a[i][ii] << endl;
        }
    }

    int imax = 0;
    for (int i = 0; i < x; i++)
    {
        for (int ii = 0; ii < y; ii++)
        {
            if (a[i][ii] > imax)
            {
                imax = a[i][ii];
            }
        }
    }

    cout << "Max:" << imax << endl;
    return 0;
}