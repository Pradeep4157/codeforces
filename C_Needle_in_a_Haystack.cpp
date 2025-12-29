#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    there are some req ..

    and remaining will be used to make

    string lexi smallest.

    for a char in t..

    i will use all the chars < curr_char

    which are not used in t..

    then i will use t..



*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        string t, s;
        cin >> t >> s;
        vector<int> need(26, 0), have(26, 0);
        for (auto a : t)
        {
            need[a - 'a']++;
        }
        for (auto a : s)
        {
            have[a - 'a']++;
        }
        // now  we will use all chars as much as we want...

        string res;
        bool imp = false;
        for (auto a : t)
        {
            int index = a - 'a';

            for (int i = 0; i < index; i++)
            {
                int req = need[i];
                int curr_have = have[i];

                if (curr_have < req)
                {
                    imp = 1;
                    break;
                }
                int diff = curr_have - req;
                have[i] -= diff;
                while (diff > 0)
                {
                    res += (i + 'a');
                    diff--;
                }
            }
            if (have[index] < need[index])
                imp = 1;
            res += (a);
            have[index]--;
            need[index]--;
        }
        if (imp == 1)
        {
            cout << "Impossible" << endl;
            continue;
        }
        for (int i = 0; i < have.size(); i++)
        {
            while (have[i] > 0)
            {
                have[i]--;
                res += (i + 'a');
            }
        }
        cout << res << endl;
    }
    return 0;
}
