#include <iostream>

using namespace std;

int main()
{
    const int x = 3, y = 3;
    int a[x][y];
    for (int i = 0; i < x; i++)
    {
        for (int ii = 0; ii < y; ii++)
        {
            a[i][ii] = i + ii;
            cout << i << "," << ii << endl;
        }
    }

    int sum = 0;
    for (int i = 0; i < x; i++)
    {
        for (int ii = 0; ii < y; ii++)
        {
            sum += a[i][ii];
        }
    }
    cout << "Sum:" << sum << endl;
    return 0;
}