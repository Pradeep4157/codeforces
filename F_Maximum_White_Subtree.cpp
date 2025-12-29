#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
vector<int> final_score, down_score;
void dfs1(int node, int par, vector<vector<int>> &adj, vector<int> &good)
{

    int curr_score = (good[node] ? 1 : -1);

    for (auto nei : adj[node])
    {
        if (nei != par)
        {
            dfs1(nei, node, adj, good);
            // now if good then we will consider..
            curr_score += (max(0LL, down_score[nei]));
        }
    }
    down_score[node] = curr_score;
}

void dfs2(int node, int par, vector<vector<int>> &adj, vector<int> &good)
{

    // only considering par node..

    int score2 = final_score[par];

    // if the DS of curr_node < 0 , then par didnt consider this..

    // so first we will incl.. it .

    if (down_score[node] < 0)
    {
        score2 += down_score[node];
    }

    final_score[node] = max(down_score[node], score2);

    for (auto nei : adj[node])
    {
        if (nei != par)
        {
            dfs2(nei, node, adj, good);
        }
    }
}

void solve(int n, vector<vector<int>> &edges, vector<int> &good)
{
    /*
        so first dfs will only consider the children subgraph..

        2nd dfs will consider the par subgraph..

        in 2dfs if the downward_score of current_node > 0 ..

        then sub from par and store best in final_score..



    */

    // first adj..

    vector<vector<int>> adj(n);
    for (auto a : edges)
    {
        int first = a[0];
        int second = a[1];
        adj[first].push_back(second);
        adj[second].push_back(first);
    }

    // resizing..

    down_score.assign(n + 1, -1e5);
    final_score.assign(n + 1, -1e5);

    // now first the child subGraph..
    dfs1(0, n + 1, adj, good);

    // now final score..

    dfs2(0, n, adj, good);

    final_score.pop_back();
    for (auto a : final_score)
        cout << a << " ";
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> good(n);
    for (int i = 0; i < n; i++)
        cin >> good[i];
    vector<vector<int>> edges;
    for (int i = 0; i < n - 1; i++)
    {
        int first, second;
        cin >> first >> second;
        first--;
        second--;
        edges.push_back({first, second});
    }

    solve(n, edges, good);

    return 0;
}
