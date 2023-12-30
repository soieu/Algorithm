#include <iostream>
using namespace std;

long long divideconquerpower(long long num, long long n, long long divisor)
{
    if (n == 0)
        return 1;
    if (n == 1)
    {
        return num % divisor;
    }
    else
    {
        long long x = divideconquerpower(num, n / 2, divisor) % divisor;
        if (n % 2 == 0)
        {
            return (x * x) % divisor;
        }
        else
        {
            return ((x * x) % divisor * num % divisor) % divisor;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b, c;
    cin >> a >> b >> c;
    cout << divideconquerpower(a, b, c);

    return 0;
}
