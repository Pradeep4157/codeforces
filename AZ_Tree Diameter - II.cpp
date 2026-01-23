#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    so if single center then return the center..

    else return -1 if 2 center..

    if array len is odd return middle

    else return -1..

    dfs1 to find the far.. node..

    dfs2 to find path ..

    so storing the whole array gives TLE..

    we can mark the parents / child  of the diameter path and backtrack to get the path..

    for this maybe first we need diameter , this we can get in dfs1 ..

    and then..

    in dfs2 if curr_path == max_path ..

        then we return 1

        else we return 0..

        now if nei returns 1..

            then child[node] = nei..

            break

        else continue.



    i wrong thing in single centriod is that there can be multiple nodes from which diameter can pass..

    so instead of doing dfs from left and right ..

    we need to count the no of nodes that are at radius dist..

    just return the sum of all these radius nodes ..



*/
int max_node, max_dist;
vector<int> child;
int radius;
vector<int> TEMP;
int DFS(int node, int par, int curr_dist, vector<vector<int>> &adj)
{
    int res = 0;
    if (adj[node].size() == 1 && adj[node][0] == par)
    {
        // this is the leaf node..
        if (curr_dist == radius)
        {
            res++;
        }
    }

    // now try for all the nei nodes..
    for (auto nei : adj[node])
    {
        if (nei != par)
        {
            res += DFS(nei, node, curr_dist + 1, adj);
        }
    }
    return TEMP[node] = res;
}
void dfs1(int node, int par, int curr_dist, vector<vector<int>> &adj)
{
    if (adj[node].size() == 1 && adj[node][0] == par)
    {
        // this is leaf..
        if (curr_dist > max_dist)
        {
            max_dist = curr_dist;
            max_node = node;
        }
        return;
    }
    // else we try ..
    for (auto nei : adj[node])
    {
        if (nei != par)
        {
            dfs1(nei, node, curr_dist + 1, adj);
        }
    }
}

bool dfs2(int node, int par, vector<vector<int>> &adj, int curr_dist)
{

    if (adj[node].size() == 1 && adj[node][0] == par)
    {

        // this is the leaf..
        if (curr_dist == max_dist)
        {

            // this is a diameter..
            return 1;
        }
        else
            return 0;
    }
    // now we try to find ..
    for (auto nei : adj[node])
    {
        if (nei != par)
        {
            bool curr = dfs2(nei, node, adj, curr_dist + 1);
            if (curr)
            {
                // this is a diameter path..

                child[node] = nei;
                return 1;
            }
        }
    }
    return 0;
}

int dfs3(int node, int par, vector<vector<int>> &adj, int rem_dist)
{
    if (adj[node].size() == 1 && adj[node][0] == par)
    {

        if (rem_dist == 0)
            return 1;
        else
            return 0;
    }
    int res = 0;
    for (auto nei : adj[node])
    {
        if (nei != par)
        {
            res += dfs3(nei, node, adj, rem_dist - 1);
        }
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < n - 1; i++)
    {
        int first, second;
        cin >> first >> second;
        adj[first].push_back(second);
        adj[second].push_back(first);
        indegree[first]++;
        indegree[second]++;
    }
    int root_node = 1;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 1)
        {
            root_node = i;
            break;
        }
    }
    max_dist = -1, max_node = -1;
    child.assign(n + 1, -1);
    dfs1(root_node, -1, 0, adj);

    // now we have max_node we find the path..
    vector<int> temp;
    int first_end = max_node;
    dfs1(max_node, -1, 0, adj);
    int second_end = max_node;
    // now we have both then ends.. we will do dfs2 from one of the ends.. and mark the nei..
    dfs2(max_node, -1, adj, 0);
    // now we need to store the path from the child..
    vector<int> max_path;
    first_end = max_node;
    while (true)
    {
        max_path.push_back(first_end);
        if (child[first_end] == -1)
        {
            break;
        }
        else
            first_end = child[first_end];
    }

    int size = max_path.size();

    
    if ((size % 2) == 0)
    {
        // left center is size/2 - 1
        int c1 = max_path[size / 2 - 1];
        int c2 = max_path[size / 2];
        int count1 = dfs3(c1, c2, adj, (size / 2) - 1);
        int count2 = dfs3(c2, c1, adj, (size / 2) - 1);
        cout << ((count1 * count2)) << endl;
    }
    else
    {
        // here only 1 centroid..
        int c = max_path[size / 2];
        radius = size / 2;

        TEMP.assign(n + 1, 0);

        DFS(c, -1, 0, adj);
        int prev = 0;
        int res = 0;
        for (auto nei : adj[c])
        {
            res += (prev * TEMP[nei]);
            prev += TEMP[nei];
        }
        cout << res << endl;
    }
    return 0;
}
