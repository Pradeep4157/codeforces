#include <bits/stdc++.h>
#define int long long
using namespace std;

int_fast32_t main()
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
        int i = 0;
        int res = 1;
        while (i < arr.size())
        {
            int curr = arr[i];
            auto it = upper_bound(arr.begin(), arr.end(), curr + 1);
            if (it == arr.end())
            {
                break;
            }
            i = it - arr.begin();
            res++;
        }
        cout << res << endl;
    }
    return 0;
}
