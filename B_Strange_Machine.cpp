#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    every query starts from machine 1 only so we can bf becuase n<=20

    now ai might be much higher so

    we need amount a number decreases in a single operation

    so for every query we can do one pass through  array if the number

    decreases to 0 mid way good

    so one thing can be noticed that if there is b in the array

    we can bf because at every move the number decreases by 1/2

    so it will take at max log n else we do the prefix and


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        bool found = false;
        for (auto a : s)
        {
            if (a == 'B')
            {
                found = 1;
                break;
            }
        }
        if (found == false)
        {
            // then we can precompute all the res
            int perdecrease = n; // every iteration it will dec by n
            while (q--)
            {
                int curr;
                cin >> curr;
                int full = curr / perdecrease;
                int rem = curr % n;
                cout << (full * n) + rem << endl;
            }
        }
        else
        {
            // here we can bf
            while (q--)
            {
                int curr;
                cin >> curr;
                int i = 0;
                int res = 0;
                while (curr)
                {
                    if (s[i] == 'B')
                        curr /= 2;
                    else
                        curr--;
                    res++;
                    if (curr == 0)
                        break;
                    i++;
                    i %= n;
                }
                cout << res << endl;
            }
        }
    }
    return 0;
}
