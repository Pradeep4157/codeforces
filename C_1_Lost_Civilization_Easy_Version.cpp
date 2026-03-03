#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    for every start i need to check could i have inserted that next

    thing..

    if yes then i will have a left and a right

    i need to check from this left to right is poss or not.

    if yes then move to the next thing else do res ++ and move left = right + 1..

    for every left check next

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
        int right = 1;
        int left = 0;
        int size = 1;
        while (right < n)
        {
            while (right < n)
            {
                if (arr[right] > arr[right - 1] + 1)
                    break;
                // now it is either less than or equal to prev..
                if (arr[right] <= arr[left])
                    break;
                right++;
            }
            if (right == n)
                break;

            size++;
            left = right;
            right++;
        }
        cout << size << endl;
    }
    return 0;
}
