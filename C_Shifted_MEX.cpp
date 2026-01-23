#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    for any value if arr[i] - 1 is there

    use dp of that else mp of arr[i] == 1




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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        map<int, int> mp;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int curr_val = arr[i];
            int prev_val = arr[i] - 1;
            if (mp.find(prev_val) != mp.end())
            {
                mp[curr_val] = mp[prev_val] + 1;
            }
            else
                mp[curr_val] = 1;
            res = max(res, mp[curr_val]);
        }
        cout << res << endl;
    }
    return 0;
}
