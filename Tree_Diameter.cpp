#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so we find the farthest node using dfs and then from there

    we find the farthest node again using the same dfs..

    during this dfs we will store the dist we found till now..

    and update the global dist if it is greater..


*/
int final_node, final_dist;
void dfs(int node, int par, vector<vector<int>> &adj, int dist)
{
    if (dist > final_dist)
    {
        final_dist = dist;
        final_node = node;
    }
    for (auto nei : adj[node])
    {
        if (nei != par)
        {
            dfs(nei, node, adj, dist + 1);
        }
    }
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
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
    dfs(1, -1, adj, 0);

    dfs(final_node, -1, adj, 0);
    cout << final_dist << endl;
    return 0;
}
