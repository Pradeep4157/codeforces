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
        // the edge case is that if count(open bracket)!=count(close bracket) then we return -1
        int n;
        cin >> n;
        string s;
        cin >> s;
        int opencount = 0, closecount = 0;
        char prevstart = (s[0] == '(') ? ')' : '(';
        for (auto a : s)
        {
            if (a == '(')
                opencount++;
            else
                closecount++;
        }
        if (opencount != closecount)
        {
            cout << -1 << endl;
            continue;
        }
        vector<int> arr(n, -1);
        stack<char> st;
        bool twoused = 0;
        int color = 2;
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                if (prevstart != s[i])
                {
                    color = (color == 1) ? 2 : 1;
                    if (color == 2)
                    {
                        twoused = 1;
                    }
                    prevstart = s[i];
                    arr[i] = color;
                    st.push(s[i]);
                }
                else
                {
                    arr[i] = color;
                    st.push(s[i]);
                }
            }
            else
            {
                char top = st.top();
                if (top == s[i])
                {
                    arr[i] = color;
                    st.push(top);
                }
                else
                {
                    st.pop();
                    arr[i] = color;
                }
            }
        }
        if (twoused == 1)
        {
            cout << 2 << endl;
        }
        else
            cout << 1 << endl;
        for (auto a : arr)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
