#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
int rounder(int n, int k)
{
    int p = 1;
    for (int i = 0; i < k; i++)
        p *= 10;

    return ((n + p - 1) / p) * p;
}
int sum(int n)
{
    int res = 0;
    while (n)
    {
        res += (n % 10);
        n /= 10;
    }
    return res;
}
int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
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
        int y = n;
        int temp_n = n;
        int curr_addition = 0;
        bool found = false;
        for (int i = 1; i < 10; i++)
        {
            for (int j = 1; j < 10; j++)
            {
                int curr = binpow(10, j);
                curr *= i;
                int y = curr + n;
                if (y - n == sum(y))
                {
                    found = 1;
                    break;
                }
            }
        }
        if (found)
            cout << 10 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
