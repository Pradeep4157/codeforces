#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    from right take an ele remove everything on the right..

    left greatest ele..

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
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int curr = 0;
            int max_seen = arr[i];
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < max_seen)
                {
                    curr++;
                }

                else
                    max_seen = max(max_seen, arr[j]);
            }

            res = max(res, curr);
        }
        cout << res << endl;
    }
    return 0;
}
