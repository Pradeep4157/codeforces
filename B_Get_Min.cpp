#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    multiset<int> st;
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int number;
            cin >> number;
            st.insert(number);
        }
        else
        {
            if (st.empty())
                continue;
            int first = *st.begin();
            st.erase(st.begin());
            cout << first << endl;
        }
    }
    return 0;
}
