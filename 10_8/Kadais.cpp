#include <iostream>
#include <string>

using namespace std;

//Helloと出力する関数
void sayhello()
{
    cout << "Hello" << endl;
}

//Helloをn回出力する関数
void sayhello(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Hello" << endl;
    }
}

//aとbで大きい方を値を返す関数
/*int maxof(int a, int b)
{
    if (a > b) return a;
    return b;
}*/

//aとbで大きい方を値を返す関数
int maxof(int a, int b)
{
    return a > b ? a : b;
}

//a,b,cで一番大きい値を返す関数
int maxof(int a, int b, int c)
{
    return maxof(maxof(a, b), c);
}

//[課題1]引数aの絶対値を返します。
int absof(int a)
{
    //aが負の整数だったら-aを返す。return a*-1;　としても同様。
    if (a < 0) return -a;
    return a;
}

//[課題2]aとbのどちらか小さい方を返します。
int minof(int a, int b)
{
    return (a <= b) ? a : b;
}

//[課題3]指定した文字列をn回出力する。
void saymsg(string msg, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << msg << endl;
    }
    return;
}

//[課題4]引数の時間、分、秒から全て、秒単位に換算します。
double hmstosec(int h, int m, double s)
{
    double sec = (h * (60 * 60)) + (m * 60) + s;
    return sec;
}

//[課題5]指定した引数の中で最も大きい数を返します。
int maxof(int a, int b, int c, int d)
{
    //引数ab,bcそれぞれで大小関係を調べ、最後に大きかった数同士で再び大小関係を調べている。
    int ab = a >= b ? a : b;
    int cd = c >= d ? c : d;
    return ab >= cd ? ab : cd;
}

/*別解
パターン１(初代maxofを使い回す方法)
int maxof(int a,int b,int c,int d)
{
    return maxof(maxof(a,b),maxof(b,c));
}

パターン２（三項演算子と初代maxofを使う方法。有識者向け）
int maxoff(int a,int b,int c,int d)
{
    return maxof(a,b) > maxof(c,d) ? maxof(a,b) : maxof(c,d);//三項演算子は「悪」らしい。
}

*/

//引数の小文字を大文字に変換した文字を返します。引数が小文字で無いか英文字でない場合は空白' 'が返されます。
char getcapital(char c)
{
    if (c < 'a' || c > 'z') return ' ';//英子文字であるかどうか。//要件以上の品質　→ なくても問題的に間違いはない
    int Value = 'a' - 'A';//同じ文字で大文字にするための差を求める。
    c = c - Value;
    return c;
}

//1桁目～3桁目までの数字をそれぞれ足した合計を返します。
int addfig123(int a)
{
    string sa = to_string(a);
    int sum = 0;

    for (int i = sa.size() - 3; i <= sa.size() - 1; i++) sum += sa[i] - '0';
    return sum;
}

//引数の整数iを２進数法表記に変換した文字列を返します。
string itobin(int i)
{
    if (i <= 0) return "";//引数が0以下の時、変換しません。
    int value = i;
    string bin = "";//bin..　binaryの略、2進数の意味
    while (value >= 0)
    {
        if (value % 2 == 0)bin += "0";
        else bin += "1";
        value /= 2;
        if (value <= 0) break;//保険で入れてあるだけ。無限ループは避けたい
    }
    string cs = bin;
    bin = "";
    for (int i = cs.size() - 1; i >= 0; i--)//2進数表記はbinの中身の逆に並べるので、反転処理。
    {
        bin += cs[i];
    }
    return bin;
}

int main()
{
    cout << absof(-5) << "," << absof(5) << endl;//[課題1]のテスト
    cout << minof(2, 4) << endl;//[課題2]のテスト
    saymsg("OECU", 3);//[課題3]のテスト
    cout << maxof(2, 3, 5, 1) << endl;//[課題4]のテスト
    cout << hmstosec(1, 2, 3.4) << endl;//[課題5]のテスト
    cout << getcapital('c') << endl;//[課題6]のテスト
    cout << addfig123(1234) << endl;//[課題7]のテスト
    cout << itobin(21099) << endl;//[課題8]のテスト
    return 0;
}