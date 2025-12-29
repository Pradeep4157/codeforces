#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> allCycles;
vector<int> currentPath;
vector<bool> visited;
vector<int> longestPath;

void dfs(int start, int u, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &currentPath)
{
    visited[u] = true;
    currentPath.push_back(u);

    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs(start, v, adj, visited, currentPath);
        }
        else if (v == start && currentPath.size() > 2)
        {
            allCycles.push_back(currentPath);
        }
    }

    visited[u] = false;
    currentPath.pop_back();
}

void findCycles(int n, vector<vector<int>> &adj)
{
    visited.assign(n, false);
    for (int i = 0; i < n; ++i)
    {
        dfs(i, i, adj, visited, currentPath);
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
        allCycles.clear();
        currentPath.clear();
        visited.clear();
        longestPath.clear();

        int m;
        cin >> m;

        vector<vector<int>> adj(1005);
        map<pair<int, int>, int> edgeIndexMap;
        int n = 2;

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            n = max({n, u + 1, v + 1});
            edgeIndexMap[{min(u, v), max(u, v)}] = i + 1;
        }

        findCycles(n, adj);

        for (auto &a : allCycles)
            sort(a.begin(), a.end());

        vector<vector<bool>> iscycles(n, vector<bool>(n, false));
        for (auto a : allCycles)
        {
            int size = a.size();
            iscycles[a[0]][a[size - 1]] = true;
            iscycles[a[size - 1]][a[0]] = true;
        }
        if (4 < n)
        {
            cout << iscycles[1][4] << endl;
        }
        int res = 0;
        for (auto a : allCycles)
        {
            int size = a.size();
            int val = a[size - 1] - a[0] + 1 - size;
            if (val > res)
            {
                res = val;
                longestPath = a;
            }
        }

        vector<bool> vis(n, false);
        vector<int> tempPath;

        function<void(int, int)> dfsCheck = [&](int u, int start)
        {
            vis[u] = true;
            tempPath.push_back(u);
            for (int v : adj[u])
            {
                if (!iscycles[u][v])
                {
                    int val = abs(v - start) + 1;
                    if (val > res)
                    {
                        res = val;
                        longestPath = tempPath;
                        longestPath.push_back(v);
                    }
                    if (!vis[v])
                        dfsCheck(v, start);
                }
            }
            tempPath.pop_back();
        };

        for (int i = 0; i < n; ++i)
        {
            vis.assign(n, false);
            tempPath.clear();
            dfsCheck(i, i);
        }

        cout << longestPath.size() - 1 << endl;

        for (int i = 1; i < longestPath.size(); i++)
        {
            int u = longestPath[i - 1];
            int v = longestPath[i];
            cout << edgeIndexMap[{min(u, v), max(u, v)}] << " ";
        }
        cout << '\n';
    }

    return 0;
}