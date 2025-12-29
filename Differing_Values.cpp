#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    binary string is given..

    si!=si+k...

    0...k-11..0

    if k is 1..

    every adj should be diff.

    if k == 2 ..

    two same can be there..

    if k == 3..

    three same will be there..

    req is

    1 ) subarray size is k,,


    it doesnt matter where i place them at the end there should

    be some 1,0 to satisfy..

    i think that is the number of pos where i + k is valid..


    every k distant indexes are only dependent on each other nothing

    else..

    now at these arrays only alternate need to be diff..

    so..

    if even then both will subtract n / 2..



*/

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int zero = 0, one = 0;
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        for (auto a : s)
        {
            if (a == '0')
                zero++;
            else
                one++;
        }
        map<int, vector<int>> mp;
        vector<int> arr(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == -1)
            {
                // first time..
                for (int j = i; j < n; j += k)
                {
                    arr[j] = i;
                    mp[i].push_back(j);
                }
            }
        }
        // now try placing..
        bool ok = 1;
        for (auto a : mp)
        {
            int size = a.second.size();
            int first = size / 2;
            int second = size - first;

            if (first == second)
            {
                // we need equal  zero and one..
                if (zero < first || one < first)
                {

                    ok = false;
                    break;
                }
                // now we are safe..
                zero -= first;
                one -= first;
            }
            else
            {
                // one will contri more..
                if (zero == one)
                {
                    // anyone can..
                    zero -= first;
                    one -= second;
                    if (zero < 0 || one < 0)
                    {
                        ok = false;
                        break;
                    }
                }
                else
                {
                    // one can give more..
                    if (one > zero)
                    {
                        int maxi = max(first, second);
                        int mini = min(first, second);
                        one -= maxi;
                        zero -= mini;
                        if (one < 0 || zero < 0)
                        {
                            ok = false;
                            break;
                        }
                    }
                    else
                    {
                        int maxi = max(first, second);
                        int mini = min(first, second);
                        one -= mini;
                        zero -= maxi;
                        if (one < 0 || zero < 0)
                        {
                            ok = false;
                            break;
                        }
                    }
                }
            }
        }
        if (ok)
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
    return 0;
}
