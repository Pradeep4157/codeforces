#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

        so every platform needs to be visited so

        for every i platform from 1 to n - 1 either i reach there using i - 1 or i + 1

        for 0th i can either use arr[i] or abs(arr[1] -arr[0])

        same for nth

        so one thing is true for any i i will either come from behind or i will climb manually or i will climb through the next platform

        so it can be seen as a prefix / suffix + dp question ?

        first we build prefix array  && suffix array

*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input_1.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    int index = 1;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int res = 0;
        vector<int> prefix(n), suffix(n), dp(n);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            // either i climb using arr[i]
            prefix[i] = arr[i];
            // else i want to climb using arr[i-1]
            prefix[i] = min(prefix[i], max(prefix[i - 1], (abs(arr[i] - arr[i - 1]))));
        }
        suffix[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = arr[i];
            suffix[i] = min(suffix[i], max(suffix[i + 1], abs(arr[i + 1] - arr[i])));
        }
        res = max(suffix[0], prefix[n - 1]);
        // cout << prefix[n - 1] << ":" << suffix[0] << endl;
        for (int i = 1; i < n - 1; i++)
        {
            // either i climb alone
            int curr = arr[i];
            // else come from behind
            curr = min(curr, max(abs(arr[i] - arr[i - 1]), prefix[i - 1]));
            // else come from ahead
            curr = min(curr, max(abs(arr[i] - arr[i + 1]), suffix[i + 1]));
            res = max(res, curr);
            // cout << curr << endl;
        }
        cout << "Case #" << index++ << ": ";
        cout << res << endl;
    }
    return 0;
}
