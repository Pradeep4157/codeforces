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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    while (q--)
    {
        int curr = 0;
        int type;
        cin >> type;
        if (type == 2)
        {
            int col;
            cin >> col;
            for (int i = 0; i < n; i++)
            {
                for (int j = max(0LL, m - col); j < m; j++)
                {
                    if (vis[i][j] == false)
                    {
                        vis[i][j] = 1;
                        curr++;
                    }
                }
            }
            m = (m - col);
            cout << curr << endl;
        }
        else
        {
            int row;
            cin >> row;
            for (int i = max(0LL, n - row); i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (vis[i][j] == false)
                    {
                        vis[i][j] = 1;
                        curr++;
                    }
                }
            }
            n = (n - row);
            cout << curr << endl;
        }
        }
    return 0;
}
