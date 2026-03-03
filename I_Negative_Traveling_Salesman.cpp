#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so we will try to add the worst weights ever and then keep

    adding edges till the no of comps == 1..

    if this edge creates a cycle avoid that and move to the next worst edge..




*/
vector<int> vis;
pair<int, int> recursion(int node, int par, vector<vector<pair<int, int>>> &adj, int nodes_left)
{
    if (vis[node] == 2)
    {
        // it is in current dfs..
        return {0, 0};
    }
    if (nodes_left == 0)
    {
        return {1, 0};
    }
    vis[node] = 2;
    pair<int, int> ans = {0, INT_MAX};
    for (auto child : adj[node])
    {

        pair<int, int> next = recursion(child.first, node, adj, nodes_left - 1);
        if (next.first == 1)
        {
            cout << node << ":" << par << endl;
            // then it is a valid dfs..
            if (ans.first == 0)
                ans.first = 1;
            ans.second = min(ans.second, next.first + child.second);
        }
    }
    vis[node] = 1;

    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vis.assign(n + 1, 1);
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<vector<int>> weights;
    for (int i = 0; i < m; i++)
    {
        int weight;
        int first, second;
        cin >> first >> second;
        cin >> weight;

        adj[first].push_back({second, weight});
    }

    int res = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        pair<int, int> curr = recursion(i, -1, adj, n - 1);
        if (curr.first == 1)
            res = min(res, curr.second);
    }
    if (res == INT_MAX)
        cout << "No" << endl;
    else
        cout << res << endl;

    return 0;
}
