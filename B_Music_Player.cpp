#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    int curr = 0;
    bool play = false;
    while (q--)
    {
        int a;
        cin >> a;
        if (a == 1)
            curr++;
        else if (a == 2)
            if (curr >= 1)
                curr--;
        if (a == 3)
        {
            if (play)
                play = 0;
            else
                play = 1;
        }
        if (play && curr >= 3)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
