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
        int n, k;
        cin >> n >> k;
        int i = 0;
        string s;
        cin >> s;
        int res = 0;
        vector<bool> arr(n, 1);
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                for (int j = i; j < min(n, i + k + 1); j++)
                {
                    arr[j] = false;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i])
                res++;
        }
        cout << res << endl;
    }
    return 0;
}
