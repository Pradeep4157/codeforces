#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, k;
        cin >> n >> x >> k;
        int rem = x % k;
        int res = rem;
        int second_rem = k - rem;
        if (second_rem + x <= n)
        {
            res = min(res, second_rem);
        }
        cout << res << endl;
    }
    return 0;
}
