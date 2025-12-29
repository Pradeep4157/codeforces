#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int first, second;
        cin >> first >> second;
        adj[first].push_back(second);
        adj[second].push_back(first);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    vector<bool> vis(n + 1, false);
    vis[1] = 1;
    vector<int> ans;
    while (!pq.empty())
    {
        int curr = pq.top();
        pq.pop();
        ans.push_back(curr);
        for (auto nei : adj[curr])
        {
            if (!vis[nei])
            {
                vis[nei] = 1;
                pq.push(nei);
            }
        }
    }
    for (auto a : ans)
        cout << a << " ";
    cout << endl;
}
