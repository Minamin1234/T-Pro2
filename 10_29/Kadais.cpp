#include <iostream>
#include <string>

using namespace std;

//課題１　nの長さを持つ配列の要素の値を順にディスプレイに表示する関数。
void disparray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ",";
    }
    cout << endl;
}

//課題２　配列の要素すべてをｋ倍にする関数。
void multiply(int a[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = a[i] * k;
    }
}

//課題３　小数aの整数部分をi、小数部分をdに格納する関数。
void intdec(double a, int& i, double& d)
{
    i = (int)a;
    d = a - i;
}

//課題４　文字c1とc2を連結した文字列を返す関数。
string mergechars(char c1, char c2)
{
    string value = "";
    value += c1;  value += c2;
    return value;
}

//課題５　長さnの文字配列cを回文であるかどうか判定する関数。
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

//課題６　文字配列cが回文であるかどうか判定する関数。
//配列の長さが不明でも実行可能。
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

//課題７　学年yと番号iを入力し、情報学科の学籍番号を生成して返す関数。
string studentid(int y, int i)
{
    string id_num = "A";
    if (i < 100) id_num += "0";
    return "HT" + to_string(y) + id_num + to_string(i);
}

//課題８　整数配列の中身で2番目に大きい数の要素を返す関数。
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
    //課題1のテスト
    int a_01[] = { 1,5,3,56,2,6 };
    disparray(a_01, 6);

    //課題2のテスト
    int a_02[] = { 7,5,8,4,7,0,2 };
    multiply(a_02, 7, 2);
    disparray(a_02, 7);

    //課題3のテスト
    double a_03 = 3.1415;
    int aa_03 = 0;
    double aaa_03 = 0;
    intdec(a_03, aa_03, aaa_03);
    cout << "i:" << aa_03 << ", d:" << aaa_03 << endl;

    //課題4のテスト
    char a04_1 = 'H', a04_2 = 'T';
    cout << mergechars(a04_1, a04_2) << endl;

    //課題5のテスト
    //回文の英単語の例　level, madam, dad, mom, pop, wow, peep,,,など
    char a05[] = "level";
    cout << palindrome(a05, 6) << endl;
    char a05_1[] = "levels";
    cout << palindrome(a05_1, 7) << endl;

    //課題6のテスト
    char a06[] = "madam";
    cout << palindrome(a06) << endl;
    char a06_1[] = "adam";
    cout << palindrome(a06_1) << endl;

    //課題7のテスト
    cout << studentid(21, 99) << endl;

    //課題8のテスト
    int a08[] = { 1,5,4,9,6,7,0 };
    cout << secondlargest(a08, 7);

    return 0;
}