#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:



    open time..


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int res = 0;
    int open_time = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= open_time)
        {
            res += (arr[i] - open_time);
            open_time = arr[i] + 100;
        }
    }
    if (open_time <= t)
    {
        res += (t - open_time);
    }
    cout << res << endl;

    return 0;
}
