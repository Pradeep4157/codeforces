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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        bool dec = false;
        bool ok = true;
        int minele = arr[0];
        bool inc = false;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
            {

                if (arr[i] >= 2 * minele)
                {

                    ok = false;
                    break;
                }
            }
            else if (arr[i] < arr[i - 1])
            {
                minele = min(minele, arr[i]);
                dec = true;
            }
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
