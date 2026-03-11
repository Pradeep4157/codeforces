#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so for every node we need to dp[child], max node that child has seen , no of nodes in that comp..

    for every child first add weight to dp[node][0] and then if the child's max

    just max weight that child has seen will give incorrect ans..

    if the node's weight is

    so if we see it from dp on trees problem..

    every node should store some things :

        1) no of nodes in that component

        2) dp till that node all traversals in that subtree is done..

        3) max val that is found in that subtree..

    now with these data we might be able to find how many times which child edge is going to be added in them ..

    now we need to figure out the part of how many times are we adding some max of a child..

    in the overall res the min amount of times an edge will be used == 1

    max edge will be used n times..



*/
struct DSU
{
    vector<int> parent, sz;

    DSU(int n)
    {
        parent.resize(n);
        sz.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];

        return true;
    }

    int comp_size(int x)
    {
        return sz[find(x)];
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> edges;
    for (int i = 0; i < n - 1; i++)
    {
        int first, second, weight;
        cin >> first >> second >> weight;
        first--;
        second--;
        edges.push_back({weight, first, second});
    }
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    int res = 0;
    for (auto a : edges)
    {
        int curr_weight = a[0];
        int first = a[1];
        int second = a[2];
        int first_size = dsu.comp_size(first);
        int second_size = dsu.comp_size(second);
        bool curr = dsu.unite(first, second);
        if (curr)
        {
            res += curr_weight * first_size * second_size;
        }
    }
    cout << res << endl;
    return 0;
}
