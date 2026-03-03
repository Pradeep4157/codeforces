#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


        so i will take from closest left or closest right..

        and the ele from there till here should be

        same arr[i]..


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
        vector<int> B;
        B.push_back(b[0]);
        for (int i = 1; i < n; i++)
        {
            if (b[i] == B.back())
                continue;
            else
                B.push_back(b[i]);
        }
        int right = 0;
        int index = 0;
        while (right < n)
        {
            if (index == B.size())
                break;
            if (arr[right] == B[index])
            {
                index++;
            }
            right++;
        }
        if (index == B.size())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
