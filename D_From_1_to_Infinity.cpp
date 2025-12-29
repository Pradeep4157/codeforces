#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so the sequence is just...

    1
    2
    3
    4
    5
    ..
    10
    11
    12 ..


    20
    21
    22
    23 ..

    maybe we can BS on the numbers :

        for every mid if the number of digits

        till that mid is <=k :
            res = mid
            low =  mid + 1
        else :
            high = mid - 1

    now how does this number of digits till

    some mid is calc..

    mid has some number of digits ..

        lowest of that will be 10^(digits - 1)

        and places += (currele - lowest + 1)*(digits)


        && then curr = lowest - 1 && digits --

        we keep doing this till digits >=0

        and then break  and check whether places<=mid

        if yes return true else return false


        now in the recursion ...

        at every step if tight is true

        then we can only use numbers till

        arr[start] else we can use

        digits from 0..9

        && when tight is true if the

        current digit != arr[start] then

        we can mark tight as false ..

        now even after this ..

        there can still be some places left by another ..

        and at max 1 number to the right is possible also not fully

        but partially ..

        so how do we find that ?

        from k we will subtract places of our current number..

        and we will push the next number in an array and keep

        adding digits till remaining_places > 0 ;


        now implementing the digit DP part

            now we know that only returning the sum is not enough

            because for a digit fromm 0.. some x :

                we also need to know how many numbers is it getting

                combined with like for n == 11 :

                    1 is comb with 0 , 1


            the combinations is the multiplication of all the numbers..

            possible after this ..

            so at the end i need to return times as 1 else

            everything becomes 0..

            and the sum just needs to be added..



*/
vector<vector<pair<int, int>>> dp;
pair<int, int> recursion(int start, vector<int> &arr, bool istight)
{
    pair<int, int> res = {0, 0};
    if (start == arr.size())
    { // theres no number to combine with ..
        return {0, 1};
    }
    if (dp[start][istight].first != -1 && dp[start][istight].second != -1)
        return dp[start][istight];
    if (istight)
    { // we can only use numbers till arr[start]..
        for (int i = 0; i <= arr[start]; i++)
        {
            if (i == arr[start])
            {
                pair<int, int> curr = recursion(start + 1, arr, 1);
                res.first += (curr.second * i);
                res.first += curr.first;
                res.second += curr.second;
            }
            else
            {
                pair<int, int> curr = recursion(start + 1, arr, 0);
                res.first += (curr.second * i);
                res.first += curr.first;
                res.second += curr.second;
            }
        }
    }
    else
    {
        for (int i = 0; i <= 9; i++)
        {
            pair<int, int> curr = recursion(start + 1, arr, 0);
            res.first += (curr.second * i);
            res.first += curr.first;
            res.second += curr.second;
        }
    }
    return dp[start][istight] = res;
}
int binpow(int a, int b)
{
    if (b == 0)
        return 1;
    else if (b & 1)
    {
        return a * binpow(a, b - 1);
    }
    else
    {

        int temp = binpow(a, b >> 1);
        return temp * temp;
    }
}
int find_digits(int n)
{
    int res = 0;
    while (n)
    {
        n /= 10;
        res++;
    }
    return res;
}
int placesfinder(int n)
{
    // this is our placesfinder function..
    int digits = find_digits(n);
    int curr = n;
    int places = 0;
    while (digits > 0)
    {
        int lowest = binpow(10, digits - 1);
        places += (curr - lowest + 1) * (digits);
        curr = lowest - 1;
        digits--;
    }
    return places;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        int low = 1, high = 1e15;
        int res = 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (placesfinder(mid) <= k)
            {
                res = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        int tempres = res;
        vector<int> arr;
        while (res)
        {
            arr.push_back(res % 10);
            res /= 10;
        }

        reverse(arr.begin(), arr.end());
        dp.assign(arr.size() + 1, vector<pair<int, int>>(2, {-1, -1}));
        int ans = recursion(0, arr, 1).first;
        vector<int> b;
        int nextres = tempres + 1;
        while (nextres)
        {
            int last = nextres % 10;
            nextres /= 10;
            b.push_back(last);
        }
        reverse(b.begin(), b.end());
        int remplaces = k - placesfinder(tempres);
        for (int i = 0; i < b.size(); i++)
        {
            if (remplaces == 0)
                break;
            remplaces--;
            ans += b[i];
        }
        cout << ans << endl;
    }
    return 0;
}
