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
        {
            cin >> arr[i];
        }
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
        }

        vector<int> res(n, 0);
        res[0] = 1;
        res[n - 1] = 1;
        for (int i = 1; i < n - 1; i++)
        {
            if (arr[i] == mini || arr[i] == maxi)
            {
                res[i] = 1;
            }
        }
        int currmini = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > currmini)
            {
                continue;
            }
            res[i] = 1;
            currmini = arr[i];
        }
        int currmaxi = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] < currmaxi)
            {
                continue;
            }
            currmaxi = arr[i];
            res[i] = 1;
        }
        string ans;
        for (int i = 0; i < n; i++)
        {
            if (res[i] == 1)
            {
                ans += '1';
            }
            else
                ans += '0';
        }
        cout << ans << endl;
    }
    return 0;
}
