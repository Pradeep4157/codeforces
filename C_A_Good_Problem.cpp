#include <bits/stdc++.h>
#define int long long
using namespace std;
long long find(long long x)
{
    if (x <= 0)
        return 1;
    if (x > (1e18 / 2))
        return -1;
    x--;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x |= x >> 32;
    return x + 1;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r, k;
        cin >> n >> l >> r >> k;

        if (n == 1)
        {
            // because k cant be anything else other than 1
            cout << l << endl;
            continue;
        }
        if (n & 1)
        {

            cout << l << endl;
        }
        else
        {
            if ((n / 2) & 1)
            {
                if ((n / 2) == 1)
                {
                    cout << -1 << endl;
                    continue;
                }
                int res = find(l);
                if (res == -1)
                {
                    cout << res << endl;
                    continue;
                }
                if (res == l)
                    res *= 2;
                if (res > r)
                {
                    cout << -1 << endl;
                    continue;
                }
                int first = n - 2;
                if (k <= first)
                {
                    cout << l << endl;
                }
                else
                    cout << res << endl;
            }
            else
            {
                // first half is l and second half is 2^n
                int secondhalf = find(l);
                if (secondhalf == -1)
                {
                    cout << secondhalf << endl;
                    continue;
                }
                if (secondhalf == l)
                    secondhalf *= 2;
                if (secondhalf > r)
                {

                    cout << -1 << endl;
                    continue;
                }

                int half = n - 2;
                if (k <= half)
                {
                    cout << l << endl;
                }
                else
                    cout << secondhalf << endl;
            }
        }
    }
    return 0;
}
