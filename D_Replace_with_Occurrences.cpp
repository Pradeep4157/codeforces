#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


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
        map<int, vector<int>> mp;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]].push_back(i);
        }
        bool ok = 1;
        for (auto a : mp)
        {
            if ((a.second.size() % a.first) != 0)
            {
                ok = 0;
                break;
            }
        }
        if (ok == 0)
        {
            cout << -1 << endl;
            continue;
        }
        vector<int> res(n);
        vector<int>
            unused;
        for (int i = 1; i <= n; i++)
        {
            unused.push_back(i);
        }
        for (auto a : mp)
        {
            int first = a.first;
            vector<int> &indexes = a.second;
            int usedcount = 0;
            for (auto a : indexes)
            {
                usedcount++;
                res[a] = unused.back();
                if (usedcount == first)
                {
                    usedcount = 0;
                    unused.pop_back();
                }
            }
        }
        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
