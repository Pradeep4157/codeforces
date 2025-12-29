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
        vector<char> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        bool possible = 1;
        int even = 0, odd = 0;
        for (int i = 0; i < n; i++)
        {
            if (b[i] == '0')
            {
                if (i % 2 == 0)
                    even++;
                else
                    odd++;
            }
        }

        for (int i = 0; i < n; i++)
        {

            if (a[i] == '1')
            {
                if (i % 2)
                {
                    if (even == 0)
                    {
                        possible = false;
                        break;
                    }
                    else
                    {
                        even--;
                    }
                }
                else
                {
                    if (odd == 0)
                    {
                        possible = false;
                        break;
                    }
                    odd--;
                }
            }
        }
        if (possible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
