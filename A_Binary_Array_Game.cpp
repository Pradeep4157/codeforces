#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    alice wants last to be 1 1 1 1

    1010101
    100000
    1010
    100
    10

    if one of the ends is 1 and there is atleast one zero

    then after alice it will become 11 then she  wins

    else she looses.

    0100
    011

    010
    001010
    11010

    1111010
    1111
    10


    00010
    110
    1

    110



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
            cin >> arr[i];
        bool found_one = false;
        if (arr[0] == 1 || arr[n - 1] == 1)
            found_one = 1;
        if (found_one)
        {
            cout << "Alice" << endl;
        }
        else
            cout << "Bob" << endl;
    }
    return 0;
}
