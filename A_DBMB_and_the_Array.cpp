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
        int n, s, x;
        cin >> n >> s >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int sum = accumulate(arr.begin(), arr.end(), 0LL);
        if (sum > s)
        {
            cout << "NO" << endl;
        }
        else
        {
            int rem = s - sum;
            if ((rem % x) == 0)
            {
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
