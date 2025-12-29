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
        int res = INT_MAX;
        for (int i = 0; i < n - 1; i++)
        {
            if (abs(arr[i] - arr[i + 1]) <= 1)
            {
                res = 0;
                break;
            }
            int mini = min(arr[i], arr[i + 1]);
            int maxi = max(arr[i], arr[i + 1]);
            for (int j = 0; j < n; j++)
            {
                if (j == i || j == i + 1)
                {
                    continue;
                }
                if (arr[j] >= mini && arr[j] <= maxi)
                {
                    int step1 = abs(j - i);
                    step1 = min(step1, abs(i + 1 - j));
                    res = min(res, step1);
                }
            }
        }
        if (res == INT_MAX)
        {
            cout << -1 << endl;
            continue;
        }
        else
            cout << res << endl;
    }
    return 0;
}
