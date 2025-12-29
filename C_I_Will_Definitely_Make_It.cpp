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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        k--;
        int ele = arr[k];
        int index = 0;
        sort(arr.begin(), arr.end());
        int maxele = arr[n - 1];

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == ele)
                index = i;
        }

        // cout << index << endl;
        bool ok = false;
        int wl = 1;

        for (int i = index; i < n; i++)
        {

            if (arr[i] == maxele)
            {

                ok = 1;
                break;
            }
            int nexttime = arr[i + 1] - arr[i];
            wl += nexttime;
            // cout << arr[i] << ":" << wl << endl;
            if (wl > arr[i] + 1)
            {
                // cout << i << endl;
                // cout << wl << ":" << arr[i] << endl;
                ok = false;
                break;
            }
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
