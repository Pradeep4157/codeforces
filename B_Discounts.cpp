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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> d(k);
        for (int i = 0; i < k; i++)
            cin >> d[i];
        sort(d.begin(), d.end());
        sort(arr.rbegin(), arr.rend());
        int i = 0;
        int res = 0;
        for (auto a : d)
        {
            int left = n - i;
            if (left < a)
                break;
            int end = a + i - 1;
            while (i < end)
            {
                res += arr[i];
                i++;
            }
            i++;
        }
        if (i < n)
        {
            while (i < n)
            {
                res += arr[i];
                i++;
            }
        }
        cout << res << endl;
    }
    return 0;
}
