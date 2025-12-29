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
        string s;
        cin >> s;
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                res.push_back(i + 1);
            }
        }
        cout << res.size() << endl;
        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
