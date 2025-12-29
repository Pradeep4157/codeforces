#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    a of 2n numbers..

    f(b) dist ele with odd freq in b..

    a into p,q of size n.

    f(p) + f(q) should be max..

    so odd in both should be max..

    if a num is odd..

    then one will be even , other will be odd.

    is maximizing one enough ?

    no

    i can use other array better..

    if it is even..

    1 n - 1
    odd odd

    odd 1 n - 1

    odd even..

    so maybe its just that..

    i am trying to push 1 and rem in other

    why though ?

    our first priority should be to equally space even numbers then odd

    because they give  res += 2

    and odd only 1





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
        n *= 2;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        map<int, int> mp;
        n /= 2;

        int first, second;
        for (auto a : arr)
            mp[a]++;
        // first try for even numbers..

        bool found = false;

        for (auto a : mp)
        {
            if (a.second & 1)
                found = 1; // we dont care nigga..
        }
        int res = 0;
        if (found)
        {

            for (auto a : mp)
            {
                if (a.second & 1)
                    res++;
                else
                    res += 2;
            }
        }
        else
        {
            
        }
        cout << res << endl;
    }
    return 0;
}
