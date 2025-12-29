#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so if k is -ve :

        then we will  try to multiply it with non positive elements and if there are no non positive elements then we multiple it with two smallest

        elements in the array

    same when k is +ve :
        here also we will try to multiply it with max subarrays where sum is max and second max



    so the idea is that we have lower areas and uppper areas we try to minimize lower areas

    and maximize upper areas

    if k is negative then we take the max lower area and multiple the sum with k

    and

    if k is positive then we take max upper area and multiple the sum with k


    we cant simply determine which window to take


    one greedy way that i can think of is that


    this merging of between negative elements with positiive ends is good when k > 0 but when k < 0 then it is better that we try to do the opposite




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
        vector<int> prefix(n);
        int psum = 0;
        for (int i = 0; i < n; i++)
        {
            psum += arr[i];
            prefix[i] = psum;
        }
        vector<int> dp(n, 0);
        if (k > 0)
        {
            int currsum = 0;
            vector<pair<int, int>> sums;
            int prevpositive = -1;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] >= 0)
                {
                    // if this is the first positive element that i have found
                    if (prevpositive == -1)
                    {
                        // i will not merge it with any previous element because that will  only decrease the value
                        dp[i] = arr[i];
                        sums.push_back({i, i});
                    }
                    else
                    {
                        // there is some +ve element previously
                        // can i merge them ?
                        int betweensum = prefix[i - 1] - prefix[prevpositive];
                        betweensum = abs(betweensum);
                        if (betweensum <= dp[prevpositive])
                        {
                            // then i will  definitely merge these two
                            while (true)
                            {
                                auto [left, right] = sums.back();
                                if (right == prevpositive)
                                {
                                    // this is the subarray
                                    int size = sums.size();
                                    sums[size - 1].second = i;
                                    break;
                                }
                                else
                                {
                                    sums.pop_back();
                                }
                            }
                            // current dp updation
                            dp[i] = dp[prevpositive] + betweensum + arr[i];
                        }
                        else
                        {
                            // if the sum is greater than the dp of prevpositive then there's no meaning to add these two
                            dp[i] = arr[i];
                            sums.push_back({i, i});
                        }
                    }
                    prevpositive = i;
                }
                else
                {
                    // in this i dont want these negative elements to group together because they will affect me badly here
                    // i will  push them all  alone
                    dp[i] = arr[i];
                    sums.push_back({i, i});
                }
            }
            // lets test this code

            vector<vector<int>> actualsums;
            for (auto a : sums)
            {
                int left = a.first;
                int right = a.second;
                int currsum = prefix[right];
                if (left)
                    currsum -= prefix[left - 1];
                actualsums.push_back({currsum, right - left + 1});
            }

            sort(actualsums.rbegin(), actualsums.rend());

            int res = actualsums[0][0] * k;
            cout << res << endl;
        }
        else
        {
            // first try -ve subarrays
            vector<int> dp2(n, 0);
            vector<pair<int, int>> sums;
            int prevnegative = -1;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] <= 0)
                {
                    // here i will try to merge with prevnegative
                    if (prevnegative == -1)
                    {
                        // it will be itself only
                        dp[i] = arr[i];
                        sums.push_back({i, i});
                    }
                    else
                    {
                        int betweensum = prefix[i - 1] - prefix[prevnegative];

                        if (betweensum <= abs(dp[prevnegative]))
                        {
                            // then it is good to match
                            while (true)
                            {
                                auto [left, right] = sums.back();
                                if (right == prevnegative)
                                {
                                    int size = sums.size();
                                    sums[size - 1].second = i;
                                    break;
                                }
                                else
                                {
                                    sums.pop_back();
                                }
                            }
                            dp[i] = arr[i] + betweensum + dp[prevnegative];
                        }
                        else
                        {
                            // i dont need to merge them
                            dp[i] = arr[i];
                            sums.push_back({i, i});
                        }
                    }
                    prevnegative = i;
                }
                else
                {
                    // positive element
                    // i dont want these numbers
                    sums.push_back({i, i});
                    dp[i] = arr[i];
                }
            }

            // now i have all the negatives
            int res = LLONG_MIN;
            for (auto a : sums)
            {
                int right = a.second;
                int left = a.first;
                int currsum = prefix[right];
                if (left)
                    currsum -= prefix[lef - 1];
                res = max(res, currsum);
                res = max(res, )
            }
        }
    }
    return 0;
}
