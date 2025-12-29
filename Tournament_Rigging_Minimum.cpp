#include <bits/stdc++.h>
#define int long long
using namespace std;

/*

    PROBLEM:

        n && w is given ..

        array of len 2^(n+1) - 1 should be created..

        first ele should be w ..

        ai = max ( a2i , a2i + 1 ) or min ..

        last 2^n should be permutation..

        indices where ai = max(a2i , a2i + 1 ) should be minimized..

        so try more of min ( a2i , a2i + 1)

        if an array could be created its not at all difficult .

        just create array of size (2^2n - 1 )

    OBSERVATIONS:





*/
int binpow(int a, int b)
{
    if (b == 0)
        return 1;
    else if (b & 1)
    {
        return a * binpow(a, b - 1);
    }
    else
    {

        int temp = binpow(a, b >> 1);
        return temp * temp;
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;
        int pow = (n + 1);
        int size = binpow(2, pow);
        size--;
        vector<int> arr(size, -1);
        int ele = binpow(2, n);
        int index = -1;
        for (int i = size - 1; i >= 0; i--)
        {
            if (ele == 0)
            {
                index = i;
                break;
            }
            ele--;
        }
        int z = 0;
        while (true)
        {
            if (z > index && z < size)
            {
                // we just fill this and get lost..
                arr[z] = w;
                break;
            }
            arr[z] = w;
            int j = z + 1;
            j *= 2;
            z = j;
        }
        ele = binpow(2, n);
        // now we will mark last 2^n ele as 11
        for (int i = size - 1; i >= 0; i--)
        {
            if (ele == 0)
                break;
            if (ele == w)
            {
                ele--;
            }
            if (arr[i] == -1)
                arr[i] = ele--;
        }
        for (int i = index; i >= 0; i--)
        {
            if (arr[i] != -1)
                continue;
            int j = i + 1;
            arr[i] = min(arr[2 * j - 1], arr[2 * j]);
        }

        for (auto a : arr)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
