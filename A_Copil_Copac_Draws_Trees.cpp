#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<bool> vis;
int maxi;
void recursion(int previndex, vector<vector<int>> &indexes, vector<pair<int, int>> &adj, int prevnumber, int ans)
{
    int currnumber = (prevnumber == adj[previndex].first) ? adj[previndex].second : adj[previndex].first;
    if (indexes[currnumber].size() == 1)
    {
        maxi = max(maxi, ans);
        return;
    }
    int res = (indexes[currnumber][0] == previndex) ? 0 : 1;
    if (res == 1)
    {
        ans++;
        // cout << prevnumber << "::" << currnumber << "->" << indexes[currnumber][0] << ":" << previndex << endl;
    }

    vis[currnumber] = 1;
    for (auto nextindex : indexes[currnumber])
    {
        if (nextindex == previndex)
            continue;
        int nextnumber = (adj[nextindex].first == currnumber) ? adj[nextindex].second : adj[nextindex].first;
        if (vis[nextnumber])
            continue;
        recursion(nextindex, indexes, adj, currnumber, ans);
    }
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
        n--;
        maxi = -1;
        vector<pair<int, int>> arr(n + 10);
        vector<vector<int>> indexes(n + 10);
        for (int i = 0; i < n; i++)
        {
            int left, right;
            cin >> left >> right;
            left--;
            right--;
            arr[i].first = left;
            arr[i].second = right;
            indexes[left].push_back(i);
            indexes[right].push_back(i);
        }

        vis.clear();
        vis.resize(n + 10, false);
        int count = 1;
        vis[0] = 1;
        for (auto a : indexes[0])
        {
            recursion(a, indexes, arr, 0, 1);
        }
        cout << maxi << endl;
    }
    return 0;
}
