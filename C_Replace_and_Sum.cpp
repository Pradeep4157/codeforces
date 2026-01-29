#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so any ai can take best value on its right side..

    then the following queries are just prefix..




*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> arr(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
            cin >> b[i];
        vector<int> best(n);
        best[n - 1] = max(arr[n - 1], b[n - 1]);
        for (int i = n - 2; i >= 0; i--)
        {
            best[i] = max({arr[i], b[i], best[i + 1]});
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = best[i];
        }
        int sum = 0;
        vector<int> prefix(n);
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            prefix[i] = sum;
        }
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int curr = prefix[r];
            if (l)
                curr -= prefix[l - 1];
            cout << curr << " ";
        }
        cout << endl;
    }
    return 0;
}
