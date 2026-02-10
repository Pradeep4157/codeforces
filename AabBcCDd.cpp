#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    max two

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
        vector<int> temp(26);
        for (auto a : s)
        {
            char curr = tolower(a);
            temp[curr - 'a']++;
        }
        vector<int> freq;
        for (auto a : temp)
        {
            freq.push_back(a);
        }
        sort(freq.rbegin(), freq.rend());
        int res = 0;
        for (int i = 0; i < 2; i++)
        {
            res += freq[i];
        }
        cout << res << endl;
    }
    return 0;
}
