#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    unordered_map<ll, unordered_set<ll>> adj;
    ll res = 0;
    for (int i = 0; i < m; i++)
    {
        int left, right;
        cin >> left >> right;
        if (left == right)
            res++;
        else if (adj[left].count(right) || adj[right].count(left))
            res++;
        else
        {
            adj[left].insert(right);
            adj[right].insert(left);
        }
    }
    cout << res << endl;
    return 0;
}
