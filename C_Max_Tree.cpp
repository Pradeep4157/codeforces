#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

        the node which does not want to be bigger than anyone we will give that value =1
        we will store the number of  elements which a current node wants to be greater than


        there is some way that i can assign values such that i get greater of x and y
        at each step

        so we need to create a directed tree where the current node will mark towards its parent

        and for every node we will assign valeues and keep traversing until the array is filled


        so if we go from top to bottom there's a chance that we might give bigger values
        to children

        so its better to start form leaf nodes

*/
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
        vector<set<int>> adj(n + 1), par(n + 1);
        for (int i = 0; i < n - 1; i++)
        {
            int first, second, x, y;
            cin >> first >> second >> x >> y;
            if (x > y)
            {
                adj[first].insert(second);
                par[second].insert(first);
            }
            else
            {
                par[first].insert(second);
                adj[second].insert(first);
            }
        }
        // for (int i = 1; i <= n; i++)
        // {
        //     cout << i << ":";
        //     for (auto a : par[i])
        //         cout << a << " ";
        //     cout << endl;
        // }
        vector<bool> vis(n + 1, false);
        queue<int> leaf;
        for (int i = 1; i < adj.size(); i++)
        {
            if (adj[i].empty())
            {
                leaf.push(i);
                vis[i] = 1;
            }
        }

        vector<int> res(n, -1);
        int val = 1;
        while (!leaf.empty())
        {
            int size = leaf.size();
            for (int i = 0; i < size; i++)
            {
                int curr = leaf.front();

                leaf.pop();
                for (auto nei : par[curr])
                {
                    adj[nei].erase(curr);
                    if (adj[nei].empty())
                    {
                        leaf.push(nei);
                    }
                }
                if (res[curr - 1] == -1)
                {
                    res[curr - 1] = val;
                    val++;
                }
            }
        }

        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
