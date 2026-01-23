#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so there should be 1 or more trees in the graph..

    if any tree is a graph then it is yes else no..

*/
int n, m;
vector<vector<int>> adj;
vector<int> vis;
bool dfs(int node, int par)
{
    if (vis[node] == 1)
    {
        return 1;
    }
    vis[node] = 1;
    bool res = false;
    for (auto nei : adj[node])
    {
        if (nei != par)
        {
            res |= dfs(nei, node);
        }
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    adj.resize(n + 1);
    vis.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int first, second;
        cin >> first >> second;
        adj[first].push_back(second);
        adj[second].push_back(first);
    }
    bool found = false;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            // check for cycle..
            found |= (dfs(i, -1));
        }
    }
    cout << ((found) ? "YES" : "NO") << endl;
    return 0;
}
