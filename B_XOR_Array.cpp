#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    n,l,r ..

    array should be gen of pos ..

    xor of l..r should be 0..

    all other xorrs shouldnt be 0..

    for xorr to be 0..

    bits from l .. r - 1 will be something

    and last will be same..

    on l..r xorr should be 0..



    1 2 1 4 1 2 4 8 1 2 1 4





*/
bool has_all(long long x)
{
    return x > 0 && ((x & (x + 1)) == 0);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> arr(n, 0);
        int ele = 8;
        int xorr = 0;
        l--;
        r--;
        bool first = true;
        vector<int> values = {1, 2, 1, 4};
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == r)
                continue;

            if (index == values.size() - 1 && first == false)
            {

                ele <<= 1;
                values.push_back(ele);
                index = 0;
            }
            else if (index == values.size() - 1 && first == 1)
            {

                ele <<= 1;
                values.push_back(ele);
                first = false;
            }
            arr[i] = values[index++];
        }
        for (int i = l; i < r; i++)
        {
            xorr ^= arr[i];
        }
        arr[r] = xorr;
        cout << "this is the xorr : " << xorr << endl;
        for (int i = 0; i < n; i++)
        {
            int curr_xorr = 0;
            // cout << i + 1 << "->";
            for (int j = i; j < n; j++)
            {
                curr_xorr ^= arr[j];
                if (curr_xorr == 0)
                {
                    cout << "THIS IS WHERE I FOND : " << i << ":" << j << endl;
                }
                // cout << curr_xorr << " ";
            }
            cout << endl;
        }

        for (auto a : arr)
            cout << a << " ";
        cout << endl;
    }

    return 0;
}
