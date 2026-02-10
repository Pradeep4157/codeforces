#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    here we need to find for some employee x who is the employee that is k levels up..

    if no such boss exists, then return -1..

    first we store the boss of current at par[node][0]..

    then i = 1..20

    par[node][i]  = par[par[node][i - 1]][i - 1]..

    we need to go from top to bottom for this..

    and also we will store the depth in this dfs..

    so that if k is > depth of this node then there is no such boss..


*/
vector<vector<int>> adj;
vector<vector<int>> parent;
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
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    adj.assign(n + 1, {});
    parent.assign(n + 1, vector<int>(20, 0));
    depth.assign(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int par;
        cin >> par;
        adj[par].push_back(i + 2);
    }
    // preprocess 2^n bosses..
    dfs(1, 0, 0);
    while (q--)
    {
        int node, level;
        cin >> node >> level;
        if (level > depth[node])
        {
            cout << -1 << endl;
            continue;
        }

        for (int i = 0; i < 20; i++)
        {
            if (level & (1 << i))
            {
                level ^= (1 << i);
                node = parent[node][i];
            }
        }
        cout << node << endl;
    }

    return 0;
}
