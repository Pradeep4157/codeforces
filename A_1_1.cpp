#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
int make_zeroes(string s, int ones)
{
    int n = s.size();
    int i = 1;
    while (i < n - 1)
    {
        if (s[i - 1] == '1' && s[i + 1] == '1')
        {
            // i will make this a zero if its a one..
            if (s[i] == '1')
            {
                s[i] = '0';
                ones--;
            }
        }
        i++;
    }
    return ones;
}
int make_ones(string &s, int ones)
{
    int n = s.size();
    int i = 1;
    while (i < n - 1)
    {
        if (s[i - 1] == '1' && s[i + 1] == '1')
        {
            // i will make this a zero if its a one..
            if (s[i] == '0')
            {
                s[i] = '1';
                ones++;
            }
        }
        i++;
    }
    return ones;
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
        int zero = 0, ones = 0;
        for (auto a : s)
        {
            if (a == '1')
                ones++;
        }
        zero = ones;
        int max_ones = make_ones(s, ones);
        ones = 0;
        for (auto a : s)
        {
            if (a == '1')
                ones++;
        }

        int min_ones = make_zeroes(s, ones);

        cout << min_ones << " " << max_ones << endl;
    }
    return 0;
}
