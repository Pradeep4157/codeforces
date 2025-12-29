#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so all 0 are free so all that sum a

    then

    either this is res else

    i pay c and take all 1..

*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        string s;
        cin >> s;
        int curr = 0;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                curr += arr[i];
        }
        res = curr;
        if (curr >= c)
        {
            curr -= c;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '1')
                {
                    curr += arr[i];
                }
            }
            res = max(res, curr);
        }
        cout << res << endl;
    }
    return 0;
}
