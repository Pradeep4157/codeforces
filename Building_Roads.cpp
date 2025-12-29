#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    this can be solved using dfs , dsu ..

    with dfs we traverse and if we get a unvisited node then we

    dfs from that node make all nodes in this comp vis..

    and then store this node as well.

    at the end if there are more than 1 node..

    then we connect the first node to all the other nodes..

    that should do..




*/

vector<bool> vis;
void dfs(int node, vector<vector<int>> &adj)
{
    if (vis[node] == 1)
        return;
    vis[node] = 1;
    for (auto nei : adj[node])
    {
        dfs(nei, adj);
    }
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int first, second;
        cin >> first >> second;
        adj[first].push_back(second);
        adj[second].push_back(first);
    }
    vector<int> res;
    // now we do the dfs part..
    vis.assign(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            dfs(i, adj);
            res.push_back(i);
        }
    }
    cout << res.size() - 1 << endl;
    int first = res[0];
    for (int i = 1; i < res.size(); i++)
    {
        cout << first << " " << res[i] << endl;
    }
    return 0;
}
