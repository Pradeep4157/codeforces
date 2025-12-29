#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;
vector<int> fact, invFact;

// Fast modular exponentiation
int power(int a, int b)
{
    int res = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

// Precompute factorials only up to MOD - 1
void precompute()
{
    int limit = MOD - 1;
    fact.resize(limit + 1);
    invFact.resize(limit + 1);
    fact[0] = invFact[0] = 1;
    for (int i = 1; i <= limit; ++i)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = power(fact[i], MOD - 2);
    }
}

// Basic combination nCr modulo MOD (n < MOD)
int comb(int n, int r)
{
    if (r < 0 || r > n)
        return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

// Lucas' Theorem for large n, r with modulus MOD
int lucas(int n, int r)
{
    if (r > n)
        return 0;
    int result = 1;
    while (n > 0 || r > 0)
    {
        int ni = n % MOD;
        int ri = r % MOD;
        result = result * comb(ni, ri) % MOD;
        n /= MOD;
        r /= MOD;
    }
    return result;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute(); // Setup factorials up to MOD - 1

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        // Total number of wall positions
        int totalEdges = n * (m - 1) + m * (n - 1);
        int result = 0;

        if (k >= 2 && totalEdges >= 2)
        {
            int remainingEdges = totalEdges - 2;
            result = (lucas(remainingEdges, k - 2) * 2) % MOD;
        }

        cout << result << '\n';
    }

    return 0;
}