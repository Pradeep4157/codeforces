#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    we cant choose the same number  because it will

    tie..

    so we choose middle element but we still

    can get better..

    if the a < current_ele then alice cant take

    ele >=arr[i]

    so we will try to take more

    if he also chooses middle ele return this only..

    else try to take more on his side..


    so when they are same alice still gets the point..

    so its better to take either left / right side..






*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, a;
        cin >> n >> a;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int b1 = arr[0];
        int b2 = arr[n - 1];
        int c1 = 0, c2 = 0;
        // trying to find b towards the left..
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= a)
            {
                break;
            }
            c1++;
            b1 = arr[i];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] <= a)
                break;
            c2++;
            b2 = arr[i];
        }
        if (c1 == c2)
        {
            cout << b1 << endl;
        }
        else
        {
            if (c1 > c2)
                cout << b1 << endl;
            else
                cout << b2 << endl;
        }
    }
    return 0;
}
