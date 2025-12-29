#include <bits/stdc++.h>
using namespace std;
bool dfs(int curr, int par, vector<vector<int>> &adj, vector<bool> &vis)
{
    if (adj[curr].size() != 2)
        return false;
    if (vis[curr] == 1)
        return true;
    vis[curr] = 1;
    for (auto neighbor : adj[curr])
    {
        if (neighbor != par)
        {
            if (dfs(neighbor, curr, adj, vis))
                return true;
            else
                return false;
        }
    }
}
int main()
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
    for(int i=1;i<=n;i++){
        if(adj[i].size()!=2){
            cout<<"No"<<endl;
            return 0;
        }
    }
    vector<bool> vis(n + 1, false);
    bool ok = 1;
    if (dfs(1, -1, adj, vis))
    {
        ok = 0;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]) ok=1;
    }
    if (ok == 0)
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
    return 0;
}
