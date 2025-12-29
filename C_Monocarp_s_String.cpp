#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:



        instead of focusing on the middle segments we can instead focus on left and right segments where a && b must be equal

        for this we can have suffix of difference between a & b

        now for the current left side from where we start we get the current difference and for this we find the closest complement

        difference if there is some then the length is min ( res , j - i - 1)


        j is where the suffix ends , i is where our prefix ends so the between segments is what we delete


        if we dont get any then we return - 1

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
        int diff = 0;

        map<int, vector<int>> suffix;
        for (int i = n - 1; i >= 0; i--)
        {

            diff += (s[i] == 'a') ? -1 : 1;

            suffix[diff].push_back(i);
        }

        for (auto &a : suffix)
        {
            reverse(a.second.begin(), a.second.end());
        }
        suffix[0].push_back(n);
        diff = 0;
        int res = n;
        if (suffix.find(0) != suffix.end())
        {
            res = suffix[0][0];
        }
        for (int i = 0; i < n; i++)
        {
            diff += (s[i] == 'a') ? 1 : -1;
            int complement = diff;
            if (suffix.find(complement) == suffix.end())
                continue;
            vector<int> &current = suffix[complement];
            auto it = upper_bound(current.begin(), current.end(), i);
            if (it == current.end())
            {
                continue;
            }
            int index = *it;
            // cout << i << ":" << index - i - 1 << endl;
            res = min(res, index - i - 1);
        }
        if (res == n)
            cout << -1 << endl;
        else
            cout << res << endl;
    }
    return 0;
}
