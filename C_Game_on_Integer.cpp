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
        int res = arr[0] - arr[1];
        int i = 2;

        vector<int> suffix(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            suffix[i] += arr[i];
            if (i < n - 1)
                suffix[i] += suffix[i + 1];
        }
        bool ok = 1;
        while (i < n)
        {
            if (ok)
            {
                ok = false;
                if (arr[i] >= 0)
                {
                    res += arr[i];
                }
                else
                    break;
            }
            else
            {
                ok = true;
                if (arr[i] >= 0)
                {
                    res -= arr[i];
                }
                else
                    break;
            }
            i++;
        }
        cout << res << endl;
    }
    return 0;
}
