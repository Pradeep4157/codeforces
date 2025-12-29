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
        int n, m;
        cin >> n >> m;
        vector<int> a(n - 1), b(n);
        for (int i = 0; i < n - 1; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        a.push_back(1);
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0, j = 0;
        int count = 0;
        while (i < n && j < n)
        {
            if (a[i] < b[j])
            {
                count++;
                i++;
            }
            j++;
        }
        cout << n - count << endl;
    }
    return 0;
}
