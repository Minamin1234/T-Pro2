#include <iostream>
#include <string>

using namespace std;

//課題１
//小文字abcdをそれぞれ大文字にした状態で返す関数。
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

//課題2
//ABCDのどれかを指定して、それぞれのメッセージを表示する関数。
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

//指定したiの符号に応じて値返す関数。正の整数なら１、負の場合は－1、
//０の場合は０を返します。
int signof(int i)//voidで良いのだろうか？？
{
    if (i < 0) return -1;
    if (i > 0) return 1;
    return 0;
}

//課題4
//指定した個数の金額を割引された状態の値を返す関数。
int nedan(int k)
{
    int total = 100 * k;
    if (k >= 50) total *= 0.7;
    else if (k >= 20) total *= 0.8;
    else if (k >= 10) total *= 0.9;
    return total;
    //ifの順序に注意する
}

//課題５
//0－15の整数を16進数に変換した文字列を返す関数。
char dechex(int k)//戻り値型はint で良いのか？？
{
    if (k >= 0 && k <= 15)
    {
        if (k >= 0 && k <= 9) return '0' + k;
        else if (k >= 10 && k <= 15) return 'A' + (k - 10);//(k - 10)は10からの差
    }
    return '\0';
}

//課題6
//入力された点数を元に、ABCD評価を返す関数。
char gradepoint(int k)
{
    if (k < 0 || k > 100) return '\0';
    if (k <= 59) return 'D';
    else if (k <= 69) return 'C';
    else if (k <= 79) return 'B';
    return 'A';
}

//課題7
//指定した16進数の文字列を10進数の整数にした値を返す関数。
int hexdec(char c)
{
    if (c < '0') return -1;
    if (c > 'F') return -1;
    if (c >= '0' && c <= '9') return (int)(c - '0');
    else if (c >= 'A') return 10 + (int)(c - 'A');
    return -1;
}

//課題8
//指定した10進数整数を16進数表記にした文字列を返す関数。
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
    cout << ABCD('c') << endl; //課題１の確認
    dispmsg('B');//課題２の確認
    cout << signof(-10) << endl; // 課題3の確認
    cout << nedan(25) << endl; //課題4の確認
    cout << dechex(10) << endl; //課題5の確認
    cout << gradepoint(65) << endl; //課題6の確認
    cout << hexdec('B') << endl; //課題7の確認
    cout << hexstr(104) << endl; //課題8の確認
    return 0;
}