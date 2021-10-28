#include <iostream>
#include <string>

using namespace std;

//�ۑ�P�@n�̒��������z��̗v�f�̒l�����Ƀf�B�X�v���C�ɕ\������֐��B
void disparray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ",";
    }
    cout << endl;
}

//�ۑ�Q�@�z��̗v�f���ׂĂ����{�ɂ���֐��B
void multiply(int a[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i] * k;
    }
}

//�ۑ�R�@����a�̐���������i�A����������d�Ɋi�[����֐��B
void intdec(double a, int& i, double& d)
{
    i = (int)a;
    d = a - i;
}

//�ۑ�S�@����c1��c2��A�������������Ԃ��֐��B
string mergechars(char c1, char c2)
{
    string value = "";
    value += c1;  value += c2;
    return value;
}

//�ۑ�T�@����n�̕����z��c���񕶂ł��邩�ǂ������肷��֐��B
int palindrome(char c[], int n)
{
    string c_copy = "";
    string rev_c = "";
    c_copy = c;
    for (int i = n - 2; i >= 0; i--)
    {
        rev_c += c[i];
    }
    if (c_copy == rev_c) return 1;
    return 0;
}

//�ۑ�U�@�����z��c���񕶂ł��邩�ǂ������肷��֐��B
//�z��̒������s���ł����s�\�B
int palindrome(char c[])
{
    string c_copy = "";
    string rev_c = "";
    c_copy = c;
    for (int i = c_copy.size() - 1; i >= 0; i--)
    {
        rev_c += c_copy[i];
    }
    if (c_copy == rev_c) return 1;
    return 0;
}

//�ۑ�V�@�w�Ny�Ɣԍ�i����͂��A���w�Ȃ̊w�Дԍ��𐶐����ĕԂ��֐��B
string studentid(int y, int i)
{
    string id_num = "A";
    if (i < 100) id_num += "0";
    return "HT" + to_string(y) + id_num + to_string(i);
}

//�ۑ�W�@�����z��̒��g��2�Ԗڂɑ傫�����̗v�f��Ԃ��֐��B
int secondlargest(int a[], int n)
{
    int value = a[0];
    bool IsFoundF = false;

    for (int i = 1; i < n; i++)
    {
        cout << a[i] << endl;
        if (value < a[i])
        {
            if (IsFoundF) return a[i];
            else value = a[i];
            IsFoundF = true;
        }
    }
    return value;
}

int main()
{
    //�ۑ�1�̃e�X�g
    int a_01[] = { 1,5,3,56,2,6 };
    disparray(a_01, 6);

    //�ۑ�2�̃e�X�g
    int a_02[] = { 7,5,8,4,7,0,2 };
    multiply(a_02, 7, 2);
    disparray(a_02, 7);

    //�ۑ�3�̃e�X�g
    double a_03 = 3.1415;
    int aa_03 = 0;
    double aaa_03 = 0;
    intdec(a_03, aa_03, aaa_03);
    cout << "i:" << aa_03 << ", d:" << aaa_03 << endl;

    //�ۑ�4�̃e�X�g
    char a04_1 = 'H', a04_2 = 'T';
    cout << mergechars(a04_1, a04_2) << endl;

    //�ۑ�5�̃e�X�g
    //�񕶂̉p�P��̗�@level, madam, dad, mom, pop, wow, peep,,,�Ȃ�
    char a05[] = "level";
    cout << palindrome(a05, 6) << endl;
    char a05_1[] = "levels";
    cout << palindrome(a05_1, 7) << endl;

    //�ۑ�6�̃e�X�g
    char a06[] = "madam";
    cout << palindrome(a06) << endl;
    char a06_1[] = "adam";
    cout << palindrome(a06_1) << endl;

    //�ۑ�7�̃e�X�g
    cout << studentid(21, 99) << endl;

    //�ۑ�8�̃e�X�g
    int a08[] = { 1,5,4,9,6,7,0 };
    cout << secondlargest(a08, 7);

    return 0;
}