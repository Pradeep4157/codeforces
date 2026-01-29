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
        int n;
        cin >> n;
        vector<int> arr(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        sort(arr.begin(), arr.end());
        vector<int> suffix(n, 0), prefix(n, 0);
        int sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            sum++;
            suffix[i] = sum;
        }
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += b[i];
            prefix[i] = sum;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int x = arr[i];
            int swords = suffix[i];
            if (prefix[0] > swords)
            {
                break;
            }
            int left = 0, right = n - 1;
            int res = left;
            while (left <= right)
            {
                int mid = (left + right) / 2;
                int monsters = prefix[mid];
                if (monsters <= swords)
                {

                    res = mid;
                    left = mid + 1;
                }
                else
                    right = mid - 1;
            }

            ans = max(ans, x * (res + 1));
        }
        cout << ans << endl;
    }
    return 0;
}
