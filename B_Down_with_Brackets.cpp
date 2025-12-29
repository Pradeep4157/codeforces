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

        string s;
        cin >> s;
        stack<char> st;
        int count = 0;
        for (auto a : s)
        {
            if (st.empty())
                count++;
            if (a == '(')
            {
                st.push(a);
            }
            else
                st.pop();
        }
        if (count >= 2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
