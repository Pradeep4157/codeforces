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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> ones;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 1)
                ones.push_back(i);
        }
        int i = 0;
        int res = 0;
        while (i < n)
        {
            while (i < n && arr[i] == 1)
                i++;
            if (i == n)
                break;
            int req = i + k;
            if (i + k > n)
            {
                break;
            }
            auto it = lower_bound(ones.begin(), ones.end(), i);
            if (it != ones.end())
            {
                int index = *it;
                if (index < req)
                {
                    i++;
                    continue;
                }
                res++;
                i = req + 1;
                continue;
            }
            else
            {
                res++;
                i = req + 1;
                continue;
            }
        }
        cout << res << endl;
    }
    return 0;
}
