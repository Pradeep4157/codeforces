#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << -1 << endl;
            continue;
        }
        if (a < b)
            swap(a, b);
        ll dupa = a;
        ll k = 1;
        while (dupa)
        {
            dupa >>= 1;
            k <<= 1;
        }

        int res = k - a;
        cout << res << endl;
    }
    return 0;
}
