#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so this can be solved using cycle detection because for every row we can ignore the first number because that will be wrong most of the times but the relative order

    of the remaining nodes should always remain same if the ss is correct so if the relative order is always same then for any arr[i], arr[j] where j > i in some row x

    it should be same in all the other rows as well and in case it is not true that means it occurs before i , which leads to cycle formation .

    so for this cycle detection we can have vis[] array that will tell us whether the current node is visited never or whether it is already visited or it is visited in the

    current dfs traversal , so for any node in the adj array if the node is zero then only we will start the dfs from this node && during the dfs we will first mark

    the node as 1 and if we get cycle we will return 1 else we will mark this node as 2 and return false

    during traversal if the current node is 1 we return true

    else if the node is 2 we return false

    else if the node is 0 then we do dfs of this node as well .

*/
bool iscycle(int node, map<int, set<int>> &mp, vector<int> &vis)
{
    if (vis[node] == 1)
    {
        // then we got a cycle
        return true;
    }
    else if (vis[node] == 2)
    {
        // then we have already done a cycle check for this node
        return false;
    }
    else
    {
        // now this node is not visited till now
        // first we will mark it as current visited
        vis[node] = 1;
        for (auto a : mp[node])
        {
            bool curr = iscycle(a, mp, vis);
            if (curr)
            {
                // then we got a cycle
                return true;
            }
        }
        // else we did not get any cycle
        // so we first mark this node as safe
        vis[node] = 2;
        return false;
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
        int n, k;
        cin >> n >> k;
        map<int, set<int>> mp;
        vector<vector<int>> arr(k, vector<int>(n));
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        }
        // now we will insert in map

        for (int i = 0; i < k; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                // the current node is par of next node
                mp[arr[i][j]].insert(arr[i][j + 1]);
            }
        }
        bool found = false;
        vector<int> vis(n + 1, 0);
        for (auto a : mp)
        {
            // if the current node is never visited
            if (vis[a.first] == 0)
            {
                // then we will do  cycle detection from this node

                bool curr = iscycle(a.first, mp, vis);
                if (curr == true)
                {
                    found = 1;
                    break;
                }
            }
        }
        if (found == false)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
