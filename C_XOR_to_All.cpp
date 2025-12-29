#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> bitset(32);
    for (auto a : arr)
    {
        for (int i = 0; i < 32; i++)
        {
            if (a & (1 << i))
            {
                bitset[i]++;
            }
        }
    }
    int res = accumulate(arr.begin(), arr.end(), 0LL);
    for (auto a : arr)
    {
        int curr = 0;
        for (int i = 0; i < 32; i++)
        {
            if (a & (1 << i))
            {
                curr += (1 << i) * (n - bitset[i]);
            }
            else
                curr += (1 << i) * bitset[i];
        }
        res = max(res, curr);
    }
    cout << res << endl;
    return 0;
}
