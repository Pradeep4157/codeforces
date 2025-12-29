#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    he can only type substrings including k letters that have been given.

    classic example of 2 pointer where we will keep moving till we find a char which is not present in the k
    letters given, then ans+=(count)(count+1)/2


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < k; i++)
    {
        char curr;
        cin >> curr;
        mp[curr]++;
    }
    int left = 0, right = 0;
    int res = 0;
    while (right < n)
    {
        while (right < n && mp.find(s[right]) == mp.end())
        {
            right++;
        }
        if (right == n)
            break;
        left = right;
        while (right < n && mp.find(s[right]) != mp.end())
        {
            right++;
        }
        right--;
        int curr = (right - left + 1);
        res += (curr * (curr + 1)) / 2;
        right++;
    }
    cout << res << endl;
    return 0;
}
