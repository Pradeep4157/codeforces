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
        int m = (n * (n - 1)) / 2;
        vector<int> arr(m);
        for (int i = 0; i < m; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());

        if (n == 2)
        {
            cout << arr[0] << endl;
            continue;
        }
        int res = arr[0];
        int skip = 1;
        int taken = 1;
        for (int i = 1; i < m; i += skip)
        {
            if (taken == n - 1)
            {
                break;
            }
            res += arr[i];
            // cout << arr[i] << endl;
            skip++;
            taken++;
        }
        cout << res << endl;
    }
    return 0;
}
