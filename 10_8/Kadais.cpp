#include <iostream>
#include <string>

using namespace std;

//Hello�Əo�͂���֐�
void sayhello()
{
    cout << "Hello" << endl;
}

//Hello��n��o�͂���֐�
void sayhello(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Hello" << endl;
    }
}

//a��b�ő傫������l��Ԃ��֐�
/*int maxof(int a, int b)
{
    if (a > b) return a;
    return b;
}*/

//a��b�ő傫������l��Ԃ��֐�
int maxof(int a, int b)
{
    return a > b ? a : b;
}

//a,b,c�ň�ԑ傫���l��Ԃ��֐�
int maxof(int a, int b, int c)
{
    return maxof(maxof(a, b), c);
}

//[�ۑ�1]����a�̐�Βl��Ԃ��܂��B
int absof(int a)
{
    //a�����̐�����������-a��Ԃ��Breturn a*-1;�@�Ƃ��Ă����l�B
    if (a < 0) return -a;
    return a;
}

//[�ۑ�2]a��b�̂ǂ��炩����������Ԃ��܂��B
int minof(int a, int b)
{
    return (a <= b) ? a : b;
}

//[�ۑ�3]�w�肵���������n��o�͂���B
void saymsg(string msg, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << msg << endl;
    }
    return;
}

//[�ۑ�4]�����̎��ԁA���A�b����S�āA�b�P�ʂɊ��Z���܂��B
double hmstosec(int h, int m, double s)
{
    double sec = (h * (60 * 60)) + (m * 60) + s;
    return sec;
}

//[�ۑ�5]�w�肵�������̒��ōł��傫������Ԃ��܂��B
int maxof(int a, int b, int c, int d)
{
    //����ab,bc���ꂼ��ő召�֌W�𒲂ׁA�Ō�ɑ傫�����������m�ōĂё召�֌W�𒲂ׂĂ���B
    int ab = a >= b ? a : b;
    int cd = c >= d ? c : d;
    return ab >= cd ? ab : cd;
}

/*�ʉ�
�p�^�[���P(����maxof���g���񂷕��@)
int maxof(int a,int b,int c,int d)
{
    return maxof(maxof(a,b),maxof(b,c));
}

�p�^�[���Q�i�O�����Z�q�Ə���maxof���g�����@�B�L���Ҍ����j
int maxoff(int a,int b,int c,int d)
{
    return maxof(a,b) > maxof(c,d) ? maxof(a,b) : maxof(c,d);//�O�����Z�q�́u���v�炵���B
}

*/

//�����̏�������啶���ɕϊ�����������Ԃ��܂��B�������������Ŗ������p�����łȂ��ꍇ�͋�' '���Ԃ���܂��B
char getcapital(char c)
{
    if (c < 'a' || c > 'z') return ' ';//�p�q�����ł��邩�ǂ����B//�v���ȏ�̕i���@�� �Ȃ��Ă����I�ɊԈႢ�͂Ȃ�
    int Value = 'a' - 'A';//���������ő啶���ɂ��邽�߂̍������߂�B
    c = c - Value;
    return c;
}

//1���ځ`3���ڂ܂ł̐��������ꂼ�ꑫ�������v��Ԃ��܂��B
int addfig123(int a)
{
    string sa = to_string(a);
    int sum = 0;

    for (int i = sa.size() - 3; i <= sa.size() - 1; i++) sum += sa[i] - '0';
    return sum;
}

//�����̐���i���Q�i���@�\�L�ɕϊ������������Ԃ��܂��B
string itobin(int i)
{
    if (i <= 0) return "";//������0�ȉ��̎��A�ϊ����܂���B
    int value = i;
    string bin = "";//bin..�@binary�̗��A2�i���̈Ӗ�
    while (value >= 0)
    {
        if (value % 2 == 0)bin += "0";
        else bin += "1";
        value /= 2;
        if (value <= 0) break;//�ی��œ���Ă��邾���B�������[�v�͔�������
    }
    string cs = bin;
    bin = "";
    for (int i = cs.size() - 1; i >= 0; i--)//2�i���\�L��bin�̒��g�̋t�ɕ��ׂ�̂ŁA���]�����B
    {
        bin += cs[i];
    }
    return bin;
}

int main()
{
    cout << absof(-5) << "," << absof(5) << endl;//[�ۑ�1]�̃e�X�g
    cout << minof(2, 4) << endl;//[�ۑ�2]�̃e�X�g
    saymsg("OECU", 3);//[�ۑ�3]�̃e�X�g
    cout << maxof(2, 3, 5, 1) << endl;//[�ۑ�4]�̃e�X�g
    cout << hmstosec(1, 2, 3.4) << endl;//[�ۑ�5]�̃e�X�g
    cout << getcapital('c') << endl;//[�ۑ�6]�̃e�X�g
    cout << addfig123(1234) << endl;//[�ۑ�7]�̃e�X�g
    cout << itobin(21099) << endl;//[�ۑ�8]�̃e�X�g
    return 0;
}