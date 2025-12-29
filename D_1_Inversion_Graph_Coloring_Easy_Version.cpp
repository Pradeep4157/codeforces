#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    dp[n-1]=1 because we cannot add any more element to the last element

    ans=1 because we can have empty subsequence as well
    so we start from n-2  for j=i+1 to n if arr[j]>=arr[i] then dp[j]+=dp[i]
    else:
        ans+=dp[i]

    after this ans+=sum of dp array


    one thing which i am missing is that for an increasing subsequence i can  combine it
    will all the elements that are lesser than arr[j] and are after j


    dp[j] will store the increasing subsequence starting from j


    so there are two cases:
        if(arr[j]<arr[i]) then we just do ans+=dp[j] ?
            yes its true because the dp[j]' s increasing sequence can be colored with
            one color and arr[i] can be colored with other and it will satisfy the
            constraints

        else:
            which means arr[j]>=arr[i]:
                dp[i]+=dp[j]

            so we are here storing the increasing subsequence starting at i


    so basically there are 2 conditions only:
        either we only taking increasing subsequence or
        we take keep increasing and then take a smaller element's increasing subsequence


        1st condition is already stored properly in the dp array

        but is the 2nd condition tracked properly ?

        lets say 100,101, 1,2,4

        for 101 i am adding



        i am not so sure about the 2nd condition that if arr[j]<arr[i], then we are
        simply adding incresing subsequence of that dp[j]

        but we can add that increasing subsequence to the increasing subsequence of arr[i]

        no its not totally correct because what it traps is the increasing subsequences
        starting from j in that i am only adding arr[i]

        which is wrong i can add increasing subsequence starting at arr[i]

        so final condition would be :
            if(arr[j]> arr[i]):
                res+=(pow(2,count)*dp[j]) where count is the count of elements that
                are greater than or equal  to  arr[i] and they occur before j


            else:
                the condition where arr[j]>=arr[i]:
                    count++;
                    dp[i]+=dp[j] only increasing subsequence
        100 , 1, 3 dp[1]=2
    so for arr[j] i need two values what are the j > i where arr[j] > arr[i] and in all those
    subsequences i


    OK so increasing subsequence we are getting correct answer error is in the case
    that arr[j]<arr[i]:


    0R MAYBE THERE IS ANOTHER CASE:



    the else part is wrong because we need to only keep increasing
    subsequence followed by increasing sequence
    but instead what i am doing is just keeping count of numbers
    after i >= arr[i] and planning to color them same
    but this is wrong


    lets say arr[i]=2 after that we got 100, same color
    after that 50 same color but 100 and 50 cannot have same colors

    its  not so simple that we are just keeping 2 increasing subsequence and finding all the comibinations that we can make from
    them , instead we can keep multiple such subsequences just the condition is that the current drop should be >= previous peak

    can we store all of this ?


    how do i even make this subsequence such that for current element i can



    instead of trying to find what all things are possible why dont we first consider everything is possible then subtract impossible

    all possible=2^n

    impossible from back all the increasing sequence with length  >= 3


    how do i store dp such that each index stores subsequences starting from this index with length >= 3


*/
const int mod = (int)(1e9 + 7);
int binpow(int base, int exp)
{
    if (exp == 0)
        return 1LL;
    if (exp & 1)
        return base * binpow(base, exp - 1) % mod;
    else
    {
        int temp = binpow(base, exp >>= 1);
        return temp * temp % mod;
    }
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
        {
            cin >> arr[i];
        }
        reverse(arr.begin(), arr.end());

        vector<int> dp1(n, 1), dp2(n, 0), dp3(n, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] > arr[i])
                {
                    dp2[i] += dp1[j]; // extend to length 2
                    dp3[i] += dp2[j]; // extend to length 3+
                }
            }
        }
        int res = binpow(2, n);
        for (auto a : dp3)
            cout << a << " ";
        cout << endl;
        vector<int>dpp(n)
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(arr[j]>=arr[i]){
                    dpp[i]+=dpp[j];
                }
            }
        }
        res -= accumulate(dp3.begin(), dp3.end(), 0LL);
        cout << res << endl;
    }

    return 0;
}
