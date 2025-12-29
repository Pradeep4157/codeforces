#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
        IMPOSSIBLE CASE:
            MAX SUBARRAY WHERE ALL ELEMENTS ARE 1:
                IF THE LENGTH>=K:
                    IMPOSSIBLE
            ELSE:
                FILL THESE SUBARRAYS FIRST FROM 1 TILL WHATEVER WE GO:
                AND REMAINING WITH REMAINING NUMBERS;



*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<pair<int, int>> ones;
        int i = 0;
        int maxi = -1;
        while (i < n)
        {
            while (i < n && s[i] == '0')
                i++;
            if (i >= n)
                break;
            int j = i;
            while (j < n && s[j] == '1')
                j++;
            j--;
            ones.push_back({i, j});
            maxi = max(maxi, j - i + 1);
            i = j + 1;
        }
        if (maxi >= k)
        {
            cout << "NO" << endl;
            continue;
        }
        vector<int> res(n, -1);
        int curr = 1;
        for (auto a : ones)
        {

            int left = a.first;
            int right = a.second;

            for (int j = left; j <= right; j++)
            {
                res[j] = curr;
                curr++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (res[i] == -1)
            {
                res[i] = curr;
                curr++;
            }
        }
        cout << "YES" << endl;
        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }

    return 0;
}
