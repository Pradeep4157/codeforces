#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
ll power(ll a, ll b)
{
    ll result = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            result *= a;
        }
        a *= a;
        b /= 2;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    ll res = 0;
    ll index = 0;
    bool possible = 1;
    while (m >= 0)
    {
        m--;
        ll curr = power(n, index);
        index++;
        res += curr;
        if (res > (ll)(1e9))
        {

            possible = false;
            break;
        }
    }
    if (possible)
    {
        cout << res << endl;
    }
    else
        cout << "inf" << endl;
    return 0;
}
