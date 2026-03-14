#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    at the end we are taking AND of whole array..

    so we need to make the MSB better of all the numbers..

    check how much this bit req..

    if enough k then inc

    else continue..


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
        for (int bit = 30; bit >= 0; bit--)
        {
            int req = n;
            for (int i = 0; i < n; i++)
            {

                if (arr[i] & (1 << bit))
                {
                    req--;
                }
            }
            if (req <= k)
            {
                k -= req;
                res |= (1 << bit);
            }
        }
        cout << res << endl;
    }
    return 0;
}
