#include <bits/stdc++.h>
#define int long long

using namespace std;
long double dfs(int node, int par, vector<vector<int>> &adj)
{
    long double sum = 0;
    for (auto nei : adj[node])
    {
        if (nei != par)
        {
            sum += dfs(nei, node, adj) + 1;
        }
    }

    if (sum > 0)
    {
        long double divide = (long double)adj[node].size();
        if (par != -1)
            divide--;
        sum /= divide;
    }
    return sum;
}
signed main()
{
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int f, s;
        cin >> f >> s;
        adj[f].push_back(s);
        adj[s].push_back(f);
    }

    cout << fixed << setprecision(15) << dfs(1, -1, adj) << endl;
}