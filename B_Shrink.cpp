#include <bits/stdc++.h>
#define int long long
using namespace std;

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
        arr[0] = 1;

        int number = 1;
        int last = n;
        int i = 1;
        while (i < n)
        {
            arr[i] = last;
            last--;
            i++;
        }
        for (auto a : arr)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
