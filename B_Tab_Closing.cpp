#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

        a,b,m


        once a/m is below b then we

        if a/m is already lesser than

        b then we it wont change..

        else it will convert from

        a/m to b

        a is size..

        b is lower limit i guess.

        n is the number of tabs..


        so as the number of a / m

        decreases the tab size increases

        but if till the end they dont

        cross

        screen is of length a

        and if b is also == a

        then we go to the final tab

        and keep pressing X




*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, n;
        cin >> a >> b >> n;
        if (a == b)
        {
            cout << 1 << endl;
            continue;
        }
        int first = a / n;
        if (first >= b)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
    return 0;
}
