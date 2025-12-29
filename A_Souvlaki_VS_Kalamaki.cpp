#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    he can rearrange before the start of the game..

    rearrange will be sorted..

    if odd indexes swap is changing order not win..
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
        sort(arr.begin(), arr.end());
        bool ok = 1;
        for (int i = 1; i < n - 1; i += 2)
        {
            if (arr[i] < arr[i + 1])
                ok = false;
        }
        cout << ((ok) ? "YES" : "NO") << endl;
    }

    return 0;
}
