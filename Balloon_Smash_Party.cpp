#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    ith person is hit with i

    balloons

    if that arr[i] > i then it will

    hit

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
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> res(n);
        int attackers = 0;
        for (int i = 0; i < n; i++)
        {
            // already attacked ..
            // now if alive will attack all right..
            res[i] = attackers;
            res[i] = min(res[i], arr[i]);
            if (arr[i] > res[i])
                attackers++;
        }
        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
