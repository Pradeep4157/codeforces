#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    good if x fx times..

    if ele is > 1 then i will put 1 front and one backk..

    0

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
        {
            cin >> arr[i];
        }
        int ans = 0;

        int first = 0;
        int second = 0;
        int both = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 1)
            {
                both++;
                int mini = min(first + both, second + both);
                ans = max(ans, mini);
                // or take a single or maxi..
            }
            else if (arr[i] == 1)
            {
                // this can be common..
                int mini = min(first, second);
                ans = max(ans, mini + 1);
                // and assign it to one of them..
                if (first <= second)
                    first++;
                else
                    second++;
            }
            if (first != second)
            {
                // then one has extra..
                // give one to min and check..
                int mini = min(first, second);
                mini += (both + 1);
                ans = max(ans, mini);
            }
            int MINI = min(first, second);
            ans = max(ans, MINI);
        }
        cout << ans << endl;
    }
    return 0;
}
