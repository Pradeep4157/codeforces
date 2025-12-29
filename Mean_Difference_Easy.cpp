#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    either i will use left elements and the last element ..

    else last elements and first element..

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
        int res = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        // coming from left..
        for (int i = 0; i < n - 1; i++)
        {
            sum += arr[i];
            int ele = i + 1;
            int currsum = sum + arr[n - 1];
            currsum /= (ele + 1);
            res = max(res, abs(arr[0] - currsum));
            res = max(res, abs(currsum - arr[n - 1]));
        }
        // coming from right..
        sum = 0;
        for (int i = n - 1; i > 0; i--)
        {
            sum += arr[i];
            int ele = n - i + 1;
            int currsum = sum + arr[0];
            currsum /= (ele);
            res = max(res, abs(arr[0] - currsum));
            res = max(res, abs(currsum - arr[n - 1]));
        }
        cout << res << endl;
    }
    return 0;
}
