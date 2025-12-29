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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int x;
        cin >> x;
        bool found = false;
        if (n == 1 && arr[0] == x)
            found = 1;
        for (int i = 0; i < n - 1; i++)
        {
            int mini = min(arr[i], arr[i + 1]);
            int maxi = max(arr[i], arr[i + 1]);
            if (x >= mini && x <= maxi)
            {
                found = 1;
                break;
            }
        }
        if (found)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
