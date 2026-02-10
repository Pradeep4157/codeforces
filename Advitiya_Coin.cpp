#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    we can buy in past and sell in future

    or buy in future and sell in past..

    so we select elements whos diff > k..

    and they should be exclusive..


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        set<int> st;
        int res = 0;
        for (int right = 0; right < n; right++)
        {
            // if i want to include...
            // search for right + k
            bool found = false;
            if (!st.empty())
            {
                int min_req = arr[right] + k;
                auto it = st.upper_bound(min_req);
                if (it != st.end())
                {
                    found = 1;
                }
                int first_ele = *st.begin();
                if (abs(first_ele - arr[right]) > k)
                {
                    found = 1;
                }
            }
            if (found == 1)
            {
                st.clear();
                res++;
            }
            else
                st.insert(arr[right]);
        }

        cout << res << endl;
    }
    return 0;
}
