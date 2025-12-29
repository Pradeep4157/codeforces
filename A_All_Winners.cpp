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
        int n, m;
        cin >> n >> m;
        if (m == 1)
        {
            cout << 1 << endl;
            continue;
        }
        else
        {
            int res = (m / 2) * (n - 1);
            res += (m + 1) / 2;
            cout << res << endl;
        }
    }
    return 0;
}
