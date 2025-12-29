#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so here we find all the bits of the numbers in the array and keep the count in an array and after that for every bit if after setting this bit

    if the number of xorrs is odd then we set else we dont

    also if we set then the total xorr < k

*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, K;
    cin >> n >> K;
    int k = (1 << K);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> bits(31, 0);
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        int j = 0;
        while (curr)
        {
            if (curr & 1)
            {
                bits[j]++;
            }
            j++;
            curr >>= 1;
        }
    }
    int res = 0;
    for (int i = 30; i >= 0; i--)
    {

        if (bits[i] & 1)
            continue; // i dont need to change because in the end res it will  be set
        else
        {
            int unset = n - bits[i];
            if (unset & 1)
            {
                // here it is beneficial to change

                int add = (1 << i);
                if (res + add < k)
                {
                    // then we will set this bit
                    res += add;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}
