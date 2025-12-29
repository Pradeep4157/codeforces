#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
            OBSERVATIONS
    HERE THE LENGHT OF THE ARRAY=(N+N-1),
    BREADTH=N+(N-1)
    FIRST LINE FROM FRONT 1 STAR, FROM BACK ANOTHER STAR
    SECOND LINE FROM FRONT 2 START, FROM BACK 2 STAR
    TILL WE REACH N AND THEN DECREASE STAR COUNT
    THIS ONE GIVES WRONG ANSWER, LETS TRY WITH GAP COUNT

    FIRST GAP COUNT=N
    THEN GAPCOUNT-=2


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

        int gapcount = n + n - 1 - 2;
        int startcount = 1;
        while (gapcount >= -1)
        {
            for (int i = 0; i < startcount; i++)
            {
                cout << '*';
            }
            if (gapcount != -1)
                for (int i = 0; i < gapcount; i++)
                    cout << " ";
            if (startcount == n)
                startcount--;
            for (int i = 0; i < startcount; i++)
                cout << '*';
            cout << endl;
            startcount++;
            gapcount -= 2;
        }
        gapcount = 1;
        startcount--;
        while (gapcount <= n + n - 1 - 2)
        {
            for (int i = 0; i < startcount; i++)
            {
                cout << '*';
            }
            for (int i = 0; i < gapcount; i++)
                cout << " ";
            for (int i = 0; i < startcount; i++)
                cout << '*';
            cout << endl;
            startcount--;
            gapcount += 2;
        }
        cout << endl;
    }
    return 0;
}
