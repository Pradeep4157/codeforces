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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int res = LLONG_MAX;

        int i = 0;
        while (i < n)
        {
            int left = i;
            int j = i;
            while (j < n && arr[i] == arr[j])
                j++;
            j--;
            int right = n - j - 1;
            int curr = (right + left) * arr[i];
            res = min(res, curr);
            i = j + 1;
        }
        cout << res << endl;
    }
    return 0;
}
