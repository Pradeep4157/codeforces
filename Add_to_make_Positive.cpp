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
        int maxi = *max_element(arr.begin(), arr.end());
        int mini = *min_element(arr.begin(), arr.end());

        int res = 0;
        for (int i = -200; i <= 200; i++)
        {
            int curr = 0;
            for (auto a : arr)
            {
                curr += a;
                curr += i;
            }

            if (curr >= 0)
            {
                res = i;
                break;
            }
        }
        cout << max(res, 0LL) << endl;
    }
    return 0;
}
