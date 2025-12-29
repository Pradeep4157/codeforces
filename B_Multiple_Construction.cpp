#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


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
        vector<int> arr(2 * n, 0);

        int val = n;
        for (int i = 0; i < n; i++)
        {
            arr[i] = val;
            val--;
        }
        arr[n] = n;

        val++;
        for (int i = n + 1; i < 2 * n; i++)
        {
            arr[i] = val;
            val++;
        }
        for (auto a : arr)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
