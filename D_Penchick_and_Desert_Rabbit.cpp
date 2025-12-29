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
        vector<int> prefix(n), suffix(n);
        for (int i = 0; i < n; i++)
        {
            prefix[i] = arr[i];
            if (i)
                prefix[i] = max(prefix[i], prefix[i - 1]);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            suffix[i] = arr[i];
            if (i < n - 1)
                suffix[i] = min(suffix[i], suffix[i + 1]);
        }
        vector<int> res(n);
        res[n - 1] = prefix[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            res[i] = prefix[i];
            if (prefix[i] > suffix[i + 1])
                res[i] = max(res[i], res[i + 1]);
        }
        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
