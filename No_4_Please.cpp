#include <bits/stdc++.h>

#define int long long

using namespace std;

/*

        OBSERVATIONS:



         2 only once ..



         3 only once if 1 is not there.



         1 only 3 times ..







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

        map<int, int> mp;

        for (int i = 0; i < n; i++)

            cin >> arr[i];

        for (auto a : arr)

            mp[a]++;

        int res = 0;

        for (auto a : mp)

        {

            if (a.first == 2)

            {

                res += a.second - 1;
            }

            if (a.first == 1)

            {

                if (mp.find(3) == mp.end())

                {

                    // then we can have 3 ones..

                    continue;
                }

                else

                {

                    // we need to remove all ..

                    int first = a.second;
                    int second = mp[3];
                    res += min(first, second);
                    // either i remove all ones / threes..
                }
            }
        }

        cout << res << endl;
    }

    return 0;
}
