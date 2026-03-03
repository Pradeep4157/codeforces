#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so you cannot backtrack more than 1 node..

    now we need to check will the subtree which consists of node n

    will be visited last ?

    for all the other branches apart from n branch  i will have to backtrack to reach n..

    for  all the other branches there is only is only 1 way

    that is i come till this node then i backtrack from here to reach node n..

    now ..

    for the branch that  consists of node n..


    so we need to no of nodes in that subtree..

    and we also need path from n ....1

    we will traverse from this n..1

    and find dp ..

    and dp[1] is going to be the final ans..

    now we traverse from n..1 and for each node

    all the nei that are not in the path i will take all their subtree sizes

    and add it here..

    so at each node of this path i need to store the no of ways that i get when i traverse its child in the path

    and no of ways where i dont traverse its child in the path..


    so for each node

    if i set then i can add it to all the  ways of its child's child..

    if i dont set to that i can add all the ways of its next child ?









*/
const int mod = 998244353;
vector<int> path;
vector<int> subtree_size;
int n;
pair<int, int> dfs(int node, int par, vector<vector<int>> &adj)
{
    // if leaf node..
    if (((adj[node].size() == 1) && (adj[node][0] == par)) || (node == n))
    {
        // then it is leaf node..
        // if it is n then return 1,1 else 1,0
        subtree_size[node] = 1;
        if (node == n)
        {
            path.push_back(node);
            return {1, 1};
        }
        else
            return {0, 1};
    }
    // now for the intermediate nodes..
    int curr_size = 1;
    bool is_there = 0;

    for (auto nei : adj[node])
    {
        if (nei != par)
        {
            pair<int, int> curr = dfs(nei, node, adj);
            if (curr.first == 1)
            {
                // this is also in the path..
                path.push_back(node);
                is_there = 1;
            }
            curr_size += curr.second;
            curr_size %= mod;
        }
    }
    subtree_size[node] = curr_size;
    if (is_there)
    {
        return {1, curr_size};
    }
    else
        return {0, curr_size};
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n;
        vector<vector<int>> adj(n + 1);
        path.clear();
        subtree_size.assign(n + 1, 0);
        for (int i = 0; i < n - 1; i++)
        {
            int first, second;
            cin >> first >> second;
            adj[first].push_back(second);
            adj[second].push_back(first);
        }
        dfs(1, -1, adj);
        int res = 1;
        int size = path.size();
        vector<pair<int, int>> dp(size);
        // for the nth node i cannot go to its child because it doesnt have one !!
        dp[0].first = 0;
        // and if i am traversing its child that is i am just going to that node once then there is 1 way that is i reach node n !!
        dp[0].second = 1;
        for (int i = 1; i < size; i++)
        {
            // now for each of these nodes..
            int node = path[i];
            int par = -1;
            if (i + 1 < size)
                par = path[i + 1];
            int child = path[i - 1];
            int curr = 0;
            // firstly i can go to all its neighbors apart from parent and come back this is def..
            for (auto nei : adj[node])
            {
                if (nei != par && nei != child)
                {
                    // this nodes i can visit anytime..
                    curr += subtree_size[nei];
                }
            }
            curr++;
            // going to these nei nodes and coming back is literally the same thing as going to the child and coming back..
            // its the same thing for node but not the child node because it hasent been visited even once in these nei ways..
            dp[i].second += curr;
            if (i > 1)
            {
                // in these cases only i can go to the child come back and go back..
                dp[i].first = 1;
            }
            // now if it hasent done the child back traversal then its child can do anything i dont have any problem..
            int SECOND = dp[i - 1].first;
            SECOND += dp[i - 1].second;
            SECOND %= mod;
            dp[i].second *= SECOND;
            dp[i].second %= mod;
            // for the thing that it has done the child traversal it will not allow its child to go either to some nei or do its
            // child traversal but we will allow its child's child to do whatever he wants..
            if (i - 2 >= 0)
            {
                SECOND = 0;
                SECOND += dp[i - 2].first;
                SECOND += dp[i - 2].second;
                SECOND %= mod;
                dp[i].first *= SECOND;
                dp[i].first %= mod;
            }
        }

        res = 0;
        res += dp[size - 1].first;
        res += dp[size - 1].second;
        res %= mod;
        cout << res << endl;
    }
    return 0;
}
