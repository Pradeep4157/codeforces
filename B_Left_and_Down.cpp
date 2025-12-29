#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, k;
        cin >> x >> y >> k;

        int common = __gcd(x, y);
        x /= common;
        y /= common;

        if ((k >= x && k >= y))
        {
            cout << 1 << endl;
            continue;
        }
        else
            cout << 2 << endl;
    }
    return 0;
}
