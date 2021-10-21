//Kadai_1
#include <string>
#include <iostream>


using namespace std;

int main()
{
    int num;
    cout << "Number:";
    cin >> num;
    cout << abs(num) << endl;
}

//--------------------------------------------------------
//Kadai_2
#include <string>
#include <iostream>


using namespace std;

int main()
{
    int num1, num2;
    cout << "num1, " << "num2:";
    cin >> num1 >> num2;
    if (num1 < num2) cout << num2 << endl;
    else cout << num1 << endl;
}

//--------------------------------------------------------
//Kadai_3
#include <string>
#include <iostream>


using namespace std;

int main()
{
    int n, sum = 0;
    cout << "n:";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout << "sum;" << sum << endl;
}

//--------------------------------------------------------
//Kadai_4
#include <string>
#include <iostream>


using namespace std;

int main()
{
    int a, b, n;
    cout << "a,b:";
    cin >> a >> b;

    n = abs(a - b);
    for (int i = 1; i <= n; i++)
    {
        cout << a << "+" << i << ":" << a + i << endl;
    }
}
//--------------------------------------------------------
//Kadai5
#include <string>
#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int nums[10];

    for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << ";";
        cin >> nums[i];
    }

    for (int i = 0; i < 10; i++)
    {
        if (nums[i] % 2 == 1) n++;
    }

    cout << "n=" << n << endl;
}