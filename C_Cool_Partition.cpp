#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
            mp[arr[i]].push_back(i);

        int start = 1;
        if (mp[arr[0]].size() == 1)
        {
            cout << 1 << endl;
            continue;
        }
        int res = 2;
        int nextend = mp[arr[0]][1] + 1;
        while (true)
        {
            int nextstart = nextend - 1;
            bool ok = 1;
            while (start < nextstart)
            {
                int ele = arr[start];
                vector<int> &indexes = mp[ele];
                auto it = lower_bound(indexes.begin(), indexes.end(), nextstart);
                if (it == indexes.end())
                {
                    ok = false;
                    break;
                }
                int index = *it;
                nextend = max(nextend, index);
                start++;
            }
            if (ok == false)
                break;

            vector<int> mainindexes = mp[arr[0]];
            start++;
            auto it1 = lower_bound(mainindexes.begin(), mainindexes.end(), nextend);
            res++;
            if (it1 == mainindexes.end())
                break;
            nextend = *it1 + 1;
            nextstart = *it1;
        }
        cout << res << endl;
    }
    return 0;
}
