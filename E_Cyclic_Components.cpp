#include <bits/stdc++.h>
#define int long long
using namespace std;
class dsu
{
    vector<int> size, par;

public:
    dsu(int n)
    {
        size.resize(n + 1, 1);
        par.resize(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            par[i] = i;
        }
    }
    int find(int n)
    {
        if (par[n] == n)
            return n;
        else
            return par[n] = find(par[n]);
    }
    int getsize(int n)
    {
        int par = find(n);
        return size[par];
    }
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (size[a] < size[b])
            swap(a, b);
        size[a] += size[b];
        par[b] = a;
        return 1;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    dsu du(n);
    set<int> candidates;
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int first, second;
        cin >> first >> second;
        indegree[first]++;
        indegree[second]++;
        bool joined = du.unite(first, second);
        if (joined == false && du.getsize(first) >= 3)
        {
            int par = du.find(first);
            candidates.insert(par);
        }
    }
    map<int, vector<int>> mp;

    for (auto a : candidates)
    {
        int par = du.find(a);
        mp[par] = {};
    }

    for (int i = 1; i <= n; i++)
    {
        int par = du.find(i);
        if (mp.find(par) != mp.end())
        {
            mp[par].push_back(i);
        }
    }
    int res = 0;
    for (auto a : mp)
    {
        bool ok = 1;
        for (auto b : a.second)
        {
            if (indegree[b] != 2)
            {
                ok = false;
                break;
            }
        }
        if (ok)
            res++;
    }
    cout << res << endl;
    return 0;
}
