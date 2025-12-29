#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    what is the max ele that we can achieve..

    so for the last element we are def going to apply  because arr[i]<=2*n

    so we can do it with dp..

    so left is being fixed at current index..

    for every l i would want the r to be as big as possible..

    but for every r i would want l to be as min as possible..

    we choose some l,r the rem is prefix[l-1] + suffix[r+1]

    if we dont want to use l,r then we will just use

    it one last ele..

        for any index..

        the left can vary from ..

            arr[i]-(i+1)....(i+1)

            how do i decide which l to take among these ?


    the best last ele can be 2n,

    2nd last best ele can be (2n-1,2n)


    1st ele best ele.. (2,2n)


    so the eqn ..

    (r+l)*(r-l+1) should be maximized..

    r^2 - l^2 + r + l - p[r] + p[l-1] + remaining should be maximized..

    so the final eqn  = r^2 + l^2 + r + l - p[r] + p[l - 1] + p[l - 1] + suffix[r]

    so we will store for every i ..

        2*p[i-1] + i - i^2


    to find the res along with this we will also add...

        suffix[r] + prefix[l-1] becuase l..r is the window that we

        have selected to change..

        so the remaining things remain unchanged..

        so instead of just storing p[i - 1] + i - i^2 we can also store

        this p[l - 1] so we dont need to worry about the left index

        where it is we dont care whatever gives the max answer for

        this right fixed pointer will get selected..


        so the equation is going to be r^2 + r - p[r] + pq.top()  + suffix[r]

        that's it !!


        what will i do when i == 0 :

            at the point instead of storing p[i - 1] + i + i^2

            just store i + i^2



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
        priority_queue<int> pq;
        vector<int> prefix(n);
        // prefix creation..
        for (int i = 0; i < n; i++)
        {
            prefix[i] = arr[i];
            if (i)
                prefix[i] += prefix[i - 1];
        }
        int res = accumulate(arr.begin(), arr.end(), 0LL);

        // now we will find the best subarray by fixing r
        for (int right = 0; right < n; right++)
        {
            // if we want single sized subarray..
            // adding 2 because it is 1 based..
            int curr = right + right + 2;
            // suffix addition..
            curr += prefix[n - 1] - prefix[right];
            // prefix addition..
            if (right)
                curr += prefix[right - 1];
            res = max(res, curr);
            // now for all the remaining arrays..
            if (!pq.empty())
            {
                // r^2 - l^2 + r + l  + p[l - 1] + suffix[r]
                int bestleft = pq.top();

                int curr = 0;

                // now the equation..

                // first part of the equation..
                curr += ((right + 1) * (right + 1));
                curr += (right + 1);

                // second part of the equation..
                curr += bestleft;

                // suffix addition..
                curr += prefix[n - 1];
                curr -= prefix[right];

                res = max(res, curr);
            }
            // cout << res << endl;
            if (right)
            {

                pq.push(right + 1 - ((right + 1) * (right + 1)) + (prefix[right - 1]));
            }
            else
            {
                pq.push(right + 1 - ((right + 1) * (right + 1)));
            }
        }
        // what if we want to  transform the whole array ..

        cout << res << endl;
    }
    return 0;
}
