#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

        we need to minimize s + ai  = 2s

        so

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
        sort(arr.rbegin(), arr.rend());
        if (n >= 2)
            swap(arr[n - 1], arr[1]);
        for (auto a : arr)
            cout << a << ' ';
        cout << endl;
    }
    return 0;
}
