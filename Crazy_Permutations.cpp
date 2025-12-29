#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    so a needs to be converted to b..

    we can do ai ++ or ai --

    but never ai == ai + 1

    they will intersect only when

    right one has to reach left

    or left has to reach right..




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
        vector<int> arr(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
            cin >> b[i];
        bool ok = 1;
        for (int i = 0; i < n - 1; i++)
        {
            // intersection..

            int first = arr[i];
            int second = arr[i + 1];
            int first2 = b[i];
            int second2 = b[i + 1];
            if (first < second && first2 < second2 || second < first && second2 < first2)
                continue;
            else
            {
                ok = false;
                break;
            }
        }
        cout << ((ok) ? "Yes" : "No") << endl;
    }
    return 0;
}
