#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define INF(t) numeric_limits<t>::max()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (auto &x : a)
            cin >> x;
        vector<unordered_map<int, int>> adj(n);
        // map<pair<int, int>, int> edge;
        vector<int> isheavy(n);
        vector<vector<int>> heavy_adj(n);
        vector<unordered_map<int, ll>> col_cnt(n);

        ll tot = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int u, v, c;
            cin >> u >> v >> c;
            u--;
            v--;
            adj[u][v] = c;
            adj[v][u] = c;
            // edge[{min(u, v), max(u, v)}] = c;
            if (a[u] != a[v])
                tot += c;
        }
        int B = sqrt(n);
        for (int i = 0; i < n; i++)
        {
            if (int(adj[i].size()) > B)
            {
                isheavy[i] = 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (auto &y : adj[i])
            {
                if (isheavy[y.first])
                {
                    heavy_adj[i].push_back(y.first);
                }
                if (isheavy[i])
                {
                    col_cnt[i][a[y.first]] += adj[i][y.first]; // edge[{min(i, y.first), max(i, y.first)}];
                }
            }
        }

        while (q--)
        {
            int i, x;
            cin >> i >> x;
            i--;
            if (isheavy[i])
            {
                tot += col_cnt[i][a[i]];
                tot -= col_cnt[i][x];
            }
            else
            {
                for (auto y : adj[i])
                {
                    if (a[y.first] == a[i])
                        tot += adj[y.first][i]; // edge[{min(y.first, i), max(y.first, i)}];
                    if (a[y.first] == x)
                        tot -= adj[y.first][i]; // edge[{min(y.first, i), max(y.first, i)}];
                }
            }

            for (auto y : heavy_adj[i])
            {
                col_cnt[y][a[i]] -= adj[y][i]; // edge[{min(y, i), max(y, i)}];
                col_cnt[y][x] += adj[y][i];    // edge[{min(y, i), max(y, i)}];
            }

            a[i] = x;
            cout << tot << "\n";
        }
    }

    return 0;
}