//HT21A099 Minami Riku
//課題5
//九九の表を表示するプログラム
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
            Kuku[x-1][y-1] = x * y;
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