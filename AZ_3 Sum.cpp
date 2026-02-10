#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
            OBSERVATIONS

*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n), temp;
        int res = LLONG_MAX;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());

        map<int, int> mp;

        for (int second = 0; second < n; second++)
        {
            for (int third = second + 1; third < n; third++)
            {
                int rem = k - arr[second] - arr[third];
                auto it = lower_bound(arr.begin(), arr.end(), rem);
                if (it != arr.begin())
                {
                    it--;
                }
                int left = it - arr.begin();
                int right = left + 1;
                while (right < n && ((right == second) || (right == third)))
                {
                    right++;
                }
                while (left >= 0 && ((left == second) || (left == third)))
                {
                    left--;
                }
                if ((right >= 0) && (right < n))
                {
                    res = min(res, abs(rem - arr[right]));
                }
                if ((left >= 0) && (left < n))
                {
                    res = min(res, abs(rem - arr[left]));
                }
                // now it is def present at some index..
            }
        }
        cout << res << endl;
    }
    return 0;
}
