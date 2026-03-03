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
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            maxi = max(maxi, arr[i]);
        }
        int res = 0;
        for (auto a : arr)
        {
            if (a == maxi)
                res++;
        }
        cout << res << endl;
    }
    return 0;
}
