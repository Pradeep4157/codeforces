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
        int zero = 0;
        int m = 0;
        for (auto a : arr)
        {
            if (a == 0)
                zero++;
            else if (a == -1)
                m++;
        }
        int res = zero;
        if (m & 1)
            res += 2;
        cout << res << endl;
    }
    return 0;
}
