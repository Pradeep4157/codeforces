#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    we cant decrease so we cant go ahead..

    so if any value != b[i] in order to make it == b[i]

    all the prev final values should be > b[i] or should

    be smaller than arr[i]...


    so we can start from biggest arr[i] ->b[i]

    now only problem is when two same arr[i]...

    in this case the left ones will get converted first..

    so their b[i] must be >= this b[i]..

    but again this will cause problem when we keep increasing this arr[i] such that it exceeds or reaches some

    greater arr[i] that has been converted to b[i] and is left to this

    then it will increase that  insted of this..





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
        vector<int> arr(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        bool ok = 1;
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= maxi)
            {
                if (arr[i] != b[i])
                {
                    ok = false;
                    break;
                }
            }
            else
            {
                if (arr[i] > b[i])
                    ok = false;
                maxi = arr[i];
            }
        }
        if (ok)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
