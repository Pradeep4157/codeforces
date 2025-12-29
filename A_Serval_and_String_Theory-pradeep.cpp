#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int half = n / 2;
        int count = 0;
        bool possible = false;
        if (n == 1)
        {
            cout << "NO" << endl;
            continue;
        }
        unordered_map<char, int> mp;
        for (auto a : s)
            mp[a]++;
        if (k == 0)
        {
            if (mp.size() == 1)
            {
                cout << "NO" << endl;
                continue;
            }
            string rev = s;
            reverse(rev.begin(), rev.end());
            for (int i = 0; i < half; i++)
            {
                if (rev[i] == s[i])
                    continue;
                else
                {
                    if (rev[i] > s[i])
                    {
                        possible = true;
                    }
                    break;
                }
            }
            if (possible == false)
            {

                cout << "NO" << endl;
            }
            else
                cout << "YES" << endl;
            continue;
        }
        if (mp.