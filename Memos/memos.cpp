//Kadai
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

#include <iostream>

using namespace std;

//Ex. (5x^2 - 2y - 20 = 0)
//1 <= x,y <= 100
int main()
{
    int x, y;
    const int max = 100;
    int ansrs[max][max];

    bool frag = false;
    for (x = 1; x < max; x++)
    {
        for (y = 1; y < max; y++)
        {
            //20x^3 - 21y - 99
            ansrs[x][y] = (20 * pow(x, 3)) - (21 * y) - 99;
            if (ansrs[x][y] == 0) frag = true;
            if (frag)
            {
                cout << "(X,Y):(" << x << "," << y << ")" << endl;
                return 0;
            }
            cout << "‰ð:" << ansrs[x][y] << endl;
        }
    }
    cout << "‰ð‚È‚µ" << endl;
    return 0;
}

#include <iostream>

using namespace std;

int main()
{
    const int xmax = 9, ymax = 9;
    int Kuku[xmax][ymax];

    cout << " | ";
    for (int x = 1; x <= xmax; x++)
    {
        cout << " " << x << " ";
        for (int y = 1; y <= ymax; y++)
        {
            Kuku[x - 1][y - 1] = x * y;
        }
    }
    cout << endl;

    cout << "-";
    for (int i = 0; i < xmax * 3; i++)
    {
        if (i == 0) cout << "+-";
        else cout << "-";
    }
    cout << endl;

    for (int x = 1; x <= xmax; x++)
    {
        cout << x << "|" << " ";
        for (int y = 1; y <= ymax; y++)
        {
            if (x * y >= 10) cout << x * y << " ";
            else cout << " " << x * y << " ";
        }
        cout << endl;
    }
    return 0;
}