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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        int res = 0;
        for (int i = 0; i < n - 1; i += 2)
        {
            res = max(res, arr[i + 1] - arr[i]);
        }
        cout << res << endl;
    }
    return 0;
}
