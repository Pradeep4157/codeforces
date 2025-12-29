#include <bits/stdc++.h>
#define int long long
using namespace std;

// Fast exponentiation for long long
int power(int base, int exp)
{
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result *= base;
        base *= base;
        exp >>= 1;
    }
    return result;
}

// Check if n is a power of 3
bool isPowerOfThree(int n)
{
    if (n < 1)
        return false;
    while (n % 3 == 0)
        n /= 3;
    return n == 1;
}

// Cost function as per your observation
int cost(int x)
{
    return x * power(3, x - 1) + power(3, x + 1);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        if (isPowerOfThree(n))
        {
            int powerVal = 0;
            while (n > 1)
            {
                n /= 3;
                powerVal++;
            }
            cout << cost(powerVal) << '\n';
        }
        else
        {
            int powerVal = 1;
            int res = 0;

            while (power(3, powerVal) < n)
                powerVal++;
            powerVal--;

            while (true)
            {
                while (powerVal >= 0 && power(3, powerVal) > n)
                    powerVal--;
                if (powerVal < 0)
                    break;

                while (power(3, powerVal) <= n)
                {
                    res += cost(powerVal);
                    n -= power(3, powerVal);
                }
            }
            cout << res << '\n';
        }
    }

    return 0;
}