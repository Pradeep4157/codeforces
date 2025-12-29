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
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        unordered_set<int> st;
        for (auto a : arr)
        {
            st.insert(a);
        }
        if (st.size() == 1)
        {
            cout << "No" << endl;
            continue;
        }
        else
        {
            int nonzeroindex = *max_element(arr.begin(), arr.end());
            
            cout << "Yes" << endl;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] != nonzeroindex)
                    cout << 1 << " ";
                else
                    cout << 2 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
