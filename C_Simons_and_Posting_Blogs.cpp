#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> vec;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vector<int> temp;
        unordered_set<int> see;

        for (int j = 0; j < x; j++)
        {
            int v;
            cin >> v;
            if (see.count(v))
            {
                see.erase(v);
            }
            see.insert(v);
        }
        for (auto it : see)
        {
            temp.push_back(it);
        }

        vec.push_back(temp);
    }

    sort(vec.begin(), vec.end());

    map<int, int> mp;
    vector<int> ans;
    while (vec.size() > 0)
    {
        for (int i = 0; i < vec[0].size(); i++)
        {
            ans.push_back(vec[0][i]);
            mp[vec[0][i]] = 1;
        }
        vector<vector<int>> used;
        for (int i = 0; i < vec.size(); i++)
        {
            vector<int> temp1;
            for (int j = 0; j < vec[i].size(); j++)
            {
                int it = vec[i][j];
                if (mp[it] == 0)
                {
                    temp1.push_back(it);
                }
            }
            if (temp1.size() > 0)
            {
                used.push_back(temp1);
            }
        }
        sort(used.begin(), used.end());
        vec = used;
    }

    // cout << endl;

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
