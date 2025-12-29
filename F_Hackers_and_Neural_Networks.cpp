#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<vector<string>> b(m, vector<string>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> b[i][j];
            }
        }

        bool possible = true;
        for (int i = 0; i < n; i++)
        {
            string curr = a[i];
            bool impossible = true;
            for (int j = 0; j < m; j++)
            {
                if (b[j][i] == curr)
                {
                    impossible = false;
                    break;
                }
            }
            if (impossible)
            {
                possible = false;
                break;
            }
        }
        if (possible == false)
        {
            cout << -1 << endl;
            continue;
        }
        int res = INT_MAX;
        for (int j = 0; j < m; j++)
        {
            int currres = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] == b[j][i])
                    currres++;
                else
                    currres += 3;
            }
            res = min(res, currres);
        }
        cout << res << endl;
    }
    return 0;
}
