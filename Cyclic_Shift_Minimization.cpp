#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    if n is even there is 0 , else one position will be at its position

    g(p) is max count of places where i == p[i]

    i want to minimize this g(p)

    i.e., the permutation that i give , even though all the cyclic shifts are applied

    g(p) is minimum
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
        vector<int> arr(n);
        int curr = n;
        for (int i = 0; i < n; i++)
        {
            arr[i] = curr--;
        }
        for (auto a : arr)
            cout << a << ' ';
        cout << endl;
    }
    return 0;
}
