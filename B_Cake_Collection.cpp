#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    GREEDY QUESTION:
        SORT THE ARRAY
        I=N-1=>0: SECOND*ARR[I]
        IF
*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int res = 0;
        sort(arr.begin(), arr.end());
        for (int i = n - 1; i >= 0; i--)
        {
            if (k == 0)
                break;
            res += (arr[i] * k);
            k--;
        }
        cout << res << endl;
    }
    return 0;
}
