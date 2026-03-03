#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so n nodes, m edges..

    cost of each edge is 2^i..

    we need to divide graph into 2..

    currently mst we have to remove edges such

    that it divides into 2..

    we start from min cost edge..

    now if this edge


    one way is that we select a node

    and remove all the edges from that node..

    this can be one of the solutions..

    one more can be that we create an mst and

    then remove one edge ..

    it is something of the type remove the min cost

    edges till graphs divides into 2..

    how will now that now the graph has been divided

    into 2

    and how will i know that should i remove this

    edge or  not...

    so if we think of what all nodes

    are going to be in our first component ..

    so  if we think in this direction

    maybe some kind of dp we can apply ...

    so we assume that node 0 is in first component

    now either we can end here..

    that is remove all the edges and that's it..

    else we include some of the nodes in the graph..

    so among all these children we will include some in this graph..

    now i also need to be careful about cycles while this dfs is going on..

    if this is already visited return some big ass result ..

    else we either choose to remove this component that is cost = edge cost of this..

    else we choose to add this comp for that we do dfs of that child

    and then check from dp if that's better than take it or leave it..

    it might be that it is already divided into 2 comps..

    so simple check can be that if the graph has < n - 1 edges then return 0.

    there shouldnt be 3 comps because there's no coming back from there..

    maybe we can do this 

    that from all the children of 1 i will remove only 1 of the children 

    and all the other nodes that are touching 1 

    so only removing one of these would be enough.. 







*/
int n, m;
const int mod = 998244353;
int binpow(int a, int b)
{
    int result = 1;
    a %= mod;

    while (b > 0)
    {
        if (b & 1)
        {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }

    return result;
}
vector<int> dp;
vector<bool> vis;
int dfs(int node, int par, vector<vector<pair<int, int>>> &adj)
{
    
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int first, second;
        cin >> first >> second;
        adj[first].push_back({second, i});
        adj[second].push_back({first, i});
    }
    if (m < n - 1)
    {

        cout << 0 << endl;
        return 0;
    }
    // now we def need to remove some edges..
    vis.assign(n + 1, 0);
    dp.assign(n + 1, m + 1);
    // now dfs
    int res = dfs(1, 0, adj);
    
    return 0;
}
