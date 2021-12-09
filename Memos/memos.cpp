#include <iostream>

using namespace std;

const int x_size = 3;
const int y_size = 3;

const int m_size = 3;

void set0(int a[y_size][x_size])
{
    for (int y = 0; y < y_size; y++)
    {
        for (int x = 0; x < x_size; x++)
        {
            a[y][x] = 0;
        }
    }
}

void disparray(int a[y_size][x_size])
{
    for (int y = 0; y < y_size; y++)
    {
        for (int x = 0; x < x_size; x++)
        {
            cout << a[y][x] << ",";
        }
    }
    cout << endl;
}

//�ۑ�1
void setk(int a[y_size][x_size])
{
    int sum = 0;
    for (int y = 0; y < y_size; y++)
    {
        for (int x = 0; x < y; x++)
        {
            sum += a[y][x];
        }
    }
}

//�ۑ�2
int sumof(int a[y_size][x_size])
{
    const int sx = 3, sy = 3;
    int c[sx][sy];
    for (int x = 0; x < sx; x++)
    {
        for (int y = 0; y < sy; y++)
        {
            c[x][y] = x + y;
            cout << x << "," << y << endl;
        }
    }

    int sum = 0;
    for (int y = 0; y < sy; y++)
    {
        for (int x = 0; x < sx; x++)
        {
            sum += a[y][x];
        }
    }
    cout << "Sum:" << sum << endl;
    return sum;
}

//�ۑ�3
void dispmatrix(double m[m_size][m_size])
{
    const int sx = 10, sy = 10;
    int a[sx][sy];
    for (int y = 0; y < sx; y++)
    {
        for (int x = 0; x < sy; x++)
        {
            a[y][x] = x + y;
            cout << y << "," << x << ":" << a[y][x] << endl;
        }
    }

    int max = 0;
    for (int i = 0; i < sx; i++)
    {
        for (int ii = 0; ii < sy; ii++)
        {
            if (a[i][ii] > max)
            {
                max = a[i][ii];
            }
        }
    }

    cout << "Max:" << max << endl;
}

//�ۑ�4
void s_multiply(double m[m_size][m_size], double d)
{
    int n = 10;
    int a[10][10];
    for (int x = 0; x < n; x++)
    {
        cout << a[x][x] << ",";
    }
    cout << endl;

    for (int x = 0; x < n; x++)
    {
        a[x][x] = a[x][x] * n;
    }
}

//�ۑ�5
void copymatrix(double m1[m_size][m_size], double m2[m_size][m_size])
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
                return;
            }
            cout << "��:" << ansrs[x][y] << endl;
        }
    }
    cout << "���Ȃ�" << endl;
}

int main()
{
    int b[y_size][x_size];

    //�ۑ�1�̃e�X�g
    disparray(b);

    //�ۑ�2�̃e�X�g
    cout << sumof(b) << endl;

    //�ۑ�3�̃e�X�g
    double matrix[m_size][m_size];
    dispmatrix(matrix);

    //�ۑ�4�̃e�X�g
    s_multiply(matrix, 100);

    //�ۑ�5�̃e�X�g
    double matrix2[m_size][m_size];
    copymatrix(matrix, matrix2);
}