#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l, r;
    cin >> n >> l >> r;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    int res = 0;
    for (auto a : arr)
    {
        int first = a.first;
        int second = a.second;
        if (first <= l && second >= r)
        {
            res++;
        }
    }
    cout << res << endl;

    return 0;
}
