#include <bits/stdc++.h>
#define int long long
using namespace std;

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
        sort(arr.begin(), arr.end());

        int i = 0;
        while (i < n && arr[i] <= c)
            i++;
        i--;
        int mul = 0;
        int zerodone = 0;
        while (true)
        {
            int j = i;
            while (j >= 0)
            {
                int curr = arr[j] * pow(2, mul);
                if (curr <= c)
                    break;
                j--;
            }
            if (j < 0)
            {
                break;
            }
            // cout << j << endl;
            zerodone++;
            mul++;
            i = j - 1;
        }
        // cout << zerodone << endl;
        cout << n - zerodone << endl;
    }
    return 0;
}
