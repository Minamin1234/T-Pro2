#include <iostream>
#include <string>

using namespace std;

//�ۑ�P
//������abcd�����ꂼ��啶���ɂ�����ԂŕԂ��֐��B
char ABCD(char c)
{
    if (c < 'a' && c > 'd') return ' ';
    switch (c) {
    case 'a':
        c += 'A' - 'a';
        break;
    case 'b':
        c += 'B' - 'b';
        break;
    case 'c':
        c += 'C' - 'c';
        break;
    case 'd':
        c += 'D' - 'd';
        break;
    default:
        break;
    }
    return c;
}

//�ۑ�2
//ABCD�̂ǂꂩ���w�肵�āA���ꂼ��̃��b�Z�[�W��\������֐��B
void dispmsg(char c)
{
    switch (c)
    {
    case 'A':
        cout << "Excellent" << endl;
        break;

    case 'B':
        cout << "Nice" << endl;
        break;

    case 'C':
        cout << "Good" << endl;
        break;

    case 'D':
        cout << "Not Good" << endl;
        break;

    default:
        cout << "Error" << endl;
        break;
    }
}

//�w�肵��i�̕����ɉ����Ēl�Ԃ��֐��B���̐����Ȃ�P�A���̏ꍇ�́|1�A
//�O�̏ꍇ�͂O��Ԃ��܂��B
int signof(int i)//void�ŗǂ��̂��낤���H�H
{
    if (i < 0) return -1;
    if (i > 0) return 1;
    return 0;
}

//�ۑ�4
//�w�肵�����̋��z���������ꂽ��Ԃ̒l��Ԃ��֐��B
int nedan(int k)
{
    int total = 100 * k;
    if (k >= 50) total *= 0.7;
    else if (k >= 20) total *= 0.8;
    else if (k >= 10) total *= 0.9;
    return total;
    //if�̏����ɒ��ӂ���
}

//�ۑ�T
//0�|15�̐�����16�i���ɕϊ������������Ԃ��֐��B
char dechex(int k)//�߂�l�^��int �ŗǂ��̂��H�H
{
    if (k >= 0 && k <= 15)
    {
        if (k >= 0 && k <= 9) return '0' + k;
        else if (k >= 10 && k <= 15) return 'A' + (k - 10);//(k - 10)��10����̍�
    }
    return '\0';
}

//�ۑ�6
//���͂��ꂽ�_�������ɁAABCD�]����Ԃ��֐��B
char gradepoint(int k)
{
    if (k < 0 || k > 100) return '\0';
    if (k <= 59) return 'D';
    else if (k <= 69) return 'C';
    else if (k <= 79) return 'B';
    return 'A';
}

//�ۑ�7
//�w�肵��16�i���̕������10�i���̐����ɂ����l��Ԃ��֐��B
int hexdec(char c)
{
    if (c < '0') return -1;
    if (c > 'F') return -1;
    if (c >= '0' && c <= '9') return (int)(c - '0');
    else if (c >= 'A') return 10 + (int)(c - 'A');
    return -1;
}

//�ۑ�8
//�w�肵��10�i��������16�i���\�L�ɂ����������Ԃ��֐��B
string hexstr(int k)
{
    string hex = "";
    char chex = '\0';
    if (k < 0) return "0";
    int ihex = k;
    int mod;
    while (true)
    {
        mod = ihex % 16;
        if (mod < 10) chex = '0' + mod;
        else if (mod >= 10) chex = 'A' + (mod - 10);
        ihex /= 16;
        hex += chex;
        if (ihex <= 0) break;
    }
    string rhex = "";
    for (int i = 0; i < hex.size(); i++)
    {
        rhex += hex[hex.size() - (i + 1)];
    }
    return rhex;
}

int main() {
    cout << ABCD('c') << endl; //�ۑ�P�̊m�F
    dispmsg('B');//�ۑ�Q�̊m�F
    cout << signof(-10) << endl; // �ۑ�3�̊m�F
    cout << nedan(25) << endl; //�ۑ�4�̊m�F
    cout << dechex(10) << endl; //�ۑ�5�̊m�F
    cout << gradepoint(65) << endl; //�ۑ�6�̊m�F
    cout << hexdec('B') << endl; //�ۑ�7�̊m�F
    cout << hexstr(104) << endl; //�ۑ�8�̊m�F
    return 0;
}