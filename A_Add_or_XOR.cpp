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
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        if (a == b)
        {
            cout << 0 << endl;
            continue;
        }
        else if (a > b)
        {

            // can only get 1 step behind
            if ((a - b) > 1)
            {
                cout << -1 << endl;
                continue;
            }
            else
            {
                if (a & 1)
                {
                    cout << y << endl;
                    continue;
                }
                else
                {
                    cout << -1 << endl;
                    continue;
                }
            }
        }
        else
        {
            if (x <= y)
            {
                cout << (x * (b - a)) << endl;
                continue;
            }
            else
            {
                // we need to use b as much as we can
                int diff = b - a;
                int total = diff;
                if (a & 1)
                {
                    diff /= 2;
                }
                else
                {
                    diff = (diff + 1) / 2;
                }
                int rem = total - diff;

                cout << (rem * x) + (diff * y) << endl;
            }
        }
    }
    return 0;
}
