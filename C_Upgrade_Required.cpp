#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    after every operation the array size decreases , so
    now we can keep collecting the freq of every char that got  deleted from
    left till the current number and all this will take at max O(N)

    if the current right is <= left then nothing gets updated ,

    else we move right till till left and update all the freq 's to currval

*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        mp[i] = 1;
    }
    int left = 1;
    while (q--)
    {
        int right, currval;
        cin >> right >> currval;
        if (right < left)
        {
            cout << 0 << endl;
        }
        else
        {
            int updates = 0;
            while (right >= left)
            {
                updates += mp[left];
                left++;
            }

            if (currval > right)
                mp[currval] += updates;
            else
                mp[currval] = updates;
            cout << updates << endl;
        }
    }

    return 0;
}
