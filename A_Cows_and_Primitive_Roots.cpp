#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    11->2 6 7 8
    WHAT IS THAT ONE MORE NUMBER THAT
    IS SATISFYING THE CONDITION?


*/
int mod;

int binpow(int a, int b, int mod)
{
    if (b == 0)
        return 1;
    else if (b % 2)
        return (1LL * a * binpow(a, b - 1, mod)) % mod;
    else
    {
        int temp = binpow(a, b / 2, mod);
        return (1LL * temp * temp) % mod;
    }
}
bool check(int i, int p)
{
    int temp = binpow(i, p - 1, mod);
    temp -= 1;
    if (temp % p)
        return 0;

    for (int j = 1; j <= p - 2; j++)
    {
        int curr = binpow(i, j, mod);
        curr--;

        if ((curr % p) == 0)
            return false;
    }
    return 1;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    mod = n;
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (check(i, n))
        {
            // cout << i << endl;
            res++;
        }
    }
    cout << res << endl;
    return 0;
}
