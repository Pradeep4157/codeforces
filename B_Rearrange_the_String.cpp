#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {

        string s;
        cin >> s;
        int n = s.size();
        map<char, int> mp;

        for (auto a : s)
        {
            mp[a]++;
        }
        int maxi = 0;
        for (auto a : mp)
        {
            maxi = max(maxi, a.second);
        }
        if (maxi > (n + 1) / 2)
        {
            cout << -1 << endl;
            continue;
        }
        string res;
        vector<pair<char, int>> arr;
        for (auto a : mp)
        {
            arr.push_back({a.first, a.second});
        }
        sort(arr.begin(), arr.end());
        for (auto a : arr)
        {
            char curr = a.first;
            int freq = a.second;
            while (freq)
            {
                freq--;
                res += curr;
            }
        }
        // cout << res << endl;
        if (maxi > (n / 2))
        {
            char maxchar;
            for (auto a : arr)
            {
                if (a.second == maxi)
                {
                    maxchar = a.first;
                    break;
                }
            }
            for (int i = 0; i < res.size(); i++)
            {
                if (res[i] == maxchar)
                    swap(res[i], res[0]);
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (res[i] == res[i + 1])
            {
                for (int j = i + 2; j < n; j++)
                {
                    if (res[j] != res[i])
                    {
                        swap(res[i + 1], res[j]);
                        break;
                    }
                }
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (res[i] == res[i + 1])
            {
                int j = i - 1;
                while (j >= 0)
                {
                    if (res[j] != res[i] && (j == 0 || res[j - 1] != res[i]))
                    {
                        swap(res[j], res[i]);
                        break;
                    }
                    j--;
                }
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (res[i] == res[i + 1])
            {
                for (int j = i + 2; j < n; j++)
                {
                    if (res[j] != res[i])
                    {
                        swap(res[i + 1], res[j]);
                        break;
                    }
                }
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (res[i] == res[i + 1])
            {
                int j = i - 1;
                while (j >= 0)
                {
                    if (res[j] != res[i] && (j == 0 || res[j - 1] != res[i]))
                    {
                        swap(res[j], res[i]);
                        break;
                    }
                    j--;
                }
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (res[i] == res[i + 1])
            {
                for (int j = i + 2; j < n; j++)
                {
                    if (res[j] != res[i])
                    {
                        swap(res[i + 1], res[j]);
                        break;
                    }
                }
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (res[i] == res[i + 1])
            {
                int j = i - 1;
                while (j >= 0)
                {
                    if (res[j] != res[i] && (j == 0 || res[j - 1] != res[i]))
                    {
                        swap(res[j], res[i]);
                        break;
                    }
                    j--;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
