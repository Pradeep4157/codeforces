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
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first >> arr[i].second;
        }
        int res = 0;
        for (int temp = 1; temp <= 100; temp++)
        {
            int curr = temp;
            for (int i = 0; i < n; i++)
            {
                if (curr >= arr[i].second)
                    curr = arr[i].second;
                else if (curr <= arr[i].first)
                    curr = arr[i].first;
            }
            res = max(res, curr);
        }
        cout << res << endl;
    }
    return 0;
}
