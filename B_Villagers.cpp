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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.rbegin(), arr.rend());
        int i = 0;
        int res = 0;
        while (i < n)
        {
            res += arr[i];
            i += 2;
        }
        cout << res << endl;
    }
    return 0;
}
