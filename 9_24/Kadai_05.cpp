#include <iostream>
#include <climits>

using namespace std;

int main()
{
    double d = 10.5;
    cout << d << endl;
    //>> 10.5
    cout << (int)d << endl;
    //>> 10
    cout << int(d) << endl;
    //>> 10
    cout << static_cast<int>(d) << endl;
    //>> 10

    return 0;
}