#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
long long power(long long a, long long b, long long mod)
{
    long long res = 1;
    while (b > 0)
    {
        if (b % 2)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

long long binomial_coefficient(int n, int r, long long mod)
{
    if (r > n)
        return 0;
    vector<long long> fact(n + 1, 1);

    for (int i = 2; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % mod;

    long long numerator = fact[n];
    long long denominator = (fact[r] * fact[n - r]) % mod;
    return (numerator * power(denominator, mod - 2, mod)) % mod;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = n;
    set<pair<int, int>> st;
    while (m--)
    {
        int first, second;
        cin >> first >> second;
        if (first > second)
            swap(first, second);
        if (st.count({first, second}))
            continue;
        arr[first - 1]--;
        arr[second - 1]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i]--;
    }
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 3)
            continue;
        res[i] = (arr[i] * (arr[i] - 1) * (arr[i] - 2)) / 6;
    }
    for (auto a : res)
        cout << a << " ";
    cout << endl;
    return 0;
}
