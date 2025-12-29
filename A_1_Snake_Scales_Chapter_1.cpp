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
#ifndef ONLINE_JUDGE
    freopen("snake_scales_chapter_1_validation_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    int index = 1;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int res = 0;
        for (int i = 0; i < n - 1; i++)
        {
            res = max(res, abs(arr[i] - arr[i + 1]));
        }
        cout << "Case #" << index++ << ": ";
        cout << res << endl;
    }
    return 0;
}
