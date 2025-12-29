#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so perm from 0..2^n-1

    is given

    s(p) is pop count of sum of 0...2^n - 1

    for each & till i..

    one of the solutions is ..

    2^n at the front

    the last index's pop count is def 0..

    because there's a zero..

    one of the soln can be

    11111,011111,001111,0001111..,0000111...,this is the general pattern..

    now for each of this we will try to find all the numbers

    that have this mask set and add all of these to arr in sorted order..

    and continue..




*/

int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
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
        set<int> st;
        int n;
        cin >> n;
        for (int i = 0; i < (binpow(2, n)); i++)
        {
            st.insert(i);
        }
        int curr = binpow(2, n) - 1;

        int bit = 31;
        for (int i = 31; i >= 0; i--)
        {
            if (curr & (1 << i))
            {
                bit = i;
                break;
            }
        }

        vector<int> arr;
        while (true)
        {

            int curr_mask = curr;

            set<int> st1;
            for (auto a : st)
            {
                if ((a & curr) == curr)
                {
                    // then in curr is submask of a..
                    st1.insert(a);
                }
            }
            // now we add all these numbers in the final array..
            for (auto a : st1)
            {
                st.erase(a);
                arr.push_back(a);
            }
            curr ^= (1 << bit);
            bit--;

            // just break at the end ..
            if (bit < -1)
                break;
        }

        for (auto a : arr)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
