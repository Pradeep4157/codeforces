#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so if at any node..

    he first goes to the left,left,left,...

    then right,right,right,right..

    so  its dfs traversal that he's doing.. ig..

    apart from leaf nodes all the nodes are visted twice..

    once while going down and other while going up..



    for a node it will visit its subtree then

    for zero node..

    it goes to all its childs..

    and then comes back..

    for other nodess..

    time array is going to store time for traversing its subtree..

    if leaf then time is 0

    else time of other node is time of all childs + 2*no of child..

    this dp also we will have to find in dfs way ig..

    or reverse dfs way..

    now dp[i] is i go to all these child nodes then i go back to parent and then parent  goes to all its right childs not the left ones..

    and then to that i will add dp[parent] and then move to its child..


    for a node if its left child..

    it will vis all its child go to parent it will visit its right child and then go above..

    if right child then :

        visit all subtree go to par it goes to left child and then again visit this one and then go above..

        so for right its right + left time + par time

        for left left time + left time + right time + par time..
*/
vector<int> dp, TIME;
vector<pair<int, int>> adj;
const int mod = (int)(1e9 + 7);
void dfs1(int node)
{
    // leaf node..
    if ((adj[node].first == 0) && (adj[node].second == 0))
    {
        return;
    }
    else
    {
        int curr_time = 0;
        if (adj[node].first != 0)
        {

            curr_time += 2;
            dfs1(adj[node].first);
            curr_time += TIME[adj[node].first];
            curr_time %= mod;
        }
        if (adj[node].second != 0)
        {
            curr_time += 2;
            dfs1(adj[node].second);
            curr_time += TIME[adj[node].second];
            curr_time %= mod;
        }
        TIME[node] = curr_time;
    }
}
void dfs2(int node, int par, bool left)
{
    if (node == 1)
    {
        int curr_time = 0;
        if (adj[node].first != 0)
        {
            // go left..
            curr_time++;
            curr_time %= mod;
            curr_time += TIME[adj[node].first];
            // go right..
            curr_time++;
            curr_time %= mod;
            curr_time += TIME[adj[node].second];
            // come back..
            curr_time += 4;
            curr_time %= mod;
            // done..
            dp[node] = curr_time;
            if (adj[node].first != 0)
            {
                dfs2(adj[node].first, node, 1);
                dfs2(adj[node].second, node, 0);
            }
        }
    }
    else if (node == 0)
    {
        int curr_time = 1;
        curr_time += TIME[1];
        curr_time %= mod;
        dp[node] = curr_time;
        dfs2(1, 0, 1);
    }
    else
    {
        if (left)
        {
            // then 2* current time  +
            int curr_time = 0;
            curr_time += TIME[node];
            curr_time %= mod;
            curr_time += TIME[node];
            curr_time %= mod;
            if (node != 0)
            {
                // then we go to  par come back visit again and go back
                curr_time += 3;
                curr_time %= mod;
            }
            dp[node] = curr_time;
            // visit both childs..
            if (adj[node].first != 0)
            {
                dfs2(adj[node].first, node, 1);
                dfs2(adj[node].second, node, 0);
            }
        }
        else
        {
            int curr_time = 0;
            curr_time += TIME[node];
            curr_time %= mod;
            if (node != 0)
            {
                // we go to par..
                curr_time++;
                // par goes left..
                curr_time += TIME[adj[par].first];
                curr_time %= mod;
                curr_time++;
                curr_time %= mod;
                // it comes back..
                curr_time++;
                curr_time %= mod;
                // then again visit here..
                curr_time++;
                curr_time %= mod;
                curr_time += TIME[node];
                // and goes back..
                curr_time++;
                curr_time %= mod;
                dp[node] = curr_time;
                if (adj[node].first != 0)
                {
                    dfs2(adj[node].first, node, 1);
                    dfs2(adj[node].second, node, 0);
                }
            }
        }
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
        int n;
        cin >> n;
        adj.clear();
        adj.resize(n + 1);
        dp.assign(n + 1, 0);
        TIME.assign(n + 1, 0);
        adj[0].first = 1;
        for (int i = 0; i < n; i++)
        {
            int first, second;
            cin >> first >> second;
            adj[i + 1].first = first;
            adj[i + 1].second = second;
        }
        // now time calc..
        dfs1(0);
        dfs2(0, -1, 1);
        for (auto a : dp)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
