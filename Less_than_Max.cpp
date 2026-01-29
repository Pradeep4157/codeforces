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
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 1)
                continue;
            int curr = arr[i];

            int len = 1;
            set<int> mp;
            mp.insert(arr[i]);
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] == 1 || mp.count(arr[j] - 1))
                {
                    len++;
                    mp.insert(arr[j]);
                }
            }

            res = max(res, len);
        }
        cout << res << endl;
    }
    return 0;
}
