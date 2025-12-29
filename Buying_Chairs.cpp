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
        int w, p, k;
        cin >> w >> p >> k;
        int res = 0;
        int mini = min(k, w);
        res += 2 * (mini);
        k -= mini;
        res += min(k, p);
        cout << res << endl;
    }
    return 0;
}
