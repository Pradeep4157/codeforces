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
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        int low = n + 1, high = n + 1;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (low > high)
                swap(low, high);
            if (arr[i] <= low)
                low = arr[i];
            else if (arr[i] > high)
            {
                low = arr[i];
                res++;
            }
            else
                high = arr[i];
        }
        cout << res << endl;
    }
    return 0;
}
