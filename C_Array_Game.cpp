#include <bits/stdc++.h>
#define int int64_t
using namespace std;

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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr.begin(), arr.end());
        if (k >= 3)
        {
            cout << 0 << endl;
            continue;
        }
        else if (k == 1)
        {
            int res = *min_element(arr.begin(), arr.end());
            for (int i = 0; i < n - 1; i++)
            {
                res = min(res, arr[i + 1] - arr[i]);
            }
            cout << res << endl;
        }
        else
        {
            // worst case

            int res = *min_element(arr.begin(), arr.end());
            for (int i = 0; i < n - 1; i++)
            {
                res = min(res, arr[i + 1] - arr[i]);
            }
            vector<int> temp;

            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    temp.push_back(arr[j] - arr[i]);
                }
            }
            sort(temp.begin(), temp.end());
            for (int i = 0; i < n; i++)
            {
                auto it = lower_bound(temp.begin(), temp.end(), arr[i]);
                if (it != temp.end())
                {
                    int closeele = *it;
                    res = min(res, abs(arr[i] - closeele));
                }
                if (it != temp.begin())
                {
                    it--;
                    int prev = *it;
                    res = min(res, abs(arr[i] - prev));
                }
            }

            cout << res << endl;
        }
    }
    return 0;
}
