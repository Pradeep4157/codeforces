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
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int i = 0;
        bool ok = 1;
        bool used = false;
        while (i < n)
        {
            if (arr[i] && !used)
            {
                used = 1;
                i += x - 1;
            }
            else if (arr[i] && used)
                ok = false;
            i++;
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
