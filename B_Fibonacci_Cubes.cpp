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
        vector<int> sides(n);
        sides[0] = 1;
        sides[1] = 2;
        for (int i = 2; i < n; i++)
        {
            sides[i] = sides[i - 1] + sides[i - 2];
        }
        string res;
        for (int i = 0; i < m; i++)
        {
            int l, b, h;
            cin >> l >> b >> h;
            int minreq = sides[n - 1] + sides[n - 2];
            int maxi = sides[n - 1];
            if ((l >= minreq || b >= minreq || h >= minreq) && (l >= maxi && b >= maxi && h >= maxi))
            {
                res.push_back('1');
            }
            else
                res.push_back('0');
        }
        cout << res << endl;
    }
    return 0;
}
