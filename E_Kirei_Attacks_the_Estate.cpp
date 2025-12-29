#include <bits/stdc++.h>
#define int long long
using namespace std;
void dfs(int curr, int parent, vector<int> &worst, vector<int> &best, vector<vector<int>> &adj, vector<int> &arr)
{
    if (parent == -1)
    {
        best[curr] = arr[curr - 1];
        worst[curr] = arr[curr - 1];
    }
    for (auto child : adj[curr])
    {
        if (child != parent)
        {
            best[child] = max(arr[child - 1], arr[child - 1] - worst[curr]);
            worst[child] = arr[child - 1] - best[curr];
            dfs(child, curr, worst, best, adj, arr);
        }
    }
    return;
}
int_fast32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; i++)
        {
            int left, right;
            cin >> left >> right;
            adj[left].push_back(right);
            adj[right].push_back(left);
        }
        vector<int> best(n + 1), worst(n + 1);
        dfs(1, -1, worst, best, adj, arr);
        for (int i = 1; i < best.size(); i++)
            cout << best[i] << " ";
        cout << endl;
    }
    return 0;
}
