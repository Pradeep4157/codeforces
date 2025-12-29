#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> arr = {1, 2, 9, 10, 25, 4, 3, 8, 11, 24, 5, 6, 7, 12, 23, 16, 15, 14, 13, 22, 17, 18, 19, 20, 21};
    ll t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        x--;
        int index = x * 5 + y - 1;
        if (index)
            cout << arr[index] << endl;
    }
    return 0;
}
