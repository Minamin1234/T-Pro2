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

//�ۑ�1
//�񎟌��z��̗v�f��S��k�ɂ���֐��B
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


//�ۑ�2
//�񎟌��z��̗v�f�̑S�Ă̍��v��Ԃ��܂��B
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

//�ۑ�3
//�񎟌��z��̗v�f���s��̕\�L�ŗv�f���o�͂���֐�
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

//�ۑ�4
//�s��̗v�f�����ꂼ��d�{�i�X�J���[�{�j����֐�
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

//�ۑ�5
//�񎟌��z��m1�̗v�f�𓯗l�̔z��m2�ɃR�s�[����֐�
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

//�ۑ�6
//�񎟌��z��m1,m2�̘a��m3�Ɋi�[����֐��B
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

//�ۑ�7
//�w�肵���񎟌��z��i�s��j��]�u����֐��B
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

//�ۑ�8
//�񎟌��z��i�s��jm1,m2�̐ς�m3�Ɋi�[����֐�
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


//�Ǝ��ɒǉ������֐�

//�ۑ�ԍ����o�͂���֐��B
void dispKadai(int KadaiNum)
{
    cout << "Kadai" << KadaiNum << endl;
}

//setk�̔ėp�I�Ȋ֐��B
//����̌^�Ɉˑ������Aint�^��double�^�ł��K�p���邱�Ƃ��ł���B
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

//�ő�l�ȓ��œK���Ȑ����s��ɃZ�b�g����
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

    //�ۑ�1�̃e�X�g
    dispKadai(1);
    setk(b, 5);
    disparray(b);

    //�ۑ�2�̃e�X�g
    dispKadai(2);
    disparray(b);
    cout << sumof(b) << endl;

    //�ۑ�3�̃e�X�g
    dispKadai(3);
    double mtrx[m_size][m_size];
    setRand<double>(mtrx, 5);
    dispmatrix(mtrx);

    //�ۑ�4�̃e�X�g
    dispKadai(4);
    setRand<double>(mtrx, 7);
    dispmatrix(mtrx);
    s_multiply(mtrx, 2);
    dispmatrix(mtrx);

    //�ۑ�5�̃e�X�g
    dispKadai(5);
    double mtrx2[m_size][m_size];
    setRand(mtrx, 10);
    dispmatrix(mtrx);
    copymatrix(mtrx, mtrx2);
    dispmatrix(mtrx2);

    //�ۑ�6�̃e�X�g
    dispKadai(6);
    double mtrx3[m_size][m_size];
    setRand(mtrx, 10);
    setRand(mtrx2, 20);
    dispmatrix(mtrx);
    dispmatrix(mtrx2);
    m_add(mtrx, mtrx2, mtrx3);
    dispmatrix(mtrx3);

    //�ۑ�7�̃e�X�g
    dispKadai(7);
    setRand(mtrx, 5);
    dispmatrix(mtrx);
    transpose(mtrx);
    dispmatrix(mtrx);

    
    //�ۑ�8�̃e�X�g
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