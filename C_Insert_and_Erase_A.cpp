#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    if there is no a in both s and t then both should be

    same then yes else no

    now just see the diff and diff to the res..


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    string first, second;
    for (auto a : s)
    {
        if (a != 'A')
            first += a;
    }
    for (auto a : t)
    {
        if (a != 'A')
            second += a;
    }
    bool ok = 1;
    if (first.size() != second.size())
    {

        cout << -1 << endl;
        return 0;
    }
    int size = first.size();
    for (int i = 0; i < size; i++)
    {
        if (first[i] != second[i])
        {
            ok = false;
            break;
        }
    }
    if (ok == false)
    {

        cout << -1 << endl;
        return 0;
    }

    int res = 0;
    {
        int first = 0, second = 0;

        int n = s.size(), m = t.size();

        while (first < n && second < m)
        {
            int left1 = first, left2 = second;
            while (first < n && s[first] == 'A')
                first++;
            while (second < m && t[second] == 'A')
                second++;
            int size1 = first - left1;
            int size2 = second - left2;
            res += abs(size1 - size2);
            first++;
            second++;
        }
        if (first < n)
        {

            res += (n - first);
        }
        if (second < m)
        {

            res += (m - second);
        }
    }

    cout << res << endl;
    return 0;
}
