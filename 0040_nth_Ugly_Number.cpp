// nth Ugly Number

#include <iostream>
using namespace std;

int maxDiv(int a, int b)
{
    while (a % b == 0)
        a /= b;
    return a;
}

bool isUgly(int n)
{
    n = maxDiv(n, 2);
    n = maxDiv(n, 3);
    n = maxDiv(n, 5);
    return (n == 1) ? 1 : 0;
}

int Ugly_Number(int n)
{
    int i = 1, cnt = 1;
    while (n > cnt)
    {
        ++i;
        if (isUgly(i))
            ++cnt;
    }
    return i;
}

int main()
{
    int n = 15;
    long no = Ugly_Number(n);

    cout << n << " is " << no << " Ugly Number " << endl;
}