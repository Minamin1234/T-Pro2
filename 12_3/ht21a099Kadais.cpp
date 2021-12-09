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

//課題1
//二次元配列の要素を全てkにする関数。
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


//課題2
//二次元配列の要素の全ての合計を返します。
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

//課題3
//二次元配列の要素を行列の表記で要素を出力する関数
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

//課題4
//行列の要素をそれぞれd倍（スカラー倍）する関数
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

//課題5
//二次元配列m1の要素を同様の配列m2にコピーする関数
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

//課題6
//二次元配列m1,m2の和をm3に格納する関数。
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

//課題7
//指定した二次元配列（行列）を転置する関数。
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

//課題8
//二次元配列（行列）m1,m2の積をm3に格納する関数
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


//独自に追加した関数

//課題番号を出力する関数。
void dispKadai(int KadaiNum)
{
    cout << "Kadai" << KadaiNum << endl;
}

//setkの汎用的な関数。
//特定の型に依存せず、int型やdouble型でも適用することができる。
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

//最大値以内で適当な数を行列にセットする
template <typename T> void setRand(T mtrx[m_size][m_size], int max)
{
    for (int ii = 0; ii < m_size; ii++)
    {
        for (int i = 0; i < m_size; i++)
        {
            mtrx[ii][i] = rand() % (max + 1);
        }
    }
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