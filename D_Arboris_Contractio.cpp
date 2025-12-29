#include <bits/stdc++.h>
#define int long long
using namespace std;
int dfs(int node, int par, vector<vector<int>> &adj)
{
    int res = 0;
    bool first = false;
    for (auto nei : adj[node])
    {
        if (nei == par)
            continue;
        if (first == false)
        {
            first = true;
            res += dfs(nei, node, adj);
        }
        else
            res += 1 + dfs(nei, node, adj);
    }

    res = max(res, 0LL);
    return res;
}
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
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; i++)
        {
            int first, second;
            cin >> first >> second;

            adj[first].push_back(second);
            adj[second].push_back(first);
        }
        if (n == 2)
        {
            cout << 0 << endl;
            continue;
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (adj[i].size() == 1)
                res++;
        }
        int maxi = 0;
        for (int i = 1; i <= n; i++)
        {
            int count = 0;
            for (auto nei : adj[i])
            {
                if (adj[nei].size() == 1LL)
                    count++;
            }
            maxi = max(maxi, count);
        }
        cout << res - maxi << endl;
    }
    return 0;
}
