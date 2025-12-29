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
        int n;
        cin >> n;
        vector<int> arr(n);
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (!st.count(arr[i]))
            {
                st.insert(arr[i]);
            }
        }
        cout << st.size() << endl;
    }
    return 0;
}
