#include <bits/stdc++.h>
#define int long long
using namespace std;

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
        int ans5;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.rbegin(), arr.rend());
        vector<int> sorted(arr.begin(), arr.end());
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]] = i;
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                auto it1 = upper_bound(sorted.begin(), sorted.end(), arr[i] - arr[j]);
                auto it2 = upper_bound(sorted.begin(), sorted.end(), arr[0] - arr[i] - arr[j]);
                int index = n - 1;
                if (it1 != sorted.end())
                {
                    int number = *it1;
                    index = mp[number];
                }
                if (it2 != sorted.end())
                {
                    int number = *it2;
                    index = min(index, mp[number]);
                }
                if (index > j)
                {
                    res += (index - j);
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
