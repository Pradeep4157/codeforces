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
            cin >> arr[i];
        vector<vector<int>> bp(n, vector<int>(32, 0));
        int first = arr[0];
        int z = 31;
        while (z >= 0 && first >= 0)
        {
            if (first & 1)
            {
                bp[0][z]++;
            }
            z--;
            first >>= 1;
        }
        for (int i = 1; i < n; i++)
        {
            int curr = 31;
            int number = arr[i];
            while (curr >= 0)
            {
                bp[i][curr] += bp[i - 1][curr];
                if (number & 1)
                    bp[i][curr]++;
                number >>= 1;
                curr--;
            }
        }
        int q;
        cin >> q;
        while (q--)
        {
            int left, k;
            cin >> left >> k;
            left--;
            int curr = left;
            int right = n - 1;
            int maxi = curr;
            if (arr[left] < k)
            {
                cout << -1 << " ";
                continue;
            }
            while (left <= right)
            {
                int mid = (left + right) / 2;
                int amount = mid - curr + 1;
                int val = 0;
                int mul = 1;
                bool ok = false;
                for (int i = 0; i < 32; i++)
                {
                    int curramount = bp[mid][i];
                    if (curr > 0)
                        curramount -= bp[curr - 1][i];
                    if (curramount == amount)
                    {
                        val |= (1 << (31 - i));
                    }
                }

                if (val >= k)
                {
                    left = mid + 1;
                    maxi = mid;
                }
                else
                    right = mid - 1;
            }
            cout << maxi + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}