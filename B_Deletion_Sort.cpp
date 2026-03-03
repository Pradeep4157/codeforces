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
        {
            cin >> arr[i];
        }
        vector<pair<int, int>> temp;
        vector<int> sizes;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        bool found = false;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < arr[i - 1])
                found = 1;
        }
        int res;
        res = n;
        if (found)
            res = 1;
        cout << res << endl;
    }
    return 0;
}
