#include <iostream>

using namespace std;

const int x_size = 3;
const int y_size = 3;

const int m_size = 3;

void set0(int a[y_size][x_size])
{
    for (int ii = 0; ii < y_size; ii++)
    {
        for (int i = 0; i < x_size; i++)
        {
            a[ii][i] = 0;
        }
    }
}

void disparray(int a[y_size][x_size])
{
    for (int ii = 0; ii < y_size; ii++)
    {
        for (int i = 0; i < x_size; i++)
        {
            cout << a[ii][i] << ",";
        }
    }
    cout << endl;
}

void setk(int a[y_size][x_size],int k)
{
    for (int ii = 0; ii < y_size; ii++)
    {
        for (int i = 0; i < x_size; i++)
        {
            a[ii][i] = k;
        }
    }
}

template <typename T> void setx(T mtrx[m_size][m_size], T x)
{
    for (int ii = 0; ii < m_size; ii++)
    {
        for (int i = 0; i < m_size; i++)
        {
            mtrx[ii][i] = x;
        }
    }
}

template <typename T> void setRand(T mtrx[m_size][m_size], int max)
{
    for (int ii = 0; ii < m_size; ii++)
    {
        for (int i = 0; i < m_size; i++)
        {
            mtrx[ii][i] = rand() % ( (int)max + 1);
        }
    }
}

int sumof(int a[y_size][x_size])
{
    int sum = 0;
    for (int ii = 0; ii < y_size; ii++)
    {
        for (int i = 0; i < x_size; i++)
        {
            sum += a[ii][i];
        }
    }
    return sum;
}



void dispmatrix(double m[m_size][m_size])
{
    for (int ii = 0; ii < m_size; ii++)
    {
        cout << "|";
        for (int i = 0; i < m_size; i++)
        {
            cout.width(3);
            cout << m[ii][i] << " ";
        }
        cout << "|" << endl;
    }
    cout << endl;
}

void s_multiply(double m[m_size][m_size], double d)
{
    for (int ii = 0; ii < m_size; ii++)
    {
        for (int i = 0; i < m_size; i++)
        {
            m[ii][i] *= d;
        }
    }
}

void copymatrix(double m1[m_size][m_size], double m2[m_size][m_size])
{
    for (int ii = 0; ii < m_size; ii++)
    {
        for (int i = 0; i < m_size; i++)
        {
            m2[ii][i] = m1[ii][i];
        }
    }
}

void m_add(double m1[m_size][m_size],
    double m2[m_size][m_size],
    double m3[m_size][m_size])
{
    for (int ii = 0; ii < m_size; ii++)
    {
        for (int i = 0; i < m_size; i++)
        {
            m3[ii][i] = m1[ii][i] + m2[ii][i];
        }
    }
}

void transpose(double m[m_size][m_size])
{
    double nm[m_size][m_size];
    for (int ii = 0; ii < m_size; ii++)
    {
        for (int i = 0; i < m_size; i++)
        {
            nm[ii][i] = m[ii][i];
        }
    }

    for (int ii = 0; ii < m_size; ii++)
    {
        for (int i = 0; i < m_size; i++)
        {
            m[ii][i] = nm[i][ii];
        }
    }
}

void  m_multiply(double m1[m_size][m_size],
    double m2[m_size][m_size],
    double m3[m_size][m_size])
{
    for (int y = 0; y < m_size; y++)
    {
        for (int x = 0; x < m_size; x++)
        {
            double value = 0;
            for (int l = 0; l < m_size; l++)
            {
                value += m1[y][l] * m2[l][x];
            }
            m3[y][x] = value;
        }
    }
}

void dispKadai(int KadaiNum)
{
    cout << "Kadai" << KadaiNum << endl;
}

int main()
{
    int b[y_size][x_size];
    set0(b);
    disparray(b);

    //課題1のテスト
    dispKadai(1);
    setk(b, 5);
    disparray(b);

    //課題2のテスト
    dispKadai(2);
    disparray(b);
    cout << sumof(b) << endl;

    //課題3のテスト
    dispKadai(3);
    double mtrx[m_size][m_size];
    setRand<double>(mtrx, 5);
    dispmatrix(mtrx);

    //課題4のテスト
    dispKadai(4);
    setRand<double>(mtrx, 7);
    dispmatrix(mtrx);
    s_multiply(mtrx, 2);
    dispmatrix(mtrx);

    //課題5のテスト
    dispKadai(5);
    double mtrx2[m_size][m_size];
    setRand(mtrx, 10);
    dispmatrix(mtrx);
    copymatrix(mtrx, mtrx2);
    dispmatrix(mtrx2);

    //課題6のテスト
    dispKadai(6);
    double mtrx3[m_size][m_size];
    setRand(mtrx, 10);
    setRand(mtrx2, 20);
    dispmatrix(mtrx);
    dispmatrix(mtrx2);
    m_add(mtrx, mtrx2, mtrx3);
    dispmatrix(mtrx3);

    //課題7のテスト
    dispKadai(7);
    setRand(mtrx, 5);
    dispmatrix(mtrx);
    transpose(mtrx);
    dispmatrix(mtrx);

    
    //課題8のテスト
    dispKadai(8);
    setRand(mtrx, 5);
    setRand(mtrx2, 15);
    setx<double>(mtrx3, 0);
    dispmatrix(mtrx);
    dispmatrix(mtrx2);
    dispmatrix(mtrx3);
    m_multiply(mtrx, mtrx2, mtrx3);
    dispmatrix(mtrx3);
    return 0;
}