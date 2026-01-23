#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    ok so initially all the nodes are white and we need to paint all of them black in min operations..

    each time we select a subset of nodes..

    conditions are :

        dx != dy and no edge between x & y..


    so  in this question just store the distance of all the nodes

    since we can only take some 1 di so min operations == max no of nodes at a level..

*/
vector<int> dist;
void dfs(int node, int par, int curr_dist, vector<vector<int>> &adj)
{
    dist[node] = curr_dist;
    for (auto nei : adj[node])
    {
        if (nei != par)
        {
            dfs(nei, node, curr_dist + 1, adj);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1);
        dist.assign(n + 1, 0);
        for (int i = 0; i < n - 1; i++)
        {
            int first, second;
            cin >> first >> second;
            adj[first].push_back(second);
            adj[second].push_back(first);
        }
        dfs(1, -1, 1, adj);
        // for (auto a : dist)
        //     cout << a << " ";
        // cout << endl;
        vector<int> level(n + 1, 0);
        for (int i = 1; i < dist.size(); i++)
        {
            int a = dist[i];
            level[a]++;
        }
        int res = 0;
        for (auto a : level)
        {
            cout << a << " ";
        }
        cout << endl;
        for (int i = 1; i < level.size(); i++)
        {
            // if the prev level consist of only 1 node then we cant swap and make it work ..
            int curr = level[i];
            if (level[i - 1] == 1)
            {
                curr++;
            }
            res = max(res, curr);
        }

        cout << res << endl;
    }
    return 0;
}
