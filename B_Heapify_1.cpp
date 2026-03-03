#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


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
        {
            cin >> arr[i];
        }
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        bool ok = 1;
        vector<bool> vis(n, false);
        set<int> st;

        for (int i = 1; i <= n; i++)
        {
            st.insert(i);
        }
        map<int, int> mp;

        while (!st.empty())
        {
            auto F = st.begin();
            int first = *F;
            st.erase(F);
            int FIRST = first;

            while (first <= n)
            {

                mp[arr[first - 1]]++;
                first *= 2;
            }

            while (FIRST <= n)
            {
                st.erase(FIRST);
                if (mp.find(temp[FIRST - 1]) == mp.end() || (mp[temp[FIRST - 1]] == 0))
                {

                    ok = false;
                    break;
                }
                else
                {
                    mp[temp[FIRST - 1]]--;
                }
                FIRST *= 2;
            }
            if (ok == false)
                break;
        }
        cout << ((ok) ? "YES" : "NO") << endl;
    }
    return 0;
}
