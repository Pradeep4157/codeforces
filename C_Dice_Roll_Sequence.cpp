#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    x,7- x shouldnt be adj.

    we can change the values..

    so if this is adj to i - 1 so either i change it to some value

    which one should i change..

    the one who is taking more..

    like the between ones..




*/
bool is_comp(int first, int second)
{
    return (first == 7 - second || (first == second));
}
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
        vector<pair<int, int>> subarrays;
        int left = 0;
        int right = 0;

        while (right < n)
        {
            while (right + 1 < n && is_comp(arr[right], arr[right + 1]))
            {
                right++;
            }
            subarrays.push_back({left, right});
            right++;
            left = right;
        }
        int res = 0;
        for (auto a : subarrays)
        {
            res += (a.second - a.first + 1) / 2;
        }
        cout << res << endl;
    }

    return 0;
}
