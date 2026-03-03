#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/

int find(string &s)
{
    int n = s.size();
    int res = 1;
    int right = 1;
    while (right < n)
    {
        while (right < n && s[right] == s[right - 1])
            right++;
        if (right == n)
            break;
        res++;
        right++;
    }
    return res;
}
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
        int res = find(s);
        for (int i = 0; i < n; i++)
        {
            char last = s[n - 1];
            s.insert(s.begin(), last);
            s.pop_back();
            int curr = find(s);

            res = max(res, curr);
        }
        cout << res << endl;
    }
    return 0;
}
