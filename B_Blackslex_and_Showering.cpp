#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    i remove some ele and then

    the res is prefix sum + suffix

    sum..

    add abs of prev - next

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
        vector<int> prefix(n, 0), suffix(n, 0);
        for (int i = 1; i < n; i++)
        {
            prefix[i] = abs(arr[i] - arr[i - 1]);
            prefix[i] += prefix[i - 1];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = abs(arr[i] - arr[i + 1]);
            suffix[i] += suffix[i + 1];
        }
        int res = suffix[0];
        for (int i = 0; i < n; i++)
        {
            int curr = 0;
            if (i)
                curr += prefix[i - 1];
            if (i < n - 1)
                curr += suffix[i + 1];
            if (i > 0 && i < n - 1)
            {
                // then we need to add this as well.
                curr += abs(arr[i - 1] - arr[i + 1]);
            }
            res = min(res, curr);
        }
        cout << res << endl;
    }
    return 0;
}
