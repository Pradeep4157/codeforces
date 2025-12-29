#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
int first(string s, vector<int> &mp)
{
    // EVEN INDEX A AND ODD INDEXES B
    int n = s.size();
    int index = 0;
    int res = 0;
    for (int i = 0; i < n; i += 2)
    {
        if (i == mp[index])
        {
            index++;
            continue;
        }

        int curr = abs(i - mp[index]);
        // cout << i << ":" << mp[index] << endl;
        res += curr;
        index++;
    }
    return res;
}
int second(string s, vector<int> &mp)
{
    int n = s.size();
    int index = 0;
    int res = 0;
    for (int i = 1; i < n; i += 2)
    {
        if (i == mp[index])
        {
            index++;
            continue;
        }

        int curr = abs(i - mp[index]);
        // cout << i << ":" << mp[index] << endl;
        res += curr;
        index++;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    n *= 2;
    string s;
    cin >> s;

    vector<int> mp;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'B')
        {
            mp.push_back(i);
        }
    }

    int res1 = first(s, mp);
    int res2 = second(s, mp);
    cout << min(res1, res2) << endl;
    return 0;
}
