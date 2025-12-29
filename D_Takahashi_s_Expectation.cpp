#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> prefix(501, 0), suffix(501, 0);
    for (int i = 0; i < n; i++)
    {
        int first, second, third;
        cin >> first >> second >> third;
        prefix[first] += second;
        suffix[first] += third;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        int i = 0;
        while (i < prefix.size())
        {
            x += prefix[i];
            i = max(i + 1, x + 1);
        }

        if (i == prefix.size())
        {
            cout << x << endl;
            continue;
        }
        while (i < suffix.size())
        {
            x -= suffix[i];
            i++;
        }
        cout << x << endl;
    }

    return 0;
}
