#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
        ALL THE SUBARRAYS
        SUM OF EVEN INDICES>=SUM OF ODD INDICES(1 BASED)
        FOR  I=1 TO N I+=2
            SUM+=ARR[I-1]
            IF(I+1<N) SUM+=ARR[I+1]
            IF(SUM>=ARR[I]){
                INT DEC=SUM+1-ARR[I]
                IF(I+1<N){
                    SUB=MIN(DEC,ARR[I+1])
                    ARR[I+1]-=SUB;
                    DEC-=SUB;
                }

            }


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
        int res = 0;
        for (int i = 1; i < n; i += 2)
        {
            int sum = 0;
            sum += arr[i - 1];
            if (i + 1 < n)
                sum += arr[i + 1];
            if (sum > arr[i])
            {
                int dec = sum - arr[i];
                res += dec;
                if (i + 1 < n)
                {
                    int sub = min(dec, arr[i + 1]);
                    arr[i + 1] -= sub;
                    dec -= sub;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
