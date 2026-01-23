#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    i choose a point, then after sorting till here

    if next things are sorted and the min of them

    is > max till here then  it is valid..


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
        vector<int> res = arr;
        sort(res.begin(), res.end());
        bool sorted = 1;
        for (int i = 0; i < n; i++)
        {
            if (res[i] != arr[i])
            {
                sorted = false;
                break;
            }
        }
        if (sorted)
        {
            cout << 0 << endl;
            continue;
        }
        // now it is def unsorted..
        int ans = LLONG_MAX;

        for (int i = 0; i < n; i++)
        {
            if (res[i] != arr[i])
            {
                // then till here it is unsorted..
                // 1 more condition that suffix should be sorted..
                bool next_sorted = 1;
                for (int j = i + 1; j < n; j++)
                {
                    if (res[j] != arr[j])
                    {
                        next_sorted = false;
                        break;
                    }
                }

                if (next_sorted)
                {

                    ans = min(ans, arr[i]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
