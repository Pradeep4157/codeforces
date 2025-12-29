#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        set<pair<int, int>> edges;
        vector<int> indegree(n + 1, 0);
        for (int i = 0; i < n - 1; i++)
        {
            int first, second;
            cin >> first >> second;
            indegree[first]++;
            indegree[second]++;
            edges.insert({first, second});
            edges.insert({second, first});
        }
        vector<pair<int, int>> degree;
        for (int i = 1; i <= n; i++)
        {
            degree.push_back({indegree[i], i});
        }
        sort(degree.rbegin(), degree.rend());

        int res = 0;
        // first we will do for non adjacent
        for (int i = 0; i < n; i++)
        {
            int degree1 = degree[i].first;
            int ele1 = degree[i].second;
            for (int j = i + 1; j < n; j++)
            {
                int degree2 = degree[j].first;
                int ele2 = degree[j].second;
                if (edges.count({ele1, ele2}))
                    continue;
                else
                {
                    res = max(res, degree1 + degree2 - 1);
                    break;
                }
            }
        }
        // now we will do for adjacent elements
        for (auto a : edges)
        {
            int first = a.first;
            int second = a.second;
            int degree1 = indegree[first];
            int degree2 = indegree[second];
            res = max(res, degree1 + degree2 - 2);
        }
        cout << res << endl;
    }

    return 0;
}
