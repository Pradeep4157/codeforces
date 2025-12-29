#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    so initially the field is empty for each i all the top element in the stack <= arr[i] we keep poping and after all this we push this arr[i]
    in the stack and the size of stack is the no . of alive members in the battle field.

*/
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
        stack<int> st;
        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top() <= arr[i])
            {
                st.pop();
            }
            st.push(arr[i]);
            res[i] = st.size();
        }
        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
