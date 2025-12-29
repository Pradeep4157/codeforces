#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so if 11 is already greater we dont

    do anything..

    else we try to make them equal


    in a single op..

    we can destroy how many cnt00

    we can destroy 2 ..

    000 - > 010

    01010

    00100

    so we keep subarrays and keep destroying

    odd indexes..




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
        int onecount = 0, zerocount = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '1' && s[i + 1] == '1')
                onecount++;
            else if (s[i] == '0' && s[i + 1] == '0')
                zerocount++;
        }
        if (onecount >= zerocount)
        {
            cout << 0 << endl;
        }
        else
        {
            // now we will get subarrays..
            vector<pair<int, int>> zerosub;
            int i = 0;
            while (i < n)
            {
                while (i < n && s[i] == '1')
                    i++;
                if (i == n)
                    break;
                int j = i;
                while (j < n && s[j] == s[i])
                    j++;
                j--;
                zerosub.push_back({i, j});
                i = j + 1;
            }
            int res = 0;
            for (auto a : zerosub)
            {
                int left = a.first;
                int right = a.second;
                bool found = false;
                for (int i = left + 1; i <= right; i += 2)
                {
                    zerocount -= 2;
                    res++;
                    if (zerocount <= onecount)
                    {
                        found = 1;

                        break;
                    }
                }
                if (found)
                    break;
            }

            cout << res << endl;
        }
    }
    return 0;
}
