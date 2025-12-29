#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so the array is going to be either

    01010
    10101
    01010
    ...

    OR

    10101
    01010

    any one of these two works
    because if at an index we need odd number and if we have odd number then we can simply skip  else if we want
    even number then just add 1 and return the res

    we can keep an oddstart boolean that will tell us which indexes are going to be odd and which are going to be even
    if oddstart is true then all even indexes should be odd
    else all even indexes should be even

*/

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        }
        bool oddstart = 1;
        for (int i = 0; i < n; i++)
        {
            if (oddstart)
            {
                oddstart = 0;
                for (int j = 0; j < m; j++)
                {
                    if (j & 1)
                    {
                        // element should be even
                        if (arr[i][j] & 1)
                            arr[i][j]++;
                    }
                    else
                    {
                        // element should be odd
                        if (arr[i][j] % 2 == 0)
                            arr[i][j]++;
                    }
                }
            }
            else
            {
                oddstart = 1;
                for (int j = 0; j < m; j++)
                {
                    // odd indexes should be should be odd
                    if (j & 1)
                    {
                        if (arr[i][j] % 2 == 0)
                            arr[i][j]++;
                    }
                    else
                    {
                        // even indexes should be even
                        if (arr[i][j] & 1)
                            arr[i][j]++;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}
