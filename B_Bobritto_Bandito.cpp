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
        ll n, m, l, r;
        cin >> n >> m >> l >> r;
        ll left = 0, right = r;
        ll days = min(right, m);
        ll rem = max(0LL, m - right);
        left = -rem;
        cout << left << " " << days << endl;
    }
    return 0;
}
