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
        int n, x, y;
        cin >> n >> x >> y;
        bool ok = false;
        for (int i = -1; i <= 110; i++)
        {
            if (i == n)
            {
                continue;
            }
            else
            {
                if (abs(i - x) <= abs(x - n) && abs(i - y) <= abs(y - n))
                {
                    ok = 1;
                    break;
                }
            }
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
