#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so undi weighted graph is given..

    there are m edges in the graph..

    what will be the min weight of the graph such that this edge is used..

    first we can find the mst ..

    the edges that are in the mst, for these edges ..

    the weight is going to be the mst weight sum only..

    but for all the other nodes that are not present in the graph..

    maybe we just need to replace the weight of the edge that is in their place and we will get ..

    no maybe these two nodes are not direclty connected in the mst..

    so for these cases :

        when we connect these 2 nodes it will cause a cycle..

        so we need to remove some edge from the mst we can remove any edge ?

        mostly yes because all are connected and adding this edge causes a cycle so we will remove the max weight edge in the mst

        and add this edge..


    it does not work..

    when i add an edge that is not present in the mst..

    cycles does gets created but we cant remove any edge

    we need to remove some edge from this cycle..

    cycle might not cover the whole graph..

    so first of all this is a tree

    and we have child for all the nodes..

    we can keep the depth to know which of the 2 nodes is child..

    now the bf way is that we start dfs from parent and find the max weight

    from the path from parent -> child..

    through binary lifting  maybe we can find this in logn ..

    so every node keeps its 2^n parent / child.

    mostly we will not keep track of 2^n child because there are going to be multiple childs..

    how will we know max weight in this segment..

    so maybe we can create structure of segtree / fenwick tree

    on the graph..

    where every node is going to not only store 2^i parent but also max weight from this

    node till that parent..

    we have all the 2^n parents along with that we will also store max weight found till that parent..

    base logic is that for parent[node][0] = distance between current node and its  parent..

    for n = 1...20 logic

    now we have stored parnets till 2^20 so now maybe from the child we are going to find the paent..

    we also have the depths of the nodes with that we can find the distance between the nodes and keep

    updating the child and finding the parent..

    while distance > 0...

    the error is that dist being dist2 - dist1 is not always correct because they can be present in different  roots so we need to find lca of both

    the nodes and then return the max among those..







*/
struct DSU
{
    vector<int> parent, rank;

    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;

        if (rank[a] < rank[b])
            swap(a, b);

        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;

        return true;
    }
};

vector<vector<pair<int, int>>> PARENT;
vector<vector<pair<int, int>>> adj;
vector<int> depth;
void dfs(int node, int par, int weight_between, int dep)
{

    // first storing the depth and first parent of the current node.
    PARENT[node][0].first = par;
    // cout << node << "::::" << par << ":::" << weight_between << endl;
    PARENT[node][0].second = weight_between;
    depth[node] = dep;
    // now storing all the 2^n bosses..

    for (int i = 1; i < 20; i++)
    {

        PARENT[node][i].first = PARENT[PARENT[node][i - 1].first][i - 1].first;
        PARENT[node][i].second = PARENT[PARENT[node][i - 1].first][i - 1].second;
        // now comparing it with weight found till 2^(i - 1) th level..
        PARENT[node][i].second = max(PARENT[node][i].second, PARENT[PARENT[node][i - 1].first][i - 1].second);
        PARENT[node][i].second = max(PARENT[node][i].second, PARENT[node][i - 1].second);
    }

    // cout << "this is the node : " << node << endl;
    for (auto nei : adj[node])
    {
        // cout << nei.first << ":" << nei.second << endl;

        if (nei.first != par)
        {

            dfs(nei.first, node, nei.second, dep + 1);
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
            u = PARENT[u][i].first;
        }
    }
    // if at the same level they are the same node then we just return the node..
    if (u == v)
        return u;
    // now we keep going above till the parent of both the nodes is the lca..
    for (int i = 19; i >= 0; i--)
    {
        int ith_par_1 = PARENT[u][i].first;
        int ith_par_2 = PARENT[v][i].first;
        if (ith_par_1 != ith_par_2)
        {
            // then we can jump this power of 2 jump..
            u = PARENT[u][i].first;
            v = PARENT[v][i].first;
        }
    }
    return PARENT[u][0].first;
}
int find_max_weight(int first, int second)
{
    int first_dist = depth[first];
    int second_dist = depth[second];

    if (first_dist > second_dist)
    {
        // second node is the parent of first node..
        swap(first, second);
        swap(first_dist, second_dist);
    }
    // now first is def parent..
    int dist = second_dist - first_dist;
    int max_weight = PARENT[second][0].second;
    bool first_set = false;
    for (int i = 0; i < 20; i++)
    {
        if (dist & (1 << i))
        {

            max_weight = max(max_weight, PARENT[second][i].second);
            second = PARENT[second][i].first;
        }
    }
    return max_weight;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);

    PARENT.assign(n + 1, vector<pair<int, int>>(20, {0, 0}));

    depth.assign(n + 1, 0);
    map<int, set<pair<int, int>>> used_edges;
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int first, second, weight;
        cin >> first >> second >> weight;
        if (first > second)
            swap(first, second);
        edges.push_back({weight, first, second});
    }

    vector<vector<int>> temp;
    temp = edges;
    sort(edges.begin(), edges.end());

    // now we have min weight first..

    // we make the mst first...

    int mst_weight = 0;
    int max_weight_in_mst = 0;

    DSU du(n + 1);

    for (int i = 0; i < m; i++)
    {
        int first = edges[i][1];
        int second = edges[i][2];
        int curr_weight = edges[i][0];

        bool curr_united = du.unite(first, second);
        if (curr_united)
        {
            //  then we have used this in mst..

            // cout << first << ":" << second << ":" << curr_weight << endl;
            mst_weight += curr_weight;

            max_weight_in_mst = max(max_weight_in_mst, curr_weight);
            used_edges[first].insert({second, curr_weight});
            adj[first].push_back({second, curr_weight});
            adj[second].push_back({first, curr_weight});
        }
    }

    dfs(1, 0, 0, 0);

    // now we have all the edges that have been used in the mst..

        for (int i = 0; i < m; i++)
    {
        int first = temp[i][1];
        int second = temp[i][2];
        int curr_weight = temp[i][0];
        if (first > second)
            swap(first, second);

        // now if this edge is used in mst then add this weight in the mst, sub the weight that was used in mst..
        set<pair<int, int>> &edges_from_first = used_edges[first];
        auto it = edges_from_first.lower_bound({second, INT_MIN});

        if (it != edges_from_first.end() && it->first == second)
        {

            int second_node_found = it->first;
            int weight = it->second;

            // this 2 nodes are direclty connected in the mst..
            int curr_mst_weight = mst_weight;
            curr_mst_weight -= weight;
            curr_mst_weight += curr_weight;
            cout << curr_mst_weight << endl;
        }
        // here
        else
        {

            int first_dist = depth[first];
            int second_dist = depth[second];

            if (first_dist > second_dist)
            {
                // second node is the parent of first node..
                swap(first, second);
                swap(first_dist, second_dist);
            }
            int lca_node = lca(first, second);
            int max_weight = 0;
            if (lca_node == first)
            {

                // then they are in the same branch..
                max_weight = find_max_weight(first, second);
            }
            else
            {
                // we need to find max weight from seccond..lca and first..lca
                max_weight = find_max_weight(lca_node, first);
                max_weight = max(max_weight, find_max_weight(lca_node, second));
            }
            int curr_mst_weight = mst_weight;
            curr_mst_weight -= max_weight;
            curr_mst_weight += curr_weight;
            cout << curr_mst_weight << endl;
        }
    }

    return 0;
}
