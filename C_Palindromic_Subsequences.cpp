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
        ll n;
        cin >> n;
        vector<ll> res(n);
        res[0] = 1;
        res[1] = 2;
        res[n - 1] = 2;
        res[n - 2] = 1;

        ll index = 3;
        for (ll i = 2; i < n - 2; i++)
        {
            res[i] = index;
            index++;
        }
        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
