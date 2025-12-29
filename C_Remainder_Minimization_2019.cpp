#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

        I%2019*(J%2019)
        i*j SHOULD BE AS CLOSE TO 2019 AS POSSIBLE
        IF L IS ZERO ANS=0;
            O*ANYTHING=0
        ELSE FOR A L:
            R=2019/L:
            AND THIS R SHOULD BE IN THE WINDOW


        IF R*(R-1) IS LESSER THAN 2019:
            THEN ANS=L*(L+1)

        NOW {L,R}={0,2018}

*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int l, r;
    cin >> l >> r;
    if (r - l + 1 >= 2019)
    {
        cout << 0 << endl;
        return 0;
    }
    int res = INT_MAX;
    for (int i = l; i <= r; i++)
    {
        for (int j = i + 1; j <= r; j++)
        {
            res = min(res, (i * j) % 2019);
        }
    }
    cout << res << endl;
    return 0;
}
