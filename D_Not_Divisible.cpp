#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    SORT THE ARRAY
    CHECK ALL THE DIVISORS OF THIS NUMBER
    THEN THIS NUMBER CANT BE USED
    ELSE ADD THIS NUMBER TO ST

    THIS STILL HAS A PROBLEM:
        WHEN A NUMBER OCCURS FIRST TIME, IF THE SAME
        NUMBER HAS OCCURED MORE THAN ONCE THEN WE CANT
        THIS NUMBER SINCE THEY DIVIDE THIS
        NUMBER

*/
vector<vector<int>> divisors;
void find(int n)
{
    for (int i = 1; i <= n; i++)
        divisors[i].push_back(1);
    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            divisors[j].push_back(i);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    divisors.resize(1e6 + 10);
    find((int)(1e6 + 1));
    sort(arr.begin(), arr.end());
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    int res = 0;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        // IT SHOULD BE PRESENT ONLY ONCE IN THE ARRAY
        if (mp[arr[i]] == 1)
        {
            bool ok = 1;
            for (auto a : divisors[arr[i]])
            {
                if (st.count(a))
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
                res++;
        }
        st.insert(arr[i]);
    }
    cout << res << endl;

    return 0;
}
