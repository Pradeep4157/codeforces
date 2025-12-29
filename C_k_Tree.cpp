#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    i take some path :

    it is valid if :

        the path sum == n

        at least one edge of weight >= d

    n,k,d <=100


    if this >=d condition was not there then what would be the answer ?

        we could go at max till n depth right ??

        becuase if we go below that even if we take 1,1,1,1,... it would still be > n


        so we can go only till level n - d + 1  becausee anything below  that if we take a d also and all 1's the sum would be > n

        so we go bf from level 1 - > level n - d + 1 :

            now how do we calculate the possibilities ?

                at any level we start from d ... n right ?


                    and for each of these values the remaining sum n - currd

                    but this can cause over counting if we equally distribute remaining sum before and after

                    so for this i can set conditions that no prefix should be >= d


            what if instead of focusing on this level is going to have d->..whatever last limit i bf on that this is going to be the last level .. then


            so the fact that n - d + 1 is the last level where d is valid all the levels before that needs to have some d so that sum == n else it is not possible to make

            sum n

            eg: n = 4 && d = 2 so at least one edge should be >=2 for level 1 : only 4 works , for level 2 : 1, reamining_sum = 3 dp[level1][remaining sum] ,

            2 - > dp[lev 1][2] , 3 - > dp[lev1][1] , 4 - > dp[lev1][0]

            so for every level we iterate from 1 - > n - level + 1 becuase at least remaining should have something

            now how do we calc dp :

                for first row dp[1][k]=k

                we just need to calc sums that are possible at each level :
                    the minimum sum possible till n levels is n

                    and the max sum possible till n level is n*k which is 1e4

                the sums that are possible at this level only depends on the sums that were possible at the previous level then we just add 1 to k to all the possibilities


                does seeing it from an upward view helps in any way ?


                the thing is although the sum can range fromm 1 - > n * k but the sum we need should be <=n only so we dont care about the

                sums that exceed k so this is how we will create dp :


                for level 2 - >  n - d + 2 :
                    we iterate from 1 .. n :
                        we iterate from 1 .. k :

                            if(dp[level-1][prevsum]!=0):
                                int currsum=prevsum+currk
                                if(currsum>n) continue
                                else :
                                    just like coin sum the no  of ways we could reach prev sum just add this currk to those comb
                                    dp[level][currsum]+=dp[level-1][prevsum]


                now dp is done !!



        now how do we calculate the no of ways:

            for i = 1 .. n - d + 1 :

            this is the last level :
                so the sum till this level should be n :
                    so the no of ways will be dp[i][n] that's all ?

            also there can be an edge case that if d > n then res will be zero that will also be covered

        it is overcounting some paths

        the issue is that level 1 ... level n - d + 1 does not guarentee that

        some value >= d so we need to do something else for that ..

        so instead of 2d dp we will have 3d dp where the 3rd state will tell whether we have some value >=d or not

        dp calc:

            for the first level we iterate from 1 .. k or n :
                if i is >=d dp[1][i][1]=1 else dp[1][i][0]=1;

            now from level 2 onwards..
                level = 2...n :
                    prevsum = 1...n:
                        k = 1...k:
                            has = 0..1
                                int newsum = prevsum + currk
                                dp[level][newsum][has]+=dp[level-1][prevsum][has]

            this should be enough and now another loop :
                i = 1...n :
                    res+=dp[i][n][1]
            that should work

*/
const int mod = (int)(1e9 + 7);
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, d;
    cin >> n >> k >> d;
    // dp creation
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));
    // first level filling
    for (int i = 1; i <= min(n, k); i++)
    {
        // only one way to reach this sum that is by k itself
        if (i >= d)
            dp[1][i][1] = 1;
        else
            dp[1][i][0] = 1;
    }
    //  now for all the bigger levels
    for (int level = 2; level <= n; level++)
    {
        for (int prevsum = 1; prevsum <= n; prevsum++)
        {

            // else we join k roots from this
            for (int currk = 1; currk <= k; currk++)
            {
                int newsum = prevsum + currk;
                if (newsum > n)
                    continue;

                // now if currk >=d then it will always be in has state
                if (currk < d)
                {
                    // now this can only be reached by prevsum that dint had d
                    dp[level][newsum][0] = (dp[level][newsum][0] + dp[level - 1][prevsum][0]) % mod;
                    // has state can only be acheived if prevsum had some d
                    dp[level][newsum][1] = (dp[level][newsum][1] + dp[level - 1][prevsum][1]) % mod;
                }
                else
                {

                    // we can take all prevsum not has and has and update
                    dp[level][newsum][1] = (dp[level][newsum][1] + dp[level - 1][prevsum][0]) % mod;
                    // we can also take all prevsum which has and add this
                    dp[level][newsum][1] = (dp[level][newsum][1] + dp[level - 1][prevsum][1]) % mod;
                }
            }
        }
    }
    // now dp is created , now we count the number of ways
    // we only go till n - d + 1 because that ensures that atleast one of the values > = d
    int res = 0;
    for (int level = 1; level <= n; level++)
    {
        // now if we can reach n till this level then just add that to res
        int curr = dp[level][n][1];

        res = (res + curr) % mod;
    }
    cout << res << endl;

    return 0;
}
