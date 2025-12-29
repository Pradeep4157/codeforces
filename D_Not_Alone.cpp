#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    for every arr[i] i either make this equal to arr[i-1] or arr[i+1]

    what is the cost for making arr[i] == arr[i-1]:
        here also i either make arr[i] as arr[i-1] or arr[i-1] as arr[i]

        so two states for every i

        dp[i][0] cost to make arr[i] as arr[i-1]

        dp[i][1] cost to make arr[i-1] as arr[i]

        so at every index :
            dp[i][0] = abs(arr[i]-arr[i-1]) + dp[i-1][1] this is cost to make arr[i-2] equal to arr[i-1]

            dp[i][1] = abs(arr[i]-arr[i-1]) + dp[i-1][]


        but i dont need to make all of them equal  right !!


        we dont need two dp arrays:
            dp[i][prev/next] this is enough:

        they have given that n >=3 so no need to worry

        for every i , i either choose to combine this with i - 1 or i + 1


        dp[0][0] = abs(arr[0]-arr[n-1]);
        dp[0][1] = abs(arr[0]-arr[1]);

        for every i , i have a lot of conditions :
            arr[i-1] = arr[i] = arr[i+1]
            arr[i-1] = arr[i]
            arr[i] = arr[i+1]


            i dont think we need to think about i + 1

            but again :
                if arr[i] = arr[i - 1 ]

                or not this is the condition ?

                here also :

                if i dont change arr[i] == arr[i-1]
                then what ?
                then here i will  have to make arr[i] == arr[i+1]


    so the states are dp[i][2]

    for every i , the first one is that i match this array[i] with prev index &&

    the second one is that i match this array[i] with the next element that is i + 1

    now ,

    dp[0][0] = abs(arr[0] - arr[n-1])

    dp[0][1] = abs(arr[0] - arr[n-1]);

    is n == 3 an edge case ? or can i generalize that also ?

    cause i am thinking to start my dp from i == 2 :

        and for every i , i will either make arr[i]- > arr[i-1] or arr[i-1] - > arr[i]

    what happens when i start my dp from i == 2 :

        at every i either make arr[i-1] - > arr[i] :


    HERE THE DP STATE SHOULDNT BE WHETHER I CONVERT ARR[I-1] -> ARR[I] OR OTHER WAY :

        instead the dp state is that whether you make group of size 2 or of size 3 :


    for every i , i can make the dp state for 2 / 3 elements but there is an overlap of

    count betweent the last 2 elements & initial elements :

    1       2        3      4
    1,4     2,1     2,3    3,4
    1,4,3   2,1,4   3,2,1  4,3,1

    so should i make 3 dp arrays for definite end of the dp array:

    first dp is going to end just after n - 3 , 2nd dp is going to end just after n - 2 ,

    and the last dp is going to end after n - 1

    this should do the job of covering all the cases !!

    and what are we going to return min ( dp1[n - 3][0], dp1[n - 3][1] , dp2[n - 2][0] , dp2[n - 2][1]
    ,dp3[n - 1][0], dp2[n - 1][1]);


    now before i go with the normal transitions i need to preprocess somethings :

    in dp1 :

        since the start is n - 2 : 0, n - 1, n - 2 or 0 , 1 && n - 1 && n - 2 that's all no other

        initial pairing can be done

        if(n>=4) dp1[n - 1][0] = abs(arr[n - 1] - arr[n - 2]) && dp1[1][0] = abs(arr[1] - arr[0]) + dp1[n-1][0]

        other case :
            dp1[0][1] = mincost(last two ele , arr[0])


    in dp2 :
        since the start is n - 1: n - 1,


    why am i doing these things just make three arrays where the first array has last 2 elements in

    the front of the array and second array has last element in the front and last array has

    no change

    NO NEED OF DOING THESE STUPID PREPROCESSING !!

*/
int mincost(int a, int b, int c)
{
    vector<int> v = {a, b, c};
    sort(v.begin(), v.end());
    int target = v[1]; // median
    return abs(a - target) + abs(b - target) + abs(c - target);
}
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
        vector<vector<int>> dp1(n, vector<int>(2, INT_MAX)), dp2(n, vector<int>(2, INT_MAX)), dp3(n, vector<int>(2, INT_MAX));
        vector<int> arr1(arr.begin(), arr.end());
        int lastele = arr1.back();
        arr1.pop_back();
        arr1.insert(arr1.begin(), lastele);
        lastele = arr1.back();
        arr1.pop_back();
        arr1.insert(arr1.begin(), lastele);
        vector<int> arr2(arr.begin(), arr.end());
        lastele = arr2.back();
        arr2.insert(arr2.begin(), lastele);
        arr2.pop_back();
        vector<int> arr3(arr.begin(), arr.end());
        for (int i = 1; i < n; i++)
        {
            // dp1 transition
            dp1[i][0] = abs(arr1[i] - arr1[i - 1]);
            dp2[i][0] = abs(arr2[i] - arr2[i - 1]);
            dp3[i][0] = abs(arr3[i] - arr3[i - 1]);
            if (i > 1)
            {
                // here we can make 3 length blocks and also need to merge prev blocks with 2 len
                // first lets make 3 length blocks
                dp1[i][1] = mincost(arr1[i], arr1[i - 1], arr1[i - 2]);
                dp2[i][1] = mincost(arr2[i], arr2[i - 1], arr2[i - 2]);
                dp3[i][1] = mincost(arr3[i], arr3[i - 1], arr3[i - 2]);

                // now we will make 2 len merging with prev dp's
                dp1[i][0] += min(dp1[i - 2][0], dp1[i - 2][1]);
                dp2[i][0] += min(dp2[i - 2][0], dp2[i - 2][1]);
                dp3[i][0] += min(dp3[i - 2][0], dp3[i - 2][1]);
            }
            if (i > 2)
            {
                // here is where we can merge 3 len blocks with prev blocks
                dp1[i][1] += min(dp1[i - 3][0], dp1[i - 3][1]);
                dp2[i][1] += min(dp2[i - 3][0], dp2[i - 3][1]);
                dp3[i][1] += min(dp3[i - 3][0], dp3[i - 3][1]);
            }
        }

        int res = min({dp1[n - 1][0], dp1[n - 1][1], dp2[n - 1][0], dp2[n - 1][1], dp3[n - 1][0], dp3[n - 1][1]});
        cout << res << endl;
    }
    return 0;
}