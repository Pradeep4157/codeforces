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
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            if (ele == -1)
                continue;
            st.insert(ele);
        }
        if (st.size() > 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            if (st.empty())
            {
                cout << "YES" << endl;
                continue;
            }
            if (*st.begin() == 0)
            {
                cout << "NO" << endl;
            }
            else
                cout << "YES" << endl;
        }
    }
    return 0;
}
