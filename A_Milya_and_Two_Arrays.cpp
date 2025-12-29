#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        unordered_set<int> st;
        vector<bool> visa(n), visb(n);
        bool possible = 0;
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++)
            {
                int ele1 = a[i];
                int ele2 = b[j];
                if (visa[i] || visb[j])
                    continue;
                int sum = ele1 + ele2;
                if (st.count(sum))
                    continue;
                st.insert(sum);
                visa[i] = 1;
                visb[j] = 1;
                if (st.size() >= 3)
                {
                    possible = 1;
                    break;
                }
            }
        }

        if (possible)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
