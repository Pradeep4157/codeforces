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
        vector<bool> used(n + 4, false);
        bool ok = false;
        for (int i = 0; i < n; i++)
        {
            while (used[i])
                i++;
            if (i == n)
                break;
            ok = 1;
            used[i] = 1;
            int need = i % 4;
            need = 3 - need;
            int next = -1;

            for (int j = need; j < n; j += 4)
            {
                if (!used[j])
                {
                    next = j;
                    break;
                }
            }
            // cout << i << ":" << need << endl;
            if (next == -1)
            {
                break;
            }
            else
            {
                ok = 0;
                used[next] = 1;
            }
        }
        if (ok)
        {
            cout << "Alice" << endl;
        }
        else
            cout << "Bob" << endl;
    }
    return 0;
}
