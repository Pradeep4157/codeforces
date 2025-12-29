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
        vector<int> arr(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        int res = 1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > b[i])
            {
                res += (arr[i] - b[i]);
            }
        }

        cout << res << endl;
    }
    return 0;
}
