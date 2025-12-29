#include <bits/stdc++.h>
#define int long long
using namespace std;
/*

dijkstra gives TLE..




*/

signed main()
{
    // your code goes here
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    map<pair<int, int>, int> mp;
    for (int i = 0; i < m; i++)
    {
        int first, second, weight;
        cin >> first >> second >> weight;
        adj[first].push_back({second, weight});
    }

    priority_queue<pair<long long, int>,
                   vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        pq;

    vector<int> res(n + 1, LLONG_MAX);
    pq.push({0, 1});
    while (!pq.empty())
    {
        pair<int, int> top = pq.top();
        pq.pop();
        int node = top.second;
        int dist = top.first;
        if (res[node] <= dist)
            continue;
        res[node] = (dist);

        for (auto &nei : adj[node])
        {
            int new_node = nei.first;
            int new_dist = (nei.second + dist);
            if (res[new_node] > new_dist)
            {

                pq.push({new_dist, new_node});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}