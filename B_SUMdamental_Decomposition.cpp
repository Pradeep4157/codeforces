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
        int n, x;
        cin >> n >> x;
        if (n == 1 && x == 0)
        {
            cout << -1 << endl;
            continue;
        }
        int dupx = x;
        int res = 0;
        int curr = 1;
        int ele = 0;
        vector<int> doubles;
        while (x > 0)
        {
            if (x & 1)
            {
                res += (curr);
                ele++;
            }
            else
            {
                doubles.push_back(curr);
            }

            curr <<= 1;

            x >>= 1;
        }
        if (ele == n)
            cout << res << endl;
        else if (ele > n)
        {

            cout << res << endl;
        }
        else
        {
            int bit = 1;
            while (ele < n)
            {
                if (bit <= dupx)
                {
                    // if this bit was set
                    if (bit & dupx)
                    {
                        int left = n - 1;
                        int other = n - ele;
                        if (other & 1)
                            other++;
                        left = min(left, other);
                        if (left & 1)
                        {
                            left--;
                        }
                        res += (left * bit);
                        ele += left;
                    }
                    else
                    {
                        int left = n;
                        if (n & 1)
                            left--;
                        int other = n - ele;
                        if (other & 1)
                            other++;
                        left = min(left, other);
                        if (left & 1)
                            left--;
                        res += (left * bit);
                        ele += left;
                    }
                }
                else
                {
                    if (n & 1)
                    {
                        int left = n - 1;
                        int other = n - ele;
                        if (other & 1)
                            other++;
                        left = min(left, other);
                        res += (left * bit);
                        ele += left;
                    }
                    else
                    {
                        int left = n;
                        int other = n - ele;
                        if (other & 1)
                            other++;
                        left = min(left, other);
                        res += (left * bit);
                        ele += left;
                    }
                }
                bit <<= 1;
            }
            cout << res << endl;
        }
    }
    return 0;
}
