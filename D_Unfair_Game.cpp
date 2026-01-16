#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so alice only plays the game..

    and the initial number is from 1..n

    and this is the starting number..

    now if the number is even then only alice can half that number..

    else alice will have to subtract the number..

    in even although she has an option of subtracting 1

    will she do that ?

    i dont think so because k needs to be minimum and

    n - 1 is not giving any benefit.. maybe..

    maybe we have to calc min number we can get that

    takes more than k turns to reach 0 ..

    and the answer will be min_number - 1..


    or maybe bs to find this number..


    some numbers even though they are smaller 

    take more steps.. 

    1 step = 1 

    2 step = 2 

    3 step = 3 , 4 

    4 steps = 5 , 6 , 8 

    5 steps = 7 , 9 , 10 , 12 , 16






*/
int find(int n)
{
    int p = 1;
    while ((p << 1) <= n)
        p <<= 1;
    return p;
}
map<int, int> dp;
int k;
int recursion(int n)
{
    if (n < k)
        return (int)1e9;
    if (n == k)
        return 0;
    if (dp.find(n) != dp.end())
        return dp[n];
    int res;
    if (n & 1)
    {
        res = 1 + recursion(n - 1);
    }
    else
        res = 1 + recursion(n / 2);

    return dp[n] = res;
}
bool is_possible(int n, int K)
{
    int min_req = recursion(n);
    return (min_req <= K);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    map<int, int> dp;
    while (t--)
    {

        int n, K;
        cin >> n >> K;
        dp.clear();
        k = 0;
        int left = 0, right = n;

        int res = n + 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (!(is_possible(mid, K)))
            {

                res = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        cout << res << endl;

        cout << n - res + 1 << endl;
    }
    return 0;
}
