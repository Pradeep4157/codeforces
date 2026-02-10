#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so in this we are going to write the general structure of binary lifting ..

    so in the condition is that the root is fixed ..

    and in the dfs we will store all the 2 power parents of all the nodes and along with that we are also

    going to store the depth of all the nodes from the root node..

    IN THE DFS FUNCTION PREV IS THE PARENT OF THE CURRENT NODE...



*/
vector<vector<int>> par;
vector<vector<int>> adj;
vector<int> depth;
void dfs(int node, int par, int dep)
{
    // first storing the depth and first parent of the current node.
    parent[node][0] = par;
    depth[node] = dep;
    // now storing all the 2^n bosses..
    for (int i = 1; i < 20; i++)
    {
        parent[node][i] = parent[parent[node][i - 1]][i - 1];
    }
    for (auto nei : adj[node])
    {
        if (nei != par)
        {
            dfs(nei, node, dep + 1);
        }
    }
}
int lca(int u, int v)
{
    // first we need to make both of them at the same level..
    int first_dist = depth[u];
    int second_dist = depth[v];
    if (first_dist < second_dist)
    {
        swap(u, v);
    }
    // now u is going to be always at a deeper depth than node v..
    // now we are going to make u reach v..
    for (int i = 19; i >= 0; i--)
    {
        if ((depth[u] - depth[v]) & (1 << i))
        {
            // if this bit is set in the difference of them then we can jump this much..
            u = par[u][i];
        }
    }
    // if at the same level they are the same node then we just return the node..
    if (u == v)
        return u;
    // now we keep going above till the parent of both the nodes is the lca..
    for (int i = 19; i >= 0; i--)
    {
        int ith_par_1 = par[u][i];
        int ith_par_2 = par[v][i];
        if (ith_par_1 != ith_par_2)
        {
            // then we can jump this power of 2 jump..
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    adj.resize(n + 1, {});
    depth.assign(n + 1, 0);
    // now n - 1 lines are going to be edges between nodes..
    for (int i = 0; i < n - 1; i++)
    {
        int first, second;
        cin >> first >> second;
        adj[first].push_back(second);
        adj[second].push_back(first);
    }

    par.assign(n + 1, vector<int>(20, 0));

    return 0;
}
