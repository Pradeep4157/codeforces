#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    this can be seen as a variation of kadane's algo ..

        where we keep a left pointer && right pointer keeps moving ..

            at every step if the right encounters a 1 curr --
            else curr++

            now ..
                if curr < 0 :
                    then we move left to this right pointer && continue ..

                    else :
                        we do a bf check to count number of ones before left , number of ones after right ..

                        && do res= max(res,curr+ ones);

                we could do prefix && suffix but since constraints are low we can do this ..



        */
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    int res = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int left = 0;
    int curr = 0;
    for (int right = 0; right < n; right++)
    {

        if (arr[right] == 1)
            curr--;
        else
            curr++;
        if (curr < 0)
        {
            left = right + 1;
            curr = 0;
        }
        else

        {
            int ones = 0;
            for (int i = left - 1; i >= 0; i--)
                if (arr[i] == 1)
                    ones++;
            for (int i = right + 1; i < n; i++)
                if (arr[i] == 1)
                    ones++;
            res = max(res, ones + curr);
        }
    }
    cout << res << endl;

    return 0;
}