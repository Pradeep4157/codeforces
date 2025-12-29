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
        int n, j, k;
        cin >> n >> j >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int number = arr[j - 1];
        int eliminate = n - k;

        sort(arr.rbegin(), arr.rend());
        if (k == 1)
        {
            if (arr[0] != number)
            {
                cout << "NO" << endl;
                continue;
            }
            else
                cout << "YES" << endl;
            continue;
        }
        else
        {
            // best will eliminate all
            cout << "YES" << endl;
        }
    }
    return 0;
}
