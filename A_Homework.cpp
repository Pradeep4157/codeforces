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
        string s;
        cin >> s;
        int m;
        cin >> m;
        string f, se;
        cin >> f;
        cin >> se;
        for (int i = 0; i < m; i++)
        {
            if (se[i] == 'D')
                s += f[i];
            else
                s = f[i] + s;
        }
        cout << s << endl;
    }
    return 0;
}
