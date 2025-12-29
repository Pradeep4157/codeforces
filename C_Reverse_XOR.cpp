#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so the end zeroes can only be

    balanced not any else

    if it is a power of 2 then not possible

    because the set bits should balance themselves


*/
int findlastzeroes(int n)
{
    int res = 0;
    while (n)
    {
        if (n & 1)
            break;
        res++;
        n >>= 1;
    }

    return res;
}
int finddigits(int n)
{
    int res = 0;
    while (n)
    {
        res++;
        n >>= 1;
    }
    return res;
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
        if ((n > 0) && ((n & (n - 1)) == 0))
        {
            cout << "NO" << endl;
            continue;
        }

        int lastzeroes = findlastzeroes(n);
        int digits = finddigits(n);
        vector<int> res(lastzeroes + digits);
        for (int i = 0; i < lastzeroes; i++)
        {
            res[i] = 1;
        }
        bool set = 1;
        vector<int> b(res.size(), -1);
        for (int i = lastzeroes; i < res.size(); i++)
        {
            if (n & (1 << i))
            {
                // this maybe 0 or 1
                if (set)
                {
                    set = 0;
                    res[i] = 1;
                    b[i] = 0;
                }
                else
                {
                    res[i] = 0;
                    set = 1;
                    b[i] = 1;
                }
            }
            else
            {
                res[i] = 1;
                b[i] = 1;
            }
        }

        int index = res.size() - 1;
        for (int i = 0; i < res.size(); i++)
        {
            if (b[i] == -1)
                b[i] = 1;
        }
        bool ok = 1;
        index = res.size() - 1;
        for (int i = 0; i < n; i++)
        {
            if (res[i] != b[index])
            {
                ok = false;
                break;
            }
            else
            {
                index--;
            }
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
