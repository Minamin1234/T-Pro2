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
            ansrs[x][y] = (20 * pow(x,3)) - (21 * y) - 99;
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