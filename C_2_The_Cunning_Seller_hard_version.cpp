#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
    OBSERVATIONS:
    1->3
    3->9+1=10
    9->27+2*(3)=33
    3,10,33,108
    10->3 =1
    33->10=3
    108->33=9
    AMONG THE REMAINING K-MINREQ WHICH DEALS WILL I USE:
        LETS SAY I HAVE USED X NUMBERS OF DEAL C, SO TO CONVERT ONE DEAL C TO DEAL B IT WILL TAKE ME 2 EXTRA DEALS:
            PRICE DECREMENT=power(3,x-1);

    FIRST WE WILL CALCULATE THE AMOUNT OF DEALS OF TYPE X AND THEN CALCULATE K-DEALS THAT  HAVE BEEN MADE, THEN FROM THE LAST DEAL WE WILL KEEP DECREASING EACH OF THE DEAL TILL WE HAVE NO MORE EXTRA DEALS LEFT

*/
// Fast exponentiation for long long
int power(int base, int exp)
{
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result *= base;
        base *= base;
        exp >>= 1;
    }
    return result;
}

// Check if n is a power of 3
bool isPowerOfThree(int n)
{
    if (n < 1)
        return false;
    while (n % 3 == 0)
        n /= 3;
    return n == 1;
}

int cost(int x)
{
    return x * power(3, x - 1) + power(3, x + 1);
}

pair<int, int> computeCost(int n)
{
    int deals = 0;
    if (isPowerOfThree(n))
    {
        int powerVal = 0;
        while (power(3, powerVal) < n)
            powerVal++;
        return {1, cost(powerVal)};
    }
    else
    {
        int powerVal = 0;
        int res = 0;

        while (power(3, powerVal) < n)
            powerVal++;
        powerVal--;

        while (true)
        {
            while (powerVal >= 0 && power(3, powerVal) > n)
                powerVal--;
            if (powerVal < 0)
                break;

            while (power(3, powerVal) <= n)
            {
                deals++;
                res += cost(powerVal);
                n -= power(3, powerVal);
            }
        }
        return {deals, res};
    }
}
map<int, int> find(int n)
{
    int deals = 0;
    map<int, int> mp;
    if (isPowerOfThree(n))
    {

        int powerVal = 0;
        while (power(3, powerVal) < n)
            powerVal++;
        mp[powerVal] = 1;
        return mp;
    }
    else
    {
        int powerVal = 0;
        int res = 0;

        while (power(3, powerVal) < n)
            powerVal++;
        powerVal--;

        while (true)
        {
            while (powerVal >= 0 && power(3, powerVal) > n)
                powerVal--;
            if (powerVal < 0)
                break;
            int currdeals = 0;
            while (power(3, powerVal) <= n)
            {
                currdeals++;
                res += cost(powerVal);
                n -= power(3, powerVal);
            }
            mp[powerVal] = currdeals;
        }
        return mp;
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
        int n, k;
        cin >> n >> k;
        auto [minreq, res] = computeCost(n);
        // cout<<minreq<<":"<<res<<endl;
        //  IMPOSSIBLE CASE
        if (minreq > k)
        {
            cout << -1 << endl;
            continue;
        }

        int dealsleft = k - minreq;
        // WE WILL USE THE REMAINING K-MINREQ DEALS TO MINIMIZE THE COST
        map<int, int> mp = find(n);
        int maxtypedeal = 0;
        for (auto a : mp)
        {
            maxtypedeal = max(maxtypedeal, a.first);
        }
        vector<pair<int, int>> deals;
        for (auto a : mp)
        {
            deals.push_back({a.first, a.second});
        }
        // for(auto a:deals) cout<<a<<":";
        // cout<<endl;
        //  WE WILL NOT DO I=0 BECAUSE THERES NO BETTER DEAL TO SWAP WITH
        for (int i = deals.size() - 1; i > 0; i--)
        {
            int currdeals = deals[i].second;
            int prevdeals = deals[i - 1].second;
            while (currdeals > 0)
            {
                // WE CANT EXCHANGE CURRENT DEAL FOR PREV DEAL
                if (dealsleft < 2)
                    break;
                dealsleft -= 2;
                deals[i - 1] += 3;
                deals[i]--;
                res -= cost(i) - 3 * cost(i - 1);
            }
        }
        // for(auto a:deals) cout<<a<<" ";
        // cout<<endl;
        cout << res << endl;
    }

    return 0;
}
