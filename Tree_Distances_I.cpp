#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    so for every node in the tree we need to find the max distance

    to any node..

    one thing which is const is dist of centroid ..

    it is radius only..

    so for every node..

    for these centroids the distance is simply radius of tree..

    and for all the other nodes..

    we need to find distance of them from these centroids..

    if there are 2 store the max one..

    after this ..

    for all the nodes add diameter/2  distance..

    that should work..



*/
int final_node, final_dist;
vector<int> parent;
vector<int> max_dist;
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
bool dfs2(int node, int par, vector<vector<int>> &adj, int dist_left)
{
    // checking if we have reached one of the ends..
    if (adj[node].size() == 1 && adj[node][0] == par && dist_left == 0)
    {
        return 1;
    }
    // now either we are on wrong leaf or we are somewhere in between..
    for (auto nei : adj[node])
    {
        if (nei != par)
        {
            bool is_this = dfs2(nei, node, adj, dist_left - 1);
            if (is_this)
            {

                parent[node] = nei;
                return true;
            }
        }
    }
    return false;
}
void DFS(int node, int par, vector<vector<int>> &adj, int curr_dist)
{
    if (max_dist[node] < curr_dist)
    {
        max_dist[node] = curr_dist;
    }
    for (auto nei : adj[node])
    {
        if (nei != par)
        {
            DFS(nei, node, adj, curr_dist + 1);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n == 1)
    {
        // then there's no dist..
        cout << 0 << endl;
        return 0;
    }
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

    // now we have diameter and of the ends of diameter ..

    // now we can find centroids using another dfs method...

    // bool return type, if yes then child of this as nei else nothing.
    parent.assign(n + 1, -1);
    dfs2(final_node, -1, adj, final_dist);
    vector<int> path;
    int curr_node = final_node;
    while (true)
    {

        path.push_back(curr_node);
        if (parent[curr_node] == -1)
            break;
        curr_node = parent[curr_node];
    }
    int size = path.size();
    max_dist.assign(n + 1, 0);
    // now we have the path..
    // now we need to find the centroids and max dist of all nodes from centroid/s..
    if (size % 2 == 0)
    {
        // then there are 2 centroids..
        int half = size / 2;
        int first_c = path[half - 1];
        int second_c = path[half];
        // to find this dist we can dfs from these centroids..
        DFS(first_c, -1, adj, 0);
        DFS(second_c, -1, adj, 0);
    }
    else
    {
        int half = size / 2;
        int c = path[half];
        DFS(c, -1, adj, 0);
    }
    // now we have all the radius from centroids..
    int radius = size / 2;
    if (size % 2 == 0)
    {
        radius--;
    }
    for (int i = 0; i < (int)max_dist.size(); i++)
    {
        max_dist[i] += radius;
    }
    for (int i = 1; i <= n; i++)
    {
        int a = max_dist[i];
        cout << a << " ";
    }

    return 0;
}