#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    NO INITIAL IDEAS:
        MAYBE SEGMENT TREE/ SOME PREFIX APPROACH

    SO FOR EVERY SEGMENT IN ARRAY:
        WHAT IS THE REASON BECAUSE OF WHICH SWAPPING ARR[I], ARR[I+2] HAS NO EFFECT

    THERE SHOULD BE SOME USE OF PERMUTATION AS WELL
    REASONS:
        => IF THE SEGMENT SIZE IS ONLY 2:
        =>

    WHATEVER THE SEGMENT IS:
        IF THE CURRENT ELEMENT IS GREATER THAN ARR[I+2], SO IN THIS  CASE:
        OPERATION 2 WILL BE BETTER THAN OPERATION 1?

        THERE IS NO BENEFIT THAT I CAN GET IF ARR[I]>ARR[I+1] BECAUSE
        IN F(A) I CAN DO OPERATION 1 AS WELL

        WE NEED TO FIND WHERE OPERATION 2 HAS NO USE:

        FOR EVERY WINDOW GIVEN, WE HAVE TO FIND WHICH THE COUNT OF PLACES
        WHERE ARR[I]>ARR[I+2]
        2 1 4
        THERE IS NO BENEFIT PREFIX OF THIS IS 0\


        AMONG THREE ELEMENTS IF WE HAVE TO SORT:
            OP2: IS ONLY BENEFICIAL IF 2ND ELEMENT IS IN ITS PLACE AND FIRST AND
            3RD ELEMENT ARE OUT OF ORDER

            ELSE:
                OP1 AND OP2 TAKE SAME OPERATIONS TO SORT THE ARRAY


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> prefix(n, 0);
        int sum = 0;
        for (int i = 0; i < n - 2; i++)
        {
            if (arr[i] > arr[i + 2] && arr[i] > arr[i + 1] && arr[i + 1] > arr[i + 2])
            {
                sum++;
            }
            prefix[i] = sum;
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--, r--;
            if (r - l + 1 <= 2)
            {

                cout << "YES" << endl;
                continue;
            }
            int curr = prefix[r - 2];
            if (l - 1 >= 0)
                curr -= prefix[l - 1];
            if (curr == 0)
            {
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
