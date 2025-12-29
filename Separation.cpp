#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    we need to make x not separated..

    so either one of the adj should be == x

    so we need >=half of the ele == x

    or either both of them are lesser than x or greater than x ..

    so we will keep these cnt at odd indexes ..

    we will cover cnt*2+1 indexes, for remaining..

    they need to be in pair..

    i need only 1 element  == x to cover  the gap of < and >




*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        int cnt = 0;
        int lesser = 0, greater = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] == x)
                cnt++;
            if (arr[i] < x)
                lesser++;
            else if (arr[i] > x)
                greater++;
        }
        if (cnt == 0)
        {
            // there is going to be a gap unless all are < /  >

            if (lesser == n || greater == n)
            {
                cout << "Yes" << endl;
            }
            else
                cout << "No" << endl;
        }
        else
            cout << "Yes" << endl;
    }
    return 0;
}
