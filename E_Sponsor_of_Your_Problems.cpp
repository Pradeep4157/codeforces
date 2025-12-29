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
        string l, r;
        cin >> l >> r;
        int res = 0;
        int i = 0, n = l.size(), a;
        while (i < n && l[i] == r[i])
        {
            i++;
            res += 2;
        }
        if (i == n || r[i] - l[i] > 1)
        {
            cout << res << endl;
            continue;
        }
        i++;
        res++;
        while (i < n && l[i] == '9' && r[i] == '0')
        {
            i++;
            res++;
        }
        cout << res << endl;
    }
    return 0;
}
