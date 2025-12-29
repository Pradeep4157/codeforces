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
        int n;
        cin >> n;
        int res = n % 10;
        while (n)
        {
            int last = n % 10;
            res = min(res, last);
            n /= 10;
        }
        cout << res << endl;
    }
    return 0;
}
