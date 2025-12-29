#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so del left ele k times..

    and right ele n - 1 - k times..

    if left del are 0 ..

    then ans is the 0th index ele in the array..

    else if left del is n - 1 then ans is last ele..

    else can it be any ele ?



*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (k == 0)
        {
            cout << arr[0] << endl;
        }
        else if (k == n - 1)
        {
            cout << arr[n - 1] << endl;
        }
        else
        {
            cout << *max_element(arr.begin(), arr.end()) << endl;
                }
    }
    return 0;
}
