#include <bits/stdc++.h>

using namespace std;
int n;
const int mod = (int)(1e9 + 7);
vector<vector<int>> dp;
int recursion(int node, int mask, vector<vector<int>> &adj)
{
    if (node >= n)
    {
        // check whether all the nodes are visited or not
        int check = 0;
        bool ok = 1;

        while (check < n)
        {
            if (!(mask & (1 << check)))
            {
                // cout << check << endl;
                ok = false;
                break;
            }
            check++;
        }
        if (ok)
            return 1;
        else
            return 0;
    }
    if (dp[node][mask] != -1)
        return dp[node][mask];

    int res = 0;
    for (auto nei : adj[node])
    {
        if (!(mask & (1 << nei)))
        {
            int newmask = mask | (1 << nei);
            // cout << newmask << endl;
            res = (res + recursion(nei, newmask, adj)) % mod;
        }
    }
    return dp[node][mask] = res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int first, second;
        cin >> first >> second;
        adj[first].push_back(second);
    }

    dp.assign(n, vector<int>(1 << (n), -1));
    cout << recursion(1, 3, adj) << endl;
    return 0;
}
