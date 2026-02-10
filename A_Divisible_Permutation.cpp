#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

        12
        23
        34

        13
        24

        2314

        32415

        342516

        213


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
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(i + 1);
        }
        arr[n - 1] = n;
        st.erase(n);
        for (int i = n - 2; i >= 0; i--)
        {
            int curr_number = arr[i + 1] - (i + 1);
            int curr_number_2 = arr[i + 1] + (i + 1);
            if (st.count(curr_number))
            {
                arr[i] = curr_number;
                st.erase(curr_number);
            }
            else
            {
                st.erase(curr_number_2);
                arr[i] = curr_number_2;
            }
        }
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
