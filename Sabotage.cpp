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
        int n, x, k;
        cin >> n >> x >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int i = 0;
        int finalscore = x + (100 * k);
        if (k == 0)
            finalscore = x;
        while (i < n && arr[i] <= finalscore)
            i++;
        while (i < n && k)
        {
            k--;
            i++;
        }
        cout << (n - i + 1) << endl;
    }
    return 0;
}
