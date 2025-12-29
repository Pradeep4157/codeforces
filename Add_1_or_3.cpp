#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    add 1 or 3..

    so n times i have to  add something..

    now i can bs on  amount of times i will add 1..

    if poss return true

    else if if number exceeds low inc..

    else high dec..


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        // if n 1's also exceed m then no..
        if (m < n)
        {
            cout << "NO" << endl;
            continue;
        }
        // now poss.

        int low = 0, high = n;
        bool ok = false;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int rem = n - mid;
            int tot = 3 * rem + mid;
            if (tot == m)
            {
                ok = 1;
                break;
            }
            else if (tot > m)
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        cout << ((ok) ? "YES" : "NO") << endl;
    }
    return 0;
}
