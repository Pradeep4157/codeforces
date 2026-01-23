#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    so there is going to multiple graphs..

    all the nei are either undpited or if already dpited the parity of that nei and the current node should

    be diff, if they are same then it is not possible..

    else continue with other undpited nei..
*/

int n, m;
vector<vector<int>> adj;
vector<int> dp;
bool dfs(int node, int par, int parity)
{
    dp[node] = parity;
    int nei_parity = (parity + 1) % 2;
    bool res = false;
    for (auto nei : adj[node])
    {
        if (dp[nei] == -1)
        {
            // then we find from this nei node..
            res |= dfs(nei, node, nei_parity);
        }
        else
        {
            // here is where conflict might occur..
            if (nei_parity != dp[nei])
            {
                res = 1;
                break;
            }
        }
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    adj.resize(n + 1);
    dp.assign(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int first, second;
        cin >> first >> second;
        adj[first].push_back(second);
        adj[second].push_back(first);
    }
    bool found = false;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == -1)
        {
            found |= dfs(i, -1, 0);
        }
    }
    cout << ((found == false) ? "YES" : "NO") << endl;

    return 0;
}
