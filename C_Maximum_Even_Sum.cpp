#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    OUR GOAL IS TO MAKE A + B  EVEN

    EITHER WE MAKE:
        A AND B BOTH ODD OR
        A AND B BOTH EVEN
        ANY OTHER CASE IS IMPOSSIBLE

    IS THERE A WAY TO FIND IMPOSSIBLE CASE:


    IN THE CASE OF ODD AND ODD:
        SINCE ODD+ODD=EVEN
        I WILL MAKE B=1 AND A=A*B THAT IS GOING TO MAXIMIZE THE RES

    IN THE CASE OF ODD AND EVEN:
        NO MATTER WHAT I DO I WILL HAVE TO MAKE
        BOTH A AND B EVEN BECUASE EVEN IF I TRY TO MAKE B
        ODD THE FACTORS OF 2 GETS MULTIPLIED TO A AND A
        BECOMES EVEN
        SO THE ONLY WAY IS THAT I GIVE

    OTHER THAN ODD AND ODD I WLL KEEP A 2 IN B AND
    GIVE THE REST OF THE FACTORS TO A

*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if ((a & 1) && (b & 1))
        {
            int res = (a * b) + 1;
            cout << res << endl;
        }
        else if ((a % 2 == 0) && (b % 2 == 0))
        {

            int res = 2;
            b /= 2;
            res += (a * b);
            cout << res << endl;
        }
        else
        {
            // B SHOULD BE A FACTOR OF 4 SO THAT IT KEEPS ONE TWO
            if (b % 4)
            {
                cout << -1 << endl;
            }
            else
            {
                int res = 2;
                b /= 2;
                res += (a * b);
                cout << res << endl;
            }
        }
    }
    return 0;
}
