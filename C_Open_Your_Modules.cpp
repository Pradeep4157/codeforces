#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
ll power(ll a, ll b, ll mod)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        b /= 2;
        a = (a * a) % mod;
    }
    return res;
}
ll binomial_coefficient(ll n, ll r, ll mod)
{
    if (r > n)
        return 0;
    vector<ll> fact(n + 1, 1);
    for (ll i = 2; i <= n; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    ll numerator = fact[n];
    ll denominator = (fact[n - r] * fact[r]) % mod;
    return (numerator * power(denominator, mod - 2, mod)) % mod;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    cout << binomial_coefficient(2 * n - 1, n, (ll)(1e9 + 7));
    return 0;
}
