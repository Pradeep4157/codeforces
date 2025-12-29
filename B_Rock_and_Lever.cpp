#include <bits/stdc++.h>
#define int long long
using namespace std;
int find(int a)
{
    int res = 0;
    while (a)
    {
        a >>= 1;
        res++;
    }
    return res;
}

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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int curr = find(arr[i]);
            mp[curr]++;
        }
        int res = 0;
        for (auto a : mp)
        {
            res += (a.second * (a.second - 1)) / 2;
        }
        cout << res << endl;
    }
    return 0;
}
