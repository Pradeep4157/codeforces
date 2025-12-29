#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> isthere(n);
    for (int i = 0; i < n; i++)
        cin >> isthere[i];
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int first, second;

        cin >> first >> second;
        first--;
        second--;
        adj[first].push_back(second);
        adj[second].push_back(first);
    }

    queue<vector<int>> q;
    if (isthere[0])
    {
        q.push({1, 0, -1});
    }
    else
        q.push({0, 0, -1});
    // a node will only be visited once
    int res = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            vector<int> z = q.front();
            q.pop();
            int cats = z[0];
            int curr = z[1];
            int par = z[2];
            if (adj[curr].size() == 1 && curr != 0)
            {

                res++;
                continue;
            }
            for (auto nei : adj[curr])
            {
                if (nei != par)
                {

                    int newcats = cats;
                    if (isthere[nei])
                    {
                        newcats++;
                        if (newcats <= k)
                        {
                            q.push({newcats, nei, curr});
                        }
                    }
                    else
                    {
                        q.push({0, nei, curr});
                    }
                }
            }
        }
    }
    cout << res << endl;

    return 0;
}
