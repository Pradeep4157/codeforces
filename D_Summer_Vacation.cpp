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

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(m + 1);
    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        int day, reward;
        cin >> day >> reward;
        if (day <= m)
            arr[day].push_back(reward);
    }

    int days = 0;
    int res = 0;
    for (int i = 0; i <= m; i++)
    {
        for (auto a : arr[i])
            ms.insert(a);
        if (!ms.empty())
        {
            auto it = prev(ms.end());
            if (it != ms.end())
            {
                res += *it;
                ms.erase(it);
            }
        }
    }
    cout << res << endl;

    return 0;
}
