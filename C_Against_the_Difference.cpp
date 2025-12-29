#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
            IT LOOKS LIKE 1D DP QUESTION:
            MAP<INT,VECTOR<INT>>LASTOCCURENCE


            BASE CASE:
                DP[0]=(ARR[0]==1)?1:0
                FOR I=1->N:
                    IF I DONT ADD THIS NUMBER:
                        DP[I]=DP[I-1]
                    IF(ARR[I]==1):
                        DP[I]++;

                        COMPLETE++;


                    ELSE(I  WANT TO ADD THIS NUMBER TO MY SUBSEQUENCE):
                        INT REM=MP[3]
                        IF(REM==1){
                            IF I ADD THIS IT WILL COMPLETE THIS BLOCK:
                                INT FIRSTINDEX=SOMETHING:
                                INT VAL=(FIRSTINDEX==0)?0:DP[FIRSTINDEX-1]
                                DP[I]=MAX(DP[I],VAL+ARR[I])
                        }
                    MP[ARR[I]].PUSH_BACK(I)

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
        map<int, vector<int>> mp;
        vector<int> dp(n, 0);
        dp[0] = (arr[0] == 1) ? 1 : 0;
        mp[arr[0]].push_back(0);
        for (int i = 1; i < n; i++)
        {
            dp[i] = dp[i - 1];
            if (arr[i] == 1)
            {
                dp[i]++;
            }
            else
            {
                vector<int> &indexes = mp[arr[i]];
                int size = indexes.size();
                if (size >= (arr[i] - 1))
                {
                    // THIS BLOCK CAN BE  COMPLETED
                    int firstindex = indexes[size - arr[i] + 1];
                    // cout << firstindex << endl;
                    int val = (firstindex == 0) ? 0 : dp[firstindex - 1];
                    dp[i] = max(dp[i], val + arr[i]);
                }
            }
            mp[arr[i]].push_back(i);
        }

        cout << dp[n - 1] << endl;
    }
    return 0;
}
