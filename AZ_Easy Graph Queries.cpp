#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    it can be done using DSU where for query 1 find the parent of the  node and return the size of the comp..

    and for the second query find the parent of both the nodes and then if same par then return yes else no..

    now lets try to solve it using dfs..

    for the same comp while dfs it will be added in some comp x..

    this first dfs is also going to return the size and after this we will do another dfs to store the  size in the size array..




*/
// struct DSU
// {
//     vector<int> parent, size;

//     DSU(int n)
//     {
//         parent.resize(n);
//         size.resize(n, 1);
//         iota(parent.begin(), parent.end(), 0);
//     }

//     int find(int v)
//     {
//         if (parent[v] == v)
//             return v;
//         return parent[v] = find(parent[v]);
//     }

//     bool unite(int a, int b)
//     {
//         a = find(a);
//         b = find(b);
//         if (a == b)
//             return false;
//         if (size[a] < size[b])
//             swap(a, b);
//         parent[b] = a;
//         size[a] += size[b];
//         return true;
//     }

//     int getSize(int v)
//     {
//         return size[find(v)];
//     }
// };

vector<int> SIZE;
vector<int> comp;
vector<int> vis;
int dfs(int node, int par, int comp_no, vector<vector<int>> &adj)
{
    // already visited..
    if (vis[node] >= 1)
        return 0;
    // first time visiting...
    vis[node]++;
    comp[node] = comp_no;
    int res = 1;
    for (auto nei : adj[node])
    {
        if (nei != par)
        {
            res += dfs(nei, node, comp_no, adj);
        }
    }
    return res;
}
void dfs2(int node, int par, int curr_size, vector<vector<int>> &adj)
{
    if (vis[node] >= 2)
        return;
    // first time visiting..
    vis[node]++;
    SIZE[node] = curr_size;
    for (auto nei : adj[node])
    {
        if (nei != par)
        {
            dfs2(nei, node, curr_size, adj);
        }
    }
    return;
}
signed main()

{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int first, second;
        cin >> first >> second;
        adj[first].push_back(second);
        adj[second].push_back(first);
    }
    // now allocating comp no and sizes..
    vis.assign(n + 1, 0);
    comp.assign(n + 1, 0);
    SIZE.assign(n + 1, 0);
    int comp_no = 1;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            int curr_size = dfs(i, -1, comp_no, adj);
            dfs2(i, -1, curr_size, adj);
            comp_no++;
        }
    }
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int x;
            cin >> x;
            cout << SIZE[x] << endl;
        }
        else
        {
            int first, second;
            cin >> first >> second;
            first = comp[first];
            second = comp[second];
            if (first == second)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
